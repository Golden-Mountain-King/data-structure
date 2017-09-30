//��������������㷨
#include <stdio.h>
#include <malloc.h>
typedef int ElemType;
typedef struct LNode  
{
	ElemType data;
	struct LNode *next;		//ָ���̽��
} LinkNode;					//����������������

void CreateListR(LinkNode *&L,ElemType a[],int n)
//β�巨����������
{
	LinkNode *s,*r;
	L=(LinkNode *)malloc(sizeof(LinkNode));  	//����ͷ���
	L->next=NULL;
	r=L;					//rʼ��ָ���ն˽��,��ʼʱָ��ͷ���
	for (int i=0;i<n;i++)
	{	
		s=(LinkNode *)malloc(sizeof(LinkNode));//�����½��s
		s->data=a[i];
		r->next=s;			//�����s������r֮��
		r=s;
	}
	r->next=NULL;			//�ն˽��next����ΪNULL
}

void DestroyList(LinkNode *&L)
{
	LinkNode *pre=L,*p=pre->next;
	while (p!=NULL)
	{	free(pre);
		pre=p;
		p=pre->next;
	}
	free(pre);	//��ʱpΪNULL,preָ��β���,�ͷ���
}


void DispList(LinkNode *L)
{
	LinkNode *p=L->next;
	while (p!=NULL)
	{	printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}


//���õ������������ʱ�Ķ�·�鲢�㷨(�󲢼���
void UnionList1(LinkNode *LA,LinkNode *LB,LinkNode *&LC){
	LinkNode *pa=LA->next,*pb=LB->next,*r,*s;
	LC=(LinkNode *)malloc(sizeof(LinkNode));
	r=LC;
	while(pa!=NULL&&pb!=NULL){
		if (pa->data != pb->data) {
			if(pa->data<pb->data){
				s=(LinkNode *)malloc(sizeof(LinkNode));
				s->data=pa->data;
				r->next=s;r=s;
				pa=pa->next;
			}
			else if(pa->data>pb->data){
				s=(LinkNode *)malloc(sizeof(LinkNode));
				s->data=pb->data;
				r->next=s;r=s;
				pb=pb->next;
			}
		}
		else {
			s = (LinkNode *)malloc(sizeof(LinkNode));
			s->data = pa->data;
			r->next = s; r = s;
			pa = pa->next;
			pb = pb->next;
		}
	}
	while(pa!=NULL){
		if(pa->data!=r->data){
			s=(LinkNode *)malloc(sizeof(LinkNode));
			s->data=pa->data;
			r->next=s;r=s;
		}
		pa=pa->next;
	}
	while(pb!=NULL){
		if(pb->data!=r->data){
			s=(LinkNode *)malloc(sizeof(LinkNode));
			s->data=pb->data;
			r->next=s;r=s;
		}
		pb=pb->next;
	}
	r->next=NULL;
}

//���õ������������ʱ�Ķ�·�鲢�㷨(����
void UnionList2(LinkNode *LA,LinkNode *LB,LinkNode *&LD){
	LinkNode *pa=LA->next,*pb=LB->next,*r,*s;
	LD=(LinkNode *)malloc(sizeof(LinkNode));//�����ڴ�ռ�
	r=LD;//rָ��LDͷ��ַ
	while(pa->next!=NULL){//pa��û��ѭ����β��

		pb=LB->next;//pbָ��LB�ĵ�һ��Ԫ��

		while(pa->data!=pb->data){//��pa������pbʱ
			if(pb->next!=NULL){
				pb=pb->next;//pb���ϵ����ѭ����ֱ��pb��β��
			}
			else{//pa����pbʱ
				s=(LinkNode *)malloc(sizeof(LinkNode));//Ϊ��Ҫ�洢���ڴ�����ڴ�ռ�
				s->data=pa->data;//��s�д��pa��ֵ
				r->next=s;r=s;//��s����ld�ĺ���
				break;//����ѭ��
			}
		}

		pa=pa->next;
	}
	r->next=NULL;//�������µ������ĩβָ���ָ��
}

void UnionList3(LinkNode *LA, LinkNode *LB, LinkNode *&LE) {//�󽻼����㷨
	LinkNode *pa = LA->next, *pb = LB->next, *r, *s;//s��һ����ʱ�洢���õ������Ľ��
	LE = (LinkNode *)malloc(sizeof(LinkNode));
	r = LE;

	while (pa != NULL||pb != NULL) {//��
		if (pb == NULL) {
			pa = pa->next;
			pb = LB->next;
			continue;
		}
		if(pa->data == pb->data) {
			s = (LinkNode *)malloc(sizeof(LinkNode));
			s->data = pa->data;
			r->next = s; r = s;
			pa = pa->next;
			pb = pb->next;
			continue;
		}
		if (pa->data != pb->data) {
			pb = pb->next;
		}
	}
	r->next = NULL;
}