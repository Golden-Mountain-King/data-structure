#pragma once
#include"graph.h"
#include<malloc.h>
typedef int ElemType1;
#define MaxSize2 100
typedef struct {
	ElemType1 data[MaxSize2];
	int top;
}SqStack;

//��ʼ��ջ
void InitStack(SqStack *&s);

//����ջ
void DestroyStack(SqStack *&s);

//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(SqStack *s);

//��ջ
bool Push(SqStack *&s, ElemType1 e);

//	��ջ
bool Pop(SqStack *&s, ElemType1 &e);

//ȡջ��Ԫ��
bool GetTop(SqStack *s, ElemType1 &e);