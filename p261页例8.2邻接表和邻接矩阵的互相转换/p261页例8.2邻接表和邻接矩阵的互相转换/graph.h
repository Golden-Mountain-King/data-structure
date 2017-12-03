#pragma once
typedef int InfoType;
//ͼ���ڽӾ���������������
#define MAXV 100
#define INF 32767//���������

typedef struct {
	int no;//����ı��
	InfoType info;//����������Ϣ
}VertexType;//���������
typedef struct {
	int edges[MAXV][MAXV];//�ڽӾ�������
	int n, e;//������������
	VertexType vexs[MAXV];//��Ŷ�����Ϣ
}MatGraph;

//ͼ���ڽӱ�������������
typedef struct ANode {
	int adjvex;//�ıߵ��ڽӵ���
	struct ANode *nextarc;//ָ����һ���ߵ�ָ��
	int weight;//�ıߵ������Ϣ����Ȩֵ�����������α�ʾ��
}ArcNode;//�߽�������
typedef struct Vnode {
	InfoType info;//�����������Ϣ
	ArcNode *firstarc;//ָ���һ���߽��
}VNode;//�ڽӱ�Ľ��ͷ�������
typedef struct {
	VNode adjlist[MAXV];//�ڽӱ��ͷ�������
	int n, e;//ͼ�еĶ�����n�ͱ���e
}AdjGraph;//������ͼ�ڽӱ�����

void MatToList(MatGraph g, AdjGraph *&G);//�ڽӾ���ת��Ϊ�ڽӱ�
void ListToMat(AdjGraph *G, MatGraph &g);//�ڽӱ�ת��Ϊ�ڽӾ���
//��

void DispMat(MatGraph g);//����ڽӾ���
void DispAdj(AdjGraph *G);//����ڽӱ�