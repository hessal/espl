


%.o: %.asm
	nasm -g -f elf -o $@ $<
.PHONY: clean all

all: strcmp calc2

strcmp: strcmp.o hsvmhr.o
	$(CC) -m32 $(LDFLAGS) -o $@ $^
	
calc: calc2.o 
	$(CC)  $(LDFLAGS) -o $@ $^	
strcmp.o: strcmp.c 
	$(CC) -m32 $(CFLAGS) -c -o $@ $<	
	
calc2.o: calc2.c 
	$(CC)  $(CFLAGS) -c -o $@ $<	
clean:
	rm -f strcmp calc2 strcmp.o calc2.o 
