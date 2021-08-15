[org 0x100]

mov ax,[num1]       ;move value of num1 to ax

L1:
cmp ax,-100         ;compares num1 with -100
jg L2               ;if num1 is greater than -100 then move to level 2
mov bx,[num2]       ;else move num2 to bx
mov [result],bx     ;store num2 in result variable
jmp EXIT            ;exit the program (no further calculation needed)

L2:
cmp ax,[num2]       ;compares num1 and num2
jz L3               ;if num1=num2 then jump to level 3
cmp [num2],ax       ;else if compare num2 and num1
jg L4               ;if num2 is greater then num1 then jump to level 4
mov bx,[num2]       ;else move value of num2 to bx
mov [result],bx     ;store num2 in result
jmp EXIT            ;exit the program (no futher calculation needed)

L3:
mov bx,[num2]       ;move value of num2 to bx
add ax,bx           ;add ax=ax+bx which is SUM = num1+num2
mov [result],ax     ;store the SUM in the result variable
jmp EXIT            ;exit the program (no futher calculation needed)

L4:
mov [result],ax     ;store num1 in result variable
jmp EXIT            ;exit the program

EXIT:
mov ax,0x4c00
int 21h

num1 : dw 2
num2 : dw 2
result : dw 0
