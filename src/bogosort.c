#include "bogosort.h"
#include <stdlib.h>
#include <time.h>

// Private function declarations
static int bogosort_det_rec(int *a, int n, int depth, cmp_t cmp);
static void shuffle(int *a, int n);
static int is_sorted(int *a, int n, cmp_t cmp);
static void swap(int *x, int *y);

// Bogosort algorithm
void bogosort(int *a, int n, cmp_t cmp) {
	bogosort_det(a, n, cmp); // Deterministic version is used by default
}
// Deterministic version of bogosort
void bogosort_det(int *a, int n, cmp_t cmp) {
	bogosort_det_rec(a, n, 0, cmp);
}
// Random version of bogosort
void bogosort_rand(int *a, int n, cmp_t cmp) {
	srand(time(NULL)); // Time as the RNG seed
	while (!is_sorted(a, n, cmp))
		shuffle(a, n);
}

// Recursively permute a until it is sorted
static int bogosort_det_rec(int *a, int n, int depth, cmp_t cmp) {
	if (depth == n)
		return is_sorted(a, n, cmp);

	for (int i = depth; i < n; i++) {
		swap(a+depth, a+i);
		if (bogosort_det_rec(a, n, depth+1, cmp))
			return 1;
		swap(a+depth, a+i);
	}
	return 0;
}

// Randomly permute a
static void shuffle(int *a, int n) {
	for (int i = 0; i < n - 1; i++) {
		int r = (rand() % (n-i)) + i;
		if (i != r)
			swap(a+i, a+r);
	}
}

// Check if a is sorted
static int is_sorted(int *a, int n, cmp_t cmp) {
	for (int i = 0; i < n-1; i++) {
		if (!cmp(a[i], a[i+1]))
			return 0;
	}
	return 1;
}

// Swap two integers
static void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}
