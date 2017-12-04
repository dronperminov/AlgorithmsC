#include "algorithms.h"

// инициализация пустого дерева
TreeT* initTree() {
	return NULL;
}

// добавление элемента в дерево (одинаковые элементы игнорируются)
void insertToTree(TreeT **root, int value) {
	if (!*root) {
		// если дерево пустое, создаём новый элемент
		*root = (TreeT *) malloc(sizeof(TreeT));

		(*root)->value = value;
		(*root)->left = NULL;
		(*root)->right = NULL;
	} else if (value < (*root)->value)
		insertToTree(&(*root)->left, value); // если дерево существует и вставляем элемент меньший значения корня, вставляем в левое поддерево
	else
		insertToTree(&(*root)->right, value); // иначе вставляем в правое поддерево
}

// вывод бинарного дерева (корень - левое поддерево - правое поддерево)
void printTreeKLP(TreeT *root) {
	if (root) {
		printf("%d ", root->value); // выводим значение корня
		printTreeKLP(root->left); // выводим левое поддерево
		printTreeKLP(root->right); // выводим правое поддерево
	}
}

// вывод бинарного дерева (левое поддерево - правое поддерево - корень)
void printTreeLPK(TreeT *root) {
	if (root) {
		printTreeLPK(root->left); // выводим левое поддерево
		printTreeLPK(root->right); // выводим правое поддерево
		printf("%d ", root->value); // выводим корень
	}
}

// вывод бинарного дерева (левое поддерево - корень - правое поддерево)
void printTreeLKP(TreeT *root) {
	if (root) {
		printTreeLKP(root->left); // выводим левое поддерево
		printf("%d ", root->value); // выводим корень
		printTreeLKP(root->right); // выводим правое поддерево
	}
}

// высота дерева
int heightTree(TreeT *root) {
    if(!root)
        return 0; // высота пустого дерева равна нулю

    int left =  heightTree(root->left); // считаем высоту левого поддерева
    int right = heightTree(root->right); // считаем высоту правого поддерева

    return 1 + (left > right ? left : right);

}

// подсчёт числа элементов в дереве
int countTree(TreeT * root) {
    if (!root)
        return 0;

    return countTree(root->right) + countTree(root->left) + 1;
}

// минимальный элемент дерева
TreeT *minTree(TreeT *root) {
	if (!root)
		return NULL;

	while (root->left)
		root = root->left;

	return root;
}

// максимальный элемент дерева
TreeT *maxTree(TreeT *root) {
	if (!root)
		return NULL;

	while (root->right)
		root = root->right;

	return root;
}

// поиск в двоичном дереве
TreeT *searchTree(TreeT *root, int value) {
	if (!root)
		return NULL;

	if (value == root->value)
		return root;

	if (value < root->value)
		return searchTree(root->left, value);
	else
		return searchTree(root->right, value);
}

// удаление дерева
void deleteTree(TreeT **root) {
	if (!*root)
		return;

	deleteTree(&(*root)->left);
	deleteTree(&(*root)->right);
	free(*root);

	*root = NULL;
}
