#include <stdio.h>
#include <malloc.h>
#include "matrix.h"
#include "pair.h"

struct matrix* create_matrix(int y, int x)
{
    struct matrix* new_matrix = (struct matrix*)malloc(sizeof(struct matrix));
    new_matrix->y = y;
    new_matrix->x = x;
    new_matrix->mtx = (int**)malloc(new_matrix->y * sizeof(int));

    for (int i = 0; i < x; ++i)
        *(new_matrix->mtx + i) = (int*)malloc(new_matrix->x * sizeof(int));

    return new_matrix;
}

void fill_matrix(struct matrix* mt)
{
    if (mt->y == 0 || mt->x == 0) return;

    for (int i = 0; i < mt->y; ++i)
        for (int j = 0; j < mt->x; ++j)
            *(*(mt->mtx + i) + j) = j;
}

void fill_diagonal(struct matrix* mt)
{
    if (mt->y == 0 || mt->x == 0) return;

    for (int i = 0; i < mt->y; ++i)
    {
       for (int j = 0; j < mt->x; ++j)
       {
            if (i == j)
               *(*(mt->mtx + i) + j) = 0;
            else
               *(*(mt->mtx + i) + j) = 1;
       }
    }
}

void print_matrix(struct matrix* mt)
{
    if (mt->y == 0 || mt->x == 0) return;

    for (int i = 0; i < mt->y; ++i)
    {
        for (int j = 0; j < mt->y; ++j)
            printf("%d ", *(*(mt->mtx + i) + j));
        printf("\n");
    }
}

void sort(struct matrix* mt)
{
    if (mt->y == 0 || mt->x == 0) return;

    for (int k = 0; k < mt->y * 3; ++k)
    {
        for (int i = 0; i < mt->y; ++i)
        {
            for (int j = 0; j < mt->x; ++j) 
            {
                if (j == mt->x - 1 && i < mt->y - 1)
                {
                    if (*(*(mt->mtx + i) + j) > *(*(mt->mtx + i + 1)))
                    {
                        int temp = *(*(mt->mtx + i) + j);
                        *(*(mt->mtx + i) + j) = *(*(mt->mtx + i + 1));
                        *(*(mt->mtx + i + 1) + 0) = temp;
                    }
                }
                else if (j != mt->y - 1 && *(*(mt->mtx + i) + j) > *(*(mt->mtx + i) + j + 1))
                {
                    int temp = *(*(mt->mtx + i) + j);
                    *(*(mt->mtx + i) + j) = *(*(mt->mtx + i) + j + 1);
                    *(*(mt->mtx + i) + j + 1) = temp;
                }
            }
        }
    }
}

struct pair* binary_search(struct matrix* mt, int number)
{
    if (!mt->mtx) return NULL;

    int start = 0;
    int mid, row, col, value;
    int end = mt->y * mt->x - 1;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        row = mid / mt->x;
        col = mid % mt->x;
        value = *(*(mt->mtx + row) + col);
    
        if (value == number)
        {
            struct pair* pr = (struct pair*)malloc(sizeof(struct pair));
            pr->first = row;
            pr->second = col;
            return pr;
        }
        if (value > number)
        end = mid - 1;
        else
        start = mid + 1;
    }
    return NULL;
}

void delete_matrix(struct matrix* mt)
{
    if (mt->y == 0 || mt->x == 0) return;

    for (int i = mt->y - 1; i > 0; --i)
        free(mt->mtx[i]);

    free(mt);
}