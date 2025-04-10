#include "sort.h"
/**
 * swap - Function that swaps two values
 *
 * @a: Fisrt value
 * @b: Second value
 * Return: 0
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *b;
	*b = *a;
	*a = tmp;
}
/**
 * bubble_sort -  function that sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 * @array: pointer to the array
 * @size: size of the array
 * Return: Nothing
 */
void bubble_sort(int *array, size_t size)
{
size_t i, j;
if (!array)
return;
			for (i = 0; i < size - 1; i++) /** boucle extérieure pour parcourir le tableau (chaque tour de tableau) => size -1, si tableau de 3 cases on fera 2 tours par exemple*/
		{
			for (j = 0; j < size - i - 1; j++) /** boucle intérieure pour comparer chaque paire d'éléments qui ne sont pas encore triés => size - i -1, si on est au tour 1, on va comparer les deux premier éléments donc j-1-1 
   au tour suivant, on ne comparera pas les valeurs qui ont déjà été comparées*/
			{
				if (array[j] > array[j + 1]) /** si la valeur trouvé de j est supérieure à la valeur trouvée de j+1*/
				{
					swap(&array[j], &array[j + 1]); /** on échange les valeurs de j et j+1 en leur changeant leur adresses*/
					print_array(array, size); /** afficher le tableau après échange*/
				}
			}
		}
	}
