#include <iostream>
#include <vector>

using namespace std;

vector<int> xor_arr(vector<int> arr1, vector<int> arr2, int arr_size)
{
    vector<int> xor_arr (arr_size);

    for (int i = 0; i < arr_size; ++i)
        if (arr1[i] == arr2[i]) xor_arr[i] = 0;
        else xor_arr[i] = 1;

    return xor_arr;
}

void show_xor_arr(vector<int> xor_arr, int arr_size)
{
    cout << "Xor array: ";
    for (int i = 0; i < arr_size; ++i)
        cout << xor_arr[i] << " ";
}

int main()
{
    int arr_size = 10;
    vector<int> arr1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> arr2{0, 5, 2, 3, 1, 1, 6, 7, 5, 9};
    
    show_xor_arr(xor_arr(arr1, arr2, arr_size), arr_size);
    return 0;
}