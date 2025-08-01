/**
 * @file    aes_regs.h
 * @brief   Registers, Bit Masks and Bit Positions for the AES Peripheral Module.
 * @note    This file is @deprecated.
 */

/******************************************************************************
 *
 * Copyright (C) 2022-2023 Maxim Integrated Products, Inc. (now owned by 
 * Analog Devices, Inc.),
 * Copyright (C) 2023-2024 Analog Devices, Inc.
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

#ifndef LIBRARIES_CMSIS_DEVICE_MAXIM_MAX32520_INCLUDE_AES_REGS_H_
#define LIBRARIES_CMSIS_DEVICE_MAXIM_MAX32520_INCLUDE_AES_REGS_H_

#warning "DEPRECATED(1-10-2023): aes_regs.h - Scheduled for removal. Please use aeskeys_regs.h."

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
 * @ingroup     aes
 * @defgroup    aes_registers AES_Registers
 * @brief       Registers, Bit Masks and Bit Positions for the AES Peripheral Module.
 * @details     AES Keys.
 */

/**
 * @ingroup aes_registers
 * Structure type to access the AES Registers.
 */
#if defined(__GNUC__)
__attribute__((deprecated("mxc_aes_regs_t struct and aes_regs.h no longer supported. Use aeskeys_regs.h and MXC_AESKEYS (mxc_aeskeys_regs_t) for AES Key Access. 1-10-2023")))
#else
#warning "mxc_aes_regs_t struct and aes_regs.h no longer supported. Use aeskeys_regs.h and MXC_AESKEYS (mxc_aeskeys_regs_t) for AES Key Access. 1-10-2023"
#endif
typedef struct {
    __IO uint32_t aes_sram_key;         /**< <tt>\b 0x000:</tt> AES AES_SRAM_KEY Register */
    __R  uint32_t rsv_0x4_0x7f[31];
    __IO uint32_t aes_code_key;         /**< <tt>\b 0x080:</tt> AES AES_CODE_KEY Register */
    __R  uint32_t rsv_0x84_0xff[31];
    __IO uint32_t aes_data_key;         /**< <tt>\b 0x100:</tt> AES AES_DATA_KEY Register */
} mxc_aes_regs_t;

/* Register offsets for module AES */
/**
 * @ingroup    aes_registers
 * @defgroup   AES_Register_Offsets Register Offsets
 * @brief      AES Peripheral Register Offsets from the AES Base Peripheral Address.
 * @{
 */
#define MXC_R_AES_AES_SRAM_KEY             ((uint32_t)0x00000000UL) /**< Offset from AES Base Address: <tt> 0x0000</tt> */
#define MXC_R_AES_AES_CODE_KEY             ((uint32_t)0x00000080UL) /**< Offset from AES Base Address: <tt> 0x0080</tt> */
#define MXC_R_AES_AES_DATA_KEY             ((uint32_t)0x00000100UL) /**< Offset from AES Base Address: <tt> 0x0100</tt> */
/**@} end of group aes_registers */

#ifdef __cplusplus
}
#endif

#endif // LIBRARIES_CMSIS_DEVICE_MAXIM_MAX32520_INCLUDE_AES_REGS_H_
