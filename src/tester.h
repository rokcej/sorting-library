#ifndef _test_h
#define _test_h

typedef int (*cmp_t)(int, int); // Sorting function comparator
typedef void (*func_t)(int*, int, cmp_t); // Sorting function

typedef struct { // Struct representing the result of a sorting algorithm test
	int sorted; // Was the result correctly sorted?
	float exec_time; // Execution time
} Res;
typedef struct { // Struct representing a sorting algorithm
	int use; // Flag specifying whether to use/test this algorithm
	char *name; // Algorithm name
	func_t func; // Algorithm function pointer
} Alg;

void tester(Alg *algs, int num_algs, int n, cmp_t cmp);

#endif
