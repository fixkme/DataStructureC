//BTree.cpp 主函数

#include "BTree.h"
#include <stack>
#include <queue>
#include <string>
#include <list>
#include <vector>

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
	std::stack<BTreeNode *> S;
	BTreeNode *p = T, *prev = NULL;
	while (p || !S.empty()) {
		if (p) {
            S.push(p);
            p = p->lchild;
        } else {
            p = S.top();
            // 如果右子树为空，或右子树已访问过
            if (p->rchild == NULL || p->rchild == prev) {
                visit(p->data);
                prev = p;
                S.pop();
                p = NULL; // 防止继续向左走
            } else {
                p = p->rchild; // 转向右子树
            }
        }
	}
	return OK;
}

//非递归层次遍历二叉树
Status RLevelorderTraverse(BTreeNode *T, Status(*visit)(TElemType))
{
	// 如果节点数量固定或上限，则可以使用循环队列
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

// 层次遍历二叉树， 返回二维数组，一行对应一层
std::vector<std::vector<int>> RLevelorderTraverse2(BTreeNode *T) {
	std::vector<std::vector<int>> ret;
    if (T == NULL) {
		return ret;
	}
	BTreeNode* p;
	std::queue<BTreeNode*> q;
	q.push(T);
	while (!q.empty()) {
		int size = q.size();
		std::vector<int> currentLevel;
		currentLevel.reserve(size);
		for (int i=0; i < size; i++) {
			p = q.front(); q.pop();
			currentLevel.push_back(p->data);
			if (p->lchild != NULL) {
				q.push(p->lchild);
			}
			if (p->rchild != NULL) {
				q.push(p->rchild);
			}
		}
		ret.push_back(currentLevel);
	}
	return ret;
}

// 莫里斯前序遍历
Status MorrisPreorderTraversal(BTreeNode* T, Status(*visit)(TElemType)) {
    BTreeNode *cur = T;
    while (cur) {
        if (cur->lchild == NULL) {
            // 如果没有左子树，直接访问当前节点并转向右子树
            visit(cur->data);
            cur = cur->rchild;
        } else {
            // 找到当前节点在中序遍历下的前驱节点
            BTreeNode *pre = cur->lchild;
            while (pre->rchild && pre->rchild != cur) {
                pre = pre->rchild;
            }
            
            if (pre->rchild == NULL) {
                // 第一次访问，建立临时链接并访问当前节点
                pre->rchild = cur;
                visit(cur->data);  // 前序遍历：在第一次访问时输出
                cur = cur->lchild;
            } else {
                // 第二次访问，恢复树结构并转向右子树
                pre->rchild = NULL;
                cur = cur->rchild;
            }
        }
    }
	return OK;
}

// Morris 中序遍历, 时间O(n)，空间O(1)
// 有临时写操作， 不利于并发
Status MorrisInorderTraversal(BTreeNode *T, Status(*visit)(TElemType)) {
    BTreeNode* cur = T;
    while (cur != NULL) {
        if (cur->lchild == NULL) {
            // 没有左子树：访问当前节点，然后去右子树
            visit(cur->data);
            cur = cur->rchild;
        } else {
            // 找到 cur 的中序前驱（左子树的最右节点）
            BTreeNode* pre = cur->lchild;
            while (pre->rchild != NULL && pre->rchild != cur) {
                pre = pre->rchild;
            }

            if (pre->rchild == NULL) {
                // 第一次到达：建立线索 pre->rchild = cur
                pre->rchild = cur;
                cur = cur->lchild;
            } else {
                // 第二次到达：说明左子树已遍历完，断开线索
                pre->rchild = NULL;
                visit(cur->data);  // 访问当前节点
                cur = cur->rchild;
            }
        }
    }
	return OK;
}

//求二叉树的深度
int Deep(BTreeNode *T)
{
	if (!T)
		return 0;
	else {
        int n = Deep(T->lchild);
		int m = Deep(T->rchild);
        if (n < m)
            n = m;
		return n + 1;
	}
}
