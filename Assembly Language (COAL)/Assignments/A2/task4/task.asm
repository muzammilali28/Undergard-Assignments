[org 0x0100]

mov ax,0        ; making AX equal to 0.
mov bx,0        ; making BX equal to 0.
mov cx,0        ; making CX equal to 0.
mov dx,0        ; making DX equal to 0.
mov si,0        ; making SI equal to 0.
mov di,0        ; making DI equal to 0.

jmp start       ; jump to start label.

Iterations:     ; Subroutine to calculate number of iterations it takes to get only one 1 in AX.
mov bp,sp       ; moving value of SP in BP.
push bp         ; push value of BP on top of stack.
push cx         ; push value of CX on top of stack.
l2:
mov cx,16       ; moving count of bits of AX in CX.
add bx,1        ; adding the iteration count in BX.
mov dx,0        ; moving 0 in DX to start the iteration.
l1:
shr ax,1        ; shift right AX by 1.
jnc skip        ; if carry flag bit is not 1 then jump to skip label.
add dx,1        ; otherwise add 1 in dx.
skip:
sub cx,1        ; decrement CX by 1.
jnz l1          ; if CX is not equal to 0 then jump to label l1.
mov ax,dx       ; move value of DX in AX.( DX = count of 1's in AX )
cmp dx,1        ; comparing DX with 1. 
jne l2          ; if DX is not equal to 1 then jump to label l2.
return:
pop cx          ; pop value of CX from the top of stack.
pop bp          ; pop value of BX from the top of stack. 
ret             ; return to the line number from where the subroutine was called.

start:
mov ax,1100010110100011b        ; moving 1100010110100011 in AX as a default example.
mov cx,16                       ; moving 16 in CX which is the count of bits in AX.
call Iterations                 ; calling the Iterations Subroutine.

exit:
mov ax,0x4c00                   ; Program Terminated.
int 0x21
