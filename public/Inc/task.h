#ifndef _TASK_H_
#define _TASK_H_ 

#include "stm32f1xx_hal.h"
#include "gpio.h"
#include "tim.h" 
#include  "stdbool.h"

#include "uart_stdio.h"
#include "key.h"
#include "adc_app.h"
#include "pwm_app.h" 
#include "oled.h"
#include "key_app.h"

void TaskTimeSlice(void) ; 

void TaskHandler(void) ; 

void task1_key (void) ; 

void oled_app_task (void) ; 


#endif

