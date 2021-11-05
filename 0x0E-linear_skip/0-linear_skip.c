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
	skiplist_t *old_express = NULL, *express = NULL, *node = NULL;

	if (!list)
		return (NULL);
	
	node = list;

	if (node->n != value)
		express = node->express;
	else
		return (node);

	for (; express->next != NULL; express = express->next)
	{
		printf("Value checked at index [%lu] = [%d]\n", express->index, express->n);
		if (value < express->n)
			break;
		old_express = express;
	}

	printf("Value found between indexes [%lu] and [%lu]\n", old_express->index, express->index);
	return (NULL);

}
