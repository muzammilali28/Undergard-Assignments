[org 0x100]

jmp start

dividend: db 18
divisor: db 4
quotient: db 0
remainder: db 0

	clrScr:
	push bp
	mov bp,sp
	push ax
	push cx
	push di
	mov ax, 0xb800
	mov es, ax
	mov ax, 0x0720
	mov cx, 2000
	cld
	mov di,0
	rep stosw
	pop di
	pop cx
	pop ax
	pop bp
	ret

	repeatedSub:
	push bp 
	mov bp,sp
	push ax
	push bx
	
	mov ax,[bp+6]
	mov bx,[bp+4]
	
	Subtraction:
	sub al,bl
	add byte[quotient],1
	cmp al,bl
	jae Subtraction
	mov byte[remainder],al
	
	pop bx
	pop ax
	pop bp
	ret 4
	
	
	Print:
	push bp
	mov bp,sp
	push es
	push ax
	push di
	
	mov ax,0xb800
	mov es,ax
	
	mov ax,[bp+10]
	mov bl,80
	mul bl
	add ax,[bp+8]
	shl ax,1
	
	mov di,ax
	mov ax,0
	cld
	mov ax,[bp+6]
	mov ah,0x0F
	stosw
	mov ax,[bp+4]
	mov ah,0x0F
	stosw
	
	pop di
	pop ax
	pop es
	pop bp
	ret 8



start:
mov ax,0
mov bx,0
mov cx,0
mov dx,0
mov si,0
mov di,0

call clrScr
mov ax,0
mov al,[dividend]
push ax
mov al,[divisor]
push ax
mov ax,0
call repeatedSub
mov ax,12
push ax
mov ax,39
push ax
mov ax,0
mov al,[quotient]
add al,0x30
push ax
mov al,[remainder]
add al,0x30
push ax
call Print

exit:
mov ax,0x4c00
int 21h
