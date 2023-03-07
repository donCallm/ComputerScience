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

int is_valid_index(int size, int index)
{
    if (size == 0 || size < index)
        return 1;
    return 0;
}

int is_valid_size(int first_size, int second_size)
{
    if (first_size == 0 || second_size == 0 || first_size != second_size)
        return 1;
    return 0; 
}

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
        if (arr->size < CAPACITY_DECREASE(arr))
        {
            arr->capacity = CAPACITY_DECREASE(arr);
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

void quick_sort(int *arr, int first, int last)
{
    if (arr == NULL)
        return;

    if(first < last)
    {
        int privot = arr[(first + last)/2];
        int left_index = first;
        int right_index = last;
        do
        {
            while(arr[left_index] < privot)
                left_index++;
            while (arr[right_index] > privot)
                right_index--;
            
            if (left_index <= right_index)
            {
                int temp = arr[left_index];
                arr[left_index] = arr[right_index];
                arr[right_index] = temp;
                right_index--;
                left_index++;
            }
        }while (left_index < right_index);
        quick_sort(arr, first, right_index);
        quick_sort(arr, left_index, last);
    }
}

int compare_array(struct array *arr1, struct array *arr2)
{
    if (is_valid_size(arr1->size, arr2->size))
        return 0;
    
    int temp = 0;

    for (size_t i = 0; i < arr1->size; i++)
        if (arr1->arr[i] != arr2->arr[i])
        {
            temp++;
            break;
        }
    
    if (temp != 0)
        return 0;
    
    return 1;
}

int main()
{
    struct array *p_arr1 = (struct array*)malloc(sizeof(struct array));
    struct array *p_arr2 = (struct array*)malloc(sizeof(struct array));

    create_array(p_arr1);
    create_array(p_arr2);

    printf("capacity array1 %d\n", p_arr1->capacity);
    printf("size array1 %d\n", p_arr1->size);
    printf("capacity array2 %d\n", p_arr2->capacity);
    printf("size array2 %d\n", p_arr2->size);

    for (int i = 10; i > 0; i--)
        add(p_arr1, i);
    for (int i = 10; i > 0; i--)
        add(p_arr2, i);
    
    print_arr(p_arr1);
    print_arr(p_arr2);
    printf("capacity array1: %d\n", p_arr1->capacity);
    printf("size array1: %d\n", p_arr1->size);
    printf("capacity array2: %d\n", p_arr2->capacity);
    printf("size array2: %d\n", p_arr2->size);

    printf("Sort first array\n");
    quick_sort(p_arr1->arr, 0, p_arr1->size);
    print_arr(p_arr1);

    printf("Compare result: ");
    if(compare_array(p_arr1, p_arr2))
        printf("identical\n");
    else
        printf("different\n");

    for (int i = 10; i >= 0; i--)
        my_remove(p_arr1, i);
    for (int i = 10; i >= 0; i--)
        my_remove(p_arr2, i);
    
    print_arr(p_arr1);
    print_arr(p_arr2);
    printf("capacity array1: %d\n", p_arr1->capacity);
    printf("size array1: %d\n", p_arr1->size);
    printf("capacity array2: %d\n", p_arr2->capacity);
    printf("size array2: %d\n", p_arr2->size); 

    delete(p_arr1);
    
    return 0;
}


