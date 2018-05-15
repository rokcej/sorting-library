#include "gnome_sort.h"

// Private function declarations
static void swap(int *x, int *y);

// Gnome sort algorithm
void gnome_sort(int *a, int n, cmp_t cmp) {
	int i = 1;
    while (i < n) {
        if (i == 0 || cmp(a[i-1], a[i])) {
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
