#include<stdio.h>
#include<stdlib.h>
#include"linklist.h"

void main() {
	LinkNode *h;
	ElemType e;
	printf("������Ļ����������£�\n");
	printf("(1)��ʼ��������h");
	InitList(h);
	printf("\n(2)���β���β�巨����a,b,c,d,eԪ��");
	ListInsert(h, 1, 'a');
	ListInsert(h, 2, 'b');
	ListInsert(h, 3, 'c');
	ListInsert(h, 4, 'd');
	ListInsert(h, 5, 'e');
	printf("\n(3)���������h��");
	DisList(h);
	printf("(4)���������h�ĳ���=%d", ListLength(h));
	printf("\n(5)�жϵ�����h�Ƿ�Ϊ��%s", (ListEmpty(h)?"��":"�ǿ�"));
	printf("\n(6)���������h�ĵ�����Ԫ�أ�");
	GetElem(h, 3, e);
	printf("%c", e);
	printf("\n(7)���Ԫ��a��λ��=%d", LocateElem(h, 'a'));
	printf("\n(8)�ڵ��ĸ�λ�ò���fԪ��");
	ListInsert(h, 4, 'f');
	printf("\n(9)���������h��");
	DisList(h);
	printf("(10)ɾ��������h�ĵ�����Ԫ�أ�");
	ListDelete(h, 3, e);
	printf("\n(10)���������h��");
	DisList(h);
	printf("(11)�ͷŵ�����h��\n");
	DestoryList(h);
	system("pause");
}