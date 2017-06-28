#include "led.h"
#include "timer.h"
#include "key.h"
#include "usart.h"

extern key_state key0;
int main(void)
{
    
    SystemInit();                              //��ʼ��ϵͳ��ʹ��ϵͳƵ��Ϊ72M
    systick_init();                            //����Systick��ʹ��1ms�����ж�
    led_gpio_init ();                          //����LED�����ܽ�
    key_gpio_init ();                          //���ð�����������
    usart_config();
    while(1)
    {
        if(key0.key_change_bit == CHGE_IN)
        {
            if((key0.led_on_off % 2) == 1)
            {
                GPIO_SetBits (GPIOB, GPIO_Pin_10);   //����
                USART_SendData(USART1, 0x01);
            }
            else
            {
                GPIO_ResetBits (GPIOB, GPIO_Pin_10); //�ص� 
                USART_SendData(USART1, 0x00);
            }
            key0.key_change_bit = NO_CHGE;
        }
        else
        {
            ;
        }
    }
}