/*
* 简体中文
*
* 作者：HRL
* 日期：20190314
* 描述：这里是一些红黑树操作函数的实现
*
* English
*
*/
#pragma once
#include "RedBlackTree.h"
#include "RBTreeLStack.h"

void out()
{
	cout << "123" << endl;
}


bool find(KeyType x,RBTree T)
{
	RBTNode *t = T.root;

}


//reLink函数
////这里还得用到链栈
void reLink(RBTree &T, RBTNode *oldp, RBTNode *newp, LStack &p)
{
	if (isEmpty(p))
		T.root = newp;
	else
	{
		RBTNode x;
		pop(x, p);
		RBTNode *parent = &x;
		if (parent->left == oldp)
			parent->left = newp;
		else
			parent->right = newp;
		push(*parent, p);
	}
}

void insert(KeyType x, LStack p)
{

}