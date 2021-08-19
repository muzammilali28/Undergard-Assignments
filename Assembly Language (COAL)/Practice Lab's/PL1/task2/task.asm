[org 0x100]

jmp START

num: dw 0xABCD

	INVERT:
	push bp
	mov bp,sp
	push ax
	
	mov ax,[bp+4]
	
	xor ax,1010101010101010b

	pop ax
	pop bp
	
	ret 2
	
START:
mov ax,[num]
push ax
mov ax,0
call INVERT

EXIT:
mov ax,0x4c00
int 21h
