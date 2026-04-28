#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
 *                                        INCLUDE FILES
 *==================================================================================================*/

#include "thermistor_mux.h"
#include "lut.h"
#include "Dio.h"
#include "Port.h"
#include "Adc.h"

/*==================================================================================================
 *                                      LOCAL VARIABLES
 *==================================================================================================*/

Thermistors Thermistors_Data;

// Index:        0    1    2    3    4    5    6    7
//               8    9   10   11   12   13   14   15

uint16 bankselpins[16] = {
    129, 103, 142, 141, 47, 48, 49, 46,
    144, 143, 102, 79, 7, 45, 15, 16
};

uint32 bankselpinsid[16] = {
    19, 20, 17, 18, 8, 10, 6, 7,
    15, 16, 21, 22, 13, 14, 11, 12
};

uint16 adcreadchannels[THERMISTORS_PER_BANK] = {0, 1, 2, 3, 4, 5, 6, 7};

/*==================================================================================================
 *                                       LOCAL FUNCTIONS
 *==================================================================================================*/

static void ActivateThermistorBank(uint16 ThermistorBankIndex)
{
    Port_SetPinDirection(
        Thermistors_Data.BankSelectPinsID[ThermistorBankIndex],
        PORT_PIN_OUT
    );

    Dio_WriteChannel(
        Thermistors_Data.BankSelectPins[ThermistorBankIndex],
        STD_LOW
    );
}

static void DeactivateThermistorBank(uint16 ThermistorBankIndex)
{
    Port_SetPinDirection(
        Thermistors_Data.BankSelectPinsID[ThermistorBankIndex],
        PORT_PIN_HIGH_Z
    );
}

/*==================================================================================================
 *                                       GLOBAL FUNCTIONS
 *==================================================================================================*/

void TempSensorInit()
{
    for (int i = 0; i < THERMISTOR_BANKS; i++)
    {
        for (int j = 0; j < THERMISTORS_PER_BANK; j++)
        {
            Thermistors_Data.ThermistorValues[i][j] = 0;
            Thermistors_Data.BankReadChannels[j] = adcreadchannels[j];
        }

        Thermistors_Data.BankSelectPins[i] = bankselpins[i];
        Thermistors_Data.BankSelectPinsID[i] = bankselpinsid[i];
    }

    for (int i = 0; i < THERMISTOR_BANKS; i++)
    {
        DeactivateThermistorBank(i);
    }
}

sint32 GetTemp(uint16 TempSensorIndex)
{
    ActivateThermistorBank(TempSensorIndex);

    for (int i = 0; i < THERMISTORS_PER_BANK; i++)
    {
        Adc_SetupResultBuffer(
            Thermistors_Data.BankReadChannels[i],
            &Thermistors_Data.ThermistorValues[TempSensorIndex][i]
        );

        Adc_StartGroupConversion(
            Thermistors_Data.BankReadChannels[i]
        );

        while (Adc_GetGroupStatus(
                   Thermistors_Data.BankReadChannels[i]) != ADC_STREAM_COMPLETED)
        {
        }

        Adc_ReadGroup(
            Thermistors_Data.BankReadChannels[i],
            &Thermistors_Data.ThermistorValues[TempSensorIndex][i]
        );
    }

    DeactivateThermistorBank(TempSensorIndex);

    return 0;
}

void corectieValoriADC(void)
{
    // corecteaza valorile aberante, gasite empiric
	// TODO dovedit care exact sunt
    Thermistors_Data.ThermistorValues[7][0]  = Thermistors_Data.ThermistorValues[7][1];
    Thermistors_Data.ThermistorValues[6][0]  = Thermistors_Data.ThermistorValues[6][1];
    Thermistors_Data.ThermistorValues[11][1] = Thermistors_Data.ThermistorValues[11][0];
    Thermistors_Data.ThermistorValues[13][7] = Thermistors_Data.ThermistorValues[13][6];
    Thermistors_Data.ThermistorValues[12][7] = Thermistors_Data.ThermistorValues[12][6];
    Thermistors_Data.ThermistorValues[12][4] = Thermistors_Data.ThermistorValues[12][3];

    Thermistors_Data.ThermistorValues[14][3] = Thermistors_Data.ThermistorValues[14][1];
    Thermistors_Data.ThermistorValues[14][2] = Thermistors_Data.ThermistorValues[14][0];
}

uint16 getMin(void)
{
    uint16 min = 65000;

    for (int i = 0; i < THERMISTOR_BANKS; i++)
    {
        for (int j = 0; j < THERMISTORS_PER_BANK; j++)
        {
            if (Thermistors_Data.ThermistorValues[i][j] < min)
            {
                min = Thermistors_Data.ThermistorValues[i][j];
            }
        }
    }

    return min;
}

uint16 getMax(void)
{
    uint16 max = 0;

    for (int i = 0; i < THERMISTOR_BANKS; i++)
    {
        for (int j = 0; j < THERMISTORS_PER_BANK; j++)
        {
            if (Thermistors_Data.ThermistorValues[i][j] > max)
            {
                max = Thermistors_Data.ThermistorValues[i][j];
            }
        }
    }

    return max;
}

uint16 getMedie(void)
{
    uint32 medie = 0;

    for (int i = 0; i < THERMISTOR_BANKS; i++)
    {
        for (int j = 0; j < THERMISTORS_PER_BANK; j++)
        {
            medie += Thermistors_Data.ThermistorValues[i][j];
        }
    }

    return medie / (THERMISTOR_BANKS * THERMISTORS_PER_BANK);
}

void citesteToateADC(void)
{
    for (int i = 0; i < THERMISTOR_BANKS; i++)
    {
        GetTemp(i);
    }
}

void lookUPtemperaturi(void)
{
    for (int i = 0; i < THERMISTOR_BANKS; i++)
    {
        for (int j = 0; j < THERMISTORS_PER_BANK; j++)
        {
            Thermistors_Data.temperaturi[i][j] =
                temp_lut[Thermistors_Data.ThermistorValues[i][j]];
        }
    }
}

#ifdef __cplusplus
}
#endif

/** @} */
