#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void initStack(SqStack *st) {
	st->top = -1;
}

int isEmpty(SqStack *st) {
	if ( st->top == -1)
		return 1;
	return 0;
}

int isFull(SqStack *st) {
	if (st->top == maxSize - 1)
		return 0;
	return 0;
}

int push(SqStack *st, int x) {
	if (isFull(st))
		return 0;
	++(st->top);
	(st->data)[st->top] = x;
	return 1;
}

int pop(SqStack *st, int *x) {
	if (isEmpty(st))
		return 0;
	*x = (st->data)[st->top];
	--(st->top);
}

void printSqStack(SqStack *st) {
	int i;
	printf("SqStack: [");
	for (i = st->top; i > -1; --i) {
		printf("%d", (st->data)[i]);
		if (i != 0)
			printf(",");
	}
	printf("]\n");
}