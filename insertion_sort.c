#include "insertion_sort.h"

// Insertion sort algorithm
void insertion_sort(int *a, int n) {
	for (int i = 1; i < n; i++) {
		int temp = a[i];
		int j = i;
		while (j >= 1 && a[j-1] > temp) {
			a[j] = a[j-1];
			j--;
		}
		a[j] = temp;
	}
}
