#include "matrix_operations.h"
#include <math.h>

void matrix_multiply(double* a, double* b, double* result, int a_rows, int a_cols, int b_cols) {
    for (int i = 0; i < a_rows; ++i) {
        for (int j = 0; j < b_cols; ++j) {
            result[i * b_cols + j] = 0.0;
            for (int k = 0; k < a_cols; ++k) {
                result[i * b_cols + j] += a[i * a_cols + k] * b[k * b_cols + j];
            }
        }
    }
}

void matrix_add_bias(double* matrix, double* biases, double* result, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i * cols + j] = matrix[i * cols + j] + biases[j];
        }
    }
}

double dot_product(double* vec1, double* vec2, int length) {
    double result = 0.0;
    for (int i = 0; i < length; ++i) {
        result += vec1[i] * vec2[i];
    }
    return result;
}

double norm(double* vec, int length) {
    double sum = 0.0;
    for (int i = 0; i < length; ++i) {
        sum += vec[i] * vec[i];
    }
    return sqrt(sum);
}

