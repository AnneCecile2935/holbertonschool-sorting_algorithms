#include "sort.h"
/**
 * swap_nodes - Swap two nodes in a listint_t doubly-linked list.
 * @h: A pointer to the head of the doubly-linked list.
 * @n1: A pointer to the first node to swap.
 * @n2: The second node to swap.
 */
void swap_nodes(listint_t **h, listint_t *n1, listint_t *n2)
{
	if (n1 == NULL || n2 == NULL)
	return;
	n1->next = n2->next; /** le pointeur next de n1 pointe vers n2 */
	if (n2->next) /** si n2 n'est pas la dernier noeud */
		n2->next->prev = n1;
		n2->prev = n1->prev; /** mettre à jour le prev du noeud suivant n2 pour qu'il pointe vers n1 */
	if (n1->prev) /** si n1 n'est pas en en-tête */
	n1->prev->next = n2; /** le noeud n1 précédent doit pointer vers n2 */
	else
		*h = n2; /** si le noeud est l'en-tête ,la tête de liste devient n2 */
	n2->next = n1; /** on remet n1 après n2 */
	n1->prev = n2; /** on relie n1 et n2 */
}
/**
 * insertion_sort_list - that sorts a doubly linked list of
 * integers in ascending order using the Insertion sort algorithm
 * @list: pointer to the head of list
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
listint_t *current;
listint_t *temp; /** noeud avant current dans la liste */
if (list == NULL || *list == NULL || (*list)->next == NULL) /** si la liste n'existe pas, ou qu'elle est vide, ou qu’elle a un seul élément
.. alors pas besoin de trier, on sort de la fonction. */
return;
current = (*list)->next; /** element qu'on veut insérer dans la partie triée à gauche */
while (current != NULL)
{
	temp = current->prev; /** Est-ce que le nœud précédent (temp) est plus grand que le nœud courant (current) */
	while (temp != NULL && temp->n > current->n) /** Tant que l’élément temp (à gauche de current) est plus grand, on échange */
	{
		swap_nodes(list, temp, current);
		print_list(*list);
		temp = current->prev; /** on remonte temp pour vérifier encore à gauche */
	}
	current = current->next; /** on passe au suivant */
}
}
