#ifndef LAYER_H
#define LAYER_H

#include "activation.h"

// Neural network layer structure
typedef struct {
    int num_inputs;
    int num_outputs;
    double* weights;
    double* biases;
    Activation activation;
    double* output_cache;
    double* input_cache;
} Layer;

Layer* init_layer(int num_inputs, int num_outputs, Activation activation);
void free_layer(Layer* layer);
void forward_layer(Layer* layer, double* input, double* output);

#endif // LAYER_H

