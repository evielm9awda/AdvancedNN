#include "neural_network.h"

NeuralNetwork* create_network(size_t num_layers, size_t *layer_sizes, double (**activation_funcs)(double), double (**activation_derivs)(double)) {
    NeuralNetwork *network = (NeuralNetwork*)malloc(sizeof(NeuralNetwork));
    network->num_layers = num_layers;
    network->layers = (Layer**)malloc(num_layers * sizeof(Layer*));
    for (size_t i = 0; i < num_layers; ++i) {
        network->layers[i] = (Layer*)malloc(sizeof(Layer));
        network->layers[i]->weights = random_matrix(layer_sizes[i], (i == 0) ? layer_sizes[i] : layer_sizes[i - 1]);
        network->layers[i]->biases = random_matrix(1, layer_sizes[i]);
        network->layers[i]->outputs = create_matrix(1, layer_sizes[i]);
        network->layers[i]->deltas = create_matrix(1, layer_sizes[i]);
        network->layers[i]->activation_func = activation_funcs[i];
        network->layers[i]->activation_deriv = activation_derivs[i];
    }
    return network;
}

void free_network(NeuralNetwork *network) {
    for (size_t i = 0; i < network->num_layers; ++i) {
        free_matrix(network->layers[i]->weights);
        free_matrix(network->layers[i]->biases);
        free_matrix(network->layers[i]->outputs);
        free_matrix(network->layers[i]->deltas);
        free(network->layers[i]);
    }
    free(network->layers);
    free(network);
}

void forward_propagation(NeuralNetwork *network, const Matrix *input) {
    Matrix *current_input = input;
    for (size_t i = 0; i < network->num_layers; ++i) {
        Matrix *z = matrix_multiply(current_input, network->layers[i]->weights);
        Matrix *a = matrix_add_bias(z, network->layers[i]->biases);
        free_matrix(z);
        for (size_t j = 0; j < a->cols; ++j) {
            a->data[0][j] = network->layers[i]->activation_func(a->data[0][j]);
        }
        free_matrix(current_input);
        current_input = a;
        network->layers[i]->outputs = a;
    }
}

void backward_propagation(NeuralNetwork *network, const Matrix *input, const Matrix *expected_output) {
    // Calculate deltas for the output layer
    Layer *output_layer = network->layers[network->num_layers - 1];
    for (size_t i = 0; i < output_layer->outputs->cols; ++i) {
        double output = output_layer->outputs->data[0][i];
        double expected = expected_output->data[0][i];
        output_layer->deltas->data[0][i] = (output - expected) * output_layer->activation_deriv(output);
    }

    // Propagate deltas backward
    for (size_t i = network->num_layers - 2; i >= 0; --i) {
        Layer *current_layer = network->layers[i];
        Layer *next_layer = network->layers[i + 1];
        Matrix *transposed_weights = matrix_transpose(next_layer->weights);
        Matrix *deltas = matrix_multiply(next_layer->deltas, transposed_weights);
        free_matrix(transposed_weights);
        for (size_t j = 0; j < current_layer->outputs->cols; ++j) {
            double output = current_layer->outputs->data[0][j];
            deltas->data[0][j] *= current_layer->activation_deriv(output);
        }
        current_layer->deltas = deltas;
    }
}

void update_weights(NeuralNetwork *network, double learning_rate) {
    for (size_t i = 0; i < network->num_layers; ++i) {
        Layer *layer = network->layers[i];
        for (size_t j = 0; j < layer->weights->rows; ++j) {
            for (size_t k = 0; k < layer->weights->cols; ++k) {
                layer->weights->data[j][k] -= learning_rate * layer->deltas->data[0][j] * layer->outputs->data[0][k];
            }
        }
        for (size_t j = 0; j < layer->biases->cols; ++j) {
            layer->biases->data[0][j] -= learning_rate * layer->deltas->data[0][j];
        }
    }
}

