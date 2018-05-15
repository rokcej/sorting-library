#ifndef _quicksort_h
#define _quicksort_h

typedef int (*cmp_t)(int, int); // Sorting function comparator

void quicksort(int *a, int n, cmp_t cmp);

#endif
