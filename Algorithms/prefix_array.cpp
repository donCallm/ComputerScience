#include <iostream>
#include <vector>

using namespace std;

vector<int> prefix_array(vector<int> arr, int arr_size)
{
    vector<int> prefix_arr(arr_size + 1);

    prefix_arr[0] = 0;
    for (int i = 0; i < arr_size + 1; ++i)
        prefix_arr[i + 1] += prefix_arr[i] + arr[i];
    
    return prefix_arr;
}

void show_prefix_arr(vector<int> prefix_arr, int arr_size)
{
    for (int i = 0; i < arr_size; ++i)
        cout << prefix_arr[i] << " ";
}

int main()
{
    int arr_size = 10;
    vector<int> arr {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        
    show_prefix_arr(prefix_array(arr, arr_size), arr_size);
    return 0;
}