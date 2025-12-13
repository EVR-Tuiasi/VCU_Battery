/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : ADC
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 2.0.0
*   Build Version        : S32K1_RTD_2_0_0_D2308_ASR_REL_4_7_REV_0000_20230804
*
*   Copyright 2020-2023 NXP Semiconductors
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

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

#include "Adc_Ipw_CfgDefines.h"
#include "Adc_Ipw_VS_0_PBcfg.h"
#include "Adc_Ip_VS_0_PBcfg.h"
#include "Pdb_Adc_Ip_VS_0_PBcfg.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define ADC_IPW_VENDOR_ID_VS_0_PBCFG_C                      43
#define ADC_IPW_AR_RELEASE_MAJOR_VERSION_VS_0_PBCFG_C       4
#define ADC_IPW_AR_RELEASE_MINOR_VERSION_VS_0_PBCFG_C       7
#define ADC_IPW_AR_RELEASE_REVISION_VERSION_VS_0_PBCFG_C    0
#define ADC_IPW_SW_MAJOR_VERSION_VS_0_PBCFG_C               2
#define ADC_IPW_SW_MINOR_VERSION_VS_0_PBCFG_C               0
#define ADC_IPW_SW_PATCH_VERSION_VS_0_PBCFG_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if Adc_Ipw__VS_0_PBcfg.c file and Adc_Ipw_CfgDefines.h file are of the same vendor */
#if (ADC_IPW_VENDOR_ID_VS_0_PBCFG_C != ADC_IPW_VENDOR_ID_CFGDEFINES)
    #error "Adc_Ipw_VS_0_PBcfg.c and Adc_Ipw_CfgDefines.h have different vendor ids"
#endif

/* Check if Adc_Ipw_VS_0_PBcfg.c file and Adc_Ipw_CfgDefines.h file are of the same Autosar version */
#if ((ADC_IPW_AR_RELEASE_MAJOR_VERSION_VS_0_PBCFG_C != ADC_IPW_AR_RELEASE_MAJOR_VERSION_CFGDEFINES) || \
     (ADC_IPW_AR_RELEASE_MINOR_VERSION_VS_0_PBCFG_C != ADC_IPW_AR_RELEASE_MINOR_VERSION_CFGDEFINES) || \
     (ADC_IPW_AR_RELEASE_REVISION_VERSION_VS_0_PBCFG_C != ADC_IPW_AR_RELEASE_REVISION_VERSION_CFGDEFINES) \
    )
    #error "AutoSar Version Numbers of Adc_Ipw__VS_0_PBcfg.c and Adc_Ipw_CfgDefines.h are different"
#endif

/* Check if Adc_Ipw_VS_0_PBcfg.c file and Adc_Ipw_CfgDefines.h file are of the same Software version */
#if ((ADC_IPW_SW_MAJOR_VERSION_VS_0_PBCFG_C != ADC_IPW_SW_MAJOR_VERSION_CFGDEFINES) || \
     (ADC_IPW_SW_MINOR_VERSION_VS_0_PBCFG_C != ADC_IPW_SW_MINOR_VERSION_CFGDEFINES) || \
     (ADC_IPW_SW_PATCH_VERSION_VS_0_PBCFG_C != ADC_IPW_SW_PATCH_VERSION_CFGDEFINES) \
    )
  #error "Software Version Numbers of Adc_Ipw_VS_0_PBcfg.c and Adc_Ipw_CfgDefines.h are different"
#endif

/* Check if Adc_Ipw_VS_0_PBcfg.c file and Adc_Ipw_VS_0_PBcfg.h file are of the same vendor */
#if (ADC_IPW_VENDOR_ID_VS_0_PBCFG_C != ADC_IPW_VENDOR_ID_VS_0_PBCFG)
    #error "Adc_Ipw_VS_0_PBcfg.c and Adc_Ipw_VS_0_PBcfg.h have different vendor ids"
#endif

/* Check if Adc_Ipw_VS_0_PBcfg.c file and Adc_Ipw_VS_0_PBcfg.h file are of the same Autosar version */
#if ((ADC_IPW_AR_RELEASE_MAJOR_VERSION_VS_0_PBCFG_C != ADC_IPW_AR_RELEASE_MAJOR_VERSION_VS_0_PBCFG) || \
     (ADC_IPW_AR_RELEASE_MINOR_VERSION_VS_0_PBCFG_C != ADC_IPW_AR_RELEASE_MINOR_VERSION_VS_0_PBCFG) || \
     (ADC_IPW_AR_RELEASE_REVISION_VERSION_VS_0_PBCFG_C != ADC_IPW_AR_RELEASE_REVISION_VERSION_VS_0_PBCFG) \
    )
    #error "AutoSar Version Numbers of Adc_Ipw_VS_0_PBcfg.c and Adc_Ipw_VS_0_PBcfg.h are different"
#endif

/* Check if Adc_Ipw__VS_0_PBcfg.c file and Adc_Ipw__VS_0_PBcfg.h file are of the same Software version */
#if ((ADC_IPW_SW_MAJOR_VERSION_VS_0_PBCFG_C != ADC_IPW_SW_MAJOR_VERSION_VS_0_PBCFG) || \
     (ADC_IPW_SW_MINOR_VERSION_VS_0_PBCFG_C != ADC_IPW_SW_MINOR_VERSION_VS_0_PBCFG) || \
     (ADC_IPW_SW_PATCH_VERSION_VS_0_PBCFG_C != ADC_IPW_SW_PATCH_VERSION_VS_0_PBCFG) \
    )
  #error "Software Version Numbers of Adc_Ipw_VS_0_PBcfg.c and Adc_Ipw_VS_0_PBcfg.h are different"
#endif

/* Check if Adc_Ipw_VS_0_PBcfg.c file and Adc_Ip_VS_0_PBcfg.h file are of the same vendor */
#if (ADC_IPW_VENDOR_ID_VS_0_PBCFG_C != ADC_IP_VENDOR_ID_VS_0_PBCFG)
    #error "Adc_Ipw_VS_0_PBcfg.c and Adc_Ip_VS_0_PBcfg.h have different vendor ids"
#endif

/* Check if Adc_Ipw_VS_0_PBcfg.c file and Adc_Ip_VS_0_PBcfg.h file are of the same Autosar version */
#if ((ADC_IPW_AR_RELEASE_MAJOR_VERSION_VS_0_PBCFG_C != ADC_IP_AR_RELEASE_MAJOR_VERSION_VS_0_PBCFG) || \
     (ADC_IPW_AR_RELEASE_MINOR_VERSION_VS_0_PBCFG_C != ADC_IP_AR_RELEASE_MINOR_VERSION_VS_0_PBCFG) || \
     (ADC_IPW_AR_RELEASE_REVISION_VERSION_VS_0_PBCFG_C != ADC_IP_AR_RELEASE_REVISION_VERSION_VS_0_PBCFG) \
    )
    #error "AutoSar Version Numbers of Adc_Ipw_VS_0_PBcfg.c and Adc_Ip_VS_0_PBcfg.h are different"
#endif

/* Check if Adc_Ipw_VS_0_PBcfg.c file and Adc_Ip_VS_0_PBcfg.h file are of the same Software version */
#if ((ADC_IPW_SW_MAJOR_VERSION_VS_0_PBCFG_C != ADC_IP_SW_MAJOR_VERSION_VS_0_PBCFG) || \
     (ADC_IPW_SW_MINOR_VERSION_VS_0_PBCFG_C != ADC_IP_SW_MINOR_VERSION_VS_0_PBCFG) || \
     (ADC_IPW_SW_PATCH_VERSION_VS_0_PBCFG_C != ADC_IP_SW_PATCH_VERSION_VS_0_PBCFG) \
    )
  #error "Software Version Numbers of Adc_Ipw_VS_0_PBcfg.c and Adc_Ip_VS_0_PBcfg.h are different"
#endif

/* Check if Adc_Ipw_VS_0_PBcfg.c file and Pdb_Adc_Ip_VS_0_PBcfg.h file are of the same vendor */
#if (ADC_IPW_VENDOR_ID_VS_0_PBCFG_C != PDB_ADC_IP_VENDOR_ID_VS_0_PBCFG)
    #error "Adc_Ipw_VS_0_PBcfg.c and Pdb_Adc_Ip_VS_0_PBcfg.h have different vendor ids"
#endif

/* Check if Adc_Ipw_VS_0_PBcfg.c file and Pdb_Adc_Ip_VS_0_PBcfg.h file are of the same Autosar version */
#if ((ADC_IPW_AR_RELEASE_MAJOR_VERSION_VS_0_PBCFG_C != PDB_ADC_IP_AR_RELEASE_MAJOR_VERSION_VS_0_PBCFG) || \
     (ADC_IPW_AR_RELEASE_MINOR_VERSION_VS_0_PBCFG_C != PDB_ADC_IP_AR_RELEASE_MINOR_VERSION_VS_0_PBCFG) || \
     (ADC_IPW_AR_RELEASE_REVISION_VERSION_VS_0_PBCFG_C != PDB_ADC_IP_AR_RELEASE_REVISION_VERSION_VS_0_PBCFG) \
    )
    #error "AutoSar Version Numbers of Adc_Ipw_VS_0_PBcfg.c and Pdb_Adc_Ip_VS_0_PBcfg.h are different"
#endif

/* Check if Adc_Ipw_VS_0_PBcfg.c file and Pdb_Adc_Ip_VS_0_PBcfg.h file are of the same Software version */
#if ((ADC_IPW_SW_MAJOR_VERSION_VS_0_PBCFG_C != PDB_ADC_IP_SW_MAJOR_VERSION_VS_0_PBCFG) || \
     (ADC_IPW_SW_MINOR_VERSION_VS_0_PBCFG_C != PDB_ADC_IP_SW_MINOR_VERSION_VS_0_PBCFG) || \
     (ADC_IPW_SW_PATCH_VERSION_VS_0_PBCFG_C != PDB_ADC_IP_SW_PATCH_VERSION_VS_0_PBCFG) \
    )
  #error "Software Version Numbers of Adc_Ipw_VS_0_PBcfg.c and Pdb_Adc_Ip_VS_0_PBcfg.h are different"
#endif


/*==================================================================================================
*                                   GLOBAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

#define ADC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Adc_MemMap.h"


#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
/**
* @brief          Definition of Adc Ipw Channel limits for Logical Unit Id 0 configuration variant _VS_0.
*/
static const Adc_ChannelLimitCheckingType ChannelLimitCheckingConfig_0_VS_0[] =
{
    {
        /**< @brief range for limit check */
        (boolean)FALSE, /* ChannelLimitCheckEnabled */
        /**< @brief range for limit check */
        ADC_RANGE_ALWAYS, /* ChannelRange */
        /**< @brief high limit value */
        4095U, /* ChannelHighLimit */
        /**< @brief low limit value */
        0U /* ChannelLowLimit */
    },
    {
        /**< @brief range for limit check */
        (boolean)FALSE, /* ChannelLimitCheckEnabled */
        /**< @brief range for limit check */
        ADC_RANGE_ALWAYS, /* ChannelRange */
        /**< @brief high limit value */
        4095U, /* ChannelHighLimit */
        /**< @brief low limit value */
        0U /* ChannelLowLimit */
    },
    {
        /**< @brief range for limit check */
        (boolean)FALSE, /* ChannelLimitCheckEnabled */
        /**< @brief range for limit check */
        ADC_RANGE_ALWAYS, /* ChannelRange */
        /**< @brief high limit value */
        4095U, /* ChannelHighLimit */
        /**< @brief low limit value */
        0U /* ChannelLowLimit */
    },
    {
        /**< @brief range for limit check */
        (boolean)FALSE, /* ChannelLimitCheckEnabled */
        /**< @brief range for limit check */
        ADC_RANGE_ALWAYS, /* ChannelRange */
        /**< @brief high limit value */
        4095U, /* ChannelHighLimit */
        /**< @brief low limit value */
        0U /* ChannelLowLimit */
    }
};
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
/**
* @brief          Definition of Adc Ipw Channel limits for Logical Unit Id 1 configuration variant _VS_0.
*/
static const Adc_ChannelLimitCheckingType ChannelLimitCheckingConfig_1_VS_0[] =
{
    {
        /**< @brief range for limit check */
        (boolean)FALSE, /* ChannelLimitCheckEnabled */
        /**< @brief range for limit check */
        ADC_RANGE_ALWAYS, /* ChannelRange */
        /**< @brief high limit value */
        4095U, /* ChannelHighLimit */
        /**< @brief low limit value */
        0U /* ChannelLowLimit */
    },
    {
        /**< @brief range for limit check */
        (boolean)FALSE, /* ChannelLimitCheckEnabled */
        /**< @brief range for limit check */
        ADC_RANGE_ALWAYS, /* ChannelRange */
        /**< @brief high limit value */
        4095U, /* ChannelHighLimit */
        /**< @brief low limit value */
        0U /* ChannelLowLimit */
    },
    {
        /**< @brief range for limit check */
        (boolean)FALSE, /* ChannelLimitCheckEnabled */
        /**< @brief range for limit check */
        ADC_RANGE_ALWAYS, /* ChannelRange */
        /**< @brief high limit value */
        4095U, /* ChannelHighLimit */
        /**< @brief low limit value */
        0U /* ChannelLowLimit */
    },
    {
        /**< @brief range for limit check */
        (boolean)FALSE, /* ChannelLimitCheckEnabled */
        /**< @brief range for limit check */
        ADC_RANGE_ALWAYS, /* ChannelRange */
        /**< @brief high limit value */
        4095U, /* ChannelHighLimit */
        /**< @brief low limit value */
        0U /* ChannelLowLimit */
    }
};
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */


#define ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Adc_MemMap.h"

#define ADC_START_SEC_CONFIG_DATA_16
#include "Adc_MemMap.h"
/**
* @brief          Group Channel Delays for configuration variant _VS_0.
*
*/


#define ADC_STOP_SEC_CONFIG_DATA_16
#include "Adc_MemMap.h"

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

#define ADC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Adc_MemMap.h"

/**
* @brief          Adc Ipw Config configuration variant VS_0.
*/
const Adc_Ipw_Config AdcIpwCfg_VS_0 =
{
    { &AdcIpConfig_0_VS_0, &AdcIpConfig_1_VS_0 }, /* AdcConfigPtrArr */
    { &PdbAdcIpConfig_0_VS_0, &PdbAdcIpConfig_1_VS_0 }, /* PdbConfig */
    { 0U, 1U }, /* AdcPhysicalIdArr */
#if (ADC_DUAL_CLOCK_MODE == STD_ON)
    { NULL_PTR, NULL_PTR }, /* AdcAltClockConfig */
#endif /* (ADC_DUAL_CLOCK_MODE == STD_ON) */
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    { ChannelLimitCheckingConfig_0_VS_0, ChannelLimitCheckingConfig_1_VS_0 }, /* ChannelLimitCheckingConfigs */
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
    /* Mapping */
    {
        { ADC_INTERRUPT, ADC_INTERRUPT }, /* AdcDmaInterruptSoftware */
        /**< @brief number of groups per hw unit > */
        { 4U, 4U }, /* AdcGroups */
        /**< @brief number of channels per hw unit > */
        { 4U, 4U }, /* AdcChannels */
        { ADC_IPW_INVALID_DMA_CHANNEL_ID, ADC_IPW_INVALID_DMA_CHANNEL_ID }, /* AdcDmaChannelLogicId */
#if (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS) || (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON)
        { ADC_IPW_INVALID_DMA_CHANNEL_ID, ADC_IPW_INVALID_DMA_CHANNEL_ID }, /* AdcCountingDmaChanLogicId */
#endif /* (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS) || (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON) */
        { STD_ON, STD_ON }, /* AdcHwUnitArr */
        { 0U, 1U } /* HwLogicalId */
    }
};

/**
* @brief          ADC Ipw Group 0 Config VS_0.
*/
const Adc_Ipw_GroupConfig AdcIpwGroupConfig_0_VS_0 =
{
#if (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF)
    /**< @brief Main Average enable status of group */
    STD_OFF, /* GroupAvgEnable */
    /**< @brief Main Average selection of group */
    ADC_IP_AVG_4_CONV, /* GroupAvgSelect */
    20U, /* ConvTime */
#if (ADC_DUAL_CLOCK_MODE == STD_ON)
    /**< @brief Alternate Average enable status of group */
    STD_OFF, /* GroupAvgEnableAlternate */
    /**< @brief Alternate Average selection of group */
    ADC_IP_AVG_4_CONV, /* GroupAvgSelectAlternate */
    ADC_IP_DEFAULT_SAMPLE_TIME, /* AlternateConvTime */
#endif /* (ADC_DUAL_CLOCK_MODE == STD_ON) */
#endif /* (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF) */
    0U, /* PdbPeriod */
    0U, /* PdbDelay */
    (boolean)TRUE, /* AdcGroupEnableBackToBack */
    (boolean)FALSE, /* AdcGroupEnableChannelDelays */
    NULL_PTR /* DelayPtr */
};

/**
* @brief          ADC Ipw Group 1 Config VS_0.
*/
const Adc_Ipw_GroupConfig AdcIpwGroupConfig_1_VS_0 =
{
#if (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF)
    /**< @brief Main Average enable status of group */
    STD_OFF, /* GroupAvgEnable */
    /**< @brief Main Average selection of group */
    ADC_IP_AVG_4_CONV, /* GroupAvgSelect */
    1U, /* ConvTime */
#if (ADC_DUAL_CLOCK_MODE == STD_ON)
    /**< @brief Alternate Average enable status of group */
    STD_OFF, /* GroupAvgEnableAlternate */
    /**< @brief Alternate Average selection of group */
    ADC_IP_AVG_4_CONV, /* GroupAvgSelectAlternate */
    ADC_IP_DEFAULT_SAMPLE_TIME, /* AlternateConvTime */
#endif /* (ADC_DUAL_CLOCK_MODE == STD_ON) */
#endif /* (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF) */
    0U, /* PdbPeriod */
    0U, /* PdbDelay */
    (boolean)TRUE, /* AdcGroupEnableBackToBack */
    (boolean)FALSE, /* AdcGroupEnableChannelDelays */
    NULL_PTR /* DelayPtr */
};

/**
* @brief          ADC Ipw Group 2 Config VS_0.
*/
const Adc_Ipw_GroupConfig AdcIpwGroupConfig_2_VS_0 =
{
#if (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF)
    /**< @brief Main Average enable status of group */
    STD_OFF, /* GroupAvgEnable */
    /**< @brief Main Average selection of group */
    ADC_IP_AVG_4_CONV, /* GroupAvgSelect */
    1U, /* ConvTime */
#if (ADC_DUAL_CLOCK_MODE == STD_ON)
    /**< @brief Alternate Average enable status of group */
    STD_OFF, /* GroupAvgEnableAlternate */
    /**< @brief Alternate Average selection of group */
    ADC_IP_AVG_4_CONV, /* GroupAvgSelectAlternate */
    ADC_IP_DEFAULT_SAMPLE_TIME, /* AlternateConvTime */
#endif /* (ADC_DUAL_CLOCK_MODE == STD_ON) */
#endif /* (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF) */
    0U, /* PdbPeriod */
    0U, /* PdbDelay */
    (boolean)TRUE, /* AdcGroupEnableBackToBack */
    (boolean)FALSE, /* AdcGroupEnableChannelDelays */
    NULL_PTR /* DelayPtr */
};

/**
* @brief          ADC Ipw Group 3 Config VS_0.
*/
const Adc_Ipw_GroupConfig AdcIpwGroupConfig_3_VS_0 =
{
#if (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF)
    /**< @brief Main Average enable status of group */
    STD_OFF, /* GroupAvgEnable */
    /**< @brief Main Average selection of group */
    ADC_IP_AVG_4_CONV, /* GroupAvgSelect */
    1U, /* ConvTime */
#if (ADC_DUAL_CLOCK_MODE == STD_ON)
    /**< @brief Alternate Average enable status of group */
    STD_OFF, /* GroupAvgEnableAlternate */
    /**< @brief Alternate Average selection of group */
    ADC_IP_AVG_4_CONV, /* GroupAvgSelectAlternate */
    ADC_IP_DEFAULT_SAMPLE_TIME, /* AlternateConvTime */
#endif /* (ADC_DUAL_CLOCK_MODE == STD_ON) */
#endif /* (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF) */
    0U, /* PdbPeriod */
    0U, /* PdbDelay */
    (boolean)TRUE, /* AdcGroupEnableBackToBack */
    (boolean)FALSE, /* AdcGroupEnableChannelDelays */
    NULL_PTR /* DelayPtr */
};

/**
* @brief          ADC Ipw Group 4 Config VS_0.
*/
const Adc_Ipw_GroupConfig AdcIpwGroupConfig_4_VS_0 =
{
#if (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF)
    /**< @brief Main Average enable status of group */
    STD_OFF, /* GroupAvgEnable */
    /**< @brief Main Average selection of group */
    ADC_IP_AVG_4_CONV, /* GroupAvgSelect */
    1U, /* ConvTime */
#if (ADC_DUAL_CLOCK_MODE == STD_ON)
    /**< @brief Alternate Average enable status of group */
    STD_OFF, /* GroupAvgEnableAlternate */
    /**< @brief Alternate Average selection of group */
    ADC_IP_AVG_4_CONV, /* GroupAvgSelectAlternate */
    ADC_IP_DEFAULT_SAMPLE_TIME, /* AlternateConvTime */
#endif /* (ADC_DUAL_CLOCK_MODE == STD_ON) */
#endif /* (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF) */
    0U, /* PdbPeriod */
    0U, /* PdbDelay */
    (boolean)TRUE, /* AdcGroupEnableBackToBack */
    (boolean)FALSE, /* AdcGroupEnableChannelDelays */
    NULL_PTR /* DelayPtr */
};

/**
* @brief          ADC Ipw Group 5 Config VS_0.
*/
const Adc_Ipw_GroupConfig AdcIpwGroupConfig_5_VS_0 =
{
#if (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF)
    /**< @brief Main Average enable status of group */
    STD_OFF, /* GroupAvgEnable */
    /**< @brief Main Average selection of group */
    ADC_IP_AVG_4_CONV, /* GroupAvgSelect */
    1U, /* ConvTime */
#if (ADC_DUAL_CLOCK_MODE == STD_ON)
    /**< @brief Alternate Average enable status of group */
    STD_OFF, /* GroupAvgEnableAlternate */
    /**< @brief Alternate Average selection of group */
    ADC_IP_AVG_4_CONV, /* GroupAvgSelectAlternate */
    ADC_IP_DEFAULT_SAMPLE_TIME, /* AlternateConvTime */
#endif /* (ADC_DUAL_CLOCK_MODE == STD_ON) */
#endif /* (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF) */
    0U, /* PdbPeriod */
    0U, /* PdbDelay */
    (boolean)TRUE, /* AdcGroupEnableBackToBack */
    (boolean)FALSE, /* AdcGroupEnableChannelDelays */
    NULL_PTR /* DelayPtr */
};

/**
* @brief          ADC Ipw Group 6 Config VS_0.
*/
const Adc_Ipw_GroupConfig AdcIpwGroupConfig_6_VS_0 =
{
#if (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF)
    /**< @brief Main Average enable status of group */
    STD_OFF, /* GroupAvgEnable */
    /**< @brief Main Average selection of group */
    ADC_IP_AVG_4_CONV, /* GroupAvgSelect */
    1U, /* ConvTime */
#if (ADC_DUAL_CLOCK_MODE == STD_ON)
    /**< @brief Alternate Average enable status of group */
    STD_OFF, /* GroupAvgEnableAlternate */
    /**< @brief Alternate Average selection of group */
    ADC_IP_AVG_4_CONV, /* GroupAvgSelectAlternate */
    ADC_IP_DEFAULT_SAMPLE_TIME, /* AlternateConvTime */
#endif /* (ADC_DUAL_CLOCK_MODE == STD_ON) */
#endif /* (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF) */
    0U, /* PdbPeriod */
    0U, /* PdbDelay */
    (boolean)TRUE, /* AdcGroupEnableBackToBack */
    (boolean)FALSE, /* AdcGroupEnableChannelDelays */
    NULL_PTR /* DelayPtr */
};

/**
* @brief          ADC Ipw Group 7 Config VS_0.
*/
const Adc_Ipw_GroupConfig AdcIpwGroupConfig_7_VS_0 =
{
#if (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF)
    /**< @brief Main Average enable status of group */
    STD_OFF, /* GroupAvgEnable */
    /**< @brief Main Average selection of group */
    ADC_IP_AVG_4_CONV, /* GroupAvgSelect */
    1U, /* ConvTime */
#if (ADC_DUAL_CLOCK_MODE == STD_ON)
    /**< @brief Alternate Average enable status of group */
    STD_OFF, /* GroupAvgEnableAlternate */
    /**< @brief Alternate Average selection of group */
    ADC_IP_AVG_4_CONV, /* GroupAvgSelectAlternate */
    ADC_IP_DEFAULT_SAMPLE_TIME, /* AlternateConvTime */
#endif /* (ADC_DUAL_CLOCK_MODE == STD_ON) */
#endif /* (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF) */
    0U, /* PdbPeriod */
    0U, /* PdbDelay */
    (boolean)TRUE, /* AdcGroupEnableBackToBack */
    (boolean)FALSE, /* AdcGroupEnableChannelDelays */
    NULL_PTR /* DelayPtr */
};


#define ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Adc_MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

