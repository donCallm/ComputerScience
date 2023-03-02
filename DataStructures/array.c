#include<stdio.h>
#include<malloc.h>

struct array
{
    int size;
    int *arr;
};

void create_array(struct array *array)
{
    array->size = 0;
    array->arr = (int*)malloc(0 * sizeof(int));
}

int size(struct array *array)
{
    return array->size;
}

void add(struct array *array, int number)
{
    int *temp_array = (int*)malloc(array->size * sizeof(int));

    for (size_t i = 0; i < array->size; i++)
        temp_array[i] = array->arr[i];
    
    array->size = array->size + 1;
    array->arr = (int*)malloc(array->size * sizeof(int));

    for (size_t i = 0; i < array->size - 1; i++)
        array->arr[i] = temp_array[i];
    
    array->arr[array->size - 1] = number;
}

void my_remove(struct array *array, int index)
{
    if (array->size == 0)
        return;

    if (array->size < index)
        return;

    if (array->size == 1)
    {
        array->arr = NULL;
        array->size = 0;
        return;
    }

    int *temp_array = (int*)malloc(array->size * sizeof(int));

    for (size_t i = 0; i < array->size; i++)
        temp_array[i] = array->arr[i];

    array->size = array->size - 1;
    array->arr = (int*)malloc(array->size * sizeof(int));

    for (size_t i = 0; i <= index; i++)
        if (i == index)
            for (size_t j = i + 1; j < array->size; j++)
                array->arr[j - 1] = temp_array[j];
}

void delete(struct array *array)
{
    free(array->arr);
}

void print_arr(int arr[], int arr_size)
{
    printf("Array: ");
    for (size_t i = 0; i < arr_size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    struct array array;
    struct array *p_array = &array;
    create_array(p_array);
    add(p_array, 1);
    print_arr(p_array->arr, p_array->size);
    my_remove(p_array, 0);
    print_arr(p_array->arr, p_array->size);
    delete(p_array);
    
    return 0;
}

