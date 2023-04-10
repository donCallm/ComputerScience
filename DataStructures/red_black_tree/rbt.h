#ifndef RBT_H
#define RBT_H

struct rbt
{
    struct node* root;
};

struct rbt* create_rbt();
struct node* find_previous_elem(struct node* root, int value);
void add_elem(struct rbt* tree, int value);
void left_rotate(struct node* g);
void right_rotate(struct node* g);
void fixup(struct node* root);
void delete_rbt(struct rbt* tree);

#endif