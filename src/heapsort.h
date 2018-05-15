#ifndef _heapsort_h
#define _heapsort_h

typedef int (*cmp_t)(int, int); // Sorting function comparator

void heapsort(int *a, int n, cmp_t cmp);

#endif
