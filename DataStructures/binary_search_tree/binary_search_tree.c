#include <malloc.h>
#include "node.h"
#include "binary_search_tree.h"

struct binary_search_tree* create_tree()
{
    struct binary_search_tree* tree = (struct binary_search_tree*)malloc(sizeof(struct binary_search_tree));
    tree->head = NULL;
    return tree;
}

void add(struct binary_search_tree* tree, int value)
{
    if (tree->head == NULL)
    {
        tree->head = create_node(value);
        return;
    }

    struct node* temp = tree->head;
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

struct node* find_min(struct node* nd)
{
    if (nd == NULL)
        return NULL;
    
    if (nd->left == NULL)
        return nd;

    struct node* min = nd->left;

    while (min->left)
        min = min->left;

    return min;
}

struct node* find_max(struct node* nd)
{
    if (nd == NULL)
        return NULL;
    
    if (nd->right == NULL)
        return nd;

    struct node* max = nd->right;

    while (max->right)
        max = max->right;

    return max;
}

struct node* find_elem(struct node* nd, int value)
{
    if (nd == NULL)
        return NULL;
    
    if (nd->value == value)
        return nd;

    struct node* temp;

    if (nd->value < value)
    {
        temp = find_elem(nd->right, value);
        
        if (temp != NULL)
            return temp;
    }

    temp = find_elem(nd->left, value);
    if (temp != NULL)
        return temp;

    return NULL;
}

struct node* find_previous_elem(struct node* nd, int value)
{
    if (nd == NULL)
        return NULL;
    
    if (nd->left == NULL && nd->right == NULL)
        return NULL;

    if ((nd->left != NULL && nd->left->value == value) || (nd->right != NULL && nd->right->value == value))
        return nd;

    struct node* temp;

    if (nd->left != NULL && nd->left->value <= value)
    {
        temp = find_previous_elem(nd->right, value);
        
        if (temp != NULL)
            return temp;
    }

    temp = find_previous_elem(nd->left, value);
    if (temp != NULL)
        return temp;

    return NULL;
}

void delete_elem(struct binary_search_tree* tree, int delete_elem)
{
    if (tree->head == NULL)
        return;

    struct node* del_elem = find_elem(tree->head, delete_elem);

    if (del_elem->left == NULL && del_elem->right == NULL)
    {
        free(del_elem);
        return;
    }

    struct node* pre_del_elem;

    if (del_elem->left != NULL && del_elem->right != NULL)
    {
        struct node* max_l = find_max(del_elem->left);
        struct node* pre_max_l = find_previous_elem(del_elem, max_l->value);
        
        if (pre_max_l->left == max_l)
            pre_max_l->left = NULL;
        else    
            pre_max_l->right = NULL;

        struct node* del_l = del_elem->left;
        struct node* del_r = del_elem->right;

        max_l->left = del_l;
        max_l->right = del_r;

        if (tree->head == del_elem)
        {
            free(tree->head);
            tree->head = max_l;
            return;
        }

        pre_del_elem = find_previous_elem(tree->head, delete_elem);

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

    pre_del_elem = find_previous_elem(tree->head, delete_elem);

    if (pre_del_elem->left == del_elem)
    {
        pre_del_elem->left = (del_elem->left == NULL) ? del_elem->right : del_elem->right;
        return;
    }

    pre_del_elem->right = (del_elem->left == NULL) ? del_elem->right : del_elem->right;
}

void delete_tree(struct binary_search_tree* tree)
{   
    if (tree->head == NULL)
    {
        free(tree);
        return;
    }

    if (tree->head->left == NULL && tree->head->right == NULL)
    {
        free(tree->head);
        free(tree);
        return;
    }

    delete_node(tree->head);

    free(tree);
}