#include "sort.h"

/**
 * lomuto_partition - Partition the array using Lomuto scheme
 * @array: The array to sort
 * @low: The low index of the partition
 * @high: The high index of the partition
 * @size: The size of the array (for printing)
 * Return: The index of the pivot after partition
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot;
	int i;
	int j;
	int temp;

if (array == NULL || low < 0 || high < 0 ||
(size_t)low >= size || (size_t)high >= size)
return (-1);
	pivot = array[high];
	i = low;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
			i++;
		}
	}

	if (i != high && i <= high && (size_t)i < size)
	{
		temp = array[i];
		array[i] = array[high];
		array[high] = temp;
		print_array(array, size);
	}

	return (i);
}

/**
 * quick_sort_recursive - Recursively pplies quicksort
 * @array: Array to sort
 * @low: Low index
 * @high: High index
 * @size: Size of the array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pi;
if (array == NULL || low < 0 || high < 0
	|| (size_t)low >= size || (size_t)high >= size)
return;
	if (low < high)
	{
		pi = lomuto_partition(array, low, high, size);
		if (pi == -1)
		return;
		quick_sort_recursive(array, low, pi - 1, size);
		quick_sort_recursive(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - Sorts array using quick sort algorithm (Lomuto scheme)
 * @array: Array to sort
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
