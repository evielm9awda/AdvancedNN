#include "layer.h"
#include <stdlib.h>

Layer* init_layer(int num_inputs, int num_outputs, Activation activation) {
    Layer* layer = (Layer*)malloc(sizeof(Layer));
    layer->num_inputs = num_inputs;
    layer->num_outputs = num_outputs;
    layer->weights = (double*)malloc(num_inputs * num_outputs * sizeof(double));
    layer->biases = (double*)malloc(num_outputs * sizeof(double));
    layer->activation = activation;
    layer->output_cache = (double*)malloc(num_outputs * sizeof(double));
    layer->input_cache = (double*)malloc(num_inputs * sizeof(double));

    for (int i = 0; i < num_inputs * num_outputs; ++i) {
        layer->weights[i] = (double)rand() / RAND_MAX * 2.0 - 1.0;
    }
    for (int i = 0; i < num_outputs; ++i) {
        layer->biases[i] = (double)rand() / RAND_MAX * 2.0 - 1.0;
    }

    return layer;
}

void free_layer(Layer* layer) {
    free(layer->weights);
    free(layer->biases);
    free(layer->output_cache);
    free(layer->input_cache);
    free(layer);
}

void forward_layer(Layer* layer, double* input, double* output) {
    // Implementation
}

