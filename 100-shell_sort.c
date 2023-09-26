#include "sort.h"
/**
 * shell_sort - Sort array of integers using the Shell sort algorithm
 *              with the Knuth sequence
 *
 * @array: Array of integers to be sorted
 * @size: Array size
 */
void shell_sort(int *array, size_t size)
{
	size_t distance = 1, i, x;
	int tmp;

	if (!array || size < 2)
		return;

	while (distance < size / 3)
		distance = distance * 3 + 1;

	while (distance >= 1)
	{
		for (i = distance; i < size; i++)
		{
			tmp = array[i];
			for (x = i; x >= distance && array[x - distance] > tmp; x -= distance)
				array[x] = array[x - distance];
			array[x] = tmp;
		}
		distance = (distance - 1) / 3;
		print_array(array, size);
	}
}
