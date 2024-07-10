#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

void matrix_multiply(double* a, double* b, double* result, int a_rows, int a_cols, int b_cols);
void matrix_add_bias(double* matrix, double* biases, double* result, int rows, int cols);
double dot_product(double* vec1, double* vec2, int length);
double norm(double* vec, int length);

#endif // MATRIX_OPERATIONS_H

