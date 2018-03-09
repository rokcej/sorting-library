#include "insertion_sort.h"

// Insertion sort algorithm
void insertion_sort(int *a, int n) {
	for (int i = 1; i < n; i++) {
		int j = i;
		while (j > 0 && a[j] < a[j-1]) {
			swap(a+j, a+j-1);
			j--;
		}
	}
}
// Swap two integers
static void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}
