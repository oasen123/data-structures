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

//˳���
void insertElem(Sqlist * const, int);
int doInsertElem(Sqlist * const, int, int);
int deleteElem(Sqlist * const, int, int * const);
void initList(Sqlist * const);
int getElem(const Sqlist * const, int, int * const);
void printList(const Sqlist *);

//������
void merge(LNode *, LNode *, LNode *);
void createlistR(LNode **, int[], int);
void createlistL(LNode **, int[], int);
int findAndDelete(LNode *, int);
void printLList(const LNode *);

//˫����
void createDlistR(DLNode **, int[], int);
DLNode * findDLNode(DLNode *, int);
DLNode * findDLPNode(DLNode *, int);
DLNode * findDLTail(DLNode *);
int getDLLength(const DLNode *);
int insertDLElem(const DLNode *, int, int);
int deleteDLPElem(DLNode *, int);
int deleteDLElem(DLNode *, int);
void printDLList(DLNode *);