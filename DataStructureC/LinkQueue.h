
#ifndef LINK_QUEUE_H
#define LINK_QUEUE_H

#include "macro.h"
#define ElemType int

//队列结点
typedef struct  QNode
{
	ElemType data;
	QNode *next;
}QNode;

//单链表队列
typedef struct
{
	QNode *front;
	QNode *rear;
	int length;
}LinkQueue;

//------------------------------  函数声明 ----------------------------

Status InitQueue(LinkQueue *Q);
Status DestroyQueue(LinkQueue *Q);
Status ClearQueue(LinkQueue *Q);
Status QueueEmpty(LinkQueue Q);
int QueueLength(LinkQueue Q);
Status GetHead(LinkQueue Q, ElemType *e);
Status EnQueue(LinkQueue *Q, ElemType e);
Status DeQueue(LinkQueue *Q, ElemType *e);
Status QueueTraverce(LinkQueue Q, void(*visit)(ElemType));

#endif