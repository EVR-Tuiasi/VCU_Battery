#ifdef __cplusplus
extern "C" {
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "CDD_I2c.h"
#include "Dio.h"
#include "Icu.h"
#include "Mcu.h"
#include "Mcl.h"
#include "Platform.h"
#include "Port.h"
#include "Spi.h"
#include "bms.h"
#include "uart_datasend.h"
#include "uart_error_handling.h"
#include "CDD_Uart.h"
#include "7-segment-display.h"
#include "bms_cosa.h"
#include "thermistor_mux.h"
#include "Can_GeneralTypes.h"
#include "Can_43_FLEXCAN.h"
#include "CanIf.h"
#include "SchM_Can_43_FLEXCAN.h"
#include "invertor.h"

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
volatile uint8 ok = 0;



volatile int delei;
int curent1,curent2;
volatile int i1,i2;
volatile int v1,v2;
volatile int32_t value24;
bool flag=true;
int bomba=0;

uint16 dpec;

extern struct biemese icBaterie;

int numarulDeDispozitive = NUMARUL_DE_MONITOARE + NUMARUL_DE_SUNTURI;

uint8 buffTrimitere[64] = {0x00, 0x2C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
uint8 buffPrimire[64] = {0};

uint8 buffer[10];
int j=0;

uint8 pachete[6]={0x44, 0x46, 0x48, 0x4A};
uint8 pacheteS[6]={0x03, 0x05, 0x07, 0x0D};

extern Thermistors Thermistors_Data;

void CAN0_Wake_Up_IRQHandler(void) {
    // Handle CAN0 wakeup interrupt
	buffer[0]=1;
}

void CanIf_ControllerModeIndication(uint8_t Controller, uint8_t ControllerMode)
{
	buffer[0]=Controller+ControllerMode;
}
void CanIf_ControllerBusOff(uint8_t Controller)
{
	buffer[0]=Controller;
}



/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
void IntrerupereBTN(void){
	ok = 1;
	Dio_WriteChannel(96, 1);
	Dio_WriteChannel(111, 1);

}

void I2c_Callback(uint8 Event, uint8 Channel){
	Dio_WriteChannel(96, 0);
	Dio_WriteChannel(111, 1);
	(void) Event;
	(void) Channel;
}

void I2c_ErrorCallback(uint8 Event, uint8 Channel){
	Dio_WriteChannel(111, 0);
	Dio_WriteChannel(96, 1);
	ok = 1;
	(void) Event;
	(void) Channel;
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
    Uart_Init(NULL_PTR);
    Spi_Init(NULL_PTR);
    Adc_Init(NULL_PTR);
    USBInit(0);

    volatile int pauza=100000;  //3*8000000; //3sec
    while(pauza--);

    bmsInit();
    RDCFGA();
    RDCFGB();


    while (1) {
        //if(!CFGAok()) //check RAW
        bmsInit();
    	readBieMieSe();

    	populeazaCMD(0x04,0x10);
    	transmisieCMD();         //ADAX
    	populeazaCMD(0x00,0x19); //RDAUXA
    	transmisieCMD();
    	buffPrimire[0]=0;


    	v1=((buffPrimire[5]<<8)+buffPrimire[4])*150+1500000;
    	v2=((buffPrimire[7]<<8)+buffPrimire[6])*150+1500000;

    	buffer[0] = 10;
    	buffer[1] = 0;
    	buffer[2] = 0;
    	buffer[3] = (v1>>24) % 256;
    	buffer[4] = (v1 >> 16) % 256;
    	buffer[5] = (v1 >> 8)  % 256;
    	buffer[6] = v1 % 256;
    	buffer[7] = CRC_calculate(8);
    	Uart_SyncSend(0, buffer, 8, 10000000);
    	//trimite set celula

    	buffer[0] = 10;
    	buffer[1] = 0;
    	buffer[2] = 1;
    	buffer[3] = (v2>>24) % 256;
    	buffer[4] = (v2 >> 16) % 256;
    	buffer[5] = (v2 >> 8)  % 256;
    	buffer[6] = v2 % 256;
    	buffer[7] = CRC_calculate(8);
    	Uart_SyncSend(0, buffer, 8, 10000000);



    	sendAllUart(); //send usefull ingo
    	//daca eroare register basicaly reset
    	//daca eroare CRC forget
    	//daca eroare valoare stupida then ZERO
    }
   }

// test

#ifdef __cplusplus
}
#endif

/** @} */
