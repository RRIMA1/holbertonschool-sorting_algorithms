#include "sort.h"
#include <stdio.h>
/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: Double pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *cur, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	cur = (*list)->next;

	while (cur)
	{
		tmp = cur;

		while (tmp->prev && tmp->n < tmp->prev->n)
		{
			listint_t *prev = tmp->prev;

			prev->next = tmp->next;
			if (tmp->next)
				tmp->next->prev = prev;

			tmp->prev = prev->prev;
			tmp->next = prev;

			if (prev->prev)
				prev->prev->next = tmp;
			else
				*list = tmp;

			prev->prev = tmp;

			print_list(*list);
		}

		cur = cur->next;
	}
}
