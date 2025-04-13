/*
 * i2c_lcd.c
 *
 *  Created on: Apr 5, 2025
 *      Author: ibrahim
 */

#include "i2c_lcd.h"

static void LCD_SendCmd(uint8_t cmd);
static void LCD_SendData(uint8_t data);
static void LCD_Send(uint8_t data, uint8_t mode);
static void LCD_Write4Bits(uint8_t data);


void LCD_Init(void)
{
    CLK_SysTickDelay(50000); // Power On Delay 50ms

    LCD_Write4Bits(0x30);
    CLK_SysTickDelay(4500);

    LCD_Write4Bits(0x30);
    CLK_SysTickDelay(150);

    LCD_Write4Bits(0x30);
    CLK_SysTickDelay(150);

    LCD_Write4Bits(0x20);  // 4-bit mode
    CLK_SysTickDelay(150);

    LCD_SendCmd(0x28); // 4-bit, 2 line, 5x8 dots
    LCD_SendCmd(0x08); // Display off
    LCD_SendCmd(0x01); // Clear display
    CLK_SysTickDelay(2000);
    LCD_SendCmd(0x06); // Entry mode
    LCD_SendCmd(0x0C); // Display on, Cursor off
}

void LCD_Clear(void)
{
    LCD_SendCmd(0x01);
    CLK_SysTickDelay(2000);
}

void LCD_SetCursor(uint8_t row, uint8_t col)
{
    uint8_t row_offsets[] = {0x00, 0x40, 0x14, 0x54};
    LCD_SendCmd(0x80 | (col + row_offsets[row]));
}

void LCD_Print(char *str)
{
    while (*str)
    {
        LCD_WriteChar(*str++);
    }
}

void LCD_WriteChar(char data)
{
    LCD_Send(data, 1);
}

static void LCD_SendCmd(uint8_t cmd)
{
    LCD_Send(cmd, 0);
}

static void LCD_Send(uint8_t data, uint8_t mode)
{
    uint8_t high_nibble = data & 0xF0;
    uint8_t low_nibble = (data << 4) & 0xF0;

    LCD_Write4Bits(high_nibble | mode);
    LCD_Write4Bits(low_nibble | mode);
}

static void LCD_Write4Bits(uint8_t data)
{
    I2C_WriteByte(I2C0,LCD_I2C_ADDR, data | LCD_BACKLIGHT);
    I2C_WriteByte(I2C0,LCD_I2C_ADDR, data | LCD_ENABLE_BIT | LCD_BACKLIGHT);
    CLK_SysTickDelay(1);
    I2C_WriteByte(I2C0,LCD_I2C_ADDR, (data & ~LCD_ENABLE_BIT) | LCD_BACKLIGHT);
    CLK_SysTickDelay(50);
}
