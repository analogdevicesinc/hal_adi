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

#ifndef _WRAP_MAX32_TMR_H_
#define _WRAP_MAX32_TMR_H_

/***** Includes *****/
#include <tmr.h>

#ifdef __cplusplus
extern "C" {
#endif


typedef struct {
    mxc_tmr_pres_t pres; 
    mxc_tmr_mode_t mode; 
    int bitMode; /* Some PN does not support it, check mxc_tmr_bit_mode_t in tmr.h file */
    int clock; /* Some PN does not support it, check mxc_tmr_clock_t in tmr.h file */
    uint32_t cmp_cnt; /**< Compare register value in timer ticks */
    unsigned pol; /**< Polarity (0 or 1) */
} wrap_mxc_tmr_cfg_t;

/*
 *  MAX32665, MAX32666 related mapping
 */
#if defined(CONFIG_SOC_MAX32665) || (CONFIG_SOC_MAX32666)

static inline int Wrap_MXC_TMR_Init(mxc_tmr_regs_t *tmr, wrap_mxc_tmr_cfg_t *cfg)
{
    mxc_tmr_cfg_t mxc_cfg;

    mxc_cfg.pres = cfg->pres;
    mxc_cfg.mode = cfg->mode;
    mxc_cfg.cmp_cnt = cfg->cmp_cnt;
    mxc_cfg.pol = cfg->pol;

    MXC_TMR_Init(tmr, &mxc_cfg);
    return 0;
}

static inline int Wrap_MXC_TMR_GetClockIndex(int z_clock)
{
    if (z_clock == 0) {
        /* Only peripheral clock is supported, just retunr 0 */
        return 0;
    } else {
        return -1; /* Not supported */
    }
}

/*
 *  MAX32690, MAX32655 related mapping
 */
#elif defined(CONFIG_SOC_MAX32690) || (CONFIG_SOC_MAX32655)

static inline int Wrap_MXC_TMR_Init(mxc_tmr_regs_t *tmr, wrap_mxc_tmr_cfg_t *cfg)
{
    mxc_tmr_cfg_t mxc_cfg;

    mxc_cfg.pres = cfg->pres;
    mxc_cfg.mode = cfg->mode;
    mxc_cfg.cmp_cnt = cfg->cmp_cnt;
    mxc_cfg.pol = cfg->pol;
    mxc_cfg.bitMode = (mxc_tmr_bit_mode_t) cfg->bitMode;
    mxc_cfg.clock = (mxc_tmr_clock_t) cfg->clock;
    
    return  MXC_TMR_Init(tmr, &mxc_cfg, 0); // init_pins not used
}

static inline int Wrap_MXC_TMR_GetClockIndex(int z_clock)
{
    switch (z_clock) {
    case 0: // ADI_MAX32_PRPH_CLK_SRC_PCLK
        return MXC_TMR_APB_CLK;
    case 1: // ADI_MAX32_PRPH_CLK_SRC_EXTCLK
        return MXC_TMR_EXT_CLK;
    case 2: // ADI_MAX32_PRPH_CLK_SRC_IBRO
        return MXC_TMR_8M_CLK;
    case 3: //ADI_MAX32_PRPH_CLK_SRC_ERFO
        return MXC_TMR_32M_CLK;
    case 4: //ADI_MAX32_PRPH_CLK_SRC_ERTCO
        return MXC_TMR_32K_CLK;
    case 5: //ADI_MAX32_PRPH_CLK_SRC_INRO
        return MXC_TMR_8K_CLK;
#if defined(CONFIG_SOC_MAX32690)
    case 6: //ADI_MAX32_PRPH_CLK_SRC_ISO
        return MXC_TMR_60M_CLK;
#endif
    }

    return -1; /* Not supported */
}

#endif  // part number


#ifdef __cplusplus
}
#endif

#endif // _WRAP_MAX32_TMR_H_
