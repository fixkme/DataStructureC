//SqStack.cpp

#include"SqStack.h"

/*----------------------------------- 定义各个函数 -------------------------------*/

//构造顺序栈
Status InitStack(SqStack *S)
{
	S->base = (ElemType *)malloc(sizeof(ElemType)*(STACK_INIT_SIZE));
	if (!S->base)
		exit(ERROR);
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
	return OK;
}
//销毁
Status DestroyStack(SqStack *S)
{
	if (!S->base)
		return INFEASIBLE;
	free(S->base);
	S->base = NULL;
	S->top = NULL;
	S->stacksize = 0;
	return OK;
}
//判断是否为空
Status StackEmpty(SqStack S)
{
	if (S.base == S.top)
		return TRUE;
	else
		return FALSE;
}
//清空栈
Status ClearStack(SqStack *S)
{
	if (!S->base)
		return INFEASIBLE;
	S->top = S->base;
	return OK;
}
//返回栈元素个数,栈长度
int StackLength(SqStack S) 
{
	return S.top - S.base;
}
//压入栈
Status Push(SqStack *S, ElemType e)
{
	if (S->top - S->base >= S->stacksize)
	{
		S->base = (ElemType *)realloc(S->base, sizeof(ElemType)*(S->stacksize + STACK_INCREMENT));
		if (!S->base)
			exit(ERROR);
		S->top = S->stacksize + S->base;
		S->stacksize += STACK_INCREMENT;
	}
	*(S->top) = e;
	S->top++;
	return OK;
}
//删除栈顶元素，用e返回
Status Pop(SqStack *S, ElemType *e) 
{
	if (S->base == S->top)
		return INFEASIBLE;
	S->top--;
	*e = *(S->top);
	return OK;
}
//用e返回栈顶元素
Status GetTop(SqStack S, ElemType *e)  
{
	if (S.base == S.top)
		return INFEASIBLE;
	*e = *(S.top);
	return OK;
}
//遍历栈
Status StackTraverse(SqStack S, Status (*func)(ElemType))
{
	ElemType *p;
	for (p = S.base; p != S.top; p++){
		func(*p);
	}
	printf("; %d个元素\n", S.top - S.base);
	return OK;
}

//------------------- 辅助函数 ---------------------

Status visit(ElemType e){
	printf("%c", e);
	return OK;
}

//------------------- 算法 --------------------------

/*数值转换， 十进制N和其他d进制的转换，N = (N div d) * d + N mod d; div为整除， mod求余。
输入任意非负十进制，输出d进制
**************************************************************************/
void Conversion(unsigned int N, unsigned int d){
	ElemType e;
	SqStack s;
	InitStack(&s);

	while (N){
		Push(&s, N % d);
		N = N / d;
	}
	while (!StackEmpty(s)){
		Pop(&s, &e);
		printf("%d", e);
	}
	printf("\n");
	DestroyStack(&s);
}

/*括号匹配
***********************************************************************/
void BracketMatch(){
	typedef struct Bracket{
		char left;
		char right;
	}Bracket;

	ElemType e;
	SqStack s;
	InitStack(&s);
	
	DestroyStack(&s);
}

/*行编辑；#退格， @退行
***********************************************************************/
void LineEdit(){
	ElemType ch, e;
	SqStack s;
	InitStack(&s);
	ch = getchar();
	while (ch != EOF){
		while (ch != EOF && ch != '\n'){
			switch (ch)
			{
			case '#': 
				Pop(&s, &e);
				break;
			case '@':
				ClearStack(&s);
				break;
			default:
				Push(&s, ch);
				break;
			}
			ch = getchar();
		}
		StackTraverse(s, visit);
		ClearStack(&s);
		if (ch != EOF)
			ch = getchar();
	}
	DestroyStack(&s);
}

/*表达式求值：
1、先乘除后加减
2、从左到右
3、先括号内，后括号外
***********************************************************************/

//运算符优先级比较
int precede(OP fore, OP back){
	return 0;
}
//二元运算
ElemType Operate(ElemType fore_num, OP op, ElemType back_num){
	return fore_num;
}
//表达式求值
ElemType EvaluateExpression(){
	ElemType e='\0';
	return e;
}

/*迷宫求解
***********************************************************************/
void MazePath(int map[HEIGHT][WIDTH], Pos startPos, Pos endPos){

}

/*hanoi塔递归
*********************************************************************/

//n为圆盘总数，x初始位置，y辅助位置，z目的位置;将1到n-1移到z
void Hanoi(int n, char x, char y, char z){
	if (n == 1){
		move(x, 1, z);
	}
	else{
		Hanoi(n - 1, x, z, y);
		move(x, n, z);
		Hanoi(n - 1, y, x, z);
	}
}
//将编号为n的圆盘从x移到z
void move(char x, int n, char z){
	static int i = 0;
	printf("%d: 将编号为 %d 的圆盘从 %c 移到 %c\n", ++i, n, x, z);
}
