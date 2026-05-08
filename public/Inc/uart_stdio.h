#ifndef _UART_STDIO_H
#define _UART_STDIO_H

#include "stm32f1xx_hal.h"
#include "usart.h"
#include "stdio.h"
#include "unistd.h"
#include "string.h"

#include "pwm_app.h"

extern int pwm_duty ; 

int _write (int fd , char*ptr , int len) ; 
void uart_stdio_Init (void) ; 

#endif 
