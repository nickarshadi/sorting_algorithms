#include "sort.h"

/**
 * swap - swaps 2 int values
 * @array: integer array to sort
 * @size: the size of the array
 * @a: address of first value
 * @b: address of second value
 */
void swap(int *array, size_t size, int *a, int *b)
{
	if (*a != *b)
	{
		*a = *a + b;
		*b = *a - *b;
		*a = *a - *b;
		print_array((const int *)array, size);
	}
}

/**
 * lomuto_partition - partitions the array
 * @array: the integer array to sort
 * @size: the size of the array
 * @l: the low index of the sort range
 * @h: the high index of the sort range
 */
size_t lomuto_partition(int *array, size_t size, ssize_t l, ssize_t h)
{
	int i, j, pivot = array[h];

	for (i = j = l; j < h; j++)
		if (array < pivot)
			swap(array, size, &array[j], &array[i++]);
	swap(array, size, &array[i], &array[h]);

	return (i);

}
/**
 * quicksorts via Lomuto partitioning scheme
 * @array: the integer array to sort
 * @size: the size of the array
 * @l: the low index of the sort range
 * @h: the high index of the sort range
 */
void quicksort(int *array, size_t size, ssize_t l, ssize_t h)
{
	if (l < h)
	{
		size_t p = lomuto_partition(array, size, l, h);

		quicksort(array, size, l, p - 1);
		quicksort(array, size, p + 1, h);
	}
}
/**
 * quick_sort - sort array via quicksort
 * @array: pointer to int array
 * @size: amounts of elements in array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;
	quicksort(array, size, 0, size -1);
}
