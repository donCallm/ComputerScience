#include<stdio.h>
#include<malloc.h>
#include <stdlib.h>

#define CAPACITY_DEFAULT 5
#define ARR_CAPACITY_INCREACE(arr) ((int)(arr->capacity * 2))
#define STK_CAPACITY_INCREACE(stk) ((int)(stk->capacity * 2))
#define ARR_CAPACITY_DECREASE(arr) ((int)(arr->capacity / 2))
#define STK_CAPACITY_DECREASE(stk) ((int)(stk->capacity / 2))

struct array
{
    int capacity;
    int size;
    int *arr;
};

struct stack
{
    struct pair *pr;
    int capacity;
    int top;
};

struct pair
{
    int first;
    int second;
};

void init_stack(struct stack *stk)
{
    stk->top = 0;
    stk->capacity = CAPACITY_DEFAULT;
    stk->pr = (struct pair*)malloc(stk->capacity * sizeof(struct pair));
}

void push(struct stack *stk, int first_number, int second_number)
{
    if (stk->top == stk->capacity)
    {
        stk->capacity = STK_CAPACITY_INCREACE(stk);
        stk->pr = realloc(stk->pr, stk->capacity * sizeof(struct pair));
        stk->pr[stk->top].first = first_number;
        stk->pr[stk->top++].second = second_number;
        return;
    }
    stk->pr[stk->top].first = first_number;
    stk->pr[stk->top++].second = second_number;
}

struct pair pop(struct stack *stk)
{
    stk->top--;

    if (STK_CAPACITY_DECREASE(stk) >= CAPACITY_DEFAULT)
    {
        if (stk->top < STK_CAPACITY_DECREASE(stk))
        {
            stk->capacity = STK_CAPACITY_DECREASE(stk);
            stk->pr = (struct pair*)realloc(stk->pr, stk->capacity * sizeof(struct pair));
        }
    }

    return stk->pr[stk->top];
}

int is_not_empty(struct stack *stk)
{
    if (stk->top != 0)
        return 1;
    return 0;
}

void create_array(struct array *arr)
{
    arr->size = 0;
    arr->capacity = CAPACITY_DEFAULT;
    arr->arr = (int*)malloc(arr->capacity * sizeof(int));
}

int is_valid_index(int size, int index)
{
    if (size == 0 || size < index)
        return 0;
    return 1;
}

void add(struct array *arr, int number)
{
    if (arr->size == arr->capacity)
    {
        arr->capacity = ARR_CAPACITY_INCREACE(arr);
        arr->arr = realloc(arr->arr, arr->capacity * sizeof(int));
        arr->arr[arr->size++] = number;
        return;
    }

    arr->arr[arr->size++] = number;
}

void my_remove(struct array *arr, int index)
{
    if (!is_valid_index(arr->size, index))
        return;

    for (size_t i = 0; i < arr->size; i++)
        if (i > index)
            arr->arr[i - 1] = arr->arr[i];

    if (ARR_CAPACITY_DECREASE(arr) >= CAPACITY_DEFAULT)
    {
        if (arr->size < ARR_CAPACITY_DECREASE(arr))
        {
            arr->capacity = ARR_CAPACITY_DECREASE(arr);
            arr->arr = realloc(arr->arr, arr->capacity * sizeof(int));
        }
    }
    arr->size--;
}

void delete_arr(struct array *arr)
{
    free(arr->arr);
    free(arr);
}

void delete_stack(struct stack *stk)
{
    free(stk->pr);
    free(stk);
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

int partition(struct array *a, int l, int r)
{
    int v = a->arr[(int)(l + r) / 2];
    int i = l;
    int j = r;
    while (i <= j) 
    {
        while (a->arr[i] < v)
            i++;
        while (a->arr[j] > v)
            j--;
        if (i >= j) 
            break;
        int temp = a->arr[i];
        a->arr[i] = a->arr[j];
        a->arr[j] = temp;
        i++;
        j--;
    }
    return j;
}

void quick_sort(struct array *arr)
{
    if (arr == NULL || arr->size <= 1)
        return;

    struct stack stk;
    init_stack(&stk);
    struct pair pr;
    int left = 0;
    int right = arr->size - 1;
    push(&stk, left, right);

    while (is_not_empty(&stk))
    {
        pr = pop(&stk);
        left = pr.first;
        right = pr.second;
        
        if (right <= left)
            continue;
        
        int i = partition(arr, left, right);

        if (i - left > right - i)
        {
            push(&stk, left, i - 1);
            push(&stk, i + 1, right);
        }
        else
        {
            push(&stk, i + 1, right);
            push(&stk, left, i - 1);
        }
    }
    free(stk.pr);
}

int compare_array(struct array *arr1, struct array *arr2)
{
    if (arr1->size != arr2->size)
        return 0;

    for (size_t i = 0; i < arr1->size; i++)
        if (arr1->arr[i] != arr2->arr[i])
            return 0;
    
    return 1;
}

void shuffle(struct array *arr)
{
    if (arr->size <= 1)
        return;
    
    int rand_index = 0;
    for (size_t i = 0; i < arr->size; i++)
    {
        rand_index = rand()%(arr->size - 1);
        int temp = arr->arr[i];
        arr->arr[i] = arr->arr[rand_index];
        arr->arr[rand_index] = temp;
    }
}

void buble_sort(struct array *arr)
{
    if (arr == NULL || arr->size <= 1)
        return;

    for (size_t i = 0; i < arr->size - 1; i++)
    {
        for (size_t j = 0; j < (arr->size - i) - 1; j++)
        {
            if (arr->arr[j] > arr->arr[j + 1])
            {
                int temp = arr->arr[j];
                arr->arr[j] = arr->arr[j + 1];
                arr->arr[j + 1] = temp;
            }
        }
    }
}

void selection_sort(struct array *arr)
{
    if (arr == NULL || arr->size <= 1)
        return;

    for (size_t i = 0; i < arr->size - 1; i++)
    {

        for (size_t j = i + i; j < arr->size; j++)
        {
            int min_index = i;
            
            if (arr->arr[min_index] > arr->arr[j])
                min_index = j;

            int temp = arr->arr[min_index];
            arr->arr[min_index] = arr->arr[i];
            arr->arr[i] = temp;
        }
    }
}

void insertion_sort(struct array *arr)
{
    if (arr == NULL || arr->size <= 1)
        return;

    for (size_t i = 0; i < arr->size; i++)
    {
        int number = arr->arr[i];
        int index = i;
        
        while (index > 0 && number < arr->arr[index - 1])
        {
            arr->arr[index] = arr->arr[index - 1];
            index--;
        }
        arr->arr[index] = number;
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
    quick_sort(p_arr1);
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

    delete_arr(p_arr1);
    delete_arr(p_arr2);

    struct stack stk;
    init_stack(&stk);

    for (size_t i = 0; i < 10; i++)
        push(&stk, i, i);

    printf("\nis not empty %d\n", is_not_empty(&stk));

    struct pair pr;
    while (is_not_empty(&stk))
    {
        pr = pop(&stk);
        printf("%d and %d\n", pr.first, pr.second);
    }
    
    printf("is not empty %d\n", is_not_empty(&stk));
    free(stk.pr);

    struct array *arr3 = (struct array*)malloc(sizeof(struct array));

    printf("S----------------\n");
    printf("S----------------\n");
    printf("S----------------\n");
    
    create_array(arr3);
    filling_array(arr3);
    
    print_arr(arr3);
    shuffle(arr3);
    print_arr(arr3);
    
    printf("QSORT\n");
    quick_sort(arr3);
    print_arr(arr3);

    printf("S----------------\n");
    shuffle(arr3);
    print_arr(arr3);

    printf("BUBLE_SORT\n");
    buble_sort(arr3);
    print_arr(arr3);

    printf("S----------------\n");  
    shuffle(arr3);
    print_arr(arr3);    

    printf("SELECTION_SORT\n");
    selection_sort(arr3);
    print_arr(arr3);

    printf("S----------------\n");  
    shuffle(arr3);
    print_arr(arr3);

    printf("INSERTION_SORT\n");
    insertion_sort(arr3);
    print_arr(arr3);

    delete_arr(arr3);

    return 0;
}


