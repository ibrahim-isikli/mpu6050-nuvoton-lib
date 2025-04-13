/****************************************************************************
 * @file     clk_conf.c
 * @version  V0.42
 * @Date     2025/04/05-17:38:14
 * @brief    NuMicro generated code file
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Copyright (C) 2016-2025 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/

/********************
MCU:M032SE3AE(LQFP64)
Base Clocks:
LIRC:38.4kHz
HIRC:48MHz
LXT:32.768kHz
HXT:32MHz
HCLK:48MHz
PCLK0:48MHz
PCLK1:48MHz
Enabled-Module Frequencies:
I2C0=Bus Clock(PCLK0):48MHz
ISP=Bus Clock(HCLK):48MHz/Engine Clock:48MHz
WDT=Bus Clock(PCLK0):48MHz/Engine Clock:38.4kHz
WWDT=Bus Clock(PCLK0):48MHz/Engine Clock:23.4375kHz
********************/

#include "lcd_for_nuvoton.h"

/*
 * @brief This function updates clock registers to fulfill the configuration
 * @param None
 * @return None
 */
void Clock_Init(void)
{
    /*---------------------------------------------------------------------------------------------------------*/
    /* Init System Clock                                                                                       */
    /*---------------------------------------------------------------------------------------------------------*/
    //CLK->PWRCTL   = (CLK->PWRCTL   & ~(0x0000000FUL)) | 0x0231001FUL;
    //CLK->PLLCTL   = (CLK->PLLCTL   & ~(0x000FFFFFUL)) | 0x0005C25EUL;
    //CLK->CLKDIV0  = (CLK->CLKDIV0  & ~(0x00FFFFFFUL)) | 0x00000000UL;
    //CLK->CLKDIV4  = (CLK->CLKDIV4  & ~(0x00FFFFFFUL)) | 0x00000000UL;
    //CLK->PCLKDIV  = (CLK->PCLKDIV  & ~(0x00000077UL)) | 0x00000000UL;
    //CLK->CLKSEL0  = (CLK->CLKSEL0  & ~(0x0000013FUL)) | 0x0000003FUL;
    //CLK->CLKSEL1  = (CLK->CLKSEL1  & ~(0x7777777FUL)) | 0x4477773BUL;
    //CLK->CLKSEL2  = (CLK->CLKSEL2  & ~(0x0030033FUL)) | 0x0020032BUL;
    //CLK->CLKSEL3  = (CLK->CLKSEL3  & ~(0x77777700UL)) | 0x44444400UL;
    //CLK->AHBCLK   = (CLK->AHBCLK   & ~(0x0000009EUL)) | 0x00000004UL;
    //CLK->APBCLK0  = (CLK->APBCLK0  & ~(0x18FF33FFUL)) | 0x00000101UL;
    //CLK->APBCLK1  = (CLK->APBCLK1  & ~(0x000F0300UL)) | 0x00000000UL;
    //CLK->CLKOCTL  = (CLK->CLKOCTL  & ~(0x0000007FUL)) | 0x00000000UL;
    //SysTick->CTRL = (SysTick->CTRL & ~(0x00000005UL)) | 0x00000000UL;
    //RTC->LXTCTL   = (RTC->LXTCTL   & ~(0x00000080UL)) | 0x00000000UL;

    /* Enable clock source */
    CLK_EnableXtalRC(CLK_PWRCTL_LIRCEN_Msk | CLK_PWRCTL_HIRCEN_Msk | CLK_PWRCTL_LXTEN_Msk | CLK_PWRCTL_HXTEN_Msk);

    /* Waiting for clock source ready */
    CLK_WaitClockReady(CLK_STATUS_LIRCSTB_Msk | CLK_STATUS_HIRCSTB_Msk | CLK_STATUS_LXTSTB_Msk | CLK_STATUS_HXTSTB_Msk);

    /* Set HCLK clock */
    CLK_SetHCLK(CLK_CLKSEL0_HCLKSEL_HIRC, CLK_CLKDIV0_HCLK(1));

    /* Set PCLK-related clock */
    CLK->PCLKDIV = (CLK_PCLKDIV_APB0DIV_DIV1 | CLK_PCLKDIV_APB1DIV_DIV1);

    /* Enable IP clock */
    CLK_EnableModuleClock(I2C0_MODULE);
    CLK_EnableModuleClock(ISP_MODULE);
    CLK_EnableModuleClock(WDT_MODULE);
    CLK_EnableModuleClock(WWDT_MODULE);

    /* Set IP clock */
    CLK_SetModuleClock(WDT_MODULE, CLK_CLKSEL1_WDTSEL_LIRC, MODULE_NoMsk);
    CLK_SetModuleClock(WWDT_MODULE, CLK_CLKSEL1_WWDTSEL_HCLK_DIV2048, MODULE_NoMsk);

    /* Update System Core Clock */
    /* User can use SystemCoreClockUpdate() to calculate SystemCoreClock. */
    SystemCoreClockUpdate();

    return;
}

/*** (C) COPYRIGHT 2016-2025 Nuvoton Technology Corp. ***/
