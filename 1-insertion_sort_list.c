#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order (smallest to largest) using insertion sort
 * @list: double pointer to the list to be sorted
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *s_tail, *next, *after, *before, *curr, *curr_prev;

	/* the sorted part is assumed to be the first node */
	s_tail = *list; /* begin with (sorted tail) == head of list */
	if (!s_tail) /* list is NULL */
		return;
	for (next = s_tail->next; next != NULL; s_tail = next, next = next->next)
	{ /* compare the sorted set of nodes with the next unsorted node */
		if (s_tail->n > next->n) /* swap */
		{ /* compare next with its previous, going backwards */
			curr = next;
			curr_prev = s_tail; /* i.e. next->prev */
			while (curr_prev)
			{
				if (curr_prev->n > curr->n)
				{ /* then swap the nodes */
					before = curr_prev->prev;
					if (before)
						before->next = curr;
					else
						*list = curr; /* update head of list */
					curr_prev->prev = curr;
					after = curr->next;
					curr->next = curr_prev;
					if (after)
						after->prev = curr_prev;
					curr_prev->next = after;
					curr->prev = before;
					print_list(*list); /* print list after swap */
				} /* update curr_prev & curr - to the node before it */
				curr = curr_prev; /* the node we've just swapped */
				curr_prev = curr_prev->prev;
			}
		} /* else update s_tail to next & get next unsorted node*/
	}
}
