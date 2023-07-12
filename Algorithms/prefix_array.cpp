#include <iostream>
#include <vector>

std::vector<int> prefix_array(const std::vector<int>& arr)
{
    std::vector<int> prefix_arr(arr.size() + 1);

    prefix_arr[0] = 0;
    for (int i = 0; i < arr.size(); ++i)
        prefix_arr[i + 1] += prefix_arr[i] + arr[i];
    
    return prefix_arr;
}

void show_prefix_arr(const std::vector<int>& prefix_arr)
{
    for (int i = 0; i < prefix_arr.size(); ++i)
        std::cout << prefix_arr[i] << " ";
}

int main()
{
    std::vector<int> arr {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        
    show_prefix_arr(prefix_array(arr));
    return 0;
}