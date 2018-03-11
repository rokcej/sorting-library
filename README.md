
# Sorting library
A simple sorting algorithm library written in C, along with a program to test and compare different sorting algorithms.

## Algorithms
The included sorting algorithms and their worst-case computational complexities:
### Advanced
* <b>Heapsort</b> (`heapsort.c`):
  * O(n) = nlogn
* <b>Shellsort</b> (`shellsort.c`):
  * Using Ciura gap sequence (function `shellsort` or `shellsort_ciura`):
    * O(n) = unknown
    * Currently has the best known performance
    * The sequence was found empirically. Gaps beyond 1750 are not yet known, but it can be extended with the recursive formula h<sub>k</sub> = floor(2.25 * h<sub>k-1</sub>)
  * Using Tokuda gap sequence (function `shellsort_tokuda`):
    * O(n) = unknown
    * Sequence formula: h<sub>k</sub> = ceiling((9 * (9/4)<sup>k-1</sup> - 4) / 5); k ≥ 1
### Simple
* <b>Insertion sort</b> (`insertion_sort.c`):
  * O(n) = n<sup>2</sup>
* <b>Selection sort</b> (`selection_sort.c`):
  * O(n) = n<sup>2</sup>
* <b>Gnome sort</b> (`gnome_sort.c`):
  * O(n) = n<sup>2</sup>
  * Also known as Stupid sort
  * Similar to Insertion sort, but simpler (uses only 1 variable)
* <b>Cocktail shaker sort</b> (`cocktail_shaker_sort.c`):
  * O(n) = n<sup>2</sup>
  * Similar to Bubble sort, except it sorts in both directions
* <b>Bubble sort</b> (`bubble_sort.c`):
  * O(n) = n<sup>2</sup>
* <b>Bogosort</b> (`bogosort.c`):
  * O(n) = infinity
  * Not recommended running on more than 13 elements
  * Disabled by default in the tester

Note that additional sorting algorithms may be added in the future.

## Tester
The tester reads `n` from the standard input, generates an array that is a random permutation of numbers from 1 to `n` and measures the execution time of different sorting algorithms on that array.

## How to use it
### Building and running the tester
Use the `Makefile` to compile and link the program. On Linux you can do so by using the command:
```bash
$ make
```
This will create an executable file (and object files) in the `build` folder. You can then run the tester with:
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
	{ "Algorithm name", algorithm_name }
	// , ...
};
```
Each `alg` struct in the array represents a sorting algorithm to be tested. It includes:
* A string `"Algorithm name"` - the name of the algorithm, which is printed along with the test results.
* A function pointer `algorithm_name` - it points to the sorting function of the algorithm.

Note that sorting functions always have the same name as the algorithm source code file (without the `.c` or `.h` extension).
