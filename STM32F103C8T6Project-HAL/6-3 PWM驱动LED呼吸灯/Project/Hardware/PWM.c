#include "PWM.h"
#include "tim.h"

/**
  * 函    数：PWM初始化
  * 参    数：无
  * 返 回 值：无
  */
void PWM_Init(void)
{
    // HAL库生成代码已经完成了引脚的初始化，所以此处无需再初始化
    // 关于引脚的初始化配置，跳转这个函数 MX_TIM2_Init()
	
	/*TIM使能*/
	HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_1);			//使能TIM2，定时器开始运行
}

/**
  * 函    数：PWM设置CCR
  * 参    数：Compare 要写入的CCR的值，范围：0~100
  * 返 回 值：无
  * 注意事项：CCR和ARR共同决定占空比，此函数仅设置CCR的值，并不直接是占空比
  *           占空比Duty = CCR / (ARR + 1)
  */
void PWM_SetCompare1(uint16_t Compare)
{
    __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, Compare);   //设置CCR1的值
}
