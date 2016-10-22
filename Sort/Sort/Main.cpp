#include <iostream>
#include <stdlib.h>
using namespace std;

#include "BubbleSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"

void display(int *array, int size);

int main()
{
	cout << "SORTING ALGORITHMS" << endl;
	cout << "==================" << endl;

	int size = 5;

	BubbleSort bubbleSort;
	SelectionSort selectionSort;
	InsertionSort insertionSort;

	int choice;
	do
	{
		cout << endl;
		cout << "1. Bubble Sort" << endl;
		cout << "2. Modified Bubble Sort" << endl;
		cout << "3. Selection Sort" << endl;
		cout << "4. Insertion Sort" << endl;
		cout << "7. Exit" << endl;
		cout << "Enter your choice" << endl;
		cin >> choice;
		
		int a[] = { 2, 3, 1, 5, 4 };
		int *b = nullptr;

		switch (choice)
		{
		case 1:
			cout << endl << "Bubble Sort" << endl;
			cout << "Array Before Sorting" << endl;
			display(a, size);
			
			b = bubbleSort.sort(a, size);
			cout << "Array After Sorting" << endl;
			display(b, size);
			break;

		case 2:
			cout << endl << "Modified Bubble Sort" << endl;
			cout << "Array Before Sorting" << endl;
			display(a, size);

			b = bubbleSort.modifiedSort(a, size);
			cout << "Array After Sorting" << endl;
			display(b, size);
			break;

		case 3:
			cout << endl << "Selection Sort" << endl;
			cout << "Array Before Sorting" << endl;
			display(a, size);

			b = selectionSort.sort(a, size);
			cout << "Array After Sorting" << endl;
			display(b, size);
			break;

		case 4:
			cout << endl << "Insertion Sort" << endl;
			cout << "Array Before Sorting" << endl;
			display(a, size);

			b = insertionSort.sort(a, size);
			cout << "Array After Sorting" << endl;
			display(b, size);
			break;

		case 7:
			exit(0);

		default:
				break;
		}
	} while (choice != 7);

	getchar();
	return 0;
}

void display(int *array, int size)
{
	for (int i = 0; i < size; i++)
		cout << array[i] << " ";
	cout << endl;
}