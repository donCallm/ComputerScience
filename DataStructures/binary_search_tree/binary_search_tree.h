#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

struct binary_search_tree
{
    struct node* head;
};

struct binary_search_tree* create_tree();
void add(struct binary_search_tree* tree, int value);

#endif