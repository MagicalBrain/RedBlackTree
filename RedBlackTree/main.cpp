#include <iostream>
#include "RedBlackTree.h"
#include "RBTreeLStack.h"

using namespace std;


//reLink����
////���ﻹ���õ���ջ
void reLink(RBTree &T, RBTNode *oldp, RBTNode *newp, LStack &p)
{
	if (isEmpty(p))
		T.root = newp;
	else
	{
		RBTNode x;
		pop(x,p);
		RBTNode *parent = &x;
		if (parent->left == oldp)
			parent->left = newp;
		else
			parent->right = newp;
		push(*parent, p);
	}
}


int main()
{
	return 0;
}