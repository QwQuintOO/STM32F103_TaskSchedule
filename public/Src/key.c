#include "key.h"

KEY   key[2] ; 

void key_Init (void)
{
	key[0].gpio = 0 ,key[0].state = IDLE , key[0].kind = 'n' , key[0].count = 0 ; 
	key[1].gpio = 0 ,key[1].state = IDLE , key[1].kind = 'n' , key[1].count = 0 ; 
}

void key_interupt (void)
{
    key[0].gpio = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_15);
    key[1].gpio = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_12);
    
    for (uint8_t i = 0; i < 2; i++)
    {
        switch (key[i].state)
        {
            case IDLE:
                if (key[i].gpio == 0)
                {
                    key[i].state = DEBOUNCE;
                }
                else  key[i].state = IDLE;

            break ;  
            case DEBOUNCE:  
                if (key[i].gpio == 0)
                {
                    key[i].state = PRESSED;
                }
                else key[i].state = IDLE;

            break;   
            case PRESSED:  
               key[i].count++;
               if (key[i].gpio == 0 && key[i].count == 5 )
               {
                 key[i].state = LONG;
               }
               else  if (key[i].gpio == 1 && key[i].count < 5 )
               {
                key[i].state = SINGLE;
               }
                break;
                case SINGLE:

                key[i].kind = 's' ;
                key[i].count = 0 ;

                break ; 
                case LONG:

                key[i].kind = 'l' ;
                key[i].count = 0 ;

                break  ; 
            default:
                key[i].state = IDLE;
                break;
        }
    }
}


