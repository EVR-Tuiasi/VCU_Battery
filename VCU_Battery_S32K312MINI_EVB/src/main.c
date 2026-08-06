
#ifdef __cplusplus
extern "C" {
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Adc.h"
#include "Mcl.h"
#include "Dio.h"
#include "Mcu.h"
#include "Spi.h"
#include "Platform.h"
#include "Port.h"
#include "CDD_Uart.h"
#include "Can_GeneralTypes.h"
#include "Can_43_FLEXCAN.h"
#include "CanIf.h"
#include "SchM_Can_43_FLEXCAN.h"
#include "Gpt.h"

#include "CanMessaging.h"
#include "UartMessaging.h"
#include "Messaging.h"

#include "thermistor_mux.h"
#include "iso_spi_primitives.h"
#include "lut.h"
#include "charger.h"
#include "BMS_config.h"
#include "ams.h"
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
bool stateAMS=false;

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
extern struct biemese icBaterie;
extern Thermistors Thermistors_Data;
extern uint8 buffPrimire[64];
extern MonitoredValues_t MonitoredValues;
/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

int main(void)
{

    /* Initialize the Mcu driver */
#if (MCU_PRECOMPILE_SUPPORT == STD_ON)
    Mcu_Init(NULL_PTR);
#elif (MCU_PRECOMPILE_SUPPORT == STD_OFF)
    Mcu_Init(&Mcu_Config_VS_0);
#endif /* (MCU_PRECOMPILE_SUPPORT == STD_ON) */

    /* Initialize the clock tree and apply PLL as system clock */
    Mcu_InitClock(McuClockSettingConfig_0);
#if (MCU_NO_PLL == STD_OFF)
    while ( MCU_PLL_LOCKED != Mcu_GetPllStatus() )
    {
        /* Busy wait until the System PLL is locked */
    }
    Mcu_DistributePllClock();
#endif
    Mcu_SetMode(McuModeSettingConf_0);

    /* Initialize all pins using the Port driver */
    Mcl_Init(NULL_PTR);
    Port_Init(NULL_PTR);
    Platform_Init(NULL_PTR);
    Adc_Init(NULL_PTR);
    Uart_Init(NULL_PTR);
    Spi_Init(NULL_PTR);
    Can_43_FLEXCAN_Init(NULL_PTR);
    CanIf_Init(NULL_PTR);
    Gpt_Init(NULL_PTR);

    if (useCAN_messaging)
    {
       	CanMessaging_Init();
       	Can_43_FLEXCAN_SetBaudrate (0, 0); //1 mBaud
       	//CanMessaging_Test();  //intra in bucla lui Matei
    }
    if (useUART_messaging)
    {
    	UartMessaging_Init();
    	//UartMessaging_Test(); //pentru a verifica trimiterea tuturor datelor
    }
    if(useCHARGER)
    {
    	Can_43_FLEXCAN_SetBaudrate (0, 1); //250 kBaud
    }
    TempSensorInit();
    initAMS();

    int stateErori=0;
    while(1)
    {
    	//pinu AMS
    	if(stateErori == numberOfFailsBeforeAMS)
    	{
    		switchAMSstate(true);
    	}

    	citesteToateADC();
    	corectieValoriADC();
    	lookUPtemperaturi();

    	Bms_RESET();
    	bmsInit();

    	if(useCHARGER)
    	{
    		BmsReadConfigB();
    		muteDischarge();
    		readBieMieSe();
    		//readBieMieSeOW(); //dezactivat din considerente HW
    		unMuteDischarge();
    		parametriiCFGB(); //activate discharge cu balansare
    		parametriiPWM(12); // numar bitii de 1, 6.6% per bit
    	}
    	else
    	{
    		readBieMieSe();
    		//readBieMieSeOW(); //dezactivat din considerente HW
    	}

    	if (useCAN_messaging)
    	{
        	WriteCanDataAtAddress(BmsGetHighestCellVoltage()/1000, &MonitoredValues.TsacMonitoredValues.HighestCellVoltage);
        	WriteCanDataAtAddress(BmsGetLowestCellVoltage()/1000, &MonitoredValues.TsacMonitoredValues.LowestCellVoltage);
        	WriteCanDataAtAddress(BmsGetOverallCellVoltage()/1000, &MonitoredValues.TsacMonitoredValues.MedianCellVoltage);
        	WriteCanDataAtAddress(BmsGetPackVoltage()/10,&MonitoredValues.TsacMonitoredValues.OverallVoltage);

        	if(BmsGetPackCurrent()/100>=0)
        	{
        		WriteCanDataAtAddress(BmsGetPackCurrent()/100,&MonitoredValues.TsacMonitoredValues.OverallCurrent);
        		WriteCanDataAtAddress(0,&MonitoredValues.TsacMonitoredValues.ReportedChargingCurrent);
        	}
        	else
        	{
        		WriteCanDataAtAddress((BmsGetPackCurrent()/100)*(-1),&MonitoredValues.TsacMonitoredValues.ReportedChargingCurrent);
        		WriteCanDataAtAddress(0,&MonitoredValues.TsacMonitoredValues.OverallCurrent);
        	}

        	for (int i =0;i<24;i++)
        	{
        		CanMessaging_SetCellVoltage(icBaterie.cellVoltage[i]/1000 ,i);
        		if(icBaterie.cellVoltage[i]<overVoltageCelula && icBaterie.cellVoltage[i]>underVoltageCelula)
        		{
        			CanMessaging_SetCellVoltageErrors(false,i);
        		}
        		else
        		{
        			stateAMS=true;
        			CanMessaging_SetCellVoltageErrors(true,i);
        			WriteCanDataAtAddress(true,&MonitoredValues.TsacMonitoredValues.AmsError);
        		}
        	}

        	for (int i = 0; i < THERMISTOR_BANKS; i++)
        	    {
        	        for (int j = 0; j < THERMISTORS_PER_BANK; j++)
        	        {
        	        	CanMessaging_SetCellTemperature(Thermistors_Data.temperaturi[i][j]/10,i*8+j);
        	        	if(Thermistors_Data.temperaturi[i][j]==0)
        	        	{
        	        		CanMessaging_SetCellTemperatureErrors(true,i*8+j);
        	        		WriteCanDataAtAddress(true,&MonitoredValues.TsacMonitoredValues.ThermistorsError);
        	        	}
        	        	else if(Thermistors_Data.temperaturi[i][j]>underTemperatura && Thermistors_Data.temperaturi[i][j]<overTemperatura)
        	        		CanMessaging_SetCellTemperatureErrors(false,i*8+j);
        	        	else
        	        	{
        	        		CanMessaging_SetCellTemperatureErrors(true,i*8+j);
        	        		stateAMS=true;
        	        	}
        	        }
        	    }

        	WriteCanDataAtAddress(getMedie()/10,&MonitoredValues.TsacMonitoredValues.MedianCellTemperature);
        	WriteCanDataAtAddress(getMax()/10,&MonitoredValues.TsacMonitoredValues.HighestCellTemperature);
        	WriteCanDataAtAddress(getMin()/10,&MonitoredValues.TsacMonitoredValues.LowestCellTemperature);

        	WriteCanDataAtAddress(useCHARGER,&MonitoredValues.TsacMonitoredValues.ChargerStatus);
    	}

    	if (useUART_messaging)
    	{
    		WriteUartDataAtAddress(BmsGetHighestCellVoltage()/1000, &MonitoredValues.TsacMonitoredValues.HighestCellVoltage);
    		WriteUartDataAtAddress(BmsGetLowestCellVoltage()/1000, &MonitoredValues.TsacMonitoredValues.LowestCellVoltage);
    		WriteUartDataAtAddress(BmsGetOverallCellVoltage()/1000, &MonitoredValues.TsacMonitoredValues.MedianCellVoltage);
    		WriteUartDataAtAddress(BmsGetPackVoltage()/10,&MonitoredValues.TsacMonitoredValues.OverallVoltage);

    		if(BmsGetPackCurrent()/100>=0)
	    	{
	    		WriteUartDataAtAddress(BmsGetPackCurrent()/100,&MonitoredValues.TsacMonitoredValues.OverallCurrent);
	    		WriteUartDataAtAddress(0,&MonitoredValues.TsacMonitoredValues.ReportedChargingCurrent);
   		    }
   		    else
   		    {
   		    	WriteUartDataAtAddress((BmsGetPackCurrent()/100)*(-1),&MonitoredValues.TsacMonitoredValues.ReportedChargingCurrent);
   		    	WriteUartDataAtAddress(0,&MonitoredValues.TsacMonitoredValues.OverallCurrent);
   		    }

    		for (int i =0;i<24;i++)
    		        	{
    		        		UartMessaging_SetCellVoltage(icBaterie.cellVoltage[i]/1000 ,i);
    		        		if(icBaterie.cellVoltage[i]<overVoltageCelula && icBaterie.cellVoltage[i]>underVoltageCelula)
    		        		{
    		        			UartMessaging_SetCellVoltageErrors(false,i);
    		        		}
    		        		else
    		        		{
    		        			stateAMS=true;
    		        			UartMessaging_SetCellVoltageErrors(true,i);
    		        			WriteUartDataAtAddress(true,&MonitoredValues.TsacMonitoredValues.AmsError);
    		        		}
    		        	}

    		        	for (int i = 0; i < THERMISTOR_BANKS; i++)
    		        	    {
    		        	        for (int j = 0; j < THERMISTORS_PER_BANK; j++)
    		        	        {
    		        	        	UartMessaging_SetCellTemperature(Thermistors_Data.temperaturi[i][j]/10,i*8+j);
    		        	        	if(Thermistors_Data.temperaturi[i][j]==0)
    		        	        	{
    		        	        		UartMessaging_SetCellTemperatureErrors(true,i*8+j);
    		        	        		WriteUartDataAtAddress(true,&MonitoredValues.TsacMonitoredValues.ThermistorsError);
    		        	        	}
    		        	        	else if(Thermistors_Data.temperaturi[i][j]>underTemperatura && Thermistors_Data.temperaturi[i][j]<overTemperatura)
    		        	        		UartMessaging_SetCellTemperatureErrors(false,i*8+j);
    		        	        	else
    		        	        	{
    		        	        		UartMessaging_SetCellTemperatureErrors(true,i*8+j);
    		        	        		stateAMS=true;
    		        	        	}
    		        	        }
    		        	    }
   		    WriteUartDataAtAddress(getMedie()/10,&MonitoredValues.TsacMonitoredValues.MedianCellTemperature);
  		    WriteUartDataAtAddress(getMax()/10,&MonitoredValues.TsacMonitoredValues.HighestCellTemperature);
   		    WriteUartDataAtAddress(getMin()/10,&MonitoredValues.TsacMonitoredValues.LowestCellTemperature);

   		    WriteUartDataAtAddress(useCHARGER,&MonitoredValues.TsacMonitoredValues.ChargerStatus);
        }
    	if(useCHARGER)
    	{
    		//daca am subtensiune pornesc chargeru
    		if(!(BmsGetHighestCellVoltage()>420000)) //la pofta lui Paul
    		{
    			setParametriiCharger(chargeVoltage,chargeCurrent);//100V cu 30A
   		    	transmiteCharger();
   		    	if(useCAN_messaging)
   		    	{
   		    		WriteCanDataAtAddress(chargeVoltage,&MonitoredValues.TsacMonitoredValues.DesiredChargingVoltage);
   		    		WriteCanDataAtAddress(chargeCurrent,&MonitoredValues.TsacMonitoredValues.DesiredChargingVoltage);
   		    	}
   		    	if(useUART_messaging)
   		    	{
   		    	   	WriteCanDataAtAddress(chargeVoltage,&MonitoredValues.TsacMonitoredValues.DesiredChargingVoltage);
   		    		WriteCanDataAtAddress(chargeCurrent,&MonitoredValues.TsacMonitoredValues.DesiredChargingVoltage);
   		    	}
    		}
    	}
    	NIMIC

		if(useUART_messaging)
			UartMessaging_Update();
    	if(useCAN_messaging)
    		CanMessaging_Update();

    	if(MonitoredValues.TsacMonitoredValues.AmsError.valueCan || MonitoredValues.TsacMonitoredValues.AmsError.valueCan)
    	{
    		switchAMSstate(true);
    	}
    	else
    	{
    		switchAMSstate(false);
    	}
    	WriteCanDataAtAddress(false,&MonitoredValues.TsacMonitoredValues.AmsError);
    	WriteCanDataAtAddress(false,&MonitoredValues.TsacMonitoredValues.ThermistorsError);
    	WriteUartDataAtAddress(false,&MonitoredValues.TsacMonitoredValues.AmsError);
    	WriteUartDataAtAddress(false,&MonitoredValues.TsacMonitoredValues.ThermistorsError);
    }


}

#ifdef __cplusplus
}
#endif

/** @} */
