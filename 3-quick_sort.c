#include "sort.h"
/**
 * lomuto_partition - function
 * La fonction de partitionnement va prendre en entrée le tableau,
 * l'indice bas et l'indice haut. Elle va réorganiser les éléments du
 * tableau pour placer les éléments inférieurs au pivot à gauche et
 * les éléments supérieurs à droite.
 * @array: pointer to the array
 * @low: indice du bas
 * @high: indice du haut
 * @size: size of array
 * Return: indice du pivot
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
int pivot;
int i;
int temp;
int j;
pivot = array[high];
i = low - 1;
for (j = low; j < high; j++)
{
if (array[j] < pivot)
{
i++;
if (i != j)
{
temp = array[i];
array[i] = array[j];
array[j] = temp;
print_array(array, size);
}
}
}
if (i + 1 != high)
{
temp = array[i + 1];
array[i + 1] = array[high];
array[high] = temp;
print_array(array, size);
}
return (i + 1);
}
/**
 * quick_sort_recursive - Fonction récursive de tri rapide
 * @array: tableau
 * @low: indice début
 * @high: indice fin
 * @size: taille totale du tableau (pour affichage)
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
 * quick_sort - function
 * @array: pointer to the array
 * @size: size of the array
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
{
return;
}
	quick_sort_recursive(array, 0, size - 1, size);
}
