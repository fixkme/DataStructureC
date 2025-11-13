
//SqStack.h
#ifndef SQ_STACK_H
#define SQ_STACK_H

#define STACK_INIT_SIZE 100
#define STACK_INCREMENT 10
#define ElemType int
#include "macro.h"


//定义顺序栈
typedef struct SqStack
{
	ElemType *base;
	ElemType *top;
	int stacksize;
}SqStack;

//函数声明

Status InitStack(SqStack *S);  //构造顺序栈
Status DestroyStack(SqStack *S); //销毁
Status StackEmpty(SqStack S);  //判断是否为空
Status ClearStack(SqStack *S);  //清空栈
int StackLength(SqStack S);  //返回栈元素个数
Status Push(SqStack *S, ElemType e);  //压入栈
Status Pop(SqStack *S, ElemType *e); //删除栈顶元素，用e返回
Status GetTop(SqStack S, ElemType *e);  //用e返回栈顶元素
Status StackTraverse(SqStack S, Status(*func)(ElemType)); //遍历栈


//------------------------- 算法 --------------------------

/*数值转换， 十进制N和其他d进制的转换，N = (N div d) * d + N mod d; div为整除， mod求余。
输入任意非负十进制，输出八进制
*********************************************************************/
void Conversion(unsigned int N, unsigned int d);

/*括号匹配
*********************************************************************/
void BracketMatch();

/*行编辑
*********************************************************************/
void LineEdit();

/*表达式求值：
1、先乘除后加减
2、从左到右
3、先括号内，后括号外
*********************************************************************/

typedef enum OP
{
	start,
	rightB,
	add,
	sub,
	mut,
	divi,
	leftB
}OP;
//运算符优先级比较
int precede(OP fore, OP back);
//二元运算
ElemType Operate(ElemType fore_num, OP op, ElemType back_num);
//表达式求值
ElemType EvaluateExpression();


/* 迷宫求解 ,0路径，1墙，2已经走过
*********************************************************************/

#define HEIGHT 61
#define WIDTH 61
//搜索的方向
enum Direction
{
	up = 1,
	left,
	down,
	right
};

//定义迷宫位置
typedef struct
{
	int x;
	int y;
	Direction dir;
}Pos;

void MazePath(int map[HEIGHT][WIDTH], Pos startPos, Pos endPos);


/*hanoi塔递归
*********************************************************************/

//n为圆盘总数，x初始位置，y辅助位置，z目的位置;将1到n-1移到z
void Hanoi(int n, char x, char y, char z);
//将编号为n的圆盘从x移到z
void move(char x, int n, char z);

#endif