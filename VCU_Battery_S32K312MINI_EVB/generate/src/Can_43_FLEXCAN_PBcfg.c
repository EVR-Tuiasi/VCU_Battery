/*==================================================================================================
*   Project              : RTD AUTOSAR 4.9
*   Platform             : CORTEXM
*   Peripheral           : FLEXCAN
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
*   @file    Can_43_FLEXCAN_PBcfg.c
*   @version 7.0.1
*
*   @brief   AUTOSAR Can_43_FLEXCAN - module interface
*   @details Configuration Structures for PostBuild
*
*   @addtogroup CAN_43_FLEXCAN_DRIVER
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2012 violations
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.1, External identifiers shall be distinct.
* The used compilers use more than 31 chars for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.2, Identifiers declared in the same scope and name space shall be distinct.
* The used compilers use more than 31 chars for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.4, Macro identifiers shall be distinct.
* The used compilers use more than 31 chars for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.5, Identifiers shall be distinct from macro names.
* The used compilers use more than 31 chars for identifiers.
*
* @section Can_43_FLEXCAN_PBcfg_BOARD_InitPeripherals_c_REF_1
* Violates MISRA 2012 Required Directive 4.10, Precautions shall be taken in order to prevent the contents
* of a header file being included more than once
* This violation is not fixed since the inclusion of <MA>_MemMap.h is as per AUTOSAR requirement [SWS_MemMap_00003].
*
* @section Can_43_FLEXCAN_PBcfg_BOARD_InitPeripherals_c_REF_2
* Violates MISRA 2012 Advisory Rule 20.1, #include directives should only be preceded by preprocessor directives or comments.
* AUTOSAR imposes the specification of the sections in which certain parts of the driver must be placed.
*
* @section Can_43_FLEXCAN_PBcfg_BOARD_InitPeripherals_c_REF_3
* Violates MISRA 2012 Advisory Rule 8.7, Function and objects should not be defined with external linkage if they
* are referenced in only one translation unit.
* This constant variable will be called by higher layer.
*
* @section Can_43_FLEXCAN_PBcfg_BOARD_InitPeripherals_c_REF_4
* Violates MISRA 2012 Advisory Rule 8.9, An object should be defined at block scope if identifier only appears in a single function.
* These objects are used when Precompile is supported.
*
* @section Can_43_FLEXCAN_PBcfg_BOARD_InitPeripherals_c_REF_5
* Violates MISRA 2012 Required Rule 8.4, A compatible declaration shall be visible when an object or function with external linkage is defined.
*
*/
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Can_43_FLEXCAN.h"
#include "Can_43_FLEXCAN_Ipw_Types.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CAN_43_FLEXCAN_VENDOR_ID_PBCFG_C                      43
#define CAN_43_FLEXCAN_AR_RELEASE_MAJOR_VERSION_PBCFG_C       4
#define CAN_43_FLEXCAN_AR_RELEASE_MINOR_VERSION_PBCFG_C       9
#define CAN_43_FLEXCAN_AR_RELEASE_REVISION_VERSION_PBCFG_C    0
#define CAN_43_FLEXCAN_SW_MAJOR_VERSION_PBCFG_C               7
#define CAN_43_FLEXCAN_SW_MINOR_VERSION_PBCFG_C               0
#define CAN_43_FLEXCAN_SW_PATCH_VERSION_PBCFG_C               1
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Can_43_FLEXCAN.h are of the same vendor */
#if (CAN_43_FLEXCAN_VENDOR_ID_PBCFG_C != CAN_43_FLEXCAN_VENDOR_ID)
    #error "Can_43_FLEXCAN_PBcfg.c and Can_43_FLEXCAN.h have different vendor ids"
#endif
/* Check if current file and Can_43_FLEXCAN.h are of the same Autosar version */
#if ((CAN_43_FLEXCAN_AR_RELEASE_MAJOR_VERSION_PBCFG_C != CAN_43_FLEXCAN_AR_RELEASE_MAJOR_VERSION) || \
     (CAN_43_FLEXCAN_AR_RELEASE_MINOR_VERSION_PBCFG_C != CAN_43_FLEXCAN_AR_RELEASE_MINOR_VERSION) || \
     (CAN_43_FLEXCAN_AR_RELEASE_REVISION_VERSION_PBCFG_C != CAN_43_FLEXCAN_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Can_43_FLEXCAN_PBcfg.c and Can_43_FLEXCAN.h are different"
#endif
/* Check if current file and Can_43_FLEXCAN.h are of the same Software version */
#if ((CAN_43_FLEXCAN_SW_MAJOR_VERSION_PBCFG_C != CAN_43_FLEXCAN_SW_MAJOR_VERSION) || \
     (CAN_43_FLEXCAN_SW_MINOR_VERSION_PBCFG_C != CAN_43_FLEXCAN_SW_MINOR_VERSION) || \
     (CAN_43_FLEXCAN_SW_PATCH_VERSION_PBCFG_C != CAN_43_FLEXCAN_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Can_43_FLEXCAN_PBcfg.c and Can_43_FLEXCAN.h are different"
#endif

/* Check if current file and Can_43_FLEXCAN_Ipw_Types.h are of the same vendor */
#if (CAN_43_FLEXCAN_VENDOR_ID_PBCFG_C != CAN_43_FLEXCAN_IPW_TYPES_VENDOR_ID_H)
    #error "Can_43_FLEXCAN_PBcfg.c and Can_43_FLEXCAN_Ipw_Types.h have different vendor ids"
#endif
/* Check if current file and Can_43_FLEXCAN_Ipw_Types.h are of the same Autosar version */
#if ((CAN_43_FLEXCAN_AR_RELEASE_MAJOR_VERSION_PBCFG_C != CAN_43_FLEXCAN_IPW_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (CAN_43_FLEXCAN_AR_RELEASE_MINOR_VERSION_PBCFG_C !=  CAN_43_FLEXCAN_IPW_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (CAN_43_FLEXCAN_AR_RELEASE_REVISION_VERSION_PBCFG_C != CAN_43_FLEXCAN_IPW_TYPES_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Can_43_FLEXCAN_PBcfg.c and Can_43_FLEXCAN_Ipw_Types.h are different"
#endif
/* Check if current file and Can_43_FLEXCAN_Ipw_Types.h are of the same software version */
#if ((CAN_43_FLEXCAN_SW_MAJOR_VERSION_PBCFG_C != CAN_43_FLEXCAN_IPW_TYPES_SW_MAJOR_VERSION_H) || \
     (CAN_43_FLEXCAN_SW_MINOR_VERSION_PBCFG_C != CAN_43_FLEXCAN_IPW_TYPES_SW_MINOR_VERSION_H) || \
     (CAN_43_FLEXCAN_SW_PATCH_VERSION_PBCFG_C != CAN_43_FLEXCAN_IPW_TYPES_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Can_43_FLEXCAN_PBcfg.c and Can_43_FLEXCAN_Ipw_Types.h are different"
#endif
/*==================================================================================================
*                                   GLOBAL VARIABLES
==================================================================================================*/
#if (CAN_43_FLEXCAN_FEATURE_HAS_DMA_ENABLE == STD_ON)
    /* CAN_43_FLEXCAN_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE */
    #define CAN_43_FLEXCAN_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
    #include "Can_43_FLEXCAN_MemMap.h"


    #define CAN_43_FLEXCAN_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
    #include "Can_43_FLEXCAN_MemMap.h"
    /* CAN_43_FLEXCAN_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE */
#endif /* (CAN_43_FLEXCAN_FEATURE_HAS_DMA_ENABLE == STD_ON) */
/*==================================================================================================
*                                   GLOBAL FUNCTION PROTOTYPES
==================================================================================================*/
#define CAN_43_FLEXCAN_START_SEC_CODE
/* @violates @ref Can_43_FLEXCAN_PBcfg_BOARD_InitPeripherals_c_REF_1 MISRA 2012 Required Directive 4.10 */
#include "Can_43_FLEXCAN_MemMap.h"
#define CAN_43_FLEXCAN_STOP_SEC_CODE
/* @violates @ref Can_43_FLEXCAN_PBcfg_BOARD_InitPeripherals_c_REF_1 MISRA 2012 Required Directive 4.10 */
/* @violates @ref Can_43_FLEXCAN_PBcfg_BOARD_InitPeripherals_c_REF_2 MISRA 2012 Advisory Rule 20.1 */
#include "Can_43_FLEXCAN_MemMap.h"
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/
#define CAN_43_FLEXCAN_START_SEC_CONFIG_DATA_32
#include "Can_43_FLEXCAN_MemMap.h"

/**
*   @brief  Hardware Buffer Address of CanController_0
*/
static const uint32 Can_au32HwBufferAddr_Ctrl0[26U]=
{
    (FLEXCAN_0_BASE + (uint32)0x0080U),
    (FLEXCAN_0_BASE + (uint32)0x0090U),
    (FLEXCAN_0_BASE + (uint32)0x00a0U),
    (FLEXCAN_0_BASE + (uint32)0x00b0U),
    (FLEXCAN_0_BASE + (uint32)0x00c0U),
    (FLEXCAN_0_BASE + (uint32)0x00d0U),
    (FLEXCAN_0_BASE + (uint32)0x00e0U),
    (FLEXCAN_0_BASE + (uint32)0x00f0U),
    (FLEXCAN_0_BASE + (uint32)0x0100U),
    (FLEXCAN_0_BASE + (uint32)0x0110U),
    (FLEXCAN_0_BASE + (uint32)0x0120U),
    (FLEXCAN_0_BASE + (uint32)0x0130U),
    (FLEXCAN_0_BASE + (uint32)0x0140U),
    (FLEXCAN_0_BASE + (uint32)0x0150U),
    (FLEXCAN_0_BASE + (uint32)0x0160U),
    (FLEXCAN_0_BASE + (uint32)0x0170U),
    (FLEXCAN_0_BASE + (uint32)0x0180U),
    (FLEXCAN_0_BASE + (uint32)0x0190U),
    (FLEXCAN_0_BASE + (uint32)0x01a0U),
    (FLEXCAN_0_BASE + (uint32)0x01b0U),
    (FLEXCAN_0_BASE + (uint32)0x01c0U),
    (FLEXCAN_0_BASE + (uint32)0x01d0U),
    (FLEXCAN_0_BASE + (uint32)0x01e0U),
    (FLEXCAN_0_BASE + (uint32)0x01f0U),
    (FLEXCAN_0_BASE + (uint32)0x0200U),
    (FLEXCAN_0_BASE + (uint32)0x0210U)
};

/**
*   @brief  Hardware Filter of INVERTOR_STANGA_RECEIVE
*/
static const Can_43_FLEXCAN_HwFilterType Can_aHwFilter_Object0[1U]=
{
    /* ID Filter Element_0 of Rx MB with EXTENDED Id */
    {
        (uint32)0x00000110U,
        (uint32)0xdfffffffU
    }
};
/**
*   @brief  Hardware Filter of INVERTOR_DREAPTA_RECEIVE
*/
static const Can_43_FLEXCAN_HwFilterType Can_aHwFilter_Object1[1U]=
{
    /* ID Filter Element_0 of Rx MB with EXTENDED Id */
    {
        (uint32)0x00000111U,
        (uint32)0xdfffffffU
    }
};
/**
*   @brief  Hardware Filter of INVERTOARE_RECEIVE
*/
static const Can_43_FLEXCAN_HwFilterType Can_aHwFilter_Object2[1U]=
{
    /* ID Filter Element_0 of Rx MB with EXTENDED Id */
    {
        (uint32)0x00000112U,
        (uint32)0xdfffffffU
    }
};
/**
*   @brief  Hardware Filter of BORD_RECEIVE
*/
static const Can_43_FLEXCAN_HwFilterType Can_aHwFilter_Object3[1U]=
{
    /* ID Filter Element_0 of Rx MB with EXTENDED Id */
    {
        (uint32)0x00000113U,
        (uint32)0xdfffffffU
    }
};
/**
*   @brief  Hardware Filter of ACCELERATIE_RECEIVE
*/
static const Can_43_FLEXCAN_HwFilterType Can_aHwFilter_Object4[1U]=
{
    /* ID Filter Element_0 of Rx MB with EXTENDED Id */
    {
        (uint32)0x00000330U,
        (uint32)0xdfffffffU
    }
};
/**
*   @brief  Hardware Filter of FRANA_RECEIVE
*/
static const Can_43_FLEXCAN_HwFilterType Can_aHwFilter_Object5[1U]=
{
    /* ID Filter Element_0 of Rx MB with EXTENDED Id */
    {
        (uint32)0x00000331U,
        (uint32)0xdfffffffU
    }
};
/**
*   @brief  Hardware Filter of BATERIE_RECEIVE
*/
static const Can_43_FLEXCAN_HwFilterType Can_aHwFilter_Object6[1U]=
{
    /* ID Filter Element_0 of Rx MB with EXTENDED Id */
    {
        (uint32)0x00000114U,
        (uint32)0xdfffffffU
    }
};
/**
*   @brief  Hardware Filter of BATERIE_TENSIUNI_CELULE_RECEIVE
*/
static const Can_43_FLEXCAN_HwFilterType Can_aHwFilter_Object7[1U]=
{
    /* ID Filter Element_0 of Rx MB with EXTENDED Id */
    {
        (uint32)0x00000115U,
        (uint32)0xdfffffffU
    }
};
/**
*   @brief  Hardware Filter of BATERIE_TEMPERATURI_CELULE_RECEIVE
*/
static const Can_43_FLEXCAN_HwFilterType Can_aHwFilter_Object8[1U]=
{
    /* ID Filter Element_0 of Rx MB with EXTENDED Id */
    {
        (uint32)0x00000116U,
        (uint32)0xdfffffffU
    }
};
/**
*   @brief  Hardware Filter of BATERIE_2_RECEIVE
*/
static const Can_43_FLEXCAN_HwFilterType Can_aHwFilter_Object9[1U]=
{
    /* ID Filter Element_0 of Rx MB with EXTENDED Id */
    {
        (uint32)0x00000117U,
        (uint32)0xdfffffffU
    }
};
/**
*   @brief  Hardware Filter of BATERIE_CHARGER_RECEIVE
*/
static const Can_43_FLEXCAN_HwFilterType Can_aHwFilter_Object10[1U]=
{
    /* ID Filter Element_0 of Rx MB with EXTENDED Id */
    {
        (uint32)0x00000119U,
        (uint32)0xdfffffffU
    }
};
/**
*   @brief  Hardware Filter of COMUNICATII_RECEIVE
*/
static const Can_43_FLEXCAN_HwFilterType Can_aHwFilter_Object11[1U]=
{
    /* ID Filter Element_0 of Rx MB with EXTENDED Id */
    {
        (uint32)0x00000118U,
        (uint32)0xdfffffffU
    }
};
/**
*   @brief  Hardware Filter of CHARGER_RECEIVE
*/
static const Can_43_FLEXCAN_HwFilterType Can_aHwFilter_Object12[1U]=
{
    /* ID Filter Element_0 of Rx MB with EXTENDED Id */
    {
        (uint32)0x18ff50e5U,
        (uint32)0xdfffffffU
    }
};

#define CAN_43_FLEXCAN_STOP_SEC_CONFIG_DATA_32
#include "Can_43_FLEXCAN_MemMap.h"

#define CAN_43_FLEXCAN_START_SEC_CONFIG_DATA_8
#include "Can_43_FLEXCAN_MemMap.h"

/**
*   @brief  Hardware Buffer Index of CanController_0
*/
static const uint8 Can_au8HwBufferIndex_Ctrl0[26U]=
{
    (uint8)0U,
    (uint8)1U,
    (uint8)2U,
    (uint8)3U,
    (uint8)4U,
    (uint8)5U,
    (uint8)6U,
    (uint8)7U,
    (uint8)8U,
    (uint8)9U,
    (uint8)10U,
    (uint8)11U,
    (uint8)12U,
    (uint8)13U,
    (uint8)14U,
    (uint8)15U,
    (uint8)16U,
    (uint8)17U,
    (uint8)18U,
    (uint8)19U,
    (uint8)20U,
    (uint8)21U,
    (uint8)22U,
    (uint8)23U,
    (uint8)24U,
    (uint8)25U
};

/**
*   @brief  Mapping Controller ID to Controller hardware offset
*/
static const uint8 Can_aCtrlOffsetToCtrlIDMap[CAN_43_FLEXCAN_HWCONTROLLER_SUPPORT]=
{
    (uint8)0U,
    (uint8)CAN_43_FLEXCAN_CONTROLLER_UNUSED,
    (uint8)CAN_43_FLEXCAN_CONTROLLER_UNUSED,
    (uint8)CAN_43_FLEXCAN_CONTROLLER_UNUSED,
    (uint8)CAN_43_FLEXCAN_CONTROLLER_UNUSED,
    (uint8)CAN_43_FLEXCAN_CONTROLLER_UNUSED
};
/**
*   @brief  Mapping Controller ID to Hardware Object ID
*/
static const uint8 Can_aHwObjIDToCtrlIDMap[CAN_43_FLEXCAN_HWOBJECT_CONFIG_COUNT]=
{
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U
};

#define CAN_43_FLEXCAN_STOP_SEC_CONFIG_DATA_8
#include "Can_43_FLEXCAN_MemMap.h"

#define CAN_43_FLEXCAN_START_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref Can_43_FLEXCAN_PBcfg_BOARD_InitPeripherals_c_REF_1 MISRA 2012 Required Directive 4.10 */
/* @violates @ref Can_43_FLEXCAN_PBcfg_BOARD_InitPeripherals_c_REF_2 MISRA 2012 Advisory Rule 20.1 */
#include "Can_43_FLEXCAN_MemMap.h"

/**
*   @brief  Can Hardware Object Config
*/
/* @violates @ref Can_43_FLEXCAN_PBcfg_BOARD_InitPeripherals_c_REF_5 MISRA 2012 Required Rule 8.4*/
static const Can_43_FLEXCAN_HwObjectConfigType Can_aHwObjectConfig[CAN_43_FLEXCAN_HWOBJECT_CONFIG_COUNT]=
{
    /* INVERTOR_STANGA_RECEIVE of CanController_0 */
    {
        /* Hardware Object ID */
        (Can_HwHandleType)0U,
        /* Hardware Object handle type */
        CAN_43_FLEXCAN_RECEIVE,
        /* ID Message type */
        CAN_43_FLEXCAN_EXTENDED,
        /* Object uses polling */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Number of Hw Object used in one Hoh */
        (uint8)1U,
        /* MainFunction RW period reference */
        (uint8)0xFFU,
        /* Data Payload length */
        (uint8)8U,
        /* Padding value */
        (uint8)0U,
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        Can_aHwFilter_Object0,
        /* Message Buffer is RX_NORMAL */
        CAN_43_FLEXCAN_RX_NORMAL,
        /* Buffer Index in Message buffer ram */
        &Can_au8HwBufferIndex_Ctrl0[0U],
        /* Message buffer address */
        &Can_au32HwBufferAddr_Ctrl0[0U]
    },
    /* INVERTOR_DREAPTA_RECEIVE of CanController_0 */
    {
        /* Hardware Object ID */
        (Can_HwHandleType)1U,
        /* Hardware Object handle type */
        CAN_43_FLEXCAN_RECEIVE,
        /* ID Message type */
        CAN_43_FLEXCAN_EXTENDED,
        /* Object uses polling */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Number of Hw Object used in one Hoh */
        (uint8)1U,
        /* MainFunction RW period reference */
        (uint8)0xFFU,
        /* Data Payload length */
        (uint8)8U,
        /* Padding value */
        (uint8)0U,
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        Can_aHwFilter_Object1,
        /* Message Buffer is RX_NORMAL */
        CAN_43_FLEXCAN_RX_NORMAL,
        /* Buffer Index in Message buffer ram */
        &Can_au8HwBufferIndex_Ctrl0[1U],
        /* Message buffer address */
        &Can_au32HwBufferAddr_Ctrl0[1U]
    },
    /* INVERTOARE_RECEIVE of CanController_0 */
    {
        /* Hardware Object ID */
        (Can_HwHandleType)2U,
        /* Hardware Object handle type */
        CAN_43_FLEXCAN_RECEIVE,
        /* ID Message type */
        CAN_43_FLEXCAN_EXTENDED,
        /* Object uses polling */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Number of Hw Object used in one Hoh */
        (uint8)1U,
        /* MainFunction RW period reference */
        (uint8)0xFFU,
        /* Data Payload length */
        (uint8)8U,
        /* Padding value */
        (uint8)0U,
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        Can_aHwFilter_Object2,
        /* Message Buffer is RX_NORMAL */
        CAN_43_FLEXCAN_RX_NORMAL,
        /* Buffer Index in Message buffer ram */
        &Can_au8HwBufferIndex_Ctrl0[2U],
        /* Message buffer address */
        &Can_au32HwBufferAddr_Ctrl0[2U]
    },
    /* BORD_RECEIVE of CanController_0 */
    {
        /* Hardware Object ID */
        (Can_HwHandleType)3U,
        /* Hardware Object handle type */
        CAN_43_FLEXCAN_RECEIVE,
        /* ID Message type */
        CAN_43_FLEXCAN_EXTENDED,
        /* Object uses polling */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Number of Hw Object used in one Hoh */
        (uint8)1U,
        /* MainFunction RW period reference */
        (uint8)0xFFU,
        /* Data Payload length */
        (uint8)8U,
        /* Padding value */
        (uint8)0U,
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        Can_aHwFilter_Object3,
        /* Message Buffer is RX_NORMAL */
        CAN_43_FLEXCAN_RX_NORMAL,
        /* Buffer Index in Message buffer ram */
        &Can_au8HwBufferIndex_Ctrl0[3U],
        /* Message buffer address */
        &Can_au32HwBufferAddr_Ctrl0[3U]
    },
    /* ACCELERATIE_RECEIVE of CanController_0 */
    {
        /* Hardware Object ID */
        (Can_HwHandleType)4U,
        /* Hardware Object handle type */
        CAN_43_FLEXCAN_RECEIVE,
        /* ID Message type */
        CAN_43_FLEXCAN_EXTENDED,
        /* Object uses polling */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Number of Hw Object used in one Hoh */
        (uint8)1U,
        /* MainFunction RW period reference */
        (uint8)0xFFU,
        /* Data Payload length */
        (uint8)8U,
        /* Padding value */
        (uint8)0U,
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        Can_aHwFilter_Object4,
        /* Message Buffer is RX_NORMAL */
        CAN_43_FLEXCAN_RX_NORMAL,
        /* Buffer Index in Message buffer ram */
        &Can_au8HwBufferIndex_Ctrl0[4U],
        /* Message buffer address */
        &Can_au32HwBufferAddr_Ctrl0[4U]
    },
    /* FRANA_RECEIVE of CanController_0 */
    {
        /* Hardware Object ID */
        (Can_HwHandleType)5U,
        /* Hardware Object handle type */
        CAN_43_FLEXCAN_RECEIVE,
        /* ID Message type */
        CAN_43_FLEXCAN_EXTENDED,
        /* Object uses polling */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Number of Hw Object used in one Hoh */
        (uint8)1U,
        /* MainFunction RW period reference */
        (uint8)0xFFU,
        /* Data Payload length */
        (uint8)8U,
        /* Padding value */
        (uint8)0U,
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        Can_aHwFilter_Object5,
        /* Message Buffer is RX_NORMAL */
        CAN_43_FLEXCAN_RX_NORMAL,
        /* Buffer Index in Message buffer ram */
        &Can_au8HwBufferIndex_Ctrl0[5U],
        /* Message buffer address */
        &Can_au32HwBufferAddr_Ctrl0[5U]
    },
    /* BATERIE_RECEIVE of CanController_0 */
    {
        /* Hardware Object ID */
        (Can_HwHandleType)6U,
        /* Hardware Object handle type */
        CAN_43_FLEXCAN_RECEIVE,
        /* ID Message type */
        CAN_43_FLEXCAN_EXTENDED,
        /* Object uses polling */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Number of Hw Object used in one Hoh */
        (uint8)1U,
        /* MainFunction RW period reference */
        (uint8)0xFFU,
        /* Data Payload length */
        (uint8)8U,
        /* Padding value */
        (uint8)0U,
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        Can_aHwFilter_Object6,
        /* Message Buffer is RX_NORMAL */
        CAN_43_FLEXCAN_RX_NORMAL,
        /* Buffer Index in Message buffer ram */
        &Can_au8HwBufferIndex_Ctrl0[6U],
        /* Message buffer address */
        &Can_au32HwBufferAddr_Ctrl0[6U]
    },
    /* BATERIE_TENSIUNI_CELULE_RECEIVE of CanController_0 */
    {
        /* Hardware Object ID */
        (Can_HwHandleType)7U,
        /* Hardware Object handle type */
        CAN_43_FLEXCAN_RECEIVE,
        /* ID Message type */
        CAN_43_FLEXCAN_EXTENDED,
        /* Object uses polling */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Number of Hw Object used in one Hoh */
        (uint8)1U,
        /* MainFunction RW period reference */
        (uint8)0xFFU,
        /* Data Payload length */
        (uint8)8U,
        /* Padding value */
        (uint8)0U,
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        Can_aHwFilter_Object7,
        /* Message Buffer is RX_NORMAL */
        CAN_43_FLEXCAN_RX_NORMAL,
        /* Buffer Index in Message buffer ram */
        &Can_au8HwBufferIndex_Ctrl0[7U],
        /* Message buffer address */
        &Can_au32HwBufferAddr_Ctrl0[7U]
    },
    /* BATERIE_TEMPERATURI_CELULE_RECEIVE of CanController_0 */
    {
        /* Hardware Object ID */
        (Can_HwHandleType)8U,
        /* Hardware Object handle type */
        CAN_43_FLEXCAN_RECEIVE,
        /* ID Message type */
        CAN_43_FLEXCAN_EXTENDED,
        /* Object uses polling */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Number of Hw Object used in one Hoh */
        (uint8)1U,
        /* MainFunction RW period reference */
        (uint8)0xFFU,
        /* Data Payload length */
        (uint8)8U,
        /* Padding value */
        (uint8)0U,
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        Can_aHwFilter_Object8,
        /* Message Buffer is RX_NORMAL */
        CAN_43_FLEXCAN_RX_NORMAL,
        /* Buffer Index in Message buffer ram */
        &Can_au8HwBufferIndex_Ctrl0[8U],
        /* Message buffer address */
        &Can_au32HwBufferAddr_Ctrl0[8U]
    },
    /* BATERIE_2_RECEIVE of CanController_0 */
    {
        /* Hardware Object ID */
        (Can_HwHandleType)9U,
        /* Hardware Object handle type */
        CAN_43_FLEXCAN_RECEIVE,
        /* ID Message type */
        CAN_43_FLEXCAN_EXTENDED,
        /* Object uses polling */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Number of Hw Object used in one Hoh */
        (uint8)1U,
        /* MainFunction RW period reference */
        (uint8)0xFFU,
        /* Data Payload length */
        (uint8)8U,
        /* Padding value */
        (uint8)0U,
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        Can_aHwFilter_Object9,
        /* Message Buffer is RX_NORMAL */
        CAN_43_FLEXCAN_RX_NORMAL,
        /* Buffer Index in Message buffer ram */
        &Can_au8HwBufferIndex_Ctrl0[9U],
        /* Message buffer address */
        &Can_au32HwBufferAddr_Ctrl0[9U]
    },
    /* BATERIE_CHARGER_RECEIVE of CanController_0 */
    {
        /* Hardware Object ID */
        (Can_HwHandleType)10U,
        /* Hardware Object handle type */
        CAN_43_FLEXCAN_RECEIVE,
        /* ID Message type */
        CAN_43_FLEXCAN_EXTENDED,
        /* Object uses polling */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Number of Hw Object used in one Hoh */
        (uint8)1U,
        /* MainFunction RW period reference */
        (uint8)0xFFU,
        /* Data Payload length */
        (uint8)8U,
        /* Padding value */
        (uint8)0U,
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        Can_aHwFilter_Object10,
        /* Message Buffer is RX_NORMAL */
        CAN_43_FLEXCAN_RX_NORMAL,
        /* Buffer Index in Message buffer ram */
        &Can_au8HwBufferIndex_Ctrl0[10U],
        /* Message buffer address */
        &Can_au32HwBufferAddr_Ctrl0[10U]
    },
    /* COMUNICATII_RECEIVE of CanController_0 */
    {
        /* Hardware Object ID */
        (Can_HwHandleType)11U,
        /* Hardware Object handle type */
        CAN_43_FLEXCAN_RECEIVE,
        /* ID Message type */
        CAN_43_FLEXCAN_EXTENDED,
        /* Object uses polling */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Number of Hw Object used in one Hoh */
        (uint8)1U,
        /* MainFunction RW period reference */
        (uint8)0xFFU,
        /* Data Payload length */
        (uint8)8U,
        /* Padding value */
        (uint8)0U,
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        Can_aHwFilter_Object11,
        /* Message Buffer is RX_NORMAL */
        CAN_43_FLEXCAN_RX_NORMAL,
        /* Buffer Index in Message buffer ram */
        &Can_au8HwBufferIndex_Ctrl0[11U],
        /* Message buffer address */
        &Can_au32HwBufferAddr_Ctrl0[11U]
    },
    /* CHARGER_RECEIVE of CanController_0 */
    {
        /* Hardware Object ID */
        (Can_HwHandleType)12U,
        /* Hardware Object handle type */
        CAN_43_FLEXCAN_RECEIVE,
        /* ID Message type */
        CAN_43_FLEXCAN_EXTENDED,
        /* Object uses polling */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Number of Hw Object used in one Hoh */
        (uint8)1U,
        /* MainFunction RW period reference */
        (uint8)0xFFU,
        /* Data Payload length */
        (uint8)8U,
        /* Padding value */
        (uint8)0U,
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        Can_aHwFilter_Object12,
        /* Message Buffer is RX_NORMAL */
        CAN_43_FLEXCAN_RX_NORMAL,
        /* Buffer Index in Message buffer ram */
        &Can_au8HwBufferIndex_Ctrl0[12U],
        /* Message buffer address */
        &Can_au32HwBufferAddr_Ctrl0[12U]
    },
    /* INVERTOR_STANGA_TRANSMIT of CanController_0 */
    {
        /* Hardware Object ID */
        (Can_HwHandleType)13U,
        /* Hardware Object handle type */
        CAN_43_FLEXCAN_TRANSMIT,
        /* ID Message type */
        CAN_43_FLEXCAN_EXTENDED,
        /* Object uses polling */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Number of Hw Object used in one Hoh */
        (uint8)1U,
        /* MainFunction RW period reference */
        (uint8)0xFFU,
        /* Data Payload length */
        (uint8)8U,
        /* Padding value */
        (uint8)0U,
        /* Hardware Filter Count */
        (uint8)0U,
        /* Hw Filter Config */
        NULL_PTR,
        /* Message Buffer is TX_NORMAL */
        CAN_43_FLEXCAN_TX_NORMAL,
        /* Buffer Index in Message buffer ram */
        &Can_au8HwBufferIndex_Ctrl0[13U],
        /* Message buffer address */
        &Can_au32HwBufferAddr_Ctrl0[13U]
    },
    /* INVERTOR_DREAPTA_TRANSMIT of CanController_0 */
    {
        /* Hardware Object ID */
        (Can_HwHandleType)14U,
        /* Hardware Object handle type */
        CAN_43_FLEXCAN_TRANSMIT,
        /* ID Message type */
        CAN_43_FLEXCAN_EXTENDED,
        /* Object uses polling */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Number of Hw Object used in one Hoh */
        (uint8)1U,
        /* MainFunction RW period reference */
        (uint8)0xFFU,
        /* Data Payload length */
        (uint8)8U,
        /* Padding value */
        (uint8)0U,
        /* Hardware Filter Count */
        (uint8)0U,
        /* Hw Filter Config */
        NULL_PTR,
        /* Message Buffer is TX_NORMAL */
        CAN_43_FLEXCAN_TX_NORMAL,
        /* Buffer Index in Message buffer ram */
        &Can_au8HwBufferIndex_Ctrl0[14U],
        /* Message buffer address */
        &Can_au32HwBufferAddr_Ctrl0[14U]
    },
    /* INVERTOARE_TRANSMIT of CanController_0 */
    {
        /* Hardware Object ID */
        (Can_HwHandleType)15U,
        /* Hardware Object handle type */
        CAN_43_FLEXCAN_TRANSMIT,
        /* ID Message type */
        CAN_43_FLEXCAN_EXTENDED,
        /* Object uses polling */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Number of Hw Object used in one Hoh */
        (uint8)1U,
        /* MainFunction RW period reference */
        (uint8)0xFFU,
        /* Data Payload length */
        (uint8)8U,
        /* Padding value */
        (uint8)0U,
        /* Hardware Filter Count */
        (uint8)0U,
        /* Hw Filter Config */
        NULL_PTR,
        /* Message Buffer is TX_NORMAL */
        CAN_43_FLEXCAN_TX_NORMAL,
        /* Buffer Index in Message buffer ram */
        &Can_au8HwBufferIndex_Ctrl0[15U],
        /* Message buffer address */
        &Can_au32HwBufferAddr_Ctrl0[15U]
    },
    /* BORD_TRANSMIT of CanController_0 */
    {
        /* Hardware Object ID */
        (Can_HwHandleType)16U,
        /* Hardware Object handle type */
        CAN_43_FLEXCAN_TRANSMIT,
        /* ID Message type */
        CAN_43_FLEXCAN_EXTENDED,
        /* Object uses polling */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Number of Hw Object used in one Hoh */
        (uint8)1U,
        /* MainFunction RW period reference */
        (uint8)0xFFU,
        /* Data Payload length */
        (uint8)8U,
        /* Padding value */
        (uint8)0U,
        /* Hardware Filter Count */
        (uint8)0U,
        /* Hw Filter Config */
        NULL_PTR,
        /* Message Buffer is TX_NORMAL */
        CAN_43_FLEXCAN_TX_NORMAL,
        /* Buffer Index in Message buffer ram */
        &Can_au8HwBufferIndex_Ctrl0[16U],
        /* Message buffer address */
        &Can_au32HwBufferAddr_Ctrl0[16U]
    },
    /* ACCELERATIE_TRANSMIT of CanController_0 */
    {
        /* Hardware Object ID */
        (Can_HwHandleType)17U,
        /* Hardware Object handle type */
        CAN_43_FLEXCAN_TRANSMIT,
        /* ID Message type */
        CAN_43_FLEXCAN_EXTENDED,
        /* Object uses polling */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Number of Hw Object used in one Hoh */
        (uint8)1U,
        /* MainFunction RW period reference */
        (uint8)0xFFU,
        /* Data Payload length */
        (uint8)8U,
        /* Padding value */
        (uint8)0U,
        /* Hardware Filter Count */
        (uint8)0U,
        /* Hw Filter Config */
        NULL_PTR,
        /* Message Buffer is TX_NORMAL */
        CAN_43_FLEXCAN_TX_NORMAL,
        /* Buffer Index in Message buffer ram */
        &Can_au8HwBufferIndex_Ctrl0[17U],
        /* Message buffer address */
        &Can_au32HwBufferAddr_Ctrl0[17U]
    },
    /* FRANA_TRANSMIT of CanController_0 */
    {
        /* Hardware Object ID */
        (Can_HwHandleType)18U,
        /* Hardware Object handle type */
        CAN_43_FLEXCAN_TRANSMIT,
        /* ID Message type */
        CAN_43_FLEXCAN_EXTENDED,
        /* Object uses polling */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Number of Hw Object used in one Hoh */
        (uint8)1U,
        /* MainFunction RW period reference */
        (uint8)0xFFU,
        /* Data Payload length */
        (uint8)8U,
        /* Padding value */
        (uint8)0U,
        /* Hardware Filter Count */
        (uint8)0U,
        /* Hw Filter Config */
        NULL_PTR,
        /* Message Buffer is TX_NORMAL */
        CAN_43_FLEXCAN_TX_NORMAL,
        /* Buffer Index in Message buffer ram */
        &Can_au8HwBufferIndex_Ctrl0[18U],
        /* Message buffer address */
        &Can_au32HwBufferAddr_Ctrl0[18U]
    },
    /* BATERIE_TRANSMIT of CanController_0 */
    {
        /* Hardware Object ID */
        (Can_HwHandleType)19U,
        /* Hardware Object handle type */
        CAN_43_FLEXCAN_TRANSMIT,
        /* ID Message type */
        CAN_43_FLEXCAN_EXTENDED,
        /* Object uses polling */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Number of Hw Object used in one Hoh */
        (uint8)1U,
        /* MainFunction RW period reference */
        (uint8)0xFFU,
        /* Data Payload length */
        (uint8)8U,
        /* Padding value */
        (uint8)0U,
        /* Hardware Filter Count */
        (uint8)0U,
        /* Hw Filter Config */
        NULL_PTR,
        /* Message Buffer is TX_NORMAL */
        CAN_43_FLEXCAN_TX_NORMAL,
        /* Buffer Index in Message buffer ram */
        &Can_au8HwBufferIndex_Ctrl0[19U],
        /* Message buffer address */
        &Can_au32HwBufferAddr_Ctrl0[19U]
    },
    /* BATERIE_TENSIUNI_CELULE_TRANSMIT of CanController_0 */
    {
        /* Hardware Object ID */
        (Can_HwHandleType)20U,
        /* Hardware Object handle type */
        CAN_43_FLEXCAN_TRANSMIT,
        /* ID Message type */
        CAN_43_FLEXCAN_EXTENDED,
        /* Object uses polling */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Number of Hw Object used in one Hoh */
        (uint8)1U,
        /* MainFunction RW period reference */
        (uint8)0xFFU,
        /* Data Payload length */
        (uint8)8U,
        /* Padding value */
        (uint8)0U,
        /* Hardware Filter Count */
        (uint8)0U,
        /* Hw Filter Config */
        NULL_PTR,
        /* Message Buffer is TX_NORMAL */
        CAN_43_FLEXCAN_TX_NORMAL,
        /* Buffer Index in Message buffer ram */
        &Can_au8HwBufferIndex_Ctrl0[20U],
        /* Message buffer address */
        &Can_au32HwBufferAddr_Ctrl0[20U]
    },
    /* BATERIE_TEMPERATURI_CELULE_TRANSMIT of CanController_0 */
    {
        /* Hardware Object ID */
        (Can_HwHandleType)21U,
        /* Hardware Object handle type */
        CAN_43_FLEXCAN_TRANSMIT,
        /* ID Message type */
        CAN_43_FLEXCAN_EXTENDED,
        /* Object uses polling */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Number of Hw Object used in one Hoh */
        (uint8)1U,
        /* MainFunction RW period reference */
        (uint8)0xFFU,
        /* Data Payload length */
        (uint8)8U,
        /* Padding value */
        (uint8)0U,
        /* Hardware Filter Count */
        (uint8)0U,
        /* Hw Filter Config */
        NULL_PTR,
        /* Message Buffer is TX_NORMAL */
        CAN_43_FLEXCAN_TX_NORMAL,
        /* Buffer Index in Message buffer ram */
        &Can_au8HwBufferIndex_Ctrl0[21U],
        /* Message buffer address */
        &Can_au32HwBufferAddr_Ctrl0[21U]
    },
    /* BATERIE_2_TRANSMIT of CanController_0 */
    {
        /* Hardware Object ID */
        (Can_HwHandleType)22U,
        /* Hardware Object handle type */
        CAN_43_FLEXCAN_TRANSMIT,
        /* ID Message type */
        CAN_43_FLEXCAN_EXTENDED,
        /* Object uses polling */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Number of Hw Object used in one Hoh */
        (uint8)1U,
        /* MainFunction RW period reference */
        (uint8)0xFFU,
        /* Data Payload length */
        (uint8)8U,
        /* Padding value */
        (uint8)0U,
        /* Hardware Filter Count */
        (uint8)0U,
        /* Hw Filter Config */
        NULL_PTR,
        /* Message Buffer is TX_NORMAL */
        CAN_43_FLEXCAN_TX_NORMAL,
        /* Buffer Index in Message buffer ram */
        &Can_au8HwBufferIndex_Ctrl0[22U],
        /* Message buffer address */
        &Can_au32HwBufferAddr_Ctrl0[22U]
    },
    /* BATERIE_CHARGER_TRANSMIT of CanController_0 */
    {
        /* Hardware Object ID */
        (Can_HwHandleType)23U,
        /* Hardware Object handle type */
        CAN_43_FLEXCAN_TRANSMIT,
        /* ID Message type */
        CAN_43_FLEXCAN_EXTENDED,
        /* Object uses polling */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Number of Hw Object used in one Hoh */
        (uint8)1U,
        /* MainFunction RW period reference */
        (uint8)0xFFU,
        /* Data Payload length */
        (uint8)8U,
        /* Padding value */
        (uint8)0U,
        /* Hardware Filter Count */
        (uint8)0U,
        /* Hw Filter Config */
        NULL_PTR,
        /* Message Buffer is TX_NORMAL */
        CAN_43_FLEXCAN_TX_NORMAL,
        /* Buffer Index in Message buffer ram */
        &Can_au8HwBufferIndex_Ctrl0[23U],
        /* Message buffer address */
        &Can_au32HwBufferAddr_Ctrl0[23U]
    },
    /* COMUNICATII_TRANSMIT of CanController_0 */
    {
        /* Hardware Object ID */
        (Can_HwHandleType)24U,
        /* Hardware Object handle type */
        CAN_43_FLEXCAN_TRANSMIT,
        /* ID Message type */
        CAN_43_FLEXCAN_EXTENDED,
        /* Object uses polling */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Number of Hw Object used in one Hoh */
        (uint8)1U,
        /* MainFunction RW period reference */
        (uint8)0xFFU,
        /* Data Payload length */
        (uint8)8U,
        /* Padding value */
        (uint8)0U,
        /* Hardware Filter Count */
        (uint8)0U,
        /* Hw Filter Config */
        NULL_PTR,
        /* Message Buffer is TX_NORMAL */
        CAN_43_FLEXCAN_TX_NORMAL,
        /* Buffer Index in Message buffer ram */
        &Can_au8HwBufferIndex_Ctrl0[24U],
        /* Message buffer address */
        &Can_au32HwBufferAddr_Ctrl0[24U]
    },
    /* CHARGER_TRANSMIT of CanController_0 */
    {
        /* Hardware Object ID */
        (Can_HwHandleType)25U,
        /* Hardware Object handle type */
        CAN_43_FLEXCAN_TRANSMIT,
        /* ID Message type */
        CAN_43_FLEXCAN_EXTENDED,
        /* Object uses polling */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Number of Hw Object used in one Hoh */
        (uint8)1U,
        /* MainFunction RW period reference */
        (uint8)0xFFU,
        /* Data Payload length */
        (uint8)8U,
        /* Padding value */
        (uint8)0U,
        /* Hardware Filter Count */
        (uint8)0U,
        /* Hw Filter Config */
        NULL_PTR,
        /* Message Buffer is TX_NORMAL */
        CAN_43_FLEXCAN_TX_NORMAL,
        /* Buffer Index in Message buffer ram */
        &Can_au8HwBufferIndex_Ctrl0[25U],
        /* Message buffer address */
        &Can_au32HwBufferAddr_Ctrl0[25U]
    }
};


/**
*   @brief  Can Baudrate Config of CanController_0
*/
static const Can_43_FLEXCAN_BaudrateConfigType Can_aBaudrateConfig_Ctrl0[1U]=
{
    { /* Start BaudConfig Struct 0 */
        /*Can_bEnhanceCBTEnable*/
        (boolean)FALSE,
            /* Tx Bit Rate Switch - Can_bBitRateSwitch */
        (boolean)FALSE,
        /* FD Enable - Can_bFDFrame*/
        (boolean)FALSE,
        /*Nominal Bit Rate - Can_TimeSegmentType Can_NominalBitRate*/
        {
            (uint8)2U,
            (uint8)5U,
            (uint8)5U,
            /* BaudratePrescaler -Can_u16Prescaler  */
            (uint16)11U,
        #if (CAN_43_FLEXCAN_DUAL_CLOCK_MODE == STD_ON)
            /* Alternative Baudrate Prescaler  Can_u16PrescalerAlternate*/
            (uint16)9U,
        #endif
            (uint8)3U
        },
        /* Data bit rate - Can_TimeSegmentType Can_DataBitRate */
        {
            (uint8)0U,
            (uint8)0U,
            (uint8)0U,
            (uint16)0U,
            #if (CAN_43_FLEXCAN_DUAL_CLOCK_MODE == STD_ON)
            (uint16)0U,
            #endif
            (uint8)0U
        },
        /* Tx Arbitration Start delay - Can_u8TxArbitrationStartDelay */
        (uint8)12U,
        /*Transmiter Delay Compensation Enable */
        (boolean)FALSE,
        /*Specifies the Transmiter Delay Compensation Offset - Can_u8TrcvDelayCompOffset */
        (uint8)0U
    } /* End BaudConfig Struct 0 */
};
/**
*   @brief  HwObjects pointer structure of CanController_0
*/
static const Can_43_FLEXCAN_HwObjectConfigType * const Can_apHwObject_Ctrl0[26U]=
{
    &Can_aHwObjectConfig[0U],
    &Can_aHwObjectConfig[1U],
    &Can_aHwObjectConfig[2U],
    &Can_aHwObjectConfig[3U],
    &Can_aHwObjectConfig[4U],
    &Can_aHwObjectConfig[5U],
    &Can_aHwObjectConfig[6U],
    &Can_aHwObjectConfig[7U],
    &Can_aHwObjectConfig[8U],
    &Can_aHwObjectConfig[9U],
    &Can_aHwObjectConfig[10U],
    &Can_aHwObjectConfig[11U],
    &Can_aHwObjectConfig[12U],
    &Can_aHwObjectConfig[13U],
    &Can_aHwObjectConfig[14U],
    &Can_aHwObjectConfig[15U],
    &Can_aHwObjectConfig[16U],
    &Can_aHwObjectConfig[17U],
    &Can_aHwObjectConfig[18U],
    &Can_aHwObjectConfig[19U],
    &Can_aHwObjectConfig[20U],
    &Can_aHwObjectConfig[21U],
    &Can_aHwObjectConfig[22U],
    &Can_aHwObjectConfig[23U],
    &Can_aHwObjectConfig[24U],
    &Can_aHwObjectConfig[25U]
};

CAN_43_FLEXCAN_IPW_EXT
/**
*   @brief  Can Controller Config
*/
static const Can_43_FLEXCAN_ControllerConfigType Can_aControllerConfig[CAN_43_FLEXCAN_CONTROLLER_CONFIG_COUNT]=
{
    {   /* Start Generation of ControllerConfig_0 structure */
        /* Abstracted CanIf Controller ID */
        (uint8)0U,
        /* Controller ID */
        (uint8)0U,
        /* Controller Offset */
        (uint8)0U,
        /* Controller Base Address */
        FLEXCAN_0_BASE,
        /* Controller Activation */
        (boolean)TRUE,
        /* Bus Off uses polling */
        (boolean)FALSE,
        /* Wakeup uses Polling */
        (boolean)FALSE,
        /* --- Default values when Legacy FIFO is not available --- */
        /* Global mask of Legacy FIFO */
        (uint32)0xFFFFFFFFU,
        /* ID Acceptance Mode */
        CAN_43_FLEXCAN_LEGACY_FIFO_FORMAT_A,
        /* Legacy FIFO Warning Notification */
        NULL_PTR,
        /* Legacy FIFO Overflow Notification */
        NULL_PTR,
        /* Enhanced FIFO Overflow Notification */
        NULL_PTR,
        #if (CAN_43_FLEXCAN_FEATURE_HAS_DMA_ENABLE == STD_ON)
        /* FIFO Dma Error Notification is not used */
        NULL_PTR,
        /* DMA is not enabled */
        NULL_PTR,
        #endif /* (CAN_43_FLEXCAN_FEATURE_HAS_DMA_ENABLE == STD_ON) */
        /* Default Baudrate ID */
        (uint16)0U,
        /* Baudrate config Count*/
        (uint16)1U,
        /* Baudrate config Pointer Structure */
        Can_aBaudrateConfig_Ctrl0,
        /* Pointer to IPW structure to IP config */
        &Can_43_FLEXCANIpwHwChannelConfig0,
        /* Hw Object reference count */
        (uint8)26U,
        /* Pointer point to Group of Hw Object that refer to Controller */
        Can_apHwObject_Ctrl0
        #if (CAN_43_FLEXCAN_TIMESTAMP_ENABLE == STD_ON)
        ,(boolean)FALSE
        #endif
    }
};  /* End of generation Can_ControllerConfigType */


/**
*   @brief  Can Controller Object pointer structure
*/
static const Can_43_FLEXCAN_ControllerConfigType * const Can_apController[CAN_43_FLEXCAN_CONTROLLER_CONFIG_COUNT]=
{
    &Can_aControllerConfig[0U]
};
/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/
/**
*   @brief  Top level structure contain all Can driver Config
*/
const Can_43_FLEXCAN_ConfigType Can_43_FLEXCAN_Config =
{
    /* Configuration Partition ID */
    (uint32)0U,
    /* The HTH first Index after HRH consecutive */
    (Can_HwHandleType)13U,
    /* Mapping Controller ID to Controller Hw Offset */
    Can_aCtrlOffsetToCtrlIDMap,
    /* Mapping Controller ID to Hardware Object ID */
    Can_aHwObjIDToCtrlIDMap,
    /* Pointer point to Can Hw Object Config */
    Can_aHwObjectConfig,
    /* Array of Pointer to Controller infomation have aligned by Controller ID */
    Can_apController
};

#define CAN_43_FLEXCAN_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref Can_43_FLEXCAN_PBcfg_BOARD_InitPeripherals_c_REF_1 MISRA 2012 Required Directive 4.10 */
/* @violates @ref Can_43_FLEXCAN_PBcfg_BOARD_InitPeripherals_c_REF_2 MISRA 2012 Advisory Rule 20.1 */
#include "Can_43_FLEXCAN_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

