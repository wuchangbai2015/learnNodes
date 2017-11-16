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
#ifndef  __LCD_H
#define  __LCD_H  

 
//-----------------LCD�˿ڶ���---------------- 
#define	LCD_RST     P12      //��λ        P1.2
#define	LCD_CS      P10      //Ƭѡ�˿�  	 P1.0
#define	LCD_DC	    P35      //����/����   P3.5   
#define	LCD_SDI	    P36      //����			   P3.6
#define	LCD_SCK  	  P37      //ʱ��    		 P3.7					  	    																						  
	
	
typedef enum
{
	FONT_5X8 = 1,
	FONT_8X16,
	FONT_16X16,
	FONT_128X64,
	SCRIBING
}Typeface;

void LCDInit(void);
void Lcd_Address(u16 page,u16 column);
void ClearScreen(void);
void DisplayFont(u8 page, u8 column, u8 No, u8 typeface);


#endif    // end 

