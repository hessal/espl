section .text
    global openFile ;must be declared for linker (ld)
;extern length ;length is implemented in length.c
extern bcmp2       
openFile: ;tell linker entry point
      
       push ebp
       mov ebp, esp
       mov eax,5
       mov ebx,[ebp+8]
mov ecx, 0
mov edx, 0700
int 0x80 ;call kernel
mov eax, [ebp+12]
pop ebp
        ret

section .data