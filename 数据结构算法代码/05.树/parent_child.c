#define MAX_TREE_SIZE 100
typedef char ElemType;
typedef struct CTNode//���ӽ��
{
    int child;
    struct CTNode *next;
}*ChilePtr;
typedef struct//��ͷ�ṹ
{
    ElemType data;
    int parent;
    ChildPtr firstchild;
}CTBox;
typedef struct
{
    CTBox nodes[MAX_TREE_SIZE];//�������
}
