#ifndef NETWORK_H
#define NETWORK_H

#include "layer.h"

typedef struct {
    int num_layers;
    Layer* layers;
} NeuralNetwork;

NeuralNetwork* create_network(int num_layers);
void add_layer(NeuralNetwork* nn, Layer* layer, int layer_index);
void free_network(NeuralNetwork* nn);

#endif // NETWORK_H

