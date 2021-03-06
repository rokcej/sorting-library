
# Sorting library
A simple sorting algorithm library written in C, along with a program to test and compare different sorting algorithms.

## Algorithms
The included sorting algorithms and their worst-case computational complexities:
### Advanced
* <b>Quicksort</b> (`quicksort.c`):
  * Average-case: O(n*logn)
  * Worst-case: O(n<sup>2</sup>)
  * Despite the bad worst-case performance, it can still be much faster than Merge sort and Heapsort when implemented well
* <b>Merge sort</b> (`merge_sort.c`):
  * O(n*logn)
* <b>Heapsort</b> (`heapsort.c`):
  * O(n*logn)
* <b>Shellsort</b> (`shellsort.c`):
  * O(n<sup>α</sup>); α < 2
  * Using [Ciura gap sequence](https://oeis.org/A102549) (function `shellsort` or `shellsort_ciura`):
    * Time complexity unknown
    * Currently has the best known performance among other gap sequences
    * The sequence was found empirically. Gaps beyond 1750 are not yet known, but it can be extended with the recursive formula h<sub>k</sub> = floor(2.25 * h<sub>k-1</sub>) ([Source](https://en.wikipedia.org/wiki/Shellsort#Gap_sequences))
  * Using [Tokuda gap sequence](https://oeis.org/A108870) (function `shellsort_tokuda`):
    * Time complexity unknown
    * Sequence formula: h<sub>k</sub> = ceiling((9 * (9/4)<sup>k</sup> - 4) / 5); k ≥ 0
### Simple
* <b>Insertion sort</b> (`insertion_sort.c`):
  * O(n<sup>2</sup>)
* <b>Selection sort</b> (`selection_sort.c`):
  * O(n<sup>2</sup>)
* <b>Gnome sort</b> (`gnome_sort.c`):
  * O(n<sup>2</sup>)
  * Also known as Stupid sort
  * Similar to Insertion sort, but simpler (uses only 1 variable)
* <b>Cocktail shaker sort</b> (`cocktail_shaker_sort.c`):
  * O(n<sup>2</sup>)
  * Similar to Bubble sort, except it works in both directions
* <b>Bubble sort</b> (`bubble_sort.c`):
  * O(n<sup>2</sup>)
* <b>Bogosort</b> (`bogosort.c`):
  * Disabled by default in the tester because it is too slow
  * Deterministic version (function `bogosort` or `bogosort_det`):
    * O((n+1)!)
  * Random version (function `bogosort_rand`):
    * O(∞)

Note that additional sorting algorithms may be added in the future.

## Tester
The tester reads `n` from the standard input, generates an array that is a random permutation of numbers from 1 to `n` and measures the execution time of different sorting algorithms on that array.

## How to use it
### Building and running the tester
Use the `Makefile` to compile and link the program. On Linux you can do so by using the command:
```bash
make
```
This will create an executable file (and object files) in the `build` folder. You can then run the tester with:
```bash
build/main
```

### Using the sorting algorithms in your programs
If you want to use one or more sorting algorithms from this library in one of your programs, include the header file of the wanted sorting algorithm into your program:
```c
#include "algorithm_name.h"
```
 Then you can use the included sorting algorithm by calling the function:
```c
algorithm_name(array, n, cmp);
```
to sort an integer array `array` (data type `int*`) with `n` (data type `int`) elements using the `cmp` (data type `int (*)(int, int)`) comparator function.  
For example, a comparator that sorts the elements in ascending order would be:
```c
int comparator_ascending(int x, int y) { return x <= y; }
```

### Choosing which sorting algorithms to use in the tester
To choose which sorting algorithms to test, edit the `use_algorithm` flag in the `algorithms` struct array in the `main` function of `main.c`:
```c
Alg algorithms[] = {
	// ... ,
	{ use_algorithm, "Algorithm name", algorithm_name }
	// , ...
};
```
Each `Alg` struct in the array represents an avaliable sorting algorithm. It includes:
* An integer `use_algorighm` - a flag that specifies whether to test this algorithm. Acceptable values are `1` (true) and `0` (false).
* A string `"Algorithm name"` - the name of the algorithm, which is printed along with the test result.
* A function pointer `algorithm_name` - the sorting function of the algorithm.

To add your own sorting algorithm to the tester, add a corresponding `Alg` struct to the `algorithms` array. The struct is defined in `tester.h`.
Note that sorting functions should always have the same name as the algorithm source code file (without the `.c` or `.h` extension) for consistency.

### Example
Here's an example of what running the tester on an array of length 100000 looks like:  
![Tester example](img/example.jpg "Tester example")
