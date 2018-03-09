#include "bogosort.h"
#include <stdlib.h>

// Bogosort algorithm
void bogosort(int *a, int n) {
	while (!is_sorted(a, n))
		shuffle(a, n);
}
// Check if a is sorted
static int is_sorted(int *a, int n) {
	for (int i = 0; i < n-1; i++) {
		if (a[i] > a[i+1])
			return 0;
	}
	return 1;
}
// Shuffle a
static void shuffle(int *a, int n) {
	// Version 1
	for (int i = 0; i < n - 1; i++) {
		int r = (rand() % (n-i)) + i;
		if (i != r)	
			swap(a+i, a+r);
	}

	// Version 2
	/*for (int i = 0; i < n; i++)
		int r = rand() % n;
		if (i != r)
			swap(a+i, a+r);*/
}
// Swap two integers
static void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}
