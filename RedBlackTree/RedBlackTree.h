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

