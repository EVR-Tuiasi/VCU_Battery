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

#ifndef S32K37_DSPI_MSC_WRAPPER_H
#define S32K37_DSPI_MSC_WRAPPER_H

/**
*   @file    S32K37_DSPI_MSC_WRAPPER.h
*
*   @brief   DSPI IP driver types header file.
*   @details DSPI IP driver types header file.

*   @addtogroup DSPI_DRIVER Dspi Driver
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
#include "S32K37_DSPI_MSC.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/* ----------------------------------------------------------------------------
   -- DSPI_MSC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DSPI_MSC_Peripheral_Access_Layer DSPI_MSC Peripheral Access Layer
 * @{
 */

/** DSPI_MSC - Size of Registers Arrays */
#define DSPI_MODE_CTAR_CTAR_COUNT             DSPI_MSC_MODE_CTAR_CTAR_COUNT
#define DSPI_TXFR_COUNT                       DSPI_MSC_TXFR_COUNT
#define DSPI_RXFR_COUNT                       DSPI_MSC_RXFR_COUNT
#define DSPI_CTARE_COUNT                      DSPI_MSC_CTARE_COUNT

/** DSPI_MSC - Register Layout Typedef */
typedef DSPI_MSC_Type DSPI_Type;
typedef DSPI_MSC_MemMapPtr DSPI_MemMapPtr;

/** Number of instances of the DSPI_MSC module. */
#define DSPI_INSTANCE_COUNT                  DSPI_MSC_INSTANCE_COUNT

/* DSPI_MSC - Peripheral instance base addresses */
/** Peripheral DSPI_MSC base address */
#define IP_DSPI_BASE                         IP_DSPI_MSC_BASE
/** Peripheral DSPI_MSC base pointer */
#define IP_DSPI                              IP_DSPI_MSC
/** Array initializer of DSPI_MSC peripheral base addresses */
#define IP_DSPI_BASE_ADDRS                   IP_DSPI_MSC_BASE_ADDRS
/** Array initializer of DSPI_MSC peripheral base pointers */
#define IP_DSPI_BASE_PTRS                    IP_DSPI_MSC_BASE_PTRS

/* ----------------------------------------------------------------------------
   -- DSPI_MSC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DSPI_MSC_Register_Masks DSPI_MSC Register Masks
 * @{
 */

/*! @name MCR - Module Configuration Register */
/*! @{ */

#define DSPI_MCR_HALT_MASK                   DSPI_MSC_MCR_HALT_MASK
#define DSPI_MCR_HALT_SHIFT                  DSPI_MSC_MCR_HALT_SHIFT
#define DSPI_MCR_HALT_WIDTH                  DSPI_MSC_MCR_HALT_WIDTH
#define DSPI_MCR_HALT(x)                     DSPI_MSC_MCR_HALT(x)

#define DSPI_MCR_PES_MASK                    DSPI_MSC_MCR_PES_MASK
#define DSPI_MCR_PES_SHIFT                   DSPI_MSC_MCR_PES_SHIFT
#define DSPI_MCR_PES_WIDTH                   DSPI_MSC_MCR_PES_WIDTH
#define DSPI_MCR_PES(x)                      DSPI_MSC_MCR_PES(x)

#define DSPI_MCR_XSPI_MASK                   DSPI_MSC_MCR_XSPI_MASK
#define DSPI_MCR_XSPI_SHIFT                  DSPI_MSC_MCR_XSPI_SHIFT
#define DSPI_MCR_XSPI_WIDTH                  DSPI_MSC_MCR_XSPI_WIDTH
#define DSPI_MCR_XSPI(x)                     DSPI_MSC_MCR_XSPI(x)

#define DSPI_MCR_CLR_RXF_MASK                DSPI_MSC_MCR_CLR_RXF_MASK
#define DSPI_MCR_CLR_RXF_SHIFT               DSPI_MSC_MCR_CLR_RXF_SHIFT
#define DSPI_MCR_CLR_RXF_WIDTH               DSPI_MSC_MCR_CLR_RXF_WIDTH
#define DSPI_MCR_CLR_RXF(x)                  DSPI_MSC_MCR_CLR_RXF(x)

#define DSPI_MCR_CLR_TXF_MASK                DSPI_MSC_MCR_CLR_TXF_MASK
#define DSPI_MCR_CLR_TXF_SHIFT               DSPI_MSC_MCR_CLR_TXF_SHIFT
#define DSPI_MCR_CLR_TXF_WIDTH               DSPI_MSC_MCR_CLR_TXF_WIDTH
#define DSPI_MCR_CLR_TXF(x)                  DSPI_MSC_MCR_CLR_TXF(x)

#define DSPI_MCR_DIS_RXF_MASK                DSPI_MSC_MCR_DIS_RXF_MASK
#define DSPI_MCR_DIS_RXF_SHIFT               DSPI_MSC_MCR_DIS_RXF_SHIFT
#define DSPI_MCR_DIS_RXF_WIDTH               DSPI_MSC_MCR_DIS_RXF_WIDTH
#define DSPI_MCR_DIS_RXF(x)                  DSPI_MSC_MCR_DIS_RXF(x)

#define DSPI_MCR_DIS_TXF_MASK                DSPI_MSC_MCR_DIS_TXF_MASK
#define DSPI_MCR_DIS_TXF_SHIFT               DSPI_MSC_MCR_DIS_TXF_SHIFT
#define DSPI_MCR_DIS_TXF_WIDTH               DSPI_MSC_MCR_DIS_TXF_WIDTH
#define DSPI_MCR_DIS_TXF(x)                  DSPI_MSC_MCR_DIS_TXF(x)

#define DSPI_MCR_MDIS_MASK                   DSPI_MSC_MCR_MDIS_MASK
#define DSPI_MCR_MDIS_SHIFT                  DSPI_MSC_MCR_MDIS_SHIFT
#define DSPI_MCR_MDIS_WIDTH                  DSPI_MSC_MCR_MDIS_WIDTH
#define DSPI_MCR_MDIS(x)                     DSPI_MSC_MCR_MDIS(x)

#define DSPI_MCR_PCSIS_MASK                  DSPI_MSC_MCR_PCSIS_MASK
#define DSPI_MCR_PCSIS_SHIFT                 DSPI_MSC_MCR_PCSIS_SHIFT
#define DSPI_MCR_PCSIS_WIDTH                 DSPI_MSC_MCR_PCSIS_WIDTH
#define DSPI_MCR_PCSIS(x)                    DSPI_MSC_MCR_PCSIS(x)

#define DSPI_MCR_ROOE_MASK                   DSPI_MSC_MCR_ROOE_MASK
#define DSPI_MCR_ROOE_SHIFT                  DSPI_MSC_MCR_ROOE_SHIFT
#define DSPI_MCR_ROOE_WIDTH                  DSPI_MSC_MCR_ROOE_WIDTH
#define DSPI_MCR_ROOE(x)                     DSPI_MSC_MCR_ROOE(x)

#define DSPI_MCR_FRZ_MASK                    DSPI_MSC_MCR_FRZ_MASK
#define DSPI_MCR_FRZ_SHIFT                   DSPI_MSC_MCR_FRZ_SHIFT
#define DSPI_MCR_FRZ_WIDTH                   DSPI_MSC_MCR_FRZ_WIDTH
#define DSPI_MCR_FRZ(x)                      DSPI_MSC_MCR_FRZ(x)

#define DSPI_MCR_DCONF_MASK                  DSPI_MSC_MCR_DCONF_MASK
#define DSPI_MCR_DCONF_SHIFT                 DSPI_MSC_MCR_DCONF_SHIFT
#define DSPI_MCR_DCONF_WIDTH                 DSPI_MSC_MCR_DCONF_WIDTH
#define DSPI_MCR_DCONF(x)                    DSPI_MSC_MCR_DCONF(x)

#define DSPI_MCR_CONT_SCKE_MASK              DSPI_MSC_MCR_CONT_SCKE_MASK
#define DSPI_MCR_CONT_SCKE_SHIFT             DSPI_MSC_MCR_CONT_SCKE_SHIFT
#define DSPI_MCR_CONT_SCKE_WIDTH             DSPI_MSC_MCR_CONT_SCKE_WIDTH
#define DSPI_MCR_CONT_SCKE(x)                DSPI_MSC_MCR_CONT_SCKE(x)

#define DSPI_MCR_MSTR_MASK                   DSPI_MSC_MCR_MSTR_MASK
#define DSPI_MCR_MSTR_SHIFT                  DSPI_MSC_MCR_MSTR_SHIFT
#define DSPI_MCR_MSTR_WIDTH                  DSPI_MSC_MCR_MSTR_WIDTH
#define DSPI_MCR_MSTR(x)                     DSPI_MSC_MCR_MSTR(x)
/*! @} */

/*! @name TCR - Transfer Count Register */
/*! @{ */

#define DSPI_TCR_SPI_TCNT_MASK               DSPI_MSC_TCR_SPI_TCNT_MASK
#define DSPI_TCR_SPI_TCNT_SHIFT              DSPI_MSC_TCR_SPI_TCNT_SHIFT
#define DSPI_TCR_SPI_TCNT_WIDTH              DSPI_MSC_TCR_SPI_TCNT_WIDTH
#define DSPI_TCR_SPI_TCNT(x)                 DSPI_MSC_TCR_SPI_TCNT(x)
/*! @} */

/*! @name CTAR - Clock and Transfer Attributes Register (In Master Mode) */
/*! @{ */

#define DSPI_CTAR_BR_MASK                    DSPI_MSC_CTAR_BR_MASK
#define DSPI_CTAR_BR_SHIFT                   DSPI_MSC_CTAR_BR_SHIFT
#define DSPI_CTAR_BR_WIDTH                   DSPI_MSC_CTAR_BR_WIDTH
#define DSPI_CTAR_BR(x)                      DSPI_MSC_CTAR_BR(x)

#define DSPI_CTAR_DT_MASK                    DSPI_MSC_CTAR_DT_MASK
#define DSPI_CTAR_DT_SHIFT                   DSPI_MSC_CTAR_DT_SHIFT
#define DSPI_CTAR_DT_WIDTH                   DSPI_MSC_CTAR_DT_WIDTH
#define DSPI_CTAR_DT(x)                      DSPI_MSC_CTAR_DT(x)

#define DSPI_CTAR_ASC_MASK                   DSPI_MSC_CTAR_ASC_MASK
#define DSPI_CTAR_ASC_SHIFT                  DSPI_MSC_CTAR_ASC_SHIFT
#define DSPI_CTAR_ASC_WIDTH                  DSPI_MSC_CTAR_ASC_WIDTH
#define DSPI_CTAR_ASC(x)                     DSPI_MSC_CTAR_ASC(x)

#define DSPI_CTAR_CSSCK_MASK                 DSPI_MSC_CTAR_CSSCK_MASK
#define DSPI_CTAR_CSSCK_SHIFT                DSPI_MSC_CTAR_CSSCK_SHIFT
#define DSPI_CTAR_CSSCK_WIDTH                DSPI_MSC_CTAR_CSSCK_WIDTH
#define DSPI_CTAR_CSSCK(x)                   DSPI_MSC_CTAR_CSSCK(x)

#define DSPI_CTAR_PBR_MASK                   DSPI_MSC_CTAR_PBR_MASK
#define DSPI_CTAR_PBR_SHIFT                  DSPI_MSC_CTAR_PBR_SHIFT
#define DSPI_CTAR_PBR_WIDTH                  DSPI_MSC_CTAR_PBR_WIDTH
#define DSPI_CTAR_PBR(x)                     DSPI_MSC_CTAR_PBR(x)

#define DSPI_CTAR_PDT_MASK                   DSPI_MSC_CTAR_PDT_MASK
#define DSPI_CTAR_PDT_SHIFT                  DSPI_MSC_CTAR_PDT_SHIFT
#define DSPI_CTAR_PDT_WIDTH                  DSPI_MSC_CTAR_PDT_WIDTH
#define DSPI_CTAR_PDT(x)                     DSPI_MSC_CTAR_PDT(x)

#define DSPI_CTAR_PASC_MASK                  DSPI_MSC_CTAR_PASC_MASK
#define DSPI_CTAR_PASC_SHIFT                 DSPI_MSC_CTAR_PASC_SHIFT
#define DSPI_CTAR_PASC_WIDTH                 DSPI_MSC_CTAR_PASC_WIDTH
#define DSPI_CTAR_PASC(x)                    DSPI_MSC_CTAR_PASC(x)

#define DSPI_CTAR_PCSSCK_MASK                DSPI_MSC_CTAR_PCSSCK_MASK
#define DSPI_CTAR_PCSSCK_SHIFT               DSPI_MSC_CTAR_PCSSCK_SHIFT
#define DSPI_CTAR_PCSSCK_WIDTH               DSPI_MSC_CTAR_PCSSCK_WIDTH
#define DSPI_CTAR_PCSSCK(x)                  DSPI_MSC_CTAR_PCSSCK(x)

#define DSPI_CTAR_LSBFE_MASK                 DSPI_MSC_CTAR_LSBFE_MASK
#define DSPI_CTAR_LSBFE_SHIFT                DSPI_MSC_CTAR_LSBFE_SHIFT
#define DSPI_CTAR_LSBFE_WIDTH                DSPI_MSC_CTAR_LSBFE_WIDTH
#define DSPI_CTAR_LSBFE(x)                   DSPI_MSC_CTAR_LSBFE(x)

#define DSPI_CTAR_CPHA_MASK                  DSPI_MSC_CTAR_CPHA_MASK
#define DSPI_CTAR_CPHA_SHIFT                 DSPI_MSC_CTAR_CPHA_SHIFT
#define DSPI_CTAR_CPHA_WIDTH                 DSPI_MSC_CTAR_CPHA_WIDTH
#define DSPI_CTAR_CPHA(x)                    DSPI_MSC_CTAR_CPHA(x)

#define DSPI_CTAR_CPOL_MASK                  DSPI_MSC_CTAR_CPOL_MASK
#define DSPI_CTAR_CPOL_SHIFT                 DSPI_MSC_CTAR_CPOL_SHIFT
#define DSPI_CTAR_CPOL_WIDTH                 DSPI_MSC_CTAR_CPOL_WIDTH
#define DSPI_CTAR_CPOL(x)                    DSPI_MSC_CTAR_CPOL(x)

#define DSPI_CTAR_FMSZ_MASK                  DSPI_MSC_CTAR_FMSZ_MASK
#define DSPI_CTAR_FMSZ_SHIFT                 DSPI_MSC_CTAR_FMSZ_SHIFT
#define DSPI_CTAR_FMSZ_WIDTH                 DSPI_MSC_CTAR_FMSZ_WIDTH
#define DSPI_CTAR_FMSZ(x)                    DSPI_MSC_CTAR_FMSZ(x)

#define DSPI_CTAR_DBR_MASK                   DSPI_MSC_CTAR_DBR_MASK
#define DSPI_CTAR_DBR_SHIFT                  DSPI_MSC_CTAR_DBR_SHIFT
#define DSPI_CTAR_DBR_WIDTH                  DSPI_MSC_CTAR_DBR_WIDTH
#define DSPI_CTAR_DBR(x)                     DSPI_MSC_CTAR_DBR(x)
/*! @} */

/*! @name SR - Status Register */
/*! @{ */

#define DSPI_SR_POPNXTPTR_MASK               DSPI_MSC_SR_POPNXTPTR_MASK
#define DSPI_SR_POPNXTPTR_SHIFT              DSPI_MSC_SR_POPNXTPTR_SHIFT
#define DSPI_SR_POPNXTPTR_WIDTH              DSPI_MSC_SR_POPNXTPTR_WIDTH
#define DSPI_SR_POPNXTPTR(x)                 DSPI_MSC_SR_POPNXTPTR(x)

#define DSPI_SR_RXCTR_MASK                   DSPI_MSC_SR_RXCTR_MASK
#define DSPI_SR_RXCTR_SHIFT                  DSPI_MSC_SR_RXCTR_SHIFT
#define DSPI_SR_RXCTR_WIDTH                  DSPI_MSC_SR_RXCTR_WIDTH
#define DSPI_SR_RXCTR(x)                     DSPI_MSC_SR_RXCTR(x)

#define DSPI_SR_TXNXTPTR_MASK                DSPI_MSC_SR_TXNXTPTR_MASK
#define DSPI_SR_TXNXTPTR_SHIFT               DSPI_MSC_SR_TXNXTPTR_SHIFT
#define DSPI_SR_TXNXTPTR_WIDTH               DSPI_MSC_SR_TXNXTPTR_WIDTH
#define DSPI_SR_TXNXTPTR(x)                  DSPI_MSC_SR_TXNXTPTR(x)

#define DSPI_SR_TXCTR_MASK                   DSPI_MSC_SR_TXCTR_MASK
#define DSPI_SR_TXCTR_SHIFT                  DSPI_MSC_SR_TXCTR_SHIFT
#define DSPI_SR_TXCTR_WIDTH                  DSPI_MSC_SR_TXCTR_WIDTH
#define DSPI_SR_TXCTR(x)                     DSPI_MSC_SR_TXCTR(x)

#define DSPI_SR_CMDFFF_MASK                  DSPI_MSC_SR_CMDFFF_MASK
#define DSPI_SR_CMDFFF_SHIFT                 DSPI_MSC_SR_CMDFFF_SHIFT
#define DSPI_SR_CMDFFF_WIDTH                 DSPI_MSC_SR_CMDFFF_WIDTH
#define DSPI_SR_CMDFFF(x)                    DSPI_MSC_SR_CMDFFF(x)

#define DSPI_SR_RFDF_MASK                    DSPI_MSC_SR_RFDF_MASK
#define DSPI_SR_RFDF_SHIFT                   DSPI_MSC_SR_RFDF_SHIFT
#define DSPI_SR_RFDF_WIDTH                   DSPI_MSC_SR_RFDF_WIDTH
#define DSPI_SR_RFDF(x)                      DSPI_MSC_SR_RFDF(x)

#define DSPI_SR_TFIWF_MASK                   DSPI_MSC_SR_TFIWF_MASK
#define DSPI_SR_TFIWF_SHIFT                  DSPI_MSC_SR_TFIWF_SHIFT
#define DSPI_SR_TFIWF_WIDTH                  DSPI_MSC_SR_TFIWF_WIDTH
#define DSPI_SR_TFIWF(x)                     DSPI_MSC_SR_TFIWF(x)

#define DSPI_SR_RFOF_MASK                    DSPI_MSC_SR_RFOF_MASK
#define DSPI_SR_RFOF_SHIFT                   DSPI_MSC_SR_RFOF_SHIFT
#define DSPI_SR_RFOF_WIDTH                   DSPI_MSC_SR_RFOF_WIDTH
#define DSPI_SR_RFOF(x)                      DSPI_MSC_SR_RFOF(x)

#define DSPI_SR_DDIF_MASK                    DSPI_MSC_SR_DDIF_MASK
#define DSPI_SR_DDIF_SHIFT                   DSPI_MSC_SR_DDIF_SHIFT
#define DSPI_SR_DDIF_WIDTH                   DSPI_MSC_SR_DDIF_WIDTH
#define DSPI_SR_DDIF(x)                      DSPI_MSC_SR_DDIF(x)

#define DSPI_SR_SPEF_MASK                    DSPI_MSC_SR_SPEF_MASK
#define DSPI_SR_SPEF_SHIFT                   DSPI_MSC_SR_SPEF_SHIFT
#define DSPI_SR_SPEF_WIDTH                   DSPI_MSC_SR_SPEF_WIDTH
#define DSPI_SR_SPEF(x)                      DSPI_MSC_SR_SPEF(x)

#define DSPI_SR_DPEF_MASK                    DSPI_MSC_SR_DPEF_MASK
#define DSPI_SR_DPEF_SHIFT                   DSPI_MSC_SR_DPEF_SHIFT
#define DSPI_SR_DPEF_WIDTH                   DSPI_MSC_SR_DPEF_WIDTH
#define DSPI_SR_DPEF(x)                      DSPI_MSC_SR_DPEF(x)

#define DSPI_SR_CMDTCF_MASK                  DSPI_MSC_SR_CMDTCF_MASK
#define DSPI_SR_CMDTCF_SHIFT                 DSPI_MSC_SR_CMDTCF_SHIFT
#define DSPI_SR_CMDTCF_WIDTH                 DSPI_MSC_SR_CMDTCF_WIDTH
#define DSPI_SR_CMDTCF(x)                    DSPI_MSC_SR_CMDTCF(x)

#define DSPI_SR_BSYF_MASK                    DSPI_MSC_SR_BSYF_MASK
#define DSPI_SR_BSYF_SHIFT                   DSPI_MSC_SR_BSYF_SHIFT
#define DSPI_SR_BSYF_WIDTH                   DSPI_MSC_SR_BSYF_WIDTH
#define DSPI_SR_BSYF(x)                      DSPI_MSC_SR_BSYF(x)

#define DSPI_SR_TFFF_MASK                    DSPI_MSC_SR_TFFF_MASK
#define DSPI_SR_TFFF_SHIFT                   DSPI_MSC_SR_TFFF_SHIFT
#define DSPI_SR_TFFF_WIDTH                   DSPI_MSC_SR_TFFF_WIDTH
#define DSPI_SR_TFFF(x)                      DSPI_MSC_SR_TFFF(x)

#define DSPI_SR_DSITCF_MASK                  DSPI_MSC_SR_DSITCF_MASK
#define DSPI_SR_DSITCF_SHIFT                 DSPI_MSC_SR_DSITCF_SHIFT
#define DSPI_SR_DSITCF_WIDTH                 DSPI_MSC_SR_DSITCF_WIDTH
#define DSPI_SR_DSITCF(x)                    DSPI_MSC_SR_DSITCF(x)

#define DSPI_SR_EOQF_MASK                    DSPI_MSC_SR_EOQF_MASK
#define DSPI_SR_EOQF_SHIFT                   DSPI_MSC_SR_EOQF_SHIFT
#define DSPI_SR_EOQF_WIDTH                   DSPI_MSC_SR_EOQF_WIDTH
#define DSPI_SR_EOQF(x)                      DSPI_MSC_SR_EOQF(x)

#define DSPI_SR_SPITCF_MASK                  DSPI_MSC_SR_SPITCF_MASK
#define DSPI_SR_SPITCF_SHIFT                 DSPI_MSC_SR_SPITCF_SHIFT
#define DSPI_SR_SPITCF_WIDTH                 DSPI_MSC_SR_SPITCF_WIDTH
#define DSPI_SR_SPITCF(x)                    DSPI_MSC_SR_SPITCF(x)

#define DSPI_SR_TXRXS_MASK                   DSPI_MSC_SR_TXRXS_MASK
#define DSPI_SR_TXRXS_SHIFT                  DSPI_MSC_SR_TXRXS_SHIFT
#define DSPI_SR_TXRXS_WIDTH                  DSPI_MSC_SR_TXRXS_WIDTH
#define DSPI_SR_TXRXS(x)                     DSPI_MSC_SR_TXRXS(x)

#define DSPI_SR_TCF_MASK                     DSPI_MSC_SR_TCF_MASK
#define DSPI_SR_TCF_SHIFT                    DSPI_MSC_SR_TCF_SHIFT
#define DSPI_SR_TCF_WIDTH                    DSPI_MSC_SR_TCF_WIDTH
#define DSPI_SR_TCF(x)                       DSPI_MSC_SR_TCF(x)
/*! @} */

/*! @name RSER - DMA/Interrupt Request Select and Enable Register */
/*! @{ */

#define DSPI_RSER_DDIF_DIRS_MASK             DSPI_MSC_RSER_DDIF_DIRS_MASK
#define DSPI_RSER_DDIF_DIRS_SHIFT            DSPI_MSC_RSER_DDIF_DIRS_SHIFT
#define DSPI_RSER_DDIF_DIRS_WIDTH            DSPI_MSC_RSER_DDIF_DIRS_WIDTH
#define DSPI_RSER_DDIF_DIRS(x)               DSPI_MSC_RSER_DDIF_DIRS(x)

#define DSPI_RSER_CMDFFF_DIRS_MASK           DSPI_MSC_RSER_CMDFFF_DIRS_MASK
#define DSPI_RSER_CMDFFF_DIRS_SHIFT          DSPI_MSC_RSER_CMDFFF_DIRS_SHIFT
#define DSPI_RSER_CMDFFF_DIRS_WIDTH          DSPI_MSC_RSER_CMDFFF_DIRS_WIDTH
#define DSPI_RSER_CMDFFF_DIRS(x)             DSPI_MSC_RSER_CMDFFF_DIRS(x)

#define DSPI_RSER_RFDF_DIRS_MASK             DSPI_MSC_RSER_RFDF_DIRS_MASK
#define DSPI_RSER_RFDF_DIRS_SHIFT            DSPI_MSC_RSER_RFDF_DIRS_SHIFT
#define DSPI_RSER_RFDF_DIRS_WIDTH            DSPI_MSC_RSER_RFDF_DIRS_WIDTH
#define DSPI_RSER_RFDF_DIRS(x)               DSPI_MSC_RSER_RFDF_DIRS(x)

#define DSPI_RSER_RFDF_RE_MASK               DSPI_MSC_RSER_RFDF_RE_MASK
#define DSPI_RSER_RFDF_RE_SHIFT              DSPI_MSC_RSER_RFDF_RE_SHIFT
#define DSPI_RSER_RFDF_RE_WIDTH              DSPI_MSC_RSER_RFDF_RE_WIDTH
#define DSPI_RSER_RFDF_RE(x)                 DSPI_MSC_RSER_RFDF_RE(x)

#define DSPI_RSER_TFIWF_RE_MASK              DSPI_MSC_RSER_TFIWF_RE_MASK
#define DSPI_RSER_TFIWF_RE_SHIFT             DSPI_MSC_RSER_TFIWF_RE_SHIFT
#define DSPI_RSER_TFIWF_RE_WIDTH             DSPI_MSC_RSER_TFIWF_RE_WIDTH
#define DSPI_RSER_TFIWF_RE(x)                DSPI_MSC_RSER_TFIWF_RE(x)

#define DSPI_RSER_RFOF_RE_MASK               DSPI_MSC_RSER_RFOF_RE_MASK
#define DSPI_RSER_RFOF_RE_SHIFT              DSPI_MSC_RSER_RFOF_RE_SHIFT
#define DSPI_RSER_RFOF_RE_WIDTH              DSPI_MSC_RSER_RFOF_RE_WIDTH
#define DSPI_RSER_RFOF_RE(x)                 DSPI_MSC_RSER_RFOF_RE(x)

#define DSPI_RSER_DDIF_RE_MASK               DSPI_MSC_RSER_DDIF_RE_MASK
#define DSPI_RSER_DDIF_RE_SHIFT              DSPI_MSC_RSER_DDIF_RE_SHIFT
#define DSPI_RSER_DDIF_RE_WIDTH              DSPI_MSC_RSER_DDIF_RE_WIDTH
#define DSPI_RSER_DDIF_RE(x)                 DSPI_MSC_RSER_DDIF_RE(x)

#define DSPI_RSER_SPEF_RE_MASK               DSPI_MSC_RSER_SPEF_RE_MASK
#define DSPI_RSER_SPEF_RE_SHIFT              DSPI_MSC_RSER_SPEF_RE_SHIFT
#define DSPI_RSER_SPEF_RE_WIDTH              DSPI_MSC_RSER_SPEF_RE_WIDTH
#define DSPI_RSER_SPEF_RE(x)                 DSPI_MSC_RSER_SPEF_RE(x)

#define DSPI_RSER_DPEF_RE_MASK               DSPI_MSC_RSER_DPEF_RE_MASK
#define DSPI_RSER_DPEF_RE_SHIFT              DSPI_MSC_RSER_DPEF_RE_SHIFT
#define DSPI_RSER_DPEF_RE_WIDTH              DSPI_MSC_RSER_DPEF_RE_WIDTH
#define DSPI_RSER_DPEF_RE(x)                 DSPI_MSC_RSER_DPEF_RE(x)

#define DSPI_RSER_CMDTCF_RE_MASK             DSPI_MSC_RSER_CMDTCF_RE_MASK
#define DSPI_RSER_CMDTCF_RE_SHIFT            DSPI_MSC_RSER_CMDTCF_RE_SHIFT
#define DSPI_RSER_CMDTCF_RE_WIDTH            DSPI_MSC_RSER_CMDTCF_RE_WIDTH
#define DSPI_RSER_CMDTCF_RE(x)               DSPI_MSC_RSER_CMDTCF_RE(x)

#define DSPI_RSER_TFFF_DIRS_MASK             DSPI_MSC_RSER_TFFF_DIRS_MASK
#define DSPI_RSER_TFFF_DIRS_SHIFT            DSPI_MSC_RSER_TFFF_DIRS_SHIFT
#define DSPI_RSER_TFFF_DIRS_WIDTH            DSPI_MSC_RSER_TFFF_DIRS_WIDTH
#define DSPI_RSER_TFFF_DIRS(x)               DSPI_MSC_RSER_TFFF_DIRS(x)

#define DSPI_RSER_TFFF_RE_MASK               DSPI_MSC_RSER_TFFF_RE_MASK
#define DSPI_RSER_TFFF_RE_SHIFT              DSPI_MSC_RSER_TFFF_RE_SHIFT
#define DSPI_RSER_TFFF_RE_WIDTH              DSPI_MSC_RSER_TFFF_RE_WIDTH
#define DSPI_RSER_TFFF_RE(x)                 DSPI_MSC_RSER_TFFF_RE(x)

#define DSPI_RSER_DSITCF_RE_MASK             DSPI_MSC_RSER_DSITCF_RE_MASK
#define DSPI_RSER_DSITCF_RE_SHIFT            DSPI_MSC_RSER_DSITCF_RE_SHIFT
#define DSPI_RSER_DSITCF_RE_WIDTH            DSPI_MSC_RSER_DSITCF_RE_WIDTH
#define DSPI_RSER_DSITCF_RE(x)               DSPI_MSC_RSER_DSITCF_RE(x)

#define DSPI_RSER_EOQF_RE_MASK               DSPI_MSC_RSER_EOQF_RE_MASK
#define DSPI_RSER_EOQF_RE_SHIFT              DSPI_MSC_RSER_EOQF_RE_SHIFT
#define DSPI_RSER_EOQF_RE_WIDTH              DSPI_MSC_RSER_EOQF_RE_WIDTH
#define DSPI_RSER_EOQF_RE(x)                 DSPI_MSC_RSER_EOQF_RE(x)

#define DSPI_RSER_SPITCF_RE_MASK             DSPI_MSC_RSER_SPITCF_RE_MASK
#define DSPI_RSER_SPITCF_RE_SHIFT            DSPI_MSC_RSER_SPITCF_RE_SHIFT
#define DSPI_RSER_SPITCF_RE_WIDTH            DSPI_MSC_RSER_SPITCF_RE_WIDTH
#define DSPI_RSER_SPITCF_RE(x)               DSPI_MSC_RSER_SPITCF_RE(x)

#define DSPI_RSER_CMDFFF_RE_MASK             DSPI_MSC_RSER_CMDFFF_RE_MASK
#define DSPI_RSER_CMDFFF_RE_SHIFT            DSPI_MSC_RSER_CMDFFF_RE_SHIFT
#define DSPI_RSER_CMDFFF_RE_WIDTH            DSPI_MSC_RSER_CMDFFF_RE_WIDTH
#define DSPI_RSER_CMDFFF_RE(x)               DSPI_MSC_RSER_CMDFFF_RE(x)

#define DSPI_RSER_TCF_RE_MASK                DSPI_MSC_RSER_TCF_RE_MASK
#define DSPI_RSER_TCF_RE_SHIFT               DSPI_MSC_RSER_TCF_RE_SHIFT
#define DSPI_RSER_TCF_RE_WIDTH               DSPI_MSC_RSER_TCF_RE_WIDTH
#define DSPI_RSER_TCF_RE(x)                  DSPI_MSC_RSER_TCF_RE(x)
/*! @} */

/*! @name CMD - DSPI_MSC_CMD register */
/*! @{ */

#define DSPI_CMD_CMD_MASK                    DSPI_MSC_CMD_CMD_MASK
#define DSPI_CMD_CMD_SHIFT                   DSPI_MSC_CMD_CMD_SHIFT
#define DSPI_CMD_CMD_WIDTH                   DSPI_MSC_CMD_CMD_WIDTH
#define DSPI_CMD_CMD(x)                      DSPI_MSC_CMD_CMD(x)
/*! @} */

/*! @name TX - DSPI_MSC_TX register */
/*! @{ */

#define DSPI_TX_TX_MASK                      DSPI_MSC_TX_TX_MASK
#define DSPI_TX_TX_SHIFT                     DSPI_MSC_TX_TX_SHIFT
#define DSPI_TX_TX_WIDTH                     DSPI_MSC_TX_TX_WIDTH
#define DSPI_TX_TX(x)                        DSPI_MSC_TX_TX(x)
/*! @} */

/*! @name PUSHR - PUSH TX FIFO Register In Master Mode */
/*! @{ */

#define DSPI_PUSHR_TXDATA_MASK               DSPI_MSC_PUSHR_TXDATA_MASK
#define DSPI_PUSHR_TXDATA_SHIFT              DSPI_MSC_PUSHR_TXDATA_SHIFT
#define DSPI_PUSHR_TXDATA_WIDTH              DSPI_MSC_PUSHR_TXDATA_WIDTH
#define DSPI_PUSHR_TXDATA(x)                 DSPI_MSC_PUSHR_TXDATA(x)

#define DSPI_PUSHR_PCS_MASK                  DSPI_MSC_PUSHR_PCS_MASK
#define DSPI_PUSHR_PCS_SHIFT                 DSPI_MSC_PUSHR_PCS_SHIFT
#define DSPI_PUSHR_PCS_WIDTH                 DSPI_MSC_PUSHR_PCS_WIDTH
#define DSPI_PUSHR_PCS(x)                    DSPI_MSC_PUSHR_PCS(x)

#define DSPI_PUSHR_PP_MCSC_MASK              DSPI_MSC_PUSHR_PP_MASK
#define DSPI_PUSHR_PP_MCSC_SHIFT             DSPI_MSC_PUSHR_PP_SHIFT
#define DSPI_PUSHR_PP_MCSC_WIDTH             DSPI_MSC_PUSHR_PP_WIDTH
#define DSPI_PUSHR_PP_MCSC(x)                DSPI_MSC_PUSHR_PP(x)

#define DSPI_PUSHR_PE_MASC_MASK              DSPI_MSC_PUSHR_PE_MASK
#define DSPI_PUSHR_PE_MASC_SHIFT             DSPI_MSC_PUSHR_PE_SHIFT
#define DSPI_PUSHR_PE_MASC_WIDTH             DSPI_MSC_PUSHR_PE_WIDTH
#define DSPI_PUSHR_PE_MASC(x)                DSPI_MSC_PUSHR_PE(x)

#define DSPI_PUSHR_CTCNT_MASK                DSPI_MSC_PUSHR_CTCNT_MASK
#define DSPI_PUSHR_CTCNT_SHIFT               DSPI_MSC_PUSHR_CTCNT_SHIFT
#define DSPI_PUSHR_CTCNT_WIDTH               DSPI_MSC_PUSHR_CTCNT_WIDTH
#define DSPI_PUSHR_CTCNT(x)                  DSPI_MSC_PUSHR_CTCNT(x)

#define DSPI_PUSHR_EOQ_MASK                  DSPI_MSC_PUSHR_EOQ_MASK
#define DSPI_PUSHR_EOQ_SHIFT                 DSPI_MSC_PUSHR_EOQ_SHIFT
#define DSPI_PUSHR_EOQ_WIDTH                 DSPI_MSC_PUSHR_EOQ_WIDTH
#define DSPI_PUSHR_EOQ(x)                    DSPI_MSC_PUSHR_EOQ(x)

#define DSPI_PUSHR_CTAS_MASK                 DSPI_MSC_PUSHR_CTAS_MASK
#define DSPI_PUSHR_CTAS_SHIFT                DSPI_MSC_PUSHR_CTAS_SHIFT
#define DSPI_PUSHR_CTAS_WIDTH                DSPI_MSC_PUSHR_CTAS_WIDTH
#define DSPI_PUSHR_CTAS(x)                   DSPI_MSC_PUSHR_CTAS(x)

#define DSPI_PUSHR_CONT_MASK                 DSPI_MSC_PUSHR_CONT_MASK
#define DSPI_PUSHR_CONT_SHIFT                DSPI_MSC_PUSHR_CONT_SHIFT
#define DSPI_PUSHR_CONT_WIDTH                DSPI_MSC_PUSHR_CONT_WIDTH
#define DSPI_PUSHR_CONT(x)                   DSPI_MSC_PUSHR_CONT(x)
/*! @} */

/*! @name POPR - POP RX FIFO Register */
/*! @{ */

#define DSPI_POPR_RXDATA_MASK                DSPI_MSC_POPR_RXDATA_MASK
#define DSPI_POPR_RXDATA_SHIFT               DSPI_MSC_POPR_RXDATA_SHIFT
#define DSPI_POPR_RXDATA_WIDTH               DSPI_MSC_POPR_RXDATA_WIDTH
#define DSPI_POPR_RXDATA(x)                  DSPI_MSC_POPR_RXDATA(x)
/*! @} */

/*! @name TXFR - Transmit FIFO Registers */
/*! @{ */

#define DSPI_TXFR_TXDATA_MASK                DSPI_MSC_TXFR_TXDATA_MASK
#define DSPI_TXFR_TXDATA_SHIFT               DSPI_MSC_TXFR_TXDATA_SHIFT
#define DSPI_TXFR_TXDATA_WIDTH               DSPI_MSC_TXFR_TXDATA_WIDTH
#define DSPI_TXFR_TXDATA(x)                  DSPI_MSC_TXFR_TXDATA(x)

#define DSPI_TXFR_TXCMD_TXDATA_MASK          DSPI_MSC_TXFR_TXCMD_TXDATA_MASK
#define DSPI_TXFR_TXCMD_TXDATA_SHIFT         DSPI_MSC_TXFR_TXCMD_TXDATA_SHIFT
#define DSPI_TXFR_TXCMD_TXDATA_WIDTH         DSPI_MSC_TXFR_TXCMD_TXDATA_WIDTH
#define DSPI_TXFR_TXCMD_TXDATA(x)            DSPI_MSC_TXFR_TXCMD_TXDATA(x)
/*! @} */

/*! @name RXFR - Receive FIFO Registers */
/*! @{ */

#define DSPI_RXFR_RXDATA_MASK                DSPI_MSC_RXFR_RXDATA_MASK
#define DSPI_RXFR_RXDATA_SHIFT               DSPI_MSC_RXFR_RXDATA_SHIFT
#define DSPI_RXFR_RXDATA_WIDTH               DSPI_MSC_RXFR_RXDATA_WIDTH
#define DSPI_RXFR_RXDATA(x)                  DSPI_MSC_RXFR_RXDATA(x)
/*! @} */

/*! @name DSICR0 - DSI Configuration Register 0 */
/*! @{ */

#define DSPI_DSICR0_DPCSx_MASK               DSPI_MSC_DSICR0_DPCSx_MASK
#define DSPI_DSICR0_DPCSx_SHIFT              DSPI_MSC_DSICR0_DPCSx_SHIFT
#define DSPI_DSICR0_DPCSx_WIDTH              DSPI_MSC_DSICR0_DPCSx_WIDTH
#define DSPI_DSICR0_DPCSx(x)                 DSPI_MSC_DSICR0_DPCSx(x)

#define DSPI_DSICR0_PP_MASK                  DSPI_MSC_DSICR0_PP_MASK
#define DSPI_DSICR0_PP_SHIFT                 DSPI_MSC_DSICR0_PP_SHIFT
#define DSPI_DSICR0_PP_WIDTH                 DSPI_MSC_DSICR0_PP_WIDTH
#define DSPI_DSICR0_PP(x)                    DSPI_MSC_DSICR0_PP(x)

#define DSPI_DSICR0_PE_MASK                  DSPI_MSC_DSICR0_PE_MASK
#define DSPI_DSICR0_PE_SHIFT                 DSPI_MSC_DSICR0_PE_SHIFT
#define DSPI_DSICR0_PE_WIDTH                 DSPI_MSC_DSICR0_PE_WIDTH
#define DSPI_DSICR0_PE(x)                    DSPI_MSC_DSICR0_PE(x)

#define DSPI_DSICR0_PES_MASK                 DSPI_MSC_DSICR0_PES_MASK
#define DSPI_DSICR0_PES_SHIFT                DSPI_MSC_DSICR0_PES_SHIFT
#define DSPI_DSICR0_PES_WIDTH                DSPI_MSC_DSICR0_PES_WIDTH
#define DSPI_DSICR0_PES(x)                   DSPI_MSC_DSICR0_PES(x)

#define DSPI_DSICR0_DMS_MASK                 DSPI_MSC_DSICR0_DMS_MASK
#define DSPI_DSICR0_DMS_SHIFT                DSPI_MSC_DSICR0_DMS_SHIFT
#define DSPI_DSICR0_DMS_WIDTH                DSPI_MSC_DSICR0_DMS_WIDTH
#define DSPI_DSICR0_DMS(x)                   DSPI_MSC_DSICR0_DMS(x)

#define DSPI_DSICR0_DSICTAS_MASK             DSPI_MSC_DSICR0_DSICTAS_MASK
#define DSPI_DSICR0_DSICTAS_SHIFT            DSPI_MSC_DSICR0_DSICTAS_SHIFT
#define DSPI_DSICR0_DSICTAS_WIDTH            DSPI_MSC_DSICR0_DSICTAS_WIDTH
#define DSPI_DSICR0_DSICTAS(x)               DSPI_MSC_DSICR0_DSICTAS(x)

#define DSPI_DSICR0_DCONT_MASK               DSPI_MSC_DSICR0_DCONT_MASK
#define DSPI_DSICR0_DCONT_SHIFT              DSPI_MSC_DSICR0_DCONT_SHIFT
#define DSPI_DSICR0_DCONT_WIDTH              DSPI_MSC_DSICR0_DCONT_WIDTH
#define DSPI_DSICR0_DCONT(x)                 DSPI_MSC_DSICR0_DCONT(x)

#define DSPI_DSICR0_CID_MASK                 DSPI_MSC_DSICR0_CID_MASK
#define DSPI_DSICR0_CID_SHIFT                DSPI_MSC_DSICR0_CID_SHIFT
#define DSPI_DSICR0_CID_WIDTH                DSPI_MSC_DSICR0_CID_WIDTH
#define DSPI_DSICR0_CID(x)                   DSPI_MSC_DSICR0_CID(x)

#define DSPI_DSICR0_TRRE_MASK                DSPI_MSC_DSICR0_TRRE_MASK
#define DSPI_DSICR0_TRRE_SHIFT               DSPI_MSC_DSICR0_TRRE_SHIFT
#define DSPI_DSICR0_TRRE_WIDTH               DSPI_MSC_DSICR0_TRRE_WIDTH
#define DSPI_DSICR0_TRRE(x)                  DSPI_MSC_DSICR0_TRRE(x)

#define DSPI_DSICR0_TPOL_MASK                DSPI_MSC_DSICR0_TPOL_MASK
#define DSPI_DSICR0_TPOL_SHIFT               DSPI_MSC_DSICR0_TPOL_SHIFT
#define DSPI_DSICR0_TPOL_WIDTH               DSPI_MSC_DSICR0_TPOL_WIDTH
#define DSPI_DSICR0_TPOL(x)                  DSPI_MSC_DSICR0_TPOL(x)

#define DSPI_DSICR0_TXSS_MASK                DSPI_MSC_DSICR0_TXSS_MASK
#define DSPI_DSICR0_TXSS_SHIFT               DSPI_MSC_DSICR0_TXSS_SHIFT
#define DSPI_DSICR0_TXSS_WIDTH               DSPI_MSC_DSICR0_TXSS_WIDTH
#define DSPI_DSICR0_TXSS(x)                  DSPI_MSC_DSICR0_TXSS(x)

#define DSPI_DSICR0_TSBC_MASK                DSPI_MSC_DSICR0_TSBC_MASK
#define DSPI_DSICR0_TSBC_SHIFT               DSPI_MSC_DSICR0_TSBC_SHIFT
#define DSPI_DSICR0_TSBC_WIDTH               DSPI_MSC_DSICR0_TSBC_WIDTH
#define DSPI_DSICR0_TSBC(x)                  DSPI_MSC_DSICR0_TSBC(x)

#define DSPI_DSICR0_ITSB_MASK                DSPI_MSC_DSICR0_ITSB_MASK
#define DSPI_DSICR0_ITSB_SHIFT               DSPI_MSC_DSICR0_ITSB_SHIFT
#define DSPI_DSICR0_ITSB_WIDTH               DSPI_MSC_DSICR0_ITSB_WIDTH
#define DSPI_DSICR0_ITSB(x)                  DSPI_MSC_DSICR0_ITSB(x)

#define DSPI_DSICR0_TRG_MASK                 DSPI_MSC_DSICR0_TRG_MASK
#define DSPI_DSICR0_TRG_SHIFT                DSPI_MSC_DSICR0_TRG_SHIFT
#define DSPI_DSICR0_TRG_WIDTH                DSPI_MSC_DSICR0_TRG_WIDTH
#define DSPI_DSICR0_TRG(x)                   DSPI_MSC_DSICR0_TRG(x)

#define DSPI_DSICR0_FMSZ5_MASK               DSPI_MSC_DSICR0_FMSZ5_MASK
#define DSPI_DSICR0_FMSZ5_SHIFT              DSPI_MSC_DSICR0_FMSZ5_SHIFT
#define DSPI_DSICR0_FMSZ5_WIDTH              DSPI_MSC_DSICR0_FMSZ5_WIDTH
#define DSPI_DSICR0_FMSZ5(x)                 DSPI_MSC_DSICR0_FMSZ5(x)

#define DSPI_DSICR0_FMSZ4_MASK               DSPI_MSC_DSICR0_FMSZ4_MASK
#define DSPI_DSICR0_FMSZ4_SHIFT              DSPI_MSC_DSICR0_FMSZ4_SHIFT
#define DSPI_DSICR0_FMSZ4_WIDTH              DSPI_MSC_DSICR0_FMSZ4_WIDTH
#define DSPI_DSICR0_FMSZ4(x)                 DSPI_MSC_DSICR0_FMSZ4(x)
/*! @} */

/*! @name SDR0 - DSI Serialization Data Register 0 */
/*! @{ */

#define DSPI_SDR0_SER_DATA_MASK              DSPI_MSC_SDR0_SER_DATA_MASK
#define DSPI_SDR0_SER_DATA_SHIFT             DSPI_MSC_SDR0_SER_DATA_SHIFT
#define DSPI_SDR0_SER_DATA_WIDTH             DSPI_MSC_SDR0_SER_DATA_WIDTH
#define DSPI_SDR0_SER_DATA(x)                DSPI_MSC_SDR0_SER_DATA(x)
/*! @} */

/*! @name ASDR0 - DSI Alternate Serialization Data Register 0 */
/*! @{ */

#define DSPI_ASDR0_ASER_DATA_MASK            DSPI_MSC_ASDR0_ASER_DATA_MASK
#define DSPI_ASDR0_ASER_DATA_SHIFT           DSPI_MSC_ASDR0_ASER_DATA_SHIFT
#define DSPI_ASDR0_ASER_DATA_WIDTH           DSPI_MSC_ASDR0_ASER_DATA_WIDTH
#define DSPI_ASDR0_ASER_DATA(x)              DSPI_MSC_ASDR0_ASER_DATA(x)
/*! @} */

/*! @name COMPR0 - DSI Transmit Comparison Register 0 */
/*! @{ */

#define DSPI_COMPR0_COMP_DATA_MASK           DSPI_MSC_COMPR0_COMP_DATA_MASK
#define DSPI_COMPR0_COMP_DATA_SHIFT          DSPI_MSC_COMPR0_COMP_DATA_SHIFT
#define DSPI_COMPR0_COMP_DATA_WIDTH          DSPI_MSC_COMPR0_COMP_DATA_WIDTH
#define DSPI_COMPR0_COMP_DATA(x)             DSPI_MSC_COMPR0_COMP_DATA(x)
/*! @} */

/*! @name DDR0 - DSI Deserialization Data Register 0 */
/*! @{ */

#define DSPI_DDR0_DESER_DATA_MASK            DSPI_MSC_DDR0_DESER_DATA_MASK
#define DSPI_DDR0_DESER_DATA_SHIFT           DSPI_MSC_DDR0_DESER_DATA_SHIFT
#define DSPI_DDR0_DESER_DATA_WIDTH           DSPI_MSC_DDR0_DESER_DATA_WIDTH
#define DSPI_DDR0_DESER_DATA(x)              DSPI_MSC_DDR0_DESER_DATA(x)
/*! @} */

/*! @name DSICR1 - DSI Configuration Register 1 */
/*! @{ */

#define DSPI_DSICR1_DPCS1_x_MASK             DSPI_MSC_DSICR1_DPCS1_x_MASK
#define DSPI_DSICR1_DPCS1_x_SHIFT            DSPI_MSC_DSICR1_DPCS1_x_SHIFT
#define DSPI_DSICR1_DPCS1_x_WIDTH            DSPI_MSC_DSICR1_DPCS1_x_WIDTH
#define DSPI_DSICR1_DPCS1_x(x)               DSPI_MSC_DSICR1_DPCS1_x(x)

#define DSPI_DSICR1_DSE0_MASK                DSPI_MSC_DSICR1_DSE0_MASK
#define DSPI_DSICR1_DSE0_SHIFT               DSPI_MSC_DSICR1_DSE0_SHIFT
#define DSPI_DSICR1_DSE0_WIDTH               DSPI_MSC_DSICR1_DSE0_WIDTH
#define DSPI_DSICR1_DSE0(x)                  DSPI_MSC_DSICR1_DSE0(x)

#define DSPI_DSICR1_DSE1_MASK                DSPI_MSC_DSICR1_DSE1_MASK
#define DSPI_DSICR1_DSE1_SHIFT               DSPI_MSC_DSICR1_DSE1_SHIFT
#define DSPI_DSICR1_DSE1_WIDTH               DSPI_MSC_DSICR1_DSE1_WIDTH
#define DSPI_DSICR1_DSE1(x)                  DSPI_MSC_DSICR1_DSE1(x)

#define DSPI_DSICR1_DSI64E_MASK              DSPI_MSC_DSICR1_DSI64E_MASK
#define DSPI_DSICR1_DSI64E_SHIFT             DSPI_MSC_DSICR1_DSI64E_SHIFT
#define DSPI_DSICR1_DSI64E_WIDTH             DSPI_MSC_DSICR1_DSI64E_WIDTH
#define DSPI_DSICR1_DSI64E(x)                DSPI_MSC_DSICR1_DSI64E(x)

#define DSPI_DSICR1_CSE_MASK                 DSPI_MSC_DSICR1_CSE_MASK
#define DSPI_DSICR1_CSE_SHIFT                DSPI_MSC_DSICR1_CSE_SHIFT
#define DSPI_DSICR1_CSE_WIDTH                DSPI_MSC_DSICR1_CSE_WIDTH
#define DSPI_DSICR1_CSE(x)                   DSPI_MSC_DSICR1_CSE(x)

#define DSPI_DSICR1_TSBCNT_MASK              DSPI_MSC_DSICR1_TSBCNT_MASK
#define DSPI_DSICR1_TSBCNT_SHIFT             DSPI_MSC_DSICR1_TSBCNT_SHIFT
#define DSPI_DSICR1_TSBCNT_WIDTH             DSPI_MSC_DSICR1_TSBCNT_WIDTH
#define DSPI_DSICR1_TSBCNT(x)                DSPI_MSC_DSICR1_TSBCNT(x)
/*! @} */

/*! @name SSR0 - DSI Serialization Source Select Register 0 */
/*! @{ */

#define DSPI_SSR0_SS_MASK                    DSPI_MSC_SSR0_SS_MASK
#define DSPI_SSR0_SS_SHIFT                   DSPI_MSC_SSR0_SS_SHIFT
#define DSPI_SSR0_SS_WIDTH                   DSPI_MSC_SSR0_SS_WIDTH
#define DSPI_SSR0_SS(x)                      DSPI_MSC_SSR0_SS(x)
/*! @} */

/*! @name DIMR0 - DSI Deserialized Data Interrupt Mask Register 0 */
/*! @{ */

#define DSPI_DIMR0_MASK_MASK                 DSPI_MSC_DIMR0_MASK_MASK
#define DSPI_DIMR0_MASK_SHIFT                DSPI_MSC_DIMR0_MASK_SHIFT
#define DSPI_DIMR0_MASK_WIDTH                DSPI_MSC_DIMR0_MASK_WIDTH
#define DSPI_DIMR0_MASK(x)                   DSPI_MSC_DIMR0_MASK(x)
/*! @} */

/*! @name DPIR0 - DSI Deserialized Data Polarity Interrupt Register 0 */
/*! @{ */

#define DSPI_DPIR0_DP_MASK                   DSPI_MSC_DPIR0_DP_MASK
#define DSPI_DPIR0_DP_SHIFT                  DSPI_MSC_DPIR0_DP_SHIFT
#define DSPI_DPIR0_DP_WIDTH                  DSPI_MSC_DPIR0_DP_WIDTH
#define DSPI_DPIR0_DP(x)                     DSPI_MSC_DPIR0_DP(x)
/*! @} */

/*! @name SDR1 - DSI Serialization Data Register 1 */
/*! @{ */

#define DSPI_SDR1_SER_DATA_MASK              DSPI_MSC_SDR1_SER_DATA_MASK
#define DSPI_SDR1_SER_DATA_SHIFT             DSPI_MSC_SDR1_SER_DATA_SHIFT
#define DSPI_SDR1_SER_DATA_WIDTH             DSPI_MSC_SDR1_SER_DATA_WIDTH
#define DSPI_SDR1_SER_DATA(x)                DSPI_MSC_SDR1_SER_DATA(x)
/*! @} */

/*! @name ASDR1 - DSI Alternate Serialization Data Register 1 */
/*! @{ */

#define DSPI_ASDR1_ASER_DATA_MASK            DSPI_MSC_ASDR1_ASER_DATA_MASK
#define DSPI_ASDR1_ASER_DATA_SHIFT           DSPI_MSC_ASDR1_ASER_DATA_SHIFT
#define DSPI_ASDR1_ASER_DATA_WIDTH           DSPI_MSC_ASDR1_ASER_DATA_WIDTH
#define DSPI_ASDR1_ASER_DATA(x)              DSPI_MSC_ASDR1_ASER_DATA(x)
/*! @} */

/*! @name COMPR1 - DSI Transmit Comparison Register 1 */
/*! @{ */

#define DSPI_COMPR1_COMP_DATA_MASK           DSPI_MSC_COMPR1_COMP_DATA_MASK
#define DSPI_COMPR1_COMP_DATA_SHIFT          DSPI_MSC_COMPR1_COMP_DATA_SHIFT
#define DSPI_COMPR1_COMP_DATA_WIDTH          DSPI_MSC_COMPR1_COMP_DATA_WIDTH
#define DSPI_COMPR1_COMP_DATA(x)             DSPI_MSC_COMPR1_COMP_DATA(x)
/*! @} */

/*! @name DDR1 - DSI Deserialization Data Register 1 */
/*! @{ */

#define DSPI_DDR1_DESER_DATA_MASK            DSPI_MSC_DDR1_DESER_DATA_MASK
#define DSPI_DDR1_DESER_DATA_SHIFT           DSPI_MSC_DDR1_DESER_DATA_SHIFT
#define DSPI_DDR1_DESER_DATA_WIDTH           DSPI_MSC_DDR1_DESER_DATA_WIDTH
#define DSPI_DDR1_DESER_DATA(x)              DSPI_MSC_DDR1_DESER_DATA(x)
/*! @} */

/*! @name SSR1 - DSI Serialization Source Select Register 1 */
/*! @{ */

#define DSPI_SSR1_SS_MASK                    DSPI_MSC_SSR1_SS_MASK
#define DSPI_SSR1_SS_SHIFT                   DSPI_MSC_SSR1_SS_SHIFT
#define DSPI_SSR1_SS_WIDTH                   DSPI_MSC_SSR1_SS_WIDTH
#define DSPI_SSR1_SS(x)                      DSPI_MSC_SSR1_SS(x)
/*! @} */

/*! @name DIMR1 - DSI Deserialized Data Interrupt Mask Register 1 */
/*! @{ */

#define DSPI_DIMR1_MASK_MASK                 DSPI_MSC_DIMR1_MASK_MASK
#define DSPI_DIMR1_MASK_SHIFT                DSPI_MSC_DIMR1_MASK_SHIFT
#define DSPI_DIMR1_MASK_WIDTH                DSPI_MSC_DIMR1_MASK_WIDTH
#define DSPI_DIMR1_MASK(x)                   DSPI_MSC_DIMR1_MASK(x)
/*! @} */

/*! @name DPIR1 - DSI Deserialized Data Polarity Interrupt Register 1 */
/*! @{ */

#define DSPI_DPIR1_DP_MASK                   DSPI_MSC_DPIR1_DP_MASK
#define DSPI_DPIR1_DP_SHIFT                  DSPI_MSC_DPIR1_DP_SHIFT
#define DSPI_DPIR1_DP_WIDTH                  DSPI_MSC_DPIR1_DP_WIDTH
#define DSPI_DPIR1_DP(x)                     DSPI_MSC_DPIR1_DP(x)
/*! @} */

/*! @name CTARE - Clock and Transfer Attributes Register Extended */
/*! @{ */

#define DSPI_CTARE_DTCP_MASK                 DSPI_MSC_CTARE_DTCP_MASK
#define DSPI_CTARE_DTCP_SHIFT                DSPI_MSC_CTARE_DTCP_SHIFT
#define DSPI_CTARE_DTCP_WIDTH                DSPI_MSC_CTARE_DTCP_WIDTH
#define DSPI_CTARE_DTCP(x)                   DSPI_MSC_CTARE_DTCP(x)

#define DSPI_CTARE_FMSZE_MASK                DSPI_MSC_CTARE_FMSZE_MASK
#define DSPI_CTARE_FMSZE_SHIFT               DSPI_MSC_CTARE_FMSZE_SHIFT
#define DSPI_CTARE_FMSZE_WIDTH               DSPI_MSC_CTARE_FMSZE_WIDTH
#define DSPI_CTARE_FMSZE(x)                  DSPI_MSC_CTARE_FMSZE(x)
/*! @} */

/*! @name SREX - Status Register Extended */
/*! @{ */

#define DSPI_SREX_CMDNXTPTR_MASK             DSPI_MSC_SREX_CMDNXTPTR_MASK
#define DSPI_SREX_CMDNXTPTR_SHIFT            DSPI_MSC_SREX_CMDNXTPTR_SHIFT
#define DSPI_SREX_CMDNXTPTR_WIDTH            DSPI_MSC_SREX_CMDNXTPTR_WIDTH
#define DSPI_SREX_CMDNXTPTR(x)               DSPI_MSC_SREX_CMDNXTPTR(x)

#define DSPI_SREX_CMDCTR_MASK                DSPI_MSC_SREX_CMDCTR_MASK
#define DSPI_SREX_CMDCTR_SHIFT               DSPI_MSC_SREX_CMDCTR_SHIFT
#define DSPI_SREX_CMDCTR_WIDTH               DSPI_MSC_SREX_CMDCTR_WIDTH
#define DSPI_SREX_CMDCTR(x)                  DSPI_MSC_SREX_CMDCTR(x)

#define DSPI_SREX_RXCTR4_MASK                DSPI_MSC_SREX_RXCTR4_MASK
#define DSPI_SREX_RXCTR4_SHIFT               DSPI_MSC_SREX_RXCTR4_SHIFT
#define DSPI_SREX_RXCTR4_WIDTH               DSPI_MSC_SREX_RXCTR4_WIDTH
#define DSPI_SREX_RXCTR4(x)                  DSPI_MSC_SREX_RXCTR4(x)

#define DSPI_SREX_TXCTR4_MASK                DSPI_MSC_SREX_TXCTR4_MASK
#define DSPI_SREX_TXCTR4_SHIFT               DSPI_MSC_SREX_TXCTR4_SHIFT
#define DSPI_SREX_TXCTR4_WIDTH               DSPI_MSC_SREX_TXCTR4_WIDTH
#define DSPI_SREX_TXCTR4(x)                  DSPI_MSC_SREX_TXCTR4(x)
/*! @} */

/*! @name TSL - Time Slot Length Register */
/*! @{ */

#define DSPI_TSL_TS0_LEN_MASK                DSPI_MSC_TSL_TS0_LEN_MASK
#define DSPI_TSL_TS0_LEN_SHIFT               DSPI_MSC_TSL_TS0_LEN_SHIFT
#define DSPI_TSL_TS0_LEN_WIDTH               DSPI_MSC_TSL_TS0_LEN_WIDTH
#define DSPI_TSL_TS0_LEN(x)                  DSPI_MSC_TSL_TS0_LEN(x)

#define DSPI_TSL_TS1_LEN_MASK                DSPI_MSC_TSL_TS1_LEN_MASK
#define DSPI_TSL_TS1_LEN_SHIFT               DSPI_MSC_TSL_TS1_LEN_SHIFT
#define DSPI_TSL_TS1_LEN_WIDTH               DSPI_MSC_TSL_TS1_LEN_WIDTH
#define DSPI_TSL_TS1_LEN(x)                  DSPI_MSC_TSL_TS1_LEN(x)

#define DSPI_TSL_TS2_LEN_MASK                DSPI_MSC_TSL_TS2_LEN_MASK
#define DSPI_TSL_TS2_LEN_SHIFT               DSPI_MSC_TSL_TS2_LEN_SHIFT
#define DSPI_TSL_TS2_LEN_WIDTH               DSPI_MSC_TSL_TS2_LEN_WIDTH
#define DSPI_TSL_TS2_LEN(x)                  DSPI_MSC_TSL_TS2_LEN(x)

#define DSPI_TSL_TS3_LEN_MASK                DSPI_MSC_TSL_TS3_LEN_MASK
#define DSPI_TSL_TS3_LEN_SHIFT               DSPI_MSC_TSL_TS3_LEN_SHIFT
#define DSPI_TSL_TS3_LEN_WIDTH               DSPI_MSC_TSL_TS3_LEN_WIDTH
#define DSPI_TSL_TS3_LEN(x)                  DSPI_MSC_TSL_TS3_LEN(x)
/*! @} */

/*! @name TS_CONF - Time Slot Configuration Register */
/*! @{ */

#define DSPI_TS_CONF_TS0_MASK                DSPI_MSC_TS_CONF_TS0_MASK
#define DSPI_TS_CONF_TS0_SHIFT               DSPI_MSC_TS_CONF_TS0_SHIFT
#define DSPI_TS_CONF_TS0_WIDTH               DSPI_MSC_TS_CONF_TS0_WIDTH
#define DSPI_TS_CONF_TS0(x)                  DSPI_MSC_TS_CONF_TS0(x)

#define DSPI_TS_CONF_TS1_MASK                DSPI_MSC_TS_CONF_TS1_MASK
#define DSPI_TS_CONF_TS1_SHIFT               DSPI_MSC_TS_CONF_TS1_SHIFT
#define DSPI_TS_CONF_TS1_WIDTH               DSPI_MSC_TS_CONF_TS1_WIDTH
#define DSPI_TS_CONF_TS1(x)                  DSPI_MSC_TS_CONF_TS1(x)

#define DSPI_TS_CONF_TS2_MASK                DSPI_MSC_TS_CONF_TS2_MASK
#define DSPI_TS_CONF_TS2_SHIFT               DSPI_MSC_TS_CONF_TS2_SHIFT
#define DSPI_TS_CONF_TS2_WIDTH               DSPI_MSC_TS_CONF_TS2_WIDTH
#define DSPI_TS_CONF_TS2(x)                  DSPI_MSC_TS_CONF_TS2(x)

#define DSPI_TS_CONF_TS3_MASK                DSPI_MSC_TS_CONF_TS3_MASK
#define DSPI_TS_CONF_TS3_SHIFT               DSPI_MSC_TS_CONF_TS3_SHIFT
#define DSPI_TS_CONF_TS3_WIDTH               DSPI_MSC_TS_CONF_TS3_WIDTH
#define DSPI_TS_CONF_TS3(x)                  DSPI_MSC_TS_CONF_TS3(x)
/*! @} */

/*!
 * @}
 */ /* end of group DSPI_MSC_Register_Masks */

/*!
 * @}
 */ /* end of group DSPI_MSC_Peripheral_Access_Layer */
#define DSPI_MCR_FCPCS_MASK                      (0x4U)
#define DSPI_MCR_FCPCS_SHIFT                     (2U)
#define DSPI_MCR_FCPCS_WIDTH                     (1U)
#define DSPI_MCR_FCPCS(x)                        (((uint32_t)(((uint32_t)(x)) << DSPI_MCR_FCPCS_SHIFT)) & DSPI_MCR_FCPCS_MASK)

#define DSPI_MCR_SMPL_PT_MASK                    (0x300U)
#define DSPI_MCR_SMPL_PT_SHIFT                   (8U)
#define DSPI_MCR_SMPL_PT_WIDTH                   (2U)
#define DSPI_MCR_SMPL_PT(x)                      (((uint32_t)(((uint32_t)(x)) << DSPI_MCR_SMPL_PT_SHIFT)) & DSPI_MCR_SMPL_PT_MASK)

#define DSPI_MCR_MTFE_MASK                       (0x4000000U)
#define DSPI_MCR_MTFE_SHIFT                      (26U)
#define DSPI_MCR_MTFE_WIDTH                      (1U)
#define DSPI_MCR_MTFE(x)                         (((uint32_t)(((uint32_t)(x)) << DSPI_MCR_MTFE_SHIFT)) & DSPI_MCR_MTFE_MASK)

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /*S32K37_DSPI_MSC_WRAPPER*/
