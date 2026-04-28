#include "Can_GeneralTypes.h"
#include "Can_43_FLEXCAN.h"
#include "CanIf.h"
#include "SchM_Can_43_FLEXCAN.h"
#include "Platform.h"
#include "charger.h"

uint8 dataCharger[8]={0x03,0xE8, //100,0 V trimit catre 0x1806E7F4
		0,0x32, //5A
		0, //porneste charger
		0,0,0 //reserved
};


void setParametriiCharger(uint16_t voltage,uint16_t current)
{
	dataCharger[0]=voltage/256;
	dataCharger[1]=voltage%256;
	dataCharger[2]=current/256;
	dataCharger[3]=current%256;
}


void transmiteCharger(void)
{
	Can_PduType pduCharger;
	int delayLocal=DELAY_MESAJ_INCARCARE;

	pduCharger.swPduHandle = 0;                    // Handle-ul software pentru PDU
	pduCharger.length = 8;                         // Lungimea datelor: 8 bytes
	pduCharger.sdu = dataCharger;                      // Pointer catre datele mesajului
	pduCharger.id = CAN_CHARGER_ID;                 // ID-ul mesajului CAN (extended)
	Can_43_FLEXCAN_Write(CAN_HTH_HANDLE_C, &pduCharger);
	while(delayLocal--);


}
