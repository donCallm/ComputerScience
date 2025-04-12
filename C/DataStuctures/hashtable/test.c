#include <malloc.h>
#include <stdio.h>
#include "hashtable.h"
#include "item.h"

void test_create()
{
    printf("\n------test_create------\n");
    struct hashtable* table = create_hashtable();
    
    printf("\ntest 1: test_create -");
    if (table != NULL)
        printf("passed\n");
    else
        printf("ERROR: invalid_get_elem\n");
    
    delete_table(table);
    printf("\n----------------------\n");
}

void test_add_and_get_elem()
{
    printf("\n------test_add_and_get_elem------\n");
    struct hashtable* table = create_hashtable();

    printf("\ntest 1: test_add_and_get_elem - ");
    fill_table(table, 0, 9);
    
    if (get_elem(table, 5) == 5)
        printf("passed\n");
    else
        printf("ERROR: invalid_invalid_get\n");

    printf("\ntest 2: test_increace_capacity - ");

    if (table->capacity == CAPACITY_DEFAULT)
        printf("ERROR: invalid_increace_capacity\n");
    else
        printf("passed\n");

    delete_table(table);
    printf("\n----------------------\n");
}

void test_delete()
{
    printf("\n------test_add_and_get_elem------\n");
    struct hashtable* table = create_hashtable();
    fill_table(table, 0, 9);

    printf("\ntest 1: test_delete_one_elem - ");
    delete_elem(table, 5);
    if (get_elem(table, 5) == 5)
        printf("ERROR: invalid_delete_elem\n");
    else
        printf("passed\n");

    printf("\ntest 2: test_dicreace_capacity - ");
    delete_elem(table, 0);
    delete_elem(table, 1);
    delete_elem(table, 2);
    delete_elem(table, 3);
    delete_elem(table, 4);
    delete_elem(table, 6);

    if (table->capacity == CAPACITY_DEFAULT)
        printf("passed\n");
    else
        printf("ERROR: invalid_dicreace_capacity\n");

    delete_table(table);
    printf("\n----------------------\n");
}

void do_test()
{
    test_create();
    test_add_and_get_elem();
    test_delete();
}