#include "InsertionSort.h"



InsertionSort::InsertionSort()
{
}


InsertionSort::~InsertionSort()
{
}

/* Insertion sort is also a simple sorting algorithm where it inserts each element of the array into its proper position.
The algorithm starts with the 2nd element in array and checks if it s smaller than the previous element and if so the element is swapped. 
The algorithm then moves to the next element and checks if it is smaller than the previous element and if so element is swapped, 
it then checks if the newly swapped smaller element is smaller than the previous element, if so swap again.

Hence, each element is checked with its previous elements starting from position 1 and moved back to its original position.
Variables 'i' and 'j' begin on the same index after every pass of the first loop, the second loop only executes if variable 'j' is greater then index 0 AND arr[j] < arr[j - 1].
j is then decremented.  As long as these two conditions are met in the second loop it will keep executing, this is what sets insertion sort apart from selection sort. 
Only the data that needs to be sorted is sorted.

For visual representation of this sorting technique, visit http://cforbeginners.com/insertionsort.html for more details.

The average and worst case order for this algorithm is O(n ^ 2) and the besty case order is O(n)
*/
int* InsertionSort::sort(int *array, int size)
{
	int j;
	for (int i = 0; i < size; i++)					// The array is iterated n times where n is the size of the array
	{
		j = i;										// Set j and i to be same during the start of each iteration
		while (j > 0 && array[j] < array[j - 1])	// Check if j > 0 and element at j is less than element at j-1
		{											// If so swap the elements
			int temp = array[j];
			array[j] = array[j - 1];
			array[j - 1] = temp;
			j--;									// Decrement j
		}
	}
	return array;									// Finally return the array
}
