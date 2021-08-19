[org 0x100]

jmp start

var: db 0
temp: db 0



start:
mov ax,0
mov bx,0
mov cx,0
mov dx,0
mov si,0
mov di,0

mov ax,0xb800
mov es,ax

intake:
mov ax,0
mov ah,0
int 16h
cmp al,0x0D
jne SUM
mov ax,0
mov bx,0
mov cx,0

sep_dig:
mov al,[var]
LOP:
mov bx,10
div bx
inc cx
mov dh,0x0F
add dl,0x30
push dx
mov dx,0
cmp ax,0
jne LOP

cld
print:
pop ax
stosw
loop print
jmp exit


SUM:
mov ah,0Eh
int 10h
sub al,0x30
mov byte[temp],al
mov ax,0
mov al,[var]
mov bl,10
mul bl
add al,[temp]
mov byte[var],al
jmp intake

exit:
mov ax,0x4c00
int 21h
