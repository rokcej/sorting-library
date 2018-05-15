#ifndef _test_h
#define _test_h

// ANSI escape codes to color the console output
#define COLOR_RED		"\x1b[91m"
#define COLOR_GREEN		"\x1b[92m"
#define COLOR_CYAN		"\x1b[96m"
#define COLOR_RESET		"\x1b[0m"

typedef int (*cmp_t)(int, int); // Sorting function comparator
typedef void (*func_t)(int*, int, cmp_t); // Sorting function

typedef struct { // Struct representing the result of a sorting algorithm test
	int sorted; // Was the result correctly sorted?
	float exec_time; // Execution time
} res;
typedef struct { // Struct representing a sorting algorithm
	int use; // Flag specifying whether to use/test this algorithm
	char *name; // Algorithm name
	func_t func; // Algorithm function pointer
} alg;

int cmp_asc(int x, int y);
int cmp_desc(int x, int y);

void run_tests(alg *algs, int num_algs, int n, cmp_t cmp);
int *allocate_array(int n);
int *generate_array(int n);
void shuffle_array(int *a, int n);
void swap(int *x, int *y);
int *copy_array(int *a_in, int *a_out, int n);
float measure_time(int *a, int n, cmp_t cmp, func_t func);
int is_sorted(int *a, int n, cmp_t cmp);
void print_result(res *res);

#endif
