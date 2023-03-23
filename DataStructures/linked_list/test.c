#include <stdio.h>
#include <stdio.h>
#include <malloc.h>
#include "node.h"
#include "linked_list.h"

void test_create_list()
{
    printf("\n------test_create_list------\n");

    struct linked_list *list = create_list();
    
    printf("filling_list: \n");
    fill_list(list, 0, 9);
    print_list(list);

    for (int i = 9; i >= 0; --i)
        delete_elem(list, i);
    delete_list(list);
    printf("\n----------------------\n");
}

void test_add_elem()
{
    printf("\n------test_add_elem------\n");

    struct linked_list *list = create_list();

    add_elem(list, 0);
    printf("list_after_add_first_elem:\n");
    print_list(list);
    add_elem(list, 1);
    printf("list_after_add_second_elem:\n");
    print_list(list);

    delete_list(list);

    printf("\n----------------------\n");
}

void test_delete_list()
{
    printf("\n------test_delete_list------\n");

    struct linked_list *list = create_list();
    
    printf("fill_list: \n");
    fill_list(list, 0, 9);
    print_list(list);
    
    printf("\ntry_delete_non-existent_elem:\n");
    delete_elem(list, 39);
    print_list(list);

    printf("\nlist_after_delete_one_elem: \n"); 
    delete_elem(list, 0);
    print_list(list);

    for (int i = 8; i >= 0; --i)
        delete_elem(list, i);
    
    printf("\nlist_after_delete_all_other_elem: \n");
    print_list(list);

    printf("\ntry_delete_empty_list:\n");
    delete_elem(list, 2);
    print_list(list);

    delete_list(list);
    printf("\n----------------------\n");
}

void test_create_node()
{
    printf("\n------test_create_node------\n");
    struct node *nd = create_node();
    printf("new_node_data: %d", nd->data);
    delete_node(nd);
    printf("\n----------------------\n");
}

void test_contains()
{
    printf("\n------test_contains------\n");

    struct linked_list* list = create_list();
    fill_list(list, 0, 9);
    print_list(list);

    if (contains(list, 5))
        printf("\nlist_contains_number_5\n");
    else
        printf("\nlist_dont_contains_number_5\n");

    if (contains(list, 10))
        printf("\nlist_contains_number_10\n");
    else
        printf("\nlist_dont_contains_number_10\n");

    delete_list(list);
    printf("\n----------------------\n");
}

void test_revers()
{
    printf("\n------test_reverse------\n");

    struct linked_list* list = create_list();
    fill_list(list, 0, 9);
    printf("\nlist_before_reverse:\n");
    print_list(list);

    reverse(list);
    printf("\nlist_after_reverse:\n");
    print_list(list);

    delete_list(list);
    printf("\n----------------------\n");
}

void test_swap()
{
    printf("\n------test_swap------\n");

    struct linked_list* list = create_list();
    fill_list(list, 0, 9);
    printf("\nlist_before_swap:\n");
    print_list(list);

    swap(list, 1, 9);
    printf("\nlist_after_swap:\n");
    print_list(list);
    
    delete_list(list);
    printf("\n----------------------\n");
}

void do_test()
{
    test_create_list();
    test_add_elem();
    test_delete_list();
    test_create_node();
    test_contains();
    test_revers();
    test_swap();
}