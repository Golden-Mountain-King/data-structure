#include <stdio.h>
#include <malloc.h>
#include "btree.h"

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


//--------------------------------------------------------
//--ѭ�����л��������㷨----------------------------------
//--------------------------------------------------------

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
//--------------------------------------------------------

bool LevelOrder(BTNode *b){
	int a = 0;
	BTNode *p;
	SqQueue *qu;
	InitQueue(qu);
	enQueue(qu, b);		
	int m = BTHeight(b);//�õ����ĸ߶�	
	int n = 1;//��һ��	
	int j = 1;	
	int k = 1;
	for(int i = 1;i<=m-2;i++){
		k=k*2;
	}
	while (!QueueEmpty(qu))	
	{
		while(n != m-1){//�������һ��
			deQueue(qu, p);//����һ�����
			if (p->lchild != NULL) {//���������
				enQueue(qu, p->lchild);
			}
			if (p->rchild != NULL) {//������Һ���
				enQueue(qu, p->rchild);
			}
			if(n = m-1){
				if(j == k ){
					break;
				}
				else{
					return false;
				}
			}
		}
		while(n == m){//���������
			int o = 0;
			deQueue(qu, p);//����һ�����
			printf("%c ", p->data);	//���ʽڵ�p
			if (p->lchild != NULL) {//���������
				o++;
				enQueue(qu, p->lchild);
			}
			if (p->rchild != NULL&&a != 1) {//������Һ��Ӳ���û������
				printf("����ȫ������\n");
				break;
			}
			else{//�����Ӳ������Һ���
				o--;
				enQueue(qu, p->rchild);
			}
		}
	}
	return true;
}
/**
 * 
 * ��ȫ������(Complete Binary Tree)�� 
 * ����������ĸ߶�Ϊh������ h ���⣬�������� (1��h-1) �Ľ�������ﵽ��������
 * �� h �����еĽڵ㶼��������������ߣ��������ȫ��������
 * �жϺܼ򵥣������������������������
 * һ����һ���������ӽڵ����ֻ����һ�����ӽڵ�֮��
 * ��ô���������нڵ㶼������Ҷ�ӽڵ㡣���򣬸����Ͳ�����ȫ��������
 * 
 * 
 * /
deQueue(qu, p);	//���ӽڵ�p
			printf("%c ", p->data);	//���ʽڵ�p
			if (p->lchild != NULL) {//���������
				a++;
				enQueue(qu, p->lchild);
			}
			if (p->rchild != NULL&&a != 1) {//������Һ��Ӳ���û������
				printf("����ȫ������\n");
				break;
			}
			else{//�����Ӳ������Һ���
				a--;
				enQueue(qu, p->rchild);
			}