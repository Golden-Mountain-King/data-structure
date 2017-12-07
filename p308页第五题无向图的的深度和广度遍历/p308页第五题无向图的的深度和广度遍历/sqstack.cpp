#include"sqstack.h"

//��ʼ��ջ
void InitStack(SqStack *&s) {
	s = (SqStack *)malloc(sizeof(SqStack));
	s->top = -1;
}

//����ջ
void DestroyStack(SqStack *&s) {
	free(s);
}

//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(SqStack *s) {
	return(s->top == -1);
}

//��ջ
bool Push(SqStack *&s, ElemType1 e) {
	if (s->top == MaxSize2 - 1) {
		return false;
	}
	s->top++;
	s->data[s->top] = e;
	return true;
}

//	��ջ
bool Pop(SqStack *&s, ElemType1 &e) {
	if (s->top == -1) {
		return false;
	}
	e = s->data[s->top];
	s->top--;
	return true;
}

//ȡջ��Ԫ��
bool GetTop(SqStack *s, ElemType1 &e) {
	if (s->top == -1) {
		return false;
	}
	e = s->data[s->top];
	return true;
}
