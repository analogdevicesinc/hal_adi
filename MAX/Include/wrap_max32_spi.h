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
