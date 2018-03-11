# Sorting library
A simple sorting algorithm library written in C, along with a program to test and compare different sorting algorithms.

## Algorithms
The included sorting algorithms and their worst-case computational complexities:
* Heapsort (`heapsort.c`):
  * O(n) = nlogn
  * Currently the fastest in the library
* Selection sort (`selection_sort.c`):
  * O(n) = n<sup>2</sup>
* Insertion sort (`insertion_sort.c`):
  * O(n) = n<sup>2</sup>
* Cocktail shaker sort (`cocktail_shaker_sort.c`):
  * O(n) = n<sup>2</sup>
  * Similar to bubble sort, except it sorts in both directions
* Bubble sort (`bubble_sort.c`):
  * O(n) = n<sup>2</sup>
* Bogosort (`bogosort.c`):
  * O(n) = infinity
  * Not recommended running on more than 13 elements

Note that additional sorting algorithms may be added in the future.

## Tester
The tester receives `n` as the input, generates a random array of `n` integers from the interval [1, `n`] and measures the execution time of different sorting algorithms on that array.

## How to use it
### Building and running the tester
Use the `Makefile` to compile and link the program. On Linux you can do so by using the command:
```bash
$ make
```
This will create an executable file (and object files) in the `build/` folder. You can then run the tester with:
```bash
$ build/test
```

### Using the sorting algorithms in your programs
If you want to use one or more sorting algorithms from this library in one of your programs, include the header file of the wanted sorting algorithm into your program:
```c
#include "algorithm_name.h"
```
 Then you can use the included sorting algorithm by calling the function:
```c
algorithm_name(array, n);
```
to sort an integer array `array` (data type `int*`) with `n` (data type `int`) elements.

### Choosing which sorting algorithms to use in the tester
To choose which sorting algorithms to test, edit the `algorithms` struct array in the `main` function of `test.c`:
```c
alg algorithms[] = {
	// ... ,	
	{ "Algorithm name", algorithm_name },
	// ...
};
```
Each `alg` struct in the array represents a sorting algorithm to be tested. It includes:
* A string `"Algorithm name"` - the name of the algorithm, which is printed along with the test results.
* A function pointer `algorithm_name` - it points to the sorting function of the algorithm.

Note that sorting functions always have the same name as the algorithm source code file (without the `.c` or `.h` extension).