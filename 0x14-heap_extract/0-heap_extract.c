#include "binary_trees.h"

int *heapify(int *arr, int size, int i)
{
    int largest = i, hold;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < size && arr[l] > arr[largest])
        largest = l;
    if (r < size && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        hold = arr[i];
        arr[i] = arr[largest];
        arr[largest] = hold;
        heapify(arr, size, largest);
    }
  return arr;
}


int *to_array(int *arr, int n, int a_size)
{
    int i;

    for (i = 0; i < a_size; i++)
    {
        if (arr[i] == -2667)
        {
            arr[i] = n;
            return (arr);
        }
    }
    return (arr);
}

int *binary_tree_preorder(const binary_tree_t *tree, int *arr, int a_size)
{
	if (!tree)
		return arr;
	arr = to_array(arr, tree->n, a_size);
	binary_tree_preorder(tree->left, arr, a_size);
    binary_tree_preorder(tree->right, arr, a_size);
    return arr;
}

int *build_tree(binary_tree_t *tree, int *arr, int a_size, int layer)
{
    binary_tree_t *node = tree;
    int i = 0, count = 0;

    if (!tree || layer == a_size)
		return arr;
    if (layer != 0)
    {
        for (layer = 0; i < a_size && node->parent; layer++)
        {
            count += (layer * layer - (layer - layer));
            if (node->parent->right->n == node->n)
                count++;
            node = node->parent;
        }
    }
	tree->n = arr[count];
	build_tree(tree->left, arr, a_size, 1);
    build_tree(tree->right, arr, a_size, 1);
    return arr;
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
    heap_t *min = *root, *min_p = NULL;
    int ans = (*root)->n, i, leaves = 1024, hold = 0, check;
    int *arr;

    /*leaves = binary_tree_leaves(*root);*/
    arr = malloc(sizeof(int) * leaves);
    for (i = 0; i < leaves; i++)
        arr[i] = -2667;

    /* Extract root and replact with other node */
    check = binary_tree_is_full(*root);
    if (check == 0)
    {
        while (min->left)
            min = min->left;
        min_p = min->parent;
    }
    else
    {
        while (min->right)
            min = min->right;
        min_p = min->parent;
    }
    
    (*root)->n = min->n;
    if (check == 0)
        min_p->left = NULL;
    else
        min_p->right = NULL;
    free(min);

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

    /* Heapify */
    /*arr = binary_tree_preorder(*root, arr, leaves);
    for (i = 0; i < leaves && arr[i] != -2667; i++)
        size++;
    for (i = size / 2 - 1; i >= 0; i--)
        arr = heapify(arr, 90, i);
    for (i = 0; i < size && arr[i] != -2667; i++)
        printf("%d\n", arr[i]);*/
    
    /*build_tree(*root, arr, size, 0);*/

    /* Turn into binary tree */
    free(arr);
    return ans;
}