#ifndef MATRIX_H
#define MATRIX_H

struct matrix
{
    int y;
    int x;
    int** mtx;
};

struct matrix* create_matrix(int y, int x);
void fill_matrix(struct matrix* mt);
void print_matrix(struct matrix* mt);
void fill_diagonal(struct matrix* mt);
void delete_matrix(struct matrix* mt);
void sort(struct matrix* mt);
struct pair* binary_search(struct matrix* mt, int number);

#endif