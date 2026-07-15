
#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include"Mcu.h"
#include"Can_43_FLEXCAN.h"
#include "CanIf.h"
#include "SchM_Can_43_FLEXCAN.h"

#include"invertor.h"
#include"Dio.h"

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
InverterData InverterInstance[2];
uint16 currentDebounceBuffer[CURRENT_DEBOUNCE_BUFFER_SIZE] = {0U}, voltageDebounceBuffer[VOLTAGE_DEBOUNCE_BUFFER_SIZE] = {0U};
uint8 currentDebounceIndex = 0U, voltageDebounceIndex = 0U;

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
/*boolean InverterReceivedMessage(Can_HwHandleType handle, Can_IdType id, PduLengthType length, uint8* data){
	uint64 mean = 0;
	if(length == 8U){
		if((id & 0x3FFFFFFF) == 0x0CF11E05){//mesaj tip 1 invertor, mascat deoarece driverul de CAN modifica cei mai din stanga doi biti
			InverterInstance[0].rpm = ((uint16)data[0]) + (((uint16)data[1])<<8U);
			//debounce curent
			currentDebounceBuffer[currentDebounceIndex] = ((uint16)data[2]) + (((uint16)data[3])<<8U);
			currentDebounceIndex = (currentDebounceIndex + 1) % CURRENT_DEBOUNCE_BUFFER_SIZE;
			for(uint8 i=0; i<CURRENT_DEBOUNCE_BUFFER_SIZE; i++){
				mean += currentDebounceBuffer[i];
			}
			mean /= CURRENT_DEBOUNCE_BUFFER_SIZE;
			InverterInstance[0].current = mean;
			//debounce tensiune
			voltageDebounceBuffer[currentDebounceIndex] = ((uint16)data[4]) + (((uint16)data[5])<<8U);
			voltageDebounceIndex = (voltageDebounceIndex + 1) % VOLTAGE_DEBOUNCE_BUFFER_SIZE;
			for(uint8 i=0; i<VOLTAGE_DEBOUNCE_BUFFER_SIZE; i++){
				mean += voltageDebounceBuffer[i];
			}
			mean /= VOLTAGE_DEBOUNCE_BUFFER_SIZE;
			InverterInstance[0].voltage = mean;
		}
		else if((id & 0x3FFFFFFF) == 0x0CF11F05){//mesaj tip 2 invertor, mascat deoarece driverul de CAN modifica cei mai din stanga doi biti
	        InverterInstance[0].throttle = data[0];
	        InverterInstance[0].controllerTemperature = data[1];
	        InverterInstance[0].motorTemperature = data[2];
		}
	}
	return TRUE;
}

*/

#ifdef __cplusplus
}
#endif
/** @} */
