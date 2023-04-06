#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

struct binary_search_tree
{
    struct node* root;
};

struct binary_search_tree* create_tree();
void add(struct binary_search_tree* tree, int value);
void delete_tree(struct binary_search_tree* tree);
struct node* find_elem(struct node* nd, int value);
struct node* find_min(struct node* nd);
struct node* find_max(struct node* nd);
struct node* find_previous_elem(struct node* nd, int value);
void delete_elem(struct binary_search_tree* tree, int delete_elem);
void in_order_print_node(struct node* nd);
void pre_order_print_node(struct node* nd);
void post_order_print_node(struct node* nd);
int get_height(struct node* root);
void bfs(struct node* root);
void print_lvl(struct node* root, int lvl);

#endif