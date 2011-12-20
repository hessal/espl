%.o: %.asm
	nasm -g -f elf -o $@ $<

%.o: %.c
	gcc -m32 -g -nostdlib -fno-stack-protector -c -o $@ $<

.PHONY: clean all

all: asmart

asmart: asmart.o puts.o font.o write.o convert.o whileLoop.o
	ld -melf_i386 -g -o $@ $^

asmart.o: asmart.asm
# check.o: check.c
puts.o: puts.c
whileLoop.o: whileLoop.asm
write.o: write.asm
convert.o: convert.asm

clean:
	rm *.o ascart

