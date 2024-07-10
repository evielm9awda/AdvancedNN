# AdvancedNN

## Description

AdvancedMathNN is a sophisticated neural network library in C leveraging advanced mathematics and machine learning techniques. This library is designed to provide powerful and efficient implementations of neural networks with support for various activation functions, regularization methods, and optimization algorithms.

## Features

- Multiple activation functions: Sigmoid, Tanh, ReLU, Leaky ReLU, Softmax
- Support for L2 regularization
- Optimization algorithms: Gradient Descent, Adam
- Modular design with separate headers for activations, layers, network, matrix operations, regularization, and optimization

## File Structure

- `activation.h`: Advanced activation functions
- `layer.h`: Layer structure and initialization
- `network.h`: NeuralNetwork structure and forward propagation
- `matrix_operations.h`: Matrix operations for computations
- `regularization.h`: L2 regularization functions
- `optimization.h`: Gradient descent and Adam optimizer
- `main.c`: Demonstration of neural network usage
- `layer.c`: Layer initialization and forward propagation
- `network.c`: Neural network initialization and propagation logic
- `matrix_operations.c`: Matrix multiplication, addition, and vector operations
- `regularization.c`: L2 regularization implementation
- `optimization.c`: Gradient descent and Adam optimization

## Usage

To compile the program, use the provided Makefile:

```sh
make
