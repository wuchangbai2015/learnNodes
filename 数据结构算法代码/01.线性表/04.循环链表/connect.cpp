LinkList Connect(LinkList A,LinkList B)
{
    LinkList p=A->next;//����A��ͷָ��
    A->next=B->next->next;
    free(B->next);
    B->next=p;
    return B;//����βָ��
}
