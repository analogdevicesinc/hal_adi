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

#include "max32655.h"
#include "gcr_regs.h"
#include "icc.h"
#include "simo.h"


static int pre_init(void)
{
    uint32_t psc = MXC_GCR->clkctrl & MXC_F_GCR_CLKCTRL_SYSCLK_DIV;

    /* Divide down system clock until SIMO is ready */
    MXC_GCR->clkctrl = (MXC_GCR->clkctrl & ~(MXC_F_GCR_CLKCTRL_SYSCLK_DIV)) |
                       (MXC_S_GCR_CLKCTRL_SYSCLK_DIV_DIV128);

    while (!(MXC_SIMO->buck_out_ready & MXC_F_SIMO_BUCK_OUT_READY_BUCKOUTRDYA)) {}
    while (!(MXC_SIMO->buck_out_ready & MXC_F_SIMO_BUCK_OUT_READY_BUCKOUTRDYB)) {}
    while (!(MXC_SIMO->buck_out_ready & MXC_F_SIMO_BUCK_OUT_READY_BUCKOUTRDYC)) {}

    /* Restore system clock divider */
    MXC_GCR->clkctrl = (MXC_GCR->clkctrl & ~(MXC_F_GCR_CLKCTRL_SYSCLK_DIV)) | (psc);

    return 0;
}

/* 
 * This function is called during boot up.
 */
void max32xx_system_init(void)
{
    pre_init();
    
    /* Enable instruction cache */
    MXC_ICC_Enable(MXC_ICC0);

    /* Setup the SIMO voltages */
    MXC_SIMO_SetVregO_A(1750);
    while (MXC_SIMO_GetOutReadyA() != E_NO_ERROR) {}
    MXC_SIMO_SetVregO_B(1100);
    while (MXC_SIMO_GetOutReadyB() != E_NO_ERROR) {}
    MXC_SIMO_SetVregO_C(1100);
    while (MXC_SIMO_GetOutReadyC() != E_NO_ERROR) {}
}
