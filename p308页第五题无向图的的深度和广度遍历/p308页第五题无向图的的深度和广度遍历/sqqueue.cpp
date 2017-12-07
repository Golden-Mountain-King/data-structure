#include"sqqueue.h"
#include<malloc.h>
void InitQueue(SqQueue *&q)
{
	q = (SqQueue *)malloc(sizeof(SqQueue));
	q->front = q->rear = 0;
}
void DestroyQueue(SqQueue *&q)
{
	free(q);
}
bool QueueEmpty(SqQueue *q)
{
	return(q->front == q->rear);
}
bool enQueue(SqQueue *&q, ElemType e)
{
	if ((q->rear + 1) % MaxSize1 == q->front)	//���������
		return false;
	q->rear = (q->rear + 1) % MaxSize1;
	q->data[q->rear] = e;
	return true;
}
bool deQueue(SqQueue *&q, ElemType &e)
{
	if (q->front == q->rear)				//�ӿ������
		return false;
	q->front = (q->front + 1) % MaxSize1;
	e = q->data[q->front];
	return true;
}
