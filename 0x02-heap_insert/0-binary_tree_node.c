#include "binary_trees.h"

/**
 * binary_tree_node - Adds node to binary tree
 * 
 * @parent:  pointer to parent node of new node
 * @value: int n to assign to new node
 * 
 * Return: pointer to new node or NULL
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    binary_tree_t *new = NULL;

    new = malloc(sizeof(binary_tree_t));
    if (!new)
        return NULL;
    
    new->n = value;
    new->left = NULL;
    new->right = NULL;
    
    if (parent->left == NULL)
        parent->left = new;
    else if (parent->right == NULL)
        parent->right = new;
    else
        return NULL;
    
    return new;
}
