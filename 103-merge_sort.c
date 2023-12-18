#include "sort.h"

/**
 * swap - Swaps two integers in an array
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 *
 * Description: This function takes two pointers to integers as parameters
 * and swaps the values at the memory locations they point to.
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * cpy - Copy elements from one array to another in a specified range.
 *
 * This function copies elements from the source array (arr) to the destination
 * array (array) within the specified range [lb, ub].
 *
 * @array: Destination array to which elements will be copied.
 * @arr: Source array from which elements will be copied.
 * @lb: Lower bound of the range (inclusive).
 * @ub: Upper bound of the range (inclusive).
 */
void cpy(int array[], int arr[], int lb, int ub)
{
	int i;

	for (i = lb; i <= ub; i++)
	{
		array[i] = arr[i];
	}
}

/**
 * merge - Merges two sorted halves of an array
 * @array: The array to merge
 * @lb: Left boundary of the subarray
 * @mid: Middle index of the subarray
 * @ub: Right boundary of the subarray
 *
 * Description: This function merges two sorted halves of the array
 * into a single sorted subarray.
 */
void merge(int array[], int lb, int mid, int ub)
{
	int i = lb, j = mid + 1, k = lb;
	int *arr = (int *)malloc((ub + 1) * sizeof(int));

	if (arr == NULL)
	{
		return;
	}
	while (i <= mid && j <= ub)
	{
		if (array[i] <= array[j])
		{
			arr[k] = array[i];
			i++;
		}
		else
		{
			arr[k] = array[j];
			j++;
		}
		k++;
	}
	if (i > mid)
	{
		while (j <= ub)
		{
			arr[k] = array[j];
			j++;
			k++;
		}
	}
	while (i <= mid)
	{
		arr[k] = array[i];
		i++;
		k++;
	}
	cpy(array, arr, lb, ub);
	free(arr);
}

/**
 * merge_helper - Recursive helper function for merge_sort
 * @array: The array to sort
 * @lb: Left boundary of the subarray
 * @ub: Right boundary of the subarray
 *
 * Description: This function is a recursive helper for the merge_sort
 * function, implementing the top-down merge sort algorithm.
 */
void merge_helper(int array[], int lb, int ub)
{
	if (lb < ub)
	{
		int mid = (lb + ub) / 2;

		merge_helper(array, lb, mid);
		merge_helper(array, mid + 1, ub);

		printf("Merging...\n[left]: ");
		print_array(array + lb, mid - lb + 1);
		printf("[right]: ");
		print_array(array + mid + 1, ub - mid);
		merge(array, lb, mid, ub);
		printf("[Done]: ");
		print_array(array + lb, ub - lb + 1);
	}
}

/**
 * merge_sort - Sorts an array of integers using the Merge sort algorithm
 * @array: The array to sort
 * @size: Size of the array
 *
 * Description: This function takes an array and its size as parameters
 * and sorts the array in ascending order using the Merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}
	merge_helper(array, 0, size - 1);
}
