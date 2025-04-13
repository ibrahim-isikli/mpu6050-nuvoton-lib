#include "lcd_for_nuvoton.h"
void CLK_Init(void)
{

}
void I2C0_Init()
{
    I2C_Open(I2C0, 100000);

}
void SYS_Init(void)
{

    /* Disable Brown-Out Detector function */
    SYS_DisableBOD();

    /* Dsiable Low-Voltage Detector function */
    SYS_DISABLE_LVR();

}

void Periph_Init(void)
{

    CLK_Init();

    SYS_Init();

    I2C0_Init();

}
