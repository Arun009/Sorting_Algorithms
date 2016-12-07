#include "SelectionSort.h"



SelectionSort::SelectionSort()
{
}


SelectionSort::~SelectionSort()
{
}

/* Selection sort is also a simple algorithm. It works by selecting the smallest element of the array and placing it at the head of the array, 
then the second smallest is placed below it and so on.
The first loop goes from 0 to n (n = size), and the second loop goes from i to n, so it goes from 0 to n, then from 1 to n, then from 2 to n and so on.
The average, best and worst case order for this algorithm is O(n ^ 2)
They are efficient than Bubble sort as after each iteration, you iterate through 1 element less.*/
int* SelectionSort::sort(int *array, int size)
{
	for (int i = 0; i < size; i++)				// The array is iterated n times where n is the size of the array
	{
		int indexOfMin = i;						// Set the indexOfMin to i, since the smallest value after iteration over the elements is placed at position i 
												// Once i is set after the pass of an array, the smallest from the rest of the elements is placed next
		for (int j = i; j < size; j++)			// The array is iterated n times where n is the size of the array
		{
			if (array[indexOfMin] > array[j])	// Check if the element at indexOfMin is greater than the lement at j
				indexOfMin = j;					// If yes set the indexOfMin to j
		}										// After one pass of the elements using iterator j, indexOfMin points to the smallest element of the elements iterated
		/* Swap the element at position i with the element at the indexOfMin. This will set the smallest element at i.
		Over the next iteration smallest from the rest of the elements is placed at next i location and so on. */
		int temp = array[i];
		array[i] = array[indexOfMin];
		array[indexOfMin] = temp;
	}
	return array;
}
