#ifndef _bubble_sort_h
#define _bubble_sort_h

typedef int (*cmp_t)(int, int); // Sorting function comparator

void bubble_sort(int *a, int n, cmp_t cmp);

#endif
