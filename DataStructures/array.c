#include<stdio.h>
#include<malloc.h>
#include <stdlib.h>

struct array
{
    int size;
    int *arr;
};

void create_array(struct array *arr)
{
    arr->size = 0;
    arr->arr = (int*)malloc(0 * sizeof(int));
}

int size(struct array *arr)
{
    return arr->size;
}

int is_valid_index(int size, int index)
{
    if (size == 0 || size < index)
        return 1;
    return 0;
}

void add(struct array *arr, int number)
{
    arr->arr = (int*) realloc(arr->arr, ++arr->size * sizeof(int));
    arr->arr[arr->size - 1] = number;
}

void my_remove(struct array *arr, int index)
{
    if (is_valid_index(arr->size, index) >= 1)
        return;

    for (size_t i = 0; i <= arr->size; i++)
        if (i > index)
            arr->arr[i - 1] = arr->arr[i];

    arr->arr = (int*) realloc(arr->arr, --arr->size * sizeof(int));
}

void delete(struct array *arr)
{
    free(arr->arr);
    free(arr);
}

void filling_array(struct array *arr)
{
    for (size_t i = 0; i < 100; i++)
        add(arr, i);
}

void print_arr(struct array *arr)
{
    printf("Array: ");
    for (size_t i = 0; i < arr->size; i++)
        printf("%d ", arr->arr[i]);
    printf("\n");
}

int main()
{
    struct array *p_arr = (struct array*)malloc(sizeof(struct array));
    create_array(p_arr);
    filling_array(p_arr);
    print_arr(p_arr);
    my_remove(p_arr, 6);
    print_arr(p_arr);
    delete(p_arr);
    
    return 0;
}

