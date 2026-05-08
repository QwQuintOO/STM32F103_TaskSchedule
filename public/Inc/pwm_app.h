#ifndef _PWM_APP_H_
#define _PWM_APP_H_ 

#include "stm32f1xx_hal.h" 
#include "tim.h"
#include "uart_stdio.h"

void pwm_app_task (void) ; 

void pwm_app_Auto (void) ; 

void pwm_app_Man (void)  ; 

extern uint8_t mode ; 

#endif