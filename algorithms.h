#ifndef ALGORITHMS_H_
#define ALGORITHMS_H_

#include <stdio.h>
#include <stdlib.h>

/************************************************************************/
/*                            Integer vector                            */
/************************************************************************/
int* getVector(size_t size);
int* getRndVector(size_t size);
int* getRndVectorInterval(size_t size, int a, int b);
void printVector(int *x, size_t size, const char* msg);

int minVector(int *x, size_t size);
int maxVector(int *x, size_t size);
int kmax(int *x, size_t size, int k);
double averageVector(int *x, size_t size);
int sumVector(int *x, size_t size);
long prodElements(int *x, size_t size);
int elementsNumber(int *x, size_t size, int value);
int linearSearch(int *x, size_t size, int value);
int binarySearch(int *x, size_t size, int value);

void cycleShift(int *x, size_t size, int count, int direction);
void reverseVector(int *x, size_t size);
void deleteElem(int *x, int *size, int elem);
void bubleSort(int *x, size_t size);
void selectionSort(int *x, size_t size);
void quick_sort(int *x, int first, int last);

void deleteVector(int **x);


/************************************************************************/
/*                            Double matrix                             */
/************************************************************************/
double** getMatrix(int n, int m);
double** getRndMatrix(int n, int m);
double** getRndMatrixInterval(int n, int m, int a, int b);
void printMatrix(double **x, int n, int m, const char* msg);

double maxMatrix(double **x, int n, int m);
double minMatrix(double **x, int n, int m);

void swapCols(double **x, int n, int col1, int col2);
void swapRows(double **x, int m, int row1, int row2);

void deleteMatrix(double ***x, int n);


/************************************************************************/
/*                             Linked list                              */
/************************************************************************/
typedef struct ListT {
	int value; // значение списка
	struct ListT *next; // ссылка на следующий элемент
} ListT;

ListT* initList();

ListT* getRndList(int n);
ListT* getRndListInterval(int n, int a, int b);
void printList(ListT *begin, const char* msg);

int minList(ListT *begin);
int maxList(ListT *begin);
int sizeList(ListT *begin);

void addToListBegin(ListT **begin, int value);
void addToListEnd(ListT **begin, int value);
void reverseList(ListT **begin);
void sortList(ListT **begin);
void deleteListBegin(ListT **begin);
void deleteListEnd(ListT **begin);

void deleteList(ListT **begin);


/************************************************************************/
/*                          Double Linked list                          */
/************************************************************************/
typedef struct DlistT {
	int value; // значение элемента
	struct DlistT *prev; // ссылка на предыдущий элемент
	struct DlistT *next; // ссылка на следующий элемент
} DlistT;

void initDlist(DlistT **begin, DlistT **end);

void getRndDlist(DlistT **begin, DlistT **end, int n);
void getRndDlistInterval(DlistT **begin, DlistT **end, int n, int a, int b);
void printDlistForward(DlistT *begin, const char* msg);
void printDlistBackward(DlistT *end, const char* msg);

int minDlist(DlistT *begin);
int maxDlist(DlistT *begin);
int sizeDlist(DlistT *begin);

void addToDlistBegin(DlistT **begin, DlistT **end, int value);
void addToDlistEnd(DlistT **begin, DlistT **end, int value);
void reverseDlist(DlistT **begin, DlistT **end);
void sortDlist(DlistT **begin, DlistT **end);

void deleteDlist(DlistT **begin, DlistT **end);


/************************************************************************/
/*                             Binary tree                              */
/************************************************************************/
typedef struct TreeT {
	int value; // значение элемента дерева

	struct TreeT *left; // левое поддерево
	struct TreeT *right; // правое поддерево
} TreeT;

TreeT* initTree();

void insertToTree(TreeT **root, int value);

void printTreeKLP(TreeT *root);
void printTreeLPK(TreeT *root);
void printTreeLKP(TreeT *root);

int heightTree(TreeT *root);
int countTree(TreeT * root);
TreeT *minTree(TreeT *root);
TreeT *maxTree(TreeT *root);
TreeT *searchTree(TreeT *root, int value);

void deleteTree(TreeT **root);


/************************************************************************/
/*                           Binary AVL-tree                            */
/************************************************************************/
typedef struct AVLTreeT {
	int value; // значение узла
	int height; // высота дерева

	struct AVLTreeT *left; // левое поддерево
	struct AVLTreeT *right; // правое поддерево
} AVLTreeT;

AVLTreeT* initAVLTree();

void insertToAVLTree(AVLTreeT **tree, int value);

void printAVLTreeKLP(AVLTreeT *root);
void printAVLTreeLPK(AVLTreeT *root);
void printAVLTreeLKP(AVLTreeT *root);

int heightAVL(AVLTreeT* tree);
int bfactorAVL(AVLTreeT* tree);
int countAVLTree(AVLTreeT * root);
AVLTreeT *minAVLTree(AVLTreeT *root);
AVLTreeT *maxAVLTree(AVLTreeT *root);
AVLTreeT *searchAVLTree(AVLTreeT *root, int value);

void rotateRightAVL(AVLTreeT **tree);
void rotateLeftAVL(AVLTreeT **tree);
void balanceAVL(AVLTreeT **tree);
void fixheightAVL(AVLTreeT* tree);

void deleteAVLTree(AVLTreeT **root);

/************************************************************************/
/*                               Functions                              */
/************************************************************************/
int getInteger(const char* msg);
int getIntegerInterval(int a, int b, const char* msg);
double getDouble(const char* msg);
double getDoubleInterval(double a, double b, const char* msg);

long gcd(long a, long b);
long lcm(long a, long b);
long fastPow(long x, unsigned int n);

int isPrime(long a);

#endif
