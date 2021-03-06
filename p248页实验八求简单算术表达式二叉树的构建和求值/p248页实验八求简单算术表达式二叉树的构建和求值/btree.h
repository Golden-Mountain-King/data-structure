#pragma once
#define MaxSize0 100
typedef int ElemType;
typedef struct node {
	ElemType data0;
	struct node *lchild;
	struct node *rchild;
}BTNode;
void CreateBTree(BTNode *&b, char *str);
void DispBTree(BTNode *b);
void DestroyBTree(BTNode *&b);
int SumTree(BTNode *b);