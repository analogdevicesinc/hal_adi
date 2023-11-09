/******************************************************************************
 * Copyright (C) 2023 Maxim Integrated Products, Inc., All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL MAXIM INTEGRATED BE LIABLE FOR ANY CLAIM, DAMAGES
 * OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * Except as contained in this notice, the name of Maxim Integrated
 * Products, Inc. shall not be used except as stated in the Maxim Integrated
 * Products, Inc. Branding Policy.
 *
 * The mere transfer of this software does not imply any licenses
 * of trade secrets, proprietary technology, copyrights, patents,
 * trademarks, maskwork rights, or any other form of intellectual
 * property whatsoever. Maxim Integrated Products, Inc. retains all
 * ownership rights.
 *
 ******************************************************************************/

#ifndef _WRAP_MAX32_SYS_H_
#define _WRAP_MAX32_SYS_H_

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

#define ADI_MAX32_CLK_IPO   MXC_SYS_CLOCK_HIRC96
#define ADI_MAX32_CLK_ERFO  MXC_SYS_CLOCK_XTAL32M
#define ADI_MAX32_CLK_IBRO  MXC_SYS_CLOCK_HIRC8
#define ADI_MAX32_CLK_ISO   MXC_SYS_CLOCK_HIRC
#define ADI_MAX32_CLK_INRO  MXC_SYS_CLOCK_LIRC8K
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
#elif defined(CONFIG_SOC_MAX32690) || (CONFIG_SOC_MAX32655)

#define ADI_MAX32_CLK_IPO    MXC_SYS_CLOCK_IPO
#define ADI_MAX32_CLK_ERFO   MXC_SYS_CLOCK_ERFO
#define ADI_MAX32_CLK_IBRO   MXC_SYS_CLOCK_IBRO
#define ADI_MAX32_CLK_ISO    MXC_SYS_CLOCK_ISO
#define ADI_MAX32_CLK_INRO   MXC_SYS_CLOCK_INRO
#define ADI_MAX32_CLK_ERTCO  MXC_SYS_CLOCK_ERTCO
#define ADI_MAX32_CLK_EXTCLK MXC_SYS_CLOCK_EXTCLK

#if !defined(CONFIG_SOC_MAX32690)

#define z_sysclk_prescaler(v) MXC_SYS_CLOCK_DIV_##v
#define sysclk_prescaler(v) z_sysclk_prescaler(v)

static inline void Wrap_MXC_SYS_SetClockDiv(int div)
{
    MXC_SYS_SetClockDiv((mxc_sys_system_clock_div_t)div);
}

#endif // !defined(CONFIG_SOC_MAX32690)

#endif  // part number


#ifdef __cplusplus
}
#endif

#endif // _WRAP_MAX32_SYS_H_
