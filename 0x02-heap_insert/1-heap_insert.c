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
	heap_t *node = NULL, *new = NULL, *temp = *root;
	int height, i = 0;

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		if (*root == NULL)
			return (NULL);
		return (*root);
	}
	/*traverse tree to end */
	height = binary_tree_height(*root);
	node = *root;
	while (1)
	{
		if (!node->left || !node->right)
			break;
		if (i == height - 1)
		{
			node = temp;
			temp = temp->right;
			i = 0;
			height -= 1;
		}
		node = node->left;
		i += 1;
	}

	/* add new node */
	new = binary_tree_node(node, value);
	if (!new)
		return (NULL);

	/* heapify */
	if (new->parent && new->n > new->parent->n)
	{
		swap(new, new->parent);
		printf("Swapped\n");
		return (new->parent);
	}
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
 * binary_tree_height - finds height of binary tree
 * @tree: root of tree
 * Return: height of tree
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return (0);
	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);
	if (left > right)
		return (left + 1);
	else
		return (right + 1);
}

/**
 * print_level - prints all nodes at given level
 * @tree: root of tree
 * @level: tree level
 * @func: function to print value
 * Return: void
 */

void print_level(const binary_tree_t *tree, int level, void (*func)(int))
{
	if (!tree)
		return;
	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		print_level(tree->left, level - 1, func);
		print_level(tree->right, level - 1, func);
	}
}

/**
 * binary_tree_levelorder - prints in level order
 * @tree: root of tree
 * @func: function to print node value
 * Return: void
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int i, height;

	if (!tree || !func)
		return;

	height = binary_tree_height(tree);

	for (i = 0; i <= height; i++)
		print_level(tree, i, func);
}

