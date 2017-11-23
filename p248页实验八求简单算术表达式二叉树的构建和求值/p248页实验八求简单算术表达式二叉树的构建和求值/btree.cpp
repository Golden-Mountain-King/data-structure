#pragma once
#include<stdio.h>
#include<malloc.h>
#include"btree.h"
#include"sqstack.h"


void CreateBTreee(BTNode *&b, char *str) {
	BTNode *St[MaxSize0], *p = NULL;
	int top = -1, k, j = 0;
	char ch;
	b = NULL;
	ch = str[j];
	while (ch != '\0') {
		switch (ch) {
		case '(':top++; St[top] = p; k = 1; break;
		case ')':top--; break;
		case ',':k = 2; break;
		default:
			p = (BTNode *)malloc(sizeof(BTNode));
			p->data0 = (int)ch;
			p->lchild = p->rchild = NULL;
			if (b == NULL) {
				b = p;
			}
			else {
				switch (k) {
				case 1:St[top]->lchild = p; break;
				case 2:St[top]->rchild = p; break;
				}
			}
		}
		j++;
		ch = str[j];
	}
}

void DispBTree(BTNode *b) {
	if (b != NULL) {
		printf("%c", b->data0);
		if (b->lchild != NULL || b->rchild != NULL) {
			printf("(");
			DispBTree(b->lchild);
			if (b->rchild != NULL) {
				printf(",");
			}
			DispBTree(b->rchild);
			printf(")");
		}
	}
}

BTNode *LchildNode(BTNode *p) {//�������ӽ��
	return p->lchild;
}

BTNode *RchildNode(BTNode *p) {//�����Һ��ӽ��
	return p->rchild;
}

BTNode *FindNode(BTNode *b, ElemType x) {//���ҽ��
	BTNode *p;
	if (b == NULL) {
		return NULL;
	}
	else if (b->data0 == x) {
		return b;
	}
	else {
		p = FindNode(b->lchild, x);
		if (p != NULL) {
			return p;
		}
		else {
			return FindNode(b->rchild, x);
		}
	}
}

int BTHeight(BTNode *b) {//�����ĸ߶�
	int lchild, rchild;
	if (b == NULL) {
		return (0);
	}
	else {
		lchild = BTHeight(b->lchild);
		rchild = BTHeight(b->rchild);
		return (lchild > rchild) ? (lchild + 1) : (rchild + 1);
	}
}

void DestroyBTree(BTNode *&b) {
	if (b != NULL) {
		DestroyBTree(b->lchild);
		DestroyBTree(b->rchild);
		free(b);
	}
}

int SumTree(BTNode *b)
{//��ֵ�㷨
	int c = 0;
	SqStack *s;
	InitStack(s);
	BTNode *p, *p0, *p1, *p2, *p3;
	p = b;
	p0 = (BTNode *)malloc(sizeof(BTNode));
	if (b != NULL) {
		Push(s, p);
		GetTop(s,p0);
		//�ж�ջ���Ľ���Ƿ������ӣ��еĻ��ݹ����
		if (p0!= NULL)
		{
			c += SumTree(p0->lchild);
		} 
		//ת���Һ��ӣ��ݹ����
		if (p0 != NULL)
		{
			c += SumTree(p0->rchild);
		}
		
		//��ջ����ֵ��һ������������Ҽ������ǵ�ֵ
		Pop(s, p1); int a = (int)p1->data0;
		Pop(s, p2); int b = (int)p2->data0;
		Pop(s, p3); char ch = p3->data0;
		switch (ch)
		{
		case '+':c = a + b; break;
		case '-':c = a + b; break;
		case '*':c = a + b; break;
		case '/':c = a + b; break;
		}
		return c;
	}
}