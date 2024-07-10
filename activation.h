#ifndef ACTIVATION_H
#define ACTIVATION_H

#include <math.h>

// Activation functions
typedef enum {
    SIGMOID,
    TANH,
    RELU,
    LEAKY_RELU,
    SOFTMAX
} Activation;

static inline double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

static inline double tanh_custom(double x) {
    return tanh(x);
}

static inline double relu(double x) {
    return fmax(0.0, x);
}

static inline double leaky_relu(double x) {
    return x > 0 ? x : 0.01 * x;
}

static inline void softmax(double* output, double* input, int length) {
    double max = input[0];
    for (int i = 1; i < length; ++i) {
        if (input[i] > max) {
            max = input[i];
        }
    }
    double sum = 0.0;
    for (int i = 0; i < length; ++i) {
        output[i] = exp(input[i] - max);
        sum += output[i];
    }
    for (int i = 0; i < length; ++i) {
        output[i] /= sum;
    }
}

#endif // ACTIVATION_H

