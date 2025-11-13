
//linkQueue.cpp

#include "LinkQueue.h"

//------------------------------  函数声明 ----------------------------

//构造新队列
Status InitQueue(LinkQueue *Q)
{
	Q->front = Q->rear = (QNode *)malloc(sizeof(QNode));
	if (!Q->front)
		exit(ERROR);
	Q->front->next = NULL;
	return OK;
}
//销毁队列
Status DestroyQueue(LinkQueue *Q)
{
	while (Q->front){
		Q->rear = Q->front->next;
		free(Q->front);
		Q->front = Q->rear;
	}
	return OK;
}
//清除队列
Status ClearQueue(LinkQueue *Q)
{
	QNode *p = Q->front->next;
	while (p){
		Q->rear = p->next;
		free(p);
		p = Q->rear;
	}
	Q->rear = Q->front;
	return OK;
}
//队列是否为空
Status QueueEmpty(LinkQueue Q)
{
	if (Q.front == Q.rear)
		return TRUE;
	else
		return FALSE;
}
//队列长度，元素个数
int QueueLength(LinkQueue Q)
{
	return Q.length;
}
//用e返回队头元素
Status GetHead(LinkQueue Q, ElemType *e)
{
	if (Q.front == Q.rear)
		return INFEASIBLE;
	*e = Q.front->next->data;
	return OK;
}
//入队
Status EnQueue(LinkQueue *Q, ElemType e)
{
	QNode *p = (QNode*)malloc(sizeof(QNode));
	if (!p)
		exit(ERROR);
	p->data = e;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	return OK;
}
//出队
Status DeQueue(LinkQueue *Q, ElemType *e)
{
	if (Q->front == Q->rear)
		return INFEASIBLE;
	QNode *p = Q->front->next;
	*e = p->data;
	Q->front->next = p->next;
	if (p == Q->rear)
		Q->rear = Q->front;
	free(p);
	return OK;
}
//遍历队列
Status QueueTraverce(LinkQueue Q, void(*visit)(ElemType))
{
	QNode *p = Q.front->next;
	while (p){
		visit(p->data);
		p = p->next;
	}
	printf("; %d个元素\n", Q.length);
	return OK;
}
