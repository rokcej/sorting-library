#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "test.h"
#include "quicksort.h"
#include "merge_sort.h"
#include "heapsort.h"
#include "shellsort.h"
#include "insertion_sort.h"
#include "selection_sort.h"
#include "gnome_sort.h"
#include "cocktail_shaker_sort.h"
#include "bubble_sort.h"
#include "bogosort.h"

int main() {
	/* Array of algorithms to be tested
	 * Structure: { algorithm name, pointer to the algorithm function }
	 * To test additional sorting algorithms,
	 * simply add a new struct to the array
	 */
	alg algorithms[] = {
		{ 1, "Quicksort", quicksort },
		{ 1, "Merge sort", merge_sort },
		{ 1, "Heapsort", heapsort },
		{ 1, "Shellsort", shellsort },
		{ 1, "Insertion sort", insertion_sort },
		{ 1, "Selection sort", selection_sort },
		{ 1, "Gnome sort", gnome_sort },
		{ 1, "Cocktail shaker sort", cocktail_shaker_sort },
		{ 1, "Bubble sort", bubble_sort },
		{ 0, "Bogosort", bogosort } // Too slow!
	};

	// Comparator
	cmp_t cmp = cmp_asc;
	// Total number of sorting algorithms
	int num_algorithms = sizeof(algorithms) / sizeof(*algorithms);
	// Size of the array to test the sorting algorithms on
	int n;
	printf("Enter n: ");
	if (scanf("%d", &n) == 1 && n >= 1) { // Valid input
		printf("\n");
		run_tests(algorithms, num_algorithms, n, cmp);
	} else { // Invalid input
		printf(COLOR_RED "Error: invalid input.\n" COLOR_RESET);
	}
	return 0;
}



// Sorting comparator functions
int cmp_asc(int x, int y) { // Ascending
	return x <= y;
}
int cmp_desc(int x, int y) { // Descending
	return x >= y;
}

// Tests sorting algorithms and prints the results
void run_tests(alg *algs, int num_algs, int n, cmp_t cmp) {
	int *a_raw = generate_array(n); // Generates an array of n random elements
	int *a = (int*)malloc(n * sizeof(int)); // This is the working array
	for (int i = 0; i < num_algs; i++) {
		if (algs[i].use) {
			res result;
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
int *generate_array(int n) {
	int *a = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
		a[i] = i + 1;
	shuffle_array(a, n);
	return a;
}
// Randomly permute an array of n elements
void shuffle_array(int *a, int n) {
	srand(time(NULL)); // Time as the RNG seed
	for (int i = 0; i < n - 1; i++) {
		int r = (rand() % (n-i)) + i;
		if (i != r)
			swap(a+i, a+r);
	}
}
// Copies array a_in onto array a_out
int *copy_array(int *a_in, int *a_out, int n) {
	for (int i = 0; i < n; i++)
		a_out[i] = a_in[i];
}
// Times the execution time of a sorting function f on an array a of length n
float measure_time(int *a, int n, cmp_t cmp, func_t func) {
	clock_t start = clock();

	func(a, n, cmp);

	clock_t stop = clock();
	double average_time = (double)(stop - start) / (double)CLOCKS_PER_SEC;
	return (float)average_time;
}
// Check if a is sorted
int is_sorted(int *a, int n, cmp_t cmp) {
	for (int i = 0; i < n-1; i++) {
		if (!cmp(a[i], a[i+1]))
			return 0;
	}
	return 1;
}
// Prints test results
void print_result(res *res) {
	if (res->sorted)
		printf("Sorted: " COLOR_GREEN "TRUE" COLOR_RESET "\n");
	else
		printf("Sorted: " COLOR_RED "FALSE" COLOR_RESET "\n");
	printf("Time: %lf seconds\n", res->exec_time);
}
// Swap two integers
void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}
