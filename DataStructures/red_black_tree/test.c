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
    printf("\n------test_add------\n");

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
    add_elem(tree, 14);
 
    delete_rbt(tree);
    printf("\n-----------------------\n");
}

void test_tree_traversal()
{
    printf("\n------test_tree_traversal------\n");
    int pre_order_arr[7] = {8, 5, 2, 7, 13, 10, 14};
    int in_order_arr[7] = {2, 5, 7, 8, 10, 13, 14};
    int post_order_arr[7] = {2, 7, 5, 10, 14 , 13, 8};
    int bfs_arr[7] = {8, 5, 13, 2, 7, 10, 14};
    int* arr_size = (int*)malloc(sizeof(int));
    *arr_size = 0;
    int* test_arr = (int*)malloc(7 * sizeof(int));
    struct rbt* tree = create_rbt();
    add_elem(tree,  10);
    add_elem(tree, 5);
    add_elem(tree, 8);
    add_elem(tree, 7);
    add_elem(tree, 2);
    add_elem(tree, 13);
    add_elem(tree, 14);

    printf("\ntest 1: test_pre-order - ");
    pre_order_print_node(tree->root, test_arr, arr_size);
    if (compare(pre_order_arr, test_arr, *arr_size)) printf("passed\n");
    else printf("ERROR: invalid_pre-order\n");
    *arr_size = 0;

    printf("\ntest 2: test_in-order - ");
    in_order_print_node(tree->root, test_arr, arr_size);
    if (compare(in_order_arr, test_arr, *arr_size)) printf("passed\n");
    else printf("ERROR: invalid_in-order\n");
    *arr_size = 0;

    printf("\ntest 3: test_post-order - ");
    post_order_print_node(tree->root, test_arr, arr_size);
    if (compare(post_order_arr, test_arr, *arr_size)) printf("passed\n");
    else printf("ERROR: invalid_post-order\n");
    *arr_size = 0;

    printf("\ntest 4: test_bfs - ");
    bfs(tree->root, test_arr, arr_size);
    if (compare(bfs_arr, test_arr, *arr_size)) printf("passed\n");
    else printf("ERROR: invalid_bfs\n");

    free(arr_size);
    free(test_arr);
    delete_rbt(tree);
    printf("\n-----------------------\n");
}

void test_delete()
{
    printf("\n------test_delete------\n");

    printf("\ntest 1: test_delete_one_elem - ");
    struct rbt* tree = create_rbt();
    add_elem(tree,  10);
    add_elem(tree, 5);
    add_elem(tree, 8);
    add_elem(tree, 7);
    add_elem(tree, 2);
    add_elem(tree, 13);
    add_elem(tree, 14);

    delete_elem(tree, 13);
    struct node* test = find_elem(tree->root, 13);

    if (test != NULL) printf("ERROR: invalid_del_one_elem\n");
    else printf("passed\n");

    printf("\ntest 2: test_del_root - ");

    delete_elem(tree, 8);
    test = find_elem(tree->root, 8);
    
    if (tree->root->value != 8 && !test) printf("passed\n");
    else printf("ERROR: invalid_del_elem\n");

    delete_rbt(tree);
    printf("\n-----------------------\n");
}

void do_test()
{
    test_create();
    test_add();
    test_tree_traversal();
    test_delete();
}