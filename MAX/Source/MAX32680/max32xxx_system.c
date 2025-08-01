/******************************************************************************
 *
 * Copyright (C) 2024 Analog Devices, Inc.
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

#include "max32680.h"
#include "icc.h"
#include "mcr_regs.h"

/* 
 * This function is called during boot up.
 */
void max32xx_system_init(void)
{
    /* Disable SRAM ECC until it is handled on zephyr side */
    MXC_MCR->eccen &= ~MXC_F_MCR_ECCEN_RAM0;

    /* Enable instruction cache */
    MXC_ICC_Enable(MXC_ICC0);
}
