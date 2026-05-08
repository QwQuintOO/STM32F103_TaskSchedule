#include "key_app.h"  
void key_app_task (void)
{
  key_interupt () ;

	if (key[0].kind== 's')
	  {     
      printf ("adc的数值为:%.2f\n", adc_voltage ) ; 

			key[0].kind = 'n' ;
    }
    if (key[0].kind== 'l')
    {     
      printf("ADC校准模式开启\n");
      adc_calibrated ();
      printf("ADC校准模式结束\n");

			key[0].kind = 'n' ;
  }
    if (key[1].kind== 's')
    { 
      printf ("当前PWM的占空比为:%d  \n", pwm_duty ) ; 
      key[1].kind = 'n' ;   
    }
    if (key[1].kind== 'l')
    {  
		switch ( mode )
		{
			case 0: 
			printf("PWM的AUTO模式开启\n");
				mode = 1 ; 
				break;
			case 1: 
			printf("PWM的MAN模式开启\n");
				mode = 0 ; 
				break;
		}
      key[1].kind = 'n' ;  
    }

}