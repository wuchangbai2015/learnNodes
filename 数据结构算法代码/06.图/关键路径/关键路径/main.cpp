#include <stdio.h>
#include <stdlib.h>
#define MAXVEX 100
#define ERROR 1
#define OK 0
typedef struct EdgeNode
{
    int adjvex;
    int weight;
    struct EdgeNode *next;
}EdgeNode;
typedef struct VextexNode
{
    int in;
    int data;
    EdgeNode *firstedge;
}VextexNode,AdjList[MAXVEX];
typedef struct
{
    AdjList adjlist;
    int numVertexes,numEdges;
}graphAdjList;
int *etv,*ltv;
int *stack2;//�洢�������е�ջ
int top2;//����stack2��ջ��ָ��
int LocateVex(graphAdjList G,char &v1)
{
    int i;
    for(i=0;i<G.numVertexes;i++)
    {
        if(G.adjlist[i].data==v1)
            return i;
    }
    if(i>=G.numVertexes)
        return ERROR;
    else
        return 0;
}
graphAdjList CreateDG(graphAdjList G)
{
    EdgeNode *p,*q;
    char v1,v2;
    char v;
    int i,j,k,n,m,w;
    printf("������ͼ�Ķ������ͻ�����\n");
    scanf("%d %d",&G.numVertexes,&G.numEdges);
    printf("�����붥�㣺");
    getchar();
    for(i=0;i<G.numVertexes;i++)
    {
        scanf("%c",&v);   //���붥������
        getchar();
        G.adjlist[i].data=v;
        G.adjlist[i].firstedge=NULL;
    }
    printf("�����붥����ȣ�");
    for(i=0;i<G.numVertexes;i++)
    {
        scanf("%d",&m);
        getchar();
        G.adjlist[i].in=m;
    }
    printf("�����뻡β����ͷ��Ȩֵ��");
    for(k=0;k<G.numEdges;k++) //�����ߣ�������ͷ���
    {
        scanf("%c %c %d",&v1,&v2,&w);  //v1Ϊ��β
        getchar();  //v2Ϊ��ͷ
        i=LocateVex(G,v1);
        j=LocateVex(G,v2);
        if(G.adjlist[i].firstedge==NULL)  //�������Ϊ���½�һ����ڵ㣬��ͷ�ڵ��ָ��ָ��ñ�ڵ�
        {
            p=(EdgeNode *)new EdgeNode;
            G.adjlist[i].firstedge=p;
            q=G.adjlist[i].firstedge;
        }
        else
        {
            q=G.adjlist[i].firstedge;//��ȡͷ���ı�ͷָ��
            for(n=0;n<G.numEdges;n++,q=q->next)//��qָ���ƶ��������β�ʹ�
            {
                if(!q->next)
                    break;
            }
            p=(EdgeNode *)new EdgeNode;
            q->next=p; //���ñߣ��������뵽������
            q=q->next;
        }
        q->adjvex=j;
        q->weight=w;
        q->next=NULL;
    }
    printf("ͼ�����ɹ���\n");
    return G;
}
int TopologicalSort(graphAdjList G)
{
    EdgeNode *e;
    int i,k,gettop;
    int top=0;
    int count=0;
    int *stack;
    stack=(int *)malloc(G.numVertexes*sizeof(int));
    for(i=0;i<G.numVertexes;i++)
    {
        if(0==G.adjlist[i].in)
        {
            stack[++top]=i;
        }
    }
    top2=0;
    etv=(int *)malloc(G.numVertexes*sizeof(int));
    for(i=0;i<G.numVertexes;i++)
    {
        etv[i]=0;
    }
    stack2=(int*)malloc(G.numVertexes*sizeof(int));
    while(top!=0)
    {
        gettop=stack[top--];
        stack2[++top2]=gettop;
        count++;
        for(e=G.adjlist[gettop].firstedge;e;e=e->next)
        {
            k=e->adjvex;
            if(!(--G.adjlist[k].in))
            {
                stack[++top]=k;
            }
            if((etv[gettop]+e->weight)>etv[k])
            {
                etv[k]=etv[gettop]+e->weight;
            }
        }
    }
    if(count<G.numVertexes)
    {
        return ERROR;
    }
    else
    {
        return OK;
    }
}
void CriticalPath(graphAdjList G)
{
    EdgeNode *e;
    int i,gettop,k,j;
    int ete,lte;
    TopologicalSort(G);
    ltv=(int *)malloc(G.numVertexes*sizeof(int));
    for(i=0;i<G.numVertexes;i++)
    {
        ltv[i]=etv[G.numVertexes-1];
    }
    while(0!=top2)
    {
        gettop=stack2[top2--];
        for(e=G.adjlist[gettop].firstedge;e;e=e->next)
        {
            k=e->adjvex;
            if((ltv[k]-e->weight)<ltv[gettop])
            {
                ltv[gettop]=ltv[k]-e->weight;
            }
        }
    }
    for(j=0;j<G.numVertexes;j++)
    {
        for(e=G.adjlist[j].firstedge;e;e=e->next)
        {
            k=e->adjvex;
            ete=etv[j];
            lte=ltv[k]-e->weight;
            if(ete==lte)
            {
                printf("<%c,%c> length:%d,",G.adjlist[j].data,G.adjlist[k].data,e->weight);
            }
        }
    }
}
int main()
{
    graphAdjList G;
    CriticalPath(CreateDG(G));
    return 0;
}
