#include "sort.h"

/**
 * swap - swap two nodes of a foubly linked list
 * @a: address of node1(prev)
 * @b: address of node2
 */
void swap(listint_t *a, listint_t *b)
{
	if (a->prev)
		a->prev->next = b;
	if (b->next)
		b->next->prev = a;
	a->next = b->next;
	b->prev = a->prev;
	a->prev = b;
	b->next = a;
}

/**
 * insertion_sort_list - insertion sorts a doubly-linked list
 * @list: address of pointer to head node
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node = NULL, *pr = NULL;

	if (!list || !*list || !(*list)->next)
		return;
	node = (*list)->next;
	while (node)
	{
		pr = node;
		node = node->next;
		while (pr && pr->prev)
		{
			if (pr->prev->n > pr->n)
			{
				swap(pr->prev, pr);
				if (!pr->prev)
					*list = pr;
				print_list((const listint_t *)*list);
			}
			else
				pr = pr->prev;

		}
	}
}
