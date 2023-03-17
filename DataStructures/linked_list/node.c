#include <malloc.h>
#include "node.h"

void create_node(struct node *nd, int value)
{
    nd->data = value;
    nd->next = NULL;
}

void delete_node(struct node *nd)
{
    free(nd->next);
    free(nd);
}