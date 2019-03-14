/*
* ��������
*
* ���ߣ�HRL
* ���ڣ�20190314
* �����������Ǻ�����Ķ�����ʵ��
*
* English
*
*/
#pragma once
#include <iostream>
//#include "RBTreeLStack.h"

using namespace std;

#define TRUE 1
#define FALSE 0

#define OK 1
#define ERROR 0
//#define OVERFLOW -1

typedef int Status;

#define KeyType int

typedef struct RBTNode
{
	KeyType data;
	RBTNode *left;
	RBTNode *right;
	int colour;
}RBTNode;

struct RBTree
{
	RBTNode *root;
};

RBTNode* newRBTNode(KeyType x, RBTNode* left, RBTNode*right,int colour)
{
	RBTNode *t;
	t = (RBTNode*)malloc(sizeof(RBTNode));
	t->data = x;
	t->left = left;
	t->right = right;
	t->colour = colour;
	return t;
}

//void reLink(RBTree &T, RBTNode *oldp, RBTNode *newp, LStack &p);