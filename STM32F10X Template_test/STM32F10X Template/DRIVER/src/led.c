/*******************************************************************************

��չ������a6

Ŀǰ������PA10 ��PB10�������˿ڵ�ledû������
�����������Ķ˿� PA2 ��PA3 ��PA5����������֪��Ϊɶ

*******************************************************************************/

#include "led.h"

void led_gpio_init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    
    /*ʹ��GPIOB��rccʱ��*/
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); 
    
    /*����GPIO����*/
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10; 
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;// �������
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
   
    /*��ʼ��GPIO*/
    GPIO_Init(GPIOB, &GPIO_InitStructure);
}

void turnOn(void)
{
    GPIO_SetBits (GPIOB, GPIO_Pin_10);

}

void turnOff(void)
{
    GPIO_ResetBits (GPIOB, GPIO_Pin_10);
}

//void blink(void)
//{
//    while(1)
//    {   
//        GPIO_SetBits (GPIOA, GPIO_Pin_3);
//        delay_ms(200);
//        GPIO_ResetBits (GPIOA, GPIO_Pin_3);
//        delay_ms(200);    
//    
//    }
//
//}



