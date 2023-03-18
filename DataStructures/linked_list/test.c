#include <stdio.h>
#include <stdio.h>
#include <malloc.h>
#include "node.h"
#include "linked_list.h"

void test_create_list()
{
    printf("\n------test_create_list------\n");

    struct linked_list list;
    create_list(&list);
    
    printf("filling_list: \n");
    filling_list(&list, 0, 9);
    print_list(&list);

    for (int i = list.size; i > -1; i--)
        delete_elem(&list, i);
    free(list.head);
    printf("\n----------------------\n");
}

void test_add_elem()
{
    printf("\n------test_add_elem------\n");

    struct linked_list list;
    create_list(&list);

    add_elem(&list, 0);
    printf("list_after_add_first_elem:");
    print_list(&list);
    add_elem(&list, 1);
    printf("list_after_add_second_elem");
    print_list(&list);

    for (int i = list.size; i > -1; i--)
        delete_elem(&list, i);
    free(list.head);
    printf("\n----------------------\n");
}

void test_delete_list()
{
    printf("\n------test_delete_list------\n");

    struct linked_list list;
    create_list(&list);
    
    printf("filling_list: \n");
    filling_list(&list, 0, 9);
    
    print_list(&list);

    for (int i = list.size; i > -1; i--)
        delete_elem(&list, i);
    
    printf("\nlist_after_delete_all_elem: \n");

    print_list(&list);
    free(list.head);
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

void do_test()
{
    test_create_list();
    test_add_elem();
    test_delete_list();
    test_create_node();
}