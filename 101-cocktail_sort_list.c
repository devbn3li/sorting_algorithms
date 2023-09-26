#include "sort.h"
/**
 * swap_nodes - Swap 2 adjacent nodes of a doubly linked list
 *
 * @left: Ptr to left node
 * @right: Ptr to right node
 * @list: Ptr to doubly linked list
 */
void swap_nodes(listint_t *left, listint_t *right, listint_t **list)
{
	listint_t *prev, *next;

	prev = left->prev;
	next = right->next;
	if (prev)
		prev->next = right;
	else
		*list = right;
	right->prev = prev;
	left->prev = right;
	right->next = left;
	left->next = next;
	if (next)
		next->prev = left;
}

/**
 * cocktail_sort_list - Sort doubly linked list of integers in ascending
 *                      order using Cocktail shaker sort algorithm
 *
 * @list: Ptr to doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *start, *end, *curr;
	int swaped = 0;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	start = *list;
	end = NULL;

	do {
		swaped = 0;
		for (curr = start; curr != end; curr = curr->next)
		{
			if (curr->n > curr->next->n)
			{
				swap_nodes(curr, curr->next, list);
				print_list(*list);
				swaped = 1;
			}
		}
		if (swaped == 0)
			break;
		end = curr->prev;
		swaped = 0;
		for (curr = end; curr != start; curr = curr->prev)
			if (curr->n < curr->prev->n)
			{
				swap_nodes(curr->prev, curr, list);
				print_list(*list);
				swaped = 1;
			}
		start = curr->next;
	} while (swaped);
}
