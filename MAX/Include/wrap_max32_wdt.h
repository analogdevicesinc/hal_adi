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

#ifndef _WRAP_MAX32_WDT_H_
#define _WRAP_MAX32_WDT_H_

/***** Includes *****/
#include <wdt.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    char mode; ///< WDT mode
    mxc_wdt_period_t upperResetPeriod; ///< Reset upper limit
    mxc_wdt_period_t lowerResetPeriod; ///< Reset lower limit
    mxc_wdt_period_t upperIntPeriod; ///< Interrupt upper limit
    mxc_wdt_period_t lowerIntPeriod; ///< Interrupt lower limit
} wrap_mxc_wdt_cfg_t;

/*
 *  MAX32665, MAX32666 related mapping
 */
#if defined(CONFIG_SOC_MAX32665) || (CONFIG_SOC_MAX32666)

typedef enum {
    MXC_WDT_COMPATIBILITY = 0,
    MXC_WDT_WINDOWED = 1, /* Not support on MAX32665/6, added here to get common zephyr driver */
} mxc_wdt_mode_t;

static inline int Wrap_MXC_WDT_Init(mxc_wdt_regs_t *wdt, wrap_mxc_wdt_cfg_t *cfg)
{
    int ret;

    if (cfg && ((mxc_wdt_mode_t)cfg->mode == MXC_WDT_COMPATIBILITY)) {
        /* only support compatibility mode */
        ret = MXC_WDT_Init(wdt);
    } else {
        ret = -1;
    }

    return ret;
}

static inline void Wrap_MXC_WDT_SetResetPeriod(mxc_wdt_regs_t *wdt, wrap_mxc_wdt_cfg_t *cfg)
{
    (void) cfg;

    MXC_WDT_SetResetPeriod(wdt, cfg->upperResetPeriod);
}

static inline void Wrap_MXC_WDT_SetIntPeriod(mxc_wdt_regs_t *wdt, wrap_mxc_wdt_cfg_t *cfg)
{    
    return  MXC_WDT_SetIntPeriod(wdt, cfg->upperIntPeriod);
}

/*
 *  MAX32690, MAX32655 related mapping
 */
#elif defined(CONFIG_SOC_MAX32690) || (CONFIG_SOC_MAX32655)

static inline int Wrap_MXC_WDT_Init(mxc_wdt_regs_t *wdt, wrap_mxc_wdt_cfg_t *cfg)
{
    mxc_wdt_cfg_t mxc_cfg;

    mxc_cfg.mode = (mxc_wdt_mode_t) cfg->mode;
    mxc_cfg.upperResetPeriod = cfg->upperResetPeriod;
    mxc_cfg.lowerResetPeriod = cfg->lowerResetPeriod;
    mxc_cfg.upperIntPeriod = cfg->upperIntPeriod;
    mxc_cfg.lowerIntPeriod = cfg->lowerIntPeriod;
    
    return  MXC_WDT_Init(wdt, &mxc_cfg);
}

static inline void Wrap_MXC_WDT_SetResetPeriod(mxc_wdt_regs_t *wdt, wrap_mxc_wdt_cfg_t *cfg)
{
    MXC_WDT_SetResetPeriod(wdt, (mxc_wdt_cfg_t *) cfg);
}

static inline void Wrap_MXC_WDT_SetIntPeriod(mxc_wdt_regs_t *wdt, wrap_mxc_wdt_cfg_t *cfg)
{
    mxc_wdt_cfg_t mxc_cfg;

    mxc_cfg.mode = (mxc_wdt_mode_t) cfg->mode;
    mxc_cfg.upperResetPeriod = cfg->upperResetPeriod;
    mxc_cfg.lowerResetPeriod = cfg->lowerResetPeriod;
    mxc_cfg.upperIntPeriod = cfg->upperIntPeriod;
    mxc_cfg.lowerIntPeriod = cfg->lowerIntPeriod;
    
    return  MXC_WDT_SetIntPeriod(wdt, &mxc_cfg);
}

#endif  // part number


#ifdef __cplusplus
}
#endif

#endif // _WRAP_MAX32_WDT_H_
