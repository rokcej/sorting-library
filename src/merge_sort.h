#ifndef _merge_sort_h
#define _merge_sort_h

typedef int (*cmp_t)(int, int); // Sorting function comparator

void merge_sort(int *a, int n, cmp_t cmp);

#endif
