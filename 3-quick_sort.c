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
	int pivot = array[high];
	int i = low;
	int j, temp;

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
			else
			{
				print_array(array, size);
			}
			i++;
		}
	}

	if (i != high)
	{
		temp = array[i];
		array[i] = array[high];
		array[high] = temp;
		print_array(array, size);
	}

	return (i);
}

/**
 * quick_sort_recursive - Recursively applies quicksort
 * @array: Array to sort
 * @low: Low index
 * @high: High index
 * @size: Size of the array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		pi = lomuto_partition(array, low, high, size);
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
