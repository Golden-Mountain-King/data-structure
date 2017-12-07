//#include"graph.h"
#include"sqqueue.h"
#include"sqstack.h"
#include<stdio.h>

void CreateAdj(AdjGraph *&G,int A[MAXV][MAXV],int n,int e) //����ͼ���ڽӱ�
{
	int i,j;
	ArcNode *p;
	G=(AdjGraph *)malloc(sizeof(AdjGraph));
	for (i=0;i<n;i++)								//���ڽӱ�������ͷ����ָ�����ó�ֵ
		G->adjlist[i].firstarc=NULL;
	for (i=0;i<n;i++)								//����ڽӾ�����ÿ��Ԫ��
		for (j=n-1;j>=0;j--)
			if (A[i][j]!=0 && A[i][j]!=INF)			//����һ����
			{	p=(ArcNode *)malloc(sizeof(ArcNode));	//����һ�����p
				p->adjvex=j;
				p->weight=A[i][j];
				p->nextarc=G->adjlist[i].firstarc;	//����ͷ�巨������p
				G->adjlist[i].firstarc=p;
			}
	G->n=n; G->e=n;
}
void DispAdj(AdjGraph *G)	//����ڽӱ�G
{
	int i;
	ArcNode *p;
	for (i=0;i<G->n;i++)
	{
		p=G->adjlist[i].firstarc;
		printf("%3d: ",i);
		while (p!=NULL)
		{
			printf("%3d[%d]��",p->adjvex,p->weight);
			p=p->nextarc;
		}
		printf("��\n");
	}
}
void DestroyAdj(AdjGraph *&G)		//����ͼ���ڽӱ�
{	int i;
	ArcNode *pre,*p;
	for (i=0;i<G->n;i++)			//ɨ�����еĵ�����
	{	pre=G->adjlist[i].firstarc;	//pָ���i����������׽��
		if (pre!=NULL)
		{	p=pre->nextarc;
			while (p!=NULL)			//�ͷŵ�i������������б߽��
			{	free(pre);
				pre=p; p=p->nextarc;
			}
			free(pre);
		}
	}
	free(G);						//�ͷ�ͷ�������
}





int visited[MAXV] = {0};
void DFS(AdjGraph *G,int v){//ͼ��������ȱ������ݹ��㷨��
	ArcNode *p;
	visited[v] = 1;
	printf("%d",v);
	p = G->adjlist[v].firstarc;
	while(p!=NULL){
		if(visited[p->adjvex] == 0){
			DFS(G,p->adjvex);
		}
		p = p->nextarc;
	}
}

void DFS1(AdjGraph *G,int v){//ͼ��������ȱ������ǵݹ��㷨
	int w;
	ArcNode *p;
	SqStack *s;
	InitStack(s);
	int visited2[MAXV];
	for (int i = 0; i < G->n; i++) {
		visited2[i] = 0;
	}
	Push(s, v);
	while (!StackEmpty(s)) {
		Pop(s, w);
		p = G->adjlist[w].firstarc;
		while (p!=NULL){
			if (visited2[w] == 0) {//�������0�Ͳ���ջ
				Push(s, p->adjvex);
			}
			p = p->nextarc;
		}
		if (visited2[w] == 0) {
			printf("%d", w);
			visited2[w] = 1;
		}
	}
}

void BFS(AdjGraph *G,int v){//ͼ�Ĺ�����ȱ���
	int w,i;
	ArcNode *p;
	SqQueue *qu;
	InitQueue(qu);
	int visited1[MAXV];
	for(i = 0;i<G->n;i++){
		visited1[i] = 0;
	}
	printf("%d",v);
	visited1[v] = 1;
	enQueue(qu,v);
	while(!QueueEmpty(qu)){
		deQueue(qu,w);
		p = G->adjlist[w].firstarc;
		while(p!=NULL){
			if(visited1[p->adjvex]==0){
				printf("%d",p->adjvex);
				visited1[p->adjvex] = 1;
				enQueue(qu,p->adjvex);
			}
			p = p->nextarc;
		}
	}
	printf("\n");
}