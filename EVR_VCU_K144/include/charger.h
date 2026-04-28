#pragma once

#define CAN_HTH_HANDLE_C 		  0x01
#define CAN_CHARGER_ID        0x9806E5F4U
#define DELAY_MESAJ_INCARCARE 1000000


void setParametriiCharger(uint16_t voltage,uint16_t current);
void transmiteCharger(void);
