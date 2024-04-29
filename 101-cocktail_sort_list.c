#include "sort.h"
#include <stdio.h>

/**
 * swap_node - swap a node with its previous one
 * @node: node to swap
 * @list: pointer to the list
 * Return: pointer to the swapped node
*/
listint_t *swap_node(listint_t *node, listint_t **list)
{
	listint_t *back = node->prev, *current = node;

	if (back)
		back->next = current->next;
	if (current->next)
		current->next->prev = back;
	current->next = back;
	current->prev = back->prev;
	if (current->prev)
		current->prev->next = current;
	else
		*list = current;
	back->prev = current;

	return (current);
}

/**
 * cocktail_sort_list - sort a doubly linked list using Cocktail Shaker Sort
 * @list: pointer to the head of the list
*/
void cocktail_sort_list(listint_t **list)
{
	listint_t *node;
	int swap_done = 1;

	if (!list || !(*list) || !((*list)->next))
		return;

	node = *list;
	while (swap_done == 1)
	{
		swap_done = 0;
		while (node->next)
		{
			if (node->n > node->next->n)
			{
				node = swap_node(node->next, list);
				swap_done = 1;
				print_list(*list);
			}
			else
			{
				node = node->next;
			}
		}
		if (swap_done == 0)
			break;
		swap_done = 0;
		while (node->prev)
		{
			if (node->n < node->prev->n)
			{
				node = swap_node(node, list);
				swap_done = 1;
				print_list(*list);
			}
			else
			{
				node = node->prev;
			}
		}
	}
}
