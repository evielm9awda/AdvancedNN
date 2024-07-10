CC = gcc
CFLAGS = -Wall -Wextra -O2
TARGET = neural_network

SRCS = main.c \
       layer.c \
       network.c \
       matrix_operations.c \
       regularization.c \
       optimization.c

OBJS = $(SRCS:.c=.o)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

clean:
	rm -f $(TARGET) $(OBJS)

.PHONY: clean

