 CC     = gcc
    CFLAGS = -g

all: runProg2

runProg2: runProg2.o
	$(CC) $(LDFLAGS) -o $@ $^


runProg2.o: runProg2.c 
	$(CC) $(CFLAGS) -c -o $@ $<


clean:
	rm -f runProg2 runProg2.o

    # This is GNU makefile extension to notify that roughly means: 'clean' does
    # not depend on any files in order to call it.
.PHONY: clean