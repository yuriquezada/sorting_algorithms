#include "sort.h"

/**
 * cocktail_sort_list - Sort list
 * @list: list
 *
 * Return: Nothing
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *turtle = NULL;
	listint_t *rabbit = NULL;
	int left_limit = -1;
	int right_limit = -1;
	int count = 0, flag = 0;

	if (!list || !(*list) || (!((*list)->prev) && !((*list)->next)))
		return;
	turtle = *list;
	rabbit = (*list)->next;
	while (left_limit <= right_limit)
	{
		left_limit++;
		while (turtle && rabbit && count != right_limit)
		{
			if (turtle->n > rabbit->n)
				swap_nodes(&turtle, &rabbit, list), print_list(*list), flag = 1;
			turtle = turtle->next;
			rabbit = rabbit->next;
			count++;
		}
		if (left_limit == 0)
			right_limit = count;
		right_limit--;
		turtle = turtle->prev;
		rabbit = turtle->prev;
		while (turtle && rabbit && count >= left_limit)
		{
			if (turtle->n < rabbit->n)
				swap_nodes(&rabbit, &turtle, list), print_list(*list), flag = 1;
			turtle = turtle->prev;
			rabbit = rabbit->prev;
			count--;
		}
		if (flag == 0)
			break;
		flag = 0;
		turtle = turtle->next;
		rabbit = turtle->next;
	}
}

/**
 * swap_nodes - Swap nodes
 * @turtle: List1
 * @rabbit: list2
 * @list: List
 *
 * Return: Nothing
 */
void swap_nodes(listint_t **turtle, listint_t **rabbit, listint_t **list)
{
	listint_t *before;
	listint_t *after;

	if (!(*turtle) || !(*rabbit))
		return;
	before = (*turtle)->prev;
	after = (*rabbit)->next;

	if (before)
		before->next = (*rabbit);
	(*rabbit)->prev = before;
	(*rabbit)->next = (*turtle);
	(*turtle)->prev = (*rabbit);
	(*turtle)->next = after;

	if (after)
		after->prev = (*turtle);
	*turtle = *rabbit;
	*rabbit = (*turtle)->next;

	if (!before)
		*list = *turtle;
}
