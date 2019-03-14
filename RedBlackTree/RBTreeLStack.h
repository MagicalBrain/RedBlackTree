#pragma once
#include <iostream>
#include "RedBlackTree.h"

using namespace std;

#define ElemType char

#define TRUE 1
#define FALSE 0

#define OK 1
#define ERROR 0
//#define OVERFLOW -1

//typedef int Status;

//链栈结点定义
typedef struct LSNode
{
	RBTNode data;
	LSNode *next;
}LSNode;

//链栈定义
typedef struct
{
	LSNode *elem;
	LSNode *top;
	int size;
}LStack;


//
Status InitLStack(LStack &L)
{
	L.elem = NULL;
	L.top = NULL;
	L.size = 0;
	return OK;
}


//判空函数
Status isEmpty(LStack L)
{
	if (L.elem == NULL)
		return TRUE;
	else
		return FALSE;
}


//入栈
Status push(RBTNode e, LStack &L)
{
	if (isEmpty(L))
	{
		L.elem = (LSNode*)malloc(sizeof(LSNode));
		if (L.elem == NULL)
			return OVERFLOW;
		L.elem->data = e;
		L.elem->next = NULL;
		L.top = L.elem->next;
		L.size++;
		return OK;
	}
	else
	{
		LSNode *p = L.elem;
		while (p->next != L.top)
			p = p->next;
		LSNode *q = (LSNode*)malloc(sizeof(LSNode));
		if (q == NULL)
			return OVERFLOW;
		q->data = e;
		q->next = p->next;
		p->next = q;
		L.top = q->next;
		L.size++;
		return OK;
	}
}

//出栈
Status pop(RBTNode &x, LStack &L)
{
	if (isEmpty(L))
		return FALSE;

	LSNode *p = L.elem;
	LSNode*q = p;
	while (p->next != L.top)
	{
		q = p;
		p = p->next;
	}
	q->next = L.top;
	//p->next = q->next;
	x = p->data;
	free(p);
	L.top = q->next;
	L.size--;
	return OK;
}


//链栈的销毁

//链栈的输出函数
void LStackoutput(LStack L)
{
	RBTNode x;
	while (L.size != 0)
	{
		pop(x, L);
		cout << x.data << endl;
	}

}
