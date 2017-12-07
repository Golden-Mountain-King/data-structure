#pragma once


#define	MaxSize1 100
typedef int ElemType;
typedef struct
{
	ElemType data[MaxSize1];
	int front, rear;		//���׺Ͷ�βָ��
} SqQueue;
//���в���
void InitQueue(SqQueue *&q);
void DestroyQueue(SqQueue *&q);
bool QueueEmpty(SqQueue *q);
bool enQueue(SqQueue *&q, ElemType e);
bool deQueue(SqQueue *&q, ElemType &e);
