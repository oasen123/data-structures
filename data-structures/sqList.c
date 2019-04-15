#include <stdio.h>
#include <stdlib.h>
#include "list.h"

//返回第一个比x大的下标
int findElem(const Sqlist *list, int e) {
	int i;
	for (i = 0; i < list -> length; i++) {
		if (e < (list ->data)[i]) {
			return i;
		}
	}
	return i;
}

//插入元素。首先查找第一个比x大的下标p，然后，将顺序表中>=p的项往后移动一位
void insertElem(Sqlist * const list, int e) {
	int p, r;
	p = findElem(list, e);
	r = doInsertElem(list, p, e);
	if (!r) {
		puts("Sqlist插入失败");
	}
}

int doInsertElem(Sqlist * const list, int p, int e) {
	int i;
	if (p < 0 || p > list -> length || list -> length == maxSize)
		return 0;
	for (i = (list->length) - 1; i >= p; i--)
		(list->data)[i + 1] = (list->data)[i];
	(list->data)[p] = e;
	++(list->length);
	return 1;
}

//删除下标为p的元素，并将此元素的至赋值给e
int deleteElem(Sqlist * const list, int p, int * const e) {
	int i;
	if (p < 0 || p > list->length)
		return 0;
	*e = (list->data)[p];
	for (i = p; i < (list->length) - 1; i++)
		(list->data)[i] = (list->data)[i + 1];
	--(list->length);
	return 1;
}

//初始化顺序表
void initList(Sqlist * const list) {
	list->length = 0;
}

//获取P下标的元素赋值给e
int getElem(const Sqlist * const list, int p, int * const e) {
	if (p < 0 || p >(list->length) - 1)
		return 0;
	*e = (list->data)[p];
	return 1;
}

//打印
void printList(const Sqlist * list) {
	printf("length: %d\n", list->length);
	for (int i = 0; i < list->length; i++) {
		printf("%d\n", (list->data)[i]);
	}
}