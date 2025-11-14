#include "Encoder.h"

int16_t Encoder_Count;					//全局变量，用于计数旋转编码器的增量值

/**
  * 函    数：旋转编码器初始化
  * 参    数：无
  * 返 回 值：无
  */
void Encoder_Init(void)
{
    // HAL库生成代码已经完成了引脚的初始化，所以此处无需再初始化
    // 关于引脚的初始化配置，跳转这个函数 MX_GPIO_Init()
}

/**
  * 函    数：旋转编码器获取增量值
  * 参    数：无
  * 返 回 值：自上此调用此函数后，旋转编码器的增量值
  */
int16_t Encoder_Get(void)
{
	/*使用Temp变量作为中继，目的是返回Encoder_Count后将其清零*/
	/*在这里，也可以直接返回Encoder_Count
	  但这样就不是获取增量值的操作方法了
	  也可以实现功能，只是思路不一样*/
	int16_t Temp;
	Temp = Encoder_Count;
	Encoder_Count = 0;
	return Temp;
}

/**
  * 函    数：HAL_GPIO_EXTI_Callback
  * 参    数：GPIO_Pin - 触发中断的GPIO引脚
  * 返 回 值：无
  * 描    述：GPIO外部中断回调函数，用于处理编码器输入变化
  * 注意事项：此函数为HAL库预留的回调函数，在相应的GPIO外部中断发生时自动调用
  */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    // 判断是哪个引脚触发的中断
    if(GPIO_Pin == GPIO_PIN_0)
    {
        // 添加软件消抖延时（可选）
        HAL_Delay(1);
        
        // 再次确认引脚状态以消除抖动影响
        if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0) == GPIO_PIN_RESET)
        {
            // PB0的下降沿触发中断，此时检测另一相PB1的电平，判断旋转方向
            if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_1) == GPIO_PIN_RESET)
            {
                Encoder_Count--;  // 此方向定义为反转，计数变量自减
            }
        }
    }
    else if(GPIO_Pin == GPIO_PIN_1)
    {
        // 添加软件消抖延时（可选）
        HAL_Delay(1);
        
        // 再次确认引脚状态以消除抖动影响
        if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_1) == GPIO_PIN_RESET)
        {
            // PB1的下降沿触发中断，此时检测另一相PB0的电平，判断旋转方向
            if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0) == GPIO_PIN_RESET)
            {
                Encoder_Count++;  // 此方向定义为正转，计数变量自增
            }
        }
    }
}
