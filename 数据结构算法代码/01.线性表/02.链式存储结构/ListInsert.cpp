Status ListInsert(LinkList L,int i,ElemType *e)
{
    int j;
    LinkList p,a;
    p=L;
    j=1;
    while(p && j<i)//Ѱ�ҵ�i���ڵ�
    {
        p=p->next;
        j++;
    }
    if(!p ||j>i)
    {
        return ERROR;
    }
    s=(LinkList)malloc(sizeof(Node));
    s->data=e;
    s->next=p->next;
    p->next=s;
    return OK;
}
