#include "task.h"

typedef struct{
	_Bool     	run;						//运行标志	
	uint32_t 	timeCount;					//递减计算 时间片 毫秒触发
	uint32_t 	timeRload;					//重装载值
	void 		(*pTaskFunc)(void);			//函数指针
} TaskComps_stu;

#define TASKNM (sizeof(g_TaskComps)/sizeof(g_TaskComps[0])) //任务个数

void oled_app_task (void)
{
		if (mode == 0 )  OLED_Show_String (1 , 1 , (uint8_t*)"MAN ") ; 
		else if (mode == 1 )   OLED_Show_String (1 , 1 , (uint8_t*)"AUTO") ;

		OLED_Show_String (1 , 5 ,(uint8_t*)"PWM_Duty:" ) ;
		OLED_Show_Num 	 (73 , 5 , pwm_duty , 3 ) ; 
}
 
static TaskComps_stu g_TaskComps[] = {
		{false, 20,	20, key_app_task},		//任务一
		{false, 100,100,adc_app_task},    //任务二
		{false, 1000,1000, pwm_app_task},	//任务三
		{false, 1000,1000, oled_app_task},    //任务四
};



// 任务时间片处理
void TaskTimeSlice(void)
{
	
	for(int i = 0; i < TASKNM; i++)
	{
		g_TaskComps[i].timeCount--;
		if( g_TaskComps[i].timeCount == 0 )
		{
			g_TaskComps[i].run = true;
			g_TaskComps[i].timeCount = g_TaskComps[i].timeRload;
		}
	}
}
// 任务调度器
void TaskHandler(void)
{
	
	for(int i = 0; i < TASKNM; i++)
	{
		if(g_TaskComps[i].run == true )
		{
			g_TaskComps[i].pTaskFunc();
			g_TaskComps[i].run = false;
		}
	}
}








