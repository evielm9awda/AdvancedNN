#include "network.h"
#include <stdlib.h>

NeuralNetwork* init_neural_network(int num_layers, int* layer_sizes, Activation* activations) {
    NeuralNetwork* nn = (NeuralNetwork*)malloc(sizeof(NeuralNetwork));
    nn->num_layers = num_layers;
    nn->layers = (Layer*)malloc(num_layers * sizeof(Layer));

    for (int i = 0; i < num_layers; ++i) {
        nn->layers[i] = *init_layer(layer_sizes[i], layer_sizes[i + 1], activations[i]);
    }

    return nn;
}

void free_neural_network(NeuralNetwork* nn) {
    for (int i = 0; i < nn->num_layers; ++i) {
        free_layer(&nn->layers[i]);
    }
    free(nn->layers);
    free(nn);
}

void forward_propagation(NeuralNetwork* nn, double* input, double* output) {
    double* current_input = input;
    double* current_output = (double*)malloc(nn->layers[0].num_outputs * sizeof(double));

    for (int i = 0; i < nn->num_layers; ++i) {
        Layer* layer = &nn->layers[i];
        forward_layer(layer, current_input, current_output);
        current_input = current_output;
    }

    for (int i = 0; i < nn->layers[nn->num_layers - 1].num_outputs; ++i) {
        output[i] = current_output[i];
    }

    free(current_output);
}

void train_neural_network(NeuralNetwork* nn, double* inputs, double* outputs, int num_samples, double learning_rate, int epochs) {
    // Training implementation
}

