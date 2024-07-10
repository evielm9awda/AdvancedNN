#include "matrix_operations.h"
#include <math.h>

void matrix_multiply(double* result, double* matrix1, int rows1, int cols1, double* matrix2, int rows2, int cols2) {
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols2; ++j) {
            result[i * cols2 + j] = 0.0;
            for (int k = 0; k < cols1; ++k) {
                result[i * cols2 + j] += matrix1[i * cols1 + k] * matrix2[k * cols2 + j];
            }
        }
    }
}

void matrix_add(double* result, double* matrix, double* biases, int rows, int cols) {
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

