/*
*ʵ��8���󼯺ϣ��õ������ʾ���Ĳ������Ͳ�����
*Ŀ�ģ����յ������Ӧ�ú���������Ķ�·�鲢�㷨��ơ�
*���ݣ���дһ������exp2-8.cpp�����õ������ʾ���ϣ�����ͬһ�������в������ظ���Ԫ�أ������䰴�����ķ�ʽ���򣬹����������������������������ϵĲ������Ͳ�
*/

#include<stdio.h>
#include<stdlib.h>
#include"linklist.h"

void main(){
	printf("����������L1��L2,L3,L4,L5\n");//L3�ǲ�����L4�ǲ��L5�ǽ���
	LinkNode *L1,*L2,*L3,*L4,*L5;
	printf("�����������ϣ�ElemType a[],ElemType b[]\n");
	ElemType a[]={1,3,4,5,7,8};
	ElemType b[]={1,2,5,6,8};
	printf("��ʼ��������L1,L2������a��b��Ԫ��\n");
	CreateListR(L1, a,6);
	CreateListR(L2, b,5);
	DispList(L1);DispList(L2);
	printf("���ö�·�鲢��");
	UnionList1(L1,L2,L3);
	printf("����ϲ���ı�");
	DispList(L3);
	printf("���ö�·�鲢���");
	UnionList2(L1, L2, L4);
	printf("�������ı�");
	DispList(L4);
	printf("���ö�·�鲢��");
	UnionList3(L1, L2, L5);
	printf("����󽻺�ı�");
	DispList(L5);
	printf("�ͷŵ�����L1,L2,L3,L4,L5\n");
	DestroyList(L1);DestroyList(L2);DestroyList(L3);DestroyList(L4);DestroyList(L5);
	system("pause");
}