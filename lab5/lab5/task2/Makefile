
CC = gcc
    CFLAGS = -g

%.o: %.asm
	nasm -g -f elf -o $@ $<
.PHONY: clean all

all: bcmp2

bcmp2: bcmp2.o write.o openFile.o readFile2.o closeFile.o
	$(CC) -m32 $(LDFLAGS) -o $@ $^

bcmp2.o: bcmp2.c write.o readFile2.o openFile.o closeFile.o
	$(CC) -m32 $(CFLAGS) -c -o $@ $<


clean:
	rm -f bcmp2 bcmp2.o

