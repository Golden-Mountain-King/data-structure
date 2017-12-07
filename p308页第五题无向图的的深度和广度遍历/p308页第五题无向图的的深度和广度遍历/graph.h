//ͼ�����ִ洢�ṹ
#define INF 32767				//�����
#define	MAXV 100	
#define	MaxSize 100//��󶥵����
typedef char InfoType;


typedef struct ANode
{	int adjvex;					//�ñߵ��ڽӵ���
	struct ANode *nextarc;		//ָ����һ���ߵ�ָ��
	int weight;					//�ñߵ������Ϣ����Ȩֵ�������ͱ�ʾ��
} ArcNode;						//�߽������
typedef struct Vnode
{	InfoType info;				//����������Ϣ
	int count;					//��Ŷ������,����������������
	ArcNode *firstarc;			//ָ���һ����
} VNode;						//�ڽӱ�ͷ�������
typedef struct 
{	VNode adjlist[MAXV];		//�ڽӱ�ͷ�������
	int n,e;					//ͼ�ж�����n�ͱ���e
} AdjGraph;						//������ͼ�ڽӱ�����







void CreateAdj(AdjGraph *&G,int A[MAXV][MAXV],int n,int e);//�����ڽӱ�

void DispAdj(AdjGraph *G);//����ڽӱ�

void DestroyAdj(AdjGraph *&G);//�����ڽӱ�

void DFS(AdjGraph *G,int v);//ͼ��������ȱ������ݹ��㷨��

void DFS1(AdjGraph *G,int v);//ͼ��������ȱ������ǵݹ��㷨��

void BFS(AdjGraph *G,int v);//ͼ�Ĺ�����ȱ���


