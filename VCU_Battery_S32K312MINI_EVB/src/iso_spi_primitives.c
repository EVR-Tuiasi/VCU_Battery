/*
 * bms_cosa.c
 *
 *  Created on: 29 apr. 2025
 *      Author: cosaa
 */
#include "iso_spi_primitives.h"
#include "Dio.h"
#include "Mcu.h"
#include "Mcl.h"
#include "Platform.h"
#include "Port.h"
#include "Spi.h"
#include "CDD_Uart.h"
#include "thermistor_mux.h"
#include "BMS_config.h"
#include "CanMessaging.h"
#include "UartMessaging.h"
#include "Messaging.h"

/*==================================================================================================
 * LOCAL VARIABLES
 *==================================================================================================*/

volatile int delei;
struct biemese icBaterie;
uint8 buffTrimitere[64];
uint8 buffPrimire[64];
uint8 bufferUART[10];
uint16 dpec;

// Comenzi pentru citirea registrelor de tensiune ADC
uint8 pacheteAverage[4]={0x44, 0x46, 0x48, 0x4A}; // RDACA, RDACB, RDACC, RDACD
// Comenzi pentru citirea registrelor în mod Open Wire
uint8 pacheteOW[4]={0x03, 0x05, 0x07, 0x0D};      // RDSVA, RDSVB, RDSVC, RDSVD

volatile int tensiuneMILIvolti1, tensiuneMILIvolti2, tensiuneMILIvolti3;
extern Thermistors Thermistors_Data;
extern MonitoredValues_t MonitoredValues;

/*==================================================================================================
 * GLOBAL FUNCTIONS
 *==================================================================================================*/

/**
* @brief          Resetează sistemul BMS.
* @details        Trimite comanda de Software Reset (SRST) către integratul BMS.
*
* @return         void
*/
void Bms_RESET(void)
{
    populeazaCMD(0, 0x27);
    transmisieCMD(); // SRST
}

/**
* @brief          Funcție de test pentru verificarea comunicării cu BMS-ul.
* @details        Citește ID-ul BMS-ului într-o buclă până când se primește un răspuns valid.
*
* @return         void
*/
void BmsTest(void)
{
    do
    {
        BmsReadID();
    }
    while(buffPrimire[4] != 255);
}

/**
* @brief          Citește ID-ul dispozitivului BMS.
* @details        Trimite comanda RDSID pentru a identifica dispozitivele de pe bus-ul ISO-SPI.
*
* @return         void
*/
void BmsReadID(void)
{
    populeazaCMD(0, 0x2C);
    transmisieCMD(); // read RDSID
}

/**
* @brief          Execută transmisia unei comenzi prin SPI cu manipularea CS-ului.
* @details        Include o secvență de "bit banging" pe pinul de Chip Select pentru a
* trezi transceiverul/interfața ISO-SPI înainte de transferul sincron.
*
* @return         void
*/
void transmisieCMD(void)
{
#if 1
    Port_SetPinMode(BMS_CS, PORT_MUX_AS_GPIO);
    Dio_WriteChannel(49, 0);
    delei = 30;
    while(delei) { delei--; }
    Dio_WriteChannel(49, 1);
    Port_ResetPinMode(BMS_CS);
    delei = 3000;
    while(delei) { delei--; }
#endif

    uint16 pec = Pec15_Calc(2U, buffTrimitere);
    buffTrimitere[2] = pec >> 8;
    buffTrimitere[3] = pec % 256;
    Spi_SetupEB(0u, buffTrimitere, buffPrimire, 64U);

    Spi_SyncTransmit(0);

    delei = 300000;
    while(delei) { delei--; }
}

/**
* @brief          Populează bufferul de trimitere cu codul comenzii.
*
* @param[in]      MSB: Most Significant Byte al comenzii.
* @param[in]      LSB: Least Significant Byte al comenzii.
*
* @return         void
*/
void populeazaCMD(char MSB, char LSB)
{
    buffTrimitere[0] = MSB;
    buffTrimitere[1] = LSB;
}

/**
* @brief          Transmite o configurație extinsă (Write Configuration).
* @details        Calculează PEC-ul și trimite un pachet de date a cărui lungime
* depinde de numărul de șunturi și monitoare configurate.
*
* @return         void
*/
void transmisieWR48(void)
{
    uint16 pec = Pec15_Calc(2U, buffTrimitere);
    buffTrimitere[2] = pec >> 8;
    buffTrimitere[3] = pec % 256;
#if 1
    Port_SetPinMode(BMS_CS, PORT_MUX_AS_GPIO);
    Dio_WriteChannel(49, 0);
    delei = 30;
    while(delei) { delei--; }
    Dio_WriteChannel(49, 1);
    Port_ResetPinMode(BMS_CS);
    delei = 3000;
    while(delei) { delei--; }
#endif

    Spi_SetupEB(0u, buffTrimitere, buffPrimire, 4 + 8 * NUMARUL_DE_SUNTURI + 8 * NUMARUL_DE_MONITOARE);
    Spi_SyncTransmit(0);

    delei = 300000;
    while(delei) { delei--; }
}

/**
* @brief          Curăță bufferele de transmisie și recepție SPI.
*
* @return         void
*/
void flushTX()
{
    for(int i = 0; i < 64; i++)
    {
        buffTrimitere[i] = 0;
        buffPrimire[i] = 0;
    }
}

/**
* @brief          Citește registrul de configurație A al BMS-ului.
*
* @return         void
*/
void BmsReadConfigA()
{
    populeazaCMD(0x00, 0x02);
    transmisieCMD(); // RDCFGA
}

/**
* @brief          oppreste discharge
*
* @return         void
*/
void muteDischarge()
{
    populeazaCMD(0x00, 0x28);
    transmisieCMD(); // MUTE
}

/**
* @brief          porneste discharge
*
* @return         void
*/
void unMuteDischarge()
{
    populeazaCMD(0x00, 0x29);
    transmisieCMD(); // UNMUTE
}

/**
* @brief          Citește registrul de configurație B al BMS-ului.
*
* @return         void
*/
void BmsReadConfigB()
{
    populeazaCMD(0x00, 0x26);
    transmisieCMD(); // RDCFGB
}

/**
* @brief          Configurează parametrii ADC pentru monitoare și șunturi.
* @details        Setează pinii GPIO, modurile de operare și calculează PEC-ul pentru
* fiecare modul din lanțul de comunicație.
*
* @return         void
*/
void parametriiADC()
{
    populeazaCMD(0x00, 0x01); // WRCFGA
    for(int i = 0; i < NUMARUL_DE_SUNTURI; i++)
    {
        buffTrimitere[4 + 8 * i] = 0x01; // default
        buffTrimitere[5 + 8 * i] = 0;    // CFGAR1
        buffTrimitere[6 + 8 * i] = 0;    // CFGAR2
        buffTrimitere[7 + 8 * i] = 0x5F; // porneste GPIO
        buffTrimitere[8 + 8 * i] = 0x0;
        buffTrimitere[9 + 8 * i] = 0x10;
        dpec = pec10_calc(false, 6U, buffTrimitere + 4 + 8 * i);
        buffTrimitere[10 + 8 * i] = dpec >> 8;
        buffTrimitere[11 + 8 * i] = dpec % 256;
    }

    for(int i = 0; i < NUMARUL_DE_MONITOARE; i++)
    {
        buffTrimitere[4 + 8 * NUMARUL_DE_SUNTURI + 8 * i] = 0x81; // default
        buffTrimitere[5 + 8 * NUMARUL_DE_SUNTURI + 8 * i] = 0;    // CFGAR1
        buffTrimitere[6 + 8 * NUMARUL_DE_SUNTURI + 8 * i] = 0;    // CFGAR2
        buffTrimitere[7 + 8 * NUMARUL_DE_SUNTURI + 8 * i] = 0xFF; // porneste GPIO
        buffTrimitere[8 + 8 * NUMARUL_DE_SUNTURI + 8 * i] = 0x03;
        buffTrimitere[9 + 8 * NUMARUL_DE_SUNTURI + 8 * i] = 0x10;
        dpec = pec10_calc(false, 6U, buffTrimitere + 4 + 8 * NUMARUL_DE_SUNTURI + 8 * i);
        buffTrimitere[10 + 8 * NUMARUL_DE_SUNTURI + 8 * i] = dpec >> 8;
        buffTrimitere[11 + 8 * NUMARUL_DE_SUNTURI + 8 * i] = dpec % 256;
    }
    transmisieWR48();
}


void parametriiCFGB()
{
    populeazaCMD(0x00, 0x24); // WRCFGB
    for(int i = 0; i < NUMARUL_DE_SUNTURI; i++)
    {
        buffTrimitere[4 + 8 * i] = 0x0;    // def
        buffTrimitere[5 + 8 * i] = 0x0;    // def
        buffTrimitere[6 + 8 * i] = 0x0;    // def
        buffTrimitere[7 + 8 * i] = 0x0;    // def
        buffTrimitere[8 + 8 * i] = 0x01;    // def
        buffTrimitere[9 + 8 * i] = 0xF0;   //
        dpec = pec10_calc(false, 6U, buffTrimitere + 4 + 8 * i);
        buffTrimitere[10 + 8 * i] = dpec >> 8;
        buffTrimitere[11 + 8 * i] = dpec % 256;
    }

    for(int i = 0; i < NUMARUL_DE_MONITOARE; i++)
    {
        buffTrimitere[4 + 8 * NUMARUL_DE_SUNTURI + 8 * i] = 0x00; // default
        buffTrimitere[5 + 8 * NUMARUL_DE_SUNTURI + 8 * i] = 0xF8;    // def
        buffTrimitere[6 + 8 * NUMARUL_DE_SUNTURI + 8 * i] = 0x7F;    // def
        buffTrimitere[7 + 8 * NUMARUL_DE_SUNTURI + 8 * i] = 0x00; // def
        buffTrimitere[8 + 8 * NUMARUL_DE_SUNTURI + 8 * i] = 0xFF; //1-8 cells discharge
        buffTrimitere[9 + 8 * NUMARUL_DE_SUNTURI + 8 * i] = 0x0F; //9-12 cells discharge
        dpec = pec10_calc(false, 6U, buffTrimitere + 4 + 8 * NUMARUL_DE_SUNTURI + 8 * i);
        buffTrimitere[10 + 8 * NUMARUL_DE_SUNTURI + 8 * i] = dpec >> 8;
        buffTrimitere[11 + 8 * NUMARUL_DE_SUNTURI + 8 * i] = dpec % 256;
    }
    transmisieWR48();
}

void parametriiPWM(int nrB)
{
	int masca =0;
	for (int i=0;i<nrB;i++)
		masca = masca | (1<<i);
	masca = masca | ((masca<<4)&0xF0);

    populeazaCMD(0x00, 0x20); // WRPWMA
    for(int i = 0; i < NUMARUL_DE_SUNTURI; i++)
    {
        buffTrimitere[4 + 8 * i] = 0x0;    // def
        buffTrimitere[5 + 8 * i] = 0x0;    // def
        buffTrimitere[6 + 8 * i] = 0x0;    // def
        buffTrimitere[7 + 8 * i] = 0x0;    // def
        buffTrimitere[8 + 8 * i] = 0x0;    // def
        buffTrimitere[9 + 8 * i] = 0x0;    // not valid
        dpec = pec10_calc(false, 6U, buffTrimitere + 4 + 8 * i);
        buffTrimitere[10 + 8 * i] = dpec >> 8;
        buffTrimitere[11 + 8 * i] = dpec % 256;
    }

    for(int i = 0; i < NUMARUL_DE_MONITOARE; i++)
    {
        buffTrimitere[4 + 8 * NUMARUL_DE_SUNTURI + 8 * i] = masca; // default
        buffTrimitere[5 + 8 * NUMARUL_DE_SUNTURI + 8 * i] = masca;    // def
        buffTrimitere[6 + 8 * NUMARUL_DE_SUNTURI + 8 * i] = masca;    // def
        buffTrimitere[7 + 8 * NUMARUL_DE_SUNTURI + 8 * i] = masca; // def
        buffTrimitere[8 + 8 * NUMARUL_DE_SUNTURI + 8 * i] = masca; //1-8 cells discharge
        buffTrimitere[9 + 8 * NUMARUL_DE_SUNTURI + 8 * i] = masca; //9-12 cells discharge
        dpec = pec10_calc(false, 6U, buffTrimitere + 4 + 8 * NUMARUL_DE_SUNTURI + 8 * i);
        buffTrimitere[10 + 8 * NUMARUL_DE_SUNTURI + 8 * i] = dpec >> 8;
        buffTrimitere[11 + 8 * NUMARUL_DE_SUNTURI + 8 * i] = dpec % 256;
    }
    transmisieWR48();
}


/**
* @brief          Șterge flag-urile de eroare/status din BMS.
*
* @return         void
*/
void BmsClearFLAGS()
{
    populeazaCMD(0x17, 0x07);
    transmisieCMD(); // CLRFLG
}

/**
* @brief          Inițiază conversia ADC pentru tensiunile celulelor.
*
* @return         void
*/
void BmsADCV()
{
    populeazaCMD(0x03, 0xE0);
    transmisieCMD(); // ADCV
}

/**
* @brief          Inițiază conversia pentru tensiunile auxiliare (High Voltage).
*
* @return         void
*/
void BmsADV()
{
    populeazaCMD(0x04, 0x30);
    transmisieCMD(); // ADV
}

/**
* @brief          Selectează și execută o comandă de citire dintr-un vector de comenzi.
*
* @param[in]      vector: Pointer către array-ul de comenzi.
* @param[in]      id: Indexul comenzii dorite.
*
* @return         void
*/
void BmsSelectReadCommand(uint8 *vector, uint8 id)
{
    populeazaCMD(0, vector[id]);
    transmisieCMD();
}

/**
* @brief          Citește datele principale de la BMS (Tensiuni celule, Curent, Tensiune pachet).
* @details        Parcurge pachetele de date, calculează valorile reale și gestionează semnul
* pentru curent și tensiunea totală.
*
* @return         void
*/
void readBieMieSe()
{
    BmsADV();
    volatile int delayul = MARELE_DELAY;
    for(int i = 0; i <= 3; i++)
    {
        delayul = MARELE_DELAY;
        while (delayul--) { }
        BmsSelectReadCommand(pacheteAverage, i);

        for(int j = 0; j < NUMARUL_DE_MONITOARE; j++)
        {
        	if(buffPrimire[5 + 8 * j]==0x80) //valoareaDefault
        	{
        		if(j==0)
        			WriteCanDataAtAddress(true, &MonitoredValues.TsacMonitoredValues.Bms0Error);
        		if(j==1)
        			WriteCanDataAtAddress(true, &MonitoredValues.TsacMonitoredValues.Bms1Error);
        	}
        	else if(buffPrimire[5 + 8 * j]==0xFF) //no comms
        	{
        		WriteCanDataAtAddress(true, &MonitoredValues.TsacMonitoredValues.TransceiverError);
       	        WriteUartDataAtAddress(true, &MonitoredValues.TsacMonitoredValues.TransceiverError);
        	}
			else{
				WriteCanDataAtAddress(false, &MonitoredValues.TsacMonitoredValues.TransceiverError);
       	        WriteUartDataAtAddress(false, &MonitoredValues.TsacMonitoredValues.TransceiverError);
			}
            icBaterie.cellVoltage[j * 12 + 0 + i * 3] = 15 * (buffPrimire[5 + 8 * j] * 256 + buffPrimire[4 + 8 * j]) + 150000;
            icBaterie.cellVoltage[j * 12 + 1 + i * 3] = 15 * (buffPrimire[7 + 8 * j] * 256 + buffPrimire[6 + 8 * j]) + 150000;
            icBaterie.cellVoltage[j * 12 + 2 + i * 3] = 15 * (buffPrimire[9 + 8 * j] * 256 + buffPrimire[8 * j]) + 150000;


        }

        if (i == 0)
        {
        	if(buffPrimire[5 + 4 + 8 * NUMARUL_DE_MONITOARE]==0x03)
        	{
        		if(useCAN_messaging)
        		{
        			WriteCanDataAtAddress(true, &MonitoredValues.TsacMonitoredValues.ShuntError);
        		}
        		if(useUART_messaging)
        		{
        			WriteUartDataAtAddress(true, &MonitoredValues.TsacMonitoredValues.ShuntError);
        		}
        	}
        	if(buffPrimire[5 + 4 + 8 * NUMARUL_DE_MONITOARE]==0xFF)
        	{
        		if(useCAN_messaging)
        		{
        			WriteCanDataAtAddress(true, &MonitoredValues.TsacMonitoredValues.TransceiverError);
        		}
				if(useUART_messaging)
        		{
        	    	WriteUartDataAtAddress(true, &MonitoredValues.TsacMonitoredValues.TransceiverError);
        		}
        	}
            icBaterie.packCurrent = ((buffPrimire[5 + 4 + 8 * NUMARUL_DE_MONITOARE] << 16) + (buffPrimire[4 + 4 + 8 * NUMARUL_DE_MONITOARE] << 8) + (buffPrimire[3 + 4 + 8 * NUMARUL_DE_MONITOARE])) * 5;
            if (icBaterie.packCurrent & 0x800000) {
                icBaterie.packCurrent |= 0xFF000000;
            } else {
                icBaterie.packCurrent &= 0x00FFFFFF;
            }
        }
        else if (i == 1) {
            icBaterie.packVoltage = (buffPrimire[2 + 4 + 8 * NUMARUL_DE_MONITOARE] << 16) | (buffPrimire[1 + 4 + 8 * NUMARUL_DE_MONITOARE] << 8) | buffPrimire[4 + 8 * NUMARUL_DE_MONITOARE];
            if (icBaterie.packVoltage & 0x800000) {
                icBaterie.packVoltage |= 0xFF000000;
            } else {
                icBaterie.packVoltage &= 0x00FFFFFF;
            }
        }
    }
}

/**
* @brief          Inițiază conversia ADC în modul Open Wire.
*
* @return         void
*/
void BmsADSV_OW()
{
    populeazaCMD(0x01, 0x6A);
    transmisieCMD(); // ADSV OW
}

/**
* @brief          Citește tensiunile și verifică integritatea conexiunilor (Open Wire).
* @details        Dacă o tensiune depășește pragul STUPID, se consideră fir întrerupt.
*
* @return         void
*/
void readBieMieSeOW()
{
    volatile int delayul;
    for (int i = 0; i <= 3; i++) {
        delayul = MARELE_DELAY;
        while (delayul--) { }
        BmsADSV_OW();
        BmsSelectReadCommand(pacheteOW, i);

        for(int j = 0; j < NUMARUL_DE_MONITOARE; j++)
        {
            tensiuneMILIvolti1 = 15 * (buffPrimire[5 + 8 * j] * 256 + buffPrimire[4 + 8 * j]) + 150000;
            tensiuneMILIvolti2 = 15 * (buffPrimire[7 + 8 * j] * 256 + buffPrimire[6 + 8 * j]) + 150000;
            tensiuneMILIvolti3 = 15 * (buffPrimire[9 + 8 * j] * 256 + buffPrimire[8 * j]) + 150000;

            if(tensiuneMILIvolti1 > CELULA_STUPID)
            {
                icBaterie.cellVoltage[j * 12 + 0 + i * 3] = 0;
                icBaterie.flagOW[j * 12 + 0 + i * 3] = true;
            }
            if(tensiuneMILIvolti2 > CELULA_STUPID)
            {
                icBaterie.cellVoltage[j * 12 + 1 + i * 3] = 0;
                icBaterie.flagOW[j * 12 + 1 + i * 3] = true;
            }
            if(tensiuneMILIvolti3 > CELULA_STUPID)
            {
                icBaterie.cellVoltage[j * 12 + 2 + i * 3] = 0;
                icBaterie.flagOW[j * 12 + 2 + i * 3] = true;
            }
        }
    }
}

/**
* @brief          Trimite toate datele colectate (tensiuni, curent, temperaturi) prin UART/USB.
*
* @return         void
*/
/**
* @brief          Returnează tensiunea unei anumite celule.
*
* @param[in]      index: Indexul celulei dorite.
* @return         int Tensiunea celulei în mV sau 0 dacă indexul este invalid.
*/
int getCelula(int index)
{
    if(index < BATTERY_CELLS)
    {
        return icBaterie.cellVoltage[index];
    }
    return 0;
}

/**
* @brief          Returnează curentul total al pachetului.
* @return         int Curentul pachetului.
*/
int getCurent(void)
{
    return icBaterie.packCurrent;
}

/**
* @brief          Returnează tensiunea totală a pachetului.
* @return         int Tensiunea pachetului.
*/
int getVoltagePachet(void)
{
    return icBaterie.packVoltage;
}

/**
* @brief          Validează configurația registrelor BMS.
* @details        Citește configurația curentă și o compară cu valorile de inițializare.
*
* @return         bool TRUE dacă configurația este corectă, FALSE altfel.
*/
bool CFGAok(void)
{
    BmsReadConfigA();
    int offset;
    for(int i = 0; i < NUMARUL_DE_SUNTURI; i++)
    {
        if(buffPrimire[4 + 8 * i] != 0x00) return false;
        if(buffPrimire[5 + 8 * i] != 0x00) return false;
        if(buffPrimire[6 + 8 * i] != 0x00) return false;
        if(buffPrimire[7 + 8 * i] != 0x5F) return false;
        if(buffPrimire[8 + 8 * i] != 0x00) return false;
        if(buffPrimire[9 + 8 * i] != 0x10) return false;
    }

    for(int i = 0; i < NUMARUL_DE_MONITOARE; i++)
    {
        offset = 4 + 8 * NUMARUL_DE_SUNTURI + 8 * i;
        if(buffPrimire[offset + 0] != 0x81) return false;
        if(buffPrimire[offset + 1] != 0x00) return false;
        if(buffPrimire[offset + 2] != 0x00) return false;
        if(buffPrimire[offset + 3] != 0xFF) return false;
        if(buffPrimire[offset + 4] != 0x03) return false;
        if(buffPrimire[offset + 5] != 0x10) return false;
    }
    return true;
}

/**
* @brief          Inițializează sistemul BMS.
* @details        Configurează ADC, pornește conversiile inițiale și curăță stările.
*
* @return         void
*/
void bmsInit(void)
{
    parametriiADC();
    BmsADCV();
    BmsADV();
    flushTX();
}


/**
* @brief          Getter pentru curentul pachetului.
* @return         int Curentul pachetului.
*/
int BmsGetPackCurrent(void)
{
    return icBaterie.packCurrent;
}

/**
* @brief          Getter pentru tensiunea pachetului.
* @return         int Tensiunea pachetului.
*/
int BmsGetPackVoltage(void)
{
    return icBaterie.packVoltage;
}

/**
* @brief          Identifică cea mai mare tensiune de celulă din pachet.
*
* @return         int Tensiunea maximă găsită (mV).
*/
int BmsGetHighestCellVoltage(void)
{
    int max = 0;
    for (int i = 0; i < BATTERY_CELLS; i++)
        if(icBaterie.cellVoltage[i] > max)
            max = icBaterie.cellVoltage[i];

    return max;
}

/**
* @brief          Identifică cea mai mica tensiune de celulă din pachet.
*
* @return         int Tensiunea minima găsită (mV).
*/
int BmsGetLowestCellVoltage(void)
{
    int min = icBaterie.cellVoltage[0];
    for (int i = 0; i < BATTERY_CELLS; i++)
        if(icBaterie.cellVoltage[i] < min)
            min = icBaterie.cellVoltage[i];

    return min;
}


int BmsGetOverallCellVoltage(void)
{
	int medie=0;
	for (int i = 0; i < BATTERY_CELLS; i++)
		medie+=(icBaterie.cellVoltage[i]/BATTERY_CELLS);

	return medie;
}
/*!<**************************************** BMS Driver APIs definitions ********************************************/

/*!<
* @brief Precomputed CRC15 Table
*/
const uint16 Crc15Table[256] =
{
  0x0000,0xc599, 0xceab, 0xb32, 0xd8cf, 0x1d56, 0x1664, 0xd3fd, 0xf407, 0x319e, 0x3aac,
  0xff35, 0x2cc8, 0xe951, 0xe263, 0x27fa, 0xad97, 0x680e, 0x633c, 0xa6a5, 0x7558, 0xb0c1,
  0xbbf3, 0x7e6a, 0x5990, 0x9c09, 0x973b, 0x52a2, 0x815f, 0x44c6, 0x4ff4, 0x8a6d, 0x5b2e,
  0x9eb7, 0x9585, 0x501c, 0x83e1, 0x4678, 0x4d4a, 0x88d3, 0xaf29, 0x6ab0, 0x6182, 0xa41b,
  0x77e6, 0xb27f, 0xb94d, 0x7cd4, 0xf6b9, 0x3320, 0x3812, 0xfd8b, 0x2e76, 0xebef, 0xe0dd,
  0x2544, 0x2be, 0xc727, 0xcc15, 0x98c, 0xda71, 0x1fe8, 0x14da, 0xd143, 0xf3c5, 0x365c,
  0x3d6e, 0xf8f7,0x2b0a, 0xee93, 0xe5a1, 0x2038, 0x7c2, 0xc25b, 0xc969, 0xcf0, 0xdf0d,
  0x1a94, 0x11a6, 0xd43f, 0x5e52, 0x9bcb, 0x90f9, 0x5560, 0x869d, 0x4304, 0x4836, 0x8daf,
  0xaa55, 0x6fcc, 0x64fe, 0xa167, 0x729a, 0xb703, 0xbc31, 0x79a8, 0xa8eb, 0x6d72, 0x6640,
  0xa3d9, 0x7024, 0xb5bd, 0xbe8f, 0x7b16, 0x5cec, 0x9975, 0x9247, 0x57de, 0x8423, 0x41ba,
  0x4a88, 0x8f11, 0x57c, 0xc0e5, 0xcbd7, 0xe4e, 0xddb3, 0x182a, 0x1318, 0xd681, 0xf17b,
  0x34e2, 0x3fd0, 0xfa49, 0x29b4, 0xec2d, 0xe71f, 0x2286, 0xa213, 0x678a, 0x6cb8, 0xa921,
  0x7adc, 0xbf45, 0xb477, 0x71ee, 0x5614, 0x938d, 0x98bf, 0x5d26, 0x8edb, 0x4b42, 0x4070,
  0x85e9, 0xf84, 0xca1d, 0xc12f, 0x4b6, 0xd74b, 0x12d2, 0x19e0, 0xdc79, 0xfb83, 0x3e1a, 0x3528,
  0xf0b1, 0x234c, 0xe6d5, 0xede7, 0x287e, 0xf93d, 0x3ca4, 0x3796, 0xf20f, 0x21f2, 0xe46b, 0xef59,
  0x2ac0, 0xd3a, 0xc8a3, 0xc391, 0x608, 0xd5f5, 0x106c, 0x1b5e, 0xdec7, 0x54aa, 0x9133, 0x9a01,
  0x5f98, 0x8c65, 0x49fc, 0x42ce, 0x8757, 0xa0ad, 0x6534, 0x6e06, 0xab9f, 0x7862, 0xbdfb, 0xb6c9,
  0x7350, 0x51d6, 0x944f, 0x9f7d, 0x5ae4, 0x8919, 0x4c80, 0x47b2, 0x822b, 0xa5d1, 0x6048, 0x6b7a,
  0xaee3, 0x7d1e, 0xb887, 0xb3b5, 0x762c, 0xfc41, 0x39d8, 0x32ea, 0xf773, 0x248e, 0xe117, 0xea25,
  0x2fbc, 0x846, 0xcddf, 0xc6ed, 0x374, 0xd089, 0x1510, 0x1e22, 0xdbbb, 0xaf8, 0xcf61, 0xc453,
  0x1ca, 0xd237, 0x17ae, 0x1c9c, 0xd905, 0xfeff, 0x3b66, 0x3054, 0xf5cd, 0x2630, 0xe3a9, 0xe89b,
  0x2d02, 0xa76f, 0x62f6, 0x69c4, 0xac5d, 0x7fa0, 0xba39, 0xb10b, 0x7492, 0x5368, 0x96f1, 0x9dc3,
  0x585a, 0x8ba7, 0x4e3e, 0x450c, 0x8095
};

/* Pre-computed CRC10 Table
static const uint16 crc10Table[256] =
    {
        0x000, 0x08f, 0x11e, 0x191, 0x23c, 0x2b3, 0x322, 0x3ad, 0x0f7, 0x078, 0x1e9, 0x166, 0x2cb, 0x244, 0x3d5, 0x35a,
        0x1ee, 0x161, 0x0f0, 0x07f, 0x3d2, 0x35d, 0x2cc, 0x243, 0x119, 0x196, 0x007, 0x088, 0x325, 0x3aa, 0x23b, 0x2b4,
        0x3dc, 0x353, 0x2c2, 0x24d, 0x1e0, 0x16f, 0x0fe, 0x071, 0x32b, 0x3a4, 0x235, 0x2ba, 0x117, 0x198, 0x009, 0x086,
        0x232, 0x2bd, 0x32c, 0x3a3, 0x00e, 0x081, 0x110, 0x19f, 0x2c5, 0x24a, 0x3db, 0x354, 0x0f9, 0x076, 0x1e7, 0x168,
        0x337, 0x3b8, 0x229, 0x2a6, 0x10b, 0x184, 0x015, 0x09a, 0x3c0, 0x34f, 0x2de, 0x251, 0x1fc, 0x173, 0x0e2, 0x06d,
        0x2d9, 0x256, 0x3c7, 0x348, 0x0e5, 0x06a, 0x1fb, 0x174, 0x22e, 0x2a1, 0x330, 0x3bf, 0x012, 0x09d, 0x10c, 0x183,
        0x0eb, 0x064, 0x1f5, 0x17a, 0x2d7, 0x258, 0x3c9, 0x346, 0x01c, 0x093, 0x102, 0x18d, 0x220, 0x2af, 0x33e, 0x3b1,
        0x105, 0x18a, 0x01b, 0x094, 0x339, 0x3b6, 0x227, 0x2a8, 0x1f2, 0x17d, 0x0ec, 0x063, 0x3ce, 0x341, 0x2d0, 0x25f,
        0x2e1, 0x26e, 0x3ff, 0x370, 0x0dd, 0x052, 0x1c3, 0x14c, 0x216, 0x299, 0x308, 0x387, 0x02a, 0x0a5, 0x134, 0x1bb,
        0x30f, 0x380, 0x211, 0x29e, 0x133, 0x1bc, 0x02d, 0x0a2, 0x3f8, 0x377, 0x2e6, 0x269, 0x1c4, 0x14b, 0x0da, 0x055,
        0x13d, 0x1b2, 0x023, 0x0ac, 0x301, 0x38e, 0x21f, 0x290, 0x1ca, 0x145, 0x0d4, 0x05b, 0x3f6, 0x379, 0x2e8, 0x267,
        0x0d3, 0x05c, 0x1cd, 0x142, 0x2ef, 0x260, 0x3f1, 0x37e, 0x024, 0x0ab, 0x13a, 0x1b5, 0x218, 0x297, 0x306, 0x389,
        0x1d6, 0x159, 0x0c8, 0x047, 0x3ea, 0x365, 0x2f4, 0x27b, 0x121, 0x1ae, 0x03f, 0x0b0, 0x31d, 0x392, 0x203, 0x28c,
        0x038, 0x0b7, 0x126, 0x1a9, 0x204, 0x28b, 0x31a, 0x395, 0x0cf, 0x040, 0x1d1, 0x15e, 0x2f3, 0x27c, 0x3ed, 0x362,
        0x20a, 0x285, 0x314, 0x39b, 0x036, 0x0b9, 0x128, 0x1a7, 0x2fd, 0x272, 0x3e3, 0x36c, 0x0c1, 0x04e, 0x1df, 0x150,
        0x3e4, 0x36b, 0x2fa, 0x275, 0x1d8, 0x157, 0x0c6, 0x049, 0x313, 0x39c, 0x20d, 0x282, 0x12f, 0x1a0, 0x031, 0x0be};
Const 16 section end */


/**
*******************************************************************************
* Function: Pec15_Calc
* @brief CRC15 Pec Calculation Function
*
* @details This function calculates and return the CRC15 value
*
* Parameters:
* @param [in]	Len	Data length
*
* @param [in] *data    Data pointer
*
* @return CRC15_Value
*
*******************************************************************************
*/
uint16 Pec15_Calc
(
	uint8 len, /*!< Number of bytes that will be used to calculate a PEC */
	uint8 *data /*!< Array of data that will be used to calculate  a PEC */
)
{
  uint16 remainder,addr;
  remainder = 16u; /*!< initialize the PEC */
  for (uint8 i = 0; i<len; i++) /*!< loops for each byte in data array */
  {
    addr = (((remainder>>7u)^data[i])&0xff);/*!< calculate PEC table address */
    remainder = ((remainder<<8u)^Crc15Table[addr]);
  }
  return(remainder*2u);/*!< The CRC15 has a 0 in the LSB so the remainder must be multiplied by 2 */
}

/**
*******************************************************************************
* Function: Pec10_Calc
* @brief CRC10 Pec Calculation Function
*
* @details This function calculates and return the CRC15 value
*
* Parameters:
* @param [in]	Len	Data length
*
* @param [in] *data    Data pointer
*
* @return CRC10_Value
*
*******************************************************************************
*/
uint16 pec10_calc(bool rx_cmd, int len, uint8 *data)
{
  uint16 remainder = 16u; /*!< PEC_SEED;   0000010000 */
  uint16 polynom = 0x8F; /*!< x10 + x7 + x3 + x2 + x + 1 <- the CRC15 polynomial         100 1000 1111   48F */

  /*!< Perform modulo-2 division, a byte at a time. */
  for (uint8 pbyte = 0; pbyte < len; ++pbyte)
  {
    /*!< Bring the next byte into the remainder. */
    remainder ^= (uint16)((uint16)data[pbyte] << 2u);
    /*!< Perform modulo-2 division, a bit at a time.*/
    for (uint8 bit_ = 8u; bit_ > 0u; --bit_)
    {
      /*!< Try to divide the current data bit. */
      if ((remainder & 0x200) > 0u)/*!<equivalent to remainder & 2^14 simply check for MSB */
      {
        remainder = (uint16)((remainder << 1u));
        remainder = (uint16)(remainder ^ polynom);
      }
      else
      {
        remainder = (uint16)(remainder << 1u);
      }
    }
  }
  if (rx_cmd == true)
  {
    remainder ^= (uint16)(((uint16)data[len] & (uint8)0xFC) << 2u);
  }
  /*!< Perform modulo-2 division, a bit at a time */
  for (uint8 bit_ = 6u; bit_ > 0u; --bit_)
  {
    /*!< Try to divide the current data bit */
    if ((remainder & 0x200) > 0u)/*!<equivalent to remainder & 2^14 simply check for MSB*/
    {
      remainder = (uint16)((remainder << 1u));
      remainder = (uint16)(remainder ^ polynom);
    }
    else
    {
      remainder = (uint16)((remainder << 1u));
    }
  }
  return ((uint16)(remainder & 0x3FFu));
}

/**
*******************************************************************************
* Function: pec10_calc_modular
* @brief calculate data pec
*
* @details This function is used to calculate Data PEC.
*
* @return Pec
*
*******************************************************************************
*/
#if 0
uint16 pec10_calc_modular(
    uint8 * data, // Array of data that will be used to calculate a PEC
    uint8 PEC_Format // use any of PEC10_...
)
{
    uint16 remainder = 16u; // PEC_SEED;
    uint16 len;
    switch (PEC_Format)
    {
    case PEC10_WRITE:
        data[6] = 0; // for write commands the command counter is all zero
        // step through
    case PEC10_READ:
        len = 6;
        break;
    case PEC10_READ256:
        len = 256;
        break;
    case PEC10_READ512:
        len = 512;
        break;
    case PEC10_WRITE2:
        data[2] = 0;
        // step through
    case PEC10_READ2:
        len = 2;
        break;
    default:
        return 0xFFFF;
        break;
    }
    //Perform modulo-2 division, a byte at a time.
    for (uint8 pbyte = 0; pbyte < len; ++pbyte)
    {
        // Bring the next byte into the remainder.
        remainder ^= (uint16)(data[pbyte]) << 2u;
        remainder = pec10_calc_int(remainder, 8u);
    }
    // the last byte is different as it holds the 6-bit command counter
    // Note: for write commands, those bits are zero!
    remainder ^= (uint16)((data[len] & 0xFC) << 2u);
    remainder = pec10_calc_int(remainder, 6u);
    return ((uint16)(remainder & 0x3FF));
}
#endif
/**
*******************************************************************************
* Function: pec10_calc_int
* @brief calculate data pec
*
* @details This function is used to calculate Data PEC.
*
* @return Pec
*
*******************************************************************************
*/
#if 0
uint16 pec10_calc_int(uint16 remainder, uint8 bit)
{
  uint8 PEC10_POLY = 0x8F;
    //Perform modulo-2 division, a bit at a time.
    //Perform modulo-2 division, a bit at a time.
    for (; bit > 0; --bit)
    {
        //Try to divide the current data bit.
        if ((remainder & 0x200u) > 0u)//equivalent to remainder & 2^14 simply check for MSB
        {
            remainder = (uint16)((remainder << 1u));
            remainder = (uint16)(remainder ^ PEC10_POLY);
        }
        else
        {
            remainder = (uint16)(remainder << 1u);
        }
    }
    return ((uint16)(remainder & 0x3FFu));
}
#endif

