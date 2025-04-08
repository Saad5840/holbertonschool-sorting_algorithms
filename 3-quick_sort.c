#include "sort.h"
#include <stdio.h>

/**
 * swap - Swaps two integers in an array
 * @a: Pointer to first integer
 * @b: Pointer to second integer
 */
void swap(int *a, int *b)
{
    if (a != b)
    {
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }
}

/**
 * lomuto_partition - Lomuto partition scheme
 * @array: Array of integers
 * @low: Starting index
 * @high: Ending index
 * @size: Size of the array (for print)
 * Return: Index of the pivot
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
                swap(&array[i], &array[j]);
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
 * quicksort_rec - Recursive helper function for Quick Sort
 * @array: Array of integers
 * @low: Starting index
 * @high: Ending index
 * @size: Size of the array
 */
void quicksort_rec(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int p = lomuto_partition(array, low, high, size);
        quicksort_rec(array, low, p - 1, size);
        quicksort_rec(array, p + 1, high, size);
    }
}

/**
 * quick_sort - Sorts an array using Quick Sort (Lomuto)
 * @array: Array of integers
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;
    quicksort_rec(array, 0, size - 1, size);
}
