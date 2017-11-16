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
#ifndef __LCD_H
#define __LCD_H		
#include "sys.h"	 
#include "stdlib.h" 

 
////////////////////////////////////////////////////////////////////
//-----------------LCD�˿ڶ���---------------- 
#define	LCD_CS_SET  GPIO_SetBits(GPIOC,GPIO_Pin_9)    //Ƭѡ�˿�  	 PC9
#define	LCD_DC_SET	GPIO_SetBits(GPIOC,GPIO_Pin_8)    //����/����    PC8	   
#define	LCD_SDI_SET	GPIO_SetBits(GPIOC,GPIO_Pin_7)    //����			   PC7
#define	LCD_SCK_SET	GPIO_SetBits(GPIOC,GPIO_Pin_6)    //ʱ��    		 PC6
								    
#define	LCD_CS_CLR  GPIO_ResetBits(GPIOC,GPIO_Pin_9)     //Ƭѡ�˿�  PC9
#define	LCD_DC_CLR	GPIO_ResetBits(GPIOC,GPIO_Pin_8)     //����/���� PC8	   
#define	LCD_SDI_CLR	GPIO_ResetBits(GPIOC,GPIO_Pin_7)     //����			 PC7
#define	LCD_SCK_CLR	GPIO_ResetBits(GPIOC,GPIO_Pin_6)     //ʱ��			 PC6	    																						  
	

typedef enum
{
	FONT_5X8 = 1,
	FONT_8X16,
	FONT_16X16,
	FONT_128X64,
	SCRIBING
}Typeface;

void LCDInit(void);
void Lcd_Address(uint16_t page,uint16_t column);
void ClearScreen(void);
void DisplayFont(uint8_t page, uint8_t column, uint8_t No, uint8_t typeface);
									 
#endif  
	 
