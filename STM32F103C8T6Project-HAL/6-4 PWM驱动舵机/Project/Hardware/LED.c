#include "LED.h"

/**
 * 函    数：LED初始化
 * 参    数：无
 * 返 回 值：无
 */
void LED_Init(void)
{
    // HAL库生成代码已经完成了引脚的初始化，所以此处无需再初始化
    // 关于引脚的初始化配置，跳转这个函数 MX_GPIO_Init()
}

/**
 * 函    数：LED1开启
 * 参    数：无
 * 返 回 值：无
 */
void LED1_ON(void)
{
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET); // 设置PA1引脚为低电平
}

/**
 * 函    数：LED1关闭
 * 参    数：无
 * 返 回 值：无
 */
void LED1_OFF(void)
{
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET); // 设置PA1引脚为高电平
}

/**
 * 函    数：LED1状态翻转
 * 参    数：无
 * 返 回 值：无
 */
void LED1_Turn(void)
{
    if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == 0)             // 获取输出寄存器的状态，如果当前引脚输出低电平
    {
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET);   // 则设置PA1引脚为高电平
    }
    else                                                      // 否则，即当前引脚输出高电平
    {
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET); // 则设置PA1引脚为低电平
    }
}

/**
 * 函    数：LED2开启
 * 参    数：无
 * 返 回 值：无
 */
void LED2_ON(void)
{
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET); // 设置PA2引脚为低电平
}

/**
 * 函    数：LED2关闭
 * 参    数：无
 * 返 回 值：无
 */
void LED2_OFF(void)
{
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET); // 设置PA2引脚为高电平
}

/**
 * 函    数：LED2状态翻转
 * 参    数：无
 * 返 回 值：无
 */
void LED2_Turn(void)
{
    if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_2) == 0)            // 获取输出寄存器的状态，如果当前引脚输出低电平
    {
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET);  // 则设置PA2引脚为高电平
    }
    else                                                      // 否则，即当前引脚输出高电平
    {
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET); // 则设置PA2引脚为低电平
    }
}
