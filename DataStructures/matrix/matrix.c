#include <stdio.h>
#include <malloc.h>
#include "matrix.h"
#include "point.h"

struct matrix* create_matrix(int y_size, int x_size)
{
    struct matrix* new_matrix = (struct matrix*)malloc(sizeof(struct matrix));
    new_matrix->y_size = y_size;
    new_matrix->x_size = x_size;
    new_matrix->mtx = (int**)malloc(new_matrix->y_size * sizeof(int*));

    for (int i = 0; i < new_matrix->y_size; ++i)
        *(new_matrix->mtx + i) = (int*)malloc(new_matrix->x_size * sizeof(int));

    return new_matrix;
}

void fill_matrix(struct matrix* mt)
{
    if (!mt || mt->y_size == 0 || mt->x_size == 0) return;

    for (int i = 0; i < mt->y_size; ++i)
        for (int j = 0; j < mt->x_size; ++j)
            *(*(mt->mtx + i) + j) = j;
}

void fill_diagonal(struct matrix* mt, int number)
{
    if (!mt || mt->y_size == 0 || mt->x_size == 0) return;

    for (int j = 0; j < mt->y_size; ++j)
        *(*(mt->mtx + j) + j) = number;
}

void print_matrix(struct matrix* mt)
{
    if (!mt || mt->y_size == 0 || mt->x_size == 0) return;

    for (int i = 0; i < mt->y_size; ++i)
    {
        for (int j = 0; j < mt->x_size; ++j)
            printf("%d ", *(*(mt->mtx + i) + j));
        printf("\n");
    }
}

void swap(struct matrix* mt, int y_size, int x_size)
{
    if (x_size == mt->x_size - 1 && y_size < mt->y_size - 1)
    {
        if (*(*(mt->mtx + y_size) + x_size) > *(*(mt->mtx + y_size + 1)))
        {
            int temp = *(*(mt->mtx + y_size) + x_size);
            *(*(mt->mtx + y_size) + x_size) = *(*(mt->mtx + y_size + 1));
            *(*(mt->mtx + y_size + 1) + 0) = temp;
        }
    }
    else if (x_size != mt->x_size - 1 && *(*(mt->mtx + y_size) + x_size) > *(*(mt->mtx + y_size) + x_size + 1))
    {
        int temp = *(*(mt->mtx + y_size) + x_size);
        *(*(mt->mtx + y_size) + x_size) = *(*(mt->mtx + y_size) + x_size + 1);
        *(*(mt->mtx + y_size) + x_size + 1) = temp;
    }
}

void sort(struct matrix* mt)
{
    if (!mt || mt->y_size == 0 || mt->x_size == 0) return;

    for (int k = 0; k < mt->y_size * mt->y_size; ++k)
        for (int y_size = 0; y_size < mt->y_size; ++y_size)
            for (int x_size = 0; x_size < mt->x_size; ++x_size) 
                swap(mt, y_size, x_size);
}

struct point* binary_search(struct matrix* mt, int number)
{
    if (!mt || !mt->mtx) return NULL;

    int start = 0;
    int mid, x_size, y_size, value;
    int end = mt->y_size * mt->x_size - 1;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        x_size = mid / mt->x_size;
        y_size = mid % mt->x_size;
        value = *(*(mt->mtx + x_size) + y_size);
    
        if (value == number)
        {
            struct point* pt = (struct point*)malloc(sizeof(struct point));
            pt->x = x_size;
            pt->y = y_size;
            return pt;
        }
        if (value > number) end = mid - 1;
        else start = mid + 1;
    }
    return NULL;
}

void delete_matrix(struct matrix* mt)
{
    if (!mt) return;

    for (int i = 0; i < mt->y_size; ++i)
        free(*(mt->mtx + i));
    free(mt->mtx);
    free(mt);
}