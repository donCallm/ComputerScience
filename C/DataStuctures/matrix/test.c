#include <stdio.h>
#include <malloc.h>
#include "matrix.h"
#include "point.h"

void test_create()
{
    printf("\n------test_create------\n");

    printf("\ntest 1: test_create - ");
    struct matrix* mt = create_matrix(9, 9);

    if (mt)
        printf("passed\n");
    else  
        printf("ERROR: invalid_create\n");

    delete_matrix(mt);
    printf("\n-----------------------\n");
}

void test_fill()
{
    printf("\n------test_print------\n");

    printf("\ntest 1: test_fill_and_print_matrix\n");
    struct matrix* mt1 = create_matrix(9, 9);

    fill_matrix(mt1);
    print_matrix(mt1);

    printf("\ntest 2: test_fill_diagonal_matrix\n");
    struct matrix* mt2 = create_matrix(9, 9);

    for (int i = 0; i < mt2->y_size; ++i)
        for (int j = 0; j < mt2->x_size; ++j)  
            *(*(mt2->mtx + i) + j) = 0;

    fill_diagonal(mt2, 1);
    print_matrix(mt2);

    delete_matrix(mt1);
    delete_matrix(mt2);
    printf("\n-----------------------\n");
}

void test_algorithms()
{
    printf("\n------test_algorithms------\n");

    printf("\ntest 1: test_sort_matrix - ");
    struct matrix* mt = create_matrix(3, 3);
    int number = 9;

    for (int i = 0; i < mt->y_size; ++i)
        for (int j = 0; j < mt->x_size; ++j)  
            *(*(mt->mtx + i) + j) = number--;

    sort(mt);
    
    if (*(*(mt->mtx)) == 1 && *(*(mt->mtx + 2) + 2) == 9)
        printf("passed\n");
    else   
        printf("ERROR: invalid_sort");

    printf("\ntest 2: test_search_exist_elem - ");
    struct point* pt = binary_search(mt, 2);

    if (pt)
    {
        if (pt->x == 0 && pt->y == 1)
            printf("passed\n");
        else
            printf("ERROR: invlaid_binary_search\n");
    }
    else
        printf("ERROR: invalid_binary_search\n");

    free(pt);

    printf("\ntest 3: test_search_non-exist_elem - ");
    pt = binary_search(mt, 10);

     if (!pt)
            printf("passed\n");
        else
            printf("ERROR: invlaid_binary_search\n");
    
    delete_matrix(mt);
    printf("\n-----------------------\n");
}

void do_test()
{
    test_create();
    test_fill();
    test_algorithms();
}