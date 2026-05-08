#ifndef _KEY_H
#define _KEY_H

#include "stm32f1xx_hal.h"
#include "gpio.h"
#include "stdio.h"
#include "stdbool.h"



typedef struct{
	
	_Bool gpio ; 
	uint8_t state ; 
	char kind ; 
	uint16_t count ; 

}KEY ; 

extern KEY key[2] ;

void key_Init (void) ; 
 
void key_interupt (void) ;

#endif 


