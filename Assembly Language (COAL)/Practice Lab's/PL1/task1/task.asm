[org 0x100]

jmp START

num: dw 0xABCD

	CHECK_PAIR:
	push bp
	mov bp,sp
	push ax
	push bx
	push cx
	
	mov ax,[bp+4]
	
	LOOPING:
	shr ax,1
	jnc next_itration
	add cx,1
	cmp cx,16
	jnz LOOPING
	
	pop cx
	pop bx
	pop ax
	pop bp
	ret 2
	
	next_itration:
	add cx,1
	shr ax,1
	jc COUNT
	cmp cx,16
	jnz next_itration	
	
	pop cx
	pop bx
	pop ax
	pop bp
	ret 2
	
	COUNT:
	add bx,1
	add cx,1
	cmp cx,16
	jnz LOOPING
	
	pop cx
	pop bx
	pop ax
	pop bp
	ret 2
	
	
START:
mov ax,[num]
push ax
mov ax,0
mov bx,0
mov cx,0
call CHECK_PAIR

EXIT:
mov ax,0x4c00
int 21h
