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

    delete_tree(tree);
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
    add(tree, 7);
    add(tree, 1);
    add(tree, 3);

    if (tree->root->value == 5 && tree->root->left->value == 4 && tree->root->right->value == 6)
        printf("passed\n");
    else
        printf("ERROR: invalid_add\n");

    add(tree, 25);
    add(tree, 25);
    add(tree, 25);
    add(tree, 25);
    add(tree, 25);
    add(tree, 25);
    add(tree, 25);
    add(tree, 25);
    add(tree, 25);
    add(tree, 25);
    add(tree, 25);
    add(tree, 25);
    add(tree, 0);
    add(tree, 0);
    add(tree, 0);
    add(tree, 0);
    add(tree, 0);
    add(tree, 0);
    add(tree, 0);
    add(tree, 0);
    add(tree, 0);
    add(tree, 8);
    add(tree, 9);
    add(tree, 11);
    add(tree, 10);
    add(tree, 2);
    add(tree, 8);

    delete_tree(tree);
    printf("\n-----------------------\n");
}

void test_find()
{
    printf("\n------test_find------\n");

    printf("\ntest 1: test_find_min - ");
    struct binary_search_tree* tree = create_tree();

    add(tree, 5);
    add(tree, 6);
    add(tree, 4);
    add(tree, 7);
    add(tree, 1);
    add(tree, 3);

    struct node* temp = find_min(tree->root);

    if (temp->value == 1)
        printf("passed\n");
    else
        printf("ERROR: invalid_find_min\n");

    printf("\ntest 2: test_find_max - ");
    temp = find_max(tree->root);

    if (temp->value == 7)
        printf("passed\n");
    else
        printf("ERROR: invalid_find_max\n");

    printf("\ntest 3: test_find_elem - ");
    temp = find_elem(tree->root, 3);

    if (temp->value == 3)
        printf("passed\n");
    else
        printf("ERROR: invalid_find_max\n");

    printf("\ntest 4: test_find_previous_elem - ");
    temp = find_previous_elem(tree->root, 1);

    if (temp->value == 4)
        printf("passed\n");
    else
        printf("ERROR: invalid_find_max\n");
    
    delete_tree(tree);
    printf("\n-----------------------\n");
}

void test_delete()
{
    printf("\n------test_delete------\n");

    struct binary_search_tree* tree = create_tree();
    printf("\ntest 1: test_delete_one_elem - ");

    add(tree, 8);
    add(tree, 6);
    add(tree, 10);
    add(tree, 7);
    add(tree, 4);
    add(tree, 1);
    add(tree, 5);
    add(tree, 9);
    add(tree, 12);
    delete_elem(tree, 10);

    if (tree->root->right->value == 9)
        printf("passe\n");
    else
        printf("ERROR: invalid_delete_elem\n");

    printf("\ntest 2: test_delete_head - ");
    delete_elem(tree, 8);

    if (tree->root->value == 7)
        printf("passed\n");
    else
        printf("ERROR: invalid_delete_elem\n");

    printf("\ntest 3: test_delete_non-exist_elem - ");
    delete_elem(tree, 85);
    printf("passed\n");

    printf("\ntest 4: test_delete_all_elem - ");

    delete_elem(tree, 6);
    delete_elem(tree, 7);
    delete_elem(tree, 4);
    delete_elem(tree, 1);
    delete_elem(tree, 5);
    delete_elem(tree, 9);
    delete_elem(tree, 12);
    printf("passed\n");

    free(tree);
    printf("\n-----------------------\n");
}

void test_print()
{
    printf("\n------test_print------\n");

    struct binary_search_tree* tree = create_tree();
    int* arr_size = (int*)malloc(sizeof(int));
    *arr_size = 0;

    int test_arr1[9] = {1, 4, 5, 6, 7, 8, 9, 10, 12};
    int test_arr2[9] = {8, 6, 4, 1, 5, 7, 10, 9, 12};
    int test_arr3[9] = {1, 5, 4, 7, 6, 9, 12, 10, 8};

    int* arr = (int*)malloc(9 * sizeof(int));
    printf("\ntest 1: test_in_order - ");

    add(tree, 8);
    add(tree, 6);
    add(tree, 10);
    add(tree, 7);
    add(tree, 4);
    add(tree, 1);
    add(tree, 5);
    add(tree, 9);
    add(tree, 12);
    in_order_print_node(tree->root, arr, arr_size);

    if (compare(arr, test_arr1, *arr_size))
        printf("passed\n");
    else
        printf("ERROR: invalid_post_order\n");

    printf("\ntest 2: test_pre_order - ");

    *arr_size = 0;
    pre_order_print_node(tree->root, arr, arr_size);

    if (compare(arr, test_arr2, *arr_size))
        printf("passed\n");
    else
        printf("ERROR: invalid_post_order\n");

    printf("\ntest 3: test_post_order - ");

    *arr_size = 0;
    post_order_print_node(tree->root, arr, arr_size);

    if (compare(arr, test_arr3, *arr_size))
        printf("passed\n");
    else
        printf("ERROR: invalid_post_order\n");

    printf("\ntest 4: test_bfs - ");

    *arr_size = 0;
    bfs(tree->root, arr, arr_size);
    
    if (arr[0] == 8 && arr[8] == 5)
        printf("passed\n");
    else
        printf("ERROR: invalid_bfs\n");
    
    delete_tree(tree);
    free(arr);
    free(arr_size);
    printf("\n-----------------------\n");
}

void do_test()
{
    test_create();
    test_add();
    test_find();
    test_delete();
    test_print();
}