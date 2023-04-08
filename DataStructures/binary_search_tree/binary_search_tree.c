#include <stdio.h>
#include <malloc.h>
#include "node.h"
#include "binary_search_tree.h"

struct binary_search_tree* create_tree()
{
    struct binary_search_tree* tree = (struct binary_search_tree*)malloc(sizeof(struct binary_search_tree));
    tree->root = NULL;
    return tree;
}

void add(struct binary_search_tree* tree, int value)
{
    if (tree->root == NULL)
    {
        tree->root = create_node(value);
        return;
    }

    struct node* temp = tree->root;
    while (temp)
    {
        if (temp->value <= value)
        {
            if (temp->right != NULL)
            {
                temp = temp->right;
                continue;
            }
            temp->right = create_node(value);
            return;
        }
        
        if (temp->left != NULL)
        {
            temp = temp->left;
            continue;
        }
        temp->left = create_node(value);
        return;
    }
}

struct node* find_min(struct node* root)
{
    if (root == NULL) return NULL;
    if (root->left == NULL) return root;
    return find_min(root->left);
}

struct node* find_max(struct node* root)
{
    if (root == NULL) return NULL;
    if (root->right == NULL) return root;
    return find_max(root->right);
}

struct node* find_elem(struct node* root, int value)
{
    if (root == NULL) return NULL;
    if (root->value == value) return root;
    if (root->value < value) return find_elem(root->right, value);
    return find_elem(root->left, value);
}

struct node* find_previous_elem(struct node* root, int value)
{
    if (root == NULL) return NULL;
    if (root->left == NULL && root->right == NULL) return NULL;
    if ((root->left != NULL && root->left->value == value) || (root->right != NULL && root->right->value == value)) return root;
    if (root->left != NULL && root->left->value == value) return find_previous_elem(root->right, value);
    return find_previous_elem(root->left, value);
}

void pre_order_print_node(struct node* root, int* arr, int* arr_size)
{
    if (!root) return;

    if (!root->left && !root->right)
    {
        arr[(*arr_size)++] = root->value;
        return;
    }

    arr[(*arr_size)++] = root->value;
    if (root->left) pre_order_print_node(root->left, arr, arr_size);
    if (root->right) pre_order_print_node(root->right, arr, arr_size);
}

void in_order_print_node(struct node* root, int* arr, int* arr_size)
{
    if (!root) return;

    if (!root->left && !root->right)
    {
        arr[(*arr_size)++] = root->value;
        return;
    }

    if (root->left) in_order_print_node(root->left, arr, arr_size);
    arr[(*arr_size)++] = root->value;
    if (root->right) in_order_print_node(root->right, arr, arr_size);
}

void post_order_print_node(struct node* root, int* arr, int* arr_size)
{
    if (!root) return;

    if (!root->left && !root->right)
    {
        arr[(*arr_size)++] = root->value;
        return;
    }

    if (root->left) post_order_print_node(root->left, arr, arr_size);
    if (root->right) post_order_print_node(root->right, arr, arr_size);
    arr[(*arr_size)++] = root->value;
}

int get_height(struct node* root)
{
    if(!root) return 0;
    int height_l = get_height(root->left);
    int height_r = get_height(root->right);
    return (height_l > height_r) ? height_l + 1 : height_r + 1;
}

void bfs(struct node* root, int* arr, int* arr_size)
{
    int h = get_height(root);
    for(int i = 0; i < h; i++)
        print_lvl(root, arr, arr_size, i);
}

void print_lvl(struct node* root, int* arr, int* arr_size, int lvl)
{
    if(!root) return;
    if(lvl == 0) 
    {
        arr[(*arr_size)++] =  root->value;
    }
    else
    {
        print_lvl(root->left, arr, arr_size, lvl - 1);
        print_lvl(root->right, arr, arr_size, lvl - 1);
    }
}  

void delete_elem(struct binary_search_tree* tree, int delete_elem)
{
    if (!tree->root) return;
    struct node* del_elem = find_elem(tree->root, delete_elem);
    if (!del_elem) return;
    struct node* pre_del_elem;

    if (!del_elem->left && !del_elem->right)
    {
        if (tree->root == del_elem)
        {
            free(tree->root);
            tree->root = NULL;
            return;
        }

        pre_del_elem = find_previous_elem(tree->root, delete_elem);
        if (pre_del_elem->left == del_elem) pre_del_elem->left = NULL;
        else pre_del_elem->right = NULL;
        free(del_elem);
        return;
    }

    if (del_elem->right && !del_elem->left)
    {
        if (tree->root == del_elem)
        {
            struct node* temp = del_elem->right;
            free(tree->root);
            tree->root = temp;
            return;
        }
        
        pre_del_elem = find_previous_elem(tree->root, delete_elem);
        struct node* temp = del_elem->right;
        free(del_elem);
        pre_del_elem->right = temp;
        return;
    }

    if (del_elem->left && !del_elem->right)
    {
        if (tree->root == del_elem)
        {
            struct node* temp = del_elem->left;
            free(tree->root);
            tree->root = temp;
            return;
        }

        pre_del_elem = find_previous_elem(tree->root, delete_elem);
        struct node* temp = del_elem->left;
        free(del_elem);
        pre_del_elem->left = temp;
        return;
    }

    struct node* max_l = find_max(del_elem->left);
    struct node* pre_max_l = find_previous_elem(del_elem, max_l->value);
    
    if (pre_max_l)
    {
        if (pre_max_l->left == max_l) pre_max_l->left = NULL;
        else pre_max_l->right = NULL;
    }

    struct node* del_l = del_elem->left;
    struct node* del_r = del_elem->right;

    max_l->left = del_l;
    max_l->right = del_r;

    if (tree->root == del_elem)
    {
        free(tree->root);
        tree->root = max_l;
        return;
    }

    pre_del_elem = find_previous_elem(tree->root, delete_elem);

    if (pre_del_elem->left == del_elem)
    {
        pre_del_elem->left = max_l;
        free(del_elem);
        return;
    }

    pre_del_elem->right = max_l;
    free(del_elem);
    return;
}

int compare(int* arr, int* test_arr, int arr_size)
{
    if (!arr || !test_arr) return 0;

    for (int i = 0; i < arr_size; ++i)
        if (arr[i] != test_arr[i]) return 0;

    return 1;
}

void delete_tree(struct binary_search_tree* tree)
{   
    if (!tree->root)
    {
        free(tree);
        return;
    }

    delete_node(tree->root);
    free(tree);
}