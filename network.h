#ifndef NETWORK_H
#define NETWORK_H

#include "layer.h"
#include "matrix_operations.h"
#include "regularization.h"
#include "optimization.h"

// Neural network structure
typedef struct {
    int num_layers;
    Layer* layers;
} NeuralNetwork;

NeuralNetwork* init_neural_network(int num_layers, int* layer_sizes, Activation* activations);
void free_neural_network(NeuralNetwork* nn);
void forward_propagation(NeuralNetwork* nn, double* input, double* output);
void train_neural_network(NeuralNetwork* nn, double* inputs, double* outputs, int num_samples, double learning_rate, int epochs);

#endif // NETWORK_H

