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
	n1->next = n2->next;
	if (n2->next)
		n2->next->prev = n1;
	n2->prev = n1->prev;
	if (n1->prev)
	n1->prev->next = n2;
	else
		*h = n2;
	n2->next = n1;
	n1->prev = n2;
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
listint_t *temp;
if (list == NULL || *list == NULL || (*list)->next == NULL)
return;
current = (*list)->next;
while (current != NULL)
{
	temp = current->prev;
	while (temp != NULL && temp->n > current->n)
	{
		swap_nodes(list, temp, current);
		print_list(*list);
		temp = current->prev;
	}
	current = current->next;
}
}
