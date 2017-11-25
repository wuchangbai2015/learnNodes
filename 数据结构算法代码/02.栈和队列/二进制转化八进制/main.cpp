#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 20
#define STACKINCREMENT 10
typedef char ElemType;//�������int��һ�����ֶ���һ�����
typedef struct
{
    ElemType *base;
    ElemType *top;
    int stackSize;
}sqStack;
void InitStack(sqStack *s)
{
    s->base=(ElemType *)malloc(SIZE*sizeof(ElemType));
    if(!s->base)
        exit(0);
    s->top=s->base;
    s->stackSize=SIZE;
}
void Push(sqStack *s,ElemType e)
{
    if(s->top-s->base==s->stackSize)
    {
        s->base=(ElemType *)realloc(s->base,(s->stackSize+STACKINCREMENT)*sizeof(ElemType));
        if(!s->base)
            exit(0);
        s->top=s->base+s->stackSize;
        s->stackSize=s->stackSize+STACKINCREMENT;
    }
    *(s->top)=e;
    s->top++;
}
int Pop(sqStack *s,ElemType *e)
{
    if(s->top==s->base)
        return 0;
    *e=*(--(s->top));
    return 1;

}
int StackLen(sqStack s)//���Դ����ݣ��޸Ĵ�ָ��
{
    return(s.top-s.base);
}
int main()
{
    ElemType c,ch,chi;
    sqStack s,q;
    int len1,len2,i,j,k,sum=0;
    InitStack(&s);
    InitStack(&q);
    printf("�������������������#���ű�ʾ����\n");
    scanf("%c",&c);
    while(c!='#')
    {
        Push(&s,c);
        scanf("%c",&c);
    }
    getchar();//���ջس�
    len1=StackLen(s);
    for(i=0;i<len1;i=i+3)
    {
        for(j=0;j<3;j++)
        {
            Pop(&s,&c);
            sum+=(c-48)*pow(2,j);
            if( s.base == s.top )
                break;
        }
        chi=sum+'0';
        Push(&q,chi);
        sum=0;//ÿ��ѭ��������sumҪ����
    }
    len2=StackLen(q);
    printf("ת����˽�������:");
    for(k=0;k<len2;k++)
    {
        Pop(&q,&ch);
        printf("%c",ch);
    }
    return 0;
}

