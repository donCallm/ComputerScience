#ifndef NODE_H
#define NODE_H

struct node
{
    int data;
    struct node *next;
};

struct node* create_node();
void delete_node(struct node *nd);

#endif