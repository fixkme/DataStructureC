
#include "Matrix.h"

//定义各函数
void scan(TSMatrix *M)   ////输入压缩矩阵
{
	int n;
	for (n = 1, M->tu = 0; ; n++)
	{
		cin>>M->data[n].e>>M->data[n].i>> M->data[n].j;
		//输入0 0 0表示结束输入
		if (M->data[n].e == 0 && M->data[n].i == 0 && M->data[n].j == 0)
		{
			break;
		}
		M->tu++;
	}
}

void printTSMatrix(TSMatrix *M)   //输出压缩矩阵
{
	int n;
	for (n = 1; n <= M->tu; n++)
	{
		printf("%4d %d %d\n", M->data[n].e, M->data[n].i, M->data[n].j);
	}
}

Triple getELem(TSMatrix M, int i, int j)  ////访问元素
{
	Triple zero = { 0, i, j };
	int n;
	if (i<1 || i>M.mu || j < 1 || j > M.nu)
	{
		exit(1);
	}
	for (n = 1; n <= M.tu; n++)
	{
		if (M.data[n].i == i && M.data[n].j == j)
		{
			return M.data[n];
		}
	}
	return zero;
}

void changeElem(TSMatrix *M, int i, int j, ElemType e)	//改变元素值
{
	int n, k = 0;
	if (i<1 || i>M->mu || j < 1 || j > M->nu)
	{
		printf("error");
		return;
	}
	for (n = 1; n <= M->tu; n++)
	{
		if (M->data[n].i == i)
		{
			if (M->data[n].j == j)
			{
				M->data[n].e = e;
				return;
			}
			else if (M->data[n].j > j)
			{
				k = n;
				break;
			}
			else
			{
				k = n + 1;
				if (M->data[n + 1].i != i)
				{
					break;
				}
			}
		}
		else if (M->data[n].i > i)
		{
			k = n;
			break;
		}
	}
	M->tu ++;
	for (n = M->tu; n != k; n--)
	{
		M->data[n] = M->data[n - 1];
	}
	M->data[n].e = e;
	M->data[n].i = i;
	M->data[n].j = j;
}

void TransposeTSMatrix(TSMatrix M, TSMatrix *T) //稀疏矩阵简单转置
{
	int p, col, q = 1;
	if (!M.tu)
	{
		return;
	}
	T->mu = M.nu;
	T->nu = M.mu;
	T->tu = M.tu;
	for (col = 1; col <= M.nu; col++)
	{
		for (p = 1; p <= M.tu; p++)
		{
			if (col == M.data[p].j)
			{
				T->data[q].i = M.data[p].j;
				T->data[q].j = M.data[p].i;
				T->data[q].e = M.data[p].e;
				q++;
			}
		}
	}
}

void FastTransposeTSMatrix(TSMatrix M, TSMatrix *T) //稀疏矩阵快速转置
{
	int p, q, col;
	vector<int>num(M.nu+1, 0);
	vector<int>cpot(M.nu+1, 0);
	if (!M.tu)
	{
		return;
	}
	T->mu = M.nu;
	T->nu = M.mu;
	T->tu = M.tu;
	cpot[1] = 1;
	for (int t = 1; t <= M.tu; t++)//求每列非零元个数
	{
		num[M.data[t].j] ++;
	}
	//求第col列第一个非零元在T.data[]中的序号
	for (col = 2; col <= M.nu; col++)
	{
		cpot[col] = cpot[col - 1] + num[col - 1];
	}
	for (p = 1; p <= M.tu; p++)
	{
		col = M.data[p].j;
		q = cpot[col];
		T->data[q].i = M.data[p].j;
		T->data[q].j = M.data[p].i;
		T->data[q].e = M.data[p].e;
		cpot[col]++;
	}
}
