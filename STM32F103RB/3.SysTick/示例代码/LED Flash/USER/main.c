#include "led.h"
#include "timer.h"
int main(void)
{
    SystemInit();                              //��ʼ��ϵͳ��ʹ��ϵͳƵ��Ϊ72M
    systick_init();                            //����Systick��ʹ��1ms�����ж�
    led_gpio_init ();
    while(1)
    {
        GPIO_SetBits (GPIOB, GPIO_Pin_15);
        delay_ms(1000);                        //�ӳ�1s
        GPIO_ResetBits (GPIOB, GPIO_Pin_15);
        delay_ms(1000);                        //�ӳ�1s
    }
}