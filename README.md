
# Sorting library
A simple sorting algorithm library written in C, along with a program to test and compare different sorting algorithms.
## Algorithms
The included sorting algorithms and their worst-case computational complexities:
* Heapsort (`heapsort.c`):
  * O(n) = nlogn
* Insertion sort (`insertion_sort.c`):
  * O(n) = n<sup>2</sup>
* Selection sort (`selection_sort.c`):
  * O(n) = n<sup>2</sup>
* Bubble sort (`bubble_sort.c`):
  * O(n) = n<sup>2</sup>
* Bogosort (`bogosort.c`):
  * O(n) = infinity

Note that additional sorting algorithms may be added in the future.
## Tester
The tester receives `n` as the input, generates a random array of `n` integers from the interval [1, n] and measures the execution time of different sorting algorithms on that array.

## How to use it
### Building and running the tester
On Linux, use the `Makefile` to compile and link the program. You can do so by using the command:
```bash
make
```
This will create an executable file (and object files) in the `build/` folder. You can then run the program with:
```bash
build/test
```
### Choosing which sorting algorithms to run in the tester
To select which sorting algorithms (that are already in the library) to test, simply add/remove the corresponding structs from the `algorithms`  struct array in the `main` function of `test.c`. These structs (data type `alg`) contain a string (which is printed along with the results of the test) and a pointer to the sorting function. Note that function pointers have the same name as the algorithm source code file (without the `.c` or `.h` extension).
### Adding sorting algorithms to the library
To add your own sorting programs to the library and make them avaliable in the tester, follow these steps:
1. The main sorting function of your program should be of the form:
	```c
	void algorithm_name(int *array, int n) { // Code }
	```
2. Include the main `.h` file of your program into `test.c` and add a pointer to your function into the `algorithms` struct array:
	```c
	#include "algorithm_name.h"
	```
	```c
	alg algorithms[] = {
		// ...,
		{ "Algorithm name", algorithm_name }
	};
	```
3. Add the main `.c` file of your program to the `SOURCES` variable in `Makefile`:
	```makefile
	SOURCES = ... algorithm_name.c
	```
Now you can normally build and run the tester and your program will be included.
### Using the library in other programs
If you want to use one or more sorting algorithms from this library in one of your programs, include the header file of the wanted sorting program (`algorithm_name.h`) into your program. Then you can use
```c
algorithm_name(array, n);
```
to sort the array `array` (data type `int*`) with `n` (data type `int`) elements.
