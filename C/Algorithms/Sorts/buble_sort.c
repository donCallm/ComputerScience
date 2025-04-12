#include <stdio.h>
#include <malloc.h>

void buble_sort(int arr[], int arr_size)
{
    if (arr == NULL)
        return;

  for (size_t i = 0; i < arr_size - 1; i++)
    {
        for (size_t j = 0; j < arr_size - (i + 1); j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
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