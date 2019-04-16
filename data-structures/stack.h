#pragma once
#define maxSize 20

typedef struct {
	int data[maxSize];
	int top;
} SqStack;

typedef struct SNode {
	int data;
	struct SNode *next;
} SNode;

void initStack(SqStack *st);
int isEmpty(SqStack *st);
int isFull(SqStack *st);
int push(SqStack *st, int x);
int pop(SqStack *st, int *x);
void printSqStack(SqStack *st);