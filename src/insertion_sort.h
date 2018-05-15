#ifndef _insertion_sort_h
#define _insertion_sort_h

typedef int (*cmp_t)(int, int); // Sorting function comparator

void insertion_sort(int *a, int n, cmp_t cmp);

#endif
