#include "pwm_app.h"

uint8_t mode = 0; 

void pwm_app_Man (void)
{ 
     __HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, pwm_duty*10 );
}

void pwm_app_Auto (void)
{
     static uint8_t flag = 0 ; 
        
     if (flag == 0) 
     {
         pwm_duty += 10 ;
         __HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, pwm_duty*10 );
 
         if (pwm_duty >= 100) 
         {
          flag = 1;
          pwm_duty = 100;
         }
     }
     else if (flag == 1)
     {
          pwm_duty -= 10 ;
          __HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, pwm_duty*10 );

         if (pwm_duty <= 0)
         {
          flag = 0;
          pwm_duty = 0;
         }
     }
     
}

void pwm_app_task (void)
{
     

     switch (mode)
     {
        case 0: pwm_app_Man(); break;
        case 1: pwm_app_Auto(); break;
     }
     
}
