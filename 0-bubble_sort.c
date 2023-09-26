#include "sort.h"
/**
 * bubble_sort - Sort array of integers using bubble sort algorithm
 *
 * @array: array to be sorted
 * @size: the array size
 *
 * Return: No return
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, x;
	int temp;

	if (size < 2)
	return ;

	for (i = 0; i < size - 1; i++)
	{
		for (x = 0; x < size - i - 1; x++)
		{
			if (array[x] > array[x + 1])
			{
				temp = array[x];
				array[x] = array[x + 1];
				array[x + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
