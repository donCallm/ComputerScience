#include<stdio.h>
#include<malloc.h>

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
    int arr_size = 4;
    int *arr = (int*)malloc(arr_size * sizeof(int));
    arr[0] = 4;
    arr[1] = 3;
    arr[2] = 2;
    arr[3] = 1;

    print_arr(arr, arr_size);
    quick_sort(arr, 0, arr_size);
    print_arr(arr, arr_size);

    free(arr);

    return 0;
}