/*
 * i2c_lcd.h
 *
 *  Created on: Apr 5, 2025
 *      Author: ibrahim isikli
 */

#ifndef I2C_LCD_INC_I2C_LCD_H_
#define I2C_LCD_INC_I2C_LCD_H_
#include "NuMicro.h"


#define LCD_I2C_ADDR        0x27
#define LCD_BACKLIGHT       0x08
#define LCD_ENABLE_BIT      0x04

// function prototypes
void LCD_Init(void);
void LCD_Clear(void);
void LCD_SetCursor(uint8_t row, uint8_t col);
void LCD_Print(char *str);
void LCD_WriteChar(char data);


#endif /* I2C_LCD_INC_I2C_LCD_H_ */
