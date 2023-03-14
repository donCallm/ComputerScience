#ifndef ARRAY_H
#define ARRAY_H

#define CAPACITY_DEFAULT 5
#define ARR_CAPACITY_INCREACE(arr) ((int)(arr->capacity * 2))
#define ARR_CAPACITY_DECREASE(arr) ((int)(arr->capacity / 2))

struct array
{
    int capacity;
    int size;
    int *arr;
};

void create_array(struct array *arr);
int is_valid_index(int size, int index);
void add(struct array *arr, int number);
void my_remove(struct array *arr, int index);
void delete_arr(struct array *arr);
void filling_array(struct array *arr);
void print_arr(struct array *arr);
int partition(struct array *a, int l, int r);
void quick_sort(struct array *arr);
int compare_array(struct array *arr1, struct array *arr2);
void shuffle(struct array *arr);
void buble_sort(struct array *arr);
void selection_sort(struct array *arr);
void insertion_sort(struct array *arr);

#endif