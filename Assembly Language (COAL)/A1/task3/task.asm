[org 0x100]

mov bx,[num1]       ;The value whoes sqr is needed , accessed from the variable
mov cx,[num1]       ;value accessed from variable for loop

cmp bx,0            ;compares the value of num1 with 0
jg L1               ;if the value is positive or grater then jump to L1
jmp EXIT            ;else exit the program

L1:
add ax,bx           ;add ax=ax+bx to find the sqr , without using direct multiplication

mov bx,[num1]       ;stores the variable value in bx again...

sub cx,1            ;decrements the loop by 1
jnz L1              ;jump if not zero

EXIT:
mov ax,0x4c00
int 21h

num1 : dw 3
