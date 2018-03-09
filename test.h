#ifndef _test_h
#define _test_h

// ANSI escape codes to color the console output
#define COLOR_RED		"\x1b[91m"
#define COLOR_GREEN		"\x1b[92m"
#define COLOR_CYAN		"\x1b[96m"
#define COLOR_RESET		"\x1b[0m"

typedef struct { // Struct representing the result of a sorting algorithm test
	int sorted; // Was the result correctly sorted?
	float exec_time; // Execution time
} res;
typedef struct { // Struct representing a sorting algorithm
	char *name; // Algorithm name
	void (*f)(int*, int); // Algorithm function pointer
} alg;

static void run_tests(alg *algs, int num_algs, int n);
static int *allocate_array(int n);
static int *generate_array(int n);
static int *copy_array(int *a_in, int *a_out, int n);
static float measure_time(int *a, int n, void (*f)(int*, int));
static int is_sorted(int *a, int n);
static void print_result(res *res);

#endif
