#include "usart.h"

void usart_config(void)
{
    
    /*1����GPIO��AFIO��USART1��ʱ��*/
    RCC_APB2PeriphClockCmd( RCC_APB2Periph_USART1 |RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO, ENABLE);
    
    /*2\��ʼ����Ӧ�Ĵ�������*/
    usart_release_gpio_init();  
    
    /*3�����ô����ж�*/
    usart_nvic_config();
    
    /*4�����ô���ģʽ*/
    usart_para_config();
}
void usart_release_gpio_init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct;
    
    /*����PA9Ϊ�����������*/
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStruct);
    
    /*����PA10Ϊ��������*/
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_10;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStruct);
}
void usart_para_config(void)
{
    USART_InitTypeDef USART_InitStruct;
    
    USART_InitStruct.USART_BaudRate = 115200;
    USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStruct.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
    
    USART_InitStruct.USART_WordLength = USART_WordLength_8b;  //8
    USART_InitStruct.USART_Parity = USART_Parity_No;          //n
    USART_InitStruct.USART_StopBits = USART_StopBits_1;       //1
    
    USART_Init(USART1, &USART_InitStruct);
    
    USART_ClearFlag(USART1,USART_FLAG_TC); //���������ɱ�־λ
    USART_Cmd(USART1, ENABLE); //ʹ�ܴ��� 1
    
    USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
}
void usart_nvic_config(void)
{
    NVIC_InitTypeDef NVIC_InitStructure;
  
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
    
    NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn; //���ô��� 1 �ж�
    
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; //��ռ���ȼ�0
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0; //�����ȼ�Ϊ 0
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //ʹ��
    NVIC_Init(&NVIC_InitStructure);
}
void USART1_IRQHandler(void)
{
    u8 receive_data;
    if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)
    {
        receive_data = USART_ReceiveData(USART1);
        if(receive_data == 0x00)
        {
            GPIO_ResetBits (GPIOB, GPIO_Pin_10); //�ص�
        }
        else
        {
            GPIO_SetBits (GPIOB, GPIO_Pin_10);   //����
        }
    }
    USART_ClearITPendingBit(USART1, USART_IT_RXNE);
}