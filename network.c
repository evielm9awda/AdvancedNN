#include "network.h"
#include <stdlib.h>

NeuralNetwork* create_network(int num_layers) {
    NeuralNetwork* nn = (NeuralNetwork*)malloc(sizeof(NeuralNetwork));
    nn->num_layers = num_layers;
    nn->layers = (Layer*)malloc(num_layers * sizeof(Layer));
    return nn;
}

void add_layer(NeuralNetwork* nn, Layer* layer, int layer_index) {
    if (layer_index < nn->num_layers) {
        nn->layers[layer_index] = *layer;
    }
}

void free_network(NeuralNetwork* nn) {
    for (int i = 0; i < nn->num_layers; ++i) {
        free_layer(&nn->layers[i]);
    }
    free(nn->layers);
    free(nn);
}

