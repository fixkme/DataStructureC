//BTree.cpp 主函数

#include "BTree.h"
#include <stack>
#include <queue>
#include <string>

//层次构造二叉树
BTreeNode* CreateBitTree()
{
	puts("层次顺序输入节点：");
	TElemType e;
	TElemType non = '#';
	BTreeNode *T=NULL, *p = NULL, *l = NULL, *r = NULL;
	std::queue<BTreeNode*> q;
	e = getchar();
	if (e == non)
		return NULL;
	else{
		if (!(T = (BTreeNode *)malloc(sizeof(BTreeNode))))
			exit(ERROR);
		T->data = e;
		q.push(T);
		while (!q.empty()){

			//左孩子
			e = getchar();
			if (e == non)
				l = NULL;
			else{
				if (!(l = (BTreeNode *)malloc(sizeof(BTreeNode))))
					exit(ERROR);
				l->data = e;
				q.push(l);
			}
			//右孩子
			e = getchar();
			if (e == non)
				r = NULL;
			else{
				if (!(r = (BTreeNode *)malloc(sizeof(BTreeNode))))
					exit(ERROR);
				r->data = e;
				q.push(r);
			}
			p = q.front(); q.pop();
			p->lchild = l;
			p->rchild = r;
		}
	}
	return T;
}

//构造二叉排序树
BTreeNode* CreateBitSortTree()
{
	BTreeNode *T = NULL, *p = NULL, *pt = NULL, *newNode = NULL;
	int val;
	int arr[] = { 5, 7, 12, 4, 17, 2, 1, 10 };
	std::vector<int> datas(arr, arr+8);
	if (datas.size() == 0)
		return NULL;
	if (!(T = (BTreeNode *)malloc(sizeof(BTreeNode))))
		exit(ERROR);
	T->data = datas[0]; T->lchild = T->rchild = NULL;

	for (int i = 1; i < datas.size(); i++){
		val = datas[i];
		if (!(newNode = (BTreeNode *)malloc(sizeof(BTreeNode))))
			exit(ERROR);
		newNode->data = val; newNode->lchild = newNode->rchild = NULL;
		pt = T;
		while (pt){
			p = pt;
			if (val < pt->data)
				pt = pt->lchild;
			else if (val > pt->data)
				pt = pt->rchild;
		}
		if (val < p->data)
			p->lchild = newNode;
		else if (val > p->data)
			p->rchild = newNode;
	}
	return T;
}

//左右根销毁二叉树
Status DestroyBitTree(BTreeNode *T)
{
	if (T){
		if (DestroyBitTree(T->lchild) && DestroyBitTree(T->rchild))
		{
			free(T);
			return OK;
		}
	}
	return OK;
}
//递归前序遍历二叉树
Status PreOrderTraverse(BTreeNode *T, Status(*visit)(TElemType)) 
{
	if (T){
		if (visit(T->data))
			if (PreOrderTraverse(T->lchild, visit))
				if (PreOrderTraverse(T->rchild, visit))
					return OK;
		return ERROR;
	}
	return OK;
}
//递归中序遍历二叉树
Status InOrderTraverse(BTreeNode *T, Status(*visit)(TElemType))
{
	if (T){
		if (InOrderTraverse(T->lchild, visit))
			if (visit(T->data))
				if (InOrderTraverse(T->rchild, visit))
					return OK;
		return ERROR;
	}
	return OK;
}

//递归后序遍历二叉树
Status PostOrderTraverse(BTreeNode *T, Status(*visit)(TElemType))
{
	if (T){
		if (PostOrderTraverse(T->lchild, visit))
			if (PostOrderTraverse(T->rchild, visit))
				if (visit(T->data))
					return OK;
		return ERROR;
	}
	return OK;
}

//递归层次遍历二叉树； 不推荐
Status LevelorderTraverse(BTreeNode *T, Status(*visit)(TElemType))
{
    return OK;
}

//非递归前序遍历二叉树
Status RPreOrderTraverse(BTreeNode *T, Status(*visit)(TElemType))
{
	BTreeNode *p = T;
	std::stack<BTreeNode*> s;
	while (p || !s.empty()){
		if (p){
			if (!visit(p->data))
				return ERROR;
			s.push(p->rchild);
			s.push(p->lchild);
		}
		p = s.top(); s.pop();
	}
	return OK;
}
//非递归中序遍历二叉树
Status RInOrderTraverse(BTreeNode *T, Status(*visit)(TElemType))
{
	std::stack<BTreeNode *> S;
	BTreeNode *p = T;

	while (p || !S.empty()){
		if (p){
			S.push(p);
			p = p->lchild;
		}
		else{
			p = S.top(); S.pop();
			if (!visit(p->data))
				return ERROR;
			p = p->rchild;
		}
	}
	return OK;
}

//非递归后序遍历二叉树
Status RPostOrderTraverse(BTreeNode *T, Status(*visit)(TElemType))
{

	return OK;
}

//非递归层次遍历二叉树
Status RLevelorderTraverse(BTreeNode *T, Status(*visit)(TElemType))
{
	std::queue<BTreeNode*> q;
	BTreeNode *p = NULL;
	q.push(T);
	while (!q.empty()){
		p = q.front(); q.pop();
		if (p){
			if (!visit(p->data))
				return ERROR;
			q.push(p->lchild);
			q.push(p->rchild);
		}
		else{
			//putchar('#');
		}
	}
	return OK;
}
//求二叉树的深度
int Deep(BTreeNode *T)
{
	if (!T)
		return 0;
	else{
        int n = Deep(T->lchild);
		int m = Deep(T->rchild);
        if (n < m)
            n = m;
		return n + 1;
	}
}
