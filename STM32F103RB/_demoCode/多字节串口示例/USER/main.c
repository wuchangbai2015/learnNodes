#include "led.h"
#include "timer.h"
#include "key.h"
#include "usart.h"

extern key_state key0, key1, key2, key3;
extern ptl_stack tx_stack;
extern ptr_stack rx_stack;
int main(void)
{
    
    SystemInit();                              //��ʼ��ϵͳ��ʹ��ϵͳƵ��Ϊ72M
    systick_init();                            //����Systick��ʹ��1ms�����ж�
    led_gpio_init ();                          //����LED�����ܽ�
    key_gpio_init ();                          //���ð�����������
    usart_config();
    tx_stack_init();                           //��ʼ�����ͻ�����
    rx_stack_init();                           //��ʼ�����ջ�����
    LED0_OFF();
    LED1_OFF();
    LED2_OFF();
    LED3_OFF();
    while(1)
    {
        if(key0.key_change_bit == CHGE_IN)
        {
            if((key0.led_on_off % 2) == 1)
            {
                LED0_ON();  //����
                tx_stack.data[0] = 0xff;
            }
            else
            {
                LED0_OFF(); //�ص�
                tx_stack.data[0] = 0x00;
            }
            key0.key_change_bit = NO_CHGE;
            send_ptl();
        }
        if(key1.key_change_bit == CHGE_IN)
        {
            if((key1.led_on_off % 2) == 1)
            {
                LED1_ON();  //����
                tx_stack.data[1] = 0xff;
            }
            else
            {
                LED1_OFF(); //�ص�
                tx_stack.data[1] = 0x00;
            }
            key1.key_change_bit = NO_CHGE;
            send_ptl();
        }
        if(key2.key_change_bit == CHGE_IN)
        {
            if((key2.led_on_off % 2) == 1)
            {
                LED2_ON();  //����
                tx_stack.data[2] = 0xff;
            }
            else
            {
                LED2_OFF(); //�ص�
                tx_stack.data[2] = 0x00;
            }  
            key2.key_change_bit = NO_CHGE;
            send_ptl();
        }
        if(key3.key_change_bit == CHGE_IN)
        {
            if((key3.led_on_off % 2) == 1)
            {
                LED3_ON();  //����
                tx_stack.data[3] = 0xff;
            }
            else
            {
                LED3_OFF(); //�ص�
                tx_stack.data[3] = 0x00;
            }
            key3.key_change_bit = NO_CHGE;
            send_ptl();
        }
        if(rx_stack.lock_flag == LOCK)   // ������
        {
            ptr_handle(&rx_stack.data[0]);//����Э���������
        }
    }
}