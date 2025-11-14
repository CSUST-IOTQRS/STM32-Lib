#include "CountSensor.h"

uint16_t CountSensor_Count;				//全局变量，用于计数

/**
  * 函    数：计数传感器初始化
  * 参    数：无
  * 返 回 值：无
  */
void CountSensor_Init(void)
{
    // HAL库生成代码已经完成了引脚的初始化，所以此处无需再初始化
    // 关于引脚的初始化配置，跳转这个函数 MX_GPIO_Init()
}

/**
  * 函    数：获取计数传感器的计数值
  * 参    数：无
  * 返 回 值：计数值，范围：0~65535
  */
uint16_t CountSensor_Get(void)
{
	return CountSensor_Count;
}

/**
  * 函    数：HAL库外部中断回调函数
  * 参    数：GPIO_Pin - 触发中断的GPIO引脚
  * 返 回 值：无
  * 注意事项：此函数为HAL库的中断回调函数，在HAL_GPIO_EXTI_IRQHandler中被调用
  */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    if (GPIO_Pin == GPIO_PIN_14)  // 判断是否是PB14引脚触发的中断
    {
        /* 如果出现数据乱跳的现象，可再次判断引脚电平，以避免抖动 */
        if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_14) == GPIO_PIN_RESET)
        {
            CountSensor_Count++;  // 计数值自增一次
        }
    }
}
