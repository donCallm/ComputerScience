#include <iostream>

using namespace std;

int* prefix_array(int* arr, int arr_size)
{
    int* prefix_arr = new int[arr_size + 1];

    prefix_arr[0] = 0;
    for (int i = 0; i < arr_size + 1; ++i)
        prefix_arr[i + 1] += prefix_arr[i] + arr[i];
    
    return prefix_arr;
}

void show_prefix_arr(int* prefix_arr, int arr_size)
{
    cout << "Prefix arr: ";

    for (int i = 0; i < arr_size; ++i)
        cout << prefix_arr[i] << " ";
}

int main()
{
    int arr_size = 10;
    int* arr = new int[arr_size];

    for (int i = 0; i < arr_size; ++i)
        arr[i] = i;
        
    show_prefix_arr(prefix_array(arr, arr_size), arr_size);
    return 0;
}