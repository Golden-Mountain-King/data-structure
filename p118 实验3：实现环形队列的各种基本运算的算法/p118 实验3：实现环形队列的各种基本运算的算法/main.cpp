#include<stdio.h>
#include"sqqueue.h"
#include<stdlib.h>

int main() {
	char e;
	char a[10];
	printf("��ʼ������q\n");
	SqQueue *q;
	InitQueue(q);
	printf("�ж�ջ�Ƿ�Ϊ�գ�%s\n", QueueEmpty(q)? "��":"�ǿ�");
	printf("���ν���Ԫ��a,b,c\n");
	enQuene(q, 'a');
	enQuene(q, 'b');
	enQuene(q, 'c');
	deQuene(q, e);
	printf("����һ��Ԫ�أ�����������Ԫ����:%c\n",e);
	printf("���ν���Ԫ��d,e,f\n");
	enQuene(q, 'd');
	enQuene(q, 'e');
	enQuene(q, 'f');
	printf("��������е�ֵ��");
	DispList(q);
	printf("\n�ͷŶ���q\n");
	DestoryQueue(q);

	system("pause");
	return 0;
}