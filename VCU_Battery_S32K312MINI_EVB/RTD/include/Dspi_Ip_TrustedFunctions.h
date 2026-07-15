/*==================================================================================================
*   Project              : RTD AUTOSAR 4.9
*   Platform             : CORTEXM
*   Peripheral           : LPSPI
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

#ifndef DSPI_IP_TRUSTEDFUNCTIONS_H
#define DSPI_IP_TRUSTEDFUNCTIONS_H

/**
*   @file    Dspi_Ip_TrustedFunctions.h
*
*
*   @brief   SPI IP driver header file.
*   @details SPI IP driver header file.

*   @addtogroup SPI_DRIVER Spi Driver
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
#include "Dspi_Ip_Cfg.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define DSPI_IP_TRUSTEDFUNCTIONS_VENDOR_ID                       43
#define DSPI_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION        4
#define DSPI_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION        9
#define DSPI_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION     0
#define DSPI_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION                7
#define DSPI_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION                0
#define DSPI_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION                1
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Dspi_Ip_TrustedFunctions.h header file and Dspi_Ip_Cfg.h configuration header file are of the same vendor */
#if (DSPI_IP_TRUSTEDFUNCTIONS_VENDOR_ID != DSPI_IP_VENDOR_ID_CFG)
    #error "Dspi_Ip_TrustedFunctions.h and Dspi_Ip_Cfg.h have different vendor IDs"
#endif
    /* Check if Dspi_Ip_TrustedFunctions.h header file and Dspi_Ip_Cfg.h  configuration header file are of the same Autosar version */
#if ((DSPI_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION != DSPI_IP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (DSPI_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION != DSPI_IP_AR_RELEASE_MINOR_VERSION_CFG) || \
     (DSPI_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION != DSPI_IP_AR_RELEASE_REVISION_VERSION_CFG))
#error "AutoSar Version Numbers of Dspi_Ip_TrustedFunctions.h and Dspi_Ip_Cfg.h are different"
#endif
/* Check if Dspi_Ip_TrustedFunctions.h header file and Dspi_Ip_Cfg.h configuration header file are of the same software version */
#if ((DSPI_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION != DSPI_IP_SW_MAJOR_VERSION_CFG) || \
     (DSPI_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION != DSPI_IP_SW_MINOR_VERSION_CFG) || \
     (DSPI_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION != DSPI_IP_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of Dspi_Ip_TrustedFunctions.h and Dspi_Ip_Cfg.h are different"
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/*==================================================================================================
*                                            ENUMS
==================================================================================================*/
/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#if (STD_ON == DSPI_IP_ENABLE)
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"


#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"

#endif /*(STD_ON == DSPI_IP_ENABLE)*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* DSPI_IP_TRUSTEDFUNCTIONS_H */
