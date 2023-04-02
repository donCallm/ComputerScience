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
    if (!nd)
        return;
    
    if (nd->left)
        delete_node(nd->left);
    
    if (nd->right)
        delete_node(nd->right);

    free(nd);
}