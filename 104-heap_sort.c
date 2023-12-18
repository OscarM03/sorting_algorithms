#include "sort.h"

/**
 * swap - Swaps two integers.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * heapify - Builds and maintains a max heap.
 * @array: Array to be sorted as a heap.
 * @size: Size of the array.
 * @i: Index of the current root in the heap.
 */
void heapify(int array[], int size, int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	while (left < size && array[left] > array[largest])
	{
		largest = left;
	}
	while (right < size && array[right] > array[largest])
	{
		largest = right;
	}

	if (largest != i)
	{
		swap(&array[i], &array[largest]);
		heapify(array, size, largest);
	}
}

/**
 * heap_sort - Sorts an array using the Heap Sort algorithm.
 * @array: Array to be sorted.
 * @size: Size of the array.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	for (i = size / 2 - 1; i >= 0; i--)
	{
		heapify(array, size, i);
	}
	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		heapify(array, i, 0);
		print_array(array, size);
	}
}
