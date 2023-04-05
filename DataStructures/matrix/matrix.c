#include <stdio.h>
#include <malloc.h>
#include "matrix.h"
#include "point.h"

struct matrix* create_matrix(int col, int row)
{
    struct matrix* new_matrix = (struct matrix*)malloc(sizeof(struct matrix));
    new_matrix->col = col;
    new_matrix->row = row;
    new_matrix->mtx = malloc(new_matrix->col * sizeof(int*));

    for (int i = 0; i < new_matrix->col; ++i)
        *(new_matrix->mtx + i) = malloc(new_matrix->row * sizeof(int));

    return new_matrix;
}

void fill_matrix(struct matrix* mt)
{
    if (!mt || mt->col == 0 || mt->row == 0) return;

    for (int i = 0; i < mt->col; ++i)
        for (int j = 0; j < mt->row; ++j)
            *(*(mt->mtx + i) + j) = j;
}

void fill_diagonal(struct matrix* mt, int number)
{
    if (!mt || mt->col == 0 || mt->row == 0) return;

    for (int j = 0; j < mt->row; ++j)
        *(*(mt->mtx + j) + j) = number;
}

void print_matrix(struct matrix* mt)
{
    if (!mt || mt->col == 0 || mt->row == 0) return;

    for (int i = 0; i < mt->col; ++i)
    {
        for (int j = 0; j < mt->row; ++j)
            printf("%d ", *(*(mt->mtx + i) + j));
        printf("\n");
    }
}

void swap(struct matrix* mt, int col, int row)
{
    if (row == mt->row - 1 && col < mt->col - 1)
    {
        if (*(*(mt->mtx + col) + row) > *(*(mt->mtx + col + 1)))
        {
            int temp = *(*(mt->mtx + col) + row);
            *(*(mt->mtx + col) + row) = *(*(mt->mtx + col + 1));
            *(*(mt->mtx + col + 1) + 0) = temp;
        }
    }
    else if (row != mt->row - 1 && *(*(mt->mtx + col) + row) > *(*(mt->mtx + col) + row + 1))
    {
        int temp = *(*(mt->mtx + col) + row);
        *(*(mt->mtx + col) + row) = *(*(mt->mtx + col) + row + 1);
        *(*(mt->mtx + col) + row + 1) = temp;
    }
}

void sort(struct matrix* mt)
{
    if (!mt || mt->col == 0 || mt->row == 0) return;

    for (int k = 0; k < mt->col * mt->col; ++k)
        for (int col = 0; col < mt->col; ++col)
            for (int row = 0; row < mt->row; ++row) 
                swap(mt, col, row);
}

struct point* binary_search(struct matrix* mt, int number)
{
    if (!mt || !mt->mtx) return NULL;

    int start = 0;
    int mid, row, col, value;
    int end = mt->col * mt->row - 1;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        row = mid / mt->row;
        col = mid % mt->row;
        value = *(*(mt->mtx + row) + col);
    
        if (value == number)
        {
            struct point* pt = (struct point*)malloc(sizeof(struct point));
            pt->row = row;
            pt->col = col;
            return pt;
        }
        if (value > number) end = mid - 1;
        else start = mid + 1;
    }
    return NULL;
}

void delete_matrix(struct matrix* mt)
{
    if (!mt || mt->col == 0 || mt->row == 0) return;

    for (int i = 0; i < mt->col; ++i)
        free(*(mt->mtx + i));
    free(mt);
}