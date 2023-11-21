#include "sort.h"

/**
 *swap_node - swaps two nodes
 *@head:pointer to the head of doubly linked list
 *@node1:pointer to node1
 *@node2:pointer to node2
 *Return:void
 */
void swap_node(listint_t **head, listint_t *node1, listint_t *node2)
{
	listint_t *tmp;

	tmp = node1->prev;
	if (tmp)
		tmp->next = node2;
	node2->prev = tmp;
	node1->prev = node2;
	node1->next = node2->next;
	node2->next = node1;
	if (node1->next != NULL)
		node1->next->prev = node1;
	if (node2->prev == NULL)
		*head = node2;
	print_list(*head);
}
/**
 *insertion_sort_list - sorts a doubly linked list in an ascending
 *order using insertion algorithm
 *@list:pointer to a doubly linked list
 *Return:void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *prev, *tmp, *next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	curr = next = *list;
	while (curr != NULL)
	{
		while (curr->prev != NULL)
		{
			prev = curr->prev;
			tmp = prev;
			if (prev->n > curr->n)
				swap_node(list, prev, curr);
			curr = tmp;
		}
		curr = next->next;
		next = curr;
	}
}
