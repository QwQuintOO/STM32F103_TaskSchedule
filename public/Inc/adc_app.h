#ifndef _ADC_APP_H_
#define _ADC_APP_H_

#include "stm32f1xx_hal.h"
#include "adc.h"

void adc_app_Init (void)  ;
void adc_app_task (void)  ; 
void adc_calibrated (void) ; 

extern int adc_value ; 

extern float adc_voltage ; 

#endif
