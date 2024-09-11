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

#ifndef LIBRARIES_ZEPHYR_MAX_INCLUDE_WRAP_MAX32_SYS_H_
#define LIBRARIES_ZEPHYR_MAX_INCLUDE_WRAP_MAX32_SYS_H_

/***** Includes *****/
#include <mxc_sys.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  Apply preinit configuration for the target
 */
void max32xx_system_init(void);

/*
 *  MAX32665, MAX32666 related mapping
 */
#if defined(CONFIG_SOC_MAX32665) || (CONFIG_SOC_MAX32666)

#define ADI_MAX32_CLK_IPO MXC_SYS_CLOCK_HIRC96
#define ADI_MAX32_CLK_ERFO MXC_SYS_CLOCK_XTAL32M
#define ADI_MAX32_CLK_IBRO MXC_SYS_CLOCK_HIRC8
#define ADI_MAX32_CLK_ISO MXC_SYS_CLOCK_HIRC
#define ADI_MAX32_CLK_INRO MXC_SYS_CLOCK_LIRC8K
#define ADI_MAX32_CLK_ERTCO MXC_SYS_CLOCK_XTAL32K

#define z_sysclk_prescaler(v) MXC_SYS_SYSTEM_DIV_##v
#define sysclk_prescaler(v) z_sysclk_prescaler(v)

static inline void Wrap_MXC_SYS_SetClockDiv(int div)
{
    MXC_SYS_Clock_Div((mxc_sys_system_div_t)div);
}

/*
 *  MAX32690, MAX32655 related mapping
 */
#elif defined(CONFIG_SOC_MAX32690) || (CONFIG_SOC_MAX32655) || (CONFIG_SOC_MAX32670) || \
    (CONFIG_SOC_MAX32672) || (CONFIG_SOC_MAX32662) || (CONFIG_SOC_MAX32675) ||          \
    (CONFIG_SOC_MAX32680) || (CONFIG_SOC_MAX32657)

#define ADI_MAX32_CLK_IPO MXC_SYS_CLOCK_IPO
#define ADI_MAX32_CLK_ERFO MXC_SYS_CLOCK_ERFO
#define ADI_MAX32_CLK_IBRO MXC_SYS_CLOCK_IBRO
#define ADI_MAX32_CLK_INRO MXC_SYS_CLOCK_INRO
#define ADI_MAX32_CLK_ERTCO MXC_SYS_CLOCK_ERTCO
#define ADI_MAX32_CLK_EXTCLK MXC_SYS_CLOCK_EXTCLK
#if !(defined(CONFIG_SOC_MAX32670) || (CONFIG_SOC_MAX32672) || (CONFIG_SOC_MAX32662) || \
      (CONFIG_SOC_MAX32675))
#define ADI_MAX32_CLK_ISO MXC_SYS_CLOCK_ISO
#endif

#if !defined(CONFIG_SOC_MAX32690)

#define z_sysclk_prescaler(v) MXC_SYS_CLOCK_DIV_##v
#define sysclk_prescaler(v) z_sysclk_prescaler(v)

static inline void Wrap_MXC_SYS_SetClockDiv(int div)
{
    MXC_SYS_SetClockDiv((mxc_sys_system_clock_div_t)div);
}

#endif // !defined(CONFIG_SOC_MAX32690)

#endif // part number

#ifdef __cplusplus
}
#endif

#endif // LIBRARIES_ZEPHYR_MAX_INCLUDE_WRAP_MAX32_SYS_H_
