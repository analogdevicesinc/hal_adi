/******************************************************************************
 *
 * Copyright (C) 2023 Analog Devices, Inc.
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

#ifndef _WRAP_MAX32_I2C_H_
#define _WRAP_MAX32_I2C_H_

/***** Includes *****/
#include <i2c.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  MAX32665, MAX32666 related mapping
 */
#if defined(CONFIG_SOC_MAX32665) || (CONFIG_SOC_MAX32666)

#define ADI_MAX32_I2C_INT_FL0_ERR                                                                \
    (MXC_F_I2C_INT_FL0_ARB_ER | MXC_F_I2C_INT_FL0_TO_ER | MXC_F_I2C_INT_FL0_ADDR_NACK_ER |       \
     MXC_F_I2C_INT_FL0_DATA_ER | MXC_F_I2C_INT_FL0_DO_NOT_RESP_ER | MXC_F_I2C_INT_FL0_START_ER | \
     MXC_F_I2C_INT_FL0_STOP_ER)

#define ADI_MAX32_I2C_INT_EN0_ERR                                                                \
    (MXC_F_I2C_INT_EN0_ARB_ER | MXC_F_I2C_INT_EN0_TO_ER | MXC_F_I2C_INT_EN0_ADDR_NACK_ER |       \
     MXC_F_I2C_INT_EN0_DATA_ER | MXC_F_I2C_INT_EN0_DO_NOT_RESP_ER | MXC_F_I2C_INT_EN0_START_ER | \
     MXC_F_I2C_INT_EN0_STOP_ER)

#define ADI_MAX32_I2C_INT_EN0_RX_THD MXC_F_I2C_INT_EN0_RX_THRESH
#define ADI_MAX32_I2C_INT_EN0_TX_LOCK_OUT MXC_F_I2C_INT_EN0_TX_LOCK_OUT
#define ADI_MAX32_I2C_INT_EN0_TX_THD MXC_F_I2C_INT_EN0_TX_THRESH
#define ADI_MAX32_I2C_INT_EN0_DONE MXC_F_I2C_INT_EN0_DONE
#define ADI_MAX32_I2C_INT_EN0_ADDR_MATCH MXC_F_I2C_INT_EN0_ADDR_MATCH
#define ADI_MAX32_I2C_INT_EN1_RX_OVERFLOW MXC_F_I2C_INT_EN1_RX_OVERFLOW
#define ADI_MAX32_I2C_INT_EN1_TX_UNDERFLOW MXC_F_I2C_INT_EN1_TX_UNDERFLOW

#define ADI_MAX32_I2C_INT_FL0_RX_THD MXC_F_I2C_INT_FL0_RX_THRESH
#define ADI_MAX32_I2C_INT_FL0_TX_LOCK_OUT MXC_F_I2C_INT_FL0_TX_LOCK_OUT
#define ADI_MAX32_I2C_INT_FL0_TX_THD MXC_F_I2C_INT_FL0_TX_THRESH
#define ADI_MAX32_I2C_INT_FL0_ADDR_MATCH MXC_F_I2C_INT_FL0_ADDR_MATCH
#define ADI_MAX32_I2C_INT_FL0_STOP MXC_F_I2C_INT_FL0_STOP
#define ADI_MAX32_I2C_INT_FL0_DONE MXC_F_I2C_INT_FL0_DONE
#define ADI_MAX32_I2C_INT_FL1_RX_OVERFLOW MXC_F_I2C_INT_FL1_RX_OVERFLOW

static inline void Wrap_MXC_I2C_GetIntEn(mxc_i2c_regs_t *i2c, unsigned int *int_en0,
                                         unsigned int *int_en1)
{
    *int_en0 = i2c->int_en0;
    *int_en1 = i2c->int_en1;
}

static inline void Wrap_MXC_I2C_SetIntEn(mxc_i2c_regs_t *i2c, unsigned int int_en0,
                                         unsigned int int_en1)
{
    i2c->int_en0 = int_en0;
    i2c->int_en1 = int_en1;
}

/*
 *  MAX32690, MAX32655 related mapping
 */
#elif defined(CONFIG_SOC_MAX32690) || (CONFIG_SOC_MAX32655)

#define ADI_MAX32_I2C_INT_FL0_ERR                                                          \
    (MXC_F_I2C_INTFL0_ARB_ERR | MXC_F_I2C_INTFL0_TO_ERR | MXC_F_I2C_INTFL0_ADDR_NACK_ERR | \
     MXC_F_I2C_INTFL0_DATA_ERR | MXC_F_I2C_INTFL0_DNR_ERR | MXC_F_I2C_INTFL0_START_ERR |   \
     MXC_F_I2C_INTFL0_STOP_ERR)

#define ADI_MAX32_I2C_INT_EN0_ERR                                                          \
    (MXC_F_I2C_INTEN0_ARB_ERR | MXC_F_I2C_INTEN0_TO_ERR | MXC_F_I2C_INTEN0_ADDR_NACK_ERR | \
     MXC_F_I2C_INTEN0_DATA_ERR | MXC_F_I2C_INTEN0_DNR_ERR | MXC_F_I2C_INTEN0_START_ERR |   \
     MXC_F_I2C_INTEN0_STOP_ERR)

#define ADI_MAX32_I2C_INT_EN0_RX_THD MXC_F_I2C_INTEN0_RX_THD
#define ADI_MAX32_I2C_INT_EN0_TX_LOCK_OUT MXC_F_I2C_INTEN0_TX_LOCKOUT
#define ADI_MAX32_I2C_INT_EN0_TX_THD MXC_F_I2C_INTEN0_TX_THD
#define ADI_MAX32_I2C_INT_EN0_DONE MXC_F_I2C_INTEN0_DONE
#define ADI_MAX32_I2C_INT_EN0_ADDR_MATCH MXC_F_I2C_INTEN0_ADDR_MATCH
#define ADI_MAX32_I2C_INT_EN1_RX_OVERFLOW MXC_F_I2C_INTEN1_RX_OV
#define ADI_MAX32_I2C_INT_EN1_TX_UNDERFLOW MXC_F_I2C_INTEN1_TX_UN

#define ADI_MAX32_I2C_INT_FL0_RX_THD MXC_F_I2C_INTFL0_RX_THD
#define ADI_MAX32_I2C_INT_FL0_TX_LOCK_OUT MXC_F_I2C_INTFL0_TX_LOCKOUT
#define ADI_MAX32_I2C_INT_FL0_TX_THD MXC_F_I2C_INTFL0_TX_THD
#define ADI_MAX32_I2C_INT_FL0_ADDR_MATCH MXC_F_I2C_INTFL0_ADDR_MATCH
#define ADI_MAX32_I2C_INT_FL0_STOP MXC_F_I2C_INTFL0_STOP
#define ADI_MAX32_I2C_INT_FL0_DONE MXC_F_I2C_INTFL0_DONE
#define ADI_MAX32_I2C_INT_FL1_RX_OVERFLOW MXC_F_I2C_INTFL1_RX_OV

static inline void Wrap_MXC_I2C_GetIntEn(mxc_i2c_regs_t *i2c, unsigned int *int_en0,
                                         unsigned int *int_en1)
{
    *int_en0 = i2c->inten0;
    *int_en1 = i2c->inten1;
}

static inline void Wrap_MXC_I2C_SetIntEn(mxc_i2c_regs_t *i2c, unsigned int int_en0,
                                         unsigned int int_en1)
{
    i2c->inten0 = int_en0;
    i2c->inten1 = int_en1;
}

#endif

#ifdef __cplusplus
}
#endif

#endif /* _WRAP_MAX32_I2C_H_ */
