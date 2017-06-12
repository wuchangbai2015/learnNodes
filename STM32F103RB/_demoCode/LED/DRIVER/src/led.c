#include "led.h"

void led_gpio_init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    /*ʹ��GPIOB��rccʱ��*/
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);  
    
    /*����GPIO����*/
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
      
    /*��ʼ��GPIO*/
    GPIO_Init(GPIOB, &GPIO_InitStructure);
}
