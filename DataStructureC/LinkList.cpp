
#include "LinkList.h"


//初始化一个顺序表
Status InitList(LinkList *L)
{
	L->head = NULL;
	L->tail = NULL;
	L->length = 0;
	return OK;
}
//销毁
Status DestroyList(LinkList *L)
{
	return ClearList(L);
}
//是否为空表
int ListEmpty(LinkList L)
{

	if (L.length == 0)
		return TRUE;
	else
		return FALSE;
}
//重置为空表
Status ClearList(LinkList *L)
{
	struct LNode *pt = L->head, *p = NULL;
	if (!(L->head))
		return INFEASIBLE;
	for (; pt;)
	{
		p = pt;
		pt = pt->next;
		free(p);
	}
	L->head = NULL;
	L->tail = NULL;
	L->length = 0;
	return OK;
}
//返回L的元素个数
int ListLength(LinkList L)
{
	return L.length;
}
//插入第i（i>=1）个元素
Status ListInsert(LinkList *L, int i, ElemType e)
{
	int j, n = L->length;
	LNode *pt = L->head, *p = NULL;

	if (i < 1 || i > n + 1)
		return OVERFLOW;

	if (i==1){
		p = (LNode*)malloc(sizeof(LNode));
		if (!p)
			return ERROR;
		p->data = e;
		L->head = p;
		p->next = pt;
		L->length++;
		return OK;
	}
	for (j = 1; j < i-1; j++)
	{
		pt = pt->next;
	}
	p = (LNode*)malloc(sizeof(LNode));
	if (!p)
		return ERROR;
	p->data = e;
	p->next = pt->next;
	pt->next = p;
	L->length++;
	return OK;
}
//删除第i个元素, 用e返回
Status ListDelete(LinkList *L, int i, ElemType* e)
{
	LNode *pt = L->head, *p = NULL;
	if (i == 1){
		p = L->head;
		*e = p->data;
		L->head = L->head->next;
		free(p);
		L->length--;
		return OK;
	}
	for (int j = 1; j < i-1; j++)
	{
		pt = pt->next;
	}
	p = pt->next;
	*e = p->data;
	pt->next = p->next;
	free(p);
	L->length--;
	return OK;
}
//遍历顺序表
Status ListTraverse(LinkList L, void(*visit)(ElemType))
{
	for (LNode* p = L.head; p; p = p->next){
		visit(p->data);
	}
	printf("; %d个元素\n", L.length);
	return OK;
}
//返回L第i（i>=1）个元素
Status GetElem(LinkList L, int i, ElemType *e)
{
	if (!L.head)
		return INFEASIBLE;
	if (i < 1 || i > L.length)
		return OVERFLOW;
	LNode* p = L.head;
	for (int j = 1; j < i; i++){
		p = p->next;
	}
	*e = p->data;
	return OK;
}
//返回cur_e的后继
Status NextElem(LinkList L, ElemType cur_e, ElemType *next_e)
{

	for (LNode* p = L.head; p; p = p->next){
		if (p->data == cur_e && p->next){
			*next_e = p->next->data;
			return OK;
		}
	}
	return INFEASIBLE;
}
//返回cur_e的前驱
Status PriorElem(LinkList L, ElemType cur_e, ElemType *pre_e)
{
	LNode* pt = L.head;
	for (LNode* p = pt->next; p; pt = pt->next, p = pt->next){
		if (p->data == cur_e){
			*pre_e = pt->data;
			return OK;
		}
	}
	return INFEASIBLE;
}

int LocateElem(LinkList L, ElemType e, bool (*func)(ElemType, ElemType))
{
	int i = 0;
	for (LNode* p = L.head; p; p = p->next){
		i++;
		if (func(e, p->data))
			return i;
	}
	return 0;
}



//分配由p指向的值为e的结点，并返回OK；分配失败返回ERROR
Status MakeNode(LNode *p, ElemType e){
	p = (LNode*)malloc(sizeof(LNode));
	if (!p)
		return ERROR;
	p->data = e;
	return OK;
}
//释放p所指结点
void freeNode(LNode *p)
{
	free(p);
	p = NULL;
}
//将node插入第一个结点之前
Status InsertFirst(LNode *head, LNode *node)
{

	return OK;
}
//p属于L， 将s插入p之前
Status InsertBefore(LinkList *L, LNode *p, LNode *s)
{
	return OK;
}
//p属于L， 将s插入p之后
Status InsertAfter(LinkList *L, LNode *p, LNode *s)
{
	return OK;
}
//在末尾添加p
Status Append(LinkList *L, LNode *p)
{
	L->tail->next = p;
	p->next = NULL;
	return OK;
}
//删除第一个结点，用q返回
Status DeleteFirst(LNode *head, LNode *q)
{
	return OK;
}
//删除末尾结点，用q返回
Status Remove(LinkList *L, LNode *q)
{
	return OK;
}