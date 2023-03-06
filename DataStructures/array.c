#include<stdio.h>
#include<malloc.h>
#include <stdlib.h>

#define CAPACITY_DEFAULT 5
#define CAPACITY_INCREACE(arr) ((int)(arr->capacity * 2))
#define CAPACITY_DECREASE(arr) ((int)(arr->capacity / 2))

struct array
{
    int capacity;
    int size;
    int *arr;
};

void create_array(struct array *arr)
{
    arr->size = 0;
    arr->capacity = CAPACITY_DEFAULT;
    arr->arr = (int*)malloc(arr->capacity * sizeof(int));
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
    if (arr->size == arr->capacity)
    {
        arr->capacity = CAPACITY_INCREACE(arr);
        arr->arr = realloc(arr->arr, arr->capacity * sizeof(int));
        arr->arr[arr->size++] = number;
        return;
    }

    arr->arr[arr->size++] = number;
}

void my_remove(struct array *arr, int index)
{
    if (is_valid_index(arr->size, index))
        return;

    for (size_t i = 0; i < arr->size; i++)
        if (i > index)
            arr->arr[i - 1] = arr->arr[i];

    if (CAPACITY_DECREASE(arr) >= CAPACITY_DEFAULT)
    {
        if (arr->size < (arr->capacity / 2))
        {
            arr->capacity /= 2;
            arr->arr = realloc(arr->arr, arr->capacity * sizeof(int));
        }
    }
    arr->size--;
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
    printf("capacity %d\n", p_arr->capacity);
    printf("size %d\n", p_arr->size);
    for (size_t i = 0; i < 30; i++)
        add(p_arr, i);
    print_arr(p_arr);
    printf("capacity %d\n", p_arr->capacity);
    printf("size %d\n", p_arr->size);
    for (int i = 29; i >= 0; i--)
        my_remove(p_arr, i);
    print_arr(p_arr);
    printf("capacity %d\n", p_arr->capacity);
    printf("size %d\n", p_arr->size);
    delete(p_arr);
    
    return 0;
}


