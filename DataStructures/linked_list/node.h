#ifndef NODE_H
#define NODE_H

struct node
{
    int data;
    struct node *next;
};

void create_node(struct node *ndm, int value);
void delete_node(struct node *nd);

#endif