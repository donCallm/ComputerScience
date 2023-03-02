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

int is_valid(int size, int index)
{
    if (size == 0 || size < index)
        return 1;
    return 0;
}

void add(struct array *array, int number)
{
    int *temp_array = (int*)malloc((array->size + 1) * sizeof(int));

    for (size_t i = 0; i < array->size; i++)
        temp_array[i] = array->arr[i];
    
    free(array->arr);
    array->size = array->size + 1;
    array->arr = temp_array;
    array->arr[array->size - 1] = number;
}

void my_remove(struct array *array, int index)
{
    if (is_valid(array->size, index) >= 1)
        return;

    if (array->size == 1)
    {
        array->arr = NULL;
        array->size = 0;
        return;
    }

    int *temp_array = (int*)malloc((array->size - 1) * sizeof(int));

    for (size_t i = 0; i <= index; i++)
        if (i == index)
            for (size_t j = i + 1; j < array->size; j++)
                temp_array[j] = array->arr[j + 1];

    free(array->arr);
    array->size = array->size - 1;
    array->arr = temp_array;
}

void delete(struct array *array)
{
    array = NULL;
}

void print_arr(struct array *array)
{
    printf("Array: ");
    for (size_t i = 0; i < array->size; i++)
        printf("%d ", array->arr[i]);
    printf("\n");
}

int main()
{
    struct array array;
    struct array *p_array = &array;
    create_array(p_array); 
    add(p_array, 1);
    print_arr(p_array);
    my_remove(p_array, 0);
    print_arr(p_array);
    delete(p_array);
    
    return 0;
}

