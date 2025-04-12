#include <stdio.h>
#include <malloc.h>
#include "rbt.h"
#include "node.h"

struct rbt* create_rbt()
{
    struct rbt* tree = (struct rbt*)malloc(sizeof(struct rbt));
    tree->root = NULL;
    return tree;
}

struct node* find_previous_elem(struct node* root, int value)
{
    if (root == NULL) return NULL;
    if (root->left == NULL && root->right == NULL) return NULL;
    if ((root->left != NULL && root->left->value == value) || (root->right != NULL && root->right->value == value)) return root;
    if (root->left != NULL && root->left->value == value) return find_previous_elem(root->right, value);
    return find_previous_elem(root->left, value);
}

void add_elem(struct rbt* tree, int value)
{
    if (!tree) return;
    if (!tree->root)
    {
        tree->root = create_node(value);
        tree->root->color = BLACK; 
        return;
    }

    struct node* iter = tree->root;

    while (iter)
    {
        if (iter->value <= value)
        {
            if (iter->right != NULL)
            {
                iter = iter->right;
                continue;
            }
            iter->right = create_node(value);
            iter->right->parent = iter;
            fixup(tree, iter->right);
            break;
        }
        
        if (iter->left != NULL)
        {
            iter = iter->left;
            continue;
        }
        iter->left = create_node(value);
        iter->left->parent = iter;
        fixup(tree, iter->left);
        break;
    }

}

void left_rotate(struct rbt* tree, struct node* g)
{
    struct node* p = g->right;
    g->right = NULL;

    if (!p->left)
    {
        p->parent = g->parent;
        if (tree->root == g) tree->root = p;
        else if (g->parent->left == g) g->parent->left = p;
        else g->parent->right = p;
        g->parent = p;
        p->left = g;
        g->color = RED;
        p->color = BLACK;
        return;
    }

    struct node* x = p->left;
    p->left = NULL;
    if (tree->root == g) tree->root = x;
    x->parent = g->parent;
    p->parent = x;
    g->parent = x;
    x->left = g;
    x->color = BLACK;
    g->color = RED;
}

void right_rotate(struct rbt* tree, struct node* g)
{
    struct node* p = g->left;
    g->left = NULL;

    if (!p->right)
    {   
        p->parent = g->parent;
        if (tree->root == g) tree->root = p;
        else if (g->parent->left == g) g->parent->left = p;
        else g->parent->right = p;
        g->parent = p;
        p->right = g;
        g->color = BLACK;
        p->color = RED;
        return;
    }

    struct node* x = p->right;
    p->right = NULL;
    if (tree->root == g) tree->root = x;
    p->parent = x;
    x->parent = g->parent;
    g->parent = x;
    x->left = p;
    x->right = g;
    x->color = BLACK;
    g->color = RED;
}

void fixup(struct rbt* tree, struct node* root)
{
    if (!root || !root->parent) return;

    if (root->color == RED && root->parent->color == RED)
    {
        struct node* g = root->parent->parent;
        if (g)
        {
            if (g->left == root->parent)
            {
                if (g->right && g->right->color == RED)
                {
                    g->color = RED;
                    g->right->color = BLACK;
                    root->parent->color = BLACK;
                    fixup(tree, g);
                }
                else 
                {
                    right_rotate(tree, g);
                }
                return;
            }
            if (g->left && g->left->color == RED)
            {
                g->color = RED;
                g->left->color = BLACK;
                root->color = BLACK;
                fixup(tree, g);
            }
            else 
            {
                left_rotate(tree, g);
            }
        }
    }
    if (tree->root->color != BLACK) tree->root->color = BLACK;
}

struct node* find_elem(struct node* root, int value)
{
    if (root == NULL) return NULL;
    if (root->value == value) return root;
    if (root->value < value) return find_elem(root->right, value);
    return find_elem(root->left, value);
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

void del_black_elem(struct node* g, struct node* del_elem)
{
    if (g->left == del_elem)
    {
        if (!del_elem->right && !del_elem->left)
        {
            g->left = NULL;
        }
        else if (del_elem->right && !del_elem->left)
        {
            del_elem->right->color = BLACK;
            del_elem->right->parent = g;
            g->left = del_elem->right;
        }
        else if (!del_elem->right && del_elem->left)
        {
            del_elem->left->color = BLACK;
            del_elem->left->parent = g;
            g->left = del_elem->left;
        }
        {
            struct node* max_l = find_max(del_elem->left);
            if (max_l->left)
            {
                struct node* max_l_parent = max_l->parent;
                max_l->left->color = max_l->color;
                max_l_parent->right = max_l->left;
            }

            struct node* del_l = del_elem->left;
            struct node* del_r = del_elem->right;
            max_l->left = del_l;
            max_l->right = del_r;
            max_l->parent = g;
            g->left = max_l;
        }
        g->right = NULL;
        free(del_elem);
    }
    else
    {
        if (!del_elem->right && !del_elem->left)
        {
            g->right = NULL;
        }
        else if (del_elem->right && !del_elem->left)
        {
            del_elem->right->color = BLACK;
            del_elem->right->parent = g;
            g->right = del_elem->right;
        }
        else if (!del_elem->right && del_elem->left)
        {
            del_elem->left->color = BLACK;
            del_elem->left->parent = g;
            g->right = del_elem->left;
        }
        {
            struct node* max_l = find_max(del_elem->left);

            if (max_l->left)
            {
                struct node* max_l_parent = max_l->parent;
                max_l->left->color = max_l->color;
                max_l_parent->right = max_l->left;
            }

            struct node* del_l = del_elem->left;
            struct node* del_r = del_elem->right;
            max_l->left = del_l;
            max_l->right = del_r;
            max_l->parent = g;
            g->right = max_l;
        }
        g->left = NULL;
        free(del_elem);
    }
}

void del_red_elem(struct rbt* tree, struct node* del_elem)
{
    if (!del_elem->left && !del_elem->right)
    {
        struct node* parent = del_elem->parent;
        if (parent->right == del_elem) parent->right = NULL;
        else parent->left = NULL;
        free(del_elem);
        return;
    }
    struct node* del_elem_parent = del_elem->parent;
    struct node* max_l = find_max(del_elem->left);
    struct node* max_l_parent = max_l->parent;
    struct node* del_l = del_elem->left; 
    struct node* del_r = del_elem->right;

    del_elem->color = max_l->color;
    max_l->color = RED;
    max_l->parent = del_elem_parent;
    if (del_elem_parent->right == del_elem) del_elem_parent->right = max_l;
    else del_elem_parent = max_l;
    if (max_l->left) del_elem->left = max_l->left;
    del_elem->right = NULL;
    max_l->left = del_l;
    max_l->right = del_r;
    if (max_l_parent->left == max_l) max_l_parent->left = del_elem;
    else max_l_parent->right = del_elem;
    
    if (del_elem->color == RED)
    {
        del_red_elem(tree, del_elem);
    }
    else
    {
        if (del_elem->parent->color == RED) del_black_elem_with_red_parent(tree, del_elem);
        else del_black_elem_with_black_parent(tree, del_elem);
    }
}

void del_black_elem_with_red_parent(struct rbt* tree, struct node* del_elem)
{
    struct node* g = del_elem->parent;
    if (g->left == del_elem)
    {
        if ((g->left->left && g->left->left->color == RED) || (g->left->right && g->left->right->color == RED))
        {
            struct node* p = g->left;

            if (g->left->left && g->left->left->color == RED)
            {
                struct node* x = p->right;
                p->parent = g->parent;
                if (g->parent->right == g) g->parent->right = p;
                else g->parent->left = p;
                p->color = RED;
                x->color = BLACK;
                g->color = BLACK;
                del_black_elem(g, del_elem);
            }
            else 
            {
                struct node* x = p->right;
                g->right = (del_elem->right) ? del_elem->right : NULL; 
                p->parent = x;
                x->parent = g->parent;
                if (g->parent->right == g) g->parent->right = x;
                else g->parent->left = p;
                g->parent = x;
                x->right = g;
                x->left = p;
                p->right = NULL;
                g->left = NULL;
                g->color = BLACK;
                free(del_elem);
            }
        }
        else
        {
            g->color = BLACK;
            g->right->color = RED;
            g->left = del_elem->left;
            free(del_elem);
            return;
        }
        if ((g->right->left && g->right->left->color == RED) || (g->right->right && g->right->right->color == RED))
        {
            struct node* p = g->right;
            if (g->right->left && g->right->left->color == RED)
            {
                struct node* x = p->left;
                x->parent = g->parent;
                if (g->parent->right == g) g->parent->right = x;
                else g->parent->left = x;
                p->parent = x;
                x->right = p;
                p->left = NULL;
                g->parent = x;
                x->left = g;
                g->right = NULL;
                g->color = BLACK;
                free(del_elem);
                return;
            }
            else
            {
                struct node* x = p->right;
                p->parent = g->parent;
                if (g->parent->right == g) g->parent->right = p;
                else g->parent->left = p;
                g->parent = p;
                p->left = g;
                g->right = NULL;
                p->color = RED;
                x->color = BLACK;
                g->color = BLACK;
                free(del_elem);
                return;
            }
        }
        else
        {
            g->color = BLACK;
            g->left->color = RED;
            g->right= del_elem->right;
            free(del_elem);
            return;
        } 
    }
}

void del_brother_is_red(struct rbt* tree, struct node* g, struct node* del_elem)
{
    if (g->right == del_elem)
    {
        struct node* p = g->left;
        struct node* s = p->right;
        if ((s->right && s->right->color == RED) || (s->left && s->left->color == RED))
        {
            struct node* x = (s->right) ? s->right : s->left;
            s->parent = g->parent;
            if (!g->parent)
            {
                tree->root = s;
            }
            else
            {
                if (g->parent->right == g) g->parent->right = s;
                else g->parent->left = s;
            }
            p->right = x;
            x->parent =  p;
            g->parent = s;
            s->right = g;
            x->color = BLACK;
            del_black_elem(g, del_elem);
        }
        else
        {
            s->parent = g->parent;
            if (g->parent->left == g) g->parent->left = s;
            else g->parent->right = s;
            s->color = RED;
            p->parent = s;
            g->parent = p;
            s->right = p;
            p->color = BLACK;
            p->right = g;
            del_black_elem(g, del_elem);
        }
    }
    else
    {
        struct node* p = g->right;
        struct node* s = p->left;
        if ((s->right && s->right->color == RED) || (s->left && s->left->color == RED))
        {
            struct node* x = (s->right) ? s->right : s->left;
            s->parent = g->parent;
            if (g->parent->right == g) g->parent->right = s;
            else g->parent->left = s;
            s->left = p;
            p->parent = s;
            s->right = g;
            g->parent = s;
            p->left = x;
            x->parent = p;
            x->color = BLACK;
            del_black_elem(g, del_elem);
        }
        else
        {
            s->parent = g->parent;
            if (g->parent->right == g) g->parent->right = s;
            else g->parent->left = s;
            s->color = RED;
            p->parent = s;
            p->left = g;
            g->parent = p;
            p->left = g;
            g->left = NULL;
            p->color = BLACK;
            del_black_elem(g, del_elem);
        }
    }
}

void del_brother_is_black(struct rbt* tree, struct node* g,  struct node* del_elem)
{
    if (g->left == del_elem)
    {
        struct node* p = g->right;
        if ((p->right && p->right->color == RED) || (p->left && p->left->color == RED))
        {
            if (p->left)
            {
                struct node* x = p->left;
                x->parent = g->parent;
                x->right = g;
                if (g->parent->right == g) g->parent->right = x;
                else g->parent->left = x;
                x->left = p;
                p->parent = x;
                x->color = BLACK;
                del_black_elem(g, del_elem);
            }
            else
            {
                p->parent = g->parent;
                if (g->parent->right == g) g->parent->right = p;
                else g->parent->left = p;
                p->right = g;
                g->parent = p;
                del_black_elem(g, del_elem);
            }
        }
        else
        {
            p->color = RED;
            del_black_elem(g, del_elem);
        }
    }
    else
    {
        struct node* p = g->left;
        if ((p->right && p->right->color == RED) || (p->left && p->left->color == RED))
        {
            if (p->right && p->right->color == RED)
            {
                struct node* x = p->right;
                if (!g->parent)
                {
                    tree->root = x;
                } 
                else
                {
                    x->parent = g->parent;
                    if (g->parent->right == g) g->parent->right = x;
                    else g->parent->left = x;
                } 
                x->right = g; 
                x->left = p;
                p->parent = x;
                x->color = BLACK;
                del_black_elem(g, del_elem);
            }
            else
            {
                p->left->color = BLACK;
                p->parent = g->parent;
                if (!g->parent)
                {
                    tree->root = p;
                }
                else
                {
                    if (g->parent->right == g) g->parent->right = p;
                    else g->parent->left = p;
                }
                p->right = g;
                g->parent = p;
                del_black_elem(g, del_elem);
            }
        }
        else
        {
            p->color = RED;
            del_black_elem(g, del_elem);
        }
    }
}

void del_black_elem_with_black_parent(struct rbt* tree, struct node* del_elem)
{
    struct node* g = del_elem->parent;
    if ((g->right != del_elem && g->right->color == RED) || (g->left != del_elem && g->left->color == RED))
    {
        del_brother_is_red(tree, g, del_elem);
    }
    else
    {
        del_brother_is_black(tree, g, del_elem);
    }
}

void swap(struct rbt* tree, struct node* del_elem)
{
    struct node* max_left = find_max(del_elem->left);
    int del_color = del_elem->color;
    del_elem->color = max_left->color;
    max_left->color = del_color;
    if (del_elem->left == max_left)
    {
        max_left->parent = del_elem->parent;
        if (del_elem->parent && del_elem->parent->left == del_elem) del_elem->parent->left = max_left;
        else if (del_elem->parent && del_elem->parent->right == del_elem) del_elem->parent->right = max_left;
        max_left->right = del_elem->right;
        max_left->left = NULL;
        max_left->left = del_elem;
        del_elem->parent = max_left;
        del_elem->left = NULL;
        del_elem->right = NULL;
        
    }
    else
    {
        struct node* max_l_parent = max_left->parent;
        struct node* del_l = del_elem->left;
        struct node* del_r = del_elem->right;

        max_left->parent = del_elem->parent;
        if (del_elem == tree->root)
        {
            tree->root = max_left;
        }
        else
        {
            if (del_elem->parent && del_elem->parent->left == del_elem) del_elem->parent->left = max_left;
            else if (del_elem->parent && del_elem->parent->right == del_elem) del_elem->parent->right = max_left;
        }

        if (max_l_parent->left == max_left) max_l_parent->left = del_elem;
        else max_l_parent->right = del_elem;

        del_elem->parent = max_l_parent;
        del_elem->left = (max_left->left) ? max_left->left : NULL;
        del_elem->right = NULL;

        max_left->left = del_l;
        max_left->right = del_r;
    }

    if (del_elem->color == RED)
    {
        del_red_elem(tree, del_elem);
    }
    else 
    {
        if (del_elem->parent->color == RED) del_black_elem_with_red_parent(tree, del_elem);
        else del_black_elem_with_black_parent(tree, del_elem);
    }
}

void delete_elem(struct rbt* tree, int delete_elem)
{
    if (!tree || !tree->root) return;
    struct node* del_elem = find_elem(tree->root, delete_elem);
    if (!del_elem) return;

    if (tree->root == del_elem && !del_elem->right && !del_elem->left) 
    {
        free(tree->root);
        tree->root = NULL;
        return;
    }

    if (del_elem->right && del_elem->left)
    {
        swap(tree, del_elem);
    }
    else
    {
        if (del_elem->color == RED)
        {
            del_red_elem(tree, del_elem);
        }
        else 
        {
            if (del_elem->parent->color == RED) del_black_elem_with_red_parent(tree, del_elem);
            else del_black_elem_with_black_parent(tree, del_elem);
        }
    }
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

int compare(int* arr, int* test_arr, int arr_size)
{
    if (!arr || !test_arr) return 0;

    for (int i = 0; i < arr_size; ++i)
        if (arr[i] != test_arr[i]) return 0;

    return 1;
}

void delete_rbt(struct rbt* tree)
{   
    if (!tree->root)
    {
        free(tree);
        return;
    }

    delete_node(tree->root);
    free(tree);
}