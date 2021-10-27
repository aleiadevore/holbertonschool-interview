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

	if (!array)
		return (NULL);
	root = recursive_call(array, 0, size - 1, NULL);
	return (root);
}

/**
 * recursive_call - recursive engine of algorithm
 * @array: array to turn into tree
 * @start: starting index
 * @end: ending index
 * @parent: parent of new node
 *
 * Return: root of tree
 */

avl_t *recursive_call(int *array, int start, int end, avl_t *parent)
{
	int mid;
	avl_t *root = NULL;

	/*printf("Start: %d, End: %d\n", start, end);*/
	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	/*printf("Mid: %d\n", mid);*/
	root = newNode(array[mid], parent);
	if (!root)
		return (NULL);

	root->left = recursive_call(array, start, mid - 1, root);
	root->right = recursive_call(array, mid + 1, end, root);

	return (root);
}

/**
 * newNode - creates a new node
 * @n: n value of node
 * @parent: parent of new node
 *
 * Return: pointer to node
 */

avl_t *newNode(int n, avl_t *parent)
{
	avl_t *node = NULL;

	node = malloc(sizeof(avl_t));
	if (!node)
		return (NULL);
	node->n = n;
	node->left = NULL;
	node->right = NULL;
	node->parent = parent;

	return (node);
}
