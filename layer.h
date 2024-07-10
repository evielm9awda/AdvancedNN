#ifndef LAYER_H
#define LAYER_H

#include "activation.h"

typedef struct {
    int num_inputs;
    int num_outputs;
    double* weights;
    double* biases;
    double (*activation_func)(double);
} Layer;

Layer* create_layer(int num_inputs, int num_outputs, double (*activation_func)(double));
void free_layer(Layer* layer);

#endif // LAYER_H

