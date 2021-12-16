#include "binary_trees.h"


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
 * binary_tree_balance - returns balance factor
 * @tree: root of tree
 *
 * Return: balance factor
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int balance, l, r;

	if (!tree)
		return (0);
	l = height_finder(tree->left);
	r = height_finder(tree->right);
	balance = l - r;

	return (balance);
}

/**
 * sort - sorts new tree
 * @root: root of tree
 *
 * Return: tree
 */

binary_tree_t *sort(binary_tree_t *root)
{
	binary_tree_t *min = root;
	int balance = binary_tree_balance(root), hold;

	printf("Balance: %d\n", balance);
	if (balance == 1)
	{
		hold = min->n;
		min->n = min->left->n;
		min->left->n = hold;
		min = min->left;
	}
	while (min->left)
	{
		if (min->n < min->left->n)
		{
			hold = min->n;
			min->n = min->left->n;
			min->left->n = hold;
			min = min->left;
		}
		else if (min->right && min->n < min->right->n)
		{
			hold = min->n;
			min->n = min->right->n;
			min->right->n = hold;
			min = min->right;
		}
		else
			break;
	}
	return (root);
}


/**
 * heap_extract - extracts root of max heap
 * @root: root node of binary search tree
 *
 * Return: value of node deleted
 */

int heap_extract(heap_t **root)
{
	heap_t *min = *root, *tmp = NULL;
	int ans, i, leaves = 1024;
	int *arr;

	if (!root || !(*root))
		return (0);
	ans = (*root)->n;
	arr = malloc(sizeof(int) * leaves);
	for (i = 0; i < leaves; i++)
		arr[i] = -2667;
	while (min != NULL)
	{
		if (!min->left && !min->right)
			break;
		if (binary_tree_balance(min) <= 0)
			min = min->right;
		else
			min = min->left;
	}
	if (!min->parent)
	{
		ans = min->n;
		free(min);
		return (ans);
	}
	tmp = min->parent;
	(*root)->n = min->n;
	if (tmp->left == min)
		tmp->left = NULL;
	else
		tmp->right = NULL;
	free(min);

	*root = sort(*root);

	free(arr);
	return (ans);
}
