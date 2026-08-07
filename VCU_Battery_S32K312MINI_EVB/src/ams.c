#include "Port.h"
#include "Dio.h"

void initAMS(void)
{
	Port_SetPinDirection(50,PORT_PIN_OUT);
	Dio_WriteChannel(53,false);
}

void switchAMSstate(bool state)
{
	Dio_WriteChannel(53, !state);
}
