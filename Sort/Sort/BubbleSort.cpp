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

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size-1; j++)
		{
			if (array[j] > array[j+1]) 
			{
				int temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
	return array;
}

/* A better version of bubble sort, known as modified bubble sort, includes a flag that is set if an exchange is made after an entire pass over the array. 
If no exchange is made, then it should be clear that the array is already in order because no two elements need to be switched. 
In that case, the sort should end. The new best case order for this algorithm is O(n), as if the array is already sorted, then no exchanges are made. */
int* BubbleSort::modifiedSort(int *array, int size)
{
	int sortFlag;
	for (int i = 0; i < size; i++)
	{
		sortFlag = 0;
		for (int j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				sortFlag = 1;
			}
		}
		if (sortFlag == 0)
			return array;
	}
	return array;
}
