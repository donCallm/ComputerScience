#include <stdio.h>
#include <malloc.h>
#include "rbt.h"
#include "node.h"

void test_create()
{
    printf("\n------test_create------\n");

    printf("\ntest 1: test_create - ");
    struct rbt* tree = create_rbt();

    if (tree != NULL)
        printf("passed\n");
    else
        printf("ERROR: invalid_create\n");

    delete_rbt(tree);
    printf("\n-----------------------\n");
}

void test_add()
{
    printf("\n------test_create------\n");

    printf("\ntest 1: test_add_one_elem - ");
    struct rbt* tree = create_rbt();
    add_elem(tree,  10);

    if (tree->root->value) printf("passed\n");
    else printf("ERROR: invalid_add_elem\n");

    add_elem(tree, 5);
    add_elem(tree, 8);
    add_elem(tree, 7);
    add_elem(tree, 2);
    add_elem(tree, 13);
    add_elem(tree, 10);
    add_elem(tree, 14);
 
    delete_rbt(tree);
    printf("\n-----------------------\n");
}

void do_test()
{
    test_create();
    test_add();
}