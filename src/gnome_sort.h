#ifndef _gnome_sort_h
#define _gnome_sort_h

typedef int (*cmp_t)(int, int); // Sorting function comparator

void gnome_sort(int *a, int n, cmp_t cmp);

#endif
