/*==================================================================================================
*   Project              : RTD AUTOSAR 4.9
*   Platform             : CORTEXM
*   Peripheral           : generic
*   Dependencies         : 
*
*   Autosar Version      : 4.9.0
*   Autosar Revision     : ASR_REL_4_9_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 7.0.1
*   Build Version        : S32K3_RTD_7_0_1_D2602_ASR_REL_4_9_REV_0000_20260206
*
*   Copyright 2020 - 2026 NXP
*
*   NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be 
*   used strictly in accordance with the applicable license terms. By expressly 
*   accepting such terms or by downloading, installing, activating and/or otherwise 
*   using the software, you are agreeing that you have read, and that you agree to 
*   comply with and are bound by, such license terms. If you do not agree to be 
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/
/**
*   @file    CanIf_PBcfg.c
*   @version 7.0.1
*
*   @brief   AUTOSAR CanIf - module interface
*   @details Configuration Structures for PostBuild
*
*   @addtogroup CANIF_DRIVER
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "CanIf.h"
#include "CanMessaging.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CANIF_VENDOR_ID_PBCFG_C                      43
#define CANIF_AR_RELEASE_MAJOR_VERSION_PBCFG_C       4
#define CANIF_AR_RELEASE_MINOR_VERSION_PBCFG_C       9
#define CANIF_AR_RELEASE_REVISION_VERSION_PBCFG_C    0
#define CANIF_SW_MAJOR_VERSION_PBCFG_C               7
#define CANIF_SW_MINOR_VERSION_PBCFG_C               0
#define CANIF_SW_PATCH_VERSION_PBCFG_C               1
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   GLOBAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

/* Here is the TxPdu configuration */
static const CanIf_TxPduType CanIf_TxPdu[12U] =
{
    {
        /* .PduIdType */
        (uint8)0U,
        /* .CanId */
        (Can_IdType)272U,
        /* .CanFrameType */
        CANIF_EXTENDED_CAN,
        /* .Can_HwHandleType */
        (Can_HwHandleType)12U,
        /* .CanIfCtrlId */
        (uint8)0U,
        /* .UserTxConfirmation */
        NULL_PTR
    },
    {
        /* .PduIdType */
        (uint8)1U,
        /* .CanId */
        (Can_IdType)273U,
        /* .CanFrameType */
        CANIF_EXTENDED_CAN,
        /* .Can_HwHandleType */
        (Can_HwHandleType)13U,
        /* .CanIfCtrlId */
        (uint8)0U,
        /* .UserTxConfirmation */
        NULL_PTR
    },
    {
        /* .PduIdType */
        (uint8)2U,
        /* .CanId */
        (Can_IdType)274U,
        /* .CanFrameType */
        CANIF_EXTENDED_CAN,
        /* .Can_HwHandleType */
        (Can_HwHandleType)14U,
        /* .CanIfCtrlId */
        (uint8)0U,
        /* .UserTxConfirmation */
        NULL_PTR
    },
    {
        /* .PduIdType */
        (uint8)3U,
        /* .CanId */
        (Can_IdType)275U,
        /* .CanFrameType */
        CANIF_EXTENDED_CAN,
        /* .Can_HwHandleType */
        (Can_HwHandleType)15U,
        /* .CanIfCtrlId */
        (uint8)0U,
        /* .UserTxConfirmation */
        NULL_PTR
    },
    {
        /* .PduIdType */
        (uint8)4U,
        /* .CanId */
        (Can_IdType)816U,
        /* .CanFrameType */
        CANIF_EXTENDED_CAN,
        /* .Can_HwHandleType */
        (Can_HwHandleType)16U,
        /* .CanIfCtrlId */
        (uint8)0U,
        /* .UserTxConfirmation */
        NULL_PTR
    },
    {
        /* .PduIdType */
        (uint8)5U,
        /* .CanId */
        (Can_IdType)817U,
        /* .CanFrameType */
        CANIF_EXTENDED_CAN,
        /* .Can_HwHandleType */
        (Can_HwHandleType)17U,
        /* .CanIfCtrlId */
        (uint8)0U,
        /* .UserTxConfirmation */
        NULL_PTR
    },
    {
        /* .PduIdType */
        (uint8)6U,
        /* .CanId */
        (Can_IdType)276U,
        /* .CanFrameType */
        CANIF_EXTENDED_CAN,
        /* .Can_HwHandleType */
        (Can_HwHandleType)18U,
        /* .CanIfCtrlId */
        (uint8)0U,
        /* .UserTxConfirmation */
        NULL_PTR
    },
    {
        /* .PduIdType */
        (uint8)7U,
        /* .CanId */
        (Can_IdType)277U,
        /* .CanFrameType */
        CANIF_EXTENDED_CAN,
        /* .Can_HwHandleType */
        (Can_HwHandleType)19U,
        /* .CanIfCtrlId */
        (uint8)0U,
        /* .UserTxConfirmation */
        NULL_PTR
    },
    {
        /* .PduIdType */
        (uint8)8U,
        /* .CanId */
        (Can_IdType)278U,
        /* .CanFrameType */
        CANIF_EXTENDED_CAN,
        /* .Can_HwHandleType */
        (Can_HwHandleType)20U,
        /* .CanIfCtrlId */
        (uint8)0U,
        /* .UserTxConfirmation */
        NULL_PTR
    },
    {
        /* .PduIdType */
        (uint8)9U,
        /* .CanId */
        (Can_IdType)279U,
        /* .CanFrameType */
        CANIF_EXTENDED_CAN,
        /* .Can_HwHandleType */
        (Can_HwHandleType)21U,
        /* .CanIfCtrlId */
        (uint8)0U,
        /* .UserTxConfirmation */
        NULL_PTR
    },
    {
        /* .PduIdType */
        (uint8)10U,
        /* .CanId */
        (Can_IdType)281U,
        /* .CanFrameType */
        CANIF_EXTENDED_CAN,
        /* .Can_HwHandleType */
        (Can_HwHandleType)22U,
        /* .CanIfCtrlId */
        (uint8)0U,
        /* .UserTxConfirmation */
        NULL_PTR
    },
    {
        /* .PduIdType */
        (uint8)11U,
        /* .CanId */
        (Can_IdType)280U,
        /* .CanFrameType */
        CANIF_EXTENDED_CAN,
        /* .Can_HwHandleType */
        (Can_HwHandleType)23U,
        /* .CanIfCtrlId */
        (uint8)0U,
        /* .UserTxConfirmation */
        NULL_PTR
    }
};

/* Here is the RxPdu configuration */
static const CanIf_RxPduType CanIf_RxPdu[12U] =
{
    {
        /* .PduId */
        (uint8)0U,
        /* .PduLengthCheck */
        (boolean)FALSE,
        /* .PduLength */
        (uint16)8U,
        /* .CanIfCtrlId */
        (uint8)0U,
        /* .UserRxIndication */
        Can_Receive_Interrupt_INVERTOR_STANGA
    },
    {
        /* .PduId */
        (uint8)1U,
        /* .PduLengthCheck */
        (boolean)FALSE,
        /* .PduLength */
        (uint16)8U,
        /* .CanIfCtrlId */
        (uint8)0U,
        /* .UserRxIndication */
        Can_Receive_Interrupt_INVERTOR_DREAPTA
    },
    {
        /* .PduId */
        (uint8)2U,
        /* .PduLengthCheck */
        (boolean)FALSE,
        /* .PduLength */
        (uint16)8U,
        /* .CanIfCtrlId */
        (uint8)0U,
        /* .UserRxIndication */
        Can_Receive_Interrupt_INVERTOARE
    },
    {
        /* .PduId */
        (uint8)3U,
        /* .PduLengthCheck */
        (boolean)FALSE,
        /* .PduLength */
        (uint16)8U,
        /* .CanIfCtrlId */
        (uint8)0U,
        /* .UserRxIndication */
        Can_Receive_Interrupt_BORD
    },
    {
        /* .PduId */
        (uint8)4U,
        /* .PduLengthCheck */
        (boolean)FALSE,
        /* .PduLength */
        (uint16)8U,
        /* .CanIfCtrlId */
        (uint8)0U,
        /* .UserRxIndication */
        Can_Receive_Interrupt_ACCELERATIE
    },
    {
        /* .PduId */
        (uint8)5U,
        /* .PduLengthCheck */
        (boolean)FALSE,
        /* .PduLength */
        (uint16)8U,
        /* .CanIfCtrlId */
        (uint8)0U,
        /* .UserRxIndication */
        Can_Receive_Interrupt_FRANA
    },
    {
        /* .PduId */
        (uint8)6U,
        /* .PduLengthCheck */
        (boolean)FALSE,
        /* .PduLength */
        (uint16)8U,
        /* .CanIfCtrlId */
        (uint8)0U,
        /* .UserRxIndication */
        Can_Receive_Interrupt_BATERIE
    },
    {
        /* .PduId */
        (uint8)7U,
        /* .PduLengthCheck */
        (boolean)FALSE,
        /* .PduLength */
        (uint16)8U,
        /* .CanIfCtrlId */
        (uint8)0U,
        /* .UserRxIndication */
        Can_Receive_Interrupt_BATERIE_TENSIUNI_CELULE
    },
    {
        /* .PduId */
        (uint8)8U,
        /* .PduLengthCheck */
        (boolean)FALSE,
        /* .PduLength */
        (uint16)8U,
        /* .CanIfCtrlId */
        (uint8)0U,
        /* .UserRxIndication */
        Can_Receive_Interrupt_BATERIE_TEMPERATURI_CELULE
    },
    {
        /* .PduId */
        (uint8)9U,
        /* .PduLengthCheck */
        (boolean)FALSE,
        /* .PduLength */
        (uint16)8U,
        /* .CanIfCtrlId */
        (uint8)0U,
        /* .UserRxIndication */
        Can_Receive_Interrupt_BATERIE_2
    },
    {
        /* .PduId */
        (uint8)10U,
        /* .PduLengthCheck */
        (boolean)FALSE,
        /* .PduLength */
        (uint16)8U,
        /* .CanIfCtrlId */
        (uint8)0U,
        /* .UserRxIndication */
        Can_Receive_Interrupt_BATERIE_CHARGER
    },
    {
        /* .PduId */
        (uint8)11U,
        /* .PduLengthCheck */
        (boolean)FALSE,
        /* .PduLength */
        (uint16)8U,
        /* .CanIfCtrlId */
        (uint8)0U,
        /* .UserRxIndication */
        Can_Receive_Interrupt_COMUNICATII
    }
};

/* Here is the configuration related to Can_43_FLEXCAN Driver */
static const CanIf_RxPduType * const CanIf_Can_43_FLEXCAN_HohToRxPduMapping[24U] = 
{
    &CanIf_RxPdu[0U],
    &CanIf_RxPdu[1U],
    &CanIf_RxPdu[2U],
    &CanIf_RxPdu[3U],
    &CanIf_RxPdu[4U],
    &CanIf_RxPdu[5U],
    &CanIf_RxPdu[6U],
    &CanIf_RxPdu[7U],
    &CanIf_RxPdu[8U],
    &CanIf_RxPdu[9U],
    &CanIf_RxPdu[10U],
    &CanIf_RxPdu[11U],
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR
};
static const CanIf_CanDrvConfigType CanIf_Can_43_FLEXCAN_DrvConfig = 
{
    /* .HohToRxPduMappingPtr */
    CanIf_Can_43_FLEXCAN_HohToRxPduMapping
};

static const CanIf_CanDrvConfigType * const CanIf_CanDrvConfig[1U] =
{
    &CanIf_Can_43_FLEXCAN_DrvConfig
};

const CanIf_ConfigType CanIf_Config =
{
    /* .NumRxPdu */
    (uint8)12U,
    /* .NumTxPdu */
    (uint8)12U,
    CanIf_CanDrvConfig,
    /* .CanIf_RxPduConfigPtr */
    CanIf_RxPdu,
    /* .CanIf_TxPduConfigPtr */
    CanIf_TxPdu
};

#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

