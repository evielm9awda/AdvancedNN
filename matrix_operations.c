#include "matrix_operations.h"

Matrix* create_matrix(size_t rows, size_t cols) {
    Matrix *matrix = (Matrix*)malloc(sizeof(Matrix));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = (double**)malloc(rows * sizeof(double*));
    for (size_t i = 0; i < rows; ++i) {
        matrix->data[i] = (double*)malloc(cols * sizeof(double));
    }
    return matrix;
}

void free_matrix(Matrix *matrix) {
    for (size_t i = 0; i < matrix->rows; ++i) {
        free(matrix->data[i]);
    }
    free(matrix->data);
    free(matrix);
}

Matrix* matrix_multiply(const Matrix *a, const Matrix *b) {
    if (a->cols != b->rows) return NULL;
    Matrix *result = create_matrix(a->rows, b->cols);
    for (size_t i = 0; i < a->rows; ++i) {
        for (size_t j = 0; j < b->cols; ++j) {
            result->data[i][j] = 0;
            for (size_t k = 0; k < a->cols; ++k) {
                result->data[i][j] += a->data[i][k] * b->data[k][j];
            }
        }
    }
    return result;
}

Matrix* matrix_add_bias(const Matrix *a, const Matrix *bias) {
    if (a->cols != bias->cols || bias->rows != 1) return NULL;
    Matrix *result = create_matrix(a->rows, a->cols);
    for (size_t i = 0; i < a->rows; ++i) {
        for (size_t j = 0; j < a->cols; ++j) {
            result->data[i][j] = a->data[i][j] + bias->data[0][j];
        }
    }
    return result;
}

Matrix* matrix_transpose(const Matrix *a) {
    Matrix *result = create_matrix(a->cols, a->rows);
    for (size_t i = 0; i < a->rows; ++i) {
        for (size_t j = 0; j < a->cols; ++j) {
            result->data[j][i] = a->data[i][j];
        }
    }
    return result;
}

double matrix_determinant(const Matrix *a) {
    // Determinant calculation for a square matrix
    // Implement using recursive approach or other algorithms
    return 0; // Placeholder
}

Matrix* matrix_inverse(const Matrix *a) {
    // Matrix inversion for a square matrix
    // Implement using Gauss-Jordan elimination or other methods
    return NULL; // Placeholder
}

Matrix* random_matrix(size_t rows, size_t cols) {
    Matrix *matrix = create_matrix(rows, cols);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            matrix->data[i][j] = ((double)rand() / RAND_MAX) * 2.0 - 1.0;
        }
    }
    return matrix;
}

void print_matrix(const Matrix *matrix) {
    for (size_t i = 0; i < matrix->rows; ++i) {
        for (size_t j = 0; j < matrix->cols; ++j) {
            printf("%f ", matrix->data[i][j]);
        }
        printf("\n");
    }
}

