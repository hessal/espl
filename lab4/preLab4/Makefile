%.o: %.asm
	nasm -g -f elf -o $@ $<

.PHONY: clean all

all: hello

hello: hello.o
	ld -melf_i386 -g -o $@ $^

clean:
	rm *.o hello
