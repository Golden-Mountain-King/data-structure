#include"hlist.h"
int main() {
	HList *h1, *h2, *h;
	printf("��1��\n");
	CreatTable(h1);
	printf("��2��\n");
	CreatTable(h2);
	LinkTable(h1, h2, h);
	printf("���ӵĽ����Ϊ��\n");
	DispTable(h);
	DestoryTable(h1);
	DestoryTable(h2);
	DestoryTable(h);
	return 1;
}