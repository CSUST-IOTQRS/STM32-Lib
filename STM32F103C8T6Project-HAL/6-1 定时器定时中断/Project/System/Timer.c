#include "Timer.h"
#include "tim.h"

/**
  * 函    数：定时中断初始化
  * 参    数：无
  * 返 回 值：无
  */
void Timer_Init(void)
{
    // HAL库生成代码已经完成了引脚的初始化，所以此处无需再初始化
    // 关于引脚的初始化配置，跳转这个函数 MX_TIM2_Init()

    __HAL_TIM_CLEAR_FLAG(&htim2, TIM_FLAG_UPDATE);      /*中断输出配置*/
                                                        // 清除定时器更新标志位
                                                        // TIM_TimeBaseInit函数末尾，手动产生了更新事件
                                                        // 若不清除此标志位，则开启中断后，会立刻进入一次中断
                                                        // 如果不介意此问题，则不清除此标志位也可
    /*TIM使能*/
    HAL_TIM_Base_Start_IT(&htim2);			//使能TIM2，定时器开始运行
}

/* 定时器中断回调函数 */
/*
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == TIM2)
    {
        // 在这里添加您的中断处理代码
    }
}
*/
