#include "bubble_sort.h"

// Bubble sort algorithm
void bubble_sort(int *a, int n) {
	int unsorted = n; // Number of unsorted elements left
	int lastSwapped; // Index of the last swapped element
	do {
		lastSwapped = 0;
		for (int i = 0; i < unsorted-1; i++) {
			if (a[i] > a[i+1]) {
				swap(a+i, a+i+1);
				lastSwapped = i+1;
			}
		}
		unsorted = lastSwapped;
	} while (unsorted > 0);
}
// Swap two integers
static void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}
