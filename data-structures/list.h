#ifndef LIST
#define LIST
#define maxSize 20
#endif

typedef struct {
	int data[maxSize];
	int length;
} Sqlist;

typedef struct LNode {
	int data;
	struct LNode *next;
} LNode;

typedef struct DLNode {
	int data;
	struct DLNode *prior;
	struct DLNode *next;
} DLNode;