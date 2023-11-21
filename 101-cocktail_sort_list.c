#include "sort.h"
/**
 *swap_node_infront - swaps a node in ahead manner
 *@list:pointer to head of a linked dblist
 *@tail:pointer to the tail of a dblinked list
 *@shaker: pointer to swapping node
 *Return: void
 */
void swap_node_infront(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmp = (*shaker)->next;

	if ((*shaker)->prev != NULL)
		(*shaker)->prev->next = tmp;
	else
		*list = tmp;
	tmp->prev = (*shaker)->prev;
	(*shaker)->next = tmp->next;

	if (tmp->next != NULL)
		tmp->next->prev = *shaker;
	else
		*tail = *shaker;
	(*shaker)->prev = tmp;
	tmp->next = *shaker;
	*shaker = tmp;
}

/**
 *swap_node_back - swaps a dblinked list in a backward manner
 *@list:list to sort
 *@tail:tail of a dblinked list
 *@shaker:current node, one to swap
 *Return:void
 */
void swap_node_back(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmp = (*shaker)->prev;

	if ((*shaker)->next != NULL)
		(*shaker)->next->prev = tmp;
	else
		*tail = tmp;
	tmp->next = (*shaker)->next;
	(*shaker)->prev = tmp->prev;
	if (tmp->prev != NULL)
		tmp->prev->next = *shaker;
	else
		*list = *shaker;
	(*shaker)->next = tmp;
	tmp->prev = *shaker;
	*shaker = tmp;
}
/**
 *cocktail_sort_list - sorts a list using cocktail algorithm
 *@list:dblinked list to sort
 *Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *shaker;
	unsigned int shaken_unstirred = 0;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	/*tail point to last node*/
	for (tail = *list; tail->next != NULL; tail = tail->next)
		;
	while (shaken_unstirred == 0)
	{
		shaken_unstirred = 1;

		/*forward sorting*/
		for (shaker = *list; shaker != tail; shaker = shaker->next)
		{
			if (shaker->n > shaker->next->n)
			{
				swap_node_infront(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				shaken_unstirred = 0;
			}
		}
		for (shaker = shaker->prev; shaker != *list;
		     shaker = shaker->prev)
		{
			if (shaker->n < shaker->prev->n)
			{
				swap_node_back(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				shaken_unstirred = 0;
			}
		}
	}
}
