#include "regularization.h"

double l2_regularization(double* weights, int length, double lambda) {
    double l2_loss = 0.0;
    for (int i = 0; i < length; ++i) {
        l2_loss += weights[i] * weights[i];
    }
    return lambda * l2_loss;
}

void apply_l2_regularization(NeuralNetwork* nn, double lambda) {
    for (int i = 0; i < nn->num_layers; ++i) {
        Layer* layer = &nn->layers[i];
        double reg_loss = l2_regularization(layer->weights, layer->num_inputs * layer->num_outputs, lambda);
        for (int j = 0; j < layer->num_inputs * layer->num_outputs; ++j) {
            layer->weights[j] -= lambda * layer->weights[j];
        }
    }
}

