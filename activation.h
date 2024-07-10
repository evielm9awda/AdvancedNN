#ifndef ACTIVATION_H
#define ACTIVATION_H

double sigmoid(double x);
double tanh_activation(double x);
double relu(double x);
double leaky_relu(double x);
void softmax(double* input, double* output, int length);

#endif // ACTIVATION_H

