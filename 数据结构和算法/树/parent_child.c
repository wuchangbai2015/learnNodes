#define MAX_TREE_SIZE 100
typedef char ElemType;


//���ӽ��
typedef struct CTNode
{
    int child;//���ӽ����±�
    struct CTNode *next; //ָ����һ�����ӽ���ָ��
}*ChilePtr;

//��ͷ�ṹ
typedef struct
{
    ElemType data;
    int parent;
    ChildPtr firstchild;
}CTBox;

//���ṹ
typedef struct
{
    CTBox nodes[MAX_TREE_SIZE];//�������
	int r,n;
}
