#include "sort.h"
/**
 * swap - swap two integers
 * @a: ptr to first int
 * @b: ptr to second int
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * selection_sort - sort array of integers in ascending order
 *                  using the Selection sort algorithm
 * @array: ptr to array to be sorted
 * @size: the array size
 */
void selection_sort(int *array, size_t size)
{
	size_t i, x, min_index;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_index = i;
		for (x = i + 1; x < size; x++)
		{
			if (array[x] < array[min_index])
				min_index = x;
		}

		if (min_index != i)
		{
			swap(&array[i], &array[min_index]);
			print_array(array, size);
		}
	}
}
