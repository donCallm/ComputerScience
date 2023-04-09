#include <stdio.h>
#include <malloc.h>
#include <limits.h>
#include "node.h"
#include "linked_list.h"
#include "test.h"

void test_create_list()
{
    printf("\n------test_create_list------\n");

    struct linked_list *list = create_list();
    printf("\ntest 1: create list - ");
    fill_list(list, 0, 9);

    if (list == NULL)
    {
        printf("invalid_create\n");
        return;
    }
    printf("passed\n");

    delete_list(list);
    printf("\n----------------------\n");
}

void test_add_elem()
{
    printf("\n------test_add_elem------\n");

    struct linked_list *list = create_list();

    printf("\ntest1: add_two_elems - ");
    add_elem(list, 0);
    add_elem(list, 1);

    if (list->head->data == 0 && list->head->next->data == 1)
        printf("passed\n");
    else
        printf("invalid_add_elem\n");

    delete_list(list);
    printf("\n----------------------\n");
}

void test_delete_list()
{
    printf("\n------test_delete_list------\n");

    struct linked_list* list1 = create_list();
    struct linked_list* list2 = create_list();
    
    fill_list(list1, 0, 9);
    fill_list(list2, 0, 9);

    printf("\ntest 1: try_delete_non-existent_elem - ");
    delete_elem(list1, INVALID_INDEX);

    if (compare_list(list1, list2))
        printf("passed\n");
    else
        printf("ERROR: delete_invalid_index_elem\n");

    printf("\ntest 2: delete_head - "); 
    int old_head_data = list1->head->data;
    delete_elem(list1, 0);
    if (old_head_data == list1->head->data)
        printf("ERROR: invalid_delete_head\n");
    else
        printf("passed\n");

    for (int i = 8; i >= 0; --i)
        delete_elem(list1, i);
    
    printf("\ntest 3: delete_all_other_elem - ");
    if (list1->head != NULL)
        printf("ERROR: invaid_delete\n");
    else
        printf("passed\n");

    delete_list(list1);
    delete_list(list2);
    printf("\n----------------------\n");
}

void test_create_node()
{
    printf("\n------test_create_node------\n");

    printf("\ntest 1: create_node - ");
    struct node *nd = create_node();

    if (nd == NULL)
        printf("ERROR: invalid_create_node\n");
    else
        printf("passed\n");
        
    delete_node(nd);
    printf("\n----------------------\n");
}

void test_contains()
{
    printf("\n------test_contains------\n");

    struct linked_list* list = create_list();
    fill_list(list, 0, 9);

    printf("\ntest 1: try_found_valid_numbee - " );
    if (contains(list, 5))
        printf("passed\n");
    else
        printf("ERROR: invalid_contains\n");

    printf("\ntest 2: try_found_invalid_number - ");
    if (contains(list, 10))
        printf("ERROR: invalid_contains\n");
    else
        printf("passed\n");

    printf("\ntest 3: try_found_last_elem - ");
    if (contains(list, 9))
        printf("passed\n");
    else
        printf("ERROR: invalid_contains");

    delete_list(list);
    printf("\n----------------------\n");
}

void test_revers()
{
    printf("\n------test_reverse------\n");

    struct linked_list* list_to_revers = create_list();
    struct linked_list* reverse_list = create_list();

    fill_list(list_to_revers, 0, 9);
    fill_list(reverse_list, 9, 0);
    reverse(list_to_revers);

    printf("\ntest 1: compare_list_after_reverse_and_reverse_list - ");
    if (compare_list(list_to_revers, reverse_list))
        printf("passed\n");
    else
        printf("ERROR: invalid_reverse\n");

    delete_list(list_to_revers);
    delete_list(reverse_list);
    printf("\n----------------------\n");
}

void test_swap()
{
    printf("\n------test_swap------\n");

    struct linked_list* list1 = create_list();
    struct linked_list* list2 = create_list();

    fill_list(list1, 0, 9);
    fill_list(list2, 0, 9);

    swap(list1, 0, 5);
    printf("\ntest 1: test_default_swap - ");
    if (list1->head->data == 5)
        printf("passed\n");
    else
        printf("ERROR: invalid_swap\n");

    printf("\ntest 2: try_swap_in_reverse_sequence - ");
    swap(list2, 7, 1);
    if (list2->head->next->data == 7)
        printf("passed\n");
    else 
        printf("ERROR: invalid_swap\n");

    printf("\ntest 3: try_swap_identical_indexes - ");
    int number_count = 0;
    struct node* iter = list1->head;
    swap(list1, 5, 5);
    while (iter)
    {
        if (iter->data == 5)
            number_count++;
        iter = iter->next;
    }

    if (number_count != 1)
        printf("ERROR: invalid_swap\n");
    else
        printf("passed\n");

    delete_list(list1);
    delete_list(list2);
    printf("\n----------------------\n");
}

void test_merge_list()
{
    printf("\n------test_merge_list------\n");
    struct linked_list* list1 = create_list();
    struct linked_list* list2 = create_list();
    struct linked_list* list3 = create_list();
    struct linked_list* list4 = create_list();
    struct linked_list* list5 = create_list();
    struct linked_list* list6 = create_list();

    fill_list(list1, 0, 9);
    fill_list(list2, 0, 9);
    fill_list(list3, 0, 8);
    fill_list(list4, 0, 9);
    fill_list(list5, 0, 9);
    fill_list(list6, 0, 9);

    struct node* third_iter = list3->head;
    while (third_iter->next)
        third_iter = third_iter->next;
    add_elem(list4, 9);
    third_iter->next = list4->head;

    printf("\ntest 1: merge_in_last_index - ");
    merge_list(list1, list2, 9);

    if (compare_list(list1, list3))
        printf("passed\n");
    else
        printf("ERROR: invalid_merge\n");

    printf("\ntest 2: try_merge_list_in_itself - ");
    merge_list(list2, list2, 5);

    if (compare_list(list2, list5))
        printf("passed\n");
    else
        printf("ERROR: invalid_merge\n");

    printf("\ntest 3: try_merge_in_invalid_index - ");
    merge_list(list2, list5, INVALID_INDEX);

    if (compare_list(list2, list5))
        printf("passed\n");
    else
        printf("ERROR: invalid_merge\n");

    printf("\ntest 4: merge_in_head - ");
    merge_list(list2, list5, 0);
    struct node* fifth_iter = list5->head;
    while (fifth_iter->next)
        fifth_iter = fifth_iter->next;
    fifth_iter->next = list6->head;

    if (compare_list(list2, list5))
        printf("passed\n");
    else
        printf("ERROR: invalid_merge\n");
    
    delete_list(list1);
    delete_list(list2);
    delete_list(list3);
    free(list4);
    delete_list(list5);
    free(list6);
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
    test_merge_list();
}