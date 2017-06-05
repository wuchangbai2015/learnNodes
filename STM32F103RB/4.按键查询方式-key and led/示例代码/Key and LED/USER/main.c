#include "led.h"
#include "timer.h"
#include "key.h"

int main(void)
{
  
    u8 led_state;
    
    SystemInit();                              //��ʼ��ϵͳ��ʹ��ϵͳƵ��Ϊ72M
    systick_init();                            //����Systick��ʹ��1ms�����ж�
    led_gpio_init ();                          //����LED�����ܽ�
    key_gpio_init ();                          //���ð�����������
    
    while(1)
    {
        if (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_7) == RESET) //��ⰴť�ǲ��Ǳ�������
        {
            delay_ms (10);// ��������
            if (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_7) == RESET) //GPIO_ReadInputDataBit()��ȡָ���˿ڹܽŵ�����
            {
              led_state = led_state >= 4 ? 0 : led_state + 1;
            }
            while (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_7) == RESET);
        }
        if((led_state % 2) == 1)
        {
            GPIO_SetBits (GPIOB, GPIO_Pin_10);   //���
        }
        else
        {
            GPIO_ResetBits (GPIOB, GPIO_Pin_10); //�ص�
        }
    }
}