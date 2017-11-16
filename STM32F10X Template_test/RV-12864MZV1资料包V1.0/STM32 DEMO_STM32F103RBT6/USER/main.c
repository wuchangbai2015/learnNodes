//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//����Ӳ����ԭ��MINI/����STM32���԰�   ����:8MHZ ��Ƶ��72MHZ
//RV12864 SPI����TFTҺ������
//ronview@ShenZhen RonView co., LTD
//�Ա���վ��https://shop150504992.taobao.com/
//��˾�ṩ����֧�֣��κμ������⻶ӭ��ʱ����ѧϰ
//�ֻ�:17097319383
//����:990777066@qq.com 
//QQ:990777066
//Skype:ronview
//QQ����֧��Ⱥ��288486111
//��������:2016/3/18
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ����������ʾ�������޹�˾ 2015-2065
//All rights reserved
//////////////////////////////////////////////////////////////////////////////////
//����˵����
//1��VDD��3.3V
//2��GND��GND
//3��CS��PC9
//4��RST��RESET
//5��D/C��PC8
//6��SDI��PC7
//7��SCK��PC6
//8��BL��3.3V(���߿��Լ������ܿ��ء�PWM����)
//9��---13��Ԥ�����ܣ������Լ���Ҫ���ѡ��
//////////////////////////////////////////////////////////////////////////////////
#include "led.h"
#include "delay.h"
#include "sys.h"
#include "key.h"
#include "usart.h"
#include "lcd.h"


//������˵����
//������ʾ����LOGO
//����1��PC5��������ʾASCII�ַ���
//����2��PC4��������ʾ���֣�
//����3��PC11��������ʾBMP
 int main(void)
 {
	u8 x=0,i,j,t;
	 
	SystemInit();
	delay_init(72);	     //��ʱ��ʼ��
	NVIC_Configuration();
	uart_init(9600);
 	LED_Init();
	KEY_Init();
	LCDInit();
 
	DisplayFont(1,1 , 0, FONT_128X64);
	 
	while(1)
	{		
		t=KEY_Scan();
	  if(t)
		{						   
			switch(t)
			{				 
				case 1:
					ClearScreen();
					for (i=0; i<16; i++)
					{
						DisplayFont(1, i*8+1, i, FONT_8X16);
					}
					for (i=0; i<16; i++)
					{
						j = i;
						DisplayFont(3, j*8+1, j+16, FONT_8X16);
					}
					for (i=0; i<16; i++)
					{
						j = i;
						DisplayFont(5, j*8+1, j+32, FONT_8X16);
					} 
					for (i=0; i<16; i++)
					{
						j = i;
						DisplayFont(7, j*8+1, j+48, FONT_8X16);
					} 
					break;
				case 2:
					ClearScreen();
					for (i=0; i<16; i++)
					{
						j = i;
						DisplayFont(1, j*16+1, j, FONT_16X16);
					} 
					for (i=0; i<16; i++)
					{
						j = i;
						DisplayFont(3, j*16+1, j+8, FONT_16X16);
					} 
					for (i=0; i<16; i++)
					{
						j = i;
						DisplayFont(7, j*16+1, j+16, FONT_16X16);
					}
					break;
				case 3:				
					ClearScreen();
					DisplayFont(1,1 , 0, FONT_128X64);
					break;
				case 4:				
					LED0=!LED0;
					LED1=!LED1;
					break;
			}
		}
		
	  x++;
		if(x==12)x=0;
		LED0=!LED0;					 
		delay_ms(10);	
	}	
 }

