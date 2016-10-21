#include <iostream>
using namespace std;
#include "BubbleSort.h"



BubbleSort::BubbleSort()
{
}


BubbleSort::~BubbleSort()
{
}

/* The bubble sort works by iterating down an array to be sorted from the first element to the last, comparing each pair of elements and switching their positions if necessary. 
This process is repeated as many times as necessary, until the array is sorted. Since the worst case scenario is that the array is in reverse order, 
and that the first element in sorted array is the last element in the starting array, the most exchanges that will be necessary is equal to the length of the array. 

Here is a simple example: 
Given an array 23154 a bubble sort would lead to the following sequence of partially sorted arrays: 21354, 21345, 12345. 
First the 1 and 3 would be compared and switched, then the 4 and 5. On the next pass, the 1 and 2 would switch, and the array would be in order. 

The average, best and worst case order for this algorithm is O(n ^ 2)*/
int* BubbleSort::sort(int *array, int size)
{

	for (int i = 0; i < size; i++)			// The array is iterated n times where n is the size of the array
	{
		for (int j = 0; j < size-1; j++)	// During each pass of i over the array, j is iterated size -1 times, since element at position j will be compared to element at j+1
		{
			if (array[j] > array[j+1])		// Compare if element at position j is greater than element at position j+1 (compares 1st and 2nd, then 2nd and 3rd and so on as j is incremented)
			{								// If above condition holds true swap the elements
				int temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
	return array;							// Finally return the array
}

/* A better version of bubble sort, known as modified bubble sort, includes a flag that is set if an exchange is made after an entire pass over the array. 
If no exchange is made, then it should be clear that the array is already in order because no two elements need to be switched. 
In that case, the sort should end. The new best case order for this algorithm is O(n), as if the array is already sorted, then no exchanges are made. */
int* BubbleSort::modifiedSort(int *array, int size)
{
	int sortFlag;
	for (int i = 0; i < size; i++)			// The array is iterated n times where n is the size of the array
	{
		sortFlag = 0;
		for (int j = 0; j < size - 1; j++)	// During each pass of i over the array, j is iterated size -1 times, since element at position j will be compared to element at j+1
		{
			if (array[j] > array[j + 1])	// Compare if element at position j is greater than element at position j+1 (compares 1st and 2nd, then 2nd and 3rd and so on as j is incremented)
			{								// If above condition holds true swap the elements
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				sortFlag = 1;				// Set the sortFlag to 1 to indicate that elements where swapped
			}
		}
		if (sortFlag == 0)					// If over a pass of the entire array during iteration of j, no elements where swapped, sortFlag will be 0 indication the array is sorted
			return array;					// Hence, in this case we do not have to iterate over the array again and return the array
	}
	return array;
}
