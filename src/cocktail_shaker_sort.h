#ifndef _cocktail_shaker_sort_h
#define _cocktail_shaker_sort_h

typedef int (*cmp_t)(int, int); // Sorting function comparator

void cocktail_shaker_sort(int *a, int n, cmp_t cmp);

#endif
