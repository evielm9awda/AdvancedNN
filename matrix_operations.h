#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

void matrix_multiply(double* result, double* matrix1, int rows1, int cols1, double* matrix2, int rows2, int cols2);
void matrix_add(double* result, double* matrix, double* biases, int rows, int cols);
double dot_product(double* vec1, double* vec2, int length);
double norm(double* vec, int length);

#endif // MATRIX_OPERATIONS_H

