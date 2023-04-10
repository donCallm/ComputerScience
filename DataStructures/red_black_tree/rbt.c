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
            fixup(iter->right);
            break;
        }
        
        if (iter->left != NULL)
        {
            iter = iter->left;
            continue;
        }
        iter->left = create_node(value);
        iter->left->parent = iter;
        fixup(iter->left);
        break;
    }

}

void left_rotate(struct node* g)
{
    struct node* p = g->right;
    g->right = NULL;

    if (!p->left)
    {
        p->parent = g->parent;
        g->parent = p;
        p->left = g;
        g->color = RED;
        p->color = BLACK;
    }

    struct node* x = p->left;
    p->left = NULL;
    x->parent = g->parent;
    p->parent = x;
    g->parent = x;
    x->left = g;
    x->color = BLACK;
    g->color = RED;
}

void right_rotate(struct node* g)
{
    struct node* p = g->left;
    g->left = NULL;

    if (!p->right)
    {   
        p->parent = g->parent;
        g->parent = p;
        g->color = BLACK;
        p->color = RED;
        return;
    }

    struct node* x = p->right;
    p->right = NULL;
    p->parent = x;
    x->parent = g->parent;
    g->parent = x;
    x->left = p;
    x->right = g;
    x->color = BLACK;
    g->color = RED;
}

void fixup(struct node* root)
{
    if (!root || !root->parent) return;

    if (root->color == RED && root->parent->color == RED)
    {
        struct node* g = root->parent->parent;
        if (!g)
        {
            if (g->left == root->parent)
            {
                if (g->right->color == RED)
                {
                    g->color = RED;
                    g->right->color = BLACK;
                    root->parent->color = BLACK;
                    fixup(g);
                }
                else if (g->right->color == BLACK)
                {
                    right_rotate(root);
                }
            }
            else if (g->right == root->parent)
            {
                if (g->left->color == RED)
                {
                    g->color = RED;
                    g->left->color = BLACK;
                    root->color = BLACK;
                    fixup(g);
                }
                else if (g->left->color == BLACK)
                {
                    left_rotate(root);
                }
            }
        }
    }
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