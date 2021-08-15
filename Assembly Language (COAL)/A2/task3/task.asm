[org 0x0100]

mov ax,0        ; making default value of AX to zero.
mov bx,0        ; making default value of BX to zero.
mov cx,0        ; making default value of CX to zero.
mov dx,0        ; making default value of DX to zero.
mov si,0        ; making default value of SI to zero.
mov di,0        ; making default value of DI to zero.

jmp start       ; jump to start label.

buffer : db 4,76,1,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,90,145,2       ; declaring buffer of size 32 bytes.
startingBit : db 0                                                                                        ; declaring starting bit variable of byte size.

CopyByte:         ; Subroutine to copy value in AX.
mov bp,sp         ; moving value of SP in BP.
push bp           ; push value of BP on top of stack.
push bx           ; push value of BX on top of stack.
push cx           ; push value of CX on top of stack.
cmp byte [startingBit],255      ; comparing/checking if starting bit is greater than 255.
ja return                     ; if starting bit is greater than 255 jump to return label.
cmp byte [startingBit],0        ; comparing/checking if starting bit is less or equal than 0.
jbe return                    ; if starting bit is less or equal than 0 jump to return label.
mov si,cx                   ; moving value of CX in SI.
cmp byte [startingBit],8      ; Comparing the starting bit with 1 byte size which is 8 bits.
jb l2                       ; if starting bit is less than 8 then jump to label l2.
mov cl,[startingBit]        ; move starting bit value in CL.
l1:
add dx,1            ; adding 1 in DX,
sub cx,8            ; Subtracting 8 from CX.
cmp cx,8            ; Comparing value of CX with 8.
jae l1              ; if value of CX is above or equal to 8 then jump to label l1.
jmp l3              ; jump to label l3.
l2:
mov si,30           ; move 30 in SI to access last 2 bytes of buffer.
jmp l4              ; jump to label l4.
l3:
add dx,2            ; adding 2 in DX.
sub si,dx           ; subtracting the value of DX from the value of SI.
sub dx,2            ; subtracting DX by 2.
l4:
mov cx,dx           ; move value of DX in CX.
mov dx,0            ; move 0 in DX.
cmp cx,0            ; compare value of CX with 0.
je skip             ; if CX is equal to 0 jump to skip label.
sum:
add dx,8            ; add 8 in DX.
sub cx,1            ; subtract CX by 1.
jnz sum             ; if CX is not equal to 0 then jump to sum label.
skip:
mov ax,[bx+si]          ; move the respective buffer index values in AX. 
mov cl,[startingBit]    ; move the starting bit value in CL.
sub cx,dx               ; subtract the value of DX from CX.
rol ax,8        ; rotate left AX 8 times to swap AL and AH.
ror ax,cl       ; rotate right AX by CL value times.
and ah,0x00     ; making the bits of AH equal to 0.
return:
pop cx      ; pop the value of CX from top of stack.
pop bx      ; pop the value of BX from top of stack.
pop bp      ; pop the value of BP from top of stack.
ret         ; return to the line number from where the subroutine was called.
 
start:                        ; start of program.
mov byte [startingBit],6      ; setting the default value of starting bit to 6 as an example.
mov bx,buffer                 ; moving the address of first index of buffer into BX.
mov cx,32                     ; moving the size of buffer into CX which is 32 bytes.
call CopyByte                 ; calling the CopyByte subroutine.

exit:
mov ax,0x4c00                 ; Program Terminated. 
int 0x21
