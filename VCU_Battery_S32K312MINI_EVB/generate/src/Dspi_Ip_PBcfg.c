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

/**
*   @file    Dspi_Ip_PBcfg.c
*   @version 7.0.1
*
*   @brief   AUTOSAR Spi - Post-Build(PB) configuration file code template.
*   @details Code template for Post-Build(PB) configuration file generation.
*
*   @addtogroup DSPI_IP_DRIVER_CONFIGURATION Dspi Ip Driver Configuration
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Dspi_Ip.h"
#if (DSPI_IP_DMA_USED == STD_ON)
#include "Dma_Ip_Cfg.h"
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define DSPI_IP_VENDOR_ID_PBCFG_C                        43
#define DSPI_IP_AR_RELEASE_MAJOR_VERSION_PBCFG_C         4
#define DSPI_IP_AR_RELEASE_MINOR_VERSION_PBCFG_C         9
#define DSPI_IP_AR_RELEASE_REVISION_VERSION_PBCFG_C      0
#define DSPI_IP_SW_MAJOR_VERSION_PBCFG_C                 7
#define DSPI_IP_SW_MINOR_VERSION_PBCFG_C                 0
#define DSPI_IP_SW_PATCH_VERSION_PBCFG_C                 1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Dspi_Ip.h and Dspi_Ip_PBcfg.c are of the same vendor */
#if (DSPI_IP_VENDOR_ID != DSPI_IP_VENDOR_ID_PBCFG_C)
    #error "Dspi_Ip.h and Dspi_Ip_PBcfg.c have different vendor ids"
#endif
/* Check if Dspi_Ip.h file and Dspi_Ip_PBcfg.c file are of the same Autosar version */
#if ((DSPI_IP_AR_RELEASE_MAJOR_VERSION != DSPI_IP_AR_RELEASE_MAJOR_VERSION_PBCFG_C) || \
     (DSPI_IP_AR_RELEASE_MINOR_VERSION != DSPI_IP_AR_RELEASE_MINOR_VERSION_PBCFG_C) || \
     (DSPI_IP_AR_RELEASE_REVISION_VERSION != DSPI_IP_AR_RELEASE_REVISION_VERSION_PBCFG_C))
#error "AutoSar Version Numbers of Dspi_Ip.h and Dspi_Ip_PBcfg.c are different"
#endif
#if ((DSPI_IP_SW_MAJOR_VERSION != DSPI_IP_SW_MAJOR_VERSION_PBCFG_C) || \
     (DSPI_IP_SW_MINOR_VERSION != DSPI_IP_SW_MINOR_VERSION_PBCFG_C) || \
     (DSPI_IP_SW_PATCH_VERSION != DSPI_IP_SW_PATCH_VERSION_PBCFG_C))
#error "Software Version Numbers of Dspi_Ip.h and Dspi_Ip_PBcfg.c are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if (DSPI_IP_DMA_USED == STD_ON)
        /* Check if current file and Dma_Ip header file are of the same Autosar version */
        #if ((DMA_IP_CFG_AR_RELEASE_MAJOR_VERSION != DSPI_IP_AR_RELEASE_MAJOR_VERSION_PBCFG_C) || \
             (DMA_IP_CFG_AR_RELEASE_MINOR_VERSION != DSPI_IP_AR_RELEASE_MINOR_VERSION_PBCFG_C))
        #error "AutoSar Version Numbers of Dspi_Ip_PBcfg.c and Dma_Ip_Cfg.h are different"
        #endif
    #endif
#endif
/*==================================================================================================
*                                        LOCAL MACROS
==================================================================================================*/
/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                   EXTERN FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/
/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

