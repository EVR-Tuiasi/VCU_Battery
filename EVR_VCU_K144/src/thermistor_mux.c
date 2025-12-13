#ifdef __cplusplus
extern "C" {
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "thermistor_mux.h"
#include "Dio.h"
#include "Port.h"
#include "Adc.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

Thermistors Thermistors_Data;

// Nume temporare pt buffere

uint16 bankselpins[THERMISTOR_BANKS] = {46, 47, 48, 15, 16, 7, 45,  129, 103, 102, 79, 49, 144, 143, 142, 141};
uint32	bankselpinsid[THERMISTOR_BANKS] = {7, 8, 10 ,11 ,12 ,13 , 14 ,  19, 20, 21, 22, 6, 16, 16, 17, 18};
uint16 adcreadchannels[THERMISTORS_PER_BANK] = {0,1,2,3,4,5,6,7};


/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

static void ActivateThermistorBank(uint16 ThermistorBankIndex){


	Port_SetPinDirection(Thermistors_Data.BankSelectPinsID[ThermistorBankIndex], PORT_PIN_OUT);
	Dio_WriteChannel(Thermistors_Data.BankSelectPins[ThermistorBankIndex], STD_LOW);
}

static void DeactivateThermistorBank(uint16 ThermistorBankIndex){
	Port_SetPinDirection(Thermistors_Data.BankSelectPinsID[ThermistorBankIndex], PORT_PIN_HIGH_Z);
}

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

void TempSensorInit(){
	for(int i = 0; i < THERMISTOR_BANKS; i++){
		for(int j = 0; j < THERMISTORS_PER_BANK; j++){
			Thermistors_Data.ThermistorValues[i][j] = 0;
			Thermistors_Data.BankReadChannels[j] = adcreadchannels[j];
		}
		Thermistors_Data.BankSelectPins[i] = bankselpins[i];
		Thermistors_Data.BankSelectPinsID[i] = bankselpinsid[i];
	}

	for(int i = 0; i < THERMISTOR_BANKS; i++){
		DeactivateThermistorBank(i);
	}
}

sint32 GetTemp(uint16 TempSensorIndex){
	ActivateThermistorBank(TempSensorIndex);

	sint32 temp_dummy = 0;
	for(int i = 0; i < THERMISTORS_PER_BANK; i++){
		Adc_SetupResultBuffer(Thermistors_Data.BankReadChannels[i], &Thermistors_Data.ThermistorValues[TempSensorIndex][i]);
		Adc_StartGroupConversion(Thermistors_Data.BankReadChannels[i]);

		while(Adc_GetGroupStatus(Thermistors_Data.BankReadChannels[i]) != ADC_STREAM_COMPLETED);

		Adc_ReadGroup(Thermistors_Data.BankReadChannels[i], &Thermistors_Data.ThermistorValues[TempSensorIndex][i]);
	}

	DeactivateThermistorBank(TempSensorIndex);

	// Probabil calcul matematic pentru temperatura
	temp_dummy++;
	return temp_dummy;
}

void TempSensorTest(){
	;
}

void corectieTemperatura(){
	for(int i=0;i<THERMISTOR_BANKS;i++)
	    	{
	    		for(int j=0;j<THERMISTORS_PER_BANK;j++)
	    		{
	    			//if(Thermistors_Data.ThermistorValues[i][j]<1040)
	    			//	Thermistors_Data.ThermistorValues[i][j]=1040;
	    			//else if(Thermistors_Data.ThermistorValues[i][j]>2074)
	    			//	Thermistors_Data.ThermistorValues[i][j]=2074;

	    			if(Thermistors_Data.ThermistorValues[i][j]>=1140)
	    			{
	    				Thermistors_Data.temperaturiF[i][j]=68400/Thermistors_Data.ThermistorValues[i][j];
	    				//60 65
	    			}
	    			else if(Thermistors_Data.temperaturiF[i][j]>=1248)
	    			{
	    				//55 60
	    				Thermistors_Data.ThermistorValues[i][j]=68640/Thermistors_Data.ThermistorValues[i][j];
	    			}
	    			else if(Thermistors_Data.temperaturiF[i][j]>=1399)
	    			{
	    			    				//55 50
	    				Thermistors_Data.temperaturiF[i][j]=69950/Thermistors_Data.ThermistorValues[i][j];
	    			}
	    			else if(Thermistors_Data.temperaturi[i][j]>=1545)
	    			{
	    			    				//50 45
	    				Thermistors_Data.temperaturiF[i][j]=69525/Thermistors_Data.ThermistorValues[i][j];
	    			}
	    			else if(Thermistors_Data.temperaturi[i][j]>=1708)
	    			{
	    			    				//45 40
	    				Thermistors_Data.temperaturiF[i][j]=68325/Thermistors_Data.ThermistorValues[i][j];
	    			}
	    			else if(Thermistors_Data.temperaturi[i][j]>=1881)
	    			{
	    			    				//40 35
	    				Thermistors_Data.temperaturiF[i][j]=65835/Thermistors_Data.ThermistorValues[i][j];
	    			}
	    			else
	    			{
	    			    				//35 30
	    				Thermistors_Data.temperaturi[i][j]=61410/Thermistors_Data.ThermistorValues[i][j];
	    			}
	    				//
	    		}
	    	}
}

#ifdef __cplusplus
}
#endif

/** @} */
