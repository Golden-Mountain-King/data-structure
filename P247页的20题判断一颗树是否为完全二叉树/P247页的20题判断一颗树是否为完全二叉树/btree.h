#pragma once
#define MaxSize 100
#define MaxSize 100
typedef char ElemType;
typedef struct node
{
	ElemType data;			//����Ԫ��
	struct node *lchild;	//ָ�����ӽڵ�
	struct node *rchild;	//ָ���Һ��ӽڵ�
} BTNode;
typedef struct
{
	BTNode *data[MaxSize];				//��Ŷ���Ԫ��
	int front, rear;						//��ͷ�Ͷ�βָ��
} SqQueue;								//˳�������
void CreateBTree(BTNode * &b, char *str);

void DestroyBTree(BTNode *&b);
BTNode *FindNode(BTNode *b, ElemType x);
BTNode *LchildNode(BTNode *p);
BTNode *RchildNode(BTNode *p);
int BTHeight(BTNode *b);
void DispBTree(BTNode *b);
void InitQueue(SqQueue *&q);

void DestroyQueue(SqQueue *&q);
bool QueueEmpty(SqQueue *q);
bool enQueue(SqQueue *&q, BTNode *e);
bool deQueue(SqQueue *&q, BTNode *&e);
void LevelOrder(BTNode *b);