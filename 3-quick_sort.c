#include "sort.h"

/**
 * swap_ints - Swaps two integers.
 * @a: First int pointer.
 * @b: Second int pointer.
 */
void swap_ints(int *a, int *b)
{
	if (*a == *b)
		return;
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - Partitions array with Lomuto scheme.
 * @array: Array to partition.
 * @low: Starting index.
 * @high: Ending index (pivot).
 * @size: Array size.
 * Return: Final index of pivot.
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1, j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap_ints(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (i + 1 != high)
	{
		swap_ints(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quick_sort_rec - Recursively applies quicksort.
 * @array: Array to sort.
 * @low: Starting index.
 * @high: Ending index.
 * @size: Array size.
 */
void quick_sort_rec(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot_index = lomuto_partition(array, low, high, size);
		quick_sort_rec(array, low, pivot_index - 1, size);
		quick_sort_rec(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - Quick sort entry point.
 * @array: Array to sort.
 * @size: Size of array.
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_rec(array, 0, size - 1, size);
}
