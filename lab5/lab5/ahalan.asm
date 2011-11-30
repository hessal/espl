section	.text
	global ahalan
	extern puts

ahalan:					;void ahalan()
	push ebp
	mov ebp, esp
	mov edx,len
	push msg
	call puts
	add esp,4
	pop ebp
	ret

section	.data

msg	db	'ahalan!',0xa,0	;our dear string
len equ $ - msg

write:
     ret