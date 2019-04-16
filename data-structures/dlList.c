#include <stdio.h>
#include <stdlib.h>
#include "list.h"

//创建双链表
void createDlistR(DLNode **L, int a[], int n) {
	int i;
	DLNode *s, *r;
	*L = (DLNode *)malloc(sizeof(DLNode));
	(*L)->prior = NULL;
	(*L)->next = NULL;
	r = *L;

	for (i = 0; i < n; i++) {
		s = (DLNode *)malloc(sizeof(DLNode));
		s->data = a[i];
		s->prior = r;
		r->next = s;
		r = s;
	}

	r->next = NULL;
}

//查找双链表红元素值为x的节点指针
DLNode * findDLNode(DLNode *C, int x) {
	DLNode *p = C->next;

	while (p != NULL) {
		if (x == p->data)
			break;
		p = p->next;
	}

	return p;
}

//查找双链表p位置的节点指针
DLNode * findDLPNode(DLNode *C, int p) {
	int i = 0;
	DLNode *r = C->next;

	while (r != NULL) {
		if (p == i++)
			break;
		r = r->next;
	}

	return r;
}

//获取双链表的尾节点,这里把只有头结点的链表也算作尾节点
DLNode * findDLTail(DLNode *C) {
	DLNode *r;
	r = C;

	while (r->next != NULL)
		r = r->next;

	return r;
}

//获取双链表的长度
int getDLLength(const DLNode *C) {
	int i = 0;
	DLNode *p = C->next;

	while (p != NULL) {
		i++;
		p = p->next;
	}
	return i;
}

//向双链表p位置插入一个节点
int insertDLElem(const DLNode *C,int p, int x) {
	int len;
	DLNode *s, *r;
	
	len = getDLLength(C);
	if (p < 0 || p > len) //p > len考虑在尾部插入
		return 0;

	s = (DLNode *)malloc(sizeof(DLNode));
	s->data = x;
	r = findDLPNode(C, p);
	if (r == NULL) {
		r = findDLTail(C);
	} else {
		r = r->prior;
		r->next->prior = s;
	}
	s->prior = r;
	s->next = r->next;
	r->next = s;
	return 1;
}

//删除双链表P位置的节点
int deleteDLPElem(DLNode *C, int p) {
	DLNode *r, *q;

	q = findDLPNode(C, p);
	if (q == NULL)
		return 0;

	r = q->prior;
	r->next = q->next;
	if (q->next)
		q->next->prior = r;
	free(q);
	return 1;
}

//删除双链表值为X的节点
int deleteDLElem(DLNode *C, int x) {
	DLNode *p, *q;

	q = findDLNode(C, x);
	if (q == NULL)
		return 0;

	p = q->prior;
	p->next = q->next;
	if (q->next)
		q->next->prior = p;
	free(q);
	return 1;
}

//打印双链表
void printDLList(DLNode *C) {
	DLNode *p = C->next;
	printf("%s", "DLLIST: [");
	while (p != NULL) {
		printf("%d", p->data);
		if (p->next) {
			printf("%s",",");
		}
		p = p->next;
	}
	printf("%s\n", "]");
}

