#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "test.h"
#include "heapsort.h"
#include "selection_sort.h"
#include "insertion_sort.h"
#include "cocktail_shaker_sort.h"
#include "bubble_sort.h"
#include "bogosort.h"

int main() {
	/* Array of algorithms to be tested
	 * Structure: { algorithm name, pointer to the algorithm function }
	 * To test additional sorting algorithms,
	 *  simply add a new struct to the array
	 */
	alg algorithms[] = {
		{ "Heapsort", heapsort },
		{ "Selection sort", selection_sort },
		{ "Insertion sort", insertion_sort },
		{ "Cocktail shaker sort", cocktail_shaker_sort },
		{ "Bubble sort", bubble_sort },
		{ "Bogosort", bogosort }
	};

	// Number of sorting algorithms to be tested
	int num_algorithms = sizeof(algorithms) / sizeof(*algorithms);
	// Size of the array to test the sorting algorithms on
	int n;
	printf("Enter n: ");
	if (scanf("%d", &n) == 1 && n >= 1) { // Valid input
		printf("\n");
		run_tests(algorithms, num_algorithms, n);
	} else { // Invalid input
		printf(COLOR_RED "Error: invalid input.\n" COLOR_RESET);
	}
	return 0;
}



// Tests sorting algorithms and prints the results
static void run_tests(alg *algs, int num_algs, int n) {
	int *a_raw = generate_array(n); // Generates an array of n random elements
	int *a = allocate_array(n); // This is the working array
	res *results = (res*)malloc(num_algs * sizeof(res));
	for (int i = 0; i < num_algs; i++) {
		copy_array(a_raw, a, n); // Copy original array onto working array
		printf(COLOR_CYAN "%s\n" COLOR_RESET, algs[i].name);

		results[i].exec_time = measure_time(a, n, algs[i].f);
		results[i].sorted = is_sorted(a, n);

		print_result(results+i);
		if (i < num_algs - 1)
			printf("\n");
	}
	free(a_raw);
	free(a);
	free(results);
}
// Allocate an array of n elements
static int *allocate_array(int n) {
	return (int*)malloc(n * sizeof(int));
}
// Generate an array of n random numbers on the interval [1, n]
static int *generate_array(int n) {
	srand(time(NULL)); // Time as the RNG seed
	int *a = allocate_array(n);
	for (int i = 0; i < n; i++)
		a[i] = (rand() % n) + 1;
	return a;
}
// Copies array a_in onto array a_out
static int *copy_array(int *a_in, int *a_out, int n) {
	for (int i = 0; i < n; i++)
		a_out[i] = a_in[i];
}
// Times the execution time of a sorting function f on an array a of length n
static float measure_time(int *a, int n, void (*f)(int*, int)) {
	clock_t start = clock();

	f(a, n);

	clock_t stop = clock();
	double average_time = (double)(stop - start) / (double)CLOCKS_PER_SEC;
	return (float)average_time;
}
// Check if a is sorted
static int is_sorted(int *a, int n) {
	for (int i = 0; i < n-1; i++) {
		if (a[i] > a[i+1])
			return 0;
	}
	return 1;
}
// Prints test results
static void print_result(res *res) {
	if (res->sorted)
		printf("Sorted: " COLOR_GREEN "TRUE" COLOR_RESET "\n");
	else
		printf("Sorted: " COLOR_RED "FALSE" COLOR_RESET "\n");
	printf("Time: %lf seconds\n", res->exec_time);
}
