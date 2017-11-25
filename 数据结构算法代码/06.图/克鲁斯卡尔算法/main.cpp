#include <stdio.h>
#define MAXVEX 100
#define MAXEDGE 2000
#define INFINITY 65535
typedef struct
{
    int s;
    int e;
    int w;
}Edge;
typedef struct
{
	char vexs[MAXVEX];
	Edge edge[MAXEDGE];
	int numVertexes, numEdges;
} MGraph;
MGraph CreateMGraph(MGraph G)
{
	int i, j, k, m;
	printf("�����붥������\n");
	scanf("%d",&G.numVertexes);
	printf("�����������\n");
	scanf("%d",&G.numEdges);
	printf("�����붥�����ƣ�\n");
	for( i=0; i < G.numVertexes;i++ )
	{
		scanf("%c",&G.vexs[i]);
		getchar();
		printf("�����붥�����ƣ�\n");
	}
	for( k=0; k < G.numEdges; k++ )
	{
		printf("�밴Ȩֵ�ӵ͵��������%d��begin,end�Ͷ�Ӧ��Ȩweight:\n",k);
		scanf("%d %d %d",&i,&j,&m);
		G.edge[k].s = i;
		G.edge[k].e = j;
		G.edge[k].w = m;
	}
    return G;
}
int Find(int *parent,int f)
{
    while(parent[f]>0)
    {
        f=parent[f];
    }
    return f;
}
void MiniSpanTree_Kruskal(MGraph G)
{
    int i,n,m;
    int parent[MAXVEX];//����parent���������жϱ�����Ƿ��γɻ�·
    for(i=0;i<G.numVertexes;i++)//��ʼ��
    {
        parent[i]=0;
    }
    for(i=0;i<G.numEdges;i++)
    {
        n=Find(parent,G.edge[i].s);
        m=Find(parent,G.edge[i].e);
        if(n!=m)
        {
            parent[n]=m;
            printf("(%d,%d) %d ",G.edge[i].s,G.edge[i].e,G.edge[i].w);
        }
    }
}
int main()
{
    MGraph G;
    MiniSpanTree_Kruskal(CreateMGraph(G));
    return 0;
}

