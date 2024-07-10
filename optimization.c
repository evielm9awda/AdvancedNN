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

    ++t;
    for (int i = 0; i < nn->num_layers; ++i) {
        Layer* layer = &nn->layers[i];
        int offset = i * (layer->num_inputs * layer->num_outputs + layer->num_outputs);

        for (int j = 0; j < layer->num_inputs * layer->num_outputs; ++j) {
            m[offset + j] = beta1 * m[offset + j] + (1 - beta1) * gradients[offset + j];
            v[offset + j] = beta2 * v[offset + j] + (1 - beta2) * gradients[offset + j] * gradients[offset + j];

            double m_hat = m[offset + j] / (1 - pow(beta1, t));
            double v_hat = v[offset + j] / (1 - pow(beta2, t));

            layer->weights[j] -= learning_rate * m_hat / (sqrt(v_hat) + epsilon);
        }

        for (int j = 0; j < layer->num_outputs; ++j) {
            m[offset + layer->num_inputs * layer->num_outputs + j] = beta1 * m[offset + layer->num_inputs * layer->num_outputs + j] + (1 - beta1) * gradients[offset + layer->num_inputs * layer->num_outputs + j];
            v[offset + layer->num_inputs * layer->num_outputs + j] = beta2 * v[offset + layer->num_inputs * layer->num_outputs + j] + (1 - beta2) * gradients[offset + layer->num_inputs * layer->num_outputs + j] * gradients[offset + layer->num_inputs * layer->num_outputs + j];

            double m_hat = m[offset + layer->num_inputs * layer->num_outputs + j] / (1 - pow(beta1, t));
            double v_hat = v[offset + layer->num_inputs * layer->num_outputs + j] / (1 - pow(beta2, t));

            layer->biases[j] -= learning_rate * m_hat / (sqrt(v_hat) + epsilon);
        }
    }
}

