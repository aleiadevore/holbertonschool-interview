#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * is_palindrome - determines if singly linked list is a palindrome
 * @head: pointer to head of linked list
 * 
 * Return: 0 if not a palindrom, 1 if it is
 */

int is_palindrome(listint_t **head)
{
	int s1[1024];
	int i, j;

	for (i = 0; i < 1024; i++)
	{
		s1[i] = '\0';
	}
	i = construct(*head, s1, -1);
	if (i == 1)
		return (1);
	for (j = 0, i--; i > 0; j++, i--)
	{
		if (s1[i] != s1[j])
			return (0);
	}

	return (1);
}

int construct(listint_t *head, int *s1, int i)
{
	i++;

	if (head == NULL)
		return i;

	s1[i] = head->n;

	return construct(head->next, s1, i);
}
