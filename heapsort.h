#ifndef _heapsort_h
#define _heapsort_h

void heapsort(int *a, int n);
static void create_heap(int *a, int n);
static void adjust_heap(int *a, int n, int i);
static void swap(int *x, int *y);

#endif
