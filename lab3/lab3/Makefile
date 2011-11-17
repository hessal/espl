 CC     = gcc
    CFLAGS = -g

all: bfix bcmp 

bcmp: bcmp.o
	$(CC) $(LDFLAGS) -o $@ $^
bfix: bfix.o 
            # Commands start with TAB not spaces
	$(CC) $(LDFLAGS) -o $@ $^



bfix.o: bfix.c diff.c
	$(CC) $(CFLAGS) -c -o $@ $<

bcmp.o: bcmp.c
	$(CC) $(CFLAGS) -c -o $@ $<
	



clean:
	rm -f bfix bcmp bfix.o bcmp.o 

    # This is GNU makefile extension to notify that roughly means: 'clean' does
    # not depend on any files in order to call it.
.PHONY: clean