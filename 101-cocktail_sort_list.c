#include "sort.h"

/**
 * swap_nodes_forward - swaps the the next node with the current
 * @list: double pointer to doubly linked list
 * @curr: pointer to the current node
 * @next: pointer to current's next
 * Return: Nothing
 */
void swap_nodes_forward(listint_t **list, listint_t *curr, listint_t *next)
{
	listint_t *before, *after;

	before = curr->prev;
	if (before)
		before->next = next;
	else
		*list = next; /* update head of list */
	curr->prev = next;
	after = next->next;
	next->next = curr;
	if (after)
		after->prev = curr;
	curr->next = after;
	next->prev = before;
}

/**
 * swap_nodes_backward - swaps the the previous node with the current
 * @list: double pointer to doubly linked list
 * @curr: pointer to the current node
 * @prev: pointer to current's prev node
 * Return: Nothing
 */
void swap_nodes_backward(listint_t **list, listint_t *curr, listint_t *prev)
{
	listint_t *before, *after;

	before = prev->prev;
	if (before)
		before->next = curr;
	else
		*list = curr; /* update head of list */
	prev->prev = curr;
	after = curr->next;
	curr->next = prev;
	if (after)
		after->prev = prev;
	prev->next = after;
	curr->prev = before;
}

/**
 * cocktail_sort_list - sorts array in (ascending) using cocktail shaker sort
 * Description: is an improvement of bubble sort -> uses bidirectional movement
 * fasten the moving of items to the beginning of the array: bubble sort only
 * moves items in one direction
 * @list: double pointer to the linked list to sort
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *start, *end, *left, *right;
	int sorted = 0;

	if (!list) /* if list is undefined */
		return;
	/* start and end mark the first and last node to check */
	left = *list; /* start @ head of list */
	if (left == NULL || left->next == NULL)
		return; /* empty list or one node list (sorted) */
	while (!sorted)
	{
		sorted = 1; /* advance & swap forward */
		for (right = *list; right->next != NULL; right = right->next)
		{
			end = right->next;
			if (end && right->n > end->n)
			{
				sorted = 0;
				/* swap the two nodes, right(before end) & end */
				swap_nodes_forward(list, right, end);
				print_list(*list); /* print list after swap */
				right = end; /*i.e. retain I advance position in list */
			}
		} /* decrease right since the nodes after end are in correct order */
		if (end)
			right = end;
		/* advance & swap backwards */
		if (left == right) /* just 2 elements, no need for backward swap */
			return;
		for (left = right; left->prev != NULL; left = left->prev)
		{
			start = left->prev;
			if (start && start->n > left->n)
			{ /* swap the two nodes, start(before left) & left */
				sorted = 0;
				swap_nodes_backward(list, left, start);
				print_list(*list); /* print list after swap */
				left = start; /*i.e. retain I advance position in list */
			}
		} /* increase left since the element before start are sorted */
		left = start;
		right = left; /* update right to left */
	}
}
