 CC = gcc-4.4
    CFLAGS = -g

all: prsym ascart

ascart: ascart.o font.o
# Commands start with TAB not spaces
	$(CC) $(LDFLAGS) -o $@ $^

prsym: prsym.o font.o
# Commands start with TAB not spaces
	$(CC) $(LDFLAGS) -o $@ $^

ascart.o: ascart.c
	$(CC) $(CFLAGS) -c -o $@ $<

prsym.o: prsym.c
	$(CC) $(CFLAGS) -c -o $@ $<

font.o: font.c font.h
	$(CC) $(CFLAGS) -c -o $@ $<


clean:
	rm -f prsym ascart prsym.o ascart.o font.o

# This is GNU makefile extension to notify that roughly means: 'clean' does
# not depend on any files in order to call it.
.PHONY: clean