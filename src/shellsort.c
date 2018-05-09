#include "shellsort.h"
#include <stdlib.h>
#include <math.h> // ceil() and pow() for tokuda sequence

// Shellsort algorithm
void shellsort(int *a, int n) {
    shellsort_ciura(a, n); // Ciura sequence is currently the best
}
// Shellsort using Ciura sequence
void shellsort_ciura(int *a, int n) {
    gap_insertion_sort(a, n, generate_ciura_gaps);
}
// Shellsort using Tokuda sequence
void shellsort_tokuda(int *a, int n) {
    gap_insertion_sort(a, n, generate_tokuda_gaps);
}

// Sorts a using gaps, generated by f
static void gap_insertion_sort(int *a, int n, int *(*f)(int, int*)) {
    int n_gaps; // Pass the address where the funciton will store the value
    int *gaps = f(n, &n_gaps);

    for (int iGap = 0; iGap < n_gaps; iGap++) {
        int gap = gaps[iGap];
        for (int i = gap; i < n; i++) {
            int temp = a[i];
            int j = i;
            while (j >= gap && a[j-gap] > temp) {
                a[j] = a[j-gap];
                j -= gap;
            }
            a[j] = temp;
        }
    }
    free(gaps);
}

// Generates gaps based on the Ciura sequence
static int *generate_ciura_gaps(int n, int *n_gaps) {
    int ciura_gaps[] = { 1, 4, 10, 23, 57, 132, 301, 701, 1750 };
    float ciura_factor = 2.25;
    int n_ciura_gaps = 9;

    if (n <= (int)(ciura_gaps[n_ciura_gaps-1] * ciura_factor)) {
        *n_gaps = 0;
        while (*n_gaps < n_ciura_gaps) {
            if (n <= ciura_gaps[*n_gaps])
                break;
            else
                (*n_gaps)++;
        }
    } else {
        *n_gaps = n_ciura_gaps;
        int temp = ciura_gaps[n_ciura_gaps-1] * ciura_factor;
        while (temp < n) {
            temp *= ciura_factor;
            (*n_gaps)++;
        }
    }
    int *gaps = (int*)malloc(*n_gaps * sizeof(int));
    for (int i = 0; i < *n_gaps; i++) {
        if (i < n_ciura_gaps)
            gaps[*n_gaps-1-i] = ciura_gaps[i];
        else if (i > 0)
            gaps[*n_gaps-1-i] = (int)(gaps[*n_gaps-i] * ciura_factor);
        else // Should never happen
            gaps[*n_gaps-1-i] = 1;
    }

    return gaps;
}

// Generates gaps based on the Tokuda sequence
static int *generate_tokuda_gaps(int n, int *n_gaps) {
    *n_gaps = 0;
    while (n > tokuda_sequence(*n_gaps))
        (*n_gaps)++;

    int *gaps = (int*)malloc(*n_gaps * sizeof(int));
    for (int i = 0; i < *n_gaps; i++)
        gaps[*n_gaps-1-i] = tokuda_sequence(i);

    return gaps;
}

// Returns the nth element of the tokuda sequence
static int tokuda_sequence(int n) {
    return (int)ceil(((double)9.0 * pow((double)9.0/4.0, n) - 4.0) / 5.0);
}

// Swap two integers
static void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}
