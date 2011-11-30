section	.text
    global readFile2			;must be declared for linker (ld)
   ; global putStr
	extern length			;length is implemented in length.c
        extern readFile
readFile2:					;tell linker entry point
;putStr:
      mov	eax,3
       push ebp
       mov ebp, esp
       mov ebx,[EBP+8]	;file name
	mov ecx,buf
	mov edx, 5
	int	0x80	;call kernel
	
	pop ebp
        ret

section	.data

section .bss
   buf     resb    1024