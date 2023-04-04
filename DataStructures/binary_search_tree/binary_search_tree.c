#include <malloc.h>
#include "queue.h"
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

struct node* find_min(struct node* nd)
{
    if (nd == NULL)
        return NULL;
    
    if (nd->left == NULL)
        return nd;

    struct node* min = nd->left;

    min = find_min(min);

    return min;
}

struct node* find_max(struct node* nd)
{
    if (nd == NULL)
        return NULL;
    
    if (nd->right == NULL)
        return nd;

    struct node* max = nd->right;

    max = find_max(max);

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

void straight_print_node(struct node* nd)
{
    if (!nd) return;

    if (!nd->left && !nd->right)
    {
        printf("%d ", nd->value);
        return;
    }

    printf("%d ", nd->value);
    if (nd->left) straight_print_node(nd->left);
    if (nd->right) straight_print_node(nd->right);
}

void symmetric_print_node(struct node* nd)
{
    if (!nd) return;

    if (!nd->left && !nd->right)
    {
        printf("%d ", nd->value);
        return;
    }

    if (nd->left) symmetric_print_node(nd->left);
    printf("%d ", nd->value);
    if (nd->right) symmetric_print_node(nd->right);
}

void back_print_node(struct node* nd)
{
    if (!nd) return;

    if (!nd->left && !nd->right)
    {
        printf("%d ", nd->value);
        return;
    }

    if (nd->left) back_print_node(nd->left);
    if (nd->right) back_print_node(nd->right);
    printf("%d ", nd->value);
}

void width_print_node(struct node* nd)
{
    if (!nd) return;

    if (!nd->left && !nd->right)
    {
        printf("%d ", nd->value);
        return;
    }

    struct queue* qu = create_queue();
    struct node temp;
    push(qu, nd);

    while (qu->size != 0)
    {   
        temp = pop(qu);
        int test = temp.value;
        printf("%d ", test);
        
        if (temp.left) push(qu, temp.left);
        if (temp.right) push (qu, temp.right);
    }
    delete_queue(qu);
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

        if(pre_del_elem)
        {
            if (pre_del_elem->left == del_elem)
                pre_del_elem->left = NULL;
            else
                pre_del_elem->right = NULL;
        }
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
    
    if (pre_max_l->left == max_l)
        pre_max_l->left = NULL;
    else    
        pre_max_l->right = NULL;

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