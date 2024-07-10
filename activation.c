#include "activation.h"
#include <math.h>

double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

double tanh_activation(double x) {
    return tanh(x);
}

double relu(double x) {
    return fmax(0.0, x);
}

double leaky_relu(double x) {
    return x > 0.0 ? x : 0.01 * x;
}

void softmax(double* input, double* output, int length) {
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

