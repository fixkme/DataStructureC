
#ifndef SQ_LIST_H
#define SQ_LIST_H

#include "macro.h"

#define ElemType int
#define LIST_INIT_SIZE 100
#define LIST_INCREMENT 10

//定义顺序表
typedef struct
{
	ElemType *list;
	int length;
	int listsize;
}SqList;

//函数声明

Status InitList(SqList *L);  //初始化一个顺序表
Status DestroyList(SqList *L); //销毁
int ListEmpty(SqList L); //是否为空表
Status ClearList(SqList *L);  //重置为空表
int ListLength(SqList L); //返回L的元素个数
Status GetElem(SqList L, int i, ElemType *e); //返回L第i（i>=1）个元素，下标为i-1
Status ListInsert(SqList *L, int i, ElemType e); //插入第i个元素，下标为i-1
Status ListDelete(SqList *L, int i, ElemType* e);//删除第i个元素， 下标为i-1，, 用e返回
Status ListTraverse(SqList L, Status(*visit)(ElemType)); //遍历顺序表
Status NextElem(SqList L, ElemType cur_e, ElemType *next_e); //返回cur_e的后继
Status PriorElem(SqList L, ElemType cur_e, ElemType *pre_e); //返回cur_e的前驱
int LocateElem(SqList L, ElemType e, bool (*func)(ElemType, ElemType));//判断e和L的元素的关系
int BinarySearch(SqList L, ElemType key);//折半查找

//------------------------------- 算法 -------------------------------

/*将在Lb中不在La中的元素插入到La*/
void Union(SqList *La, SqList Lb);

/*已知la和lb的元素按非递减排列
 *归并la和lb到lc，lc也按非递减排列
*/
void MergeList(SqList La, SqList Lb, SqList *Lc);

/*删除表中所有值为x的元素
时间复杂度O(n), 空间复杂度O(1)*/
void DeleteElem(SqList *L, ElemType x);

/*删除表中所有值大于mink且小于maxk的元素*/
Status DeleteBetween_min_max(SqList *L, ElemType mink, ElemType maxk);    

/*删除表中所有值相同的多余元素*/
void DeleteEqualElem(SqList *L); 

#endif

