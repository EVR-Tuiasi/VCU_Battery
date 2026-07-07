
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
#include "Mcu.h"
#include "Port.h"
#include "Platform.h"
#include "Can_GeneralTypes.h"
#include "Can_43_FLEXCAN.h"
#include "CanIf.h"
#include "SchM_Can_43_FLEXCAN.h"
#include "CDD_Uart.h"
#include "Dio.h"
#include "Mcl.h"
#include "CanMessaging.h"
#include "Messaging_Types.h"
#include "CanConfig.h"

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


InvertersMonitoredValues_t invertoareCan;
PedalsMonitoredValues_t pedaleCan;
TsacMonitoredValues_t baterieCan;
DashboardMonitoredValues_t bordCan;
CommunicationsMonitoredValues_t comunicatiiCan;

uint8_t bufferCan[8];


/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

void CanMessaging_Init(void){
	//Dio_WriteChannel(CAN_Channel1_En, STD_HIGH); //CAN0_EN
	/*volatile uint64 i = 1000000;
	while(i--);
	//Dio_WriteChannel(CAN_Channel1_Stb_N, STD_HIGH); //CAN0_STB_N
	i = 1000000;
	while(i--);
	//Dio_WriteChannel(CAN_Channel2_En, STD_HIGH); //CAN1_EN
	i = 1000000;
	while(i--);
	//Dio_WriteChannel(CAN_Channel2_Stb_N, STD_HIGH); //CAN1_STB_N
	i = 1000000;
	while(i--);*/

	Can_43_FLEXCAN_SetControllerMode(0, CAN_CS_STARTED);
	//Can_43_FLEXCAN_SetControllerMode(Can_43_FLEXCANConf_CanController_CanController_1, CAN_CS_STARTED);
	Can_43_FLEXCAN_EnableControllerInterrupts(0);
	//Can_43_FLEXCAN_EnableControllerInterrupts(1);
}

void CanMessaging_Test(void){
	int cnt = 0;
	volatile int i;
	while(1){
		CanMessaging_SetValue(Can_TSAC_OverallCurrent, cnt);
		CanMessaging_SetValue(Can_TSAC_OverallVoltage, cnt);
		CanMessaging_SetValue(Can_TSAC_HighestCellTemperature, cnt);
		CanMessaging_SetValue(Can_TSAC_HighestCellVoltage, cnt);
		CanMessaging_SetValue(Can_TSAC_LowestCellVoltage, cnt);
		CanMessaging_SetValue(Can_TSAC_LowestCellTemperature, cnt);

		for(uint16_t index = 0; index < CELLS_NUM; index++){
			CanMessaging_SetCellVoltageErrors(0, index);
			CanMessaging_SetCellVoltage(cnt, index);
		}

		for(uint16_t index = 0; index < THERMISTOR_NUM; index++){
			CanMessaging_SetCellTemperatureErrors(0, index);
			CanMessaging_SetCellTemperature(cnt, index);
		}

		CanMessaging_SetValue(Can_TSAC_MedianCellTemperature, cnt);
		CanMessaging_SetValue(Can_TSAC_MedianCellVoltage, cnt);

		CanMessaging_SetValue(Can_TSAC_IsAmsSafe, cnt & 1);
		CanMessaging_SetValue(Can_TSAC_IsTransceiverWorking, cnt & 1);
		CanMessaging_SetValue(Can_TSAC_IsShuntWorking, cnt & 1);
		CanMessaging_SetValue(Can_TSAC_IsBms0Working, cnt & 1);
		CanMessaging_SetValue(Can_TSAC_IsBms1Working, cnt & 1);
		CanMessaging_SetValue(Can_TSAC_IsCharging, cnt & 1);
		CanMessaging_SetValue(Can_TSAC_AreThermistorsWorking, cnt & 1);
		CanMessaging_SetValue(Can_TSAC_ReportedChargingCurrent, cnt);
		CanMessaging_SetValue(Can_TSAC_ReportedChargingVoltage, cnt);

		CanMessaging_SetValue(Can_TSAC_ChargerCommand, cnt & 1);
		CanMessaging_SetValue(Can_TSAC_DesiredChargingCurrent, cnt % 321);
		CanMessaging_SetValue(Can_TSAC_DesiredChargingVoltage, cnt % 1009);

		CanMessaging_SetValue(Can_PEDALS_AcceleratorSensor1Voltage, cnt);
		CanMessaging_SetValue(Can_PEDALS_AcceleratorSensor2Voltage, cnt);
		CanMessaging_SetValue(Can_PEDALS_AcceleratorSensor1TravelPercentage, cnt%101);
		CanMessaging_SetValue(Can_PEDALS_AcceleratorSensor2TravelPercentage, cnt%101);
		CanMessaging_SetValue(Can_PEDALS_BrakeSensor1Voltage, cnt);
		CanMessaging_SetValue(Can_PEDALS_BrakeSensor2Voltage, cnt);
		CanMessaging_SetValue(Can_PEDALS_BrakeSensor1TravelPercentage, cnt%101);
		CanMessaging_SetValue(Can_PEDALS_BrakeSensor2TravelPercentage, cnt%101);
		CanMessaging_SetValue(Can_PEDALS_PressureSensorVoltage, cnt%501);
		CanMessaging_SetValue(Can_PEDALS_PressureSensorBars, cnt);
		CanMessaging_SetValue(Can_PEDALS_Accel_Sensor1_ShortToGnd, cnt & 1);
		CanMessaging_SetValue(Can_PEDALS_Accel_Sensor1_ShortToVcc, cnt & 1);
		CanMessaging_SetValue(Can_PEDALS_Accel_Sensor1_OutOfRangeOutput, cnt & 1);
		CanMessaging_SetValue(Can_PEDALS_Accel_Sensor2_ShortToGnd, cnt & 1);
		CanMessaging_SetValue(Can_PEDALS_Accel_Sensor2_ShortToVcc, cnt & 1);
		CanMessaging_SetValue(Can_PEDALS_Accel_Sensor2_OutOfRangeOutput, cnt & 1);
		CanMessaging_SetValue(Can_PEDALS_Accel_Implausibility, cnt & 1);
		CanMessaging_SetValue(Can_PEDALS_Brake_Sensor1_ShortToGnd, cnt & 1);
		CanMessaging_SetValue(Can_PEDALS_Brake_Sensor1_ShortToVcc, cnt & 1);
		CanMessaging_SetValue(Can_PEDALS_Brake_Sensor1_OutOfRangeOutput, cnt & 1);
		CanMessaging_SetValue(Can_PEDALS_Brake_Sensor2_ShortToGnd, cnt & 1);
		CanMessaging_SetValue(Can_PEDALS_Brake_Sensor2_ShortToVcc, cnt & 1);
		CanMessaging_SetValue(Can_PEDALS_Brake_Sensor2_OutOfRangeOutput, cnt & 1);
		CanMessaging_SetValue(Can_PEDALS_Brake_Implausibility, cnt & 1);

		CanMessaging_SetValue(Can_INVERTERS_LeftInverterTemperature, cnt);
		CanMessaging_SetValue(Can_INVERTERS_LeftMotorTemperature, cnt);
		CanMessaging_SetValue(Can_INVERTERS_LeftInverterInputVoltage, cnt%1801);
		CanMessaging_SetValue(Can_INVERTERS_LeftInverterCurrent, cnt%4001);
		CanMessaging_SetValue(Can_INVERTERS_LeftMotorRpm, cnt%6001);
		CanMessaging_SetValue(Can_INVERTERS_LeftMotorSpeedKmh, cnt);
		CanMessaging_SetValue(Can_INVERTERS_LeftInverterThrottle, cnt%251);
		CanMessaging_SetValue(Can_INVERTERS_LeftInverterThrottleFeedback, cnt%251);
		CanMessaging_SetValue(Can_INVERTERS_RightInverterTemperature, cnt);
		CanMessaging_SetValue(Can_INVERTERS_RightMotorTemperature, cnt);
		CanMessaging_SetValue(Can_INVERTERS_RightInverterInputVoltage, cnt%1801);
		CanMessaging_SetValue(Can_INVERTERS_RightInverterCurrent, cnt%4001);
		CanMessaging_SetValue(Can_INVERTERS_RightMotorRpm, cnt%6001);
		CanMessaging_SetValue(Can_INVERTERS_RightMotorSpeedKmh, cnt);
		CanMessaging_SetValue(Can_INVERTERS_RightInverterSentThrottle, cnt%251);
		CanMessaging_SetValue(Can_INVERTERS_RightInverterThrottleFeedback, cnt%251);
		CanMessaging_SetValue(Can_INVERTERS_IsCarInReverse, cnt & 1);
		CanMessaging_SetValue(Can_INVERTERS_IsCarRunning, cnt & 1);

		CanMessaging_SetValue(Can_DASHBOARD_ActivationButtonPressed, cnt & 1);
		CanMessaging_SetValue(Can_DASHBOARD_CarReverseCommandPressed, cnt & 1);
		CanMessaging_SetValue(Can_DASHBOARD_IsDisplayWorking, cnt & 1);
		CanMessaging_SetValue(Can_DASHBOARD_IsSegmentsDriverWorking, cnt & 1);

		CanMessaging_SetValue(Can_COMMUNICATIONS_IsInverterVcuSimulated, cnt & 1);
		CanMessaging_SetValue(Can_COMMUNICATIONS_IsTsacVcuSimulated, cnt & 1);
		CanMessaging_SetValue(Can_COMMUNICATIONS_IsDashboardVcuSimulated, cnt & 1);
		CanMessaging_SetValue(Can_COMMUNICATIONS_IsPedalsVcuSimulated, cnt & 1);

		cnt+=1;
		CanMessaging_Update();
		i=1000000;
		while(i--);
	}
}

void CanMessaging_Update(void){
	volatile int i;
	Can_PduType pduInfo;
	pduInfo.swPduHandle=0;
	pduInfo.length=8;

	/*
	CanMessaging_CreateBuffer(idCanInvertorStanga);
	pduInfo.sdu=bufferCan;
	pduInfo.id=idCanInvertorStanga | ID_MASK;
	Can_43_FLEXCAN_Write(CAN_HTH_HANDLE, &pduInfo);
	i=500000;
	while(i--);

	CanMessaging_CreateBuffer(idCanInvertorDreapta);
	pduInfo.sdu=bufferCan;
	pduInfo.id=idCanInvertorDreapta | ID_MASK;
	Can_43_FLEXCAN_Write(CAN_HTH_HANDLE, &pduInfo);
	i=500000;
	while(i--);

	CanMessaging_CreateBuffer(idCanInvertoare);
	pduInfo.sdu=bufferCan;
	pduInfo.id=idCanInvertoare | ID_MASK;
	Can_43_FLEXCAN_Write(CAN_HTH_HANDLE, &pduInfo);
	i=500000;
	while(i--);

	CanMessaging_CreateBuffer(idCanBord);
	pduInfo.sdu=bufferCan;
	pduInfo.id=idCanBord | ID_MASK;
	Can_43_FLEXCAN_Write(CAN_HTH_HANDLE, &pduInfo);
	i=500000;
	while(i--);

	CanMessaging_CreateBuffer(idCanAcceleratie);
	pduInfo.sdu=bufferCan;
	pduInfo.id=idCanAcceleratie | ID_MASK;
	Can_43_FLEXCAN_Write(CAN_HTH_HANDLE, &pduInfo);
	i=500000;
	while(i--);

	CanMessaging_CreateBuffer(idCanFrana);
	pduInfo.sdu=bufferCan;
	pduInfo.id=idCanFrana | ID_MASK;
	Can_43_FLEXCAN_Write(CAN_HTH_HANDLE, &pduInfo);
	i=500000;
	while(i--);*/

	/*CanMessaging_CreateBuffer(idCanBaterie1);
	pduInfo.sdu=bufferCan;
	pduInfo.id=idCanBaterie1 | ID_MASK;
	Can_43_FLEXCAN_Write(CAN_HTH_HANDLE, &pduInfo);
	i=500000;
	while(i--);*/

	for(uint16_t index = 0; index < CELLS_LINES; index++){
		CanMessaging_CreateCellVoltageBuffer(index);
		pduInfo.sdu=bufferCan;
		pduInfo.id=idCanBaterie2 | ID_MASK;
		Can_43_FLEXCAN_Write(CAN_HTH_HANDLE, &pduInfo);
		i=500000;
		while(i--);
	}

	for(uint16_t index = 0; index <= THERMISTOR_LINES; index++){
		CanMessaging_CreateCellTemperatureBuffer(index);
		pduInfo.sdu=bufferCan;
		pduInfo.id=idCanBaterie3 | ID_MASK;
		Can_43_FLEXCAN_Write(CAN_HTH_HANDLE, &pduInfo);
		i=500000;
		while(i--);
	}

	CanMessaging_CreateBuffer(idCanBaterie4);
	pduInfo.sdu=bufferCan;
	pduInfo.id=idCanBaterie4 | ID_MASK;
	Can_43_FLEXCAN_Write(CAN_HTH_HANDLE, &pduInfo);
	i=500000;
	while(i--);

	CanMessaging_CreateBuffer(idCanBaterie5);
	pduInfo.sdu=bufferCan;
	pduInfo.id=idCanBaterie5 | ID_MASK;
	Can_43_FLEXCAN_Write(CAN_HTH_HANDLE, &pduInfo);
	i=500000;
	while(i--);

	/*CanMessaging_CreateBuffer(idCanComunicatii);
	pduInfo.sdu=bufferCan;
	pduInfo.id=idCanComunicatii | ID_MASK;
	Can_43_FLEXCAN_Write(CAN_HTH_HANDLE, &pduInfo);
	i=500000;
	while(i--);*/

}

void CanMessaging_SetValue(CanMonitoredValue_t DesiredValueType, uint32_t Value){
	switch(DesiredValueType){
		//TSAC
		case Can_TSAC_MedianCellTemperature:
			baterieCan.MedianCellTemperature = Value;
			break;
		case Can_TSAC_HighestCellTemperature:
			baterieCan.HighestCellTemperature = Value;
			break;
		case Can_TSAC_LowestCellTemperature:
			baterieCan.LowestCellTemperature = Value;
			break;
		case Can_TSAC_MedianCellVoltage:
			baterieCan.MedianCellVoltage = Value;
			break;
		case Can_TSAC_HighestCellVoltage:
			baterieCan.HighestCellVoltage = Value;
			break;
		case Can_TSAC_LowestCellVoltage:
			baterieCan.LowestCellVoltage = Value;
			break;
		case Can_TSAC_OverallVoltage:
			baterieCan.OverallVoltage = Value;
			break;
		case Can_TSAC_OverallCurrent:
			if(Value>8095)
				baterieCan.OverallCurrent = 0;
			else
				baterieCan.OverallCurrent = Value;
			break;
		case Can_TSAC_IsAmsSafe:
			baterieCan.AmsError = Value;
			break;
		case Can_TSAC_IsTransceiverWorking:
			baterieCan.TransceiverError = Value;
			break;
		case Can_TSAC_IsShuntWorking:
			baterieCan.ShuntError = Value;
			break;
		case Can_TSAC_IsBms0Working:
			baterieCan.Bms0Error = Value;
			break;
		case Can_TSAC_IsBms1Working:
			baterieCan.Bms1Error = Value;
			break;
		case Can_TSAC_IsCharging:
			baterieCan.ChargerStatus = Value;
			break;
		 case Can_TSAC_AreThermistorsWorking:
			baterieCan.ThermistorsError = Value;
			break;
		 case Can_TSAC_ReportedChargingCurrent:
			baterieCan.ReportedChargingCurrent = Value;
			break;
		 case Can_TSAC_ReportedChargingVoltage:
			baterieCan.ReportedChargingVoltage = Value;
			break;
		//PEDALS
		case Can_PEDALS_AcceleratorSensor1Voltage:
			pedaleCan.AcceleratorSensor1Voltage = Value;
			break;
		case Can_PEDALS_AcceleratorSensor2Voltage:
			pedaleCan.AcceleratorSensor2Voltage = Value;
			break;
		case Can_PEDALS_AcceleratorSensor1TravelPercentage:
			/*if(Value>100)
				pedaleCan.AcceleratorSensor1TravelPercentage = 0;
			else*/
				pedaleCan.AcceleratorSensor1TravelPercentage = Value;
			break;
		case Can_PEDALS_AcceleratorSensor2TravelPercentage:
			if(Value>100)
				pedaleCan.AcceleratorSensor2TravelPercentage = 0;
			else
				pedaleCan.AcceleratorSensor2TravelPercentage = Value;
			break;
		case Can_PEDALS_BrakeSensor1Voltage:
			pedaleCan.BrakeSensor1Voltage = Value;
			break;
		case Can_PEDALS_BrakeSensor2Voltage:
			pedaleCan.BrakeSensor2Voltage = Value;
			break;
		case Can_PEDALS_BrakeSensor1TravelPercentage:
			if(Value>100)
				pedaleCan.BrakeSensor1TravelPercentage = 0;
			else
				pedaleCan.BrakeSensor1TravelPercentage = Value;
			break;
		case Can_PEDALS_BrakeSensor2TravelPercentage:
			if(Value>100)
				pedaleCan.BrakeSensor2TravelPercentage = 0;
			else
				pedaleCan.BrakeSensor2TravelPercentage = Value;
			break;
		case Can_PEDALS_PressureSensorVoltage:
			if(Value>500)
				pedaleCan.PressureSensorVoltage = 0;
			else
				pedaleCan.PressureSensorVoltage = Value;
			break;
		case Can_PEDALS_PressureSensorBars:
			pedaleCan.PressureSensorBars = Value;
			break;
		case Can_PEDALS_Accel_Sensor1_ShortToGnd:
			pedaleCan.Accel_Sensor1_ShortToGnd = Value;
			break;
		case Can_PEDALS_Accel_Sensor1_ShortToVcc:
			pedaleCan.Accel_Sensor1_ShortToVcc = Value;
			break;
		case Can_PEDALS_Accel_Sensor1_OutOfRangeOutput:
			pedaleCan.Accel_Sensor1_OutOfRangeOutput = Value;
			break;
		case Can_PEDALS_Accel_Sensor2_ShortToGnd:
			pedaleCan.Accel_Sensor2_ShortToGnd = Value;
			break;
		case Can_PEDALS_Accel_Sensor2_ShortToVcc:
			pedaleCan.Accel_Sensor2_ShortToVcc = Value;
			break;
		case Can_PEDALS_Accel_Sensor2_OutOfRangeOutput:
			pedaleCan.Accel_Sensor2_OutOfRangeOutput = Value;
			break;
		case Can_PEDALS_Accel_Implausibility:
			pedaleCan.Accel_Implausibility = Value;
			break;
		case Can_PEDALS_Brake_Sensor1_ShortToGnd:
			pedaleCan.Brake_Sensor1_ShortToGnd = Value;
			break;
		case Can_PEDALS_Brake_Sensor1_ShortToVcc:
			pedaleCan.Brake_Sensor1_ShortToVcc = Value;
			break;
		case Can_PEDALS_Brake_Sensor1_OutOfRangeOutput:
			pedaleCan.Brake_Sensor1_OutOfRangeOutput = Value;
			break;
		case Can_PEDALS_Brake_Sensor2_ShortToGnd:
			pedaleCan.Brake_Sensor2_ShortToGnd = Value;
			break;
		case Can_PEDALS_Brake_Sensor2_ShortToVcc:
			pedaleCan.Brake_Sensor2_ShortToVcc = Value;
			break;
		case Can_PEDALS_Brake_Sensor2_OutOfRangeOutput:
			pedaleCan.Brake_Sensor2_OutOfRangeOutput = Value;
			break;
		case Can_PEDALS_Brake_Implausibility:
			pedaleCan.Brake_Implausibility = Value;
			break;
		case Can_TSAC_ChargerCommand:
			baterieCan.ChargerCommand = Value;
			break;
		case Can_TSAC_DesiredChargingCurrent:
			if(Value > 320)
				baterieCan.DesiredChargingCurrent = 0;
			else
				baterieCan.DesiredChargingCurrent = Value;
			break;
		case Can_TSAC_DesiredChargingVoltage:
			if(Value > 1008)
				baterieCan.DesiredChargingVoltage = 0;
			else
				baterieCan.DesiredChargingVoltage = Value;
			break;
		//INVERTERS
		case Can_INVERTERS_LeftInverterTemperature:
			invertoareCan.LeftInverterTemperature = Value;
			break;
		case Can_INVERTERS_LeftMotorTemperature:
			invertoareCan.LeftMotorTemperature = Value;
			break;
		case Can_INVERTERS_LeftInverterInputVoltage:
			if(Value>1800)
				invertoareCan.LeftInverterInputVoltage = 0;
			else
				invertoareCan.LeftInverterInputVoltage = Value;
			break;
		case Can_INVERTERS_LeftInverterCurrent:
			if(Value>4000)
				invertoareCan.LeftInverterCurrent = 0;
			else
				invertoareCan.LeftInverterCurrent = Value;
			break;
		case Can_INVERTERS_LeftMotorRpm:
			if(Value>6000)
				invertoareCan.LeftMotorRpm = 0;
			else
				invertoareCan.LeftMotorRpm = Value;
			break;
		case Can_INVERTERS_LeftMotorSpeedKmh:
			invertoareCan.LeftMotorSpeedKmh = Value;
			break;
		case Can_INVERTERS_LeftInverterThrottle:
			if(Value>250)
				invertoareCan.LeftInverterThrottle = 0;
			else
				invertoareCan.LeftInverterThrottle = Value;
			break;
		case Can_INVERTERS_LeftInverterThrottleFeedback:
			if(Value>250)
				invertoareCan.LeftInverterThrottleFeedback = 0;
			else
				invertoareCan.LeftInverterThrottleFeedback = Value;
			break;
		case Can_INVERTERS_RightInverterTemperature:
			invertoareCan.RightInverterTemperature = Value;
			break;
		case Can_INVERTERS_RightMotorTemperature:
			invertoareCan.RightMotorTemperature = Value;
			break;
		case Can_INVERTERS_RightInverterInputVoltage:
			if(Value>1800)
				invertoareCan.RightInverterInputVoltage = 0;
			else
				invertoareCan.RightInverterInputVoltage = Value;
			break;
		case Can_INVERTERS_RightInverterCurrent:
			if(Value>4000)
				invertoareCan.RightInverterCurrent = 0;
			else
				invertoareCan.RightInverterCurrent = Value;
			break;
		case Can_INVERTERS_RightMotorRpm:
			if(Value>6000)
				invertoareCan.RightMotorRpm = 0;
			else
				invertoareCan.RightMotorRpm = Value;
			break;
		case Can_INVERTERS_RightMotorSpeedKmh:
			invertoareCan.RightMotorSpeedKmh = Value;
			break;
		case Can_INVERTERS_RightInverterSentThrottle:
			if(Value>250)
				invertoareCan.RightInverterSentThrottle = 0;
			else
				invertoareCan.RightInverterSentThrottle = Value;
			break;
		case Can_INVERTERS_RightInverterThrottleFeedback:
			if(Value>250)
				invertoareCan.RightInverterThrottleFeedback = 0;
			else
				invertoareCan.RightInverterThrottleFeedback = Value;
			break;
		case Can_INVERTERS_IsCarInReverse:
			invertoareCan.IsCarInReverse = Value;
			break;
		case Can_INVERTERS_IsCarRunning:
			invertoareCan.IsCarRunning = Value;
			break;
		//DASHBOARD
		case Can_DASHBOARD_ActivationButtonPressed:
			bordCan.ActivationButtonPressed = Value;
			break;
		case Can_DASHBOARD_CarReverseCommandPressed:
			bordCan.CarReverseCommandPressed = Value;
			break;
		case Can_DASHBOARD_IsDisplayWorking:
			bordCan.IsDisplayWorking = Value;
			break;
		case Can_DASHBOARD_IsSegmentsDriverWorking:
			bordCan.IsSegmentsDriverWorking = Value;
			break;
		//COMMUNICATIONS
		case Can_COMMUNICATIONS_IsInverterVcuSimulated:
			comunicatiiCan.IsInverterVcuSimulated = Value;
			break;
		case Can_COMMUNICATIONS_IsTsacVcuSimulated:
			comunicatiiCan.IsTsacVcuSimulated = Value;
			break;
		case Can_COMMUNICATIONS_IsDashboardVcuSimulated:
			comunicatiiCan.IsDashboardVcuSimulated = Value;
			break;
		case Can_COMMUNICATIONS_IsPedalsVcuSimulated:
			comunicatiiCan.IsPedalsVcuSimulated = Value;
			break;
		default:
			break;
	}
}

void CanMessaging_SetCellVoltage(uint16_t Value, uint16_t index){
	//NU SCOATE IF-URILE: SUNT DE SIGURANTA
	if(index < CELLS_NUM)
		baterieCan.CellVoltage[index] = Value;
}
void CanMessaging_SetCellVoltageErrors(boolean Value, uint16_t index){
	//NU SCOATE IF-URILE: SUNT DE SIGURANTA
	if(index < CELLS_NUM)
		baterieCan.CellVoltageErrors[index] = Value;
}
void CanMessaging_SetCellTemperature(uint16_t Value, uint16_t index){
	//NU SCOATE IF-URILE: SUNT DE SIGURANTA
	if(index < THERMISTOR_NUM)
		baterieCan.ThermistorTemperature[index] = Value;
}
void CanMessaging_SetCellTemperatureErrors(boolean Value, uint16_t index){
	//NU SCOATE IF-URILE: SUNT DE SIGURANTA
	if(index < THERMISTOR_NUM)
		baterieCan.ThermistorTemperatureErrors[index] = Value;
}

uint32_t CanMessaging_ReadValue(CanMonitoredValue_t DesiredValueType){

	switch(DesiredValueType){
		case Can_TSAC_MedianCellTemperature:
			return baterieCan.MedianCellTemperature;
	    case Can_TSAC_HighestCellTemperature:
	    	return baterieCan.HighestCellTemperature;
	    case Can_TSAC_LowestCellTemperature:
	    	return baterieCan.LowestCellTemperature;
	    case Can_TSAC_MedianCellVoltage:
	    	return baterieCan.MedianCellVoltage;
	    case Can_TSAC_HighestCellVoltage:
	    	return baterieCan.HighestCellVoltage;
	    case Can_TSAC_LowestCellVoltage:
	    	return baterieCan.LowestCellVoltage;
	    case Can_TSAC_OverallVoltage:
	    	return baterieCan.OverallVoltage;
	    case Can_TSAC_OverallCurrent:
	    	return baterieCan.OverallCurrent;
	    case Can_TSAC_IsAmsSafe:
	    	return baterieCan.AmsError;
	    case Can_TSAC_IsTransceiverWorking:
	    	return baterieCan.TransceiverError;
	    case Can_TSAC_IsShuntWorking:
	    	return baterieCan.ShuntError;
	    case Can_TSAC_IsBms0Working:
	    	return baterieCan.Bms0Error;
	    case Can_TSAC_IsBms1Working:
	    	return baterieCan.Bms1Error;
	    case Can_TSAC_IsCharging:
	    	return baterieCan.ChargerStatus;
	    case Can_TSAC_AreThermistorsWorking:
	    	return baterieCan.ThermistorsError;
	    case Can_TSAC_ReportedChargingCurrent:
	    	return baterieCan.ReportedChargingCurrent;
	    case Can_TSAC_ReportedChargingVoltage:
	    	return baterieCan.ReportedChargingVoltage;
	    case Can_TSAC_ChargerCommand:
	    	return baterieCan.ChargerCommand;
	    case Can_TSAC_DesiredChargingCurrent:
	    	return baterieCan.DesiredChargingCurrent;
	    case Can_TSAC_DesiredChargingVoltage:
	    	return baterieCan.DesiredChargingVoltage;
	    case Can_PEDALS_AcceleratorSensor1Voltage:
	    	return pedaleCan.AcceleratorSensor1Voltage;
	    case Can_PEDALS_AcceleratorSensor2Voltage:
	    	return pedaleCan.AcceleratorSensor2Voltage;
		case Can_PEDALS_AcceleratorSensor1TravelPercentage:
			return pedaleCan.AcceleratorSensor1TravelPercentage;
		case Can_PEDALS_AcceleratorSensor2TravelPercentage:
			return pedaleCan.AcceleratorSensor2TravelPercentage;
		case Can_PEDALS_BrakeSensor1Voltage:
			return pedaleCan.BrakeSensor1Voltage;
		case Can_PEDALS_BrakeSensor2Voltage:
			return pedaleCan.BrakeSensor2Voltage;
		case Can_PEDALS_BrakeSensor1TravelPercentage:
			return pedaleCan.BrakeSensor1TravelPercentage;
		case Can_PEDALS_BrakeSensor2TravelPercentage:
			return pedaleCan.BrakeSensor2TravelPercentage;
		case Can_PEDALS_PressureSensorVoltage:
			return pedaleCan.PressureSensorVoltage;
		case Can_PEDALS_PressureSensorBars:
			return pedaleCan.PressureSensorBars;
		case Can_PEDALS_Accel_Sensor1_ShortToGnd:
			return pedaleCan.Accel_Sensor1_ShortToGnd;
		case Can_PEDALS_Accel_Sensor1_ShortToVcc:
			return pedaleCan.Accel_Sensor1_ShortToVcc;
		case Can_PEDALS_Accel_Sensor1_OutOfRangeOutput:
			return pedaleCan.Accel_Sensor1_OutOfRangeOutput;
		case Can_PEDALS_Accel_Sensor2_ShortToGnd:
			return pedaleCan.Accel_Sensor2_ShortToGnd;
		case Can_PEDALS_Accel_Sensor2_ShortToVcc:
			return pedaleCan.Accel_Sensor2_ShortToVcc;
		case Can_PEDALS_Accel_Sensor2_OutOfRangeOutput:
			return pedaleCan.Accel_Sensor2_OutOfRangeOutput;
		case Can_PEDALS_Accel_Implausibility:
			return pedaleCan.Accel_Implausibility;
		case Can_PEDALS_Brake_Sensor1_ShortToGnd:
			return pedaleCan.Brake_Sensor1_ShortToGnd;
		case Can_PEDALS_Brake_Sensor1_ShortToVcc:
			return pedaleCan.Brake_Sensor1_ShortToVcc;
		case Can_PEDALS_Brake_Sensor1_OutOfRangeOutput:
			return pedaleCan.Brake_Sensor1_OutOfRangeOutput;
		case Can_PEDALS_Brake_Sensor2_ShortToGnd:
			return pedaleCan.Brake_Sensor2_ShortToGnd;
		case Can_PEDALS_Brake_Sensor2_ShortToVcc:
			return pedaleCan.Brake_Sensor2_ShortToVcc;
		case Can_PEDALS_Brake_Sensor2_OutOfRangeOutput:
			return pedaleCan.Brake_Sensor2_OutOfRangeOutput;
		case Can_PEDALS_Brake_Implausibility:
			return pedaleCan.Brake_Implausibility;
		case Can_INVERTERS_LeftInverterTemperature:
			return invertoareCan.LeftInverterTemperature;
		case Can_INVERTERS_LeftMotorTemperature:
			return invertoareCan.LeftMotorTemperature;
		case Can_INVERTERS_LeftInverterInputVoltage:
			return invertoareCan.LeftInverterInputVoltage;
		case Can_INVERTERS_LeftInverterCurrent:
			return invertoareCan.LeftInverterCurrent;
		case Can_INVERTERS_LeftMotorRpm:
			return invertoareCan.LeftMotorRpm;
		case Can_INVERTERS_LeftMotorSpeedKmh:
			return invertoareCan.LeftMotorSpeedKmh;
		case Can_INVERTERS_LeftInverterThrottle:
			return invertoareCan.LeftInverterThrottle;
		case Can_INVERTERS_LeftInverterThrottleFeedback:
			return invertoareCan.LeftInverterThrottleFeedback;
		case Can_INVERTERS_RightInverterTemperature:
			return invertoareCan.RightInverterTemperature;
		case Can_INVERTERS_RightMotorTemperature:
			return invertoareCan.RightMotorTemperature;
		case Can_INVERTERS_RightInverterInputVoltage:
			return invertoareCan.RightInverterInputVoltage;
		case Can_INVERTERS_RightInverterCurrent:
			return invertoareCan.RightInverterCurrent;
		case Can_INVERTERS_RightMotorRpm:
			return invertoareCan.RightMotorRpm;
		case Can_INVERTERS_RightMotorSpeedKmh:
			return invertoareCan.RightMotorSpeedKmh;
		case Can_INVERTERS_RightInverterSentThrottle:
			return invertoareCan.RightInverterSentThrottle;
		case Can_INVERTERS_RightInverterThrottleFeedback:
			return invertoareCan.RightInverterThrottleFeedback;
		case Can_INVERTERS_IsCarInReverse:
			return invertoareCan.IsCarInReverse;
		case Can_INVERTERS_IsCarRunning:
			return invertoareCan.IsCarRunning;
		case Can_DASHBOARD_ActivationButtonPressed:
			return bordCan.ActivationButtonPressed;
		case Can_DASHBOARD_CarReverseCommandPressed:
			return bordCan.CarReverseCommandPressed;
		case Can_DASHBOARD_IsDisplayWorking:
			return bordCan.IsDisplayWorking;
		case Can_DASHBOARD_IsSegmentsDriverWorking:
			return bordCan.IsSegmentsDriverWorking;
		//COMMUNICATIONS
		case Can_COMMUNICATIONS_IsInverterVcuSimulated:
			return comunicatiiCan.IsInverterVcuSimulated;
		case Can_COMMUNICATIONS_IsTsacVcuSimulated:
			return comunicatiiCan.IsTsacVcuSimulated;
		case Can_COMMUNICATIONS_IsDashboardVcuSimulated:
			return comunicatiiCan.IsDashboardVcuSimulated;
		case Can_COMMUNICATIONS_IsPedalsVcuSimulated:
			return comunicatiiCan.IsPedalsVcuSimulated;
		default:
			return 0;
	}
	return 0;
}

uint16_t CanMessaging_ReadCellVoltage(uint16_t index){
	//NU SCOATE IF-URILE: SUNT DE SIGURANTA
	if(index < CELLS_NUM)
		return baterieCan.CellVoltage[index];
	else
		return 0;
}
boolean CanMessaging_ReadCellVoltageErrors(uint16_t index){
	//NU SCOATE IF-URILE: SUNT DE SIGURANTA
	if(index < CELLS_NUM)
		return baterieCan.CellVoltageErrors[index];
	else
		return 0;
}
uint16_t CanMessaging_ReadCellTemperature(uint16_t index){
	//NU SCOATE IF-URILE: SUNT DE SIGURANTA
	if(index < THERMISTOR_NUM)
		return baterieCan.ThermistorTemperature[index];
	else
		return 0;
}
boolean CanMessaging_ReadCellTemperatureErrors(uint16_t index){
	//NU SCOATE IF-URILE: SUNT DE SIGURANTA
	if(index < THERMISTOR_NUM)
		return baterieCan.ThermistorTemperatureErrors[index];
	else
		return 0;
}

boolean CanMessaging_ReceiveData(Can_HwHandleType handle, Can_IdType id, PduLengthType length, uint8_t* data){
	switch((id&INTERRUPT_MASK)){
		case idCanFrana:
			//extragere date
			CanMessaging_SetValue(Can_PEDALS_BrakeSensor1Voltage, ((((uint16_t)data[6])<<8) | data[7]) & (0x3FFF));
			CanMessaging_SetValue(Can_PEDALS_BrakeSensor2Voltage, ((((((uint16_t)data[4])<<8) | data[5]) & (0x0FFF)) << 2) | (data[6]>>6));
			CanMessaging_SetValue(Can_PEDALS_BrakeSensor1TravelPercentage, (((uint8_t)(data[3]<<4)) | (data[4]>>4)) & (0x7F));
			CanMessaging_SetValue(Can_PEDALS_BrakeSensor2TravelPercentage, (((uint8_t)(data[2]<<5)) | (data[3]>>3)) & (0x7F));
			CanMessaging_SetValue(Can_PEDALS_PressureSensorBars, ((uint8_t)(data[1]<<6)) | (data[2]>>2));
			CanMessaging_SetValue(Can_PEDALS_Brake_Implausibility, (data[0] & (1<<1)) >> 1);
			CanMessaging_SetValue(Can_PEDALS_Brake_Sensor1_OutOfRangeOutput, (data[0] & (1<<5)) >> 5);
			CanMessaging_SetValue(Can_PEDALS_Brake_Sensor1_ShortToVcc, (data[0] & (1<<6)) >> 6);
			CanMessaging_SetValue(Can_PEDALS_Brake_Sensor1_ShortToGnd, (data[0] & (1<<7)) >> 7);
			CanMessaging_SetValue(Can_PEDALS_Brake_Sensor2_OutOfRangeOutput, (data[0] & (1<<2)) >> 2);
			CanMessaging_SetValue(Can_PEDALS_Brake_Sensor2_ShortToVcc, (data[0] & (1<<3)) >> 3);
			CanMessaging_SetValue(Can_PEDALS_Brake_Sensor2_ShortToGnd, (data[0] & (1<<4)) >> 4);
			break;

		case idCanAcceleratie:
			//extragere date
			CanMessaging_SetValue(Can_PEDALS_AcceleratorSensor1Voltage, ((((uint16_t)data[6])<<8) | data[7]) & (0x3FFF));
			CanMessaging_SetValue(Can_PEDALS_AcceleratorSensor2Voltage, ((((((uint16_t)data[4])<<8) | data[5]) & (0x0FFF)) << 2) | (data[6]>>6));
			CanMessaging_SetValue(Can_PEDALS_AcceleratorSensor1TravelPercentage, (((uint8_t)(data[3]<<4)) | (data[4]>>4)) & (0x7F));
			CanMessaging_SetValue(Can_PEDALS_AcceleratorSensor2TravelPercentage, (((uint8_t)(data[2]<<5)) | (data[3]>>3)) & (0x7F));
			CanMessaging_SetValue(Can_PEDALS_PressureSensorVoltage, ((((uint16_t)data[1]<<6)) | (data[2]>>2)) & (0x01FF));
			CanMessaging_SetValue(Can_PEDALS_Accel_Implausibility, (data[0] & (1<<1)) >> 1);
			CanMessaging_SetValue(Can_PEDALS_Accel_Sensor1_OutOfRangeOutput, (data[0] & (1<<5)) >> 5);
			CanMessaging_SetValue(Can_PEDALS_Accel_Sensor1_ShortToVcc, (data[0] & (1<<6)) >> 6);
			CanMessaging_SetValue(Can_PEDALS_Accel_Sensor1_ShortToGnd, (data[0] & (1<<7)) >> 7);
			CanMessaging_SetValue(Can_PEDALS_Accel_Sensor2_OutOfRangeOutput, (data[0] & (1<<2)) >> 2);
			CanMessaging_SetValue(Can_PEDALS_Accel_Sensor2_ShortToVcc, (data[0] & (1<<3)) >> 3);
			CanMessaging_SetValue(Can_PEDALS_Accel_Sensor2_ShortToGnd, (data[0] & (1<<4)) >>4);
			break;

		case idCanInvertorStanga:
			//extragere date
			CanMessaging_SetValue(Can_INVERTERS_LeftMotorTemperature, data[7]);
			CanMessaging_SetValue(Can_INVERTERS_LeftInverterTemperature, data[6]);
			CanMessaging_SetValue(Can_INVERTERS_LeftInverterThrottle, data[5]);
			CanMessaging_SetValue(Can_INVERTERS_LeftMotorSpeedKmh, data[4]);
			CanMessaging_SetValue(Can_INVERTERS_LeftInverterThrottleFeedback, data[3]);
			CanMessaging_SetValue(Can_INVERTERS_LeftInverterInputVoltage, ((((uint16_t)data[1])<<8) | data[2]) & (0x07FF));
			CanMessaging_SetValue(Can_INVERTERS_LeftMotorRpm, ((((uint16_t)data[0])<<8) | data[1]) >> 3);
			break;

		case idCanInvertorDreapta:
			//extragere date
			CanMessaging_SetValue(Can_INVERTERS_RightMotorTemperature, data[7]);
			CanMessaging_SetValue(Can_INVERTERS_RightInverterTemperature, data[6]);
			CanMessaging_SetValue(Can_INVERTERS_RightInverterSentThrottle, data[5]);
			CanMessaging_SetValue(Can_INVERTERS_RightMotorSpeedKmh, data[4]);
			CanMessaging_SetValue(Can_INVERTERS_RightInverterThrottleFeedback, data[3]);
			CanMessaging_SetValue(Can_INVERTERS_RightInverterInputVoltage, ((((uint16_t)data[1])<<8) | data[2]) & (0x7FF));
			CanMessaging_SetValue(Can_INVERTERS_RightMotorRpm, ((((uint16_t)data[0])<<8) | data[1]) >> 3);
			break;

		case idCanInvertoare:
			CanMessaging_SetValue(Can_INVERTERS_IsCarRunning, (data[0] & (1<<7)) >> 7);
			CanMessaging_SetValue(Can_INVERTERS_IsCarInReverse, (data[0] & (1<<6)) >> 6);
			CanMessaging_SetValue(Can_INVERTERS_LeftInverterCurrent, ((((uint16_t)data[6])<<8) | data[7]) & (0x0FFF));
			CanMessaging_SetValue(Can_INVERTERS_RightInverterCurrent, ((((uint16_t)data[5])<<8) | data[6]) >> 4);
			break;

		case idCanBaterie1:
			//extragere date
			CanMessaging_SetValue(Can_TSAC_OverallCurrent, ((((uint16_t)data[6]) << 8) | data[7]) & (0x1FFF));
			CanMessaging_SetValue(Can_TSAC_OverallVoltage, ((((uint16_t)data[5]) << 8) | data[6]) >> 5);
			CanMessaging_SetValue(Can_TSAC_HighestCellTemperature, ((((uint16_t)data[3]) << 8) | data[4]) & (0x03FF));
			CanMessaging_SetValue(Can_TSAC_HighestCellVoltage, (((((uint16_t)data[2]) << 8) | data[3]) >> 2) & (0x03FF));
			CanMessaging_SetValue(Can_TSAC_LowestCellVoltage, (((((uint16_t)data[1]) << 8) | data[2]) >> 4) & (0x03FF));
			CanMessaging_SetValue(Can_TSAC_LowestCellTemperature, (((((uint16_t)data[0]) << 8) | data[1]) >> 6) & (0x03FF));
			break;

		case idCanBaterie2:{
			uint8_t index = (uint8_t)((data[0])) & (0x07);
			index = index * 5;
			CanMessaging_SetCellVoltageErrors(((data[0] & (1<<7)) >> 7), index + 0);
			CanMessaging_SetCellVoltageErrors(((data[0] & (1<<6)) >> 6), index + 1);
			CanMessaging_SetCellVoltageErrors(((data[0] & (1<<5)) >> 5), index + 2);
			CanMessaging_SetCellVoltageErrors(((data[0] & (1<<4)) >> 4), index + 3);
			CanMessaging_SetCellVoltageErrors(((data[0] & (1<<3)) >> 3), index + 4);
			CanMessaging_SetCellVoltage((((((uint16_t)data[1]) << 8) | data[2]) & (0x03FF)), index + 0);
			CanMessaging_SetCellVoltage(((((((uint16_t)data[3]) << 8) | data[4]) >> 6) & (0x03FF)), index + 1);
			CanMessaging_SetCellVoltage(((((((uint16_t)data[4]) << 8) | data[5]) >> 4) & (0x03FF)), index + 2);
			CanMessaging_SetCellVoltage(((((((uint16_t)data[5]) << 8) | data[6]) >> 2) & (0x03FF)), index + 3);
			CanMessaging_SetCellVoltage((((((uint16_t)data[6]) << 8) | data[7]) & (0x03FF)), index + 4);
			break;
		}

		case idCanBaterie3:{
			uint16_t index = (uint16_t)((data[0] << 2) | (data[1] >> 6)) & (0x001F);
			index = index * 5;
			CanMessaging_SetCellTemperatureErrors(((data[0] & (1<<7)) >> 7), index + 0);
			CanMessaging_SetCellTemperatureErrors(((data[0] & (1<<6)) >> 6), index + 1);
			CanMessaging_SetCellTemperatureErrors(((data[0] & (1<<5)) >> 5), index + 2);
			CanMessaging_SetCellTemperatureErrors(((data[0] & (1<<4)) >> 4), index + 3);
			CanMessaging_SetCellTemperatureErrors(((data[0] & (1<<3)) >> 3), index + 4);
			CanMessaging_SetCellTemperature((((((uint16_t)data[1]) << 8) | data[2]) & (0x03FF)), index + 0);
			CanMessaging_SetCellTemperature(((((((uint16_t)data[3]) << 8) | data[4]) >> 6) & (0x03FF)), index + 1);
			CanMessaging_SetCellTemperature(((((((uint16_t)data[4]) << 8) | data[5]) >> 4) & (0x03FF)), index + 2);
			CanMessaging_SetCellTemperature(((((((uint16_t)data[5]) << 8) | data[6]) >> 2) & (0x03FF)), index + 3);
			CanMessaging_SetCellTemperature((((((uint16_t)data[6]) << 8) | data[7]) & (0x03FF)), index + 4);
			break;
		}

		case idCanBaterie4:
			CanMessaging_SetValue(Can_TSAC_MedianCellTemperature, (((((uint16_t)data[0]) << 8) | data[1]) >> 6) & (0x03FF));
			CanMessaging_SetValue(Can_TSAC_MedianCellVoltage, (((((uint16_t)data[1]) << 8) | data[2]) >> 4) & (0x03FF));
			CanMessaging_SetValue(Can_TSAC_IsShuntWorking, (data[2] & (1<<3)) >> 3);
			CanMessaging_SetValue(Can_TSAC_IsTransceiverWorking, (data[2] & (1<<2)) >> 2);
			CanMessaging_SetValue(Can_TSAC_IsBms0Working, (data[2] & (1<<1)) >> 1);
			CanMessaging_SetValue(Can_TSAC_IsBms1Working, (data[2] & (1<<0)) >> 0);
			CanMessaging_SetValue(Can_TSAC_AreThermistorsWorking, (data[3] & (1<<7)) >> 7);
			CanMessaging_SetValue(Can_TSAC_IsAmsSafe, (data[3] & (1<<6)) >> 6);
			CanMessaging_SetValue(Can_TSAC_IsCharging, (data[3] & (1<<0)) >> 0);
			CanMessaging_SetValue(Can_TSAC_ReportedChargingCurrent, (((uint16_t)data[4]) << 8) | data[5]);
			CanMessaging_SetValue(Can_TSAC_ReportedChargingVoltage, (((uint16_t)data[6]) << 8) | data[7]);
			break;

		case idCanBaterie5:
			CanMessaging_SetValue(Can_TSAC_ChargerCommand, (data[0] & (1<<7)) >> 7);
			CanMessaging_SetValue(Can_TSAC_DesiredChargingCurrent, (((((uint16_t)data[5]) << 8) | data[6]) >> 2) & (0x01FF));
			CanMessaging_SetValue(Can_TSAC_DesiredChargingVoltage, ((((uint16_t)data[6]) << 8) | data[7]) & (0x03FF));
			break;

		case idCanBord:
			//extragere date
			CanMessaging_SetValue(Can_DASHBOARD_ActivationButtonPressed, (data[0] & (1<<7)) >> 7);
			CanMessaging_SetValue(Can_DASHBOARD_CarReverseCommandPressed, (data[0] & (1<<6)) >> 6);
			CanMessaging_SetValue(Can_DASHBOARD_IsDisplayWorking, (data[0] & (1<<5)) >> 5);
			CanMessaging_SetValue(Can_DASHBOARD_IsSegmentsDriverWorking, (data[0] & (1<<4)) >> 4);
			break;
		case idCanComunicatii:
			CanMessaging_SetValue(Can_COMMUNICATIONS_IsInverterVcuSimulated, (data[0] & (1<<7)) >> 7);
			CanMessaging_SetValue(Can_COMMUNICATIONS_IsTsacVcuSimulated, (data[0] & (1<<6)) >> 6);
			CanMessaging_SetValue(Can_COMMUNICATIONS_IsDashboardVcuSimulated, (data[0] & (1<<5)) >> 5);
			CanMessaging_SetValue(Can_COMMUNICATIONS_IsPedalsVcuSimulated, (data[0] & (1<<4)) >> 4);
			break;
		default:
			return FALSE;
	}
	return TRUE;
}

void CanMessaging_CreateCellVoltageBuffer(uint16_t index){
	bufferCan[0] = index | (CanMessaging_ReadCellVoltageErrors(index*5+0) << 7) | (CanMessaging_ReadCellVoltageErrors(index*5+1) << 6) | (CanMessaging_ReadCellVoltageErrors(index*5+2) << 5) | (CanMessaging_ReadCellVoltageErrors(index*5+3) << 4) | (CanMessaging_ReadCellVoltageErrors(index*5+4) << 3);
	bufferCan[1] = (CanMessaging_ReadCellVoltage(index*5+0) >> 8);
	bufferCan[2] = CanMessaging_ReadCellVoltage(index*5+0) & (0x00FF);
	bufferCan[3] = CanMessaging_ReadCellVoltage(index*5+1) >> 2;
	bufferCan[4] = ((CanMessaging_ReadCellVoltage(index*5+1) & (0x0003)) << 6) | (CanMessaging_ReadCellVoltage(index*5+2) >> 4);
	bufferCan[5] = ((CanMessaging_ReadCellVoltage(index*5+2) & (0x000F)) << 4) | (CanMessaging_ReadCellVoltage(index*5+3) >> 6);
	bufferCan[6] = ((CanMessaging_ReadCellVoltage(index*5+3) & (0x003F)) << 2) | (CanMessaging_ReadCellVoltage(index*5+4) >> 8);
	bufferCan[7] = CanMessaging_ReadCellVoltage(index*5+4) & (0x00FF); //PENTRU URMATORUL NEFERICIT, DACA APAR PROBLEME INSEAMNA CA AI MODIFICAT FUNCTIA DE READ VALUE SI AI SCORS SIGURANTA (god have mercy on your soul)
}

void CanMessaging_CreateCellTemperatureBuffer(uint16_t index){
	bufferCan[0] = (index >> 2) | (CanMessaging_ReadCellTemperatureErrors(index*5+0) << 7) | (CanMessaging_ReadCellTemperatureErrors(index*5+1) << 6) | (CanMessaging_ReadCellTemperatureErrors(index*5+2) << 5) | (CanMessaging_ReadCellTemperatureErrors(index*5+3) << 4) | (CanMessaging_ReadCellTemperatureErrors(index*5+4) << 3);
	bufferCan[1] = ((index & (0x0003)) << 6) | (CanMessaging_ReadCellTemperature(index*5+0) >> 8);
	bufferCan[2] = CanMessaging_ReadCellTemperature(index*5+0) & (0x00FF);
	bufferCan[3] = CanMessaging_ReadCellTemperature(index*5+1) >> 2;
	bufferCan[4] = ((CanMessaging_ReadCellTemperature(index*5+1) & (0x0003)) << 6) | (CanMessaging_ReadCellTemperature(index*5+2) >> 4);
	bufferCan[5] = ((CanMessaging_ReadCellTemperature(index*5+2) & (0x000F)) << 4) | (CanMessaging_ReadCellTemperature(index*5+3) >> 6);
	bufferCan[6] = ((CanMessaging_ReadCellTemperature(index*5+3) & (0x003F)) << 2) | (CanMessaging_ReadCellTemperature(index*5+4) >> 8);
	bufferCan[7] = CanMessaging_ReadCellTemperature(index*5+4) & (0x00FF); //PENTRU URMATORUL NEFERICIT, DACA APAR PROBLEME INSEAMNA CA AI MODIFICAT FUNCTIA DE READ VALUE SI AI SCORS SIGURANTA (god have mercy on your soul)
}

void CanMessaging_CreateBuffer(idCan_t type){
	switch(type){
		case idCanInvertorStanga:
			bufferCan[0] = CanMessaging_ReadValue(Can_INVERTERS_LeftMotorRpm) >> 5;
			bufferCan[1] = ((CanMessaging_ReadValue(Can_INVERTERS_LeftMotorRpm) & (0x00F8))) | ((CanMessaging_ReadValue(Can_INVERTERS_LeftInverterInputVoltage) & (0x0700)) >> 8);
			bufferCan[2] = ((uint8_t) CanMessaging_ReadValue(Can_INVERTERS_LeftInverterInputVoltage) & (0x00FF));
			bufferCan[3] = CanMessaging_ReadValue(Can_INVERTERS_LeftInverterThrottleFeedback);
			bufferCan[4] = CanMessaging_ReadValue(Can_INVERTERS_LeftMotorSpeedKmh);
			bufferCan[5] = CanMessaging_ReadValue(Can_INVERTERS_LeftInverterThrottle);
			bufferCan[6] = CanMessaging_ReadValue(Can_INVERTERS_LeftInverterTemperature);
			bufferCan[7] = CanMessaging_ReadValue(Can_INVERTERS_LeftMotorTemperature);
			break;
		case idCanInvertorDreapta:
			bufferCan[0] = CanMessaging_ReadValue(Can_INVERTERS_RightMotorRpm) >> 5;
			bufferCan[1] = ((CanMessaging_ReadValue(Can_INVERTERS_RightMotorRpm) & (0x00F8))) | ((CanMessaging_ReadValue(Can_INVERTERS_RightInverterInputVoltage) & (0x700)) >> 8);
			bufferCan[2] = ((uint8_t) CanMessaging_ReadValue(Can_INVERTERS_RightInverterInputVoltage) & (0x7FF));
			bufferCan[3] = CanMessaging_ReadValue(Can_INVERTERS_RightInverterThrottleFeedback);
			bufferCan[4] = CanMessaging_ReadValue(Can_INVERTERS_RightMotorSpeedKmh);
			bufferCan[5] = CanMessaging_ReadValue(Can_INVERTERS_RightInverterSentThrottle);
			bufferCan[6] = CanMessaging_ReadValue(Can_INVERTERS_RightInverterTemperature);
			bufferCan[7] = CanMessaging_ReadValue(Can_INVERTERS_RightMotorTemperature);
			break;
		case idCanInvertoare:
			bufferCan[0] = (CanMessaging_ReadValue(Can_INVERTERS_IsCarRunning) << 7) | (CanMessaging_ReadValue(Can_INVERTERS_IsCarInReverse) << 6);
			bufferCan[1] = 0;
			bufferCan[2] = 0;
			bufferCan[3] = 0;
			bufferCan[4] = 0;
			bufferCan[5] = (CanMessaging_ReadValue(Can_INVERTERS_RightInverterCurrent) & (0x0FF0)) >> 4;
			bufferCan[6] = ((CanMessaging_ReadValue(Can_INVERTERS_RightInverterCurrent) & (0x000F)) << 4) | ((CanMessaging_ReadValue(Can_INVERTERS_LeftInverterCurrent) & (0x0F00)) >> 8);
			bufferCan[7] = CanMessaging_ReadValue(Can_INVERTERS_LeftInverterCurrent) & (0x00FF);
			break;
		case idCanBord:
			bufferCan[0] = (CanMessaging_ReadValue(Can_DASHBOARD_ActivationButtonPressed) << 7) | (CanMessaging_ReadValue(Can_DASHBOARD_CarReverseCommandPressed) << 6) | (CanMessaging_ReadValue(Can_DASHBOARD_IsDisplayWorking) << 5) | (CanMessaging_ReadValue(Can_DASHBOARD_IsSegmentsDriverWorking) << 4);
			bufferCan[1] = 0;
			bufferCan[2] = 0;
			bufferCan[3] = 0;
			bufferCan[4] = 0;
			bufferCan[5] = 0;
			bufferCan[6] = 0;
			bufferCan[7] = 0;
			break;
		case idCanAcceleratie:
			bufferCan[0] = (CanMessaging_ReadValue(Can_PEDALS_Accel_Sensor1_ShortToGnd) << 7) | (CanMessaging_ReadValue(Can_PEDALS_Accel_Sensor1_ShortToVcc) << 6) | (CanMessaging_ReadValue(Can_PEDALS_Accel_Sensor1_OutOfRangeOutput) << 5) | (CanMessaging_ReadValue(Can_PEDALS_Accel_Sensor2_ShortToGnd) << 4) | (CanMessaging_ReadValue(Can_PEDALS_Accel_Sensor2_ShortToVcc) << 3) | (CanMessaging_ReadValue(Can_PEDALS_Accel_Sensor2_OutOfRangeOutput) << 2) | (CanMessaging_ReadValue(Can_PEDALS_Accel_Implausibility) << 1);
			bufferCan[1] = (CanMessaging_ReadValue(Can_PEDALS_PressureSensorVoltage) & (0x01C0)) >> 6;
			bufferCan[2] = ((CanMessaging_ReadValue(Can_PEDALS_AcceleratorSensor2TravelPercentage) & (0x0060)) >> 5) | ((CanMessaging_ReadValue(Can_PEDALS_PressureSensorVoltage) & (0x003F)) << 2);
			bufferCan[3] = ((CanMessaging_ReadValue(Can_PEDALS_AcceleratorSensor2TravelPercentage) & (0x001F)) << 3) | ((CanMessaging_ReadValue(Can_PEDALS_AcceleratorSensor1TravelPercentage) & (0x0070)) >>4);
			bufferCan[4] = ((CanMessaging_ReadValue(Can_PEDALS_AcceleratorSensor2Voltage) & (0x3C00)) >> 10) | ((CanMessaging_ReadValue(Can_PEDALS_AcceleratorSensor1TravelPercentage) & (0x000F)) << 4);
			bufferCan[5] = (CanMessaging_ReadValue(Can_PEDALS_AcceleratorSensor2Voltage) & (0x03FC)) >> 2;
			bufferCan[6] = (CanMessaging_ReadValue(Can_PEDALS_AcceleratorSensor2Voltage) & (0x0003) << 6) | ((CanMessaging_ReadValue(Can_PEDALS_AcceleratorSensor1Voltage) & (0x3F00)) >> 8);
			bufferCan[7] = CanMessaging_ReadValue(Can_PEDALS_AcceleratorSensor1Voltage) & (0x00FF);
			break;
		case idCanFrana:
			bufferCan[0] = (CanMessaging_ReadValue(Can_PEDALS_Brake_Sensor1_ShortToGnd) << 7) | (CanMessaging_ReadValue(Can_PEDALS_Brake_Sensor1_ShortToVcc) << 6) | (CanMessaging_ReadValue(Can_PEDALS_Brake_Sensor1_OutOfRangeOutput) << 5) | (CanMessaging_ReadValue(Can_PEDALS_Brake_Sensor2_ShortToGnd) << 4) | (CanMessaging_ReadValue(Can_PEDALS_Brake_Sensor2_ShortToVcc) << 3) | (CanMessaging_ReadValue(Can_PEDALS_Brake_Sensor2_OutOfRangeOutput) << 2) | (CanMessaging_ReadValue(Can_PEDALS_Brake_Implausibility) << 1);
			bufferCan[1] = (CanMessaging_ReadValue(Can_PEDALS_PressureSensorBars) & (0x00C0)) >> 6;
			bufferCan[2] = ((CanMessaging_ReadValue(Can_PEDALS_BrakeSensor2TravelPercentage) & (0x0060)) >> 5) | ((CanMessaging_ReadValue(Can_PEDALS_PressureSensorBars) & (0x003F)) << 2);
			bufferCan[3] = ((CanMessaging_ReadValue(Can_PEDALS_BrakeSensor2TravelPercentage) & (0x001F)) << 3) | ((CanMessaging_ReadValue(Can_PEDALS_BrakeSensor1TravelPercentage) & (0x007)) >>4);
			bufferCan[4] = ((CanMessaging_ReadValue(Can_PEDALS_BrakeSensor2Voltage) & (0x3C00)) >> 10) | ((CanMessaging_ReadValue(Can_PEDALS_BrakeSensor1TravelPercentage) & (0x000F)) << 4);
			bufferCan[5] = (CanMessaging_ReadValue(Can_PEDALS_BrakeSensor2Voltage) & (0x03FC)) >> 2;
			bufferCan[6] = (CanMessaging_ReadValue(Can_PEDALS_BrakeSensor2Voltage) & (0x0003) << 6) | ((CanMessaging_ReadValue(Can_PEDALS_BrakeSensor1Voltage) & (0x3F00)) >> 8);
			bufferCan[7] = CanMessaging_ReadValue(Can_PEDALS_BrakeSensor1Voltage) & (0x00FF);
			break;
		case idCanBaterie1:
			bufferCan[0] = CanMessaging_ReadValue(Can_TSAC_LowestCellTemperature) >> 2;
			bufferCan[1] = (CanMessaging_ReadValue(Can_TSAC_LowestCellVoltage) >> 4) | ((CanMessaging_ReadValue(Can_TSAC_LowestCellTemperature) & (0x0003)) << 6);
			bufferCan[2] = (CanMessaging_ReadValue(Can_TSAC_HighestCellVoltage) & (0x03C0)) >> 6 | ((CanMessaging_ReadValue(Can_TSAC_LowestCellVoltage) & (0x000F)) << 4);
			bufferCan[3] = ((CanMessaging_ReadValue(Can_TSAC_HighestCellTemperature) & (0x0300)) >> 8) | ((CanMessaging_ReadValue(Can_TSAC_HighestCellVoltage) & (0x003F)) << 2);
			bufferCan[4] = CanMessaging_ReadValue(Can_TSAC_HighestCellTemperature) & (0x00FF);
			bufferCan[5] = (CanMessaging_ReadValue(Can_TSAC_OverallVoltage) & (0x07F8)) >> 3;
			bufferCan[6] = ((CanMessaging_ReadValue(Can_TSAC_OverallVoltage) & (0x0007)) << 5) | ((CanMessaging_ReadValue(Can_TSAC_OverallCurrent) & (0x1F00)) >> 8);
			bufferCan[7] = CanMessaging_ReadValue(Can_TSAC_OverallCurrent) & (0x00FF);
			break;
		case idCanBaterie2:{
			//ESTE APELATA FUNCTIA CanMessaging_CreateCellVoltageBuffer DIRECT IN FUNCTIA DE UPDATE
			break;
		}
		case idCanBaterie3:{
			//ESTE APELATA FUNCTIA CanMessaging_CreateCellTemperatureBuffer DIRECT IN FUNCTIA DE UPDATE
			break;
		}
		case idCanBaterie4:
			bufferCan[0] = CanMessaging_ReadValue(Can_TSAC_MedianCellTemperature) >> 2;
			bufferCan[1] = ((CanMessaging_ReadValue(Can_TSAC_MedianCellTemperature) & (0x0003)) << 6) | (CanMessaging_ReadValue(Can_TSAC_MedianCellVoltage) >> 4);
			bufferCan[2] = ((CanMessaging_ReadValue(Can_TSAC_MedianCellVoltage) & (0x000F)) << 4) | (CanMessaging_ReadValue(Can_TSAC_IsShuntWorking) << 3) | (CanMessaging_ReadValue(Can_TSAC_IsTransceiverWorking) << 2) | (CanMessaging_ReadValue(Can_TSAC_IsBms0Working) << 1) | (CanMessaging_ReadValue(Can_TSAC_IsBms1Working) << 0);
			bufferCan[3] = (CanMessaging_ReadValue(Can_TSAC_AreThermistorsWorking) << 7) | (CanMessaging_ReadValue(Can_TSAC_IsAmsSafe) << 6) | (CanMessaging_ReadValue(Can_TSAC_IsCharging) << 0);
			bufferCan[4] = CanMessaging_ReadValue(Can_TSAC_ReportedChargingCurrent) >> 8;
			bufferCan[5] = CanMessaging_ReadValue(Can_TSAC_ReportedChargingCurrent) & (0x00FF);
			bufferCan[6] = CanMessaging_ReadValue(Can_TSAC_ReportedChargingVoltage) >> 8;
			bufferCan[7] = CanMessaging_ReadValue(Can_TSAC_ReportedChargingVoltage) & (0x00FF);
			break;
		case idCanBaterie5:
			bufferCan[0] = (CanMessaging_ReadValue(Can_TSAC_ChargerCommand) << 7);
			bufferCan[1] = 0;
			bufferCan[2] = 0;
			bufferCan[3] = 0;
			bufferCan[4] = 0;
			bufferCan[5] = (CanMessaging_ReadValue(Can_TSAC_DesiredChargingCurrent) >> 6);
			bufferCan[6] = ((CanMessaging_ReadValue(Can_TSAC_DesiredChargingCurrent) << 2) & (0x003F)) | (CanMessaging_ReadValue(Can_TSAC_DesiredChargingVoltage) >> 8);
			bufferCan[7] = CanMessaging_ReadValue(Can_TSAC_DesiredChargingVoltage) & (0x00FF);
			break;
		case idCanComunicatii:
			bufferCan[0] = (CanMessaging_ReadValue(Can_COMMUNICATIONS_IsInverterVcuSimulated) << 7) | (CanMessaging_ReadValue(Can_COMMUNICATIONS_IsTsacVcuSimulated) << 6) | (CanMessaging_ReadValue(Can_COMMUNICATIONS_IsDashboardVcuSimulated) << 5) | (CanMessaging_ReadValue(Can_COMMUNICATIONS_IsPedalsVcuSimulated) << 4);
			bufferCan[1] = 0;
			bufferCan[2] = 0;
			bufferCan[3] = 0;
			bufferCan[4] = 0;
			bufferCan[5] = 0;
			bufferCan[6] = 0;
			bufferCan[7] = 0;
			break;
	}
}

void CanMessaging_AppTest(void){
	while(1){
		//Brake
		UartMessaging_SetValue(Uart_PEDALS_BrakeSensor1Voltage, CanMessaging_ReadValue(Can_PEDALS_BrakeSensor1Voltage));
		UartMessaging_SetValue(Uart_PEDALS_BrakeSensor2Voltage, CanMessaging_ReadValue(Can_PEDALS_BrakeSensor2Voltage));
		UartMessaging_SetValue(Uart_PEDALS_BrakeSensor1TravelPercentage, CanMessaging_ReadValue(Can_PEDALS_BrakeSensor1TravelPercentage));
		UartMessaging_SetValue(Uart_PEDALS_BrakeSensor2TravelPercentage, CanMessaging_ReadValue(Can_PEDALS_BrakeSensor2TravelPercentage));
		UartMessaging_SetValue(Uart_PEDALS_PressureSensorBars, CanMessaging_ReadValue(Can_PEDALS_PressureSensorBars));
		UartMessaging_SetValue(Uart_PEDALS_Brake_Implausibility, CanMessaging_ReadValue(Can_PEDALS_Brake_Implausibility));
		UartMessaging_SetValue(Uart_PEDALS_Brake_Sensor1_OutOfRangeOutput, CanMessaging_ReadValue(Can_PEDALS_Brake_Sensor1_OutOfRangeOutput));
		UartMessaging_SetValue(Uart_PEDALS_Brake_Sensor1_ShortToVcc, CanMessaging_ReadValue(Can_PEDALS_Brake_Sensor1_ShortToVcc));
		UartMessaging_SetValue(Uart_PEDALS_Brake_Sensor1_ShortToGnd, CanMessaging_ReadValue(Can_PEDALS_Brake_Sensor1_ShortToGnd));
		UartMessaging_SetValue(Uart_PEDALS_Brake_Sensor2_OutOfRangeOutput, CanMessaging_ReadValue(Can_PEDALS_Brake_Sensor2_OutOfRangeOutput));
		UartMessaging_SetValue(Uart_PEDALS_Brake_Sensor2_ShortToVcc, CanMessaging_ReadValue(Can_PEDALS_Brake_Sensor2_ShortToVcc));
		UartMessaging_SetValue(Uart_PEDALS_Brake_Sensor2_ShortToGnd, CanMessaging_ReadValue(Can_PEDALS_Brake_Sensor2_ShortToGnd));

		//Acclelerator
		UartMessaging_SetValue(Uart_PEDALS_AcceleratorSensor1Voltage, CanMessaging_ReadValue(Can_PEDALS_AcceleratorSensor1Voltage));
		UartMessaging_SetValue(Uart_PEDALS_AcceleratorSensor2Voltage, CanMessaging_ReadValue(Can_PEDALS_AcceleratorSensor2Voltage));
		UartMessaging_SetValue(Uart_PEDALS_AcceleratorSensor1TravelPercentage, CanMessaging_ReadValue(Can_PEDALS_AcceleratorSensor1TravelPercentage));
		UartMessaging_SetValue(Uart_PEDALS_AcceleratorSensor2TravelPercentage, CanMessaging_ReadValue(Can_PEDALS_AcceleratorSensor2TravelPercentage));
		UartMessaging_SetValue(Uart_PEDALS_PressureSensorVoltage, CanMessaging_ReadValue(Can_PEDALS_PressureSensorVoltage));
		UartMessaging_SetValue(Uart_PEDALS_Accel_Implausibility, CanMessaging_ReadValue(Can_PEDALS_Accel_Implausibility));
		UartMessaging_SetValue(Uart_PEDALS_Accel_Sensor1_OutOfRangeOutput, CanMessaging_ReadValue(Can_PEDALS_Accel_Sensor1_OutOfRangeOutput));
		UartMessaging_SetValue(Uart_PEDALS_Accel_Sensor1_ShortToVcc, CanMessaging_ReadValue(Can_PEDALS_Accel_Sensor1_ShortToVcc));
		UartMessaging_SetValue(Uart_PEDALS_Accel_Sensor1_ShortToGnd, CanMessaging_ReadValue(Can_PEDALS_Accel_Sensor1_ShortToGnd));
		UartMessaging_SetValue(Uart_PEDALS_Accel_Sensor2_OutOfRangeOutput, CanMessaging_ReadValue(Can_PEDALS_Accel_Sensor2_OutOfRangeOutput));
		UartMessaging_SetValue(Uart_PEDALS_Accel_Sensor2_ShortToVcc, CanMessaging_ReadValue(Can_PEDALS_Accel_Sensor2_ShortToVcc));
		UartMessaging_SetValue(Uart_PEDALS_Accel_Sensor2_ShortToGnd, CanMessaging_ReadValue(Can_PEDALS_Accel_Sensor2_ShortToGnd));

		//Left Inverters
		UartMessaging_SetValue(Uart_INVERTERS_LeftMotorTemperature, CanMessaging_ReadValue(Can_INVERTERS_LeftMotorTemperature));
		UartMessaging_SetValue(Uart_INVERTERS_LeftInverterTemperature, CanMessaging_ReadValue(Can_INVERTERS_LeftInverterTemperature));
		UartMessaging_SetValue(Uart_INVERTERS_LeftInverterThrottle, CanMessaging_ReadValue(Can_INVERTERS_LeftInverterThrottle));
		UartMessaging_SetValue(Uart_INVERTERS_LeftMotorSpeedKmh, CanMessaging_ReadValue(Can_INVERTERS_LeftMotorSpeedKmh));
		UartMessaging_SetValue(Uart_INVERTERS_LeftInverterThrottleFeedback, CanMessaging_ReadValue(Can_INVERTERS_LeftInverterThrottleFeedback));
		UartMessaging_SetValue(Uart_INVERTERS_LeftInverterInputVoltage, CanMessaging_ReadValue(Can_INVERTERS_LeftInverterInputVoltage));
		UartMessaging_SetValue(Uart_INVERTERS_LeftMotorRpm, CanMessaging_ReadValue(Can_INVERTERS_LeftMotorRpm));

		//Right Inverters
		UartMessaging_SetValue(Uart_INVERTERS_RightMotorTemperature, CanMessaging_ReadValue(Can_INVERTERS_RightMotorTemperature));
		UartMessaging_SetValue(Uart_INVERTERS_RightInverterTemperature, CanMessaging_ReadValue(Can_INVERTERS_RightInverterTemperature));
		UartMessaging_SetValue(Uart_INVERTERS_RightInverterSentThrottle, CanMessaging_ReadValue(Can_INVERTERS_RightInverterSentThrottle));
		UartMessaging_SetValue(Uart_INVERTERS_RightMotorSpeedKmh, CanMessaging_ReadValue(Can_INVERTERS_RightMotorSpeedKmh));
		UartMessaging_SetValue(Uart_INVERTERS_RightInverterThrottleFeedback, CanMessaging_ReadValue(Can_INVERTERS_RightInverterThrottleFeedback));
		UartMessaging_SetValue(Uart_INVERTERS_RightInverterInputVoltage, CanMessaging_ReadValue(Can_INVERTERS_RightInverterInputVoltage));
		UartMessaging_SetValue(Uart_INVERTERS_RightMotorRpm, CanMessaging_ReadValue(Can_INVERTERS_RightMotorRpm));

		//Inverters
		UartMessaging_SetValue(Uart_INVERTERS_IsCarRunning, CanMessaging_ReadValue(Can_INVERTERS_IsCarRunning));
		UartMessaging_SetValue(Uart_INVERTERS_IsCarInReverse, CanMessaging_ReadValue(Can_INVERTERS_IsCarInReverse));
		UartMessaging_SetValue(Uart_INVERTERS_LeftInverterCurrent, CanMessaging_ReadValue(Can_INVERTERS_LeftInverterCurrent));
		UartMessaging_SetValue(Uart_INVERTERS_RightInverterCurrent, CanMessaging_ReadValue(Can_INVERTERS_RightInverterCurrent));

		//TSAC 1
		UartMessaging_SetValue(Uart_TSAC_OverallCurrent, CanMessaging_ReadValue(Can_TSAC_OverallCurrent));
		UartMessaging_SetValue(Uart_TSAC_OverallVoltage, CanMessaging_ReadValue(Can_TSAC_OverallVoltage));
		UartMessaging_SetValue(Uart_TSAC_HighestCellTemperature, CanMessaging_ReadValue(Can_TSAC_HighestCellTemperature));
		UartMessaging_SetValue(Uart_TSAC_HighestCellVoltage, CanMessaging_ReadValue(Can_TSAC_HighestCellVoltage));
		UartMessaging_SetValue(Uart_TSAC_LowestCellVoltage, CanMessaging_ReadValue(Can_TSAC_LowestCellVoltage));
		UartMessaging_SetValue(Uart_TSAC_LowestCellTemperature, CanMessaging_ReadValue(Can_TSAC_LowestCellTemperature));

		//TSAC 2
		for(uint16_t index = 0; index < CELLS_NUM; index++){
			UartMessaging_SetCellVoltageErrors(CanMessaging_ReadCellVoltageErrors(index), index);
			UartMessaging_SetCellVoltage(CanMessaging_ReadCellVoltage(index), index);
		}

		//TSAC 3
		for(uint16_t index = 0; index < THERMISTOR_NUM; index++){
			UartMessaging_SetCellTemperatureErrors(CanMessaging_ReadCellTemperatureErrors(index), index);
			UartMessaging_SetCellTemperature(CanMessaging_ReadCellTemperature(index), index);
		}

		//TSAC 4
		UartMessaging_SetValue(Uart_TSAC_MedianCellTemperature, CanMessaging_ReadValue(Can_TSAC_MedianCellTemperature));
		UartMessaging_SetValue(Uart_TSAC_MedianCellVoltage, CanMessaging_ReadValue(Can_TSAC_MedianCellVoltage));
		UartMessaging_SetValue(Uart_TSAC_IsShuntWorking,  CanMessaging_ReadValue(Can_TSAC_IsShuntWorking));
		UartMessaging_SetValue(Uart_TSAC_IsTransceiverWorking, CanMessaging_ReadValue(Can_TSAC_IsTransceiverWorking));
		UartMessaging_SetValue(Uart_TSAC_IsBms0Working, CanMessaging_ReadValue(Can_TSAC_IsBms0Working));
		UartMessaging_SetValue(Uart_TSAC_IsBms1Working, CanMessaging_ReadValue(Can_TSAC_IsBms1Working));
		UartMessaging_SetValue(Uart_TSAC_AreThermistorsWorking, CanMessaging_ReadValue(Can_TSAC_AreThermistorsWorking));
		UartMessaging_SetValue(Uart_TSAC_IsAmsSafe, CanMessaging_ReadValue(Can_TSAC_IsAmsSafe));
		UartMessaging_SetValue(Uart_TSAC_IsCharging, CanMessaging_ReadValue(Can_TSAC_IsCharging));
		UartMessaging_SetValue(Uart_TSAC_ReportedChargingCurrent, CanMessaging_ReadValue(Can_TSAC_ReportedChargingCurrent));
		UartMessaging_SetValue(Uart_TSAC_ReportedChargingVoltage, CanMessaging_ReadValue(Can_TSAC_ReportedChargingVoltage));

		//TSAC 5
		UartMessaging_SetValue(Uart_TSAC_ChargerCommand, CanMessaging_ReadValue(Can_TSAC_ChargerCommand));
		UartMessaging_SetValue(Uart_TSAC_DesiredChargingCurrent, CanMessaging_ReadValue(Can_TSAC_DesiredChargingCurrent));
		UartMessaging_SetValue(Uart_TSAC_DesiredChargingVoltage, CanMessaging_ReadValue(Can_TSAC_DesiredChargingVoltage));

		//Dashboard
		UartMessaging_SetValue(Uart_DASHBOARD_ActivationButtonPressed, CanMessaging_ReadValue(Can_DASHBOARD_ActivationButtonPressed));
		UartMessaging_SetValue(Uart_DASHBOARD_CarReverseCommandPressed, CanMessaging_ReadValue(Can_DASHBOARD_CarReverseCommandPressed));
		UartMessaging_SetValue(Uart_DASHBOARD_IsDisplayWorking, CanMessaging_ReadValue(Can_DASHBOARD_IsDisplayWorking));
		UartMessaging_SetValue(Uart_DASHBOARD_IsSegmentsDriverWorking, CanMessaging_ReadValue(Can_DASHBOARD_IsSegmentsDriverWorking));

		//Communications
		UartMessaging_SetValue(Uart_COMMUNICATIONS_IsInverterVcuSimulated, CanMessaging_ReadValue(Can_COMMUNICATIONS_IsInverterVcuSimulated));
		UartMessaging_SetValue(Uart_COMMUNICATIONS_IsTsacVcuSimulated, CanMessaging_ReadValue(Can_COMMUNICATIONS_IsTsacVcuSimulated));
		UartMessaging_SetValue(Uart_COMMUNICATIONS_IsDashboardVcuSimulated, CanMessaging_ReadValue(Can_COMMUNICATIONS_IsDashboardVcuSimulated));
		UartMessaging_SetValue(Uart_COMMUNICATIONS_IsPedalsVcuSimulated, CanMessaging_ReadValue(Can_COMMUNICATIONS_IsPedalsVcuSimulated));
		//Send data
		UartMessaging_Update();
	}
}


#ifdef __cplusplus
}
#endif
