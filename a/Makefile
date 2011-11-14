 CC     = gcc
    CFLAGS = -g

all: complines2

complines: complines2.o 
            # Commands start with TAB not spaces
	$(CC) $(LDFLAGS) -o $@ $^

complines2.o: complines2.c
	$(CC) $(CFLAGS) -c -o $@ $<


clean:
	rm -f complines2 complines2.o 

    # This is GNU makefile extension to notify that roughly means: 'clean' does
    # not depend on any files in order to call it.
.PHONY: clean