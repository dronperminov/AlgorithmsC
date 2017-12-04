#include "algorithms.h"

AVLTreeT* initAVLTree() {
	return NULL;
}

// вставка ключа value в АВЛ дерево с корнем root
void insertToAVLTree(AVLTreeT **root, int value) {
	if (!*root) {
		// если дерево пустое, создаём новый элемент
		*root = (AVLTreeT *) malloc(sizeof(AVLTreeT));

		(*root)->value = value;
		(*root)->height = 1;
		(*root)->left = NULL;
		(*root)->right = NULL;
	} else if (value < (*root)->value)
		insertToAVLTree(&(*root)->left, value);
	else
		insertToAVLTree(&(*root)->right, value);

	balanceAVL(root);
}

// вывод бинарного дерева (корень - левое поддерево - правое поддерево)
void printAVLTreeKLP(AVLTreeT *root){
	if (root) {
		printf("%d ", root->value); // выводим значение корня
		printAVLTreeKLP(root->left); // выводим левое поддерево
		printAVLTreeKLP(root->right); // выводим правое поддерево
	}
}

// вывод бинарного дерева (левое поддерево - правое поддерево - корень)
void printAVLTreeLPK(AVLTreeT *root){
	if (root) {
		printAVLTreeLPK(root->left); // выводим левое поддерево
		printAVLTreeLPK(root->right); // выводим правое поддерево
		printf("%d ", root->value); // выводим корень
	}
}

// вывод бинарного дерева (левое поддерево - корень - правое поддерево)
void printAVLTreeLKP(AVLTreeT *root) {
	if (root) {
		printAVLTreeLKP(root->left); // выводим левое поддерево
		printf("%d ", root->value); // выводим корень
		printAVLTreeLKP(root->right); // выводим правое поддерево
	}
}

// получение высоты АВЛ дерева (или поддерева)
int heightAVL(AVLTreeT *root){
	return root ? root->height : 0;
}

// проверка на необходимость банансировки АВЛ дерева
int bfactorAVL(AVLTreeT *root){
	return heightAVL(root->right) - heightAVL(root->left);
}

// подсчёт числа элементов в АВЛ дереве
int countAVLTree(AVLTreeT *root) {
    if (!root)
        return 0;

    return countAVLTree(root->right) + countAVLTree(root->left) + 1;
}

// минимум в АВЛ дереве
AVLTreeT *minAVLTree(AVLTreeT *root) {
	if (!root)
		return NULL;

	while (root->left)
		root = root->left;

	return root;
}

// максимум в АВЛ дереве
AVLTreeT *maxAVLTree(AVLTreeT *root) {
	if (!root)
		return NULL;

	while (root->right)
		root = root->right;

	return root;
}

// поиск элемента value в АВЛ дереве
AVLTreeT *searchAVLTree(AVLTreeT *root, int value) {
	if (!root)
		return NULL;

	if (root->value == value)
		return root;

	if (value < root->value)
		return searchAVLTree(root->left, value);
	else
		return searchAVLTree(root->right, value);
}

// правый поворот вокруг root АВЛ дерева
void rotateRightAVL(AVLTreeT **root){
	AVLTreeT* tmp = (*root)->left;
	(*root)->left = tmp->right;
	tmp->right = *root;

	fixheightAVL(*root);
	fixheightAVL(tmp);

	*root = tmp;
}

// левый поворот вокруг root АВЛ дерева
void rotateLeftAVL(AVLTreeT **root){
	AVLTreeT* tmp = (*root)->right;
	(*root)->right = tmp->left;
	tmp->left = *root;

	fixheightAVL(*root);
	fixheightAVL(tmp);

	*root = tmp;
}

// балансировка узла root АВЛ дерева
void balanceAVL(AVLTreeT **root){
	fixheightAVL(*root);

	if (bfactorAVL(*root) == 2) {
		if (bfactorAVL((*root)->right) < 0)
			rotateRightAVL(&(*root)->right);

		rotateLeftAVL(root);
	} else if (bfactorAVL(*root)== -2) {
		if (bfactorAVL((*root)->left) > 0)
			rotateLeftAVL(&(*root)->left);

		rotateRightAVL(root);
	}
}

// восстанавление корректного значение поля height заданного узла АВЛ дерева
void fixheightAVL(AVLTreeT *root){
	int heightLeft = heightAVL(root->left);
	int heightRight = heightAVL(root->right);

	root->height = (heightLeft > heightRight ? heightLeft : heightRight) + 1;
}

// удаление АВЛ дерева
void deleteAVLTree(AVLTreeT **root){
	if (!*root)
		return;

	deleteAVLTree(&(*root)->left);
	deleteAVLTree(&(*root)->right);
	free(*root);

	*root = NULL;
}
