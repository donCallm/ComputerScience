#include <malloc.h>
#include <stdio.h>
#include "binary_search_tree.h"
#include "node.h"
#include "test.h"

void test_create()
{
    printf("\n------test_create------\n");

    printf("\ntest 1: test_create - ");
    struct binary_search_tree* tree = create_tree();

    if (tree != NULL)
        printf("passed\n");
    else
        printf("ERROR: invalid_create\n");

    printf("\n-----------------------\n");
}

void test_add()
{
    printf("\n------test_add------\n");

    printf("\ntest 1: test_add - ");
    struct binary_search_tree* tree = create_tree();

    add(tree, 5);
    add(tree, 6);
    add(tree, 4);

    if (tree->head->value == 5 && tree->head->left->value == 4 && tree->head->right->value == 6)
        printf("passed\n");
    else
        printf("ERROR: invalid_add\n");

    printf("\n-----------------------\n");
}

void do_test()
{
    test_create();
    test_add();
}