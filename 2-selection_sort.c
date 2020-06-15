#include "sort.h"

/**
 * selection_sort - sort array via selectionsort
 * @array: array to be sorted
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j = 0;
	int min = 0, idx = 0;

	if (!array || !size)
		return;
	for (; i < size; i++)
	{
		min = array[i];
		idx = i;
		for (j = i; j < size; j++)
		{
			if (array[j] < min)
			{
				min = array[j];
				idx = j;
			}
		}
		if (array[idx] != array[i])
		{
			array[idx] = array[i];
			array[i] = min;
			print_array(array, size);
		}
	}
}
