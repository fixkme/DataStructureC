
#ifndef GRAPH_H
#define GRAPH_H

#include <limits.h>
#include "LinkQueue.h"
#include "SqStack.h"

#define INFINITY INT_MAX
#define MAX_VERTEX_NUM 20
#define VertexType int
#define VRtype int
#define InfoType void

typedef enum { DG, DN, UDG, UDN }GraphKind; //有向图, 有向网, 无向图, 无向网

/************* 数组表示, 邻接矩阵 *******************/
typedef struct ArcCell{
    VRtype adj;     //表示相邻否；对于网，则为权值
    InfoType *info; //该弧的其它信息
}ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct {
    VertexType vexs[MAX_VERTEX_NUM]; //顶点向量
    AdjMatrix arcs;                  //邻接矩阵
    int vexnum, arcnum;
    GraphKind kind;
}MGraph;


/************* 链式存储结构, 邻接表 *******************/
typedef struct ArcNode{
    int adjvex;             //该弧指向顶点的位置，这里是数组下标，也可以是指针类型
    struct ArcNode *nextarc;//指向下一个邻接顶点的弧
    InfoType *info;
}ArcNode;

typedef struct VNode{
    VertexType data;    //顶点信息
    ArcNode *firstarc;  //指向第一条弧
}VNode, AdjList[MAX_VERTEX_NUM];

typedef struct {
    AdjList vertices;   //邻接表
    int vexnum, arcnum;
    GraphKind kind;
}ALGraph;


/************* 有向图的另一种链式存储结构，十字链表 *******************/
//十字链表可以理解为邻接表和逆邻接表的结合
typedef struct ArcBox{
    int tailvex, headvex;         //该弧的尾和头顶点的位置
    struct ArcBox *tlink, *hlink; //指向下一个邻接顶点的弧
    InfoType *info;
}ArcBox;

typedef struct VexNode{
    VertexType data;            //顶点信息
    ArcBox *firstin, *firstout; //指向第一条入弧和出弧
}VexNode;

typedef struct {
    VexNode xlist[MAX_VERTEX_NUM]; //十字链表
    int vexnum, arcnum;
}OLGraph;


/************* 无向图的另一种链式存储结构，邻接多重表 *******************/
typedef enum { unvisited, visited }VisitIf;
typedef struct EBox{
    VisitIf visit;              //访问标记
    int ivex, jvex;             //该边依附的两个顶点的位置
    struct EBox *ilink, *jlink; //分别指向依附这两个顶点的下一条边
    InfoType *info;
}EBox;

typedef struct VexBox{
    VertexType data;    //顶点信息
    ArcNode *firsedge;  //指向第一条边
}VexBox;

typedef struct {
    VexBox adjmulist[MAX_VERTEX_NUM];   //邻接多重表
    int vexnum, arcnum;
}AMLGraph;




/******************* 常用函数 *******************/
int FirstAdjVex(ALGraph G, int v);
int NextAdjVex(ALGraph G, int v, int w);
void FindIndegree(ALGraph G, int indegree[MAX_VERTEX_NUM]);

/******************* 深度优先搜索 *******************/
bool visited[MAX_VERTEX_NUM]; //全局变量
Status (*VisitFunc)(VertexType);//全局变量
void DFSTraverse(ALGraph G, Status (*visit)(int))
{
    VisitFunc = visit;
    for (int v=0; v < G.vexnum; v++)
        visited[v] = false;
    for (int v=0; v < G.vexnum; v++){
        if (!visited[v])
            DFS(G, v);
    }
}
void DFS(ALGraph G, int v)
{
    visited[v] = true;
    VisitFunc(v);
    for (int w = FirstAdjVex(G, v); w >= 0; w = NextAdjVex(G, v, w)){
        if (!visited[w])
            DFS(G, w);
    }
}


/******************* 广度优先搜索 *******************/
void BFSTraverse(ALGraph G, Status (*visit)(int))
{
    LinkQueue Q;InitQueue(&Q);
    for (int v=0; v < G.vexnum; v++)
        visited[v] = false;
    for (int v=0; v < G.vexnum; v++){
        if (!visited[v]){
            EnQueue(&Q, v);
            while(!QueueEmpty(Q)){
                DeQueue(&Q, &v);
                visit(v);
                visited[v] = true;
                for (int w = FirstAdjVex(G, v); w >= 0; w = NextAdjVex(G, v, w)){
                    if (!visited[w]){
                        EnQueue(&Q, w);
                    }
                }
            }
        }
    }
    DestroyQueue(&Q);
}


/******************* 拓扑排序 *******************/
///1、用邻接表作为有向图的存储结构
///2、该算法可以用来检查有向图是否有环
///3、有向图无环时，可以用深度优先遍历进行拓扑排序，此时输出为逆向的拓扑有序序列
Status TopoLogicalSort(ALGraph G)
{   //有环返回ERROR，无环输出拓扑序列
    SqStack S;InitStack(&S);
    int indegree[MAX_VERTEX_NUM];
    FindIndegree(G, indegree);
    for (int i=0; i < G.vexnum; i++)
        if (indegree[i] == 0)
            Push(&S, i);
    int count = 0; //已经输出的拓扑序列顶点数
    int v;
    while (!StackEmpty(S)){
        Pop(&S, &v);
        printf("%d", v);
        ++count;
        for (ArcNode *p = G.vertices[v].firstarc; p; p = p->nextarc){
            int k = p->adjvex;
            if (!(--indegree[k])){
                Push(&S, k);
            }
        }
    }
    if (count < G.vexnum)
        return ERROR;
    else
        return OK;
}


#endif
