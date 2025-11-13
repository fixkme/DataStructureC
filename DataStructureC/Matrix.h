#ifndef MATRIX_H
#define MATRIX_H

#include<stdio.h>
#include<iostream>
#include<vector>
#include<stdlib.h>
#define  ElemType int
#define MAXSIZE 100
using namespace std;

typedef struct  //三元组
{
    ElemType e;
    int i, j;
}Triple;

typedef struct  //压缩矩阵
{
    Triple data[MAXSIZE + 1];
    int mu, nu, tu;
}TSMatrix;

//函数声明
void scan(TSMatrix *M);   //输入压缩矩阵
void printTSMatrix(TSMatrix *M);   //输出压缩矩阵
Triple getELem(TSMatrix M, int i, int j);  //访问元素
void changeElem(TSMatrix *M, int i, int j, ElemType e); //改变元素值
void TransposeTSMatrix(TSMatrix M, TSMatrix *T);	 //稀疏矩阵简单转置
void FastTransposeTSMatrix(TSMatrix M, TSMatrix *T); //稀疏矩阵快速转置

int Matrixtest()     //函数
{
    TSMatrix M, T;
    int i = 4, j = 5;
    M.mu = 4;
    M.nu = 5;
    M.tu = 4;
    scan(&M);
    //printf("M(%d, %d) = %d\n",i, j, getELem(M,i,j).e );
    //changeElem(&M, i, j, 22);
    //print(&M);
    //TransposeTSMatrix(M, &T);
    FastTransposeTSMatrix(M, &T);
    printTSMatrix(&T);
    return 0;
}

#endif // MATRIX_H
