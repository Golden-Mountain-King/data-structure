#include<stdio.h>
#pragma once
#include<malloc.h>

#define MaxCol 10
#define ElemType int
typedef struct Node1 {
	ElemType data[MaxCol];
	struct Node1 *next;
}DList;

typedef struct Node2 {
	int Row, Col;
	DList *next;
}HList;

void CreatTable(HList *&h) {//���û���ʽ��ʽ������������㷨
	int i, j;
	DList *r, *s;
	h = (HList *)malloc(sizeof(HList));
	printf("���������������");
	scanf("%d%d", &h->Row, &h->Col);
	for (i = 0; i < h->Row; i++) {
		printf("��%d�У�", i + 1);
		s = (DList *)malloc(sizeof(DList));
		for (j = 0; j < h->Col; j++) {
			scanf("%d", &s->data[j]);
		}
		if (h->next == NULL) {
			h->next = s;
		}
		else {
			r->next = s;
		}
		r = s;
	}
	r->next = NULL;
}

void DestoryTable(HList *&h) {//���ٵ�������㷨
	DList *pre = h->next, *p = pre->next;
	while (p != NULL) {
		free(pre);
		pre = p;
		p = p->next;
	}
}

void DispTable(HList *h) {//�����������㷨
	int j;
	DList *p=h->next;
	while (p!=NULL)
	{
		for (j = 0; j < h->Col; j++) {
			printf("%4d", p->data[j]);
		}
		printf("\n");
		p = p->next;
	}
}

void 