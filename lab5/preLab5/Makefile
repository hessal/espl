%.o: %.asm
	nasm -g -f elf -o $@ $<

%.o: %.c
	gcc -g -O -m32 -c -o $@ $<

.PHONY: clean all

all: hello

hello: hello.o length.o
	ld -melf_i386 -g -o $@ $^

length.o: length.c

hello.o: hello.asm

clean:
	rm *.o hello
