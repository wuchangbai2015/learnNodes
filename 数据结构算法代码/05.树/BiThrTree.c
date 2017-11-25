#include<stdio.h>
#include<stdlib.h>
typedef char ElemType;
//�����洢��־λ��Linkʱ����ʾֻ�����Һ��ӵ�ָ�룬Threadʱ����ʾֻ��ǰ����̵�����
typedef enum{Link,Thread} PointerTag;
typedef struct BiThrNode
{
    char data;
    struct BiThrNode *lchild,*rchild;
    PointerTag ltag;
    PointerTag rtag;
}BiThrNode,*BiThrTree;
BiThrTree pre;
//����һ�Ŷ�������Լ����������ǰ������ķ�ʽ��������
void CreateBiThrTree(BiThrTree *T)
{
    char c;
    scanf("%c",&c);
    if(c==' ')
    {
        *T=NULL;
    }
    else
    {
        *T=(BiThrNode *)malloc(sizeof(BiThrNode));
        (*T)->data=c;
        (*T)->ltag=Link;
        (*T)->rtag=Link;
        CreateBiThrTree(&(*T)->lchild);
        CreateBiThrTree(&(*T)->rchild);
    }
}
void InThreading(BiThrTree T)//�������������
{
    if(T)
    {
        InThreading(T->lchild);
        if(!T->lchild)
        {
            T->ltag=Thread;
            T->lchild=pre;
        }
        if(!pre->rchild)
        {
            pre->rtag=Thread;
            pre->rchild=T;
        }
        pre=T;
        InThreading(T->rchild);
    }
}
void InOrderThreading(BiThrTree *p,BiThrTree T)
{
    *p=(BiThrNode *)malloc(sizeof(BiThrNode));
    (*p)->ltag=Link;
    (*p)->rtag=Thread;
    (*p)->rchild=*p;
    if(!T)
    {
        (*p)->lchild=*p;
    }
    else
    {
        (*p)->lchild=T;
        pre=*p;
        InThreading(T);
        pre->rchild=*p;
        pre->rtag=Thread;
        (*p)->rchild=pre;
    }
}
void visit(char c)
{
    printf("%c",c);
}
void InOrderTraverse(BiThrTree T)
{
    BiThrTree p;
    p=T->lchild;
    while(p!=T)
    {
        while(p->ltag==Link)
        {
            p=p->lchild;
        }
        visit(p->data);
        while(p->rtag==Thread && p->rchild!=T)
        {
            p=p->rchild;
            visit(p->data);
        }
        p=p->rchild;
    }
}
int main()
{
    BiThrTree p,T=NULL;
    CreateBiThrTree(&T);
    InOrderThreading(&p,T);
    printf("�������������Ϊ��");
    InOrderTraverse(p);
    printf("\n");
    return 0;
}
