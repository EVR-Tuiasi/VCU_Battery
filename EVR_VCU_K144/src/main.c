
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
#include "CDD_I2c.h"
#include "Dio.h"
#include "Icu.h"
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
#include "invertor.h"
#include "CanMessaging.h"
#include "charger.h"
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
/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
void IntrerupereBTN(void){

}

void I2c_Callback(uint8 Event, uint8 Channel){
	(void)Event;
	(void)Channel;
}

void I2c_ErrorCallback(uint8 Event, uint8 Channel){
	(void)Event;
	(void)Channel;
}

void CAN0_Wake_Up_IRQHandler(void)
{

}

void CanIf_ControllerModeIndication(uint8_t Controller, uint8_t ControllerMode)
{
    (void)Controller;
    (void)ControllerMode;
}

void CanIf_ControllerBusOff(uint8_t Controller)
{
    (void)Controller;
}
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
    I2c_Init(NULL_PTR);
    Icu_Init(NULL_PTR);
    Spi_Init(NULL_PTR);
    Icu_EnableNotification(0);
    Can_43_FLEXCAN_Init(NULL_PTR);
    CanIf_Init(NULL_PTR);
    Can_43_FLEXCAN_SetControllerMode(0, CAN_CS_STARTED);
    Can_43_FLEXCAN_EnableControllerInterrupts(0);
    USBInit(0);
    TempSensorInit();

    //CanMessaging_Test(); //intra in bucla lui Matei

    while(1)
    {
    	//daca am subtensiune pornesc chargeru
    	if(!(BmsGetHighestCellVoltage()>418000)) //la pofta lui Paul
    	{
    		setParametriiCharger(1000,50);//100V cu 5A
    		transmiteCharger();
    	}


    	citesteToateADC();
    	corectieValoriADC();
    	lookUPtemperaturi();

    	bmsInit();
    	readBieMieSe();
    	readBieMieSeOW();
    	sendAllUart();

    	// TODO integrat astea in functie de CAN
    	CanMessaging_SetValue(Can_TSAC_OverallVoltage, (BmsGetPackVoltage()/10));
    	CanMessaging_SetValue(Can_TSAC_OverallCurrent, BmsGetPackCurrent()/100);
    	CanMessaging_SetValue(Can_TSAC_HighestCellTemperature, temp_lut[getMax()]/10);
    	CanMessaging_SetValue(Can_TSAC_HighestCellVoltage, BmsGetHighestCellVoltage()/1000);
    	CanMessaging_Update();

        __asm volatile ("nop"); //asta e un breakpoint universal. NU il sterg ca l-am cautat de m-a luat naiba
        // TODO gasit o metoda mai buna pentru breakpoint artificial
    }


}

#ifdef __cplusplus
}
#endif

/** @} */
