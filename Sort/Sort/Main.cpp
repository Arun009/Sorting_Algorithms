#include <iostream>
#include <stdlib.h>
using namespace std;

#include "BubbleSort.h"

int main()
{
	cout << "SORTING ALGORITHMS" << endl;
	cout << "==================" << endl;

	int size = 5;
	int a[] = {2, 3, 1, 5, 4};
	int a1[] = { 2, 3, 1, 5, 4 };

	BubbleSort bubbleSort;
	int *b = bubbleSort.sort(a, size);
	int *c = bubbleSort.modifiedSort(a1, size);

	for (int i = 0; i < size; i++)
		cout << b[i] << " ";
	cout << endl;
	for (int i = 0; i < size; i++)
		cout << c[i] << " ";

	getchar();
	return 0;
}