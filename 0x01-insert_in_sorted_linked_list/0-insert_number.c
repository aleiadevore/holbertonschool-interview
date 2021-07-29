#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - inserts nod in sorted linked list
 * @head: head of linked list
 * @number: number to insert
 * 
 * Return: address of new node or NULL
 **/

listint_t *insert_node(listint_t **head, int number)
{
    int i;
    listint_t *new, *before = *head, *after = (*head)->next;

    /* insert in empty list */
    if (!*head)
        return NULL;

    /* allocate space for new node */
    new = malloc(sizeof(listint_t));
    new->n = number;

    /* insert at beginning */
    if (number < before->n)
    {
        new->next = before;
        return new;
    }

    /* progress through linked list*/
    for (i = 0; before != NULL; i++, before = before->next)
    {
        if (number > before->n)
        {
            if (!after)
            {
                before->next = new;
                new->next = NULL;
                return new;
            }
            /* assuming in case of duplicate to insert before first instance */
            else if (after->n >= number)
            {
                before->next = new;
                new->next = after;
                return new;
            }
        }
        if (after->next)
            after = after->next;
        else
            after = NULL;
    }
    free(new);
    return NULL;
}
