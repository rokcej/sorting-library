#include "quicksort.h"

// Private function declarations
static void quicksort_rec(int *a, int iBegin, int iEnd, cmp_t cmp);
static void swap(int *x, int *y);

// Quicksort main wrapper function
void quicksort(int *a, int n, cmp_t cmp) {
	quicksort_rec(a, 0, n - 1, cmp);
}
// Quicksort algorithm
static void quicksort_rec(int *a, int iBegin, int iEnd, cmp_t cmp) {
	if (iEnd - iBegin <= 0)
		return;
	// Choose a pivot
	int pivot = a[(int)((iBegin+iEnd) / 2)];
	// Partition
	int i = iBegin; int j = iEnd;
	while (i <= j) {
		while (!cmp(pivot, a[i])) i++; // Asc: a[i] < pivot; desc: a[i] > pivot
		while (!cmp(a[j], pivot)) j--; // Asc: a[j] > pivot; desc: a[i] < pivot
		if (i <= j) {
			swap(a+i, a+j);
			i++; j--;
		}
	}
	// Repeat recursively
	quicksort_rec(a, iBegin, j, cmp);
	quicksort_rec(a, i, iEnd, cmp);
}

// Swap two integers
static void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}
