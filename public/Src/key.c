#include "key.h"

KEY   key[2] ; 



void key_Init (void)
{
	key[0].gpio = 0 ,key[0].state = IDLE , key[0].kind = 'n' , key[0].time.current_time = 0 , key[0].time.last_time = 0 ; 
	key[1].gpio = 0 ,key[1].state = IDLE , key[1].kind = 'n' , key[1].time.current_time = 0 , key[1].time.last_time = 0 ; 
}

void key_interupt (void)
{
    key[0].gpio = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_15);
    key[1].gpio = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_12);
    
    for (uint8_t i = 0; i < 2; i++)
    {
        switch (key[i].state)
        {
            case IDLE:  // 空闲状态
                if (key[i].gpio == 0)  // 检测到按下
                {
                    key[i].time.last_time = HAL_GetTick();  // 记录时间
                    key[i].state = DEBOUNCE;  // 进入消抖
                }
                break;
                
            case DEBOUNCE:  // 消抖状态（确认是真实按下）
                if (key[i].gpio == 1)  // 松手了（可能是抖动）
                {
                    key[i].state = IDLE;  // 放弃，回到空闲
                }
                else  // 依然按着
                {
                    key[i].time.current_time = HAL_GetTick();
                    uint32_t duration = key[i].time.current_time - key[i].time.last_time;
                    
                    if (duration >= 20)  // 消抖完成，确认有效按下
                    {
                        // 重新记录时间，用于长短按判断
                        key[i].time.last_time = key[i].time.current_time;
                        key[i].state = PRESSED;  // 进入长按/短按判断
                    }
                }
                break;
                
            case PRESSED:  // 已确认按下，等待释放或长按
                if (key[i].gpio == 1)  // 释放了
                {
                    key[i].kind = 's';  // 短按
                    key[i].state = IDLE;
                }
                else  // 仍按着
                {
                    key[i].time.current_time = HAL_GetTick();
                    uint32_t duration = key[i].time.current_time - key[i].time.last_time;
                    
                    if (duration >= 1000)  // 长按触发
                    {
                        key[i].kind = 'l';  // 长按
                        key[i].state = IDLE;
                    }
                }
                break;
                
            default:
                key[i].state = IDLE;
                break;
        }
    }
}


