section .text
    global readFile2 ;must be declared for linker (ld)
        extern bcmp2
readFile2: ;tell linker entry point
       push ebp
       mov ebp, esp
       
       mov eax, 3
       
       mov ebx,[ebp+8] 
       mov ecx,[ebp+12]
       mov edx, [ebp+16]
       int 0x80 ;call kernel
       ;mov eax,ecx
	;movzx ecx,al
        mov eax,[ecx]
	pop ebp
        ret

section .data

    