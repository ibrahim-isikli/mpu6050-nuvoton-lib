/****************************************************************************
 * @file     pin_conf.c
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
Pin Configuration:
Pin2:I2C0_SCL
Pin3:I2C0_SDA
Pin33:ICE_DAT
Pin34:ICE_CLK
Module Configuration:
I2C0_SCL(Pin:2)
I2C0_SDA(Pin:3)
ICE_CLK(Pin:34)
ICE_DAT(Pin:33)
GPIO Configuration:
PB.4:I2C0_SDA(Pin:3)
PB.5:I2C0_SCL(Pin:2)
PF.0:ICE_DAT(Pin:33)
PF.1:ICE_CLK(Pin:34)
********************/

#include "lcd_for_nuvoton.h"

/*
 * @brief This function provides the configured MFP registers
 * @param None
 * @return None
 */
void Pin_Init(void)
{
    //SYS->GPA_MFPH = 0x00000000UL;
    //SYS->GPA_MFPL = 0x00000000UL;
    //SYS->GPB_MFPH = 0x00000000UL;
    //SYS->GPB_MFPL = 0x00660000UL;
    //SYS->GPC_MFPH = 0x00000000UL;
    //SYS->GPC_MFPL = 0x00000000UL;
    //SYS->GPD_MFPH = 0x00000000UL;
    //SYS->GPD_MFPL = 0x00000000UL;
    //SYS->GPF_MFPH = 0x00000000UL;
    //SYS->GPF_MFPL = 0x000000EEUL;

    SYS->GPA_MFPH = 0x00000000;
    SYS->GPA_MFPL = 0x00000000;
    SYS->GPB_MFPH = 0x00000000;
    SYS->GPB_MFPL = SYS_GPB_MFPL_PB5MFP_I2C0_SCL | SYS_GPB_MFPL_PB4MFP_I2C0_SDA;
    SYS->GPC_MFPH = 0x00000000;
    SYS->GPC_MFPL = 0x00000000;
    SYS->GPD_MFPH = 0x00000000;
    SYS->GPD_MFPL = 0x00000000;
    SYS->GPF_MFPH = 0x00000000;
    SYS->GPF_MFPL = SYS_GPF_MFPL_PF1MFP_ICE_CLK | SYS_GPF_MFPL_PF0MFP_ICE_DAT;

    return;
}

/*** (C) COPYRIGHT 2016-2025 Nuvoton Technology Corp. ***/
