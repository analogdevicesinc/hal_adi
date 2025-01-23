/**
 * @file    sc_regs.h
 * @brief   Registers, Bit Masks and Bit Positions for the SC Peripheral Module.
 */

/******************************************************************************
* Copyright (C) 2022 Maxim Integrated Products, Inc., All Rights Reserved.
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

#ifndef _SC_REGS_H_
#define _SC_REGS_H_

/* **** Includes **** */
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#if defined (__ICCARM__)
  #pragma system_include
#endif

#if defined (__CC_ARM)
  #pragma anon_unions
#endif
/// @cond
/*
    If types are not defined elsewhere (CMSIS) define them here
*/
#ifndef __IO
#define __IO volatile
#endif
#ifndef __I
#define __I  volatile const
#endif
#ifndef __O
#define __O  volatile
#endif
#ifndef __R
#define __R  volatile const
#endif
/// @endcond

/* **** Definitions **** */

/**
 * @ingroup     sc
 * @defgroup    sc_registers SC_Registers
 * @brief       Registers, Bit Masks and Bit Positions for the SC Peripheral Module.
 * @details Smart Card Interface.
 */

/**
 * @ingroup sc_registers
 * Structure type to access the SC Registers.
 */
typedef struct {
    __IO uint32_t cr;                   /**< <tt>\b 0x00:</tt> SC CR Register */
    __IO uint32_t sr;                   /**< <tt>\b 0x04:</tt> SC SR Register */
    __IO uint32_t pn;                   /**< <tt>\b 0x08:</tt> SC PN Register */
    __IO uint32_t etur;                 /**< <tt>\b 0x0C:</tt> SC ETUR Register */
    __IO uint32_t gtr;                  /**< <tt>\b 0x10:</tt> SC GTR Register */
    __IO uint32_t wt0r;                 /**< <tt>\b 0x14:</tt> SC WT0R Register */
    __IO uint32_t wt1r;                 /**< <tt>\b 0x18:</tt> SC WT1R Register */
    __IO uint32_t ier;                  /**< <tt>\b 0x1C:</tt> SC IER Register */
    __IO uint32_t isr;                  /**< <tt>\b 0x20:</tt> SC ISR Register */
    __IO uint32_t txr;                  /**< <tt>\b 0x24:</tt> SC TXR Register */
    __IO uint32_t rxr;                  /**< <tt>\b 0x28:</tt> SC RXR Register */
    __IO uint32_t ccr;                  /**< <tt>\b 0x2C:</tt> SC CCR Register */
} mxc_sc_regs_t;

/* Register offsets for module SC */
/**
 * @ingroup    sc_registers
 * @defgroup   SC_Register_Offsets Register Offsets
 * @brief      SC Peripheral Register Offsets from the SC Base Peripheral Address.
 * @{
 */
 #define MXC_R_SC_CR                        ((uint32_t)0x00000000UL) /**< Offset from SC Base Address: <tt> 0x0000</tt> */ 
 #define MXC_R_SC_SR                        ((uint32_t)0x00000004UL) /**< Offset from SC Base Address: <tt> 0x0004</tt> */ 
 #define MXC_R_SC_PN                        ((uint32_t)0x00000008UL) /**< Offset from SC Base Address: <tt> 0x0008</tt> */ 
 #define MXC_R_SC_ETUR                      ((uint32_t)0x0000000CUL) /**< Offset from SC Base Address: <tt> 0x000C</tt> */ 
 #define MXC_R_SC_GTR                       ((uint32_t)0x00000010UL) /**< Offset from SC Base Address: <tt> 0x0010</tt> */ 
 #define MXC_R_SC_WT0R                      ((uint32_t)0x00000014UL) /**< Offset from SC Base Address: <tt> 0x0014</tt> */ 
 #define MXC_R_SC_WT1R                      ((uint32_t)0x00000018UL) /**< Offset from SC Base Address: <tt> 0x0018</tt> */ 
 #define MXC_R_SC_IER                       ((uint32_t)0x0000001CUL) /**< Offset from SC Base Address: <tt> 0x001C</tt> */ 
 #define MXC_R_SC_ISR                       ((uint32_t)0x00000020UL) /**< Offset from SC Base Address: <tt> 0x0020</tt> */ 
 #define MXC_R_SC_TXR                       ((uint32_t)0x00000024UL) /**< Offset from SC Base Address: <tt> 0x0024</tt> */ 
 #define MXC_R_SC_RXR                       ((uint32_t)0x00000028UL) /**< Offset from SC Base Address: <tt> 0x0028</tt> */ 
 #define MXC_R_SC_CCR                       ((uint32_t)0x0000002CUL) /**< Offset from SC Base Address: <tt> 0x002C</tt> */ 
/**@} end of group sc_registers */

/**
 * @ingroup  sc_registers
 * @defgroup SC_CR SC_CR
 * @brief    Control Register.
 * @{
 */
 #define MXC_F_SC_CR_CONV_POS                           0 /**< CR_CONV Position */
 #define MXC_F_SC_CR_CONV                               ((uint32_t)(0x1UL << MXC_F_SC_CR_CONV_POS)) /**< CR_CONV Mask */

 #define MXC_F_SC_CR_CREP_POS                           1 /**< CR_CREP Position */
 #define MXC_F_SC_CR_CREP                               ((uint32_t)(0x1UL << MXC_F_SC_CR_CREP_POS)) /**< CR_CREP Mask */

 #define MXC_F_SC_CR_WTEN_POS                           2 /**< CR_WTEN Position */
 #define MXC_F_SC_CR_WTEN                               ((uint32_t)(0x1UL << MXC_F_SC_CR_WTEN_POS)) /**< CR_WTEN Mask */

 #define MXC_F_SC_CR_UART_POS                           3 /**< CR_UART Position */
 #define MXC_F_SC_CR_UART                               ((uint32_t)(0x1UL << MXC_F_SC_CR_UART_POS)) /**< CR_UART Mask */

 #define MXC_F_SC_CR_CCEN_POS                           4 /**< CR_CCEN Position */
 #define MXC_F_SC_CR_CCEN                               ((uint32_t)(0x1UL << MXC_F_SC_CR_CCEN_POS)) /**< CR_CCEN Mask */

 #define MXC_F_SC_CR_RXFLUSH_POS                        5 /**< CR_RXFLUSH Position */
 #define MXC_F_SC_CR_RXFLUSH                            ((uint32_t)(0x1UL << MXC_F_SC_CR_RXFLUSH_POS)) /**< CR_RXFLUSH Mask */

 #define MXC_F_SC_CR_TXFLUSH_POS                        6 /**< CR_TXFLUSH Position */
 #define MXC_F_SC_CR_TXFLUSH                            ((uint32_t)(0x1UL << MXC_F_SC_CR_TXFLUSH_POS)) /**< CR_TXFLUSH Mask */

 #define MXC_F_SC_CR_RXTHD_POS                          8 /**< CR_RXTHD Position */
 #define MXC_F_SC_CR_RXTHD                              ((uint32_t)(0xFUL << MXC_F_SC_CR_RXTHD_POS)) /**< CR_RXTHD Mask */

 #define MXC_F_SC_CR_TXTHD_POS                          12 /**< CR_TXTHD Position */
 #define MXC_F_SC_CR_TXTHD                              ((uint32_t)(0xFUL << MXC_F_SC_CR_TXTHD_POS)) /**< CR_TXTHD Mask */

 #define MXC_F_SC_CR_DUAL_MODE_POS                      23 /**< CR_DUAL_MODE Position */
 #define MXC_F_SC_CR_DUAL_MODE                          ((uint32_t)(0x1UL << MXC_F_SC_CR_DUAL_MODE_POS)) /**< CR_DUAL_MODE Mask */

/**@} end of group SC_CR_Register */

/**
 * @ingroup  sc_registers
 * @defgroup SC_SR SC_SR
 * @brief    Status Register.
 * @{
 */
 #define MXC_F_SC_SR_PAR_POS                            0 /**< SR_PAR Position */
 #define MXC_F_SC_SR_PAR                                ((uint32_t)(0x1UL << MXC_F_SC_SR_PAR_POS)) /**< SR_PAR Mask */

 #define MXC_F_SC_SR_WTOV_POS                           1 /**< SR_WTOV Position */
 #define MXC_F_SC_SR_WTOV                               ((uint32_t)(0x1UL << MXC_F_SC_SR_WTOV_POS)) /**< SR_WTOV Mask */

 #define MXC_F_SC_SR_CCOV_POS                           2 /**< SR_CCOV Position */
 #define MXC_F_SC_SR_CCOV                               ((uint32_t)(0x1UL << MXC_F_SC_SR_CCOV_POS)) /**< SR_CCOV Mask */

 #define MXC_F_SC_SR_TXCF_POS                           3 /**< SR_TXCF Position */
 #define MXC_F_SC_SR_TXCF                               ((uint32_t)(0x1UL << MXC_F_SC_SR_TXCF_POS)) /**< SR_TXCF Mask */

 #define MXC_F_SC_SR_RXEMPTY_POS                        4 /**< SR_RXEMPTY Position */
 #define MXC_F_SC_SR_RXEMPTY                            ((uint32_t)(0x1UL << MXC_F_SC_SR_RXEMPTY_POS)) /**< SR_RXEMPTY Mask */

 #define MXC_F_SC_SR_RXFULL_POS                         5 /**< SR_RXFULL Position */
 #define MXC_F_SC_SR_RXFULL                             ((uint32_t)(0x1UL << MXC_F_SC_SR_RXFULL_POS)) /**< SR_RXFULL Mask */

 #define MXC_F_SC_SR_TXEMPTY_POS                        6 /**< SR_TXEMPTY Position */
 #define MXC_F_SC_SR_TXEMPTY                            ((uint32_t)(0x1UL << MXC_F_SC_SR_TXEMPTY_POS)) /**< SR_TXEMPTY Mask */

 #define MXC_F_SC_SR_TXFULL_POS                         7 /**< SR_TXFULL Position */
 #define MXC_F_SC_SR_TXFULL                             ((uint32_t)(0x1UL << MXC_F_SC_SR_TXFULL_POS)) /**< SR_TXFULL Mask */

 #define MXC_F_SC_SR_RXELT_POS                          8 /**< SR_RXELT Position */
 #define MXC_F_SC_SR_RXELT                              ((uint32_t)(0xFUL << MXC_F_SC_SR_RXELT_POS)) /**< SR_RXELT Mask */

 #define MXC_F_SC_SR_TXELT_POS                          12 /**< SR_TXELT Position */
 #define MXC_F_SC_SR_TXELT                              ((uint32_t)(0xFUL << MXC_F_SC_SR_TXELT_POS)) /**< SR_TXELT Mask */

/**@} end of group SC_SR_Register */

/**
 * @ingroup  sc_registers
 * @defgroup SC_PN SC_PN
 * @brief    Pin Register,
 * @{
 */
 #define MXC_F_SC_PN_CRDRST_POS                         0 /**< PN_CRDRST Position */
 #define MXC_F_SC_PN_CRDRST                             ((uint32_t)(0x1UL << MXC_F_SC_PN_CRDRST_POS)) /**< PN_CRDRST Mask */

 #define MXC_F_SC_PN_CRDCLK_POS                         1 /**< PN_CRDCLK Position */
 #define MXC_F_SC_PN_CRDCLK                             ((uint32_t)(0x1UL << MXC_F_SC_PN_CRDCLK_POS)) /**< PN_CRDCLK Mask */

 #define MXC_F_SC_PN_CRDIO_POS                          2 /**< PN_CRDIO Position */
 #define MXC_F_SC_PN_CRDIO                              ((uint32_t)(0x1UL << MXC_F_SC_PN_CRDIO_POS)) /**< PN_CRDIO Mask */

 #define MXC_F_SC_PN_CRDC4_POS                          3 /**< PN_CRDC4 Position */
 #define MXC_F_SC_PN_CRDC4                              ((uint32_t)(0x1UL << MXC_F_SC_PN_CRDC4_POS)) /**< PN_CRDC4 Mask */

 #define MXC_F_SC_PN_CRDC8_POS                          4 /**< PN_CRDC8 Position */
 #define MXC_F_SC_PN_CRDC8                              ((uint32_t)(0x1UL << MXC_F_SC_PN_CRDC8_POS)) /**< PN_CRDC8 Mask */

 #define MXC_F_SC_PN_CLKSEL_POS                         5 /**< PN_CLKSEL Position */
 #define MXC_F_SC_PN_CLKSEL                             ((uint32_t)(0x1UL << MXC_F_SC_PN_CLKSEL_POS)) /**< PN_CLKSEL Mask */

 #define MXC_F_SC_PN_IO_C48_EN_POS                      16 /**< PN_IO_C48_EN Position */
 #define MXC_F_SC_PN_IO_C48_EN                          ((uint32_t)(0x1UL << MXC_F_SC_PN_IO_C48_EN_POS)) /**< PN_IO_C48_EN Mask */

/**@} end of group SC_PN_Register */

/**
 * @ingroup  sc_registers
 * @defgroup SC_ETUR SC_ETUR
 * @brief    ETU Register.
 * @{
 */
 #define MXC_F_SC_ETUR_ETU_POS                          0 /**< ETUR_ETU Position */
 #define MXC_F_SC_ETUR_ETU                              ((uint32_t)(0x7FFFUL << MXC_F_SC_ETUR_ETU_POS)) /**< ETUR_ETU Mask */

 #define MXC_F_SC_ETUR_COMP_POS                         15 /**< ETUR_COMP Position */
 #define MXC_F_SC_ETUR_COMP                             ((uint32_t)(0x1UL << MXC_F_SC_ETUR_COMP_POS)) /**< ETUR_COMP Mask */

 #define MXC_F_SC_ETUR_HALF_POS                         16 /**< ETUR_HALF Position */
 #define MXC_F_SC_ETUR_HALF                             ((uint32_t)(0x1UL << MXC_F_SC_ETUR_HALF_POS)) /**< ETUR_HALF Mask */

/**@} end of group SC_ETUR_Register */

/**
 * @ingroup  sc_registers
 * @defgroup SC_GTR SC_GTR
 * @brief    Guard Time Register.
 * @{
 */
 #define MXC_F_SC_GTR_GT_POS                            0 /**< GTR_GT Position */
 #define MXC_F_SC_GTR_GT                                ((uint32_t)(0xFFFFUL << MXC_F_SC_GTR_GT_POS)) /**< GTR_GT Mask */

/**@} end of group SC_GTR_Register */

/**
 * @ingroup  sc_registers
 * @defgroup SC_WT0R SC_WT0R
 * @brief    Waiting Time 0 Register.
 * @{
 */
 #define MXC_F_SC_WT0R_WT_POS                           0 /**< WT0R_WT Position */
 #define MXC_F_SC_WT0R_WT                               ((uint32_t)(0xFFFFFFFFUL << MXC_F_SC_WT0R_WT_POS)) /**< WT0R_WT Mask */

/**@} end of group SC_WT0R_Register */

/**
 * @ingroup  sc_registers
 * @defgroup SC_WT1R SC_WT1R
 * @brief    Waiting Time 1 Register.
 * @{
 */
 #define MXC_F_SC_WT1R_WT_POS                           0 /**< WT1R_WT Position */
 #define MXC_F_SC_WT1R_WT                               ((uint32_t)(0xFFUL << MXC_F_SC_WT1R_WT_POS)) /**< WT1R_WT Mask */

/**@} end of group SC_WT1R_Register */

/**
 * @ingroup  sc_registers
 * @defgroup SC_IER SC_IER
 * @brief    Interrupt Enable Register.
 * @{
 */
 #define MXC_F_SC_IER_PARIE_POS                         0 /**< IER_PARIE Position */
 #define MXC_F_SC_IER_PARIE                             ((uint32_t)(0x1UL << MXC_F_SC_IER_PARIE_POS)) /**< IER_PARIE Mask */

 #define MXC_F_SC_IER_WTIE_POS                          1 /**< IER_WTIE Position */
 #define MXC_F_SC_IER_WTIE                              ((uint32_t)(0x1UL << MXC_F_SC_IER_WTIE_POS)) /**< IER_WTIE Mask */

 #define MXC_F_SC_IER_CTIE_POS                          2 /**< IER_CTIE Position */
 #define MXC_F_SC_IER_CTIE                              ((uint32_t)(0x1UL << MXC_F_SC_IER_CTIE_POS)) /**< IER_CTIE Mask */

 #define MXC_F_SC_IER_TCIE_POS                          3 /**< IER_TCIE Position */
 #define MXC_F_SC_IER_TCIE                              ((uint32_t)(0x1UL << MXC_F_SC_IER_TCIE_POS)) /**< IER_TCIE Mask */

 #define MXC_F_SC_IER_RXEIE_POS                         4 /**< IER_RXEIE Position */
 #define MXC_F_SC_IER_RXEIE                             ((uint32_t)(0x1UL << MXC_F_SC_IER_RXEIE_POS)) /**< IER_RXEIE Mask */

 #define MXC_F_SC_IER_RXTIE_POS                         5 /**< IER_RXTIE Position */
 #define MXC_F_SC_IER_RXTIE                             ((uint32_t)(0x1UL << MXC_F_SC_IER_RXTIE_POS)) /**< IER_RXTIE Mask */

 #define MXC_F_SC_IER_RXFIE_POS                         6 /**< IER_RXFIE Position */
 #define MXC_F_SC_IER_RXFIE                             ((uint32_t)(0x1UL << MXC_F_SC_IER_RXFIE_POS)) /**< IER_RXFIE Mask */

 #define MXC_F_SC_IER_TXEIE_POS                         7 /**< IER_TXEIE Position */
 #define MXC_F_SC_IER_TXEIE                             ((uint32_t)(0x1UL << MXC_F_SC_IER_TXEIE_POS)) /**< IER_TXEIE Mask */

 #define MXC_F_SC_IER_TXTIE_POS                         8 /**< IER_TXTIE Position */
 #define MXC_F_SC_IER_TXTIE                             ((uint32_t)(0x1UL << MXC_F_SC_IER_TXTIE_POS)) /**< IER_TXTIE Mask */

/**@} end of group SC_IER_Register */

/**
 * @ingroup  sc_registers
 * @defgroup SC_ISR SC_ISR
 * @brief    Interrupt Status Register.
 * @{
 */
 #define MXC_F_SC_ISR_PARIS_POS                         0 /**< ISR_PARIS Position */
 #define MXC_F_SC_ISR_PARIS                             ((uint32_t)(0x1UL << MXC_F_SC_ISR_PARIS_POS)) /**< ISR_PARIS Mask */

 #define MXC_F_SC_ISR_WTIS_POS                          1 /**< ISR_WTIS Position */
 #define MXC_F_SC_ISR_WTIS                              ((uint32_t)(0x1UL << MXC_F_SC_ISR_WTIS_POS)) /**< ISR_WTIS Mask */

 #define MXC_F_SC_ISR_CTIS_POS                          2 /**< ISR_CTIS Position */
 #define MXC_F_SC_ISR_CTIS                              ((uint32_t)(0x1UL << MXC_F_SC_ISR_CTIS_POS)) /**< ISR_CTIS Mask */

 #define MXC_F_SC_ISR_TCIS_POS                          3 /**< ISR_TCIS Position */
 #define MXC_F_SC_ISR_TCIS                              ((uint32_t)(0x1UL << MXC_F_SC_ISR_TCIS_POS)) /**< ISR_TCIS Mask */

 #define MXC_F_SC_ISR_RXEIS_POS                         4 /**< ISR_RXEIS Position */
 #define MXC_F_SC_ISR_RXEIS                             ((uint32_t)(0x1UL << MXC_F_SC_ISR_RXEIS_POS)) /**< ISR_RXEIS Mask */

 #define MXC_F_SC_ISR_RXTIS_POS                         5 /**< ISR_RXTIS Position */
 #define MXC_F_SC_ISR_RXTIS                             ((uint32_t)(0x1UL << MXC_F_SC_ISR_RXTIS_POS)) /**< ISR_RXTIS Mask */

 #define MXC_F_SC_ISR_RXFIS_POS                         6 /**< ISR_RXFIS Position */
 #define MXC_F_SC_ISR_RXFIS                             ((uint32_t)(0x1UL << MXC_F_SC_ISR_RXFIS_POS)) /**< ISR_RXFIS Mask */

 #define MXC_F_SC_ISR_TXEIS_POS                         7 /**< ISR_TXEIS Position */
 #define MXC_F_SC_ISR_TXEIS                             ((uint32_t)(0x1UL << MXC_F_SC_ISR_TXEIS_POS)) /**< ISR_TXEIS Mask */

 #define MXC_F_SC_ISR_TXTIS_POS                         8 /**< ISR_TXTIS Position */
 #define MXC_F_SC_ISR_TXTIS                             ((uint32_t)(0x1UL << MXC_F_SC_ISR_TXTIS_POS)) /**< ISR_TXTIS Mask */

/**@} end of group SC_ISR_Register */

/**
 * @ingroup  sc_registers
 * @defgroup SC_TXR SC_TXR
 * @brief    Transmit Register.
 * @{
 */
 #define MXC_F_SC_TXR_DATA_POS                          0 /**< TXR_DATA Position */
 #define MXC_F_SC_TXR_DATA                              ((uint32_t)(0xFFUL << MXC_F_SC_TXR_DATA_POS)) /**< TXR_DATA Mask */

/**@} end of group SC_TXR_Register */

/**
 * @ingroup  sc_registers
 * @defgroup SC_RXR SC_RXR
 * @brief    Receive Register.
 * @{
 */
 #define MXC_F_SC_RXR_DATA_POS                          0 /**< RXR_DATA Position */
 #define MXC_F_SC_RXR_DATA                              ((uint32_t)(0xFFUL << MXC_F_SC_RXR_DATA_POS)) /**< RXR_DATA Mask */

 #define MXC_F_SC_RXR_PARER_POS                         8 /**< RXR_PARER Position */
 #define MXC_F_SC_RXR_PARER                             ((uint32_t)(0x1UL << MXC_F_SC_RXR_PARER_POS)) /**< RXR_PARER Mask */

/**@} end of group SC_RXR_Register */

/**
 * @ingroup  sc_registers
 * @defgroup SC_CCR SC_CCR
 * @brief    Clock Counter Register,
 * @{
 */
 #define MXC_F_SC_CCR_CCYC_POS                          0 /**< CCR_CCYC Position */
 #define MXC_F_SC_CCR_CCYC                              ((uint32_t)(0xFFFFFFUL << MXC_F_SC_CCR_CCYC_POS)) /**< CCR_CCYC Mask */

 #define MXC_F_SC_CCR_MAN_POS                           31 /**< CCR_MAN Position */
 #define MXC_F_SC_CCR_MAN                               ((uint32_t)(0x1UL << MXC_F_SC_CCR_MAN_POS)) /**< CCR_MAN Mask */

/**@} end of group SC_CCR_Register */

#ifdef __cplusplus
}
#endif

#endif /* _SC_REGS_H_ */
