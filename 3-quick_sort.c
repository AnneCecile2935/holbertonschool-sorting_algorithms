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
 * Return: indice du pivot
 */
int lomuto_partition(int *array, int low, int high)
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
temp = array[i];
array[i] = array[j];
array[j] = temp;
print_array(array, high - low + 1);  
}
}
temp = array[i + 1];
array[i + 1] = array[high];
array[high] = temp;
print_array(array, high - low + 1);  
return i + 1; 
}
/**
 * quick_sort - function 
 * @array: pointer to the array
 * @size: size of the array
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
    int low = 0;
	int high;
	int pi;
	if (array == NULL || size < 2)
        return;
    
    high = size - 1;
    if (low < high)
    {
        pi = lomuto_partition(array, low, high);  
        quick_sort(array, pi);  
        quick_sort(array + pi + 1, size - pi - 1); 
    }
}