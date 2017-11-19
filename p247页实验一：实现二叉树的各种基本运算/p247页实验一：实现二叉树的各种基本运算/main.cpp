/*
*ʵ��һ��ʵ�ֶ������ĸ��ֻ�������
*Ŀ�ģ����������洢�ṹ�����ն������Ļ��������㷨���
*���ݣ���дһ������btree.cpp��ʵ�ֶ������еĻ������㣬���ڴ˻��������һ������exp7-1.cpp������¹��ܡ�
*��1����ͼ��ʾ�Ķ�����������Ӧ�Ķ������洢�ṹb���ö����������ű�ʾ��Ϊ"A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))"��
*(2)���������b��
*(3)���"H"�������Һ��ӽ��ֵ��
*(4)���������b�ĸ߶�
*(5)�ͷŶ�����b��
*/


#include<stdio.h>
#include<stdlib.h>
#include"btree.h"
int main() {
	char str[] = { "A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))" };
	BTNode *s, *s0;
	printf("�������Ϊ��");
	CreateBTreee(s, str);
	DispBTree(s);
	s0 = FindNode(s, 'H');
	printf("\nH��������Ϊ��%c", LchildNode(s0)->data);
	printf("\nH�����Һ���Ϊ��%c", RchildNode(s0)->data);
	printf("\n���ĸ߶�Ϊ��%d", BTHeight(s));
	printf("\n������\n"); DestroyBTree(s);
	system("pause");
	return 0;
}