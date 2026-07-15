#ifndef CAN_MESSAGING_H
#define CAN_MESSAGING_H

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "stdint.h"
#include "stdarg.h"
#include"Mcu.h"
#include"Can_43_FLEXCAN.h"
#include "CDD_Uart.h"
#include "Messaging_Types.h"
#include "UartMessaging.h"
#include "CanConfig.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

#define INTERRUPT_MASK 0x3FFFFFFF
#define ID_MASK 0x80000000U

typedef enum{
	idCanFrana = 0x00000331,
	idCanAcceleratie = 0x00000330,
	idCanInvertorStanga = 0x00000110,
	idCanInvertorDreapta = 0x00000111,
	idCanInvertoare = 0x00000112,
	idCanBaterie1 = 0x00000114,
	idCanBaterie2 = 0x00000115,
	idCanBaterie3 = 0x00000116,
	idCanBaterie4 = 0x00000117,
	idCanBaterie5 = 0x00000119,
	idCanBord = 0x00000113,
	idCanComunicatii = 0x00000118,
}idCan_t;

typedef enum{
    /* TSAC */
    Can_TSAC_MedianCellTemperature,
    Can_TSAC_HighestCellTemperature,
    Can_TSAC_LowestCellTemperature,
    Can_TSAC_MedianCellVoltage,
    Can_TSAC_HighestCellVoltage,
    Can_TSAC_LowestCellVoltage,
    Can_TSAC_OverallVoltage,
    Can_TSAC_OverallCurrent,
	Can_TSAC_CellVoltage,
	Can_TSAC_CellVoltageError,
	Can_TSAC_CellTemperature,
	Can_TSAC_CellTemperatureError,
    Can_TSAC_IsAmsSafe,
    Can_TSAC_IsTransceiverWorking,
    Can_TSAC_IsShuntWorking,
    Can_TSAC_IsBms0Working,
    Can_TSAC_IsBms1Working,
	Can_TSAC_IsCharging,
	Can_TSAC_AreThermistorsWorking,
	Can_TSAC_ReportedChargingCurrent,
	Can_TSAC_ReportedChargingVoltage,
	Can_TSAC_ChargerCommand,
	Can_TSAC_DesiredChargingCurrent,
	Can_TSAC_DesiredChargingVoltage,
    /* PEDALS */
    Can_PEDALS_AcceleratorSensor1Voltage,
    Can_PEDALS_AcceleratorSensor2Voltage,
    Can_PEDALS_AcceleratorSensor1TravelPercentage,
    Can_PEDALS_AcceleratorSensor2TravelPercentage,
    Can_PEDALS_BrakeSensor1Voltage,
    Can_PEDALS_BrakeSensor2Voltage,
    Can_PEDALS_BrakeSensor1TravelPercentage,
    Can_PEDALS_BrakeSensor2TravelPercentage,
    Can_PEDALS_PressureSensorVoltage,
    Can_PEDALS_PressureSensorBars,
    Can_PEDALS_Accel_Sensor1_ShortToGnd,
    Can_PEDALS_Accel_Sensor1_ShortToVcc,
    Can_PEDALS_Accel_Sensor1_OutOfRangeOutput,
    Can_PEDALS_Accel_Sensor2_ShortToGnd,
    Can_PEDALS_Accel_Sensor2_ShortToVcc,
    Can_PEDALS_Accel_Sensor2_OutOfRangeOutput,
    Can_PEDALS_Accel_Implausibility,
    Can_PEDALS_Brake_Sensor1_ShortToGnd,
    Can_PEDALS_Brake_Sensor1_ShortToVcc,
    Can_PEDALS_Brake_Sensor1_OutOfRangeOutput,
    Can_PEDALS_Brake_Sensor2_ShortToGnd,
    Can_PEDALS_Brake_Sensor2_ShortToVcc,
    Can_PEDALS_Brake_Sensor2_OutOfRangeOutput,
    Can_PEDALS_Brake_Implausibility,
    /* INVERTERS */
    Can_INVERTERS_LeftInverterTemperature,
    Can_INVERTERS_LeftMotorTemperature,
    Can_INVERTERS_LeftInverterInputVoltage,
    Can_INVERTERS_LeftInverterCurrent,
    Can_INVERTERS_LeftMotorRpm,
    Can_INVERTERS_LeftMotorSpeedKmh,
    Can_INVERTERS_LeftInverterThrottle,
    Can_INVERTERS_LeftInverterThrottleFeedback,
    Can_INVERTERS_RightInverterTemperature,
    Can_INVERTERS_RightMotorTemperature,
    Can_INVERTERS_RightInverterInputVoltage,
    Can_INVERTERS_RightInverterCurrent,
    Can_INVERTERS_RightMotorRpm,
    Can_INVERTERS_RightMotorSpeedKmh,
    Can_INVERTERS_RightInverterSentThrottle,
    Can_INVERTERS_RightInverterThrottleFeedback,
    Can_INVERTERS_IsCarInReverse,
    Can_INVERTERS_IsCarRunning,
    /* DASHBOARD */
    Can_DASHBOARD_ActivationButtonPressed,
    Can_DASHBOARD_CarReverseCommandPressed,
    Can_DASHBOARD_IsDisplayWorking,
    Can_DASHBOARD_IsSegmentsDriverWorking,
	/* COMMUNICATIONS */
	Can_COMMUNICATIONS_IsInverterVcuSimulated,
	Can_COMMUNICATIONS_IsTsacVcuSimulated,
	Can_COMMUNICATIONS_IsDashboardVcuSimulated,
	Can_COMMUNICATIONS_IsPedalsVcuSimulated,
}CanMonitoredValue_t;

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


/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

void CanMessaging_Init(void);
void CanMessaging_Test(void);
void CanMessaging_Update(void);
void CanMessaging_SetValue(CanMonitoredValue_t DesiredValueType, uint32_t Value);
void CanMessaging_SetCellVoltage(uint16_t Value, uint16_t index);
void CanMessaging_SetCellVoltageErrors(boolean Value, uint16_t index);
void CanMessaging_SetCellTemperature(uint16_t Value, uint16_t index);
void CanMessaging_SetCellTemperatureErrors(boolean Value, uint16_t index);
uint32_t CanMessaging_ReadValue(CanMonitoredValue_t DesiredValueType);
uint16_t CanMessaging_ReadCellVoltage(uint16_t index);
boolean CanMessaging_ReadCellVoltageErrors(uint16_t index);
uint16_t CanMessaging_ReadCellTemperature(uint16_t index);
boolean CanMessaging_ReadCellTemperatureErrors(uint16_t index);
boolean CanMessaging_ReceiveData(Can_HwHandleType handle, Can_IdType id, PduLengthType length, uint8_t* data);
void CanMessaging_CreateBuffer(idCan_t type);
void CanMessaging_CreateCellVoltageBuffer(uint16_t index);
void CanMessaging_CreateCellTemperatureBuffer(uint16_t index);
void CanMessaging_AppTest(void);

#ifdef __cplusplus
}
#endif

#endif
