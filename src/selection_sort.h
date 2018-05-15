#ifndef _selection_sort_h
#define _selection_sort_h

typedef int (*cmp_t)(int, int); // Sorting function comparator

void selection_sort(int *a, int n, cmp_t cmp);

#endif
