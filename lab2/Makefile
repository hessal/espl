 CC     = gcc
    CFLAGS = -g

all: canalyze

canalyze: canalyze.o 
            # Commands start with TAB not spaces
	$(CC) $(LDFLAGS) -o $@ $^

canalyze.o: canalyze.c
	$(CC) $(CFLAGS) -c -o $@ $<


clean:
	rm -f canalyze canalyze.o 

    # This is GNU makefile extension to notify that roughly means: 'clean' does
    # not depend on any files in order to call it.
.PHONY: clean