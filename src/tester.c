#include "tester.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ANSI escape codes to color the console output
#define COLOR_RED		"\x1b[91m"
#define COLOR_GREEN		"\x1b[92m"
#define COLOR_CYAN		"\x1b[96m"
#define COLOR_RESET		"\x1b[0m"

// Private function declarations
static int *generate_array(int n);
static void shuffle_array(int *a, int n);
static void swap(int *x, int *y);
static int *copy_array(int *a_in, int *a_out, int n);
static float measure_time(int *a, int n, cmp_t cmp, func_t func);
static int is_sorted(int *a, int n, cmp_t cmp);
static void print_result(Res *res);

// Tests sorting algorithms and prints the results
void tester(Alg *algs, int num_algs, int n, cmp_t cmp) {
	int *a_raw = generate_array(n); // Generates an array of n random elements
	int *a = (int*)malloc(n * sizeof(int)); // This is the working array
	for (int i = 0; i < num_algs; i++) {
		if (algs[i].use) {
			Res result;
			copy_array(a_raw, a, n); // Copy original array onto working array

			printf(COLOR_CYAN "%s\n" COLOR_RESET, algs[i].name);
			result.exec_time = measure_time(a, n, cmp, algs[i].func);
			result.sorted = is_sorted(a, n, cmp);
			print_result(&result);

			if (i < num_algs - 1)
				printf("\n");
		}
	}
	free(a_raw);
	free(a);
}

// Generate a random permutation of numbers from 1 to n (inclusive)
static int *generate_array(int n) {
	int *a = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
		a[i] = i + 1;
	shuffle_array(a, n);
	return a;
}
// Randomly permute an array of n elements
static void shuffle_array(int *a, int n) {
	srand(time(NULL)); // Time as the RNG seed
	for (int i = 0; i < n - 1; i++) {
		int r = (rand() % (n-i)) + i;
		if (i != r)
			swap(a+i, a+r);
	}
}
// Copies array a_in onto array a_out
static int *copy_array(int *a_in, int *a_out, int n) {
	for (int i = 0; i < n; i++)
		a_out[i] = a_in[i];
}
// Times the execution time of a sorting function f on an array a of length n
static float measure_time(int *a, int n, cmp_t cmp, func_t func) {
	clock_t start = clock();

	func(a, n, cmp);

	clock_t stop = clock();
	double average_time = (double)(stop - start) / (double)CLOCKS_PER_SEC;
	return (float)average_time;
}
// Check if a is sorted
static int is_sorted(int *a, int n, cmp_t cmp) {
	for (int i = 0; i < n-1; i++) {
		if (!cmp(a[i], a[i+1]))
			return 0;
	}
	return 1;
}
// Prints test results
static void print_result(Res *res) {
	if (res->sorted)
		printf("Sorted: " COLOR_GREEN "TRUE" COLOR_RESET "\n");
	else
		printf("Sorted: " COLOR_RED "FALSE" COLOR_RESET "\n");
	printf("Time: %lf seconds\n", res->exec_time);
}
// Swap two integers
static void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}
