#include "adc_app.h"

int adc_value = 0 ;

float adc_voltage = 0.0f ;
void adc_app_Init (void) 
{ 
   HAL_ADC_Start(&hadc1);
}

void adc_app_task (void) 
{ 
   HAL_ADC_PollForConversion(&hadc1, 100);

    adc_value = HAL_ADC_GetValue(&hadc1);

    adc_voltage = (float)adc_value * 3.3f / 4096.0f;
}

void adc_calibrated (void)
{
   HAL_ADC_Stop(&hadc1);

   HAL_ADCEx_Calibration_Start(&hadc1);

   HAL_ADC_Start(&hadc1);
   
}