#include <iostream>
#include <cstdio>
#include <omp.h>
#include <ctime>

int** randmat(int M, int N);
int bin_count_ones(int n);

int main()
{		
	int M = 1000;
	int N = 1000;
	long long sum = 0;
	int** mat = randmat(M, N);

	double t = omp_get_wtime();
#pragma omp parallel for reduction(+:sum) collapse(2)
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N - 1; j++) {
			for (int k = j + 1; k < N; k++) {
				sum += bin_count_ones(mat[i][j] * mat[i][k]);
			}
		}
	}
	t = omp_get_wtime() - t;
	//std::cout << "Parallel sum:" << sum << "; time:" << t << '\n';
	std::cout << "P " << t << '\n';

	sum = 0;
	t = omp_get_wtime();
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N - 1; j++) {
			for (int k = j + 1; k < N; k++) {
				sum += bin_count_ones(mat[i][j] * mat[i][k]);
			}
		}
	}
	t = omp_get_wtime() - t;
	//std::cout << "Sequential sum:" << sum << "; time:" << t << '\n';
	std::cout << "S " << t << '\n';

	for (int i = 0; i < M; i++)
		delete[] mat[i];
	delete[] mat;
	return 0;
}

int bin_count_ones(int n) {
	int c = 0;
	for (int i = 0; i < 8 * sizeof(int); i++) {
		if ((n >> i) & 1) {
			c++;
		}
	}
	return c;
}

int** randmat(int M, int N) {
	srand(time(0));
	int** mat = new int* [M];
	for (int i = 0; i < M; i++) {
		mat[i] = new int[N];
		for (int j = 0; j < N; j++)
			mat[i][j] = rand() % 100 + 1;
	}
	return mat;
}




