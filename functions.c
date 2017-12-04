#include "algorithms.h"

// получение целого числа с проверкой на некорректный ввод
int getInteger(const char *msg) {
	char answer[256];
	int n;

	printf("%s", msg);
	fgets(answer, sizeof(answer), stdin);

	while (sscanf(answer, "%d", &n) != 1) {
		printf("Incorrect input. Try again: ");
		fgets(answer, sizeof(answer), stdin);
	}

	return n;
}

// получение целого числа из интервала [a, b] с проверкой на некорректный ввод
int getIntegerInterval(int a, int b, const char *msg) {
	char answer[256];
	int n;

	printf("%s", msg);
	fgets(answer, sizeof(answer), stdin);

	while (sscanf(answer, "%d", &n) != 1 || n < a || n > b) {
		printf("Incorrect input. Try again: ");
		fgets(answer, sizeof(answer), stdin);
	}

	return n;
}

// получение вещественного числа с проверкой на некорректный ввод
double getDouble(const char *msg) {
	char answer[256];
	double x;

	printf("%s", msg);
	fgets(answer, sizeof(answer), stdin);

	while (sscanf(answer, "%lf", &x) != 1) {
		printf("Incorrect input. Try again: ");
		fgets(answer, sizeof(answer), stdin);
	}

	return x;
}

// получение вещественного числа из интервала [a, b] с проверкой на некорректный ввод
double getDoubleInterval(double a, double b, const char *msg) {
	char answer[256];
	double x;

	printf("%s", msg);
	fgets(answer, sizeof(answer), stdin);

	while (sscanf(answer, "%lf", &x) != 1 || x < a || x > b) {
		printf("Incorrect input. Try again: ");
		fgets(answer, sizeof(answer), stdin);
	}

	return x;
}


// наибольший общий делитель (НОД) - алгоритм Евклида
long gcd (long a, long b) {
	return b ? gcd (b, a % b) : a;
}

// наименьшее общее кратное
long lcm(long a, long b) {
	long p = a * b;

	while (b) {
		long t = b;
		b = a % b;
		a = t;
	}

	return p / a;
}

// быстрое возведение в степень: O(log n)
long fastPow(long x, unsigned int n) {
	if (n == 0)
		return 1;

	if (n % 2)
		return x * fastPow(x, n - 1);

	long tmp = fastPow(x, n / 2);
	return tmp * tmp;
}

// проверка числа на простоту
int isPrime(long n) {
	for (int i = 2; i < n; i+= 3)
		if (n % i == 0)
			return 1;

	return 0;
}
