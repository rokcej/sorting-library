#include "insertion_sort.h"

// Insertion sort algorithm
void insertion_sort(int *a, int n, cmp_t cmp) {
	for (int i = 1; i < n; i++) {
		int temp = a[i];
		int j = i;
		while (j >= 1 && !cmp(a[j-1], temp)) { // Asc: while (j >= 1 && a[j-1] > temp)
			a[j] = a[j-1];
			j--;
		}
		a[j] = temp;
	}
}
