#include "network.h"
#include "matrix_operations.h"
#include "regularization.h"
#include "optimization.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Create a neural network with 3 layers
    NeuralNetwork* nn = create_network(3);

    // Create and add layers
    Layer* input_layer = create_layer(3, 5, relu);
    Layer* hidden_layer = create_layer(5, 4, tanh_activation);
    Layer* output_layer = create_layer(4, 2, softmax);

    add_layer(nn, input_layer, 0);
    add_layer(nn, hidden_layer, 1);
    add_layer(nn, output_layer, 2);

    // Print a message
    printf("Neural network created with 3 layers.\n");

    // Clean up
    free_network(nn);

    return 0;
}

