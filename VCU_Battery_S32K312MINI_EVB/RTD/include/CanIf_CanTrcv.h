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
/*==================================================================================================
==================================================================================================*/
#ifndef CANIF_CANTRCV_H
#define CANIF_CANTRCV_H

/**
*   @file    CanIf_CanTrcv.h
*   @version 7.0.1
*
*   @brief   AUTOSAR CanIf - CanIf CanTrcv module interface
*   @details AUTOSAR CanIf CanTrcv module interface.- Stub Version
*   This file contains sample code only. It is not part of the production code deliverables.
*
*   @addtogroup CANIF_MODULE
*   @{
*/

#ifdef  __cplusplus
extern "C"
{
#endif
#include "CanIf_Types.h"
/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CANIF_CANTRCV_VENDOR_ID                         43
#define CANIF_CANTRCV_MODULE_ID                         60
#define CANIF_CANTRCV_AR_RELEASE_MAJOR_VERSION          4
#define CANIF_CANTRCV_AR_RELEASE_MINOR_VERSION          9
#define CANIF_CANTRCV_AR_RELEASE_REVISION_VERSION       0
#define CANIF_CANTRCV_SW_MAJOR_VERSION                  7
#define CANIF_CANTRCV_SW_MINOR_VERSION                  0
#define CANIF_CANTRCV_SW_PATCH_VERSION                  1
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CanIf_Types.h header file are of the same vendor */
#if (CANIF_CANTRCV_VENDOR_ID != CANIF_TYPES_VENDOR_ID)
#error "CanIf_CanTrcv.h and CanIf_Types.h have different vendor ids"
#endif
/* Check if current file and CanIf_Types.h header file are of the same Autosar version */
#if ((CANIF_CANTRCV_AR_RELEASE_MAJOR_VERSION != CANIF_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (CANIF_CANTRCV_AR_RELEASE_MINOR_VERSION != CANIF_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (CANIF_CANTRCV_AR_RELEASE_REVISION_VERSION != CANIF_TYPES_AR_RELEASE_REVISION_VERSION))
  #error "AutoSar Version Numbers of CanIf_CanTrcv.h and CanIf_Types.h are different"
#endif
/* Check if current file and CanIf_Types.h header file are of the same software version */
#if ((CANIF_CANTRCV_SW_MAJOR_VERSION != CANIF_TYPES_SW_MAJOR_VERSION) || \
     (CANIF_CANTRCV_SW_MINOR_VERSION != CANIF_TYPES_SW_MINOR_VERSION) || \
     (CANIF_CANTRCV_SW_PATCH_VERSION != CANIF_TYPES_SW_PATCH_VERSION))
  #error "Software Version Numbers of CanIf_CanTrcv.h and CanIf_Types.h are different"
#endif
/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"

void CanIf_TrcvModeIndication(uint8 Transceiver, CanTrcv_TrcvModeType TransceiverMode);
void CanIf_CheckTrcvWakeFlagIndication(uint8 TransceiverId);
void CanIf_ConfirmPnAvailability(uint8 TransceiverId);
void CanIf_ClearTrcvWufFlagIndication(uint8 TransceiverId);

#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif    /* CANIF_CANTRCV_H */

