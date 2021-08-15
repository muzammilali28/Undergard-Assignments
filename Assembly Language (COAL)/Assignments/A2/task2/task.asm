[org 0x0100]

mov ax,0      ; making default value of AX to zero.
mov bx,0      ; making default value of BX to zero.
mov cx,0      ; making default value of CX to zero.
mov dx,0      ; making default value of DX to zero.
mov si,0      ; making default value of SI to zero.
mov di,0      ; making default value of DI to zero.

jmp start     ; jump to start label.

SwapNibble:       ; subroutine to swap the nibbles in each byte of AX register. 
mov bp,sp         ; moving value of sp in bp.
push bp           ; push value of bp on top of stack.
ror ah,4          ; rotating right ( we can use rotate left as well ) the value of AH by 4 times. 
rol al,4          ; rotating left ( we can use rotate right as well ) the value of AL by 4 times.
pop bp            ; pop value of BP fro top of stack.
ret               ; return to line number from where the subroutine was called.

start:       ; start of program.

mov ax,0xABCD     ; moving ABCD in AX register as an example.
call SwapNibble   ; calling the SwapNibble subroutine to swap the nibbles in each byte of AX register.

exit:
mov ax,0x4c00     ; Program Terminated.
int 0x21
