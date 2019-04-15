#include <stdio.h>
#include <stdlib.h>
#include "list.h"

//���ص�һ����x����±�
int findElem(const Sqlist *list, int e) {
	int i;
	for (i = 0; i < list -> length; i++) {
		if (e < (list ->data)[i]) {
			return i;
		}
	}
	return i;
}

//����Ԫ�ء����Ȳ��ҵ�һ����x����±�p��Ȼ�󣬽�˳�����>=p���������ƶ�һλ
void insertElem(Sqlist * const list, int e) {
	int p, r;
	p = findElem(list, e);
	r = doInsertElem(list, p, e);
	if (!r) {
		puts("Sqlist����ʧ��");
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

//ɾ���±�Ϊp��Ԫ�أ�������Ԫ�ص�����ֵ��e
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

//��ʼ��˳���
void initList(Sqlist * const list) {
	list->length = 0;
}

//��ȡP�±��Ԫ�ظ�ֵ��e
int getElem(const Sqlist * const list, int p, int * const e) {
	if (p < 0 || p >(list->length) - 1)
		return 0;
	*e = (list->data)[p];
	return 1;
}

//��ӡ
void printList(const Sqlist * list) {
	printf("length: %d\n", list->length);
	for (int i = 0; i < list->length; i++) {
		printf("%d\n", (list->data)[i]);
	}
}