section .text
global _start

extern main
_start:

mov eax, esp
add eax,4
push eax
push DWORD [esp+4]
call main
mov ebx,eax
mov eax,1
int 0x80

