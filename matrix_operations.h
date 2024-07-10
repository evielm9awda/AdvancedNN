#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

#include <stdlib.h>
#include <math.h>
#include <stdio.h>

typedef struct {
    double **data;
    size_t rows;
    size_t cols;
} Matrix;

// Matrix operations
Matrix* create_matrix(size_t rows, size_t cols);
void free_matrix(Matrix *matrix);
Matrix* matrix_multiply(const Matrix *a, const Matrix *b);
Matrix* matrix_add_bias(const Matrix *a, const Matrix *bias);
Matrix* matrix_transpose(const Matrix *a);
double matrix_determinant(const Matrix *a);
Matrix* matrix_inverse(const Matrix *a);

// Utility functions
Matrix* random_matrix(size_t rows, size_t cols);
void print_matrix(const Matrix *matrix);

#endif // MATRIX_OPERATIONS_H

