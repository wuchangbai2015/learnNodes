#include "led.h"
#include "timer.h"
#include "key.h"
#include "usart.h"
#include "lcd.h"

extern key_state key0, key1, key2, key3;
extern ptl_stack tx_stack;
extern ptr_stack rx_stack;

int main(void)
{
    u8 i,j;

    /*��ֹʹ��JTAG���ţ��������ã�������ͨI/O*/
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
    GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);   
    
    
    SystemInit();                              //��ʼ��ϵͳ��ʹ��ϵͳƵ��Ϊ72M
    systick_init();                            //����Systick��ʹ��1ms�����ж�
    led_gpio_init ();                          //����LED�����ܽ�
    key_gpio_init ();                          //���ð�����������
    usart_config();
    Init_ST7567();
    LCD_BK_ON;
    for(i = 0; i < 8; i++)
    {
        write_lcd_cmd_spi(0xb0+i);
        for(j = 0; j < 128; j++)
        {
            write_lcd_cmd_spi(0x10 + ((j & 0xf0) >> 4));
            write_lcd_cmd_spi(0x00 + (j & 0x0f));
            write_lcd_data_spi(0x00);
        }
    }
    while(1)
    {
        display_pic(0, POSTIVE);
        delay_ms(2000);
        display_pic(1, POSTIVE);
        delay_ms(2000);
        display_pic(0, NECTIVE);
        delay_ms(2000);
        display_pic(1, NECTIVE);
        delay_ms(2000);
    }
}