#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status; //���庯������
typedef int ElemType;
typedef struct Node
{
    ElemType data;
    struct Node *next;
}Node;
typedef struct Node *LinkList;
Status visit(ElemType c)
{
    printf("%d ",c);
    return OK;
}
Status InitList(LinkList *L)
{
    *L=(LinkList)malloc(sizeof(Node));
    if(!(*L))
    {
        return ERROR;
    }
    (*L)->next=NULL;
    return OK;
}
int ListLength(LinkList L)
{
    int i=0;
    LinkList p=L->next;
    while(p)
    {
        i++;
        p=p->next;
    }
    return i;
}
Status ListTraverse(LinkList L)
{
    LinkList p=L->next;
    while(p)
    {
        visit(p->data);
        p=p->next;
    }
    printf("\n");
    return OK;
}
void CreateListTail(LinkList *L,int n)
{
    int i;
    LinkList p,r;
    srand(time(0));
    *L=(LinkList)malloc(sizeof(Node));
    r=*L;
    for(i=0;i<n;i++)
    {
        p=(Node *)malloc(sizeof(Node));
        p->data=rand()%100+1;
        r->next=p;//p����ʱ���
        r=p;//r��ָ�������β��
    }
    r->next=NULL;
}
Status GetMidNode(LinkList L,ElemType *e)
{
    LinkList Search,mid;
    mid=Search=L;
    while(Search->next!=NULL)
    {
        if(Search->next->next!=NULL)
        {
            Search=Search->next->next;
            mid=mid->next;
        }
        else
        {
            Search=Search->next;
            mid=mid->next;
        }
    }
    *e=mid->data;
    return OK;
}
int main()
{
    LinkList L;
    Status i;
    char opp;
    ElemType e;
    int Find;
    int tmp;
    i=InitList(&L);
    printf("��ʼ��L��ListLeng��L��=%d\n",ListLength(L));
    printf("\n1.�鿴����\n2.��������β�巨��\n3.������\n4.�м���ֵ\n0.�˳�\n��ѡ����Ĳ�����\n");
    while(opp!='0')
    {
        scanf("%c",&opp);
        switch(opp)
        {
        case'1':
            ListTraverse(L);
            printf("\n");
            break;
        case'2':
            CreateListTail(&L,20);
            printf("���崴��L��Ԫ�أ�β�巨����\n");
            ListTraverse(L);
            printf("\n");
            break;
        case'3':
            printf("ListLength(L)=%d\n",ListLength(L));
            printf("\n");
            break;
        case'4':
            GetMidNode(L,&e);
            printf("�����м����ֵΪ��%d\n",e);
            printf("\n");
            break;
        case'0':
            exit(0);
        }
    }
}
