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
void Pop(sqStack *s,ElemType *e)
{
    if(s->top==s->base)
        return;
    *e=*(--(s->top));

}
void ClearStack(sqStack *s)
{
    s->top=s->base;
}
void DestroyStack(sqStack *s)
{
    int i,len;
    len=s->stackSize;
    for(i=0;i<len;i++)
    {
        free(s->base);
        s->base++;
    }
    s->base=s->top=NULL;
    s->stackSize=0;
}
int StackLen(sqStack s)//���Դ����ݣ��޸Ĵ�ָ��
{
    return(s.top-s.base);
}
int main()
{
    ElemType c;
    sqStack s;
    int len,i,sum=0;
    InitStack(&s);
    printf("�������������������#���ű�ʾ����\n");
    scanf("%c",&c);
    while(c!='#')
    {
        Push(&s,c);
        scanf("%c",&c);
    }
    getchar();//���ջس�
    len=StackLen(s);
    printf("ջ�ĵ�ǰ�����ǣ�%d\n",len);
    for(i=0;i<len;i++)
    {
        Pop(&s,&c);
        sum+=(c-48)*pow(2,i);
    }
    printf("ת����ʮ�������ǣ� %d\n",sum);
    return 0;
}
