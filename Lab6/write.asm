section .text
global write
extern puts
write:
      push ebp
      mov ebp, esp
mov ebx,[ebp+8] ;stdout
mov edx,[ebp+16] ;length
mov ecx,[ebp+12] ;String

mov eax,4 ;sys_write
int 0x80
pop ebp
ret 