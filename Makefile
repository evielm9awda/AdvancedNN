CC = gcc
CFLAGS = -Wall -Wextra -O2
TARGET = neural_network

SRCS = main.c activation.c layer.c network.c matrix_operations.c regularization.c optimization.c
OBJS = $(SRCS:.c=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
    $(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
    $(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)

