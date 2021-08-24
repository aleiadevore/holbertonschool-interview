#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - determines if singly linked list is a palindrome
 * @head: pointer to head of linked list
 * 
 * Return: 0 if not a palindrom, 1 if it is
 */

int is_palindrome(listint_t **head)
{
    int i = 0, length;
    int buffer[1024];
    listint_t *node = *head;

    if (head == NULL)
        return (1);

    for (length = 0; length < 1024; length++)
        buffer[length] = '\0';

    for (; node != NULL; node = node->next, i++)
        buffer[i] = node->n;

    /* Set length, then traverse from both sides */
    for (length = 0; buffer[length]; length++)
        ;

    for (i = 0, length--; length > 0; i++, length--)
    {
        if (buffer[i] != buffer[length])
            return 0;
    }
    

    return 1;
}
