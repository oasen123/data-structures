#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(void) {
	//Ë³Ðò±í
	//Sqlist *list = (Sqlist *)malloc(sizeof(Sqlist));
	//initList(list);
	//insertElem(list, 2);
	//insertElem(list, 8);
	//insertElem(list, 5);
	//insertElem(list, 3);
	//int a;
	//deleteElem(list, 2, &a);
	//printf("after deleteElem a: %d\n", a);
	//getElem(list, 2, &a);
	//printf("after getElem a: %d\n", a);
	//puts("print list:");
	//printList(list);
	//free(list);

	//µ¥Á´±í
	int a[3] = { 1,4,6 };
	int b[3] = { 2,5,7 };
	LNode c;
	LNode *cl = &c;
	LNode **cll = &cl;
	createlistR(cll, a, 3);
	printLList(*cll);
	LNode d;
	LNode *dl = &d;
	LNode **dll = &dl;
	createlistR(dll, b, 3);
	printLList(*dll);
	LNode e;
	LNode *el = &e;
	LNode **ell = &el;
	merge(*cll, *dll, ell);
	printLList(*ell);
	findAndDelete(*ell, 4);
	printLList(*ell);

	getchar();
}