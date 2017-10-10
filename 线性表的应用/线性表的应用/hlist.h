#include<stdio.h>
#include<malloc.h>

#define MaxCol 10
#define ElemType int
typedef struct Node1 {//
	ElemType data[MaxCol];
	struct Node1 *next;
}DList;//�н������
typedef struct Node2 {//�������ͷ�������
	int Row, Col;//����������
	DList *next;
}HList;//ͷ�ڵ�����



void CreatTable(HList *&h) {//���û���ʽ��ʽ������������㷨
	int i, j;
	DList *r =nullptr, *s;
	h = (HList *)malloc(sizeof(HList));
	printf("���������������");
	scanf_s("%d%d", &h->Row, &h->Col);
	for (i = 0; i < h->Row; i++) {
		printf("��%d�У�", i + 1);
		s = (DList *)malloc(sizeof(DList));
		for (j = 0; j < h->Col; j++) {
			scanf_s("%d", &s->data[j]);
		}
		if (h->next == NULL) {//�����һ�����ݽ��
			h->next = s;
		}
		if (h->next != NULL){//�����������ݽ��
			r->next = s;
		}
		r = s;
	}
	r->next = NULL;//β�������Ϊ��
}

void DestoryTable(HList *&h) {//���ٵ�������㷨
	DList *pre = h->next, *p = pre->next;
	while (p != NULL) {
		free(pre);
		pre = p;
		p = p->next;
	}
	free(pre);
	free(h);
}

void DispTable(HList *h) {//�����������㷨
	int j;
	DList *p = h->next;
	while (p != NULL)
	{
		for (j = 0; j < h->Col; j++) {
			printf("%4d", p->data[j]);
		}
		printf("\n");
		p = p->next;//pָ����һ���н��
	}
}

void LinkTable(HList *h1, HList *h2, HList *&h) {//���ӱ���㷨
	int i, j, k;
	DList *p = h1->next, *q, *s, *r= nullptr;
	printf("�����ֶ��ǣ���1������ţ���2�������");
	scanf_s("%d%d", &i, &j);
	h = (HList *)malloc(sizeof(HList));
	h->Row = 0;//�������Ϊ0
	h->Col = h1->Col + h2->Col;//��1��2������
	h->next = NULL;
	while (p != NULL) {
		q = h2->next;
		while (q != NULL) {
			if (p->data[i - 1] == q->data[j - 1]) {
				s = (DList *)malloc(sizeof(DList));
				for (k = 0; k < h1->Col; k++) {
					s->data[k] = p->data[k];
				}
				for (k = 0; k < h2->Col; k++) {
					s->data[h1->Col + k] = q->data[k];
				}
				if (h->next == NULL) {//�����һ�����ݽ��
					h->next = s;
				}
				if (h->next != NULL) {//�����������ݽ��
					r->next = s;
				}
				r = s;
				h->Row++;
			}
			q = q->next;//��2����ƶ�һ�����
		}
		p = p->next;//��1����ƶ�һ�����
	}
	r->next = NULL;
}