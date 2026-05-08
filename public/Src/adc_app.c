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

   OLED_Show_String (1 , 3 ,(uint8_t*)"ADC_Voltage:" ) ; 
   OLED_Show_Float  (97 , 3 , adc_voltage , 1 , 2  ) ;

}

void adc_calibrated (void)
{
   HAL_ADC_Stop(&hadc1);

   HAL_ADCEx_Calibration_Start(&hadc1);

   HAL_ADC_Start(&hadc1);
   
}