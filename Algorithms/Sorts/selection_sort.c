#include <stdio.h>

void selection_sort(int arr[], int arr_size)
{
    if (arr == NULL)
    {
        printf("Array was null\n");
        return;
    }

    for (size_t i = 0; i < arr_size - 1; i++)
    {
        for (size_t j = i; j < arr_size; j++)
        {
            int min_index = i;

            if (arr[min_index] > arr[j])
                min_index = j;

            int temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }
}

void print_arr(int arr[], int arr_size)
{
    if (arr == NULL)
    {
        printf("Array was null\n");
        return;
    }

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
    selection_sort(arr, arr_size);
    print_arr(arr, arr_size);

    free(arr);

    return 0;
}
