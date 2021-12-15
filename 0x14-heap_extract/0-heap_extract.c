#include "binary_trees.h"

int *swap(int *arr, int i, int largest)
{
    int hold;

    hold = arr[i];
    arr[i] = arr[largest];
    arr[largest] = hold;

    return arr;
}

int *heapify(int *arr, int size, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < size && arr[l] > arr[largest])
      largest = l;
    if (r < size && arr[r] > arr[largest])
      largest = r;
    if (largest != i)
    {
      arr = swap(arr, i, largest);
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


int heap_extract(heap_t **root)
{
    heap_t *min = *root, *min_p = NULL;
    int ans = (*root)->n, i, leaves = 1024, size = 0;
    int *arr;

    /*leaves = binary_tree_leaves(*root);*/
    arr = malloc(sizeof(int) * leaves);
    for (i = 0; i < leaves; i++)
        arr[i] = -2667;

    /* Extract root and replact with other node */
    while (min->left)
        min = min->left;
    min_p = min->parent;
    
    (*root)->n = min->n;
    min_p->left = NULL;
    free(min);

    /* Heapify */
    arr = binary_tree_preorder(*root, arr, leaves);
    for (i = 0; i < leaves && arr[i] != -2667; i++)
        size++;
    for (i = size / 2 - 1; i >= 0; i--)
        arr = heapify(arr, 90, i);
    for (i = 0; i < size && arr[i] != -2667; i++)
        printf("%d\n", arr[i]);

    /* Turn into binary tree */
    free(arr);
    return ans;
}