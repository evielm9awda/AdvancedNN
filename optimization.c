#include "optimization.h"
#include <stdlib.h>
#include <math.h>

void gradient_descent(NeuralNetwork* nn, double* gradients, double learning_rate) {
    for (int i = 0; i < nn->num_layers; ++i) {
        Layer* layer = &nn->layers[i];
        for (int j = 0; j < layer->num_inputs * layer->num_outputs; ++j) {
            layer->weights[j] -= learning_rate * gradients[j];
        }
        for (int j = 0; j < layer->num_outputs; ++j) {
            layer->biases[j] -= learning_rate * gradients[layer->num_inputs * layer->num_outputs + j];
        }
    }
}

void adam_optimizer(NeuralNetwork* nn, double* gradients, double learning_rate, double beta1, double beta2, double epsilon) {
    static double* m = NULL;
    static double* v = NULL;
    static int t = 0;

    if (m == NULL) {
        int total_params = 0;
        for (int i = 0; i < nn->num_layers; ++i) {
            total_params += nn->layers[i].num_inputs * nn->layers[i].num_outputs + nn->layers[i].num_outputs;
        }
        m = (double*)calloc(total_params, sizeof(double));
        v = (double*)calloc(total_params, sizeof(double));
    }

    t++;

    int param_idx = 0;
    for (int i = 0; i < nn->num_layers; ++i) {
        Layer* layer = &nn->layers[i];
        for (int j = 0; j < layer->num_inputs * layer->num_outputs; ++j) {
            m[param_idx] = beta1 * m[param_idx] + (1.0 - beta1) * gradients[param_idx];
            v[param_idx] = beta2 * v[param_idx] + (1.0 - beta2) * gradients[param_idx] * gradients[param_idx];

            double m_hat = m[param_idx] / (1.0 - pow(beta1, t));
            double v_hat = v[param_idx] / (1.0 - pow(beta2, t));

            layer->weights[j] -= learning_rate * m_hat / (sqrt(v_hat) + epsilon);
            param_idx++;
        }
        for (int j = 0; j < layer->num_outputs; ++j) {
            m[param_idx] = beta1 * m[param_idx] + (1.0 - beta1) * gradients[param_idx];
            v[param_idx] = beta2 * v[param_idx] + (1.0 - beta2) * gradients[param_idx] * gradients[param_idx];

            double m_hat = m[param_idx] / (1.0 - pow(beta1, t));
            double v_hat = v[param_idx] / (1.0 - pow(beta2, t));

            layer->biases[j] -= learning_rate * m_hat / (sqrt(v_hat) + epsilon);
            param_idx++;
        }
    }
}

