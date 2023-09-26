#include "sort.h"
/**
 * insertion_sort_list - Sort doubly linked list of integers in
 *                       ascending order using the Insertion sort algorithm
 *
 * @list: ptr to head of the doubly linked list
 *
 * Return: Non
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *crnt, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	return;

	crnt = (*list)->next;

	while (crnt != NULL)
	{
		temp = crnt;

		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			temp->prev->next = temp->next;

			if (temp->next != NULL)
			temp->next->prev = temp->prev;

			temp->next = temp->prev;
			temp->prev = temp->prev->prev;
			temp->next->prev = temp;

			if (temp->prev == NULL)
			*list = temp;

			print_list(*list);
		}

		crnt = crnt->next;
	}
}
