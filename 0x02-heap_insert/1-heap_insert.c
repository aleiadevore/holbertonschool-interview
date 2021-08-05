#include "binary_trees.h"

/**
* heap_insert - inserts value into Max Binary Heap
* @root: double pointer to the root node of heap
* @value: int n to store in node
*
* Return: pointer to node or NULL
*/

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *node = NULL, *new = NULL;

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		if (*root == NULL)
			return (NULL);
		return (*root);
	}
	// traverse tree to end
	binary_tree_height(root);
	node = *root;
	while(1)
	{
		if (!node->left || !node->right)
			break;
		else
			node = node->left;
		
	}

	// add new node
	new = binary_tree_node(node, value);
	if (!new)
		return (NULL);

	// heapify

	return (new);
}

/**
 * swap - swaps values of two nodes
 * 
 * @a: first node
 * @b: second node
 * 
 * Return: void
 */

void swap(binary_tree_t *a, binary_tree_t *b)
{
	int hold = a->n;

	a->n = b->n;
	b->n = hold;
}

/**
 * height_finder - measure the height of binary tree
 * @tree: pointer to root node of tree to measure height
 * Return: if tree is NULL return 0
 */

size_t height_finder(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return (0);
	left = height_finder(tree->left);
	right = height_finder(tree->right);
	if (left > right)
		return (left + 1);
	else
		return (right + 1);
}

/**
 * binary_tree_height - measure the height of binary tree
 * @tree: pointer to root node of tree to measure height
 * Return: if tree is NULL return 0
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t total;

	total = height_finder(tree);

	if (total == 0)
		return (total);
	return (total - 1);
}
// insert

// heapify