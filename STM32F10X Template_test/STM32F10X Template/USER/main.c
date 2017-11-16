#include "led.h"
#include "button.h"
#include "usart.h"
#include "timer.h"


extern key_state key0;

int main(void)
{
    led_gpio_init ();
//    button_gpio_init();
    button_gpio_interrupt_init();
    
/******************************************************************************/    
    SystemInit();                              //��ʼ��ϵͳ��ʹ��ϵͳƵ��Ϊ72M
    systick_init();                            //����Systick��ʹ��1ms�����ж�
/******************************************************************************/
    
    timer2_config();
    
/*****************************************/
//   blink(); 
    
/*****************************************************************************/
/*
    ��ѯ���Ƶİ���   
*/
//    u8 led_state;
//    while(1)
//    {
//        if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_5) == RESET)
//        {
//            delay_ms (10);
//            if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_5) == RESET)
//            {
//              led_state = led_state >= 4 ? 0 : led_state + 1;
//            }
//            while (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_5) == RESET);
//        }
//        if((led_state % 2) == 1)
//        {
//            turnOn();  
//        }
//        else
//        {
//            turnOff(); 
//        }
//    } 
/*******************************************************************************/ 
// �ȴ��жϣ���ť���жϵĲ��ԣ�
//    while(1);
    
/******************************************************************************/
// �����ֽڲ���
//    usart_config();
//    while(1)
//    {
//        if(key0.key_change_bit == CHGE_IN)
//        {
//            if((key0.led_on_off % 2) == 1)
//            {
//                turnOn();   //����
//                USART_SendData(USART1, 0x01);// �����ڷ��͵��ֽ�����
//            }
//            else
//            {
//                turnOff(); //�ص�
//                USART_SendData(USART1, 0x00);
//            }
//            key0.key_change_bit = NO_CHGE;
//        }
//        else
//        {
//            ;
//        }
//    }   
/******************************************************************************/    
//    return 0;
    
/******************************************************************************/
 // pwm������ 
    while(1){
      breath_pwm_change();
    
    
    }

/******************************************************************************/
}