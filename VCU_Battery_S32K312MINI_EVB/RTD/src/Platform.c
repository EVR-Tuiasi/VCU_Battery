/*==================================================================================================
*   Project              : RTD AUTOSAR 4.9
*   Platform             : CORTEXM
*   Peripheral           :
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

/**
 *   @file
 *
 *   @addtogroup Platform
 *   @{
 */
#ifdef __cplusplus
extern "C"{
#endif
/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Mcal.h"
#include "Platform.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_PLATFORM_VENDOR_ID_C                     43
#define CDD_PLATFORM_AR_RELEASE_MAJOR_VERSION_C      4
#define CDD_PLATFORM_AR_RELEASE_MINOR_VERSION_C      9
#define CDD_PLATFORM_AR_RELEASE_REVISION_VERSION_C   0
#define CDD_PLATFORM_SW_MAJOR_VERSION_C              7
#define CDD_PLATFORM_SW_MINOR_VERSION_C              0
#define CDD_PLATFORM_SW_PATCH_VERSION_C              1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Platform header file are of the same vendor */
#if (CDD_PLATFORM_VENDOR_ID_C != CDD_PLATFORM_VENDOR_ID)
    #error "Platform.c and Platform.h have different vendor ids"
#endif
/* Check if current file and Platform header file are of the same Autosar version */
#if ((CDD_PLATFORM_AR_RELEASE_MAJOR_VERSION_C    != CDD_PLATFORM_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_PLATFORM_AR_RELEASE_MINOR_VERSION_C    != CDD_PLATFORM_AR_RELEASE_MINOR_VERSION) || \
     (CDD_PLATFORM_AR_RELEASE_REVISION_VERSION_C != CDD_PLATFORM_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Platform.c and Platform.h are different"
#endif
/* Check if current file and Platform header file are of the same Software version */
#if ((CDD_PLATFORM_SW_MAJOR_VERSION_C != CDD_PLATFORM_SW_MAJOR_VERSION) || \
     (CDD_PLATFORM_SW_MINOR_VERSION_C != CDD_PLATFORM_SW_MINOR_VERSION) || \
     (CDD_PLATFORM_SW_PATCH_VERSION_C != CDD_PLATFORM_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Platform.c and Platform.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Checks against Mcal.h */
    #if ((CDD_PLATFORM_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (CDD_PLATFORM_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AUTOSAR Version Numbers of Platform.c and Mcal.h are different"
    #endif
#endif

/*==================================================================================================
 *                                        GLOBAL CONSTANTS
==================================================================================================*/

 /*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define PLATFORM_START_SEC_CODE
#include "Platform_MemMap.h"
#if (PLATFORM_DEV_ERROR_DETECT == STD_ON)
static Std_ReturnType Platform_CheckNullPtrCfg(uint8 u8UserId);
#endif
#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"


/*==================================================================================================
 *                                        GLOBAL VARIABLES
==================================================================================================*/
#ifdef  PLATFORM_ENABLE_INT_CTRL
    #if (PLATFORM_ENABLE_INT_CTRL == STD_ON) && (PLATFORM_DEV_ERROR_DETECT == STD_ON)
    #if (PLATFORM_MULTICORE_SUPPORT == STD_ON)
    #if (PLATFORM_ISR_CONFIG_COUNT != (0U))
#define PLATFORM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h"
extern const Platform_IrqPartMapEntryType Platform_IrqToPartMapTable[PLATFORM_ISR_CONFIG_COUNT];
extern const Platform_PartIdMapCoreIdType Platform_PartIdMapCoreIdTable[PLATFORM_MAX_SUPPORTED_PARTITIONS];
#define PLATFORM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h"
    #endif
    #endif
    #endif
#endif
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#define PLATFORM_START_SEC_CODE
#include "Platform_MemMap.h"
#if (PLATFORM_DEV_ERROR_DETECT == STD_ON)
/**
 * @brief   Checks whether the configuration pointer for a given partition is valid.
 *
 * @param   u8UserId    The ID of the partition to check.
 * @return  E_OK if the configuration and its sub-configurations are not NULL, otherwise E_NOT_OK.
 */
static Std_ReturnType Platform_CheckNullPtrCfg(uint8 u8UserId)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;

    /* Check if the partition ID is within the valid range */
    if (u8UserId < PLATFORM_MAX_PARTITIONS)
    {
        /* Check if the Platform configuration pointer of the current partion is not NULL */
        if ((Platform_Config[u8UserId]) != NULL_PTR)
        {
            /* Check if the IpwConfig pointer inside the configuration of the current partiion is not NULL */
            if ((Platform_Config[u8UserId]->pIpwConfig) != NULL_PTR)
            {
                RetVal = E_OK;
            }
        }
    }

    return RetVal;
}
#endif
#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"

#ifdef  PLATFORM_ENABLE_INT_CTRL
    #if (PLATFORM_ENABLE_INT_CTRL == STD_ON) && (PLATFORM_DEV_ERROR_DETECT == STD_ON)
    #if (PLATFORM_MULTICORE_SUPPORT == STD_ON)
    #if (PLATFORM_ISR_CONFIG_COUNT != (0U))
#define PLATFORM_START_SEC_CODE
#include "Platform_MemMap.h"
/**
 * @brief   Finds the Core ID associated with a given Partition ID.
 *
 * @param   u8PartId                The Partition ID to look up.
 * @param   pu8OutMappingCoreId     Pointer to store the found Core ID.
 * @return  TRUE if the Core ID was found, FALSE otherwise.
 */
static boolean Platform_FindMappingCoreId(uint8 u8PartId, uint8 *pu8OutMappingCoreId)
{
    boolean bIsAvailable = FALSE;
    uint32 u32Index;

    /* Iterate through the partition-to-core mapping table */
    for (u32Index = 0; u32Index < PLATFORM_MAX_SUPPORTED_PARTITIONS; u32Index++)
    {
        /* Check if the current entry matches the given Partition ID */
        if (u8PartId == Platform_PartIdMapCoreIdTable[u32Index].u8PartitionId)
        {
            /* Store the corresponding Core ID and mark as found */
            *pu8OutMappingCoreId = Platform_PartIdMapCoreIdTable[u32Index].u8CoreId;
            bIsAvailable = TRUE;
            break;
        }
    }

    return bIsAvailable;
}
/**
 * @brief   Checks whether a given IRQ is assigned to another partition on the same core,
 *          which would result in a conflict.
 *
 * @param   eIrqNumber         The IRQ number to check.
 * @param   u8CurrentPartId    The current partition ID.
 * @return  TRUE if a conflict is detected on the same core, FALSE otherwise.
 */
static boolean Platform_IsIrqConflictOnSameCore(IRQn_Type eIrqNumber, uint8 u8CurrentPartId)
{
    boolean bRetVal = FALSE;
    boolean bCurrentCoreFound = FALSE;
    boolean bScanCoreFound = FALSE;
    uint8 u8CurrentCoreId = 0U;
    uint8 u8ScanCoreId = 0U;
    uint32 u32Index = 0U;

    /* Get the Core ID of the current partition */
    bCurrentCoreFound = Platform_FindMappingCoreId(u8CurrentPartId, &u8CurrentCoreId);

    if (bCurrentCoreFound == TRUE)
    {
        /* Scan the IRQ-to-partition mapping table */
        for (u32Index = 0U; u32Index < PLATFORM_ISR_CONFIG_COUNT; ++u32Index)
        {
            /* Check if the IRQ number matches */
            if (Platform_IrqToPartMapTable[u32Index].eIrqNumber == eIrqNumber)
            {
                /* Check if the IRQ is assigned to a different partition or not */
                if (Platform_IrqToPartMapTable[u32Index].u8PartId != u8CurrentPartId)
                {
                    /* If both partitions are on the same core, a conflict exists */
                    bScanCoreFound = Platform_FindMappingCoreId(
                        Platform_IrqToPartMapTable[u32Index].u8PartId,
                        &u8ScanCoreId);

                    if ((bScanCoreFound == TRUE) &&
                        (u8ScanCoreId == u8CurrentCoreId))
                    {
                        bRetVal = TRUE;
                        break;
                    }
                }
            }
        }
    }
    else
    {
        /* The current Partition ID is not available in Platform_PartIdMapCoreIdTable */
        bRetVal = TRUE;
    }

    return bRetVal;
}
#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"
    #endif
    #endif
    #endif
#endif

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
#define PLATFORM_START_SEC_CODE
#include "Platform_MemMap.h"
/**
 * @internal
 * @brief         Initializes the platform settings based on user configuration.
 * @implements    Platform_Init_Activity
 */
void Platform_Init(const Platform_ConfigType *pConfig)
{
    uint8 u8UserId;

    u8UserId = (uint8)Platform_GetCoreID();
    (void)pConfig;
#if (PLATFORM_DEV_ERROR_DETECT == STD_ON)
    /* Report error if pConfig is not NULL when precompile support is enabled */
    if (NULL_PTR != pConfig)
    {
        (void)Det_ReportError((uint16)CDD_PLATFORM_MODULE_ID, 0U, PLATFORM_INIT_ID, PLATFORM_E_PARAM_POINTER);
    }
    /* Check if the callee ECUC partition ID is assigned to the used configuration resource of the driver */
    else if ((Std_ReturnType)E_NOT_OK == Platform_CheckNullPtrCfg(u8UserId))
    {
        (void)Det_ReportError((uint16)CDD_PLATFORM_MODULE_ID, 0U, PLATFORM_INIT_ID, PLATFORM_E_PARAM_CONFIG);
    }
    else
#endif /*(PLATFORM_DEV_ERROR_DETECT == STD_ON)*/
    {
        Platform_Ipw_Init(Platform_Config[u8UserId]->pIpwConfig);
#if (PLATFORM_ENABLE_MPU_M7 == STD_ON)
#if (PLATFORM_DEV_ERROR_DETECT == STD_ON)
        /* Checks if the MPU_M7 instance is available in the current partition */
        if (Platform_Config[u8UserId]->pIpwConfig->Platform_Ipw_pMpuConfig != NULL_PTR)
#endif /*(PLATFORM_DEV_ERROR_DETECT == STD_ON)*/
        {
            Platform_Ipw_Mpu_M7_Init(Platform_Config[u8UserId]->pIpwConfig);
        }
#endif

    }
}

#ifdef  PLATFORM_ENABLE_INT_CTRL
#if  (PLATFORM_ENABLE_INT_CTRL == STD_ON)
/**
 * @internal
 * @brief         Configures (enables/disables) an interrupt request.
 * @implements    Platform_SetIrq_Activity
 */
Std_ReturnType Platform_SetIrq(IRQn_Type eIrqNumber, boolean bEnable)
{
    Std_ReturnType RetValue = (Std_ReturnType)E_OK;

#if (PLATFORM_DEV_ERROR_DETECT == STD_ON)
    if (((sint32)INT_CTRL_IP_MAX_IRQ < (sint32)eIrqNumber) || \
        ((sint32)INT_CTRL_IP_MIN_IRQ > (sint32)eIrqNumber))
    {
        (void)Det_ReportError(CDD_PLATFORM_MODULE_ID, 0U, PLATFORM_SET_IRQ_ID, PLATFORM_E_PARAM_OUT_OF_RANGE);
        RetValue = (Std_ReturnType)E_NOT_OK;
    }
    #if (PLATFORM_MULTICORE_SUPPORT == STD_ON)
        #if (PLATFORM_ISR_CONFIG_COUNT != (0U))
    else if (Platform_IsIrqConflictOnSameCore(eIrqNumber, (uint8)Platform_GetCoreID()))
    {
        (void)Det_ReportError(CDD_PLATFORM_MODULE_ID, 0U, PLATFORM_SET_IRQ_ID, PLATFORM_E_PARAM_CONFIG);
        RetValue = (Std_ReturnType)E_NOT_OK;
    }
        #endif
    #endif
    else
#endif
    {
        Platform_Ipw_SetIrq(eIrqNumber, bEnable);
    }
    return RetValue;
}

/**
 * @internal
 * @brief         Configures the priority of an interrupt request.
 * @implements    Platform_SetIrqPriority_Activity
 */
Std_ReturnType Platform_SetIrqPriority(IRQn_Type eIrqNumber, uint8 u8Priority)
{
    Std_ReturnType RetValue = (Std_ReturnType)E_OK;

#if (PLATFORM_DEV_ERROR_DETECT == STD_ON)
    #if (INT_CTRL_IP_CORTEXM == STD_ON)
    if (((sint32)eIrqNumber > (sint32)INT_CTRL_IP_MAX_IRQ) || \
        ((sint32)INT_CTRL_IP_MIN_IRQ > (sint32)eIrqNumber) || \
        (u8Priority >= (uint8)(1U << INT_CTRL_IP_NVIC_PRIO_BITS)))
    #else
    if (((sint32)eIrqNumber > (sint32)INT_CTRL_IP_MAX_IRQ) || \
        ((sint32)INT_CTRL_IP_MIN_IRQ > (sint32)eIrqNumber) || \
        (u8Priority >= (uint8)(1U << INT_CTRL_IP_GIC_PRIO_BITS)))
    #endif
    {
        (void)Det_ReportError(CDD_PLATFORM_MODULE_ID, 0U, PLATFORM_SET_IRQ_PRIO_ID, PLATFORM_E_PARAM_OUT_OF_RANGE);
        RetValue = (Std_ReturnType)E_NOT_OK;
    }
    #if (PLATFORM_MULTICORE_SUPPORT == STD_ON)
        #if (PLATFORM_ISR_CONFIG_COUNT != (0U))
    else if (Platform_IsIrqConflictOnSameCore(eIrqNumber, (uint8)Platform_GetCoreID()))
    {
        (void)Det_ReportError(CDD_PLATFORM_MODULE_ID, 0U, PLATFORM_SET_IRQ_PRIO_ID, PLATFORM_E_PARAM_CONFIG);
        RetValue = (Std_ReturnType)E_NOT_OK;
    }
        #endif
    #endif
    else
#endif
    {
        Platform_Ipw_SetIrqPriority(eIrqNumber, u8Priority);
    }
    return RetValue;
}

/**
 * @internal
 * @brief         Returns the priority of an interrupt request.
 * @implements    Platform_GetIrqPriority_Activity
 */
Std_ReturnType Platform_GetIrqPriority(IRQn_Type eIrqNumber, uint8 * u8Priority)
{
    Std_ReturnType RetValue = (Std_ReturnType)E_OK;

#if (PLATFORM_DEV_ERROR_DETECT == STD_ON)
    if (((sint32)INT_CTRL_IP_MAX_IRQ < (sint32)eIrqNumber) || \
        ((sint32)INT_CTRL_IP_MIN_IRQ > (sint32)eIrqNumber))
    {
        (void)Det_ReportError(CDD_PLATFORM_MODULE_ID, 0U, PLATFORM_GET_IRQ_PRIO_ID, PLATFORM_E_PARAM_OUT_OF_RANGE);
        RetValue = (Std_ReturnType)E_NOT_OK;
    }
    else if (NULL_PTR == u8Priority)
    {
        (void)Det_ReportError(CDD_PLATFORM_MODULE_ID, 0U, PLATFORM_GET_IRQ_PRIO_ID, PLATFORM_E_PARAM_POINTER);
        RetValue = (Std_ReturnType)E_NOT_OK;
    }
    #if (PLATFORM_MULTICORE_SUPPORT == STD_ON)
        #if (PLATFORM_ISR_CONFIG_COUNT != (0U))
    else if (Platform_IsIrqConflictOnSameCore(eIrqNumber, (uint8)Platform_GetCoreID()))
    {
        (void)Det_ReportError(CDD_PLATFORM_MODULE_ID, 0U, PLATFORM_GET_IRQ_PRIO_ID, PLATFORM_E_PARAM_CONFIG);
        RetValue = (Std_ReturnType)E_NOT_OK;
    }
        #endif
    #endif
    else
#endif
    {
        *u8Priority = Platform_Ipw_GetIrqPriority(eIrqNumber);
    }

    return RetValue;
}

/**
 * @internal
 * @brief         Installs a new handler for an interrupt request.
 * @implements    Platform_InstallIrqHandler_Activity
 */
Std_ReturnType Platform_InstallIrqHandler(IRQn_Type eIrqNumber,
                                          const Platform_IrqHandlerType pfNewHandler,
                                          Platform_IrqHandlerType* const pfOldHandler)
{
    Std_ReturnType RetValue = (Std_ReturnType)E_OK;

#if (PLATFORM_DEV_ERROR_DETECT == STD_ON)
    if (((sint32)INT_CTRL_IP_MAX_IRQ < (sint32)eIrqNumber) || \
        ((sint32)INT_CTRL_IP_MIN_IRQ > (sint32)eIrqNumber))
    {
        (void)Det_ReportError(CDD_PLATFORM_MODULE_ID, 0U, PLATFORM_INSTALL_HANDLER_ID, PLATFORM_E_PARAM_OUT_OF_RANGE);
        RetValue = (Std_ReturnType)E_NOT_OK;
    }
    #if (PLATFORM_MULTICORE_SUPPORT == STD_ON)
        #if (PLATFORM_ISR_CONFIG_COUNT != (0U))
    else if (Platform_IsIrqConflictOnSameCore(eIrqNumber, (uint8)Platform_GetCoreID()))
    {
        (void)Det_ReportError(CDD_PLATFORM_MODULE_ID, 0U, PLATFORM_INSTALL_HANDLER_ID, PLATFORM_E_PARAM_CONFIG);
        RetValue = (Std_ReturnType)E_NOT_OK;
    }
        #endif
    #endif
    else
#endif
    {
        Platform_Ipw_InstallIrqHandler(eIrqNumber, pfNewHandler, pfOldHandler);
    }
    return RetValue;
}
#endif /* PLATFORM_ENABLE_INT_CTRL == STD_ON */
#endif /* PLATFORM_ENABLE_INT_CTRL */
#if (PLATFORM_INT_MONITOR == STD_ON)
/**
 * @internal
 * @brief         Configures (enables/disables) the interrupt monitor.
 * @implements    Platform_SetIrqMonitor_Activity
 */
void Platform_SetIrqMonitor(boolean bEnable)
{
    #if (PLATFORM_DEV_ERROR_DETECT == STD_ON)
    uint8 u8UserId;

    u8UserId = (uint8)Platform_GetCoreID();
    if ((Std_ReturnType)E_NOT_OK == Platform_CheckNullPtrCfg(u8UserId))
    {
        (void)Det_ReportError(CDD_PLATFORM_MODULE_ID, 0U, PLATFORM_SET_IRQ_MONITOR_ID, PLATFORM_E_PARAM_CONFIG);
    }
    else
    {
        /* This API is only valid for the partition selected via PlatformIntmGenericEcucPartitionRef in the configuration tool */
        if ((Std_ReturnType)E_NOT_OK == Platform_Ipw_ValidateSetIrqMonitor(Platform_Config[u8UserId] -> pIpwConfig))
        {
            (void)Det_ReportError(CDD_PLATFORM_MODULE_ID, 0U, PLATFORM_SET_IRQ_MONITOR_ID, PLATFORM_E_PARAM_CONFIG);
        }
        else
        {
    #endif
            Platform_Ipw_SetIrqMonitor(bEnable);
#if (PLATFORM_DEV_ERROR_DETECT == STD_ON)
        }
    }
#endif
}

/**
 * @internal
 * @brief         Acknowledges a monitored interrupt has been served.
 * @implements    Platform_AckIrq_Activity
 */
void Platform_AckIrq(IRQn_Type eIrqNumber)
{
#if (PLATFORM_DEV_ERROR_DETECT == STD_ON)
#if (PLATFORM_MULTICORE_SUPPORT == STD_ON)
    uint8 u8UserId;

    u8UserId = (uint8)Platform_GetCoreID();
    if ((Std_ReturnType)E_NOT_OK == Platform_CheckNullPtrCfg(u8UserId))
    {
        (void)Det_ReportError(CDD_PLATFORM_MODULE_ID, 0U, PLATFORM_ACK_IRQ_ID, PLATFORM_E_PARAM_CONFIG);
    }
    else if (Platform_Config[u8UserId]->pIpwConfig->pIntMonitor == NULL_PTR)
    {
        (void)Det_ReportError(CDD_PLATFORM_MODULE_ID, 0U, PLATFORM_ACK_IRQ_ID, PLATFORM_E_PARAM_CONFIG);
    }
    else if ((Platform_Config[u8UserId]->pIpwConfig->pIntMonitor->pIntmGenericConfig == NULL_PTR) &&
             (Platform_Config[u8UserId]->pIpwConfig->pIntMonitor->u8NumChannel == 0U))
    {
        (void)Det_ReportError(CDD_PLATFORM_MODULE_ID, 0U, PLATFORM_ACK_IRQ_ID, PLATFORM_E_PARAM_CONFIG);
    }
    else
#endif
#endif
    {
#if (PLATFORM_DEV_ERROR_DETECT == STD_ON)
        if (((sint32)eIrqNumber > (sint32)INTM_IP_MAX_IRQ) || \
            ((sint32)INTM_IP_MIN_IRQ > (sint32)eIrqNumber))
        {
            (void)Det_ReportError(CDD_PLATFORM_MODULE_ID, 0U, PLATFORM_ACK_IRQ_ID, PLATFORM_E_PARAM_OUT_OF_RANGE);
        }
        else
        {
#endif
            Platform_Ipw_AckIrq(eIrqNumber);
#if (PLATFORM_DEV_ERROR_DETECT == STD_ON)
        }
#endif
    }
}

/**
 * @internal
 * @brief         Selects an interrupt to monitor.
 * @implements    Platform_SelectMonitoredIrq_Activity
 */
void Platform_SelectMonitoredIrq(uint8 u8Channel , IRQn_Type eIrqNumber)
{
    uint8 u8UserId;

    u8UserId = (uint8)Platform_GetCoreID();
#if (PLATFORM_DEV_ERROR_DETECT == STD_ON)
    if (((sint32)eIrqNumber > (sint32)INTM_IP_MAX_IRQ) || \
        ((sint32)INTM_IP_MIN_IRQ > (sint32)eIrqNumber) ||
        (u8Channel >= PLATFORM_INT_MONITOR_CNT))
    {
        (void)Det_ReportError(CDD_PLATFORM_MODULE_ID, 0U, PLATFORM_SELECT_MONITORED_IRQ_ID, PLATFORM_E_PARAM_OUT_OF_RANGE);
    }
    else
    {
        if ((Std_ReturnType)E_OK == Platform_CheckNullPtrCfg(u8UserId))
        {
            if ((Std_ReturnType)E_NOT_OK == Platform_Ipw_ValidateChannelIntm(Platform_Config[u8UserId] -> pIpwConfig, u8Channel))
            {
                (void)Det_ReportError(CDD_PLATFORM_MODULE_ID, 0U, PLATFORM_SELECT_MONITORED_IRQ_ID, PLATFORM_E_PARAM_CONFIG);
            }
            else
            {
#endif
                Platform_Ipw_SelectMonitoredIrq(Platform_Config[u8UserId] -> pIpwConfig,
                                            u8Channel, eIrqNumber);
#if (PLATFORM_DEV_ERROR_DETECT == STD_ON)
            }
        }
        else
        {
             (void)Det_ReportError(CDD_PLATFORM_MODULE_ID, 0U, PLATFORM_SELECT_MONITORED_IRQ_ID, PLATFORM_E_PARAM_CONFIG);
        }
    }
#endif
}

/**
 * @internal
 * @brief         Sets the latency for a monitored interrupt.
 * @implements    Platform_SetMonitoredIrqLatency_Activity
 */
void Platform_SetMonitoredIrqLatency(uint8 u8Channel, uint32 u32Latency)
{
    uint8 u8UserId;

    u8UserId = (uint8)Platform_GetCoreID();
#if (PLATFORM_DEV_ERROR_DETECT == STD_ON)
    if ((PLATFORM_INT_MONITOR_MAX_LATENCY < u32Latency) ||
        (PLATFORM_INT_MONITOR_CNT <= u8Channel))
    {
         (void)Det_ReportError(CDD_PLATFORM_MODULE_ID, 0U, PLATFORM_SET_MONITORED_IRQ_LATENCY_ID, PLATFORM_E_PARAM_OUT_OF_RANGE);
    }
    else
    {
        if ((Std_ReturnType)E_NOT_OK == Platform_CheckNullPtrCfg(u8UserId))
        {
            (void)Det_ReportError(CDD_PLATFORM_MODULE_ID, 0U, PLATFORM_SET_MONITORED_IRQ_LATENCY_ID, PLATFORM_E_PARAM_CONFIG);
        }
        else
        {
            if ((Std_ReturnType)E_NOT_OK == Platform_Ipw_ValidateChannelIntm(Platform_Config[u8UserId] -> pIpwConfig, u8Channel))
            {
                (void)Det_ReportError(CDD_PLATFORM_MODULE_ID, 0U, PLATFORM_SET_MONITORED_IRQ_LATENCY_ID, PLATFORM_E_PARAM_CONFIG);
            }
            else
            {
#endif
                Platform_Ipw_SetMonitoredIrqLatency(Platform_Config[u8UserId] -> pIpwConfig,
                                               u8Channel, u32Latency);
#if (PLATFORM_DEV_ERROR_DETECT == STD_ON)
            }
        }
    }
#endif
}
/**
 * @internal
 * @brief         Resets the timer for an interrupt monitor.
 * @implements    Platform_ResetIrqMonitorTimer_Activity
 */
void Platform_ResetIrqMonitorTimer(uint8 u8Channel)
{
    uint8 u8UserId;

    u8UserId = (uint8)Platform_GetCoreID();
#if (PLATFORM_DEV_ERROR_DETECT == STD_ON)
    if (PLATFORM_INT_MONITOR_CNT <= u8Channel)
    {
        (void)Det_ReportError(CDD_PLATFORM_MODULE_ID, 0U, PLATFORM_RESET_IRQ_MONITOR_TIMER_ID, PLATFORM_E_PARAM_OUT_OF_RANGE);
    }
    else
    {
        if ((Std_ReturnType)E_NOT_OK == Platform_CheckNullPtrCfg(u8UserId))
        {
            (void)Det_ReportError(CDD_PLATFORM_MODULE_ID, 0U, PLATFORM_RESET_IRQ_MONITOR_TIMER_ID, PLATFORM_E_PARAM_CONFIG);
        }
        else
        {
            if ((Std_ReturnType)E_NOT_OK == Platform_Ipw_ValidateChannelIntm(Platform_Config[u8UserId] -> pIpwConfig, u8Channel))
            {
                (void)Det_ReportError(CDD_PLATFORM_MODULE_ID, 0U, PLATFORM_RESET_IRQ_MONITOR_TIMER_ID, PLATFORM_E_PARAM_CONFIG);
            }
            else
            {
#endif
                Platform_Ipw_ResetIrqMonitorTimer(Platform_Config[u8UserId] -> pIpwConfig,
                                            u8Channel);
#if (PLATFORM_DEV_ERROR_DETECT == STD_ON)
            }
        }
    }
#endif
}

/**
 * @internal
 * @brief         Retrieves the status of an interrupt monitor.
 * @implements    Platform_GetIrqMonitorStatus_Activity
 */
Std_ReturnType Platform_GetIrqMonitorStatus(uint8 u8Channel, boolean *bLatencyExceeded)
{
    uint8 u8UserId;
    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;

    u8UserId = (uint8)Platform_GetCoreID();
#if (PLATFORM_DEV_ERROR_DETECT == STD_ON)
    if (PLATFORM_INT_MONITOR_CNT <= u8Channel)
    {
        (void)Det_ReportError(CDD_PLATFORM_MODULE_ID, 0U, PLATFORM_GET_IRQ_MONITOR_STATUS_ID, PLATFORM_E_PARAM_OUT_OF_RANGE);
    }
    else if (NULL_PTR == bLatencyExceeded)
    {
        (void)Det_ReportError(CDD_PLATFORM_MODULE_ID, 0U, PLATFORM_GET_IRQ_MONITOR_STATUS_ID, PLATFORM_E_PARAM_POINTER);
    }
    else
    {
        if((Std_ReturnType)E_NOT_OK == Platform_CheckNullPtrCfg(u8UserId))
        {
            (void)Det_ReportError(CDD_PLATFORM_MODULE_ID, 0U, PLATFORM_GET_IRQ_MONITOR_STATUS_ID, PLATFORM_E_PARAM_CONFIG);
        }
        else
        {
            if ((Std_ReturnType)E_NOT_OK == Platform_Ipw_ValidateChannelIntm(Platform_Config[u8UserId] -> pIpwConfig, u8Channel))
            {
                (void)Det_ReportError(CDD_PLATFORM_MODULE_ID, 0U, PLATFORM_GET_IRQ_MONITOR_STATUS_ID, PLATFORM_E_PARAM_CONFIG);
            }
            else
            {
#endif
                *bLatencyExceeded = Platform_Ipw_GetIrqMonitorStatus(Platform_Config[u8UserId] -> pIpwConfig,
                                                        u8Channel);
                 RetVal = (Std_ReturnType)E_OK;
#if (PLATFORM_DEV_ERROR_DETECT == STD_ON)
            }
        }
    }
 #endif
    return RetVal;
}
#endif





#if (PLATFORM_ENABLE_MPU_M7 == STD_ON)
/*================================================================================================*/

 /**
 * @brief         Configures the region selected by u8RegionNum with the data from pUserConfigPtr
 *
 * @details       This function is Reentrant
 *
 * @param[in]     u8RegionNum:    region number
 * @param[in]     pUserConfigPtr: pointer to the region configuration structure for MPU M7.
 * @return        void
 *
 * @api
 *
 * @pre
 *
 * */
/* @implements         Platform_Mpu_M7_SetRegionConfig_Activity */
void Platform_Mpu_M7_SetRegionConfig(uint8 u8RegionNum, const Platform_Mpu_M7_RegionConfigType * const pUserConfigPtr)
{
#if (PLATFORM_DEV_ERROR_DETECT == STD_ON)
#if (PLATFORM_MULTICORE_SUPPORT == STD_ON)
    uint8 u8UserId;

    /* In multi-partition systems on the same core, only one partition can configure the MPU instance */
    /* This check ensures MPU is configured by the partition it belongs to */
    u8UserId = (uint8)Platform_GetCoreID();
    if ((Std_ReturnType)E_NOT_OK == Platform_CheckNullPtrCfg(u8UserId))
    {
        (void)Det_ReportError((uint16)CDD_PLATFORM_MODULE_ID, 0U, PLATFORM_MPU_M7_SET_REGION_CONFIG_ID, PLATFORM_E_PARAM_CONFIG);
    }
    else if (Platform_Config[u8UserId]->pIpwConfig->Platform_Ipw_pMpuConfig == NULL_PTR)
    {
        (void)Det_ReportError((uint16)CDD_PLATFORM_MODULE_ID, 0U, PLATFORM_MPU_M7_SET_REGION_CONFIG_ID, PLATFORM_E_PARAM_CONFIG);
    }
    else
#endif
#endif
    {
        Platform_Ipw_Mpu_M7_SetRegionConfig(u8RegionNum, pUserConfigPtr);
    }
}

/**
 * @brief         Enables or disabled a specific region
 *
 * @details       This function is Reentrant
 *
 * @param[in]     u8RegionNum : Region to be modified
 * @param[in]     bEnable  : Specifies wheter the region is enabled or disabled
 * @return        void
 *
 * @api
 *
 * @pre
 *
 * */
/* @implements         Platform_Mpu_M7_EnableRegion_Activity */
void Platform_Mpu_M7_EnableRegion(uint8 u8RegionNum, boolean bEnable)
{
#if (PLATFORM_DEV_ERROR_DETECT == STD_ON)
#if (PLATFORM_MULTICORE_SUPPORT == STD_ON)
    uint8 u8UserId;

    /* In multi-partition systems on the same core, only one partition can configure the MPU instance */
    /* This check ensures MPU is configured by the partition it belongs to */
    u8UserId = (uint8)Platform_GetCoreID();
    if ((Std_ReturnType)E_NOT_OK == Platform_CheckNullPtrCfg(u8UserId))
    {
        (void)Det_ReportError((uint16)CDD_PLATFORM_MODULE_ID, 0U, PLATFORM_MPU_M7_ENABLE_REGION_ID, PLATFORM_E_PARAM_CONFIG);
    }
    else if (Platform_Config[u8UserId]->pIpwConfig->Platform_Ipw_pMpuConfig == NULL_PTR)
    {
        (void)Det_ReportError((uint16)CDD_PLATFORM_MODULE_ID, 0U, PLATFORM_MPU_M7_ENABLE_REGION_ID, PLATFORM_E_PARAM_CONFIG);
    }
    else
#endif
#endif
    {
        Platform_Ipw_Mpu_M7_EnableRegion(u8RegionNum, bEnable);
    }
}

/**
 * @brief         Modify the access rights for a specific region
 *
 * @details       This function is Reentrant
 *
 * @param[in]     u8RegionNum : Region to be modified
 * @param[in]     eRights     : Specifies the new access rights
 * @return        void
 *
 * @api
 *
 * @pre
 *
 * */
/* @implements         Platform_Mpu_M7_SetAccessRight_Activity */
void Platform_Mpu_M7_SetAccessRight(uint8 u8RegionNum, Platform_Mpu_M7_AccessRightsType eRights)
{
#if (PLATFORM_DEV_ERROR_DETECT == STD_ON)
#if (PLATFORM_MULTICORE_SUPPORT == STD_ON)
    uint8 u8UserId;

    /* In multi-partition systems on the same core, only one partition can configure the MPU instance */
    /* This check ensures MPU is configured by the partition it belongs to */
    u8UserId = (uint8)Platform_GetCoreID();
    if ((Std_ReturnType)E_NOT_OK == Platform_CheckNullPtrCfg(u8UserId))
    {
        (void)Det_ReportError((uint16)CDD_PLATFORM_MODULE_ID, 0U, PLATFORM_MPU_M7_SET_ACCESS_RIGHT_ID, PLATFORM_E_PARAM_CONFIG);
    }
    else if (Platform_Config[u8UserId]->pIpwConfig->Platform_Ipw_pMpuConfig == NULL_PTR)
    {
        (void)Det_ReportError((uint16)CDD_PLATFORM_MODULE_ID, 0U, PLATFORM_MPU_M7_SET_ACCESS_RIGHT_ID, PLATFORM_E_PARAM_CONFIG);
    }
    else
#endif
#endif
    {
        Platform_Ipw_Mpu_M7_SetAccessRight(u8RegionNum, eRights);
    }
}

/**
 * @brief         Retrieve error details
 *
 * @details       This function is Reentrant
 *
 * @return        Std_ReturnType
 * @retval        E_OK                    if an error was present
 * @retval        E_NOT_OK                otherwise
 *
 * @api
 *
 * @pre
 *
 * */
/* @implements         Platform_Mpu_M7_GetErrorDetails_Activity */
Std_ReturnType Platform_Mpu_M7_GetErrorDetails(Platform_Mpu_M7_ErrorDetailsType * pErrorDetails)
{
    Std_ReturnType retval = (Std_ReturnType)E_NOT_OK;
    boolean bErr;

#if (PLATFORM_DEV_ERROR_DETECT == STD_ON)
#if (PLATFORM_MULTICORE_SUPPORT == STD_ON)
    uint8 u8UserId;

    /* In multi-partition systems on the same core, only one partition can configure the MPU instance */
    /* This check ensures MPU is configured by the partition it belongs to */
    u8UserId = (uint8)Platform_GetCoreID();
    if ((Std_ReturnType)E_NOT_OK == Platform_CheckNullPtrCfg(u8UserId))
    {
        (void)Det_ReportError((uint16)CDD_PLATFORM_MODULE_ID, 0U, PLATFORM_MPU_M7_GET_ERROR_DETAILS_ID, PLATFORM_E_PARAM_CONFIG);
        bErr = (Std_ReturnType)E_NOT_OK;
    }
    else if (Platform_Config[u8UserId]->pIpwConfig->Platform_Ipw_pMpuConfig == NULL_PTR)
    {
        (void)Det_ReportError((uint16)CDD_PLATFORM_MODULE_ID, 0U, PLATFORM_MPU_M7_GET_ERROR_DETAILS_ID, PLATFORM_E_PARAM_CONFIG);
        bErr = (Std_ReturnType)E_NOT_OK;
    }
    else
#endif
#endif
    {
        bErr = Platform_Ipw_Mpu_M7_GetErrorDetails(pErrorDetails);

        if (TRUE == bErr)
        {
            retval = (Std_ReturnType)E_OK;
        }
        else
        {
            retval = (Std_ReturnType)E_NOT_OK;
        }
    }

    return retval;
}

#endif /* #if (STD_ON == PLATFORM_ENABLE_MPU_M7)  */



#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
