#include "lists.h"

/**
 * check_cycle: checks if linked list has a cycle in it
 *
 * @list: list to check
 * Return: 0 if no cycle, 1 if there is a cycle
 */

int check_cycle(listint_t *list)
{
	listint_t *slow = list;
	listint_t *fast;

	if (list == NULL)
		return 0;

	fast = list->next;

	while (slow != NULL && fast != NULL)
	{
		if (slow->n == fast->n)
			return (1);
		slow = slow->next;
		if (fast->next && fast->next->next)
			fast = fast->next->next;
		else
			break;
	}
	return (0);
}
