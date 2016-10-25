#pragma once
class HeapSort
{
public:
	HeapSort();
	~HeapSort();
	void heapify(int array[], int size, int i);
	void heapSort(int array[], int n);
	int* printArray(int array[], int n);
};

