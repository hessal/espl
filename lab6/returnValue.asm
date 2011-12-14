section	.text
    global returnValue			;must be declared for linker (ld)
   
			

returnValue:					;tell linker entry point

       push ebp
       mov ebp, esp
       mov eax, [ebp+8]
 	sub eax,32
	pop ebp
        ret

section	.data

