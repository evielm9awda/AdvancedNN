#ifndef REGULARIZATION_H
#define REGULARIZATION_H

#include "network.h"

double l2_regularization(double* weights, int length, double lambda);
void apply_l2_regularization(NeuralNetwork* nn, double lambda);

#endif // REGULARIZATION_H

