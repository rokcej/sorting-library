#ifndef _shellsort_h
#define _shellsort_h

void shellsort(int *a, int n);
void shellsort_ciura(int *a, int n);
void shellsort_tokuda(int *a, int n);

static void gap_insertion_sort(int *a, int n, int *(*f)(int, int*));
static int *generate_ciura_gaps(int n, int *n_gaps);
static int *generate_tokuda_gaps(int n, int *n_gaps);
static int tokuda_sequence(int n);
static void swap(int *x, int *y);

#endif
