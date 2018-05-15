#ifndef _shellsort_h
#define _shellsort_h

typedef int (*cmp_t)(int, int); // Sorting function comparator

void shellsort(int *a, int n, cmp_t cmp);
void shellsort_ciura(int *a, int n, cmp_t cmp);
void shellsort_tokuda(int *a, int n, cmp_t cmp);

#endif
