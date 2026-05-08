#ifndef _KEY_H
#define _KEY_H

#include "stm32f1xx_hal.h"
#include "gpio.h"
#include "stdio.h"
#include "stdbool.h"

typedef enum 
{
	IDLE  , 
	DEBOUNCE ,
	PRESSED ,
	SINGLE , 
	LONG 
}key_state ;

typedef struct
{
uint32_t current_time ;
uint32_t last_time ; 

}Key_time ;

typedef struct{
	
	_Bool     	gpio ; 
	key_state 	state ; 
	char 		kind ; 
	Key_time    time ;

}KEY ; 

extern KEY key[2] ;

void key_Init (void) ; 
 
void key_interupt (void) ;

#endif 


