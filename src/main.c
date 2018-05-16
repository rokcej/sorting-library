#include "tester.h"
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
#include <stdio.h>

// Sorting comparator functions
int cmp_asc(int x, int y) { // Ascending
	return x <= y;
}
int cmp_desc(int x, int y) { // Descending
	return x >= y;
}

int main() {
	/* Array of algorithms to be tested
	 * Structure: { use algorithm, algorithm name, pointer to the algorithm function }
	 * To test additional sorting algorithms, add a new struct to the algorithms array
	 */
	Alg algorithms[] = {
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

	/* Comparator funcion to be used with the selected algorithms
	 * To use a different comparator function, change the cmp variable
	 */
	cmp_t cmp = cmp_asc;
	
	/* Reading n from the input and running the tester
	 * Don't change anything below this point
	 */
	int num_algorithms = sizeof(algorithms) / sizeof(*algorithms);
	int n;
	printf("Enter n: ");
	if (scanf("%d", &n) == 1 && n >= 1) { // Valid input
		printf("\n");
		tester(algorithms, num_algorithms, n, cmp);
	} else { // Invalid input
		printf("Error: invalid input.\n");
	}
	return 0;
}
