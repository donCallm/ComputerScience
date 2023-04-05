#ifndef MATRIX_H
#define MATRIX_H

struct matrix
{
    int col;
    int row;
    int** mtx;
};

struct matrix* create_matrix(int col, int row);
void fill_matrix(struct matrix* mt);
void print_matrix(struct matrix* mt);
void fill_diagonal(struct matrix* mt, int number);
void delete_matrix(struct matrix* mt);
void sort(struct matrix* mt);
struct point* binary_search(struct matrix* mt, int number);
void swap(struct matrix* mt, int col, int row);

#endif