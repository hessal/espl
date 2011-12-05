section .text
    global write ;must be declared for linker (ld)
   ; global putStr
extern length ;length is implemented in length.c

write: ;tell linker entry point
;putStr:
       push ebp
       mov ebp, esp
  mov ecx,[EBP+12] ;message to write
mov edx ,[EBP+16]
mov ebx,[EBP+8] ;file descriptor (stdout)
mov eax,4 ;system call number (sys_write)
int 0x80 ;call kernel
pop ebp
        ret

section .data

