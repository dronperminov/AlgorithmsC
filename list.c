/***************************************************************/
/*                         Linked list                         */
/***************************************************************/

#include "algorithms.h"

// инициализация односвязного списка
ListT* initList() {
	return NULL;
}

// получение односвязного списка из n элементов - случайных чисел
ListT *getRndList(int n) {
	ListT *begin = NULL;

	for (int i = 0; i < n; i++) {
		ListT *elem = (ListT *) malloc(sizeof(ListT));

		elem->value = rand() % 21 - 10;
		elem->next = begin;
		begin = elem;
	}

	return begin;
}

// получение односвязного списка из n элементов - случайных чисел
ListT *getRndListInterval(int n, int a, int b) {
	ListT *begin = NULL;

	for (int i = 0; i < n; i++) {
		ListT *elem = (ListT *) malloc(sizeof(ListT));

		elem->value = a + rand() % (b - a + 1);
		elem->next = begin;
		begin = elem;
	}

	return begin;
}

// вывод односвязного списка на экран с сообщением msg
void printList(ListT *begin, const char* msg) {
	printf("%s", msg);

	if (!begin) {
		printf("empty");
		return;
	}

	while (begin) {
		printf("|%d|->", begin->value);
		begin = begin->next;
	}

	printf("NULL\n");
}

// минимальный элемент списка
int minList(ListT *begin) {
	if (!begin) {
		printf("List is empty\n");
		return 0;
	}

	int min = begin->value;

	while (begin->next) {
		begin = begin->next;

		if (min > begin->value)
			min = begin->value;
	}

	return min;
}

// максимальный элемент списка
int maxList(ListT *begin) {
	if (!begin) {
		printf("List is empty\n");
		return 0;
	}

	int max = begin->value;

	while (begin->next) {
		begin = begin->next;

		if (max < begin->value)
			max = begin->value;
	}

	return max;
}

// число элеменов односвязного списка
int sizeList(ListT *begin) {
	int count = 0;

	while (begin) {
		count++;
		begin = begin->next;
	}

	return count;
}

// добавление элемента в начало списка
void addToListBegin(ListT **begin, int value) {
	ListT *elem = (ListT *) malloc(sizeof(ListT));

	elem->value = value;
	elem->next = *begin;
	*begin = elem;
}

// добавление элемента в конец списка
void addToListEnd(ListT **begin, int value) {
	ListT *elem = (ListT *) malloc(sizeof(ListT));

	elem->value = value;
	elem->next = NULL;

	if (!*begin)
		*begin = elem;
	else {
		ListT *tmp = *begin;

		while (tmp->next)
			tmp = tmp->next;

		tmp->next = elem;
	}
}

// перестановка односвязного списка в обратном порядке
void reverseList(ListT **begin) {
	if (!*begin)
		return;

	ListT *current = *begin;

	while (current->next) {
		ListT *tmp = current->next;
		current->next = tmp->next;
		tmp->next = *begin;
		*begin = tmp;
	}
}

// сортировка односвязного списка
void sortList(ListT **begin) {
	int isSorted = 0;

	while (!isSorted) {
		isSorted = 1;

		ListT *pred = NULL;
		ListT *start = *begin;

		while (start->next) {
			if (start->value > start->next->value) {
				ListT *next = start->next;
				start->next = next->next;
				next->next = start;

				if (start == *begin)
					*begin = next;
				else {
					pred->next = next;
					start = next;
				}

				isSorted = 0;
			}

			pred = start;
			start = start->next;
		}
	}
}

// удаление первого элемента списка
void deleteListBegin(ListT **begin) {
	if (!*begin)
		return;

	ListT *tmp = *begin;
	*begin = (*begin)->next;
	free(tmp);
}

void deleteListEnd(ListT **begin) {
	if (!*begin)
		return;

	if ((*begin)->next == NULL) {
		free(*begin);
		*begin = NULL;
		return;
	}

	ListT *tmp = *begin;
	while (tmp->next->next)
		tmp = tmp->next;

	free(tmp->next);
	tmp->next = NULL;
}

// удаление односвязного списка
void deleteList(ListT **begin) {
	while (*begin) {
		ListT *tmp = *begin;
		*begin = (*begin)->next;
		free(tmp);
	}

	*begin = NULL;
}
