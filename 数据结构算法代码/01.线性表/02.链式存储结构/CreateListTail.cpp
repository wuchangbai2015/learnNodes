void CreateListHead(LinkList *L,int n)
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
