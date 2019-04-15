#include <stdio.h>
#include <stdlib.h>
#include "list.h"

//合并A和B，入C
void merge(LNode *A, LNode *B, LNode **C) {
	LNode *p = A->next;
	LNode *q = B->next;

	LNode *r;
	*C = A;
	(*C)->next = NULL;
	free(B);
	r = *C;

	while (p != NULL && q != NULL) {
		if (p->data <= q->data) {
			r->next = p;
			p = p->next;
			r = r->next;
		}
		else {
			r->next = q;
			q = q->next;
			r = r->next;
		}
	}

	r->next = NULL;

	if(p != NULL)
		r->next = p;
	if (q != NULL)
		r->next = q;
}

void createlistR(LNode **C, int a[], int n) {
	LNode *s, *r;
	int i;
	*C = (LNode *)malloc(sizeof(LNode));
	(*C)->next = NULL;
	r = *C;
	for (i = 0; i < n; i++) {
		s = (LNode *)malloc(sizeof(LNode));
		s->data = a[i];
		r->next = s;
		r = r->next;
	}
	r->next = NULL;
}

void createlistL(LNode **C, int a[], int n) {
	LNode *s;
	int i;
	*C = (LNode *)malloc(sizeof(LNode));
	(*C)->next = NULL;
	for (i = 0; i < n; i++) {
		s = (LNode *)malloc(sizeof(LNode));
		s->data = a[i];
		s->next = (*C)->next;
		(*C)->next = s;
	}
}

int findAndDelete(LNode *C, int x) {
	LNode *p, *q;
	p = C;

	while (p->next != NULL) {
		if (p->next->data == x)
			break;
		p = p->next;
	}

	if (p->next == NULL)
		return 0;
	else {
		q = p->next;
		p->next = p->next->next;
		free(q);
		return 1;
	}
}

void printLList(const LNode * list) {
	while (list->next != NULL) {
		printf("%d\n", list->next->data);
		list = list->next;
	}
	puts("");
}