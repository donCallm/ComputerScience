#ifndef NODE_H
#define NODE_H

#define RED 1
#define BLACK 0

struct node
{
    int color;
    int value;
    struct node* parent;
    struct node* left;
    struct node* right;
};

struct node* create_node(int value);
void delete_node(struct node* nd);

#endif