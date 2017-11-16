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
#include "STC12C5A.H"
#include <intrins.h>
#include <sys.h>
#include <lcd.h>


sbit key1=P3^2;
sbit key2=P3^3;
sbit key3=P3^4;
//������˵����
//������ʾ����LOGO
//����1��P3.2��������ʾASCII�ַ���
//����2��P3.3��������ʾ���֣�
//����3��P3.4��������ʾBMP
main()
{ 
	u8 i,j;
	
	LCDInit();      //LCD��ʼ��
	DisplayFont(1,1 , 0, FONT_128X64);
	
	while(1)
	{		
	  if(key1==0)	//�������1����,������ʾASCII�ַ�
		{						   
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
		}
		if(key2==0)	//�������2����,������ʾ����
		{		
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
		}
		if(key3==0)	//�������3����,������ʾBMPͼƬ
		{
			ClearScreen();
			DisplayFont(1,1 , 0, FONT_128X64);
		}
	}
}
