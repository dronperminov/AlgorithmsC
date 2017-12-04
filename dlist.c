#include "algorithms.h"

// инициализация двусвязного списка
void initDlist(DlistT **begin, DlistT **end) {
	*begin = NULL;
	*end = NULL;
}

// получение двусвязного списка из n элементов
void getRndDlist(DlistT **begin, DlistT **end, int n) {
	*begin = NULL;
	*end = NULL;

	for (int i = 0; i < n; i++) {
		DlistT *elem = (DlistT *) malloc(sizeof(DlistT));

		elem->value = -10 + rand() % 21;
		elem->next = NULL;
		elem->prev = NULL;

		if (*end == NULL)
			*end = elem;
		else {
			elem->prev = *end;
			(*end)->next = elem;
			*end = elem;
		}

		if (*begin == NULL)
			*begin = elem;
	}
}

// получение двусвязного списка из n элементов с элементами из интервала [a, b]
void getRndDlistInterval(DlistT **begin, DlistT **end, int n, int a, int b) {
	*begin = NULL;
	*end = NULL;

	for (int i = 0; i < n; i++) {
		DlistT *elem = (DlistT *) malloc(sizeof(DlistT));

		elem->value = a + rand() % (b - a + 1);
		elem->next = NULL;
		elem->prev = NULL;

		if (*end == NULL)
			*end = elem;
		else {
			elem->prev = *end;
			(*end)->next = elem;
			*end = elem;
		}

		if (*begin == NULL)
			*begin = elem;
	}
}

// вывод двусвязного списка на экран в прямом порядке с сообщением msg
void printDlistForward(DlistT *begin, const char* msg) {
	printf("%s", msg);

	if (!begin) {
		printf("empty");
		return;
	}

	while (begin) {
		printf("|%d|<=>", begin->value);
		begin = begin->next;
	}

	printf("NULL\n");
}

// вывод двусвязного списка на экран в обратном порядке с сообщением msg
void printDlistBackward(DlistT *end, const char* msg) {
	printf("%s", msg);

	if (!end) {
		printf("empty");
		return;
	}

	while (end) {
		printf("|%d|<=>", end->value);
		end = end->prev;
	}

	printf("NULL\n");
}

// минимальный элемент списка
int minDlist(DlistT *begin) {
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
int maxDlist(DlistT *begin) {
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

// число элементов двусвязного списка
int sizeDlist(DlistT *begin) {
	int count = 0;

	while (begin) {
		count++;
		begin = begin->next;
	}

	return count;
}


// добавление элемента в начало двусвязного списка
void addToDlistBegin(DlistT **begin, DlistT **end, int value) {
	DlistT *elem = (DlistT *) malloc(sizeof(DlistT));

	elem->value = value;
	elem->next = NULL;
	elem->prev = NULL;

	if (*begin == NULL)
		*begin = elem;
	else {
		elem->next = *begin;
		(*begin)->prev = elem;
		*begin = elem;
	}

	if (*end == NULL)
		*end = elem;
}

// добавление элемента в начало двусвязного списка
void addToDlistEnd(DlistT **begin, DlistT **end, int value) {
	DlistT *elem = (DlistT *) malloc(sizeof(DlistT));

	elem->value = value;
	elem->next = NULL;
	elem->prev = NULL;

	if (*end == NULL)
		*end = elem;
	else {
		elem->prev = *end;
		(*end)->next = elem;
		*end = elem;
	}

	if (*begin == NULL)
		*begin = elem;
}

// перестановка двусвязного списка в обратном порядке
void reverseDlist(DlistT **begin, DlistT **end) {
	DlistT *start = *begin, *finish = *end;

	while (start != finish && start->next != finish) {
		DlistT *next1 = start->next;
		DlistT *prev1 = start->prev;

		DlistT *next2 = finish->next;
		DlistT *prev2 = finish->prev;

		if (next2)
			next2->prev = start;
		else
			*begin = finish;

		if (prev1)
			prev1->next = finish;
		else
			*end = start;

		next1->prev = finish;
		prev2->next = start;

		start->next = next2;
		start->prev = prev2;
		finish->next = next1;
		finish->prev = prev1;

		start = next1;
		finish = prev2;
	}
}

// сортировка двусвязного списка
void sortDlist(DlistT **begin, DlistT **end) {
	int isSorted = 0;

	while (!isSorted) {
		isSorted = 1;

		DlistT *start = *begin;

		while (start->next) {
			DlistT *l1 = start;
			DlistT *l2 = start->next;

			if (l1->value > l2->value) {
				DlistT *prev = l1->prev, *next = l2->next;

				l2->prev = prev;
				l2->next = l1;
				l1->prev = l2;
				l1->next = next;

				if (l1 == *begin) {
					*begin = l2;
					next->prev = l1;
				}
				else if (l2 == *end) {
					*end = l1;
					prev->next = l2;
				}
				else {
					prev->next = l2;
					next->prev = l1;
				}

				isSorted = 0;
			}
			else
				start = start->next;
		}
	}
}

// удаление двусвязного списка
void deleteDlist(DlistT **begin, DlistT **end) {
	while (*begin) {
		DlistT *tmp = *begin;
		*begin = (*begin)->next;
		free(tmp);
	}

	*end = NULL;
}
