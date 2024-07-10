#include <stdio.h>
#include <stdlib.h>
#include "network.h"

int main() {
    int layer_sizes[] = {3, 5, 2};
    Activation activations[] = {RELU, SOFTMAX};

    NeuralNetwork* nn = init_neural_network(2, layer_sizes, activations);

    double input[] = {1.0, 0.5, -1.0};
    double output[2];

    forward_propagation(nn, input, output);

    printf("Output: %f %f\n", output[0], output[1]);

    free_neural_network(nn);
    return 0;
}

