section	.text
    global returnStrlen			
         
returnStrlen:
push ebp
mov ebp, esp
mov eax, -1
.L2:
add eax, 1
mov ebx, eax
add ebx, [ebp+8]
movzx ebx, BYTE [ebx]
test bl, bl
jne .L2
pop ebp
ret