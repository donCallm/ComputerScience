#include <stdio.h>

void insert_sort(int arr[], int arr_size)
{
    if (arr == NULL)
        return;

    for (size_t i = 0; i < arr_size; i++)
    {
        int number = arr[i];
        int index = i;
        
        while (index > 0 && number < arr[index - 1])
        {
            arr[index] = arr[index - 1];
            index--;
        }
        arr[index] = number;
    }
    
}

void print_arr(int arr[], int arr_size)
{
    if (arr == NULL)
        return;

    printf("Array: ");
    for (size_t i = 0; i < arr_size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int *arr = NULL;
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    print_arr(arr, arr_size);
    buble_sort(arr, arr_size);
    print_arr(arr, arr_size);

    free(arr);

    return 0;
}
