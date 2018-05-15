#include "heapsort.h"

// Private function declarations
static void adjust_heap(int *a, int n, int i, cmp_t cmp);
static void swap(int *x, int *y);

// Heapsort algorithm
void heapsort(int *a, int n, cmp_t cmp) {
	// Arrange the array into a heap
	for (int i = n/2 - 1; i >= 0; i--)
		adjust_heap(a, n, i, cmp);

	// Sort the array
	for (int i = n-1; i >= 1; i--) {
		swap(a+0, a+i);
		adjust_heap(a, i, 0, cmp);
	}
}
// Given the root of a subtree, recursively adjust it into a heap, provided that both of the root's subtrees are already heaps
static void adjust_heap(int *a, int n, int i, cmp_t cmp) {
	if (i <= n/2 - 1) { // If a[i] is a parent
		int c = 2*i + 1; // a[c] is a[i]'s left child
		if (c+1 <= n-1) { // If a[i] has a right child
			if (!cmp(a[c+1], a[c])) // Asc: if (a[c] < a[c+1])
				c = c+1; // Make a[c] a[i]'s largest child
		}
		if (!cmp(a[c], a[i])) { // If a[i] is smaller than its largest child // Asc: if (a[i] < a[c])
			swap(a+i, a+c); // Swap them
			adjust_heap(a, n, c, cmp); // Recursively adjust the heap
		}
	}
}
// Swap two integers
static void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}
