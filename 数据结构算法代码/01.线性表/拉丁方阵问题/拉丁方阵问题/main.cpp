#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}sqlist,*linklist;
linklist CreateLinkList(int n)
{
    linklist head=NULL;
    linklist s,r;
    int i;
    r=head;
    for(i=1;i<=n;i++)
    {
        s=(linklist)malloc(sizeof(sqlist));
        s->data=i;
        if(head==NULL)
            head=s;
        else
            r->next=s;
        r=s;
    }
    r->next=head;
    return head;
}
int main()
{
    linklist p;
    int i,j,n;
    printf("��������������Ľ�����С�ڵ���9����");
    scanf("%d",&n);
    p=CreateLinkList(n);
    printf("�����������£�\n");
    for (i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d  ",p->data);
            p=p->next;
        }
        p=p->next;
        printf("\n\n");
    }
    return 0;
}
