#ifndef BIT_TREE_H
#define BIT_TREE_H

#include "macro.h"
#include "SqStack.h"

#define TElemType int
#define MAX_TREE_SIZE 100

/**************************** 二叉树 ***************************/

//二叉树节点
typedef struct BTreeNode
{
	TElemType data;
	BTreeNode *lchild;
	BTreeNode *rchild;
}BTreeNode;

//各函数声明

BTreeNode* CreateBitTree();										//层次构造二叉树
Status DestroyBitTree(BTreeNode *T);							//销毁二叉树
Status PreOrderTraverse(BTreeNode *T, Status (*visit)(TElemType)); //递归前序遍历二叉树
Status InOrderTraverse(BTreeNode *T, Status(*visit)(TElemType)); //递归中序遍历二叉树
Status PostOrderTraverse(BTreeNode *T, Status(*visit)(TElemType)); //递归后序遍历二叉树
Status LevelorderTraverse(BTreeNode *T, Status(*visit)(TElemType)); //递归层次遍历二叉树
Status RPreOrderTraverse(BTreeNode *T, Status(*visit)(TElemType)); //非递归前序遍历二叉树
Status RInOrderTraverse(BTreeNode *T, Status(*visit)(TElemType)); //非递归中序遍历二叉树
Status RPostOrderTraverse(BTreeNode *T, Status(*visit)(TElemType)); //非递归后序遍历二叉树
Status RLevelorderTraverse(BTreeNode *T, Status(*visit)(TElemType)); //非递归层次遍历二叉树
std::vector<std::vector<int>> RLevelorderTraverse2(BTreeNode *T); // 非递归层次遍历二叉树，返回二维数组，一行对应一层
Status MorrisPreorderTraversal(BTreeNode* T, Status(*visit)(TElemType)); // Morris 前序遍历
Status MorrisInorderTraversal(BTreeNode *T, Status(*visit)(TElemType)); // Morris 中序遍历
int Deep(BTreeNode *T);											//求二叉树的深度

BTreeNode* CreateBitSortTree();									//构造二叉排序树


/**************************** 线索二叉树 ***************************/
typedef enum
{
	Link, //指针
	Thread //线索
}Tag;

//线索二叉树节点
typedef struct BiThrNode
{
	TElemType data;
	Tag LTag, RTag;
	BiThrNode *lchild, *rchild;
}BiThrNode;



/**************************** 赫夫曼树和赫夫曼编码的存储表示 ***************************/

#define NS 10  //叶子结点树为 NS，总结点 2 * NS -1

typedef struct  //结点
{
    unsigned int weight;
    unsigned int parent, lchild, rchild;
}HTNode;

//HTNode huffmanTree[2 * NS - 1];



/**************************** 树的双亲表示法 ***************************/

typedef struct PTNode //树的结点
{
	TElemType data;
	int parent;
}PTNode;

typedef struct		//树
{
	PTNode nodes[MAX_TREE_SIZE];
	int root, num;
}PTree;





/**************************** 树的孩子表示法 ***************************/

typedef struct CTNode //孩子结点
{
	int child; //孩子位置域
	CTNode *next;
}CTNode;

typedef struct  //树的结点
{
	TElemType data;
	CTNode *firstChild;
}CTBox;

typedef struct //树
{
	CTBox nodes[MAX_TREE_SIZE];
	int root, num;
}CTree;




/**************************** 树的孩子兄弟表示法 ***************************/

typedef struct CSNode  //树的结点
{
	TElemType data;
	CSNode *firstChild;
	CSNode *nextSibling;
}CSNode;


#endif
