section .text
global whileLoop
extern convert
extern puts
extern check
whileLoop:
 
push 2
push 4
call puts
      push ebp
      mov ebp, esp
      mov ebx,1
      add ebx, [ebp+8]
      movzx ebx, BYTE[ebx]
      cmp bl,0
      je Done
      
      
L2:

    push ebx
    call convert
    push eax
    push DWORD[ebp+12]
    call puts;
    jmp whileLoop
      
      
Done:
mov ebx,eax
mov eax,1
int 0x80