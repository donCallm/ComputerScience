#include <malloc.h>
#include "node.h"

struct node* create_node()
{
    struct node* nd = (struct node*)malloc(sizeof(struct node));
    nd->data = 0;
    nd->next = NULL;
    return nd;
}

void delete_node(struct node *nd)
{
    free(nd);
}