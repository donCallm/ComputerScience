#ifndef PREFIX_ARR_H
#define PREFIX_ARR_H

namespace prefix_arr
{
    class prefix_array
    {
        private:
            int* _data;
            int _size;
        public:
            prefix_array(int* arr, int arr_size);
            ~prefix_array();
            void show_prefix_arr();
    };
}

#endif