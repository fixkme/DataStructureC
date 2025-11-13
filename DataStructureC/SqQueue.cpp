//SqQueue.cpp

#include"SqQueue.h"


//构造新循环队列
Status InitQueue(SqQueue *Q)
{
	Q->base = (ElemType*)malloc(sizeof(ElemType)*MAX_SIZE);
	if (!Q->base)
		exit(ERROR);
	Q->front = Q->rear = 0;
	return OK;
}
//销毁队列
Status DestroyQueue(SqQueue *Q)
{
	if (!Q->base)
		return INFEASIBLE;
	free(Q->base);
	return OK;
}
//清除队列
Status ClearQueue(SqQueue *Q)
{
	if (!Q->base)
		return INFEASIBLE;
	Q->rear = Q->front = 0;
	return OK;
}
//队列是否为空
Status QueueEmpty(SqQueue Q)
{
	if (Q.front == Q.rear) //循环队列空
		return TRUE;
	else
		return FALSE;
}
//循环队列长度，元素个数
int QueueLength(SqQueue Q)
{
	return (Q.rear - Q.front + MAX_SIZE) % MAX_SIZE; //循环队列长度计算
}
//用e返回队头元素
Status GetHead(SqQueue Q, ElemType *e)
{
	if (Q.front == Q.rear)
		return INFEASIBLE;
	*e = Q.base[Q.front];
	return OK;
}
//入队
Status EnQueue(SqQueue *Q, ElemType e)
{
	if ((Q->rear + 1) % MAX_SIZE == Q->front) //循环队列满
		return ERROR;
	Q->base[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAX_SIZE;  //更新Q.rear
	return OK;
}
//出队
Status DeQueue(SqQueue *Q, ElemType *e)
{
	if (Q->front == Q->rear) //循环队列空
		return ERROR;
	*e = Q->base[Q->front];
	Q->front = (Q->front + 1) % MAX_SIZE;  //更新Q.front
	return OK;
}
//遍历队列
Status QueueTraverce(SqQueue Q, void(*visit)(ElemType))
{
	int i = Q.front;
	for (; i != Q.rear; i = (i+1) % MAX_SIZE){
		visit(Q.base[i]);
    }
	return OK;
}
