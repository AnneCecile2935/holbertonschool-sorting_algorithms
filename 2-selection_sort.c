#include "sort.h"
/**
 * selection_sort - function that sorts an array of integers
 * in ascending order using the Selection sort algorithm
 * @array: pointer to the array
 * @size: size of the array
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
size_t i; /** index pour la boucle principale , élément qu'on veut placer correctement*/
size_t j; /** index pour la boucle intérieure qui recherche le plus petit élement dans le reste du tableau */
size_t min_idx; /** index du plus petit élement */
int temp; /** varaible temporaire pour l'échange */
if (array == NULL || size < 2)
return;
for (i = 0; i < size - 1; i++) /** parcourir le tableau jusu'à l'avant dernier élément*/
{
	min_idx = i; /** on suppose que le plus petit élement est en position i */
	for (j = i + 1; j < size; j++) /** on cherche dans le tableau un élément plus petit */
	{
	if (array[j] < array[min_idx]) /** si on trouve un élément plus petit */
	min_idx = j; /** on met à jour la valeur du plus petit */
	}
	if (min_idx != i) /**si on a trouvé un élément plus petit */
	{
		temp = array[i]; /**on stcke la valeur de i dans la variable temp*/
		array[i] = array[min_idx]; /** on échange le plus petit élément avec celui de i */
		array[min_idx] = temp;/** on remet à jour la valeur du plus petit élément */
		print_array(array, size);
	}
}
}
