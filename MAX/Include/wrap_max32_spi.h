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

#ifndef _WRAP_MAX32_SPI_H_
#define _WRAP_MAX32_SPI_H_

/***** Includes *****/
#include <spi.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  MAX32665, MAX32666 related mapping
 */
#if defined(CONFIG_SOC_MAX32665) || (CONFIG_SOC_MAX32666)

static inline int Wrap_MXC_SPI_Init(mxc_spi_regs_t *spi, int masterMode, int quadModeUsed, 
                                    int numSlaves, unsigned ssPolarity, unsigned int hz)
{
    return  MXC_SPI_Init(spi, masterMode, quadModeUsed, numSlaves, ssPolarity, hz, (sys_map_t)0);
}


/*
 *  MAX32690, MAX32655 related mapping
 */
#elif defined(CONFIG_SOC_MAX32690) || (CONFIG_SOC_MAX32655)

static inline int Wrap_MXC_SPI_Init(mxc_spi_regs_t *spi, int masterMode, int quadModeUsed, 
                                    int numSlaves, unsigned ssPolarity, unsigned int hz)
{
    mxc_spi_pins_t tmp;// not used
    return  MXC_SPI_Init(spi, masterMode, quadModeUsed, numSlaves, ssPolarity, hz, tmp);
}

#endif  // part number


#ifdef __cplusplus
}
#endif

#endif // _WRAP_MAX32_SPI_H_
