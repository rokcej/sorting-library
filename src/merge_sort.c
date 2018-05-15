#include "merge_sort.h"
#include <stdlib.h>

// Private function declarations
static void merge_sort_rec(int* a, int iBegin, int iEnd, int* b, cmp_t cmp);
static void merge(int* a, int iBegin, int iMid, int iEnd, int* b, cmp_t cmp);

// Merge sort wrapper function
void merge_sort(int *a, int n, cmp_t cmp) {
	int *b = (int*)malloc(n * sizeof(int)); // Work array
	for (int i = 0; i < n; i++) // Copy a into b
		b[i] = a[i];
	merge_sort_rec(a, 0, n, b, cmp);
	free(b);
}
// Sort a using b as a work array
static void merge_sort_rec(int* a, int iBegin, int iEnd, int* b, cmp_t cmp) {
	if (iEnd - iBegin <= 0)
		return;
	int iMid = (int)((iBegin+iEnd) / 2);
	merge_sort_rec(b, iBegin, iMid, a, cmp); // Sort left half of b
	merge_sort_rec(b, iMid+1, iEnd, a, cmp); // Sort right half of b
	merge(a, iBegin, iMid, iEnd, b, cmp); // Merge both halves of b into a
}
// Merge halves from b into a
static void merge(int* a, int iBegin, int iMid, int iEnd, int* b, cmp_t cmp) {
	int i = iBegin;
	int j = iMid+1;
	for (int k = iBegin; k <= iEnd; k++) {
		if (i <= iMid && (j > iEnd || cmp(b[i], b[j]))) { // Asc: b[i] <= b[j]; desc: b[i] >= b[j]
			a[k] = b[i];
			i++;
		} else {
			a[k] = b[j];
			j++;
		}
	}
}
