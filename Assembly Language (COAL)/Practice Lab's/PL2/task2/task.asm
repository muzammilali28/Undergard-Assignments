[org 0x100]

jmp start

arr: dw 0xABCD, 0xBCDE, 0xCDEF, 0x1234, 0x5678, 0x9ABC, 0x1478, 0x12AB, 0xA12D, 0x1122
result: dw 0
size_arr: dw 10

	ARR_MOV:
	push bp
	mov bp,sp

	mov bx,[bp+6]
	
	mov cx,[bp+4]
	sub cx,1
	shl cx,1
	add cx,2

	LOOPING:
	mov ax,[bx+si]
	shl al,4
	shr al,4
	mov dl,al
	mov dh,0
	add word[result],dx
	shl ah,4
	shr ah,4
	mov dl,ah
	mov dh,0
	add word[result],dx
	add si,2
	cmp si,cx
	jne LOOPING
	pop bp
	ret 4

start:
mov ax,arr
push ax
mov ax,[size_arr]
push ax
mov ax,0
call ARR_MOV

exit:
mov ax,0x4c00
int 21h
