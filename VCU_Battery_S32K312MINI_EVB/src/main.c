
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
//#include "Icu.h"
#include "Mcu.h"
#include "Spi.h"
#include "Platform.h"
#include "Port.h"
#include "CDD_Uart.h"
//#include "7-segment-display.h"
#include "thermistor_mux.h"
#include "iso_spi_primitives.h"
#include "lut.h"
#include "usb_monitoring.h"
#include "Can_GeneralTypes.h"
#include "Can_43_FLEXCAN.h"
#include "CanIf.h"
#include "SchM_Can_43_FLEXCAN.h"
#include "Gpt.h"
#include "invertor.h"
#include "CanMessaging.h"
#include "charger.h"
#include "UartMessaging.h"
#include "Messaging.h"
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
    //Icu_Init(NULL_PTR);
    *((volatile uint32_t *)0xE000E008) |= (1 << 1);
    Spi_Init(NULL_PTR);
    //Icu_EnableNotification(0);
    Can_43_FLEXCAN_Init(NULL_PTR);
    CanIf_Init(NULL_PTR);
    Gpt_Init(NULL_PTR);
    //Can_43_FLEXCAN_SetControllerMode(0, CAN_CS_STARTED);
    //Can_43_FLEXCAN_EnableControllerInterrupts(0);
    USBInit(0);
    CanMessaging_Init();
    TempSensorInit();

    //UartMessaging_Test();
    //CanMessaging_Test(); //intra in bucla lui Matei


    /*while(1)
    {
        int h=200000;
        while(h--)
        	__asm volatile ("nop");
        BmsReadID();
    }*/

    while(1)
    {
    	//daca am subtensiune pornesc chargeru
    	/* pinu AMS
    	Port_SetPinDirection(50,PORT_PIN_OUT);
    	Dio_WriteChannel(53,STD_LOW);
    	Dio_WriteChannel(53,STD_HIGH);
    	Dio_WriteChannel(53,STD_LOW);

    	Port_SetPinDirection(51,PORT_PIN_OUT);
    	Dio_WriteChannel(52,STD_LOW);
    	Dio_WriteChannel(52,STD_HIGH);
    	Dio_WriteChannel(52,STD_LOW);*/


    	citesteToateADC();
    	//corectieValoriADC();
    	lookUPtemperaturi();

    	//Bms_RESET();
    	bmsInit();
    	BmsReadConfigB();
    	muteDischarge();
    	readBieMieSe();
    	//readBieMieSeOW();
    	unMuteDischarge();
    	parametriiCFGB(); //activate discharge
    	parametriiPWM(12); // numar bitii de 1, 6.6% per bit

    	// TODO integrat astea in functie de CAN

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
    		if(icBaterie.cellVoltage[i])
    		{
    			CanMessaging_SetCellTemperatureErrors(true,i);

    		}
    		else
    		{
    			CanMessaging_SetCellTemperatureErrors(false,i);
    			WriteCanDataAtAddress(false,&MonitoredValues.TsacMonitoredValues.AmsError);
    		}
    	}

    	for (int i = 0; i < THERMISTOR_BANKS; i++)
    	    {
    	        for (int j = 0; j < THERMISTORS_PER_BANK; j++)
    	        {
    	        	CanMessaging_SetCellTemperature(Thermistors_Data.temperaturi[i][j]/10,i*8+j);
    	        	if(Thermistors_Data.temperaturi[i][j]==0)
    	        		CanMessaging_SetCellTemperatureErrors(true,i*8+j);
    	        	else
    	        		CanMessaging_SetCellTemperatureErrors(false,i*8+j);
    	        }
    	    }

    	WriteCanDataAtAddress(getMedie()/10,&MonitoredValues.TsacMonitoredValues.MedianCellTemperature);
    	WriteCanDataAtAddress(getMax()/10,&MonitoredValues.TsacMonitoredValues.HighestCellTemperature);
    	WriteCanDataAtAddress(getMin()/10,&MonitoredValues.TsacMonitoredValues.LowestCellTemperature);

    	CanMessaging_Update();
    	//for(int delei = 2000000;delei>0;delei--);


    	if(!(BmsGetHighestCellVoltage()>420000)) //la pofta lui Paul
    	    	{
    	    		setParametriiCharger(1008,300);//100V cu 30A
    	    		transmiteCharger();
    	    		WriteCanDataAtAddress(true,&MonitoredValues.TsacMonitoredValues.ChargerStatus);
    	    	}
    	else
    	{
    		WriteCanDataAtAddress(false,&MonitoredValues.TsacMonitoredValues.ChargerStatus);
    	}

        __asm volatile ("nop"); //asta e un breakpoint universal. NU il sterg ca l-am cautat de m-a luat naiba
        // TODO gasit o metoda mai buna pentru breakpoint artificial
    }


}

#ifdef __cplusplus
}
#endif

/** @} */
