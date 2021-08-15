[org 0x100]

mov ax,0          ;first value in series Zero
mov bx,[num1]     ;second value in series 1

mov cx,[lop]      ;loop starts with desired value
sub cx,2          ;loop minus 2 due to 2 values already considered  0 , 1

l1:
add ax,bx         ;loop starts and SUM ax=ax+bx

mov bx,[num1]     ;bx stores the last value available in the DW variable
mov [num1],ax     ;replace the variable value with the new SUM

sub cx,1          ;decrement the loop by 1
jnz l1            ;jump if not zero

mov ax,0x4c00
int 21h

num1 : dw 1
lop : dw 10
