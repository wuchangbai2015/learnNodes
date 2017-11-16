//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//����Ӳ����51 TFT TEST BOARD V1.0/MCU :STC12LE5A60S2/STC12C5A60S2   ����:33MHZ
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
/* 
������Ի���:��Ƭ��STC12LE5A60S2/STC12C5A60S2,����33M  ��Ƭ��������ѹ3.3V
����Ĭ��IO���ӷ�ʽ��
���߷�ʽ��D/C-P3^5;    SDI-P3^6;   SCK-P3^7;   CS-P1^0;   REST-P1^2;
*/
#include "config.h"
#include "5X8ziku.h"


void LCDShiftWrite(u8 dat)   
{    
  u8 i;                                      
  u8 Series; 
	                                         
  Series = dat;   
  for(i=0; i<8; i++)   
  {   
    LCD_SCK=0;  
		if(Series&0x80) LCD_SDI=1;
		else LCD_SDI=0;
    LCD_SCK=1;                            
    Series = Series << 1;               
  }   
}   


void send_cmd(u8 cmd)
{
  LCD_CS=0;
	LCD_DC=0;
  LCDShiftWrite(cmd);
  LCD_CS=1;
}

void send_dat(u8 dat)
{
  LCD_CS=0;
	LCD_DC=1;
  LCDShiftWrite(dat);
  LCD_CS=1;
}


void LCDInit(void) 
{ 
	LCD_RST=1;	
	delayms(5);
	LCD_RST=0;
	delayms(20);	
	LCD_RST=1;	
	delayms(20);
	
  send_cmd(0xe2);	 //��λ
	delayms(10);
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

void Lcd_Address(u16 page,u16 column)
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
void Display_128x64(u8 *dp)
{
	u8 i,j;
	
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
void Display_Graphic_16x16(u8 page,u8 column,u8 *dp)
{
	u8 i,j;
	
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
void Display_Graphic_8x16(u8 page,u8 column,u8 *dp)
{
	u8 i,j;
	
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
void Display_Graphic_5x8(u8 page,u8 column,u8 *dp)
{
	u8 col_cnt;
	
    Lcd_Address(page,column);
	for (col_cnt=0;col_cnt<5;col_cnt++)
	{	
		send_dat(*dp);
		dp++;
	}
}

void Scribing(void)
{
	u8 i;
	
	Lcd_Address(2, 1);
	for (i=0; i<128; i++)
	{
		send_dat(0x08);
	}		
}

void DisplayFont(u8 page, u8 column, u8 No, u8 typeface)
{
	u8 *dp;
	
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

