#pragma once
#include <iostream>

using namespace std;

#define TRUE 1
#define FALSE 0

#define OK 1
#define ERROR 0
//#define OVERFLOW -1

typedef int Status;

#define KeyType int

struct RBTNode
{
	KeyType data;
	RBTNode *left;
	RBTNode *right;
	int colour;
};

struct RBTree
{
	RBTNode *root;
};

//reLink函数
////这里还得用到链栈
void reLink(RBTNode *oldp,RBTNode *newp)
{
	
}