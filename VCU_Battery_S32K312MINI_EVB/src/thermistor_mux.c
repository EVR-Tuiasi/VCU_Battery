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

uint16 bankselpins[16] = {  //PCR
    129, 103, 142, 141, 47, 48, 49, 46,
    144, 143, 102, 79, 7, 45, 15, 16
};

uint32 bankselpinsid[16] = { //ID-ul lor din
    19, 20, 17, 18, 8, 10, 6, 7,
    15, 16, 21, 22, 13, 14, 11, 12
};

uint16 adcreadchannels[THERMISTORS_PER_BANK] = {0, 1, 2, 3, 4, 5, 6, 7};

/*==================================================================================================
 *                                       LOCAL FUNCTIONS
 *==================================================================================================*/

/**
* @brief          Activates a thermistor bank by configuring the pin as output and driving it low.
* @details        This function enables the selected thermistor bank for ADC reading.
*
* @param[in]      ThermistorBankIndex: Index of the thermistor bank to activate.
*
* @return         void
*
* @pre            Thermistors_Data must be initialized.
* @post           Selected bank is active (enabled).
*/
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

/**
* @brief          Deactivates a thermistor bank by setting the pin to high impedance.
* @details        This function disables the selected thermistor bank.
*
* @param[in]      ThermistorBankIndex: Index of the thermistor bank to deactivate.
*
* @return         void
*
* @pre            Thermistors_Data must be initialized.
* @post           Selected bank is inactive (high-Z).
*/
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

/**
* @brief          Initializes thermistor system data and hardware configuration.
* @details        Initializes buffers, ADC channels and bank selection pins,
*                 then ensures all banks are deactivated.
*
* @return         void
*
* @pre            None
* @post           Thermistor system is initialized and all banks are inactive.
*/
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

/**
* @brief          Reads ADC values for all thermistors in a specific bank.
* @details        Activates the selected bank, performs ADC conversions for each channel,
*                 and stores the results in Thermistors_Data structure.
*
* @param[in]      TempSensorIndex: Index of the thermistor bank to read.
*
* @return         sint32 Always returns 0 (placeholder for future use).
*
* @pre            TempSensorInit must be called.
* @post           ADC values for selected bank are updated.
*/
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

/**
* @brief          Applies manual correction to specific ADC values.
* @details        Corrects empirically identified abnormal ADC readings.
*                 This is a temporary workaround and should be reviewed.
*
* @return         void
*
* @pre            ADC values must be available.
* @post           Selected values are overwritten with corrected ones.
*/
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

/**
* @brief          Returns the minimum ADC value across all thermistors.
* @details        Iterates through all banks and channels to find the smallest value.
*
* @return         uint16 Minimum ADC value.
*
* @pre            ADC values must be updated.
* @post           None
*/
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

/**
* @brief          Returns the maximum ADC value across all thermistors.
* @details        Iterates through all banks and channels to find the largest value.
*
* @return         uint16 Maximum ADC value.
*
* @pre            ADC values must be updated.
* @post           None
*/
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

/**
* @brief          Computes the average ADC value across all thermistors.
* @details        Sums all values and divides by total number of thermistors.
*
* @return         uint16 Average ADC value.
*
* @pre            ADC values must be updated.
* @post           None
*/
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

/**
* @brief          Reads ADC values for all thermistor banks.
* @details        Iterates through all banks and calls GetTemp().
*
* @return         void
*
* @pre            TempSensorInit must be called.
* @post           All ADC values are updated.
*/
void citesteToateADC(void)
{
    for (int i = 0; i < THERMISTOR_BANKS; i++)
    {
        GetTemp(i);
    }
}

/**
* @brief          Converts ADC values to temperature using lookup table.
* @details        Maps each ADC value to a temperature using temp_lut.
*
* @return         void
*
* @pre            ADC values must be available.
* @post           Temperature matrix is updated.
*/
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
