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

//查找函数
bool find(KeyType x,RBTree T)
{
	RBTNode *t = T.root;

	while (t->data != x && t != NULL)
	{
		if (t->data > x)
			t = t->left;
		else
			t = t->right;
	}

	if (NULL == t)
		return false;
	else
		return true;
}


//四个旋转函数
////左高，右旋,怎么确定失衡从而调用旋转函数？
void LL(RBTNode *t)
{
	RBTNode* t1 = t->left;
	t->left = t1->right;
	t1->right = t;
	t = t1;
}


void RR(RBTNode *t)
{
	RBTNode *t1 = t->right;
	t->right = t1->left;
	t1->left = t;
	t = t1;
}


////左高右低，先右旋再左旋
void LR(RBTNode *t)
{
	RR(t->left);
	LL(t);
}

void RL(RBTNode *t)
{
	LL(t->right);
	RR(t);
}


//reLink函数
////这里开始就得用到链栈
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


//insertRebanlance函数
void insertRebanlance(RBTNode *t,LStack &p,RBTree &L)
{
	RBTNode *parent, *grandparent, *uncle, *rootOfS;

	pop(*parent, p);
	while (parent->colour == 0)
	{
		if (parent == L.root)
		{
			parent->colour = 1;
			return;
		}
		pop(*grandparent, p);
		rootOfS = grandparent;

		if (grandparent->data > parent->data)
			uncle = parent->right;
		else
			uncle = parent->left;

		if (uncle == NULL || uncle->colour == 1)
		{
			if (grandparent->left == parent)
				if (t == parent->left)
				//
				{
					parent->colour = 1;
					grandparent->colour = 0;
					LL(grandparent);
				}
				else
				//
				{
					grandparent->colour = 0;
					t->colour = 1;
					LR(grandparent);
					
				}
			else if (t == parent->right)
			{
				parent->colour = 1;
				grandparent->colour = 0;
				RR(grandparent);
			}
			else
			{
				grandparent->colour = 0;
				t->colour = 1;
				RL(grandparent);
			}

			reLink(L,rootOfS, grandparent, p);
			return;
		}
		else
		{
			grandparent->colour = 0;
			parent->colour = 1;
			uncle->colour = 1;
			if (L.root == grandparent)
			{
				L.root->colour = 1;
				return;
			}
			t = grandparent;
			pop(*parent, p);
		}
	}

}

void insert(KeyType x, LStack &p,RBTree &L)
{
	RBTNode *t, *parent;

	if (L.root == NULL)
	{
		t = newRBTNode(x, NULL, NULL, 1);
		L.root = t;
		return;
	}	

	t = L.root;
	while (t!=NULL && t->data!=x)
	{
		push(*t, p);
		while (t->data != x && t != NULL)
		{
			if (t->data > x)
				t = t->left;
			else
				t = t->right;
		}
		if (t != NULL)
			return;

		t = newRBTNode(x, NULL, NULL, 1);
		pop(*parent, p);

		if (parent->data > x)
			parent->left = t;
		else
			parent->right = t;

		push(*parent, p);
		insertRebanlance(t, p, L);
	}
}


//removeRebanlance函数
void removeRebanlance()
{

}


//remove函数
void remove()
{

}