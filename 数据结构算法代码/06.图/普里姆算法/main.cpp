#include <stdio.h>
#define MAXVEX 100			// ��󶥵���
#define INFINITY 65535		// ��65535�����������
typedef struct
{
	char vexs[MAXVEX];				// �����
	int arc[MAXVEX][MAXVEX];		// �ڽӾ���
	int numVertexes, numEdges;		// ͼ�е�ǰ�Ķ������ͱ���
} MGraph;
// ����������ͼ���ڽӾ���
MGraph CreateMGraph(MGraph G)
{
	int i, j, k, w;
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

	for( i=0; i < G.numVertexes; i++ )
	{
		for( j=0; j < G.numVertexes; j++ )
		{
			G.arc[i][j] = INFINITY;	// �ڽӾ����ʼ��

		}
	}

	for( k=0; k < G.numEdges; k++ )
	{
		printf("�������(Vi,Vj)�ϵ��±�i,�±�j�Ͷ�Ӧ��Ȩw:\n");// ��ֻ�����ӣ�����û�������Ҫ���и���
		scanf("%d",&i);
		scanf("%d",&j);
		scanf("%d",&w);
		G.arc[i][j] = w;
		G.arc[j][i] = G.arc[i][j];			// ��������ͼ���Գƾ���
	}
    return G;
}

void MiniSpanTree_Prim(MGraph G)
{
    int min,i,j,k;
    int adjvex[MAXVEX];//������ض����±�[0,0,1,0,0,0,1,0,1]
    int lowcost[MAXVEX];//������ض���Ȩֵ
    lowcost[0]=0;//vo��Ϊ��С�������ĸ���ʼ������ȨֵΪ0
    adjvex[0]=0;
    for(i=1;i<G.numVertexes;i++)//��ʼ��
    {
        lowcost[i]=G.arc[0][i];
        adjvex[i]=0;
    }
    for(i=1;i<G.numVertexes;i++)
    {
        min=INFINITY;//��ʼ����СȨֵ
        j=1;
        k=0;
        while(j<G.numVertexes)
        {
            if(lowcost[j]!=0 && lowcost[j]<min)
            {
                min=lowcost[j];
                k=j;
            }
            j++;
        }
        printf("(%d,%d)",adjvex[k],k);
        lowcost[k]=0;
        for(j=0;j<G.numVertexes;j++)
        {
            if(lowcost[j]!=0 && G.arc[k][j]<lowcost[j])
            {
                lowcost[j]=G.arc[k][j];
                adjvex[j]=k;
            }
        }
    }
}
int main()
{
    MGraph G;
    MiniSpanTree_Prim(CreateMGraph(G));
    return 0;
}

