#include "cocktail_shaker_sort.h"

// Private function declarations
static void swap(int *x, int *y);

// Cocktail shaker sort algorithm
void cocktail_shaker_sort(int *a, int n, cmp_t cmp) {
	int iBegin = 0;
    int iEnd = n-2;
    while (iBegin <= iEnd) {
        int iBeginNew = iEnd;
        int iEndNew = iBegin;
        // Up
        for (int i = iBegin; i <= iEnd; i++) {
            if (!cmp(a[i], a[i+1])) {
                swap(a+i, a+i+1);
                iEndNew = i;
            }
        }
        iEnd = iEndNew - 1;
        // Down
        for (int i = iEnd; i >= iBegin; i--) {
            if (!cmp(a[i], a[i+1])) {
                swap(a+i, a+i+1);
                iBeginNew = i;
            }
        }
        iBegin = iBeginNew + 1;
    }
}
// Swap two integers
static void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}
