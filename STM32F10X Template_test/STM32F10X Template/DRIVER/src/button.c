#include "button.h"

key_state key0;
/******************************************************************************/
//��ѯ�ķ�ʽ
void button_gpio_init()
{
    GPIO_InitTypeDef GPIO_InitStructure;
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); //��GPIOB��RCCʱ��
    
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; //��������   
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
      
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    
}
/******************************************************************************/
//�жϵķ�ʽ
void button_gpio_interrupt_init()
{
    GPIO_InitTypeDef GPIO_InitStructure; //���� GPIO �ṹ��
    NVIC_InitTypeDef NVIC_InitStructure; //�����ⲿ�жϽṹ��   
    EXTI_InitTypeDef EXTI_InitStructure; //�����жϿ������ṹ��
   
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_AFIO,ENABLE); //���� GPIOB �� AFIO�� ���ö˿ڣ� ʱ��
    
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOB,&GPIO_InitStructure); //��ʼ�� GPIO
   
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource5); //��PB5 �� EXIT_5 ����
    
    EXTI_InitStructure.EXTI_Line = EXTI_Line5; //ѡ�� EXTI_Line5
    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt; //�ⲿ�ж�ģʽ
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling; //�½��س���
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;
    EXTI_Init(&EXTI_InitStructure);
    
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0); //�����ж������ȼ� 0
    NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn; //PPP �ⲿ�ж���  ������Ķ���EXTI_Line5�й�ϵ�����Բ鿴NVIT_INIT���ĵ�����
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3; //������ռ���ȼ�Ϊ 3
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0; //���ô����ȼ�Ϊ 0
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}

//�жϴ�����
void EXTI9_5_IRQHandler(void)
{
    u16 i, j;
    if(EXTI_GetITStatus(EXTI_Line5) != RESET) //����� EXIT_5 �������ж�,����
    {
        for(i = 100; i > 0; i--)
        for(j = 720; j > 0; j--); //�ӳ�һ�� ����
        if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_5) == RESET) 
        {
            key0.led_on_off = key0.led_on_off >= 4 ? 0 : key0.led_on_off + 1;
            key0.key_change_bit = CHGE_IN;
        } 
//        if((key0.led_on_off % 2) == 1)
//        {
//            turnOn();
//        } 
//        else
//        {
//            turnOff();
//        } 
        EXTI_ClearITPendingBit(EXTI_Line5); //�����־
    }
}
/******************************************************************************/








//int button_press()
//{
//    u8 state = 0;
//    if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_3) == RESET)
//    {
//        delay_ms (10);
//        if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_3) == RESET)
//        {
//            state = state >= 4 ? 0 : state + 1;
//        }
//        while(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_3) == RESET);
//    }
//
//    return state;
//}



