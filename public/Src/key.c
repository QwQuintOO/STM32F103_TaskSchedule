#include "key.h"

KEY   key[2] ; 



void key_Init (void)
{
	key[0].gpio = 0 ,key[0].state = 0 , key[0].kind = 'n' , key[0].count = 0 ; 
	key[1].gpio = 0 ,key[1].state = 0 , key[1].kind = 'n' , key[1].count = 0 ; 
}

void key_interupt (void)
{
	key[0].gpio = HAL_GPIO_ReadPin (GPIOA , GPIO_PIN_15) ;
	key[1].gpio = HAL_GPIO_ReadPin (GPIOA , GPIO_PIN_12) ;

  for (uint8_t i = 0 ; i < 2 ; ++i )
	{
		switch (key[i].state )
		{
			case 0 : 
				if (key[i].gpio == 0 )  key[i].state = 1 ; 
			
				else key[i].state = 0 ; 
			
				break ; 
			case 1 :
				if (key[i].gpio == 1)
				{
					if(key[i].count < 50 ) key[i].kind = 's' ; 
					
					else if (key[i].count >= 50) key[i].kind = 'l' ; 
					
					key[i].count = 0 ; 
					
					key[i].state = 0 ; 
				}
				else key[i].count ++ ; ; 
				
				break ;
			default : break ; 	
		}
	}

}




