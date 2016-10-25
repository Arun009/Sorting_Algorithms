#include <iostream>
using namespace std;
#include "HeapSort.h"

/* Heap sort is a comparison based sorting technique based on Binary Heap data structure. It is similar to selection sort.

Binary Heap: In order to understand binary heap, we need to understand what a complete Binary Tree is. A complete binary tree is a binary tree in which every level,
except possibly the last, is completely filled and all nodes are as far to the left as possible.
A Binary Heap is a Complete Binary Tree where items are stored in a special order such that value in a parent node is greater(or smaller) than the values in its two children nodes. 
The former is called as max heap and the latter is called min heap. The heap can be represented by binary tree or array.

Why array based representation for Binary Heap?
Since a Binary Heap is a Complete Binary Tree, it can be easily represented as array and array based representation is space efficient. 
If the parent node is stored at index i, the left child can be calculated by 2 * i + 1 and right child by 2 * i + 2 (assuming the indexing starts at 0).

Heap Sort Algorithm for sorting in increasing order:
1. Build a max heap from the input data.
2. At this point, the largest item is stored at the root of the heap. Replace it with the last item of the heap followed by reducing the size of heap by 1. Finally, heapify the root of tree.
3. Repeat above steps until size of heap is greater than 1.

How to build the heap?
Heapify procedure can be applied to a node only if its children nodes are heapified. So the heapification must be performed in the bottom up order.

Lets understand with the help of an example:
Input data: 4, 10, 3, 5, 1
Below is the representation of the array as a complete binary tree (Note that we are using array repressentation in the code and not linked list) as shown below
		 4(0)
		/   \
	10(1)   3(2)
	/   \
5(3)    1(4)

The numbers in bracket represent the indices in the array
representation of data.

Next we need to heapify the array. Heapify procedure can be applied to a node only if its children nodes are heapified. So the heapification must be performed in the bottom up order.
So we start by applying heapify procedure to index 1. (Note that elements at indexes 2, 3 and 4 does not have children and does not require heapifying)
Applying heapify procedure to index 1:
		 4(0)
		/   \
	10(1)    3(2)
	/   \
5(3)    1(4)

The element at index 1 that is 10 (parent) is greater than the values in its two children, hence no swapping is required. The heap remains the same.

Next:
Applying heapify procedure to index 0:
	 10(0)				10(0)
	  /  \				 /  \
	4(1)  3(2)	=>	  5(1)  3(2)
	/   \			  /   \
5(3)    1(4)		4(3)  1(4)

The element at 0, that is 4 has a child 10 which is greater and is swapped first, the resulting array is passed to the heapify function recursively to swap 5 and 4 again.

The heapify procedure calls itself recursively to build heap
in top down manner.
*/

HeapSort::HeapSort()
{
}


HeapSort::~HeapSort()
{
}

// This method does the heapifying as mentioned earlier
void HeapSort::heapify(int array[], int size, int i)
{
	int largest = i;			// Initialize largest as i
	int leftChild = 2 * i + 1;	// Left child (if i =0, leftChild = 1. if i =1, leftChild = 3 and so on)
	int rightChild = 2 * i + 2;	// ght child (if i =0, rightChild = 2. if i =1, rightChild = 4 and so on)

	// If leftChild is larger than parent
	if (leftChild < size && array[leftChild] > array[largest])
		largest = leftChild;

	// If rightChild is larger than parent
	if (rightChild < size && array[rightChild] > array[largest])
		largest = rightChild;

	// If there are nodes which are larger than the parent node
	if (largest != i)
	{
		swap(array[i], array[largest]);		// Swap the elements

		// Recursively heapify the affected sub-tree
		heapify(array, size, largest);
	}

}

// main function to do heap sort
void HeapSort::heapSort(int arr[], int n)
{
	// Build heap (rearrange array): This is where max heap is created
	for (int i = n / 2 - 1; i >= 0; i--)		// i = n/2-1 : This is so that we start from the bottom leftmost parent node (Heapify is performed from bottom up)
												// i starts from 1 in the example mentioned above (heapifying of index 1 is detailed at the begining, refer the same)
		heapify(arr, n, i);						// This is only done once before the sorting
												// At this point, the largest item is stored at the root of the heap
	// One by one extract an element from heap
	for (int i = n - 1; i >= 0; i--)			// After each pass of the array in the loop, the element at the root is replaced with the last element of the heap
	{											// which means the largest element in the heap is replaced with the last element in the heap, (move the largest element to the end)
		// Move current root to end
		swap(arr[0], arr[i]);					// Replace the element at root with the last element of the heap

		// call max heapify on the reduced heap
		heapify(arr, i, 0);						// Heapify with size reduced by 1 during each pass, so that during the next pass 
												// the second largest element occupies the second last position (note we are heapifying with size reduced by 1)
												// the third largest element occupies the third position from last and so on
	}
}

/* A utility function to print array of size n */
int* HeapSort::printArray(int array[], int n)
{
	return array;
}
