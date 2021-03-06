CC=gcc
CFLAGS= -std=c99 -pedantic -Wall -Wextra -Wall -g3
OBJS= src/queue.o src/stack.o src/evalexpr.o src/operations.c

all: $(OBJS) src/main.o
	$(CC) $^ -o evalexpr

evalexpr: $(OBJS) src/main.o
	$(CC) $^ -o evalexpr

check: $(OBJS) tests/tests.o
	$(CC) $^ -o evalexpr -lcriterion
	./evalexpr

clean:
	$(RM) *.o evalexpr tests/*.o src/*.o
