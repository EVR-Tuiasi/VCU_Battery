#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Adc.h"
#include "Pedals.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/
#define MAX_VOLTAGE 10813U //3.3 V pt adc de 14 biti

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
static Adc_ValueGroupType buffer0[4];
static Adc_ValueGroupType buffer1[1];
static PedalsData_t date_pedale = {0};
volatile PedalsErrors_t erori_pedale = {0};
static SensorLimits acc1 = {2550, 4500};
static SensorLimits acc2 = {3130, 1670};
static SensorLimits brake1 = {2550, 4500};
static SensorLimits brake2 = {3130, 1670};
static uint8_t marja_eroare = 10;
static uint16_t marja_limite = 1310; //0.4V pt adc de 14 biti
static uint8_t marja_implausibility = 10;

/*==================================================================================================
*                                      GLOBAL CONSTANTS
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
void Pedals_Init(void){
	Adc_SetupResultBuffer(AdcGroup_0, buffer0);
	Adc_SetupResultBuffer(AdcGroup_1, buffer1);
}
void Pedals_Test(void){

}
boolean Pedals_GetError(Pedal_t PedalSelect, Sensor_t SensorSelect, PedalError_t DesiredValueType){
	switch(DesiredValueType){
		case IMPLAUSIBILITY:
			if(PedalSelect == BRAKE)
				return erori_pedale.Brake_Implausibility;
			else
				return erori_pedale.Accel_Implausibility;
			break;
		case SHORT_TO_GND:
			if(PedalSelect == BRAKE){
				if(SensorSelect == SENSOR1)
					return erori_pedale.Brake_Sensor1_ShortToGnd;
				else
					return erori_pedale.Brake_Sensor2_ShortToGnd;
			}
			else{
				if(SensorSelect == SENSOR1)
					return erori_pedale.Accel_Sensor1_ShortToGnd;
				else
					return erori_pedale.Accel_Sensor2_ShortToGnd;
			}
			break;
		case SHORT_TO_VCC:
			if(PedalSelect == BRAKE){
				if(SensorSelect == SENSOR1)
					return erori_pedale.Brake_Sensor1_ShortToVcc;
				else
					return erori_pedale.Brake_Sensor2_ShortToVcc;
			}
			else{
				if(SensorSelect == SENSOR1)
					return erori_pedale.Accel_Sensor1_ShortToVcc;
				else
					return erori_pedale.Accel_Sensor2_ShortToVcc;
			}
			break;
		case OUT_OF_RANGE_OUTPUT:
			if(PedalSelect == BRAKE){
				if(SensorSelect == SENSOR1)
					return erori_pedale.Brake_Sensor1_OutOfRangeOutput;
				else
					return erori_pedale.Brake_Sensor2_OutOfRangeOutput;
			}
			else{
				if(SensorSelect == SENSOR1)
					return erori_pedale.Accel_Sensor1_OutOfRangeOutput;
				else
					return erori_pedale.Accel_Sensor2_OutOfRangeOutput;
			}
			break;
	}
	return 0;
}
uint32_t Pedals_GetData(Pedal_t PedalSelect, Sensor_t SensorSelect, PedalValue_t DesiredValueType){
	switch(DesiredValueType){
		case VOLTAGE:
			if(SensorSelect == SENSOR1){
				if(PedalSelect == ACCEL)
					return date_pedale.AcceleratorSensor1Voltage;
				else
					return date_pedale.BrakeSensor1Voltage;
			}
			else{
				if(PedalSelect == ACCEL)
					return date_pedale.AcceleratorSensor2Voltage;
				else
					return date_pedale.BrakeSensor2Voltage;
			}
			break;
		case PERCENTAGE:
			if(SensorSelect == SENSOR1){
				if(PedalSelect == ACCEL)
					return date_pedale.AcceleratorSensor1TravelPercentage;
				else
					return date_pedale.BrakeSensor1TravelPercentage;
			}
			else{
				if(PedalSelect == ACCEL)
					return date_pedale.AcceleratorSensor2TravelPercentage;
				else
					return date_pedale.BrakeSensor2TravelPercentage;
			}
			break;
	}
	return 0;
}
uint32_t Pedals_GetPressure(BrakePressure_t ValueType){
	switch(ValueType){
		case BARS:
			return date_pedale.PressureSensorBars;
			break;
		case PRESSURE_VOLTAGE:
			return date_pedale.PressureSensorVoltage;
			break;
	}
	return 0;
}

void Pedals_Update(void){

	volatile uint32_t i = 50000;

	Adc_StartGroupConversion(AdcGroup_0);
	Adc_StartGroupConversion(AdcGroup_1);

	while(Adc_GetGroupStatus(AdcGroup_0) == ADC_BUSY);
	while(Adc_GetGroupStatus(AdcGroup_1) == ADC_BUSY);

	Adc_ReadGroup(AdcGroup_0, buffer0);
	Adc_ReadGroup(AdcGroup_1, buffer1);
	while(i--);
	i = 50000;

	erori_pedale.Accel_Implausibility = 0;
	erori_pedale.Accel_Sensor1_OutOfRangeOutput = 0;
	erori_pedale.Accel_Sensor1_ShortToGnd = 0;
	erori_pedale.Accel_Sensor1_ShortToVcc = 0;
	erori_pedale.Accel_Sensor2_OutOfRangeOutput = 0;
	erori_pedale.Accel_Sensor2_ShortToGnd = 0;
	erori_pedale.Accel_Sensor2_ShortToVcc = 0;
	erori_pedale.Brake_Implausibility = 0;
	erori_pedale.Brake_Sensor1_OutOfRangeOutput = 0;
	erori_pedale.Brake_Sensor1_ShortToGnd = 0;
	erori_pedale.Brake_Sensor1_ShortToVcc = 0;
	erori_pedale.Brake_Sensor2_OutOfRangeOutput = 0;
	erori_pedale.Brake_Sensor2_ShortToGnd = 0;
	erori_pedale.Brake_Sensor2_ShortToVcc = 0;

	// Senzor 1 Acceleratie
	date_pedale.AcceleratorSensor1Voltage = buffer0[0];
	if((buffer0[0] >= (acc1.start_valid - marja_eroare)) && (buffer0[0] <= acc1.start_valid))
		date_pedale.AcceleratorSensor1TravelPercentage = 0U;
	else{
		if((buffer0[0] >= acc1.end_valid) && (buffer0[0] <= (acc1.end_valid + marja_eroare)))
			date_pedale.AcceleratorSensor1TravelPercentage = 100U;
		else
			date_pedale.AcceleratorSensor1TravelPercentage = 100U*(buffer0[0]-acc1.start_valid)/(acc1.end_valid-acc1.start_valid);
	}
	if((buffer0[0] > (acc1.end_valid + marja_eroare)) || (buffer0[0] < (acc1.start_valid - marja_eroare)))
		erori_pedale.Accel_Sensor1_OutOfRangeOutput = 1;
	if(buffer0[0] < marja_limite)
		erori_pedale.Accel_Sensor1_ShortToGnd = 1;
	if(buffer0[0] > (MAX_VOLTAGE - marja_limite))
		erori_pedale.Accel_Sensor1_ShortToVcc = 1;

	// Senzor 2 Acceleratie
	date_pedale.AcceleratorSensor2Voltage = buffer0[1];
	if((buffer0[1] <= (acc2.start_valid + marja_eroare)) && (buffer0[1] >= acc2.start_valid))
		date_pedale.AcceleratorSensor2TravelPercentage = 0U;
	else{
		if((buffer0[1] <= acc2.end_valid) && (buffer0[1] >= (acc2.end_valid - marja_eroare)))
			date_pedale.AcceleratorSensor2TravelPercentage = 100U;
		else
			date_pedale.AcceleratorSensor2TravelPercentage = 100U*(acc2.start_valid-buffer0[1])/(acc2.start_valid-acc2.end_valid);
	}
	if((buffer0[1] < (acc2.end_valid - marja_eroare)) || (buffer0[1] > (acc2.start_valid + marja_eroare)))
		erori_pedale.Accel_Sensor2_OutOfRangeOutput = 1;
	if(buffer0[1] < marja_limite)
		erori_pedale.Accel_Sensor2_ShortToGnd = 1;
	if(buffer0[1] > (MAX_VOLTAGE - marja_limite))
		erori_pedale.Accel_Sensor2_ShortToVcc = 1;

	if((date_pedale.AcceleratorSensor1TravelPercentage - date_pedale.AcceleratorSensor2TravelPercentage >= marja_implausibility) || (date_pedale.AcceleratorSensor2TravelPercentage - date_pedale.AcceleratorSensor1TravelPercentage >= marja_implausibility))
		erori_pedale.Accel_Implausibility = 1;

	// Senzor 1 Frana
	date_pedale.BrakeSensor1Voltage = buffer0[2];
	if((buffer0[2] >= (brake1.start_valid - marja_eroare)) && (buffer0[2] <= brake1.start_valid))
		date_pedale.BrakeSensor1TravelPercentage = 0U;
	else{
		if((buffer0[2] >= brake1.end_valid) && (buffer0[2] <= (brake1.end_valid + marja_eroare)))
			date_pedale.BrakeSensor1TravelPercentage = 100U;
		else
			date_pedale.BrakeSensor1TravelPercentage = 100U*(buffer0[2]-brake1.start_valid)/(brake1.end_valid-brake1.start_valid);
	}
	if((buffer0[2] > (brake1.end_valid + marja_eroare)) || (buffer0[2] < (brake1.start_valid - marja_eroare)))
		erori_pedale.Brake_Sensor1_OutOfRangeOutput = 1;
	if(buffer0[2] < marja_limite)
		erori_pedale.Brake_Sensor1_ShortToGnd = 1;
	if(buffer0[2] > (MAX_VOLTAGE - marja_limite))
		erori_pedale.Brake_Sensor1_ShortToVcc = 1;

	// Senzor 2 Frana
	date_pedale.BrakeSensor2Voltage = buffer0[3];
	if((buffer0[3] <= (brake2.start_valid + marja_eroare)) && (buffer0[3] >= brake2.start_valid))
		date_pedale.BrakeSensor2TravelPercentage = 0U;
	else{
		if((buffer0[3] <= brake2.end_valid) && (buffer0[3] >= (brake2.end_valid - marja_eroare)))
			date_pedale.BrakeSensor2TravelPercentage = 100U;
		else
			date_pedale.BrakeSensor2TravelPercentage = 100U*(brake2.start_valid-buffer0[3])/(brake2.start_valid-brake2.end_valid);
	}
	if((buffer0[3] < (brake2.end_valid - marja_eroare)) || (buffer0[3] > (brake2.start_valid + marja_eroare)))
		erori_pedale.Brake_Sensor2_OutOfRangeOutput = 1;
	if(buffer0[3] < marja_limite)
		erori_pedale.Brake_Sensor2_ShortToGnd = 1;
	if(buffer0[3] > (MAX_VOLTAGE - marja_limite))
		erori_pedale.Brake_Sensor2_ShortToVcc = 1;

	if((date_pedale.BrakeSensor1TravelPercentage - date_pedale.BrakeSensor2TravelPercentage >= marja_implausibility) || (date_pedale.BrakeSensor2TravelPercentage - date_pedale.BrakeSensor1TravelPercentage >= marja_implausibility))
		erori_pedale.Brake_Implausibility = 1;

	// Senzor Presiune
	date_pedale.PressureSensorVoltage = ((uint32_t)500U * (uint32_t)buffer1[0]) * (uint32_t)50U / ((uint32_t)33U * (uint32_t)16383U);
	uint32_t pressureVoltageCopy = (uint32_t)date_pedale.PressureSensorVoltage;
	if(pressureVoltageCopy < 50)
		pressureVoltageCopy = 50;
	if(pressureVoltageCopy > 450)
		pressureVoltageCopy = 450;
	pressureVoltageCopy -= 50;
	date_pedale.PressureSensorBars = ((uint32_t)255U * pressureVoltageCopy) / (uint32_t)400U;
}

#ifdef __cplusplus
}
#endif
