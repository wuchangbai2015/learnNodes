#include "dht11.h"
u8 dht11_buffer[5];

void dht11_portin(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    //Configure pin as input
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 ;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; //��������
    GPIO_Init(GPIOA,&GPIO_InitStructure);
}

void dht11_portout(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    //Configure pin as input
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 ;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //�������
    GPIO_Init(GPIOA,&GPIO_InitStructure);
}
void dht11_reset(void)
{
    dht11_portout(); // ��DHT11���������ó����ģʽ
    DHT11_OUT_L;    // MCU������������
    delay_us(19000);// ����19ms
    DHT11_OUT_H;    // MCU������������
    delay_us(30);   //����30us
    dht11_portin();
}

u16 dht11_scan(void)
{
    return DHT11_IN;
}

u16 dht11_read_bit(void)
{
    while(DHT11_IN == RESET);   //��⵽�͵�ƽʱ��ȴ���ÿһλ���ݵ�50us�͵�ƽ
    delay_us(40);
    if(DHT11_IN == SET)
    {
        while(DHT11_IN == SET);
        return 1;
    }
    else
        return 0;
}

u16 dht11_read_byte(void)
{
    u16 i;
    u16 data = 0;
    for(i = 0; i < 8; i ++)
    {
        data <<= 1;
        data |= dht11_read_bit();
    }
    return data;
}

/*******************************************************************************
һ�����������ݴ���Ϊ40bit,��λ�ȳ���

���ݸ�ʽ:8bitʪ����������+8bitʪ��С������
         +8bi�¶���������+8bit�¶�С������
         +8bitУ���
���ݴ�����ȷʱУ������ݵ��ڡ�8bitʪ����������+8bitʪ��С������+8bi�¶���������+
8bit�¶�С�����ݡ����ý����ĩ8λ��


1.�����������ó����ģʽ
2.�����������Ͳ��ұ���19s
3.�����������߲��ұ���30s
4.�����������ó�����ģʽ
��ʱDHT�������Ϳ�ʼ���������ݵ�׼������

5.��mcu�Ĺܽ�ȥ���dht�������Ƿ�����Ӧ�ź�
����Ǹߵ�ƽ��˵��û�з�����Ӧ�źţ�������
����ǵ͵�ƽ��˵����������Ӧ�ź�
6.�ȴ� 80us �ĵ͵�ƽ��Ӧ�źŽ���
7.�ȴ� 80us �ĸߵ�ƽ��Ӧ�źŽ���

8.���ζ�ȡ5byte���ݴ���һ����������
9.�ȴ� 40 λ����������� 50us �͵�ƽ�������
10.һ�����ݶ�ȡ����֮�󣬽����������ó����ģʽ
11.��mcu�Ĺܽ�����

12.У��
*******************************************************************************/
u16 dht11_read_data(void)
{
    u16 i = 0;
    dht11_reset();
    if(dht11_scan() == 0)   //��⵽DHT11��Ӧ
    {
        while(dht11_scan() == RESET);
        while(dht11_scan() == SET);
        for(i = 0; i < 5; i ++)
        {
            dht11_buffer[i] = dht11_read_byte();
        }
        while(DHT11_IN == RESET);
        dht11_portout();
        DHT11_OUT_H;
        if((dht11_buffer[0] + dht11_buffer[1] + dht11_buffer[2] + dht11_buffer[3]) == dht11_buffer[4])
        {
            return 1;
        }
        else
            return 0;
    }
    else
        return 0;
    
}