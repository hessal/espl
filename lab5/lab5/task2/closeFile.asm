section .text
    global closeFile ;must be declared for linker (ld)
;extern length ;length is implemented in length.c
extern bcmp2       
closeFile: ;tell linker entry point
      
       push ebp
       mov ebp, esp
       mov eax,6
       mov ebx,[ebp+8]

int 0x80 ;call kernel
;mov eax, 3
pop ebp
        ret

section .data