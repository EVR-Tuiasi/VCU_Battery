/*==================================================================================================
*   Project              : RTD AUTOSAR 4.9
*   Platform             : CORTEXM
*   Peripheral           : ADC_SAR
*   Dependencies         : none
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

#ifndef ADC_IPW_CFGDEFINES_H
#define ADC_IPW_CFGDEFINES_H

/**
*   @file
*
*   @addtogroup adc_ipw_config Adc Ipw Configuration
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
#include "Std_Types.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define ADC_IPW_VENDOR_ID_CFGDEFINES                     43
#define ADC_IPW_AR_RELEASE_MAJOR_VERSION_CFGDEFINES      4
#define ADC_IPW_AR_RELEASE_MINOR_VERSION_CFGDEFINES      9
#define ADC_IPW_AR_RELEASE_REVISION_VERSION_CFGDEFINES   0
#define ADC_IPW_SW_MAJOR_VERSION_CFGDEFINES              7
#define ADC_IPW_SW_MINOR_VERSION_CFGDEFINES              0
#define ADC_IPW_SW_PATCH_VERSION_CFGDEFINES              1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Adc_Ipw_CfgDefines.h file and Std_Types.h file are of the same Autosar version */
#if ((ADC_IPW_AR_RELEASE_MAJOR_VERSION_CFGDEFINES != STD_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_IPW_AR_RELEASE_MINOR_VERSION_CFGDEFINES != STD_AR_RELEASE_MINOR_VERSION)    \
    )
    #error "AutoSar Version Numbers of Adc_Ipw_CfgDefines.h and Std_Types.h are different"
#endif
#endif

/*==================================================================================================
*                              DEFINES AND MACROS
==================================================================================================*/

#define ADC_IPW_INVALID_LOGICAL_UNIT_ID     (0xFFU)

#define ADC_IPW_INVALID_PHYSICAL_UNIT_ID    (0xFFU)

#define ADC_IPW_INVALID_DMA_CHANNEL_ID      (0xFFU)

#define ADC_IPW_INVALID_TRANSFER_TYPE       (0xFFU)

#ifdef ADC_DMA_SUPPORTED
#if defined(ADC_DMA_ERROR_SUPPORTED)
#define ADC_IPW_TIMEOUT_TYPE                (OSIF_COUNTER_DUMMY)

#define ADC_IPW_TIMEOUT_VAL                 (100000UL)
#endif /* ADC_DMA_ERROR_SUPPORTED */
#endif /* ADC_DMA_SUPPORTED */

#define ADC_IPW_NUM_OF_GROUP_CHN                (3U)

/**
 * @brief          Max number of ADC SAR Hw units.
 */
#define ADC_IPW_MAX_HW_UNITS                    (2U)

/**
 * @brief   Define the number of maximum ADC hardware unit configured
 */
#define ADC_IPW_MAX_HW_UNITS_CFG                (2U)

/**
 * @brief          Max number of CTU Hw units.
 */
#define ADC_IPW_CTU_MAX_HW_UNITS                (1U)

/**
 * @brief   Define the number of maximum CTU hardware unit configured
 */
#define ADC_IPW_CTU_MAX_HW_UNITS_CFG            (0U)

#define ADC_IPW_CTU_UNIT_0                      (0U)

#define ADC_IPW_CTU_LOGICAL_ID_SHIFT            (28UL)
#define ADC_IPW_CTU_LOGICAL_ID_MASK             (((1UL << ADC_IPW_CTU_MAX_HW_UNITS) - 1UL) << ADC_IPW_CTU_LOGICAL_ID_SHIFT)
#define ADC_IPW_CTU_NOTIF_CTU_LOGICAL_0         ((0U) << ADC_IPW_CTU_LOGICAL_ID_SHIFT)

/**
* @brief           Bctu trigger mode is supported.
*/
#define ADC_IPW_CTU_TRIGGER_MODE_SUPPORTED      (STD_ON)

/**
* @brief           BCTU available/unavailable (STD_ON/STD_OFF).
*/
#define ADC_IPW_BCTU_AVAILABLE                  (STD_ON)

/**
* @brief           CTU available/unavailable (STD_ON/STD_OFF).
*/
#define ADC_IPW_CTU_AVAILABLE                   (STD_OFF)

/**
* @brief           Maximum CTU event configuration.
*/
#define ADC_IPW_MAX_CTU_TRIG_SOURCE_ID      (47U)
#define ADC_IPW_EXTERNAL_TRIGGER_ENABLE            (0U)

#define ADC_IPW_AUX_EXT_TRIGGER_AVAILABLE          (1U)

#if ((ADC_IPW_AUX_EXT_TRIGGER_AVAILABLE == 1U) && (ADC_IPW_EXTERNAL_TRIGGER_ENABLE == 1U))
#define ADC_IPW_EXT_TRG_SRC                     (48U) /* Normal and injected external trigger */
#define ADC_IPW_AUX_EXT_TRG_SRC                 (49U) /* Auxiliary normal external trigger */
#endif /* ((ADC_IPW_AUX_EXT_TRIGGER_AVAILABLE == 1U) && ... */

/**
* @brief           Definitions used for extracting the CTU Logical Unit Id in symbolic name having uint16 type
*/
#define ADC_IPW_CTU_LOGICAL_ID_MASK_U16          (0xFF00U)
#define ADC_IPW_CTU_LOGICAL_ID_SHIFT_U16         (8U)

/**
* @brief           Maximum CTU channel ID
*/
#define ADC_IPW_CTU_MAX_ADC_CHANNEL_ID           (127U)

/**
* @brief           CTUs FIFOs Depths
*/
#define ADC_IPW_CTU_FIFO_DEPTH                   {{16U, 8U}}
/**
* @brief           ADC hardware is supported CALSTAT register
*/
#define ADC_IPW_CALSTAT_AVAILABLE                (STD_OFF)

/**
* @brief          Mapping between ADC Physical Id and CTU Physical Id.
*/
#define ADC_IPW_ADC_TO_CTU_MAPPING_ARRAY         { 0U, 0U }



/**
* @brief          Offset for ADC index and BCTU register bitfield when using BCTU
*/
#define ADC_IPW_ADC_INDEX_OFFSET_BITFIELD_ARRAY       {0U}

/**
* @brief           SDADC is used (STD_ON/STD_OFF).
*/
#define ADC_IPW_SDADC_IS_USED                       (STD_OFF)

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* ADC_IPW_CFGDEFINES_H */
