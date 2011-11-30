section	.text
    global openFile			;must be declared for linker (ld)
   ; global putStr
	extern length			;length is implemented in length.c
        extern readFile
openFile:					;tell linker entry point
;putStr:
      mov	eax,5
       push ebp
       mov ebp, esp
       mov ebx,[EBP+8]	;file name
	mov ecx, 0
	mov edx, 0700
	int	0x80	;call kernel
	
	pop ebp
        ret

section	.data