#include "prefix_array.hpp"
#include <iostream>

using namespace prefix_arr;
using namespace std;

prefix_array::prefix_array(int* arr, int arr_size)
{
    _size = ++arr_size;
    _data = new int[_size];

    _data[0] = 0;

    for (int i = 0; i < _size - 1; ++i)
        _data[i + 1] = arr[i] + _data[i];
}

prefix_array::~prefix_array()
{
    delete[] _data;
    cout << "Destructor" << endl;
}

void prefix_array::show_prefix_arr()
{
    cout << "Prefix array: ";

    for (int i = 0; i < _size; ++i)
        cout << _data[i] << " ";
}