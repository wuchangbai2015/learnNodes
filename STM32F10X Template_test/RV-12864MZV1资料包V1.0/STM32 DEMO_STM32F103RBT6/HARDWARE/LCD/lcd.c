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
#include "lcd.h"
#include "stdlib.h"
#include "usart.h"
#include "delay.h"	  
#include "5X8ziku.h"


void LCDShiftWrite(u8 dat)   
{    
  u8 i;                                      
  u8 Series,Temp; 
	                                         
  Series = dat;   
  for(i=0; i<8; i++)   
  {   
    LCD_SCK_CLR;                              
    Temp=Series & 0x80;                    
    if(Temp)                              
    {   
      LCD_SDI_SET;                 
    }   
    else    
    {   
      LCD_SDI_CLR;                   
    } 
    LCD_SCK_SET;                            
    Series = Series << 1;               
  }   
}   


void send_cmd(u8 cmd)
{
  LCD_CS_CLR;
	LCD_DC_CLR;
  LCDShiftWrite(cmd);
  LCD_CS_SET;
}

void send_dat(u8 dat)
{
  LCD_CS_CLR;
	LCD_DC_SET;
  LCDShiftWrite(dat);
  LCD_CS_SET;
}


void LCDInit(void) 
{ 
	GPIO_InitTypeDef GPIO_InitStructure;

 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC|RCC_APB2Periph_AFIO, ENABLE); 
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable , ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10|GPIO_Pin_9|GPIO_Pin_8|GPIO_Pin_7|GPIO_Pin_6;	   //GPIO_Pin_10
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  //�������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure); //GPIOC	
	GPIO_SetBits(GPIOC,GPIO_Pin_9|GPIO_Pin_8|GPIO_Pin_7|GPIO_Pin_6);
	GPIO_ResetBits(GPIOC,GPIO_Pin_10);
	
  send_cmd(0xe2);	 //��λ
	delay_ms(1);
	send_cmd(0xa0);  //��ɨ��˳�򣺴�����
	send_cmd(0xc8);  //��ɨ��˳�򣺴��µ��ϣ�c0���ϵ���
	send_cmd(0xa2);	 //����ƫѹ��1/9
	send_cmd(0x2f);	 //���Ƶ�Դ
	send_cmd(0x25);	 //�ֵ��Աȶ�
	send_cmd(0x81);  //΢���Աȶ�,����΢���Աȶ�����
	send_cmd(0x19);  //���õ�ѹ�Ĳ���RRֵ(�Աȶ����޸Ĵ�ֵ����Ũ�����ֵ����֮����)
	send_cmd(0x40);  //��ʼ�У���һ�п�ʼ
	send_cmd(0xaf);  //����ʾ
	
	ClearScreen();

} 

void Lcd_Address(uint16_t page,uint16_t column)
{
	column=column-0x01;
	send_cmd(0xb0+page-1);   /*����ҳ��ַ*/ //1-8
	send_cmd(0x10+(column>>4&0x0f));	/*�����е�ַ�ĸ�4λ*///0-128
	send_cmd(column&0x0f);	/*�����е�ַ�ĵ�4λ*/	
}

/*ȫ������*/
void ClearScreen(void)
{
	unsigned char i,j;
	for(i=0;i<9;i++)
	{
		send_cmd(0xb0+i);  //�ӵ�0ҳ��ʼ
		send_cmd(0x10);
		send_cmd(0x00);
		for(j=0;j<132;j++)
		{
		 	send_dat(0x00);
		}
	}
}

/*��ʾ128x64����ͼ��*/
void Display_128x64(uint8_t *dp)
{
	uint8_t i,j;
	for(j=0;j<8;j++)
	{
		Lcd_Address(j+1,1);
		for (i=0;i<128;i++)
		{	
		  send_dat(*dp);	 	/*д���ݵ�LCD,ÿд��һ��8λ�����ݺ��е�ַ�Զ���1*/
		  dp++;
		}
	}
}

/*��ʾ16x16����ͼ�񡢺��֡���Ƨ�ֻ�16x16���������ͼ��*/
void Display_Graphic_16x16(uint8_t page,uint8_t column,uint8_t *dp)
{
	uint8_t i,j;
	for(j=0;j<2;j++)
	{
		Lcd_Address(page+j,column);
		for (i=0;i<16;i++)
		{	
			send_dat(*dp);	 /*д���ݵ�LCD,ÿд��һ��8λ�����ݺ��е�ַ�Զ���1*/
			dp++;
		}
	}
}

/*��ʾ8x16����ͼ��ASCII, ��8x16����������ַ�������ͼ��*/
void Display_Graphic_8x16(uint8_t page,uint8_t column,uint8_t *dp)
{
	uint8_t i,j;
	for(j=0;j<2;j++)
	{
		Lcd_Address(page+j,column);
		for (i=0;i<8;i++)
		{	
			send_dat(*dp);	 	/*д���ݵ�LCD,ÿд��һ��8λ�����ݺ��е�ַ�Զ���1*/
			dp++;
		}
	}
}

/*��ʾ5*8����ͼ��ASCII, ��5x8����������ַ�������ͼ��*/
void Display_Graphic_5x8(uint8_t page,uint8_t column,uint8_t *dp)
{
	uint8_t col_cnt;
    Lcd_Address(page,column);
	for (col_cnt=0;col_cnt<5;col_cnt++)
	{	
		send_dat(*dp);
		dp++;
	}
}

void Scribing(void)
{
	uint8_t i;
	Lcd_Address(2, 1);
	for (i=0; i<128; i++)
	{
		send_dat(0x08);
	}		
}

void DisplayFont(uint8_t page, uint8_t column, uint8_t No, uint8_t typeface)
{
	uint8_t *dp;
	switch (typeface)
	{
		case FONT_5X8:
			dp = font5x8[No];
			Display_Graphic_5x8(page, column, dp);
			break;
		case FONT_8X16:
			dp = font8x16[No];
			Display_Graphic_8x16(page, column, dp);
			break;
		case FONT_16X16:
			dp = font16x16[No];
			Display_Graphic_16x16(page, column, dp);
			break;
		case FONT_128X64:
			dp = IMG128x64;
			Display_128x64(dp);
			break;
		case SCRIBING:
			Scribing();
			break;
		default:
			break;
	}		   
}


