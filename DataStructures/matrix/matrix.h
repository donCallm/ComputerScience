#ifndef MATRIX_H
#define MATRIX_H

struct matrix
{
    int y_size;
    int x_size;
    int** mtx;
};

struct matrix* create_matrix(int y_size, int x_size);
void fill_matrix(struct matrix* mt);
void print_matrix(struct matrix* mt);
void fill_diagonal(struct matrix* mt, int number);
void delete_matrix(struct matrix* mt);
void sort(struct matrix* mt);
struct point* binary_search(struct matrix* mt, int number);
void swap(struct matrix* mt, int y_size, int x_size);

#endif