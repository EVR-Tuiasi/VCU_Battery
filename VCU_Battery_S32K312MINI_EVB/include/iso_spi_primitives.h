/*
 * bms_cosa.h
 *
 * Created on: 29 apr. 2025
 * Author: cosaa
 */

#ifndef BMS_COSA_H_
#define BMS_COSA_H_

#include "Mcu.h"

/* -------------------------------------------------------------------------- */
/* CONFIGURARE                               */
/* -------------------------------------------------------------------------- */

#define BATTERY_CELLS           24
#define NUMARUL_DE_MONITOARE    2
#define NUMARUL_DE_SUNTURI      1
#define BMS_CS                  28 // ID Pinul de CS -1

/* -------------------------------------------------------------------------- */
/* LIMITE SI PRAGURI                            */
/* -------------------------------------------------------------------------- */

#define CURENT_MAX              600000   // mA => 600A
#define TENSIUNE_MAX            10100    // 101V (format unitate masura...)
#define TENSIUNE_MIN            6000     // 60V
#define UNDERVOLTAGE_CELL       350000   // *100mV => 3.5V
#define OVERVOLTAGE_CELL        423000   // 4.23V

#define MARELE_DELAY            400000   // Delay loop/comunicatie

/* -------------------------------------------------------------------------- */
/* VALORI DE EROARE (STUPID)                       */
/* -------------------------------------------------------------------------- */

#define CURENT_STUPID           1000000  // Valoare eroare comunicatie
#define TENSIUNE_STUPID         1000000  // Valoare eroare comunicatie
#define CELULA_STUPID           500000   // Valoare eroare comunicatie

/* -------------------------------------------------------------------------- */
/* STRUCTURI DATE                               */
/* -------------------------------------------------------------------------- */

struct biemese {
    int packCurrent;
    int packVoltage;
    int cellVoltage[BATTERY_CELLS];
    bool flag;
    bool flagOW[BATTERY_CELLS];
    uint8 stateBMS[NUMARUL_DE_MONITOARE];
    uint8 stateSHUNT;
};

/* -------------------------------------------------------------------------- */
/* PROTOTIPURI FUNCTII                               */
/* -------------------------------------------------------------------------- */

/** --- Initializare si Control BMS --- **/
void bmsInit(void);
void BmsTest(void);
void BmsClearFLAGS(void);
void clearStates(void);
void Bms_RESET(void);

/** --- Achizitie Date (ADC & Masuratori) --- **/
void BmsADCV(void);         // Cell Voltage
void BmsADV(void);          // Auxiliary Voltage
void BmsADSV_OW(void);      // Open Wire detection
void parametriiADC(void);
void parametriiADCB(void);
void parametriiCFGB(void);
void parametriiPWM(int nrB);

/** --- Getters (Returneaza valori calculate) --- **/
int BmsGetPackCurrent(void);
int BmsGetPackVoltage(void);
int BmsGetHighestCellVoltage(void);
int BmsGetLowestCellVoltage(void);
int getCelula(int index);
int getCurent(void);
int getVoltagePachet(void);
bool CFGAok(void);
int BmsGetOverallCellVoltage(void);

/** --- Comunicatie Low-Level (SPI/isoSPI) --- **/
void transmisieCMD(void);
void transmisieRD48(void);
void populeazaCMD(char MSB, char LSB);
void flushTX(void);
void BmsReadConfigA(void);
void BmsReadConfigB(void);
void BmsReadID(void);
void BmsSelectReadCommand(uint8 *vector, uint8 id);
void unMuteDischarge(void);
void muteDischarge(void);

/** --- Algoritmi si Calcul (PEC) --- **/
uint16 pec10_calc(bool rx_cmd, int len, uint8 *data);
uint16 Pec15_Calc(
uint8 len, /*!< Number of bytes that will be used to calculate a PEC */
uint8 *data /*!< Array of data that will be used to calculate  a PEC */
);

/** --- Logica BMS & Citire Date --- **/
void readBieMieSe(void);
void readBieMieSeOW(void);
void readShuntOW(void);

/** --- Comunicatie Seriala (UART) / Erori --- **/
void sendAllUart(void);
void generateAMS(void);
void generateOW(void);
void sendErori(void);
void sendEroareUnitate(int index);

#endif /* BMS_COSA_H_ */
