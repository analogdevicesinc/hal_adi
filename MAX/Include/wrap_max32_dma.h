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

#ifndef _WRAP_MAX32_DMA_H_
#define _WRAP_MAX32_DMA_H_

/***** Includes *****/
#include <dma.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  MAX32665, MAX32666 related mapping
 */
#if defined(CONFIG_SOC_MAX32665) || (CONFIG_SOC_MAX32666)

#define ADI_MAX32_DMA_CTRL_DIS_IE MXC_F_DMA_CFG_CHDIEN
#define ADI_MAX32_DMA_CTRL_CTZIEN MXC_F_DMA_CFG_CTZIEN

#define ADI_MAX32_DMA_STATUS_IPEND MXC_F_DMA_ST_IPEND
#define ADI_MAX32_DMA_STATUS_BUS_ERR MXC_F_DMA_ST_BUS_ERR
#define ADI_MAX32_DMA_STATUS_TO_IF MXC_F_DMA_ST_TO_ST
#define ADI_MAX32_DMA_STATUS_ST MXC_F_DMA_ST_CH_ST

#define ADI_MAX32_DMA_CFG_REQ_POS MXC_F_DMA_CFG_REQSEL_POS

static inline int MXC_DMA_GetIntFlags(mxc_dma_regs_t *dma)
{
    return dma->intr;
}

static inline int Wrap_MXC_DMA_Init(mxc_dma_regs_t *dma) 
{
    return MXC_DMA_Init(dma);
}

static inline void Wrap_MXC_DMA_DeInit(mxc_dma_regs_t *dma)
{
    MXC_DMA_DeInit(dma);
}

static inline int Wrap_MXC_DMA_AcquireChannel(mxc_dma_regs_t *dma)
{
    return MXC_DMA_AcquireChannel(dma);
}

static inline void Wrap_MXC_DMA_Handler(mxc_dma_regs_t *dma)
{
    MXC_DMA_Handler(dma);
}

static inline int Wrap_MXC_DMA_MemCpy(mxc_dma_regs_t *dma, void *dest, void *src, int len,
                   mxc_dma_complete_cb_t callback)
{
    return MXC_DMA_MemCpy(dma, dest, src, len, callback);
}

static inline int Wrap_MXC_DMA_DoTransfer(mxc_dma_regs_t *dma, mxc_dma_config_t config, mxc_dma_srcdst_t firstSrcDst,
                       mxc_dma_trans_chain_t callback)
{
   return MXC_DMA_DoTransfer(dma, config, firstSrcDst, callback);
}


/*
 *  MAX32690, MAX32655 related mapping
 */
#elif defined(CONFIG_SOC_MAX32690) || (CONFIG_SOC_MAX32655)

#define ADI_MAX32_DMA_CTRL_DIS_IE MXC_F_DMA_CTRL_DIS_IE
#define ADI_MAX32_DMA_CTRL_CTZIEN MXC_F_DMA_CTRL_CTZ_IE

#define ADI_MAX32_DMA_STATUS_IPEND MXC_F_DMA_STATUS_IPEND
#define ADI_MAX32_DMA_STATUS_BUS_ERR MXC_F_DMA_STATUS_BUS_ERR
#define ADI_MAX32_DMA_STATUS_TO_IF MXC_F_DMA_STATUS_TO_IF
#define ADI_MAX32_DMA_STATUS_ST MXC_F_DMA_STATUS_STATUS

#define ADI_MAX32_DMA_CFG_REQ_POS MXC_F_DMA_CTRL_REQUEST_POS

static inline int MXC_DMA_GetIntFlags(mxc_dma_regs_t *dma)
{
    return dma->intfl;
}

static inline int Wrap_MXC_DMA_Init(mxc_dma_regs_t *dma) 
{
    (void) dma;
    return MXC_DMA_Init();
}

static inline void Wrap_MXC_DMA_DeInit(mxc_dma_regs_t *dma)
{
    (void) dma;
    MXC_DMA_DeInit();
}

static inline int Wrap_MXC_DMA_AcquireChannel(mxc_dma_regs_t *dma)
{
    (void) dma;
    return MXC_DMA_AcquireChannel();
}

static inline void Wrap_MXC_DMA_Handler(mxc_dma_regs_t *dma)
{
    (void) dma;
    MXC_DMA_Handler();
}

static inline int Wrap_MXC_DMA_MemCpy(mxc_dma_regs_t *dma, void *dest, void *src, int len,
                   mxc_dma_complete_cb_t callback)
{
    (void) dma;
    return MXC_DMA_MemCpy(dest, src, len, callback);
}

static inline int Wrap_MXC_DMA_DoTransfer(mxc_dma_regs_t *dma, mxc_dma_config_t config, mxc_dma_srcdst_t firstSrcDst,
                       mxc_dma_trans_chain_t callback)
{
    (void) dma;
    return MXC_DMA_DoTransfer(config, firstSrcDst, callback);
}

#endif  // part number


#ifdef __cplusplus
}
#endif

#endif // _WRAP_MAX32_DMA_H_
