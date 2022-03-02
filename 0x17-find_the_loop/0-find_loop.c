#include "lists.h"
#include <stdio.h>

/**
 * find_listint_loop - finds loop in linked list
 * @head: head of linked list
 *
 * Return: address of node where loop starts or NULL if there is no loop
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *fast, *slow;

	if (!head || head->next == NULL)
	return (NULL);

	slow = head->next;
	if (!slow->next || slow->next == head)
		return (head);

	for (fast = slow->next; fast && fast->next; slow = slow->next)
	{
		if (slow == fast)
			break;
		fast = fast->next->next;
	}
	if (slow != fast)
		return (NULL);

	for (slow = head; slow != fast; slow = slow->next)
		fast = fast->next;
	return (slow);
}
