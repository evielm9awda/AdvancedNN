#ifndef OPTIMIZATION_H
#define OPTIMIZATION_H

#include "network.h"

void gradient_descent(NeuralNetwork* nn, double* gradients, double learning_rate);
void adam_optimizer(NeuralNetwork* nn, double* gradients, double learning_rate, double beta1, double beta2, double epsilon);

#endif // OPTIMIZATION_H

