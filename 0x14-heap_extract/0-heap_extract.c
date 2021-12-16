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
* binary_tree_preorder - traverses in preorder
*  @tree: tree to traverse
*  @func: function to use to print
*  Return: void
*/

void binary_tree_preorder(binary_tree_t *tree, binary_tree_t *root)
{
	binary_tree_t *min = NULL;

	if (!tree)
		return;
	if (tree->left && !(tree)->right)
	{
		tree = tree->left;
		root->n = (tree)->n;
		min = (tree)->parent;
		if (min->left == (tree))
		min->left = NULL;
		else
		min->right = NULL;
		free(tree);

		return;
	}
	if (!(tree)->parent)
	{
		binary_tree_preorder((tree)->left, root);
		binary_tree_preorder((tree)->right, root);
	}
	else if ((tree)->left && (tree)->right)
	{
		binary_tree_preorder((tree)->left, root);
		binary_tree_preorder((tree)->right, root);
	}
	else if (tree->parent->right && tree->parent->left != tree)
	{
		for (min = root; min->left && min->right; min = min->right)
			;
		if (min == tree)
		{
			root->n = (tree)->n;
			min = (tree)->parent;
			if (min->left == (tree))
			min->left = NULL;
			else
			min->right = NULL;
			free(tree);
			return;
		}
		if (min->left == tree)
		{
		root = min->left;
		root->n = (tree)->n;
		min = (tree)->parent;
		if (min->left == (tree))
			min->left = NULL;
		else
			min->right = NULL;
		free(tree);
		return;
		}
		if (min->right == tree)
		{
		root = min->right;
		root->n = (tree)->n;
		min = (tree)->parent;
		if (min->left == (tree))
			min->left = NULL;
		else
			min->right = NULL;
		free(tree);
		return;
		}
	}
}

/**
 * binary_tree_is_full - checks if binary tree is full
 * @tree: pointer to the root node of the tree to check
 * Return: 0 if tree is NULL or not full
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);
	if ((tree->left) && (tree->right))
		return (binary_tree_is_full(tree->left) &&
		binary_tree_is_full(tree->right));
	return (0);
}

int heap_extract(heap_t **root)
{
	heap_t *min = *root;
	int ans, i, leaves = 1024, hold = 0;
	int *arr;

	if (!root || !(*root))
		return (0);
	ans = (*root)->n;

	arr = malloc(sizeof(int) * leaves);
	for (i = 0; i < leaves; i++)
		arr[i] = -2667;

	/* Extract root and replact with other node */
	binary_tree_preorder(*root, *root);

	for (min = *root; min->left;)
	{
		if (min->n < min->left->n)
		{
			hold = min->n;
			min->n = min->left->n;
			min->left->n = hold;
			min = min->left;
		}
		else if (min->n < min->right->n)
		{
			hold = min->n;
			min->n = min->right->n;
			min->right->n = hold;
			min = min->right;
		}
		else
			break;
	}

	free(arr);
	return (ans);
}
