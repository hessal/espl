 CC = gcc
    CFLAGS = -g

all: runprog2

runprog2: runprog2.o
# Commands start with TAB not spaces
	$(CC) $(LDFLAGS) -o $@ $^

runprog2.o: runprog2.c
	$(CC) $(CFLAGS) -c -o $@ $<


clean:
	rm -f runprog2 runprog2.o

# This is GNU makefile extension to notify that roughly means: 'clean' does
# not depend on any files in order to call it.
.PHONY: clean