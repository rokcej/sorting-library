#include "heapsort.h"

// Heapsort algorithm
void heapsort(int *a, int n) {
	// Arrange the array into a heap
	create_heap(a, n);

	// Sort the array
	for (int i = n-1; i >= 1; i--) {
		swap(a+0, a+i);
		adjust_heap(a, i, 0);
	}
}
// Create the initial heap out of an array
static void create_heap(int *a, int n) {
	for (int i = n/2 - 1; i >= 0; i--) {
		adjust_heap(a, n, i);
	}
}
// Given the root of a subtree, recursively adjust it into a heap, provided that both of the root's subtrees are already heaps
static void adjust_heap(int *a, int n, int i) {
	if (i <= n/2 - 1) { // If a[i] is a parent
		int c = 2*i + 1; // a[c] is a[i]'s left child
		if (c+1 <= n-1) { // If a[i] has a right child
			if (a[c] < a[c+1]) c = c+1; // Make a[c] a[i]'s largest child
		}
		if (a[i] < a[c]) { // If a[i] is smaller than its largest child
			swap(a+i, a+c); // Swap them
			adjust_heap(a, n, c); // Recursively adjust the heap
		}
	}
}
// Swap two integers
static void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}
