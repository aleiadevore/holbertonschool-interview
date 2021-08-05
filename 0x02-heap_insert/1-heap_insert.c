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
	if (*root == NULL)
	{
		printf("No root\n");
		*root = binary_tree_node(NULL, value);
		printf("%d\n", (*root)->n);
		return (*root);
	}
	printf("Not null\n");
	return (NULL);
}
