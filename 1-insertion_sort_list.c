#include "sort.h"

/**
 * swapList - function that swap 2 nodes
 * @current: current node
 * @tmp: node
 */
void swapList(listint_t *current, listint_t *tmp)
{
	if (current->prev)
		current->prev->next = tmp;
	if (tmp->next)
		tmp->next->prev = current;

	current->next = tmp->next;
	tmp->prev = current->prev;
	current->prev = tmp;
	tmp->next = current;
}

/**
 * insertion_sort_list - Entry
 * @list: the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp, *current;

	if (!(list && *list && (*list)->next))
		return;

	tmp = (*list)->next;

	while (tmp)
	{
		current = tmp;
		tmp = tmp->next;
		while (current && current->prev)
		{
			if (current->prev->n > current->n)
			{
				swapList(current->prev, current);
				if (!current->prev)
					*list = current;

				print_list((const listint_t *)*list);
			}
			else
				current = current->prev;
		}
	}
}
