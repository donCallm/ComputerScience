#ifndef RBT_H
#define RBT_H

struct rbt
{
    struct node* root;
};

struct rbt* create_rbt();
struct node* find_previous_elem(struct node* root, int value);
void add_elem(struct rbt* tree, int value);
void left_rotate(struct rbt* tree, struct node* g);
void right_rotate(struct rbt* tree, struct node* g);
void fixup(struct rbt* tree, struct node* root);
struct node* find_elem(struct node* root, int value);
struct node* find_min(struct node* root);
struct node* find_max(struct node* root);
void del_red_elem(struct rbt* tree, struct node* del_elem);
void del_black_elem_with_red_parent(struct rbt* tree, struct node* del_elem);
void del_black_elem_with_black_parent(struct rbt* tree, struct node* del_elem);
void del_brother_is_black(struct rbt* tree, struct node* g,  struct node* del_elem);
void del_brother_is_red(struct rbt* tree, struct node* g, struct node* del_elem);
void swap(struct rbt* tree, struct node* del_elem);
void del_black_elem(struct node* g, struct node* del_elem);
void pre_order_print_node(struct node* root, int* arr, int* arr_size);
void in_order_print_node(struct node* root, int* arr, int* arr_size);
void post_order_print_node(struct node* root, int* arr, int* arr_size);
int get_height(struct node* root);
void bfs(struct node* root, int* arr, int* arr_size);
void print_lvl(struct node* root, int* arr, int* arr_size, int lvl);
int compare(int* arr, int* test_arr, int arr_size);
void delete_elem(struct rbt* tree, int delete_elem);
void delete_rbt(struct rbt* tree);

#endif