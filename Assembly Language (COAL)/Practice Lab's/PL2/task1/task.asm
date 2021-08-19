[org 0x100]

jmp START

NUM: dd 0x012ABCD45
result : dw 0
	
	START:
	mov ax,[NUM]
	xor al,0xBC
	jz COUNT_UPDATE
	xor ah,0xBC
	jz COUNT_UPDATE
	
	mov ax,[NUM+2]
	xor al,0xBC
	jz COUNT_UPDATE
	xor ah,0xBC
	jz COUNT_UPDATE
	
	mov word[result],0
	jmp EXIT
	
	
	COUNT_UPDATE:
	mov word[result],1

EXIT:
mov ax,0x4c00
int 21h
