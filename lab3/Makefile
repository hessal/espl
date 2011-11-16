 CC     = gcc
    CFLAGS = -g

all: bcmp

bcmp: bcmp.o 
            # Commands start with TAB not spaces
	$(CC) $(LDFLAGS) -o $@ $^

bcmp.o: bcmp.c
	$(CC) $(CFLAGS) -c -o $@ $<


clean:
	rm -f bcmp bcmp.o 

    # This is GNU makefile extension to notify that roughly means: 'clean' does
    # not depend on any files in order to call it.
.PHONY: clean