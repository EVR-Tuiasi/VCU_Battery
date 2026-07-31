#include "Can_GeneralTypes.h"
#include "Can_43_FLEXCAN.h"
#include "CanIf.h"
#include "SchM_Can_43_FLEXCAN.h"
#include "Platform.h"
#include "charger.h"

/*==================================================================================================
 *                                      GLOBAL VARIABLES
 *==================================================================================================*/

/**
* @brief          Data buffer for charger CAN message.
* @details        Structure of the message:
*                 - Byte 0-1: Voltage (uint16, big-endian)
*                 - Byte 2-3: Current (uint16, big-endian)
*                 - Byte 4:   Control (start/stop charger)
*                 - Byte 5-7: Reserved
*
* @note           Initial values:
*                 - Voltage = 100.0V
*                 - Current = 5A
*/
uint8 dataCharger[8] =
{
    0x03, 0xE8,  /* 100.0 V */
    0x00, 0x32,  /* 5 A */
    0x00,        /* start charger */
    0x00, 0x00, 0x00 /* reserved */
};

/*==================================================================================================
 *                                       GLOBAL FUNCTIONS
 *==================================================================================================*/

/**
* @brief          Sets charger voltage and current parameters.
* @details        Encodes voltage and current into CAN message buffer (big-endian format).
*
* @param[in]      voltage: Desired charger voltage (uint16_t).
* @param[in]      current: Desired charger current (uint16_t).
*
* @return         void
*
* @pre            dataCharger buffer must be initialized.
* @post           dataCharger buffer is updated with new parameters.
*/
void setParametriiCharger(uint16_t voltage, uint16_t current)
{
    dataCharger[0] = voltage / 256;
    dataCharger[1] = voltage % 256;

    dataCharger[2] = current / 256;
    dataCharger[3] = current % 256;
}

/**
* @brief          Sends charger command over CAN bus.
* @details        Prepares a CAN PDU and transmits it using FLEXCAN driver.
*                 A simple delay loop is used after transmission.
*
* @return         void
*
* @pre            CAN module must be initialized and configured.
* @post           Charger command is sent on CAN bus.
*
* @note           Uses extended CAN ID defined by CAN_CHARGER_ID.
*/
void transmiteCharger(void)
{
    Can_PduType pduCharger;
    volatile int delayLocal = DELAY_MESAJ_INCARCARE;

    pduCharger.swPduHandle = 0;          /* Software handle */
    pduCharger.length = 8;               /* Data length */
    pduCharger.sdu = dataCharger;        /* Data pointer */
    pduCharger.id = CAN_CHARGER_ID;      /* CAN ID */

    Can_43_FLEXCAN_Write(CAN_HTH_HANDLE_C, &pduCharger);

    while (delayLocal--)
    {
        /* simple delay */
    }
}
