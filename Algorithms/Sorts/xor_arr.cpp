#include <iostream>

using namespace std;

int* xor_arr(int* arr1, int* arr2, int arr_size)
{
    int* xor_arr = new int[arr_size];

    for (int i = 0; i < arr_size; ++i)
        if (arr1[i] == arr2[i]) xor_arr[i] = 0;
        else xor_arr[i] = 1;

    return xor_arr;
}

void show_xor_arr(int* xor_arr, int arr_size)
{
    cout << "Xor array: ";
    for (int i = 0; i < arr_size; ++i)
        cout << xor_arr[i] << " ";
}

int main()
{
    int arr_size = 10;
    int* arr1 = new int[arr_size];
    int* arr2 = new int(arr_size);

    for (int i = 0; i < arr_size; ++i)
        arr1[i] = i;

    for (int i = arr_size - 1; i >= 0; --i)
        arr1[i] = i;
    
    show_xor_arr(xor_arr(arr1, arr2, arr_size), arr_size);
    return 0;
}