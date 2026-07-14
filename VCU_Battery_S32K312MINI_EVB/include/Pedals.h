/*
*   (c) Copyright 2020 NXP
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be used strictly
*   in accordance with the applicable license terms.  By expressly accepting
*   such terms or by downloading, installing, activating and/or otherwise using
*   the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms.  If you do not agree to
*   be bound by the applicable license terms, then you may not retain,
*   install, activate or otherwise use the software.
*
*   This file contains sample code only. It is not part of the production code deliverables.
*/

#ifndef PEDALS_H
#define PEDALS_H

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Mcu.h"
#include "stdint.h"
#include "Stdbool.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

typedef enum{
    BRAKE,
	ACCEL
}Pedal_t;

typedef enum{
    SENSOR1,
	SENSOR2
}Sensor_t;

typedef enum{
    VOLTAGE,
	PERCENTAGE
}PedalValue_t;

typedef enum{
	PRESSURE_VOLTAGE,
	BARS
}BrakePressure_t;

typedef enum{
	SHORT_TO_GND,
	SHORT_TO_VCC,
	OUT_OF_RANGE_OUTPUT,
	IMPLAUSIBILITY
}PedalError_t;

typedef struct{
	uint16_t AcceleratorSensor1Voltage;
	uint16_t AcceleratorSensor2Voltage;
	uint8_t AcceleratorSensor1TravelPercentage;
	uint8_t AcceleratorSensor2TravelPercentage;

	uint16_t BrakeSensor1Voltage;
	uint16_t BrakeSensor2Voltage;
	uint8_t BrakeSensor1TravelPercentage;
	uint8_t BrakeSensor2TravelPercentage;

	uint16_t PressureSensorVoltage;
	uint8_t PressureSensorBars;
}PedalsData_t;

typedef struct{
	/*Status and Errors*/
	bool Accel_Sensor1_ShortToGnd;                      /* 1 bit, 0 means safe, 1 means errors */
    bool Accel_Sensor1_ShortToVcc;                      /* 1 bit, 0 means safe, 1 means errors */
    bool Accel_Sensor1_OutOfRangeOutput;                /* 1 bit, 0 means safe, 1 means errors */
    bool Accel_Sensor2_ShortToGnd;                      /* 1 bit, 0 means safe, 1 means errors */
    bool Accel_Sensor2_ShortToVcc;                      /* 1 bit, 0 means safe, 1 means errors */
    bool Accel_Sensor2_OutOfRangeOutput;                /* 1 bit, 0 means safe, 1 means errors */
    bool Accel_Implausibility;                          /* 1 bit, 0 means safe, 1 means errors */
    bool Brake_Sensor1_ShortToGnd;                      /* 1 bit, 0 means safe, 1 means errors */
    bool Brake_Sensor1_ShortToVcc;                      /* 1 bit, 0 means safe, 1 means errors */
    bool Brake_Sensor1_OutOfRangeOutput;                /* 1 bit, 0 means safe, 1 means errors */
    bool Brake_Sensor2_ShortToGnd;                      /* 1 bit, 0 means safe, 1 means errors */
    bool Brake_Sensor2_ShortToVcc;                      /* 1 bit, 0 means safe, 1 means errors */
    bool Brake_Sensor2_OutOfRangeOutput;                /* 1 bit, 0 means safe, 1 means errors */
    bool Brake_Implausibility;                          /* 1 bit, 0 means safe, 1 means errors */
}PedalsErrors_t;

typedef struct{
	uint16_t start_valid;
	uint16_t end_valid;
}SensorLimits;

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

void Pedals_Init(void);
void Pedals_Test(void);
boolean Pedals_GetError(Pedal_t PedalSelect, Sensor_t SensorSelect, PedalError_t DesiredValueType);
uint32_t Pedals_GetData(Pedal_t PedalSelect, Sensor_t SensorSelect, PedalValue_t DesiredValueType);
uint32_t Pedals_GetPressure(BrakePressure_t ValueType);
void Pedals_Update(void);

#ifdef __cplusplus
}
#endif

#endif

/** @} */
