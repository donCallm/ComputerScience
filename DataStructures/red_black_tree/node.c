#include <malloc.h>
#include <stdio.h>
#include "node.h"

struct node* create_node(int value)
{
    struct node* nd = (struct node*)malloc(sizeof(struct node));
    nd->value = value;
    nd->color = RED;
    nd->parent = NULL;
    nd->left = NULL;
    nd->right = NULL;
    return nd;
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