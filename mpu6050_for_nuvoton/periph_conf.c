#include "mpu6050_for_nuvoton.h"
void CLK_Init(void)
{

    /* Configure clock detector functions, which are able to monitor the operations of HXT and LXT */
    CLK->CLKDCTL = (CLK_CLKDCTL_HXTFDEN_Msk | CLK_CLKDCTL_HXTFQDEN_Msk | CLK_CLKDCTL_LXTFDEN_Msk);

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
