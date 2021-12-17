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

void sort(binary_tree_t *root)
{
	int hold;
	heap_t *tmp;

	if (!root->left && !root->right)
		return;

	if (root->right && root->right->n > root->left->n)
		tmp = root->right;
	else
		tmp = root->left;

	if (root->n < tmp->n)
	{
		hold = root->n;
		root->n = tmp->n;
		tmp->n = hold;
		sort(tmp);
	}
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
	int ans;

	if (!root || !(*root))
		return (0);
	ans = (*root)->n;

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

	sort(*root);

	return (ans);
}
