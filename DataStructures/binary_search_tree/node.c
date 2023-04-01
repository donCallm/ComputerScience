#include <malloc.h>
#include "node.h"

struct node* create_node(int value)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void delete_node(struct node* nd)
{
    if (nd == NULL)
        return;
    
    if (nd->left == NULL && nd->right == NULL)
    {
        free(nd);
        nd = NULL;
        return;
    }
    
    if (nd->left != NULL)
        delete_node(nd->left);
    
    if (nd->right != NULL)
        delete_node(nd->right);

    free(nd);
}