#include<stdio.h>
#include<malloc.h>
#include"test.h"    
#include"array.h"
#include"stack.h"
#include"pair.h"

void test_create()
{
    printf("\n------test_create------\n");
    struct array arr;
    create_array(&arr);
    print_arr(&arr);
    filling_array(&arr);
    print_arr(&arr);
    free(arr.arr);
    printf("\n-----------------------\n");
}

void test_remove()
{
    printf("\n------test_remove------\n");
    struct array arr;
    create_array(&arr);
    print_arr(&arr);
    filling_array(&arr);
    print_arr(&arr);

    for (size_t i = 0; i < arr.size; i++)
        my_remove(&arr, i);

    print_arr(&arr);
    free(arr.arr);
    printf("\n-----------------------\n");
}

void test_algorihtms()
{
    printf("\n------test_algorihtms------\n");
    struct array arr1;
    struct array arr2;
    struct array arr3;
    struct array arr4;

    create_array(&arr1);
    create_array(&arr2);
    create_array(&arr3);
    create_array(&arr4);

    filling_array(&arr1);
    filling_array(&arr2);
    filling_array(&arr3);
    filling_array(&arr4);

    printf("first_arr: \n");
    print_arr(&arr1);
    printf("second_arr: \n");
    print_arr(&arr2);
    printf("third_arr: \n");
    print_arr(&arr3);
    printf("fourth_arr\n");
    print_arr(&arr4);

    printf("SHUFFLE\n");
    printf("first arr: \n");
    shuffle(&arr1);
    print_arr(&arr1);
    printf("second arr: \n");
    shuffle(&arr2);
    print_arr(&arr2);
    printf("third arr: \n");
    shuffle(&arr3);
    print_arr(&arr3);
    printf("fourth_arr\n");
    shuffle(&arr4);
    print_arr(&arr4);

    printf("sort_first_array_by_quick_sort\n");
    quick_sort(&arr1);
    print_arr(&arr1);

    printf("sort_second_array_by_buble_sort\n");
    buble_sort(&arr2);
    print_arr(&arr2);

    printf("sort_third_array_by_selection_sort\n");
    selection_sort(&arr3);
    print_arr(&arr3);

    printf("sort_fourth_array_by_insertion_sort\n");
    insertion_sort(&arr4);
    print_arr(&arr4);

    printf("find_element_index_by_binary_serch\n");
    printf("find_index_of_number_10\n");
    printf("index: %d", binary_search(&arr1, 10));

    free(arr1.arr);
    free(arr2.arr);
    free(arr3.arr);
    free(arr4.arr);
    printf("\n-----------------------\n");
}

void test_compare()
{
    printf("\n------test_compare------\n");
    struct array arr1;
    struct array arr2;

    create_array(&arr1);
    create_array(&arr2);

    filling_array(&arr1);
    filling_array(&arr2);

    printf("first_arr: \n");
    print_arr(&arr1);
    printf("second_arr: \n");
    print_arr(&arr2);

    printf("compare_result: ");
    if(compare_array(&arr1, &arr2))
        printf("identical\n");
    else
        printf("different\n");
    printf("---------------\n");

    printf("shufle_first_arr\n");
    shuffle(&arr1);
    print_arr(&arr1);

    printf("compare_result: ");
    if(compare_array(&arr1, &arr2))
        printf("identical\n");
    else
        printf("different\n");

    free(arr1.arr);
    free(arr2.arr);
    printf("\n-----------------------\n");
}

void test_stack()
{
    printf("\n------test_stack------\n");
    struct stack stk;
    init_stack(&stk);

    printf("\nstack_status_before_push: ");
    if(is_not_empty(&stk))
        printf("stack_is_not_empty\n");
    else 
        printf("stack_is_empty\n");

    for (size_t i = 0; i < 10; i++)
        push(&stk, i, i);

    printf("\nstack_status_after_push: ");
    if(is_not_empty(&stk))
        printf("stack_is_not_empty\n");
    else 
        printf("stack_is_empty\n");

    printf("\nstack_elem: \n");
    struct pair pr;
    while (is_not_empty(&stk))
    {
        pr = pop(&stk);
        printf("%d and %d\n", pr.first, pr.second);
    }
    
    printf("\nstack_status_after_pop_all_elem: ");
    if(is_not_empty(&stk))
        printf("stack_is_not_empty\n");
    else 
        printf("stack_is_empty\n");
    
    free(stk.pr);
    printf("\n-----------------------\n");
}

void do_test()
{
    test_create();
    test_remove();
    test_algorihtms();
    test_compare();
    test_stack();
}