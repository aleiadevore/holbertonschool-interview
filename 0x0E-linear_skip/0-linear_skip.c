#include "search.h"

/**
 * linear_skip - finds value in linear skip list
 * @list: list to check
 * @value: value to find
 *
 * Return: node to value
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *prev = NULL, *express = NULL;

	if (!list)
		return (NULL);

	prev = list;
	express = list->express;
	for (; express->n <= value && express->next; express = express->express)
	{
		prev = express;
		printf("Value checked at index [%lu] = [%d]\n", express->index, express->n);
		if (!express->express)
		{
			while (express->next && express->n < value)
				express = express->next;
			break;
		}
	}
	printf("Value checked at index [%lu] = [%d]\n", express->index, express->n);
	printf("Value found between indexes [%lu] and [%lu]\n",
		prev->index, express->index);
	while (prev->n <= value && prev)
	{
		printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
		if (prev->n == value)
			return (prev);
		if (!prev->next)
			break;
		prev = prev->next;
	}

	return (NULL);
}
