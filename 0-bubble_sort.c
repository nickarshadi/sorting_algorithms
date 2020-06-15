#include "sort.h"

/**
 * bubble_sort - sort array in bubble sort
 * print the array after every swap
 * @array: unsorted array
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j = 0, temp = 0;

	if (!array || !size)
		return;

	for (; i <= size; i++)
	{
		for (; j <= size - 1; j++)
		{
			if (array[j] > array[j + 1] && (j + 1) <= size)
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
		j = 0;
	}
}
