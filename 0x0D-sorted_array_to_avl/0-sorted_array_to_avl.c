#include "binary_trees.h"

/**
 * sorted_array_to_avl - builds AVL tree from array
 * @array: pointer to first element in array to convert
 * @size: size of array
 *
 * Return: avl tree
 */

/* assume no duplicate value in array */
/* not allowed to rotate */
/* Can only have three functions in file */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;

	root = recursive_call(array, array[0], array[size - 1]);
	return (root);
}

avl_t *recursive_call(int *array, int start, int end)
{
	int mid;
	avl_t *root;

	if (start > end)
		return (NULL);

	mid = (start + end)/2;
	root = newNode(array[mid]);

	root->left = recursive_call(array, start, mid - 1);
	root->right = recursive_call(array, mid + 1, end);

	return root;
}

avl_t *newNode(int n)
{
	avl_t *node = NULL;

	node = malloc(sizeof(avl_t));
	if (!node)
		return (NULL);
	node->n = n;
	node->left = NULL;
	node->right = NULL;

	return (node);
}
