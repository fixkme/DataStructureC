
#ifndef LINK_LIST_H
#define LINK_LIST_H

#include "macro.h"

#define MAX_SIZE 100
#define ElemType int

//链表结点
typedef struct  LNode
{
	ElemType data;
	LNode *next;
}LNode, pos;

//单链表
typedef struct
{
	LNode *head;
	LNode *tail;
	int length;
}LinkList;

//------------------------------  函数声明 ----------------------------

Status InitList(LinkList *L);  //初始化一个表
Status DestroyList(LinkList *L); //销毁
int ListEmpty(LinkList L); //是否为空表
Status ClearList(LinkList *L);  //重置为空表
int ListLength(LinkList L); //返回L的元素个数
Status GetElem(LinkList L, int i, ElemType *e); //返回L第i（i>=1）个元素
Status ListInsert(LinkList *L, int i, ElemType e); //插入第i个元素，
Status ListDelete(LinkList *L, int i, ElemType* e);//删除第i个元素，  用e返回
Status ListTraverse(LinkList L, void(*visit)(ElemType)); //遍历顺序表
Status NextElem(LinkList L, ElemType cur_e, ElemType *next_e); //返回cur_e的后继
Status PriorElem(LinkList L, ElemType cur_e, ElemType *pre_e); //返回cur_e的前驱
int LocateElem(LinkList L, ElemType e, bool (*func)(ElemType, ElemType));//判断e和L的元素的关系


Status MakeNode(LNode &p, ElemType e); //分配由p指向的值为e的结点，并返回OK；分配失败返回ERROR
void freeNode(LNode &p); //释放p所指结点
Status InsertFirst(LNode *head, LNode *node); //将node插入第一个结点之前
Status InsertBefore(LinkList *L, LNode *p, LNode *s); //p属于L， 将s插入p之前
Status InsertAfter(LinkList *L, LNode *p, LNode *s); //p属于L， 将s插入p之后
Status Append(LinkList *L, LNode *p); //在末尾添加p
Status DeleteFirst(LNode *head, LNode *q); //删除第一个结点，用q返回
Status Remove(LinkList *L, LNode *q); //删除末尾结点，用q返回


//------------------------------- 算法 -------------------------------

/*将在Lb中不在La中的元素插入到La*/
void Union(LinkList *La, LinkList Lb);

/*已知la和lb的元素按非递减排列
*归并la和lb到lc，lc也按非递减排列
*/
void MergeList(LinkList La, LinkList Lb, LinkList *Lc);

/*删除表中所有值大于mink且小于maxk的元素*/
Status DeleteBetween_min_max(LinkList *L, ElemType mink, ElemType maxk);

//删除表中所有值相同的多余元素*/
void DeleteEqualElem(LinkList *L);

#endif


