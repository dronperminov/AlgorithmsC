#include "algorithms.h"

/**************************************************************/
/*                       Integer vector                       */
/**************************************************************/

// создание и пользовательское заполнение массива из size элементов
int *getVector(size_t size) {
	int *x = (int *) malloc(size * sizeof(int)); // выделяем память под массив

	// заполняем массив
	for (size_t i = 0; i < size; i++) {
		printf("Enter element %ld: ", i);
		scanf("%d", &x[i]);
	}

	return x; // возвращаем указатель
}

// создание массива из n элементов и заполнение его случайными числами
int *getRndVector(size_t size) {
	int *x = (int *) malloc(size * sizeof(int)); // выделяем память под массив

	// заполняем массив
	for (size_t i = 0; i < size; i++) {
		x[i] = -20 + rand() % 41;
		printf("Enter element %ld: %d\n", i, x[i]);
	}

	return x; // возвращаем указатель
}

int *getRndVectorInterval(size_t size, int a, int b) {
	int *x = (int *) malloc(size * sizeof(int)); // выделяем память под массив

	// заполняем массив
	for (size_t i = 0; i < size; i++) {
		x[i] = a + rand() % (b - a + 1);
		printf("Enter element %ld: %d\n", i, x[i]);
	}

	return x; // возвращаем указатель
}

// вывод на экран массива из size элементов с сообщением msg
void printVector(int *x, size_t size, const char* msg) {
	printf("%s", msg);

	for (size_t i = 0; i < size - 1; i++)
		printf("%d, ", x[i]);

	printf("%d\n", x[size - 1]);
}

// минимальное значение элементов массива
int minVector(int *x, size_t size) {
	int min = x[--size]; // считаем минимумом последний элемент

	// проходимся по всему массиву, обновляя значение минимума
	while (size--)
		if (x[size] < min)
			min = x[size];

	return min;
}

// максимальное значение элементов массива
int maxVector(int *x, size_t size) {
	int max = x[--size]; // считаем максимумом последний элемент

	// проходимся по всему массиву, обновляя значение максимума
	while (size--)
		if (x[size] > max)
			max = x[size];

	return max;
}

// k-ый максимум массива
int kmax(int *x, size_t size, int k) {
    int left = 0; 
    int right = size - 1;

    // find k-th max
    while (left < right) {
        int v = x[k - 1];
        int i = left;
        int j = right;

        do {
            while (x[i] > v)
                i++;

            while (v > x[j])
                j--;

            if (i <= j) {
                int tmp = x[i];
                x[i] = x[j];
                x[j] = tmp;
                i++;
                j--;
            }
        } while (i <= j);

        if (j < k - 1)
            left = i;

        if (k - 1 < i)
            right = j;
    }

    return x[k - 1];
}

// среднее арифметическое элементов массива
double averageVector(int *x, size_t size) {
	double sum = 0; // сумма элементов

	// прозодимся по всему массиву, накапливая сумму элементов
	for (size_t i = 0; i < size; i++)
		sum += x[i];

	return sum / size; // возвращаем среднее (сумма / размер)
}

// сумма элементов массива
int sumVector(int *x, size_t size) {
	int sum = 0;

	while (size--)
		sum += x[size];

	return sum;
}

// произведение элементов массива
long prodElements(int *x, size_t size) {
	long p = 1;

	while (size--)
		p *= x[size];

	return p;
}

// подсчёт числа элементов, равных value
int elementsNumber(int *x, size_t size, int value) {
	int count = 0; // считаем, что элементов нет

	// проходимся по всему массиву
	while (size--)
		if (x[size] == value)
			count++; // если элемент совпал с искомым, увеличиваем счётчик на 1

	return count; // возвращаем значение счётчика
}

// линейный поиск элемента равного elem (результат: номер элемента или -1, если элемента нет)
int linearSearch(int *x, size_t size, int value) {
	for (size_t i = 0; i < size; i++)
		if (x[i] == value)
			return i;

	return -1;
}

// бинарный поиск в УПОРЯДОЧЕННОМ массиве (индекс найденного или -1, если элемент не найден)
int binarySearch(int *x, size_t size, int value) {
	// если искомый элемент вне диапазона значений массива
	if (x[0] > value || x[size - 1] < value)
		return -1; // возвращаем -1

	int first = 0;
	int last = size - 1;

	while (first < last) {
		int middle = first + (last - first) / 2; // (first + last) / 2

		if (value <= x[middle])
			last = middle; // элемент в левой половине
		else
			first = middle + 1; // элемент в правой половине
	}

	return x[last] == value ? last : -1;
}

// циклический сдвиг массива на count раз в направлении direction (-1 или 1)
void cycleShift(int *x, size_t size, int count, int direction) {
	// нет смысла сдвигать на число, кратное размеру (ничего не изменится)
	if (count % size == 0)
		return;

	// определяем положение сохраняемого элемента
	int start = direction == -1 ? 0 : size - 1;

	// выполняем сдвиг count раз
	for (int k = 0; k < count; k++) {
		int tmp = x[start]; // запоминаем стартовый элемент

		// проходимся по всему массиву, сдвигая всё на 1 влево или вправо
		for (size_t i = 0; i < size - 1; i++)
			if (direction == -1)
				x[start + i] = x[start + i + 1];
			else
				x[start - i] = x[start - (i + 1)];

		x[size - 1 - start] = tmp; // возвращаем значение стартового элемента на новое место
	}
}

// перестановка элементов массива в обратном порядке
void reverseVector(int *x, size_t size) {
	for (int i = 0, j = size - 1; i < j; i++, j--) {
		int tmp = x[i];
		x[i] = x[j];
		x[j] = tmp;
	}
}

// удаление элементов равных elem из массива
void deleteElem(int *x, int *size, int elem) {
	int i = 0, j = 0;

	// проходимся по всему массиву
	while (i < *size) {
		// если элемент отличен от искомого, переписываем текущее значение в новое
		if (x[i] != elem)
			x[j++] = x[i];

		i++; // переходим к следующему элементу
	}

	*size = j; // изменяем значение размера
}

// сортировка массива методом пузырька
void bubleSort(int *x, size_t size) {
	int isSorted = 0; // флаг отсортированности, считаем, что массив не отсортирован

	while (!isSorted) {
		isSorted = 1; // считаем, что он отсортирован

		for (size_t i = 0; i < size - 1; i++) {
			if (x[i] > x[i + 1]) {
				// если что-то было не отсортировано, меняем местами
				int tmp = x[i];
				x[i] = x[i + 1];
				x[i + 1] = tmp;

				isSorted = 0; // считаем, что массив снова не отсортирован
			}
		}
	}
}

// сортировка массива методом выбора
void selectionSort(int *x, size_t size) {
	for (size_t i = 0; i < size - 2; i++) {
		int min = x[i], max = x[size - 1];
		int imin = i, imax = size - 1;

		for (size_t j = i + 1; j < size - i; j++) {
			if (x[j] < min) {
				min = x[j];
				imin = j;
			} else if (x[j] > max) {
				max = x[j];
				imax = j;
			}
		}

		x[imax] = x[size - 1 - i];
		x[imin] = x[i];
		x[i] = min;
		x[size - 1 - i] = max;
	}
}

// быстрая сортировка массива
void quick_sort(int *x, int first, int last) {
	if (last <= first)
		return;

	int left = first;
	int right = last;
	int middle = x[(last + first) / 2];

	while (left <= right) {
		while (x[left] < middle)
			left++;

		while (x[right] > middle)
			right--;

		if (left <= right) {
			int tmp = x[left];
			x[left] = x[right];
			x[right] = tmp;
			left++;
			right--;
		}
	}

	quick_sort(x, first, right);	
	quick_sort(x, left, last);
}
// удаление динамического массива
void deleteVector(int **x) {
	free(*x);
	*x = NULL;
}
