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

#ifndef _WRAP_MAX32_UART_H_
#define _WRAP_MAX32_UART_H_

/***** Includes *****/
#include <uart.h>

#ifdef __cplusplus
extern "C" {
#endif

#if defined(CONFIG_SOC_MAX32665) || (CONFIG_SOC_MAX32666)
// status flags
#define ADI_MAX32_UART_RX_EMPTY MXC_F_UART_STATUS_RX_EMPTY
#define ADI_MAX32_UART_TX_EMPTY MXC_F_UART_STATUS_TX_EMPTY
// error flags
#define ADI_MAX32_UART_ERROR_OVERRUN  MXC_F_UART_INT_FL_RX_OVERRUN
#define ADI_MAX32_UART_ERROR_PARITY   MXC_F_UART_INT_FL_RX_PARITY_ERROR
#define ADI_MAX32_UART_ERROR_FRAMING  MXC_F_UART_INT_FL_RX_FRAME_ERROR
// interrupt flag
#define ADI_MAX32_UART_INT_EOT MXC_F_UART_INT_EN_LAST_BREAK // End Of Transmission Interrupt
#define ADI_MAX32_UART_INT_OE MXC_F_UART_INT_EN_RX_OVERRUN // Overrun Error Interrupt
#define ADI_MAX32_UART_INT_BE MXC_F_UART_INT_EN_BREAK // Break Error Interrupt
#define ADI_MAX32_UART_INT_PE MXC_F_UART_INT_EN_RX_PARITY_ERROR // Parity Error Interrupt
#define ADI_MAX32_UART_INT_FE MXC_F_UART_INT_EN_RX_FRAME_ERROR // Framing Error Interrupt
#define ADI_MAX32_UART_INT_RT MXC_F_UART_INT_EN_RX_TIMEOUT // Receive Timeout Interrupt
#define ADI_MAX32_UART_INT_TX MXC_F_UART_INT_EN_TX_FIFO_THRESH // Transmit Interrupt
#define ADI_MAX32_UART_INT_RX MXC_F_UART_INT_EN_RX_FIFO_THRESH // Receive Interrupt
#define ADI_MAX32_UART_INT_CTS MXC_F_UART_INT_EN_CTS_CHANGE // CTS Modem Interrupt
// parity
#define	ADI_MAX32_UART_CFG_PARITY_NONE MXC_UART_PARITY_DISABLE
#define	ADI_MAX32_UART_CFG_PARITY_ODD MXC_UART_PARITY_ODD
#define	ADI_MAX32_UART_CFG_PARITY_EVEN MXC_UART_PARITY_EVEN
#define	ADI_MAX32_UART_CFG_PARITY_MARK MXC_UART_PARITY_MARK
#define	ADI_MAX32_UART_CFG_PARITY_SPACE MXC_UART_PARITY_SPACE

/* Error interrupts */
#define ADI_MAX32_UART_ERROR_INTERRUPTS \
    (ADI_MAX32_UART_INT_OE | ADI_MAX32_UART_INT_PE | ADI_MAX32_UART_INT_FE)

static inline int Wrap_MXC_UART_Init(mxc_uart_regs_t *uart)
{
    int ret;
    
    ret = MXC_UART_SetRXThreshold(uart, 1);
    if (ret) {
        return ret;
    }

    // default values as per of MSDK
    ret = MXC_UART_SetTXThreshold(uart, 2);
    if (ret) {
        return ret;
    }

    uart->ctrl |= MXC_F_UART_CTRL_ENABLE;
    
    return ret;
}

static inline int Wrap_MXC_UART_SetFrequency(mxc_uart_regs_t *uart, unsigned int baud, int clock_source)
{
    (void) clock_source;
    return MXC_UART_SetFrequency(uart, baud);
}

static inline void Wrap_MXC_UART_SetTxDMALevel(mxc_uart_regs_t *uart, uint8_t bytes)
{
    uart->dma |= ((bytes & 0x1F) << MXC_F_UART_DMA_TXDMA_LEVEL_POS);
}

static inline void Wrap_MXC_UART_SetRxDMALevel(mxc_uart_regs_t *uart, uint8_t bytes)
{
    uart->dma |= ((bytes & 0x1F) << MXC_F_UART_DMA_RXDMA_LEVEL_POS);
}

static inline void Wrap_MXC_UART_EnableTxDMA(mxc_uart_regs_t *uart)
{
    uart->dma |= MXC_F_UART_DMA_TXDMA_EN;
}

static inline void Wrap_MXC_UART_EnableRxDMA(mxc_uart_regs_t *uart)
{
    uart->dma |= MXC_F_UART_DMA_RXDMA_EN;
}

static inline void Wrap_MXC_UART_DisableTxDMA(mxc_uart_regs_t *uart)
{
    uart->dma &= ~MXC_F_UART_DMA_TXDMA_EN;
}

static inline void Wrap_MXC_UART_DisableRxDMA(mxc_uart_regs_t *uart)
{
    uart->dma &= ~MXC_F_UART_DMA_RXDMA_EN;
}

/*
 *  MAX32690, MAX32655 related mapping
 */
#elif defined(CONFIG_SOC_MAX32690) || (CONFIG_SOC_MAX32655)
// status flags
#define ADI_MAX32_UART_RX_EMPTY MXC_F_UART_STATUS_RX_EM
#define ADI_MAX32_UART_TX_EMPTY MXC_F_UART_STATUS_TX_EM
// error flags
#define ADI_MAX32_UART_ERROR_OVERRUN  MXC_F_UART_INT_FL_RX_OV
#define ADI_MAX32_UART_ERROR_PARITY   MXC_F_UART_INT_FL_RX_PAR
#define ADI_MAX32_UART_ERROR_FRAMING  MXC_F_UART_INT_FL_RX_FERR
// interrupt flag
#define ADI_MAX32_UART_INT_OE MXC_F_UART_INT_EN_RX_OV // Overrun Error Interrupt
#define ADI_MAX32_UART_INT_PE MXC_F_UART_INT_EN_RX_PAR // Parity Error Interrupt
#define ADI_MAX32_UART_INT_FE MXC_F_UART_INT_EN_RX_FERR // Framing Error Interrupt
#define ADI_MAX32_UART_INT_TX MXC_F_UART_INT_EN_TX_HE // Transmit Interrupt
#define ADI_MAX32_UART_INT_RX MXC_F_UART_INT_EN_RX_THD // Receive Interrupt
#define ADI_MAX32_UART_INT_CTS MXC_F_UART_INT_EN_CTS_EV // CTS Modem Interrupt
//#define ADI_MAX32_UART_INT_RT   // Receive Timeout Interrupt
//#define ADI_MAX32_UART_INT_BE   // Break Error Interrupt
//#define ADI_MAX32_UART_INT_EOT  // End Of Transmission Interrupt
// parity
#define	ADI_MAX32_UART_CFG_PARITY_NONE MXC_UART_PARITY_DISABLE
#define	ADI_MAX32_UART_CFG_PARITY_ODD MXC_UART_PARITY_ODD_0
#define	ADI_MAX32_UART_CFG_PARITY_EVEN MXC_UART_PARITY_EVEN_0
//#define	ADI_MAX32_UART_CFG_PARITY_MARK
//#define	ADI_MAX32_UART_CFG_PARITY_SPACE

/* Error interrupts */
#define ADI_MAX32_UART_ERROR_INTERRUPTS \
    (ADI_MAX32_UART_INT_OE | ADI_MAX32_UART_INT_PE | ADI_MAX32_UART_INT_FE)

static inline int Wrap_MXC_UART_Init(mxc_uart_regs_t *uart)
{
    int ret;
    
    ret = MXC_UART_SetRXThreshold(uart, 1);
    
    return ret;
}

static inline int Wrap_MXC_UART_SetFrequency(mxc_uart_regs_t *uart, unsigned int baud, int clock_source)
{
    return MXC_UART_SetFrequency(uart, baud, (mxc_uart_clock_t)clock_source);
}

static inline void Wrap_MXC_UART_SetTxDMALevel(mxc_uart_regs_t *uart, uint8_t bytes)
{
    uart->dma |= ((bytes & 0xF) << MXC_F_UART_DMA_TX_THD_VAL_POS);
}

static inline void Wrap_MXC_UART_SetRxDMALevel(mxc_uart_regs_t *uart, uint8_t bytes)
{
    uart->dma |= ((bytes & 0xF) << MXC_F_UART_DMA_RX_THD_VAL_POS);
}

static inline void Wrap_MXC_UART_EnableTxDMA(mxc_uart_regs_t *uart)
{
    uart->dma |= MXC_F_UART_DMA_TX_EN;
}

static inline void Wrap_MXC_UART_EnableRxDMA(mxc_uart_regs_t *uart)
{
    uart->dma |= MXC_F_UART_DMA_RX_EN;
}

static inline void Wrap_MXC_UART_DisableTxDMA(mxc_uart_regs_t *uart)
{
    uart->dma &= ~MXC_F_UART_DMA_TX_EN;
}

static inline void Wrap_MXC_UART_DisableRxDMA(mxc_uart_regs_t *uart)
{
    uart->dma &= ~MXC_F_UART_DMA_RX_EN;
}

#endif // defined(CONFIG_SOC_MAX32690) || (CONFIG_SOC_MAX32655)

#ifdef __cplusplus
}
#endif

#endif // _WRAP_MAX32_UART_H_
