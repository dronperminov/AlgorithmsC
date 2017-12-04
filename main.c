#include <stdio.h>
#include <time.h>

#include "algorithms.h"

void vector() {
	int n = 10;

	int *x = getRndVectorInterval(n, -10, 10);
	printVector(x, n, "This is my array: ");

	int max = maxVector(x, n);
	int min = minVector(x, n);
	int sum = sumVector(x, n);
	double avg = averageVector(x, n);

	printf("Max: %d\n", max);
	printf("Min: %d\n", min);
	printf("Sum: %d\n", sum);
	printf("Avg: %lf\n", avg);

	reverseVector(x, n);
	printVector(x, n, "Reversed array: ");
	quick_sort(x, 0, n - 1);
	printVector(x, n, "Sorted array: ");

	deleteVector(&x);
}

void matrix() {
	int n = 5, m = 4;

	double **x = getRndMatrixInterval(n, m, -1, 1);
	printMatrix(x, n, m, "My matrix:");

	double max = maxMatrix(x, n, m);
	double min = minMatrix(x, n, m);

	printf("Max: %lf\n", max);
	printf("Min: %lf\n", min);

	deleteMatrix(&x, n);
}

void list() {
	int n = 5;

	ListT *list = initList();
	list = getRndListInterval(n, 0, 10);

	printList(list, "List start: ");

	addToListBegin(&list, 1);
	addToListEnd(&list, -1);

	printList(list, "List end: ");
	reverseList(&list);
	printList(list, "Reversed: ");
	sortList(&list);
	printList(list, "Sorted list: ");
	deleteListBegin(&list);
	printList(list, "Delete from begin: ");
	deleteListEnd(&list);
	printList(list, "Delete from end: ");

	int max = maxList(list);
	int min = minList(list);
	int count = sizeList(list);

	printf("Max: %d\n", max);
	printf("Min: %d\n", min);
	printf("Count: %d\n", count);

	deleteList(&list);
}

void dlist() {
	int n = 5;

	DlistT *start, *end;
	initDlist(&start, &end);

	getRndDlistInterval(&start, &end, n, 0, 10);

	printDlistForward(start, "List forward: ");
	printDlistBackward(end, "List backward: ");

	addToDlistBegin(&start, &end, 1);
	addToDlistEnd(&start, &end, -1);

	printDlistForward(start, "\nList forward: ");
	printDlistBackward(end, "List backward: ");
	reverseDlist(&start, &end);
	printDlistForward(start, "\nList reversed forward: ");
	printDlistBackward(end, "List reversed backward: ");
	sortDlist(&start, &end);
	printDlistForward(start, "\nList sorted forward: ");
	printDlistBackward(end, "List sorted backward: ");

	int max = maxDlist(start);
	int min = minDlist(start);
	int count = sizeDlist(start);

	printf("Max: %d\n", max);
	printf("Min: %d\n", min);
	printf("Count: %d\n", count);

	deleteDlist(&start, &end);
}

void tree() {
	int n = 10;
	TreeT *tree = initTree();

	int x[] = {8, 4, 2, 9, 5, 10, 1, 6, 3, 7};

	for (int i = 0; i < n; i++)
		insertToTree(&tree, x[i]);

	printf("\nKLP: ");
	printTreeKLP(tree);
	printf("\nLPK: ");
	printTreeLPK(tree);
	printf("\nLKP: ");
	printTreeLKP(tree);

	int max = maxTree(tree)->value;
	int min = minTree(tree)->value;
	int height = heightTree(tree);
	int count = countTree(tree);

	printf("\nMax: %d\n", max);
	printf("Min: %d\n", min);
	printf("Height: %d\n", height);
	printf("Count: %d\n", count);

	int key = getInteger("Enter element to find: ");
	TreeT *result = searchTree(tree, key);

	if (result)
		printf("%d", result->value);
	else
		printf("No element in tree");

	deleteTree(&tree);
}

void avl_tree() {
	AVLTreeT *tree = NULL;
	int n = 10;
	int x[] = {8, 4, 2, 9, 5, 10, 1, 6, 3, 7};

	for (int i = 0; i < n; i++)
		insertToAVLTree(&tree, x[i]);

	printf("\nAVL KLP: ");
	printAVLTreeKLP(tree);
	printf("\nAVL LPK: ");
	printAVLTreeLPK(tree);
	printf("\nAVL LKP: ");
	printAVLTreeLKP(tree);

	int max = maxAVLTree(tree)->value;
	int min = minAVLTree(tree)->value;
	int height = heightAVL(tree);
	int count = countAVLTree(tree);

	printf("\nMax: %d\n", max);
	printf("Min: %d\n", min);
	printf("Height: %d\n", height);
	printf("Count: %d\n", count);

	int key = getInteger("Enter element to find: ");
	AVLTreeT *result = searchAVLTree(tree, key);

	if (result)
		printf("%d", result->value);
	else
		printf("No element in tree");

	deleteAVLTree(&tree);
}

int main() {
	srand(time(NULL));

	vector();
	matrix();
	list();
	dlist();
	tree();
	avl_tree();
}
