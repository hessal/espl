%.o: %.asm
	nasm -g -f elf -o $@ $<

%.o: %.c
	gcc -m32 -g -nostdlib -fno-stack-protector -c -o $@ $<

.PHONY: clean all

all: ahalan

ahalan: start.o main.o ahalan.o puts.o write.o
	ld -melf_i386 -g -o $@ $^

ahalan.o: ahalan.asm puts.o 
start.o: start.asm
main.o: main.c

clean:
	rm *.o ahalan
