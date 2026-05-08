#ifndef 	_OLED_H
#define   _OLED_H

#include "stdio.h"
#include "string.h"
#include "i2c.h"
#include "main.h"

#define OLED_I2C_HANDLE      &hi2c1
#define OLED_I2C_ADDR         0x78
#define OLED_I2C_WIDTH        128
#define OLED_I2C_HEIGHT       64

void OLED_Init(void) ;
void OLED_Clear(void) ;
void OLED_Set_Pos(uint8_t x,uint8_t y) ;
void OLED_Show_Char(uint8_t x,uint8_t y,uint8_t chr) ;
void OLED_Show_String(uint8_t x,uint8_t y, uint8_t *str) ;
void OLED_Show_Num(uint8_t x,uint8_t y, uint32_t num,uint8_t len) ;
void OLED_Show_Float(uint8_t x,uint8_t y, float num, uint8_t int_len,uint8_t dec_len) ;


#endif

