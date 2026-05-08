#include "uart_stdio.h"

// 重定义标准输入输出 可以直接使用printf printf("%d",x)
int _write (int fd , char*ptr , int len)
{
    (void)fd ; 

    HAL_UART_Transmit (&huart1 , (uint8_t*)ptr , len , 0xFFFF) ;

    return len ; 

}



// 接收中断

#define    MAX              8 
uint8_t buffer[1];
uint8_t array[MAX] ; 
int temp_duty = 0 ;
volatile int rx_index = 0 ; 
int pwm_duty = 0 ; 

void uart_stdio_Init (void)
{
    HAL_UART_Receive_IT(&huart1, buffer, 1 );
}


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if (huart->Instance == USART1 && mode == 0  )
	{ 
	 if (buffer[0] == '\r' || buffer[0] == '\n')   //
      {
				HAL_UART_Receive_IT(&huart1, buffer, 1);
				
       return;
      }
		array[rx_index] = buffer[0]  ;  //rx_index = 6  pwm(50)
		
		rx_index ++ ;    // rx_index = 7
		
		if ( buffer[0] == ')' )
		{	
			
			int len = rx_index  ; //7
			
			char char_array[ len + 1 ] ;    //char_array
			
			for(int i = 0 ; i < len ; i ++) //0-6  pwm(50)  
			{
				
				char_array[i] = (char) array[i] ; 
			}
			
			char_array[len] = '\0' ; 
			
			if (sscanf (char_array , "pwm(%d)" , &temp_duty ) == 1  )
			{
				pwm_duty = temp_duty ; 
				
				
				if (pwm_duty > 100) pwm_duty = 100;
				if (pwm_duty < 0) pwm_duty = 0;	
			}
			rx_index = 0 ; 
			
		}
	}
	HAL_UART_Receive_IT(&huart1, buffer, 1 );	   
}




