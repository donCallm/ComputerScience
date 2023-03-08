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

void create_array(struct array *arr)
{
    arr->size = 0;
    arr->capacity = CAPACITY_DEFAULT;
    arr->arr = (int*)malloc(arr->capacity * sizeof(int));
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
    printf("\n---------------\n");
    printf("capacity array %d\n", arr->capacity);
    printf("size array %d\n", arr->size);
    printf("---------------\n");
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
    if (arr1->size != arr2->size || arr2->size == 0 && arr1->size == 0)
        return 0;

    for (size_t i = 0; i < arr1->size; i++)
        if (arr1->arr[i] != arr2->arr[i])
            return 0;
    
    return 1;
}

void shuffle(struct array *arr)
{
    if (arr->size == 0)
        return;
    
    int rand_index = 0;
    for (size_t i = 0; i < arr->size; i++)
    {
        rand_index = rand()%(arr->size - 1);
        int temp = arr->arr[i];
        arr->arr[0] = arr->arr[rand_index];
        arr->arr[rand_index] = temp;
    }
}

int main()
{
    struct array *p_arr1 = (struct array*)malloc(sizeof(struct array));
    struct array *p_arr2 = (struct array*)malloc(sizeof(struct array));

    create_array(p_arr1);
    create_array(p_arr2);

    print_arr(p_arr1);
    print_arr(p_arr2);

    for (int i = 10; i > 0; i--)
        add(p_arr1, i);
    for (int i = 10; i > 0; i--)
        add(p_arr2, i);
    
    print_arr(p_arr1);
    print_arr(p_arr2);

    printf("Sort first array\n");
    quick_sort(p_arr1->arr, 0, p_arr1->size - 1);
    print_arr(p_arr1);
    
    printf("Shuffle second array\n");
    shuffle(p_arr2);
    print_arr(p_arr2);

    printf("Compare result: ");
    if(compare_array(p_arr1, p_arr2))
        printf("identical\n");
    else
        printf("different\n");
    printf("---------------\n");

    for (int i = 10; i >= 0; i--)
        my_remove(p_arr1, i);
    for (int i = 10; i >= 0; i--)
        my_remove(p_arr2, i);
    
    print_arr(p_arr1);
    print_arr(p_arr2);

    delete(p_arr1);
    delete(p_arr2);
    
    return 0;
}


