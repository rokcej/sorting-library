#include "gnome_sort.h"

// Gnome sort algorithm
void gnome_sort(int *a, int n) {
	int i = 1;
    while (i < n) {
        if (i == 0 || a[i] >= a[i-1]) {
            i++;
        } else {
            swap(a+i, a+i-1);
            i--;
        }
    }
}
// Swap two integers
static void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}
