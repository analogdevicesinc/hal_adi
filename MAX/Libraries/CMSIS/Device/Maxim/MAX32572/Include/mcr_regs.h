/**
 * @file    mcr_regs.h
 * @brief   Registers, Bit Masks and Bit Positions for the MCR Peripheral Module.
 * @note    This file is @generated.
 */

/******************************************************************************
 *
 * Copyright (C) 2022-2023 Maxim Integrated Products, Inc. All Rights Reserved.
 * (now owned by Analog Devices, Inc.),
 * Copyright (C) 2023 Analog Devices, Inc. All Rights Reserved. This software
 * is proprietary to Analog Devices, Inc. and its licensors.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 ******************************************************************************/

#ifndef LIBRARIES_CMSIS_DEVICE_MAXIM_MAX32572_INCLUDE_MCR_REGS_H_
#define LIBRARIES_CMSIS_DEVICE_MAXIM_MAX32572_INCLUDE_MCR_REGS_H_

/* **** Includes **** */
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#if defined (__ICCARM__)
  #pragma system_include
#endif

#if defined (__CC_ARM)
  #pragma anon_unions
#endif
/// @cond
/*
    If types are not defined elsewhere (CMSIS) define them here
*/
#ifndef __IO
#define __IO volatile
#endif
#ifndef __I
#define __I  volatile const
#endif
#ifndef __O
#define __O  volatile
#endif
#ifndef __R
#define __R  volatile const
#endif
/// @endcond

/* **** Definitions **** */

/**
 * @ingroup     mcr
 * @defgroup    mcr_registers MCR_Registers
 * @brief       Registers, Bit Masks and Bit Positions for the MCR Peripheral Module.
 * @details     Misc Control.
 */

/**
 * @ingroup mcr_registers
 * Structure type to access the MCR Registers.
 */
typedef struct {
    __IO uint32_t eccen;                /**< <tt>\b 0x00:</tt> MCR ECCEN Register */
    __R  uint32_t rsv_0x4;
    __IO uint32_t pdown;                /**< <tt>\b 0x08:</tt> MCR PDOWN Register */
    __R  uint32_t rsv_0xc;
    __IO uint32_t ctrl;                 /**< <tt>\b 0x10:</tt> MCR CTRL Register */
    __IO uint32_t clkctrl;              /**< <tt>\b 0x14:</tt> MCR CLKCTRL Register */
    __IO uint32_t rst;                  /**< <tt>\b 0x18:</tt> MCR RST Register */
    __IO uint32_t rtctrim;              /**< <tt>\b 0x1C:</tt> MCR RTCTRIM Register */
    __R  uint32_t rsv_0x20_0x5f[16];
    __IO uint32_t ldoctrl;              /**< <tt>\b 0x60:</tt> MCR LDOCTRL Register */
} mxc_mcr_regs_t;

/* Register offsets for module MCR */
/**
 * @ingroup    mcr_registers
 * @defgroup   MCR_Register_Offsets Register Offsets
 * @brief      MCR Peripheral Register Offsets from the MCR Base Peripheral Address.
 * @{
 */
#define MXC_R_MCR_ECCEN                    ((uint32_t)0x00000000UL) /**< Offset from MCR Base Address: <tt> 0x0000</tt> */
#define MXC_R_MCR_PDOWN                    ((uint32_t)0x00000008UL) /**< Offset from MCR Base Address: <tt> 0x0008</tt> */
#define MXC_R_MCR_CTRL                     ((uint32_t)0x00000010UL) /**< Offset from MCR Base Address: <tt> 0x0010</tt> */
#define MXC_R_MCR_CLKCTRL                  ((uint32_t)0x00000014UL) /**< Offset from MCR Base Address: <tt> 0x0014</tt> */
#define MXC_R_MCR_RST                      ((uint32_t)0x00000018UL) /**< Offset from MCR Base Address: <tt> 0x0018</tt> */
#define MXC_R_MCR_RTCTRIM                  ((uint32_t)0x0000001CUL) /**< Offset from MCR Base Address: <tt> 0x001C</tt> */
#define MXC_R_MCR_LDOCTRL                  ((uint32_t)0x00000060UL) /**< Offset from MCR Base Address: <tt> 0x0060</tt> */
/**@} end of group mcr_registers */

/**
 * @ingroup  mcr_registers
 * @defgroup MCR_ECCEN MCR_ECCEN
 * @brief    ECC Enable Register
 * @{
 */
#define MXC_F_MCR_ECCEN_ICCXIP_POS                     10 /**< ECCEN_ICCXIP Position */
#define MXC_F_MCR_ECCEN_ICCXIP                         ((uint32_t)(0x1UL << MXC_F_MCR_ECCEN_ICCXIP_POS)) /**< ECCEN_ICCXIP Mask */

/**@} end of group MCR_ECCEN_Register */

/**
 * @ingroup  mcr_registers
 * @defgroup MCR_PDOWN MCR_PDOWN
 * @brief    PDOWN Drive Strength
 * @{
 */
#define MXC_F_MCR_PDOWN_PDOWNDS_POS                    0 /**< PDOWN_PDOWNDS Position */
#define MXC_F_MCR_PDOWN_PDOWNDS                        ((uint32_t)(0x3UL << MXC_F_MCR_PDOWN_PDOWNDS_POS)) /**< PDOWN_PDOWNDS Mask */

#define MXC_F_MCR_PDOWN_PDOWNVS_POS                    2 /**< PDOWN_PDOWNVS Position */
#define MXC_F_MCR_PDOWN_PDOWNVS                        ((uint32_t)(0x1UL << MXC_F_MCR_PDOWN_PDOWNVS_POS)) /**< PDOWN_PDOWNVS Mask */

/**@} end of group MCR_PDOWN_Register */

/**
 * @ingroup  mcr_registers
 * @defgroup MCR_CTRL MCR_CTRL
 * @brief    Misc Power State Control Register
 * @{
 */
#define MXC_F_MCR_CTRL_VDDCSW_POS                      1 /**< CTRL_VDDCSW Position */
#define MXC_F_MCR_CTRL_VDDCSW                          ((uint32_t)(0x3UL << MXC_F_MCR_CTRL_VDDCSW_POS)) /**< CTRL_VDDCSW Mask */

#define MXC_F_MCR_CTRL_USBSWEN_N_POS                   3 /**< CTRL_USBSWEN_N Position */
#define MXC_F_MCR_CTRL_USBSWEN_N                       ((uint32_t)(0x1UL << MXC_F_MCR_CTRL_USBSWEN_N_POS)) /**< CTRL_USBSWEN_N Mask */

#define MXC_F_MCR_CTRL_P1M_POS                         9 /**< CTRL_P1M Position */
#define MXC_F_MCR_CTRL_P1M                             ((uint32_t)(0x1UL << MXC_F_MCR_CTRL_P1M_POS)) /**< CTRL_P1M Mask */

#define MXC_F_MCR_CTRL_RSTN_VOLTAGE_SEL_POS            10 /**< CTRL_RSTN_VOLTAGE_SEL Position */
#define MXC_F_MCR_CTRL_RSTN_VOLTAGE_SEL                ((uint32_t)(0x1UL << MXC_F_MCR_CTRL_RSTN_VOLTAGE_SEL_POS)) /**< CTRL_RSTN_VOLTAGE_SEL Mask */

/**@} end of group MCR_CTRL_Register */

/**
 * @ingroup  mcr_registers
 * @defgroup MCR_CLKCTRL MCR_CLKCTRL
 * @brief    Clock Control Register.
 * @{
 */
#define MXC_F_MCR_CLKCTRL_ERTCO_PD_POS                 16 /**< CLKCTRL_ERTCO_PD Position */
#define MXC_F_MCR_CLKCTRL_ERTCO_PD                     ((uint32_t)(0x1UL << MXC_F_MCR_CLKCTRL_ERTCO_PD_POS)) /**< CLKCTRL_ERTCO_PD Mask */

#define MXC_F_MCR_CLKCTRL_ERTCO_EN_POS                 17 /**< CLKCTRL_ERTCO_EN Position */
#define MXC_F_MCR_CLKCTRL_ERTCO_EN                     ((uint32_t)(0x1UL << MXC_F_MCR_CLKCTRL_ERTCO_EN_POS)) /**< CLKCTRL_ERTCO_EN Mask */

/**@} end of group MCR_CLKCTRL_Register */

/**
 * @ingroup  mcr_registers
 * @defgroup MCR_RST MCR_RST
 * @brief    Reset Register.
 * @{
 */
#define MXC_F_MCR_RST_RTC_POS                          0 /**< RST_RTC Position */
#define MXC_F_MCR_RST_RTC                              ((uint32_t)(0x1UL << MXC_F_MCR_RST_RTC_POS)) /**< RST_RTC Mask */

/**@} end of group MCR_RST_Register */

/**
 * @ingroup  mcr_registers
 * @defgroup MCR_RTCTRIM MCR_RTCTRIM
 * @brief    RTC Trim Register.
 * @{
 */
#define MXC_F_MCR_RTCTRIM_TRIM_X1_POS                  0 /**< RTCTRIM_TRIM_X1 Position */
#define MXC_F_MCR_RTCTRIM_TRIM_X1                      ((uint32_t)(0x1FUL << MXC_F_MCR_RTCTRIM_TRIM_X1_POS)) /**< RTCTRIM_TRIM_X1 Mask */

#define MXC_F_MCR_RTCTRIM_TRIM_X2_POS                  8 /**< RTCTRIM_TRIM_X2 Position */
#define MXC_F_MCR_RTCTRIM_TRIM_X2                      ((uint32_t)(0x1FUL << MXC_F_MCR_RTCTRIM_TRIM_X2_POS)) /**< RTCTRIM_TRIM_X2 Mask */

/**@} end of group MCR_RTCTRIM_Register */

/**
 * @ingroup  mcr_registers
 * @defgroup MCR_LDOCTRL MCR_LDOCTRL
 * @brief    LDO Control Register.
 * @{
 */
#define MXC_F_MCR_LDOCTRL_LDO0P9_EN_POS                0 /**< LDOCTRL_LDO0P9_EN Position */
#define MXC_F_MCR_LDOCTRL_LDO0P9_EN                    ((uint32_t)(0x1UL << MXC_F_MCR_LDOCTRL_LDO0P9_EN_POS)) /**< LDOCTRL_LDO0P9_EN Mask */

/**@} end of group MCR_LDOCTRL_Register */

#ifdef __cplusplus
}
#endif

#endif // LIBRARIES_CMSIS_DEVICE_MAXIM_MAX32572_INCLUDE_MCR_REGS_H_
