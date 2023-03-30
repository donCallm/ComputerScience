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