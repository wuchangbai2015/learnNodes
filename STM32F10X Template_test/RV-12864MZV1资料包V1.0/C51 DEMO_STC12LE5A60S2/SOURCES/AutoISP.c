#include "config.h"


// ISP��������
static const u8 ISP_DownCmd[4] = {0x55,0xaa,0x5a,0xa5};

// ��ʱ����
static void delay(u32 dly)
{
    u32 i;
    while(--dly > 0)
    {
        for(i=0;i++;i<1000000);
    }
}

// ���������⺯��
u8 ISP_CmpDownCmd(u8 chr)
{
    static u8 i=0;
    if(chr == ISP_DownCmd[i])
    {
        i++;
        if(i == 4)
        {
            delay(100000);          // ��ʱ1����㹻��
            IAP_CONTR = 0x60;       // ��λ��ϵͳISP�����
        }
    }else{
        i=0;
    }
    return 0;
}
/*
// ���ڷ���
void UART_SendChar(U8 chr)
{
    ES     =   0;  //�ش����ж�
    TI     =   0;  //���㴮�ڷ�������ж������־
    SBUF   =   chr;
    while(TI ==0); //�ȴ��������
    TI     =   0;  //���㴮�ڷ�������ж������־
    ES     =   1;  //�������ж�
}

char putchar (char c)
{
    UART_SendChar(c);
    return(c);
}

void UART_SendString(U8 *str)
{
    while(*str)
    {
        UART_SendChar(*str++);
    }
}

static const char code digits[17] = "0123456789ABCDEF";
void PutHEX(U8 c)
{
    UART_SendChar(digits[(c>>4)&0x0f]);
    UART_SendChar(digits[c&0x0f]);
}

*/
// �����ж�
void UART_Interrupt_Receive(void) interrupt 4
{
    u8 k = 0;
    if(RI==1)
    {
        RI  =   0;
        k   =   SBUF;
        ISP_CmpDownCmd(k);
    }
    if(TI == 1)
    {
        TI  =  0;
    }
}
// ���ڳ�ʼ��
void UartInit(void)		
{
    P3M0 &= ~0x03;
    P3M1 &= ~0x03;

	PCON &= 0x7f;       // �����ʲ�����
	SCON  = 0x50;       // 8λ����,�ɱ䲨����
	BRT   = 0xFA;       // �趨���������ʷ�������װֵ  //115200bps@22.1184MHz
	AUXR |= 0x04;       // ���������ʷ�����ʱ��ΪFosc,��1T
	AUXR |= 0x01;       // ����1ѡ����������ʷ�����Ϊ�����ʷ�����
	AUXR |= 0x10;       // �������������ʷ�����

    TI = 0;             // ���㴮�ڷ�������ж������־
    PS = 1;	            // �����ж�  ���ȼ�����λ, 1 Ϊ�����ȼ� 0 Ϊ�����ȼ�
    ES = 1;             // �������ж�
    EA = 1;             // �����ж�
}















