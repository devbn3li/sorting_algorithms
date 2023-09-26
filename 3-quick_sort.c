#include "sort.h"
/**
 * swap - Swap two integers in array
 * @a: First int
 * @b: Sec int
 *
 * Return: void
 */
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto - Order subarray and places pivot
 * @array: Array will sort
 * @size: Array size
 * @low: Starting index of subarray
 * @high: Ending index of subarray
 *
 * Return: Index of placed pivot
 */
int lomuto(int *array, size_t size, int low, int high)
{
	int i = low - 1, x;

	for (x = low; x <= high - 1; x++)
	{
		if (array[x] < array[high])
		{
			i++;
			if (i != x)
			{
				swap(&array[i], &array[x]);
				print_array(array, size);
			}
		}
	}
	if (i + 1 != high)
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quicksort - Sort array of integers in ascending order using quicksort
 * algorithm
 * @array: Array to sort
 * @size: Array size
 * @low: Starting index of subarray
 * @high: Ending index of subarray
 *
 * Return: void
 */
void quicksort(int *array, size_t size, int low, int high)
{
	int pivot_idx;

	if (low < high)
	{
		pivot_idx = lomuto(array, size, low, high);
		quicksort(array, size, low, pivot_idx - 1);
		quicksort(array, size, pivot_idx + 1, high);
	}
}

/**
 * quick_sort - Sort array of integers in ascending order using quicksort
 * algorithm
 * @array: Array to sort
 * @size: the array size
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quicksort(array, size, 0, size - 1);
}
