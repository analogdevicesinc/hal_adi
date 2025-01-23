/**
 * @file    icc.h
 * @brief   Instruction Controller Cache(ICC) function prototypes and data types.
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

/* Define to prevent redundant inclusion */
#ifndef LIBRARIES_PERIPHDRIVERS_INCLUDE_MAX32650_ICC_H_
#define LIBRARIES_PERIPHDRIVERS_INCLUDE_MAX32650_ICC_H_

/* **** Includes **** */
#include <stdint.h>
#include "icc_regs.h"
#include "max32650.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup icc Internal Cache Controller (ICC)
 * @ingroup periphlibs
 * @{
 */

/**
 * @brief Enumeration type for the Cache ID Register
 */
typedef enum {
    ICC_INFO_RELNUM, ///< Identifies the RTL release version
    ICC_INFO_PARTNUM, ///< Specifies the value of C_ID Port Number
    ICC_INFO_ID ///< Specifies the value of Cache ID
} mxc_icc_info_t;

/**
 * @brief   Reads ID information from the MXC_ICC0 Cache ID Register.
 * @param   cid     Selects what information to get from the MXC_ICC0 Cache ID Register
 * @retval  Returns the selected value from the MXC_ICC0 Cache ID Register.
 */
int MXC_ICC_ID(mxc_icc_info_t cid);

/**
 * @brief	Enables both of the instruction cache controllers.
 */
void MXC_ICC_Enable(void);

/**
 * @brief	Disables both of the instruction cache controllers.
 */
void MXC_ICC_Disable(void);

/**
 * @brief	Flushes both of the instruction cache controllers.
 */
void MXC_ICC_Flush(void);

/**
 * @brief   Reads ID information from one of the ICC's Cache ID Register.
 * @param   icc     Pointer ICC instance to get ID information from.
 * @param   cid     Selects what information to get from the Cache ID Register
 * @retval  Returns the selected value from the Cache ID Register.
 */
int MXC_ICC_IDInst(mxc_icc_regs_t *icc, mxc_icc_info_t cid);

/**
 * @brief   Enables one of the ICC's.
 * @param   icc     Pointer to ICC instance to enable.
 */
void MXC_ICC_EnableInst(mxc_icc_regs_t *icc);

/**
 * @brief   Disables one of the ICC's.
 * @param   icc     Pointer to ICC instance to disable.
 */
void MXC_ICC_DisableInst(mxc_icc_regs_t *icc);

/**
 * @brief   Flushes data from one of the ICC's.
 * @param   icc     Pointer to ICC instance to flush.
 */
void MXC_ICC_FlushInst(mxc_icc_regs_t *icc);

/**@} end of group icc */

#ifdef __cplusplus
}
#endif

#endif // LIBRARIES_PERIPHDRIVERS_INCLUDE_MAX32650_ICC_H_
