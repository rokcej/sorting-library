#include "selection_sort.h"

// Private function declarations
static void swap(int *x, int *y);

// Selection sort algorithm
void selection_sort(int *a, int n, cmp_t cmp) {
	for (int i = 0; i < n-1; i++) {
		int iMin = i;
		for (int j = i+1; j < n; j++) {
			if (!cmp(a[iMin], a[j])) // Asc: if (a[j] < a[iMin])
				iMin = j;
		}
		//if (iMin != i)
		swap(a+i, a+iMin);
	}
}
// Swap two integers
static void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}
