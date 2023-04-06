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

void q_sort(int* arr, int min, int max)
{
    if (min < max)
    {
        int left = min;
        int right = max - 1;
        int mid = *(arr + ((min + max) / 2));

        do
        {
            while (mid > *(arr + left))
                left++;
            while (mid < *(arr + right))
                right--;
            if (left <= right)
            {
                int temp = *(arr + left);
                *(arr + left) = *(arr + right);
                *(arr + right) = temp;
                left++;
                right--;
            }
        } while (left < right);

        q_sort(arr, min, right);
        q_sort(arr, left, max);
    }
}

void sort(struct matrix* mt)
{
    if (!mt || mt->y_size == 0 || mt->x_size == 0) return;

    int* arr = (int*)malloc((mt->x_size * mt->y_size) * sizeof(int));
    int arr_size = 0, i, j;

    for (i = 0; i < mt->y_size; ++i)
        for (j = 0; j < mt->x_size; ++j)
            *(arr + arr_size++) = *(*(mt->mtx + i) + j);
    
    q_sort(arr, 0, arr_size);
    i = 0;
    j = 0;

    for (int k = 0; k < arr_size; ++k)
    {
        *(*(mt->mtx + i) + j++) = *(arr + k);
        if (j == mt->x_size)
        {
            j = 0;
            i++;
        }
    }
    free(arr);
}

struct point* binary_search(struct matrix* mt, int number)
{
    if (!mt || !mt->mtx) return NULL;

    int row = 0;
    int col = mt->x_size - 1;
    struct point* pt;
    while (row < mt->x_size && col >= 0) {

        if (*(*(mt->mtx + row) + col) == number) 
        {
            pt = (struct point*)malloc(sizeof(struct point));
            pt->x = row;
            pt->y = col;
            return pt;    
        }

        if (*(*(mt->mtx + row) + col) < number) row++;
        else col--;
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