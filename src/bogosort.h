#ifndef _bogosort_h
#define _bogosort_h

void bogosort(int *a, int n);
void bogosort_det(int *a, int n);
void bogosort_rand(int *a, int n);

static int bogosort_det_rec(int *a, int n, int depth);
static void shuffle(int *a, int n);
static int is_sorted(int *a, int n);
static void swap(int *x, int *y);

#endif
