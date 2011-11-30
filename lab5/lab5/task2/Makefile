%.o: %.asm
	nasm -g -f elf -o $@ $<
.PHONY: clean all

all: bcmp2

bcmp2: bcmp2.o openFile.o write.o readFile2.o
	$(CC) -m32 $(LDFLAGS) -o $@ $^
	

bcmp2.o: bcmp2.c write.o readFile2.o
	$(CC) -m32 $(CFLAGS) -c -o $@ $<	
	

clean:
	rm -f bcmp2
