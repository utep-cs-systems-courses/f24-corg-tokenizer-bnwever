# Makefile for the history and tokenizer project

# Compiler
CC = gcc
# Compiler flags
CFLAGS = -g -O3

# Define Source files
SRC = uimain.c history.c tokenizer.c
# TURN SOURCE FILES INTO EXECUTABLES
OBJS = $(SRC:.c=.o)

# Executable name
all: tokenizer

# Rule to create the tokenizer executable
tokenizer: $(OBJS)
	$(CC) -o $@ $(CFLAGS) $(OBJS)

# Rule to create object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files and executable
clean:
	rm -f *.o tokenizer

# Run the program
run: tokenizer
	./tokenizer