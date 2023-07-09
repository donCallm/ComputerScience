#include "prefix_array.hpp"
#include "test.hpp"
#include <iostream>

using namespace prefix_arr;
using namespace std;

void test_create()
{
    int arr_size = 7;
    int* arr = new int[arr_size];

    for (int i = 1; i < arr_size; ++i)
        arr[i] = i;
    
    prefix_array pre_arr {arr, arr_size};

    pre_arr.show_prefix_arr();

    delete arr;
}

void do_test()
{
    test_create();
}