#include "layer.h"
#include <stdlib.h>

Layer* create_layer(int num_inputs, int num_outputs, double (*activation_func)(double)) {
    Layer* layer = (Layer*)malloc(sizeof(Layer));
    layer->num_inputs = num_inputs;
    layer->num_outputs = num_outputs;
    layer->weights = (double*)malloc(num_inputs * num_outputs * sizeof(double));
    layer->biases = (double*)malloc(num_outputs * sizeof(double));
    layer->activation_func = activation_func;
    return layer;
}

void free_layer(Layer* layer) {
    free(layer->weights);
    free(layer->biases);
    free(layer);
}

