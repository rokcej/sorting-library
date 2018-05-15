#ifndef _bogosort_h
#define _bogosort_h

typedef int (*cmp_t)(int, int); // Sorting function comparator

void bogosort(int *a, int n, cmp_t cmp);
void bogosort_det(int *a, int n, cmp_t cmp);
void bogosort_rand(int *a, int n, cmp_t cmp);

#endif
