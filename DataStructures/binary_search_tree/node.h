#ifndef NODE_H
#define NODE_H

struct node
{
    int value;
    struct node* left;
    struct node* right;
};

struct node* create_node(int value);
void delete_node(struct node* nd);

#endif