#include <malloc.h>
#include "node.h"
#include "binary_search_tree.h"

struct binary_search_tree* create_tree()
{
    struct binary_search_tree* tree = (struct binary_search_tree*)malloc(sizeof(struct binary_search_tree));
    tree->head = NULL;
    return tree;
}

void add(struct binary_search_tree* tree, int value)
{
    if (tree->head == NULL)
    {
        tree->head = create_node(value);
        return;
    }

    struct node* temp = tree->head;
    while (temp)
    {
        if (temp->value <= value)
        {
            if (temp->right != NULL)
            {
                temp = temp->right;
                continue;
            }
            temp->right = create_node(value);
            return;
        }
        
        if (temp->left != NULL)
        {
            temp = temp->left;
            continue;
        }
        temp->left->value = value;
    }
}