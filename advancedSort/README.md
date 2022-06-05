Implement the quicksort, Shell's sort, and insertion sort algorithms as functions. Recall that the quicksort algorithm needs two functions to work properly.

We're going to time how fast the different algorithms can sort under various conditions.

Begin by creating 3 integer arrays, all of length 20 elements. Fill these arrays with random numbers, but I want the three arrays to be identical. Recall that if you want a range for a random number, it's rand()%(max+1-min)+min; where min in max specify the range of values you like [min, max] (inclusively). By being identical, the sorting time will be found fairly.

Output what the original unsorted array looks like, and then show the sorted list using each sorting algorithm. This is just to ensure that each sort is working correctly.

Now we're going to time how long it takes each sort to run given various input patterns. Instead of 20 elements, we're going to now be working with 100,000 elements.

Time how long it takes to sort the array for each function using the code below:

The way to get the time in milliseconds is:
```c++
#include <ctime>

clock_t start, end;
double milli_time;
start = clock();
  // Perform any operations you like. Be sure it's only the sort and not printing anything out. Best way is to just have the function call here.
end = clock();
milli_time = 1000.0 * (end - start) / CLOCKS_PER_SEC;
```
Obviously don't print out the super large arrays, but please give clear output as to which sort you're doing and how long it took.

Repeat this entire process again where instead of a list of random elements, the list is already in order:  1  2  3  4  5 ...


Here's a function to fill an array with random elements, where min and max represent the lower and upper bounds for the random numbers.
```c++
#include <cstdlib>
void getRandomArray(int array[], int size)
{
     int min = 0, max = 1000000; // or whatever bounds you wish
     for(int i = 0; i < size; i++)
     {
          array[i] = rand()%(max+1 - min) + min;
     }
}
```
