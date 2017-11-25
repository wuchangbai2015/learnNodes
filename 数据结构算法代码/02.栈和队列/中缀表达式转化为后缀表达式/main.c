#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define SIZE 20
#define STACKINCREMENT 10
#define MAXBUFFER 10
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
int StackLen(sqStack s)//���Դ����ݣ��޸Ĵ�ָ��
{
    return(s.top-s.base);
}
int main()
{
    sqStack s;
    char c,e;
    InitStack(&s);
    printf("��������׺���ʽ����#��Ϊ������־��");
    scanf("%c",&c);
    while(c!='#')
    {
        while(isdigit(c))
        {
            printf("%c",c);
            scanf("%c",&c);
            if(!isdigit(c))
            {
                printf(" ");
            }
        }
        if(c==')')
        {
            Pop(&s,&e);
            while(e!='(')
            {
                printf("%c ",e);
                Pop(&s,&e);
            }
        }
        else if(c=='+'||c=='-')
        {
            if(!StackLen(s))
            {
                Push(&s,c);
            }
            else
            {
                do
                {
                    Pop(&s,&e);
                    if(e=='(')
                    {
                        Push(&s,e);
                    }
                    else
                    {
                        printf("%c ",e);
                    }
                }
                while(StackLen(s)&& '('!=e);
                Push(&s,c);
            }
        }
        else if(c=='*'||c=='/'||c=='(')
        {
            Push(&s,c);
        }
        else if('#'==c)
            break;
        else
        {
            printf("\n���������ʽ����!\n");
            return -1;
        }
        scanf("%c",&c);
    }
    while(StackLen(s))
    {
        Pop(&s,&e);
        printf("%c ",e);
    }
    return 0;
}
