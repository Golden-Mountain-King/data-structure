#include<stdio.h>
#include<stdlib.h>
#include <malloc.h>
#define MaxSize 100
typedef char ElemType;
typedef struct node {
	ElemType data;			//����Ԫ��
	struct node *lchild;	//ָ�����ӽڵ�
	struct node *rchild;	//ָ���Һ��ӽڵ�
} BTNode;
void CreateBTree(BTNode * &b, char *str)	//����������
{
	BTNode *St[MaxSize], *p = NULL;
	int top = -1, k, j = 0;
	char ch;
	b = NULL;				//�����Ķ�������ʼʱΪ��
	ch = str[j];
	while (ch != '\0')  	//strδɨ����ʱѭ��
	{
		switch (ch)
		{
		case '(':top++; St[top] = p; k = 1; break;		//Ϊ���ӽڵ�
		case ')':top--; break;
		case ',':k = 2; break;                      		//Ϊ���ӽڵ��ҽڵ�
		default:p = (BTNode *)malloc(sizeof(BTNode));
			p->data = ch; p->lchild = p->rchild = NULL;
			if (b == NULL)                    	 	//*pΪ�������ĸ��ڵ�
				b = p;
			else  								//�ѽ������������ڵ�
			{
				switch (k)
				{
				case 1:St[top]->lchild = p; break;
				case 2:St[top]->rchild = p; break;
				}
			}
		}
		j++;
		ch = str[j];
	}
}
void DestroyBTree(BTNode *&b)
{
	if (b != NULL)
	{
		DestroyBTree(b->lchild);
		DestroyBTree(b->rchild);
		free(b);
	}
}
BTNode *FindNode(BTNode *b, ElemType x)
{
	BTNode *p;
	if (b == NULL)
		return NULL;
	else if (b->data == x)
		return b;
	else
	{
		p = FindNode(b->lchild, x);
		if (p != NULL)
			return p;
		else
			return FindNode(b->rchild, x);
	}
}
BTNode *LchildNode(BTNode *p)
{
	return p->lchild;
}
BTNode *RchildNode(BTNode *p)
{
	return p->rchild;
}
int BTHeight(BTNode *b)
{
	int lchildh, rchildh;
	if (b == NULL) return(0); 				//�����ĸ߶�Ϊ0
	else
	{
		lchildh = BTHeight(b->lchild);	//���������ĸ߶�Ϊlchildh
		rchildh = BTHeight(b->rchild);	//���������ĸ߶�Ϊrchildh
		return (lchildh>rchildh) ? (lchildh + 1) : (rchildh + 1);
	}
}
void DispBTree(BTNode *b)
{
	if (b != NULL)
	{
		printf("%c", b->data);
		if (b->lchild != NULL || b->rchild != NULL)
		{
			printf("(");						//�к��ӽڵ�ʱ�����(
			DispBTree(b->lchild);				//�ݹ鴦��������
			if (b->rchild != NULL) printf(",");	//���Һ��ӽڵ�ʱ�����,
			DispBTree(b->rchild);				//�ݹ鴦��������
			printf(")");						//�к��ӽڵ�ʱ�����)
		}
	}
}

typedef struct
{
	BTNode *data[MaxSize];			//���ջ�е�����Ԫ��
	int top;						//���ջ��ָ�룬��ջ��Ԫ����data�����е��±�
} SqStack;							//˳��ջ����

void InitStack(SqStack *&s)			//��ʼ��ջ
{
	s = (SqStack *)malloc(sizeof(SqStack));//����һ����˳��ջ�ռ䣬�׵�ַ�����s��
	s->top = -1;						//ջ��ָ����Ϊ-1
}
void DestroyStack(SqStack *&s)		//����ջ
{
	free(s);
}
bool StackEmpty(SqStack *s)			//�ж�ջ�Ƿ�Ϊ��
{
	return(s->top == -1);
}
bool Push(SqStack *&s, BTNode *e)	//��ջ
{
	if (s->top == MaxSize - 1)			//ջ�����������ջ�����
		return false;
	s->top++;						//ջ��ָ����1
	s->data[s->top] = e;				//Ԫ��e����ջ��ָ�봦
	return true;
}
bool Pop(SqStack *&s, BTNode *&e)	//��ջ
{
	if (s->top == -1)					//ջΪ�յ��������ջ�����
		return false;
	e = s->data[s->top];				//ȡջ��ָ��Ԫ�ص�Ԫ��
	s->top--;						//ջ��ָ���1
	return true;
}
bool GetTop(SqStack *s, BTNode *&e)	//ȡջ��Ԫ��
{
	if (s->top == -1)					//ջΪ�յ��������ջ�����
		return false;
	e = s->data[s->top];				//ȡջ��Ԫ��
	return true;
}

void PreOrder1(BTNode *b)			//����ǵݹ�����㷨1
{
	BTNode *p;
	SqStack *st;					//����һ��˳��ջָ��st
	InitStack(st);					//��ʼ��ջst
	Push(st, b);					//���ڵ��ջ
	while (!StackEmpty(st))		//ջ��Ϊ��ʱѭ��
	{
		Pop(st, p);				//��ջ�ڵ�p��������
		printf("%c ", p->data);	//���ʽڵ�p
		if (p->rchild != NULL)	//���Һ���ʱ�����ջ
			Push(st, p->rchild);
		if (p->lchild != NULL)	//������ʱ�����ջ
			Push(st, p->lchild);
	}
	printf("\n");
	DestroyStack(st);				//����ջ
}

void InOrder1(BTNode *b)				//����ǵݹ�����㷨
{
	BTNode *p;
	SqStack *st;						//����һ��˳��ջָ��st
	InitStack(st);						//��ʼ��ջst
	if (b != NULL)
	{
		p = b;
		while (!StackEmpty(st) || p != NULL)
		{
			while (p != NULL)				//ɨ��ڵ�p���������½ڵ㲢��ջ
			{
				Push(st, p);				//�ڵ�p��ջ
				p = p->lchild;			//�ƶ�������
			}
			if (!StackEmpty(st))		//��ջ����
			{
				Pop(st, p);				//��ջ�ڵ�p
				printf("%c ", p->data);	//���ʽڵ�p
				p = p->rchild;			//ת������������
			}
		}
		printf("\n");
	}
	DestroyStack(st);				//����ջ
}

void PostOrder1(BTNode *b)				//����ǵݹ�����㷨
{
	BTNode *p, *r;
	bool flag;
	SqStack *st;						//����һ��˳��ջָ��st
	InitStack(st);						//��ʼ��ջst
	p = b;
	do
	{
		while (p != NULL)					//ɨ��ڵ�p���������½ڵ㲢��ջ
		{
			Push(st, p);					//�ڵ�p��ջ
			p = p->lchild;				//�ƶ�������
		}
		r = NULL;							//rָ��ոշ��ʵĽڵ㣬��ʼʱΪ��
		flag = true;						//flagΪ���ʾ���ڴ���ջ���ڵ�
		while (!StackEmpty(st) && flag)
		{
			GetTop(st, p);				//ȡ����ǰ��ջ���ڵ�p
			if (p->rchild == r)			//���ڵ�p���Һ���Ϊ�ջ���Ϊ�ոշ��ʹ��Ľڵ�	
			{
				printf("%c ", p->data);	//���ʽڵ�p
				Pop(st, p);
				r = p;					//rָ��շ��ʹ��Ľڵ�
			}
			else
			{
				p = p->rchild;			//ת������������
				flag = false;				//��ʾ��ǰ���Ǵ���ջ���ڵ�
			}
		}
	} while (!StackEmpty(st));			//ջ����ѭ��
	printf("\n");
	DestroyStack(st);				//����ջ
}

void PreOrder(BTNode *b)  		//��������ĵݹ��㷨
{
	if (b != NULL)
	{
		printf("%c ", b->data);	//���ʸ����
		PreOrder(b->lchild);	//�������������
		PreOrder(b->rchild);	//�������������
	}
}
void InOrder(BTNode *b)   		//��������ĵݹ��㷨
{
	if (b != NULL)
	{
		InOrder(b->lchild);		//�������������
		printf("%c ", b->data);	//���ʸ����
		InOrder(b->rchild);		//�������������
	}
}
void PostOrder(BTNode *b) 		//��������ĵݹ��㷨
{
	if (b != NULL)
	{
		PostOrder(b->lchild);	//�������������
		PostOrder(b->rchild);	//�������������
		printf("%c ", b->data);	//���ʸ����
	}
}


typedef struct
{
	BTNode *data[MaxSize];				//��Ŷ���Ԫ��
	int front, rear;						//��ͷ�Ͷ�βָ��
} SqQueue;								//˳�������
void InitQueue(SqQueue *&q)				//��ʼ������
{
	q = (SqQueue *)malloc(sizeof(SqQueue));
	q->front = q->rear = 0;
}
void DestroyQueue(SqQueue *&q)			//���ٶ���
{
	free(q);
}
bool QueueEmpty(SqQueue *q)				//�ж϶����Ƿ�Ϊ��
{
	return(q->front == q->rear);
}
bool enQueue(SqQueue *&q, BTNode *e)		//������
{
	if ((q->rear + 1) % MaxSize == q->front)	//���������
		return false;
	q->rear = (q->rear + 1) % MaxSize;
	q->data[q->rear] = e;
	return true;
}
bool deQueue(SqQueue *&q, BTNode *&e)	//������
{
	if (q->front == q->rear)				//�ӿ������
		return false;
	q->front = (q->front + 1) % MaxSize;
	e = q->data[q->front];
	return true;
}

void LevelOrder(BTNode *b)
{
	BTNode *p;
	SqQueue *qu;
	InitQueue(qu);					//��ʼ������
	enQueue(qu, b);					//�����ָ��������
	while (!QueueEmpty(qu))			//�Ӳ�Ϊ��ѭ��
	{
		deQueue(qu, p);				//���ӽڵ�p
		printf("%c ", p->data);		//���ʽڵ�p
		if (p->lchild != NULL)		//������ʱ�������
			enQueue(qu, p->lchild);
		if (p->rchild != NULL)		//���Һ���ʱ�������
			enQueue(qu, p->rchild);
	}
}
int main() {
	BTNode *t;
	char str[]= { "A(B(D,E(H(J,K(L,M(N))))),C(F,G(I)))" };
	CreateBTree(t, str);
	printf("��Ϊ:"); DispBTree(t);
	printf("\n�ݹ�\n");
	printf("�����������:"); PreOrder(t); printf("\n");
	printf("�����������:"); InOrder(t); printf("\n");
	printf("�����������:"); PostOrder(t); printf("\n");
	printf("�ǵݹ�\n");
	printf("�����������:"); PreOrder1(t);
	printf("�����������:"); InOrder1(t);
	printf("�����������:"); PostOrder1(t);
	printf("��εݹ�\n");
	printf("��α�������:"); LevelOrder(t); printf("\n");
	DestroyBTree(t);
	system("pause");
	return 0;
}