section .text
global convert
extern ascart
convert:
      push ebp
      mov ebp, esp
      mov eax, [ebp+8]
      sub eax,32
; mov eax,[ebp+8]

pop ebp
ret