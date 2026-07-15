#ifndef UART_MESSAGING_H
#define UART_MESSAGING_H

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

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

typedef enum{
	idUartInvertorStanga = 0x10,
	idUartInvertorDreapta = 0x11,
	idUartInvertoare = 0x12,
	idUartBord = 0x13,
	idUartAcceleratie = 0x30,
	idUartFrana = 0x31,
	idUartBaterie1 = 0x14,
	idUartBaterie2 = 0x15,
	idUartBaterie3 = 0x16,
	idUartBaterie4 = 0x17,
	idUartBaterie5 = 0x19,
	idUartComunicatii = 0x18,
}idUart_t;

typedef enum{
    /* TSAC */
	Uart_TSAC_MedianCellTemperature,
	Uart_TSAC_HighestCellTemperature,
	Uart_TSAC_LowestCellTemperature,
	Uart_TSAC_MedianCellVoltage,
	Uart_TSAC_HighestCellVoltage,
	Uart_TSAC_LowestCellVoltage,
	Uart_TSAC_OverallVoltage,
	Uart_TSAC_OverallCurrent,
	Uart_TSAC_CellVoltage,
	Uart_TSAC_CellVoltageError,
	Uart_TSAC_CellTemperature,
	Uart_TSAC_CellTemperatureError,
	Uart_TSAC_IsAmsSafe,
	Uart_TSAC_IsTransceiverWorking,
	Uart_TSAC_IsShuntWorking,
	Uart_TSAC_IsBms0Working,
	Uart_TSAC_IsBms1Working,
	Uart_TSAC_IsCharging,
	Uart_TSAC_AreThermistorsWorking,
	Uart_TSAC_ReportedChargingCurrent,
	Uart_TSAC_ReportedChargingVoltage,
	Uart_TSAC_ChargerCommand,
	Uart_TSAC_DesiredChargingCurrent,
	Uart_TSAC_DesiredChargingVoltage,
    /* PEDALS */
    Uart_PEDALS_AcceleratorSensor1Voltage,
    Uart_PEDALS_AcceleratorSensor2Voltage,
    Uart_PEDALS_AcceleratorSensor1TravelPercentage,
    Uart_PEDALS_AcceleratorSensor2TravelPercentage,
    Uart_PEDALS_BrakeSensor1Voltage,
    Uart_PEDALS_BrakeSensor2Voltage,
    Uart_PEDALS_BrakeSensor1TravelPercentage,
    Uart_PEDALS_BrakeSensor2TravelPercentage,
    Uart_PEDALS_PressureSensorVoltage,
    Uart_PEDALS_PressureSensorBars,
    Uart_PEDALS_Accel_Sensor1_ShortToGnd,
    Uart_PEDALS_Accel_Sensor1_ShortToVcc,
    Uart_PEDALS_Accel_Sensor1_OutOfRangeOutput,
    Uart_PEDALS_Accel_Sensor2_ShortToGnd,
    Uart_PEDALS_Accel_Sensor2_ShortToVcc,
    Uart_PEDALS_Accel_Sensor2_OutOfRangeOutput,
    Uart_PEDALS_Accel_Implausibility,
    Uart_PEDALS_Brake_Sensor1_ShortToGnd,
    Uart_PEDALS_Brake_Sensor1_ShortToVcc,
    Uart_PEDALS_Brake_Sensor1_OutOfRangeOutput,
    Uart_PEDALS_Brake_Sensor2_ShortToGnd,
    Uart_PEDALS_Brake_Sensor2_ShortToVcc,
    Uart_PEDALS_Brake_Sensor2_OutOfRangeOutput,
    Uart_PEDALS_Brake_Implausibility,
    /* INVERTERS */
    Uart_INVERTERS_LeftInverterTemperature,
    Uart_INVERTERS_LeftMotorTemperature,
    Uart_INVERTERS_LeftInverterInputVoltage,
    Uart_INVERTERS_LeftInverterCurrent,
    Uart_INVERTERS_LeftMotorRpm,
    Uart_INVERTERS_LeftMotorSpeedKmh,
    Uart_INVERTERS_LeftInverterThrottle,
    Uart_INVERTERS_LeftInverterThrottleFeedback,
    Uart_INVERTERS_RightInverterTemperature,
    Uart_INVERTERS_RightMotorTemperature,
    Uart_INVERTERS_RightInverterInputVoltage,
    Uart_INVERTERS_RightInverterCurrent,
    Uart_INVERTERS_RightMotorRpm,
    Uart_INVERTERS_RightMotorSpeedKmh,
    Uart_INVERTERS_RightInverterSentThrottle,
    Uart_INVERTERS_RightInverterThrottleFeedback,
    Uart_INVERTERS_IsCarInReverse,
    Uart_INVERTERS_IsCarRunning,
    /* DASHBOARD */
    Uart_DASHBOARD_ActivationButtonPressed,
    Uart_DASHBOARD_CarReverseCommandPressed,
    Uart_DASHBOARD_IsDisplayWorking,
    Uart_DASHBOARD_IsSegmentsDriverWorking,
	/* COMMUNICATIONS */
	Uart_COMMUNICATIONS_IsInverterVcuSimulated,
	Uart_COMMUNICATIONS_IsTsacVcuSimulated,
	Uart_COMMUNICATIONS_IsDashboardVcuSimulated,
	Uart_COMMUNICATIONS_IsPedalsVcuSimulated,
}UartMonitoredValue_t;


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

void UartMessaging_Init(void);
void UartMessaging_Test(void);
void UartMessaging_Update(void);
void UartMessaging_SetValue(UartMonitoredValue_t DesiredValueType, uint32_t Value);
void UartMessaging_SetCellVoltage(uint16_t Value, uint16_t index);
void UartMessaging_SetCellVoltageErrors(boolean Value, uint16_t index);
void UartMessaging_SetCellTemperature(uint16_t Value, uint16_t index);
void UartMessaging_SetCellTemperatureErrors(boolean Value, uint16_t index);
uint32_t UartMessaging_ReadValue(UartMonitoredValue_t DesiredValueType);
uint16_t UartMessaging_ReadCellVoltage(uint16_t index);
boolean UartMessaging_ReadCellVoltageErrors(uint16_t index);
uint16_t UartMessaging_ReadCellTemperature(uint16_t index);
boolean UartMessaging_ReadCellTemperatureErrors(uint16_t index);
void UartMessaging_CreateBuffer(idUart_t type);
void UartMessaging_CreateCellVoltageBuffer(uint16_t index);
void UartMessaging_CreateCellTemperatureBuffer(uint16_t index);
uint8_t CRC_calculate(uint8_t length);

#ifdef __cplusplus
}
#endif

#endif
