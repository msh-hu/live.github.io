#include<bits/stdc++.h>
using namespace std;
typedef struct Node {
	int data;//数据域
	struct Node *leftchild;//左子树指针
	struct Node *rightchild;//右子树指针
}BiTreeNode;

//计算二叉树中度为1的结点总数
int leaf_1(BiTreeNode *T) {
	if (T==NULL) {
		return 0;
	}
	if ((T->leftchild == NULL && T->rightchild != NULL) || (T->leftchild != NULL && T->rightchild == NULL))
	{
		return 1 + leaf_1(T->leftchild) + leaf_1(T->rightchild);
	}
	return leaf_1(T->leftchild) + leaf_1(T->rightchild);
}