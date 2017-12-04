#include "algorithms.h"

/**************************************************************/
/*                       Double matrix                        */
/**************************************************************/
// создание и пользовательское заполнение матрицы из n*m элементов
double** getMatrix(int n, int m) {
	double **x = (double **) malloc(n * sizeof(double *));

	for (int i = 0; i < n; i++) {
		x[i] = (double *) malloc(m * sizeof(double));

		for (int j = 0; j < m; j++) {
			printf("Enter element %d, %d: ", i, j);
			scanf("%lf", &x[i][j]);
		}
	}

	return x;
}

// создание матрицы из n*m элементов и заполнение её случайными числами
double** getRndMatrix(int n, int m) {
	double **x = (double **) malloc(n * sizeof(double *));

	for (int i = 0; i < n; i++) {
		x[i] = (double *) malloc(m * sizeof(double));

		for (int j = 0; j < m; j++) {
			x[i][j] = (-500 + rand() % 1001) / 10.0;
			printf("Enter element %d, %d: %lf\n", i, j, x[i][j]);
		}
	}

	return x;
}

// создание матрицы из n*m элементов и заполнение её случайными числами
double** getRndMatrixInterval(int n, int m, int a, int b) {
	double **x = (double **) malloc(n * sizeof(double *));

		for (int i = 0; i < n; i++) {
			x[i] = (double *) malloc(m * sizeof(double));

			for (int j = 0; j < m; j++) {
				x[i][j] = ((a * 10) + rand() % ((b - a) * 10 + 1)) / 10.0;
				printf("Enter element %d, %d: %lf\n", i, j, x[i][j]);
		}
	}

	return x;
}


// вывод на экран матрицы из n*m элементов с сообщением msg
void printMatrix(double **x, int n, int m, const char* msg) {
	printf("%s\n", msg);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			printf("%6.1lf", x[i][j]);

		printf("\n");
	}
}

// максимум в вещественной матрице n*m
double maxMatrix(double **x, int n, int m) {
	double max = x[0][0]; // предполагаем, что максимальный элемент в левом верхнем углу

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (max < x[i][j])
				max = x[i][j];

	return max;
}

// минимум в вещественной матрице n*m
double minMatrix(double **x, int n, int m) {
	double min = x[0][0]; // предполагаем, что минимальный элемент в левом верхнем углу

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (min > x[i][j])
				min = x[i][j];

	return min;
}

// обмен двух столбцов
void swapCols(double **x, int n, int col1, int col2) {
	for (int i = 0; i < n; i++) {
		double tmp = x[i][col1];
		x[i][col1] = x[i][col2];
		x[i][col2] = tmp;
	}
}

// обмен двух строк
void swapRows(double **x, int m, int row1, int row2) {
	for (int j = 0; j < m; j++) {
		double tmp = x[row1][j];
		x[row1][j] = x[row2][j];
		x[row2][j] = tmp;
	}
}

// освобождение динамической памяти, отведённой под матрицу
void deleteMatrix(double ***x, int n) {
	for (int i = 0; i < n; i++)
		free((*x)[i]);

	free(*x);
	*x = NULL;
}
