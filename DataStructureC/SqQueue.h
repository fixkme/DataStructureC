//SqQueue.h
#ifndef SQ_QUEUE_H
#define SQ_QUEUE_H

#include "macro.h"
#define MAX_SIZE 100
#define ElemType int

//循环队列
typedef struct
{
	ElemType *base;
	int front;
	int rear;
}SqQueue;

//------------------------------  函数声明 ----------------------------

Status InitQueue(SqQueue *Q);
Status DestroyQueue(SqQueue *Q);
Status ClearQueue(SqQueue *Q);
Status QueueEmpty(SqQueue Q);
int QueueLength(SqQueue Q);
Status GetHead(SqQueue Q, ElemType *e);
Status EnQueue(SqQueue *Q, ElemType e);
Status DeQueue(SqQueue *Q, ElemType *e);
Status QueueTraverce(SqQueue Q, void(*visit)(ElemType));

#endif