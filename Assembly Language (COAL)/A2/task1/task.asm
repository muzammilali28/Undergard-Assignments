[org 0x0100]

mov ax,0            ; making default value of AX to zero.
mov bx,0            ; making default value of BX to zero.
mov cx,0            ; making default value of CX to zero.
mov dx,0            ; making default value of DX to zero.
mov si,0            ; making default value of SI to zero.
mov di,0            ; making default value of DI to zero.

jmp start           ; jumping to start label.

array : dw 1,3,2,5,4,7,6,8,9,0            ; declaring array of 10 numbers.
Sortoption : dw 0                         ; declaring sorting option variable.
SwapFlag : dw 0                           ; declaring flag variable for sorting subroutine.

sort:                   ; Subroutine for sorting of array.
mov bp,sp               ; moving value of SP in BP.
push bp                 ; pushing value of BP on top of Stack.
push bx                 ; pushing value of BX on top of Stack.
push cx                 ; pushing value of CX on top of Stack.
push word [Sortoption]        ; pushing value of Sortoption variable on top of Stack.
cmp word [Sortoption],1       ; checking if sorting option value is less than 1 or not.
jb return                     ; if value is less than 1 then returning from subroutine without any sorting.
cmp word [Sortoption],4       ; checking if sorting option value is greater than 4 or not.
ja return                 ; if value is greater than 4 then returning from subroutine without any sorting.
dec cx                    ; decrementing CX by 1 to loop one time less than size.
shl cx,1                  ; shifting left the count by 1 or multiplying it by 2 to make it word size for comparisons.
cmp word [Sortoption],1       ; checking if Sortoption is 1 or not.
je UAscending                 ; if Sortoption is 1 then jump to UAscending label.
cmp word[Sortoption],2        ; checking if Sortoption is 2 or not.
je UDescending                ; if Sortoption is 2 then jump to UDescending label.
cmp word[Sortoption],3        ; checking if Sortoption is 3 or not.
je SAscending                 ; if Sortoption is 3 then jump to SAscending label.
cmp word[Sortoption],4        ; checking if Sortoption is 4 or not.
je SDescending                ; if Sortoption is 4 then jump to SDescending label.
 
UAscending:             ; Label for unsigned Ascending sort.
mov si,0                ; moving 0 in SI.
mov word[SwapFlag],0    ; moving 0 in SwapFlag variable.
innerloop1:             ; innerloop1 label for a complete pass of an array swap.
mov ax,[bx+si]          ;  moving value of respective array index in AX.
cmp ax,[bx+si+2]        ; comparing value of AX with next index value.
jbe noswap1             ; if value is below or equal than the next value then jump to noswap1 label.
xchg ax,[bx+si+2]       ; otherwise swap values of AX and respective array index value.
mov [bx+si],ax          ; moving value of AX in the next index to complete swap.
mov word[SwapFlag],1    ; moving 1 in SwapFlag variable to make sure a swap happened.
noswap1:              ; label for no swapping.
add si,2              ; adding 2 in SI to obtaing next index values of array.
cmp si,cx             ; comparing SI with CX to check if count is equal or not.
jne innerloop1        ; if SI and CX are not equal then jump to innerloop1 label again.
cmp word [SwapFlag],1   ; compare SwapFlag with 1 to check if a swap happened in a complete pass or not.
je UAscending         ; if a swap happened then jump to UAscending label and make a complete pass again.
jmp return            ; otherwise jump to return label.

UDescending:            ; Label for unsigned Descending sort.
mov si,0                ; moving 0 in SI.
mov word[SwapFlag],0    ; moving 0 in SwapFlag variable.
innerloop2:             ; innerloop2 label for a complete pass of an array swap.
mov ax,[bx+si]          ; moving value of respective array index in AX.
cmp ax,[bx+si+2]        ; comparing value of AX with next index value.
jae noswap2             ; if value is above or equal than the next value then jump to noswap2 label.
xchg ax,[bx+si+2]       ; otherwise swap values of AX and respective array index value.
mov [bx+si],ax          ; moving value of AX in the next index to complete swap.
mov word[SwapFlag],1    ; moving 1 in SwapFlag variable to make sure a swap happened.
noswap2:              ; label for no swapping.
add si,2              ; adding 2 in SI to obtaing next index values of array.
cmp si,cx             ; comparing SI with CX to check if count is equal or not.
jne innerloop2        ; if SI and CX are not equal then jump to innerloop2 label again.
cmp word[SwapFlag],1    ; compare SwapFlag with 1 to check if a swap happened in a complete pass or not.
je UDescending        ; if a swap happened then jump to UDescending label and make a complete pass again.
jmp return            ; otherwise jump to return label.

SAscending:             ; Label for Signed Ascending sort.
mov si,0                ; moving 0 in SI.
mov word[SwapFlag],0    ; moving 0 in SwapFlag variable.
innerloop3:             ; innerloop3 label for a complete pass of an array swap.
mov ax,[bx+si]          ; moving value of respective array index in AX.
cmp ax,[bx+si+2]        ; comparing value of AX with next index value.
jle noswap3             ; if value is less or equal than the next value then jump to noswap3 label.
xchg ax,[bx+si+2]       ; otherwise swap values of AX and respective array index value.
mov [bx+si],ax          ; moving value of AX in the next index to complete swap.
mov word[SwapFlag],1    ; moving 1 in SwapFlag variable to make sure a swap happened.
noswap3:              ; label for no swapping.
add si,2              ; adding 2 in SI to obtaing next index values of array.
cmp si,cx             ; comparing SI with CX to check if count is equal or not.
jne innerloop3        ; if SI and CX are not equal then jump to innerloop3 label again.
cmp word[SwapFlag],1    ; compare SwapFlag with 1 to check if a swap happened in a complete pass or not.
je UAscending         ; if a swap happened then jump to UAscending label and make a complete pass again.
jmp return            ; otherwise jump to return label.

SDescending:          ; Label for Signed Descending sort.
mov si,0              ; moving 0 in SI.
mov word[SwapFlag],0  ; moving 0 in SwapFlag variable.
innerloop4:           ; innerloop3 label for a complete pass of an array swap.
mov ax,[bx+si]        ; moving value of respective array index in AX.
cmp ax,[bx+si+2]      ; comparing value of AX with next index value.
jge noswap4           ; if value is greater or equal than the next value then jump to noswap4 label.
xchg ax,[bx+si+2]     ; otherwise swap values of AX and respective array index value.
mov [bx+si],ax        ; moving value of AX in the next index to complete swap.
mov word[SwapFlag],1  ; moving 1 in SwapFlag variable to make sure a swap happened.
noswap4:            ; label for no swapping.
add si,2            ; adding 2 in SI to obtaing next index values of array.
cmp si,cx           ; comparing SI with CX to check if count is equal or not.
jne innerloop4      ; if SI and CX are not equal then jump to innerloop4 label again.
cmp word[SwapFlag],1  ; compare SwapFlag with 1 to check if a swap happened in a complete pass or not.
je SDescending      ; if a swap happened then jump to UAscending label and make a complete pass again.
jmp return          ; otherwise jump to return label.

return:                 ; label to return from subroutine.
pop word [Sortoption]   ; pop the value of Sortoption variable from top of stack.
pop cx                  ; pop the value of CX from top of stack.
pop bx                  ; pop the value of BX from top of stack.
pop bp                  ; pop the value of BP from top of stack.
ret         ; return to the line from where the subroutine was called.

start:                      ; start of program.
mov bx,array                ; moving starting address of array in BX.
mov cx,10                   ; moving count of numbers in CX.
mov word  [Sortoption],1    ; By default setting the option to option 1 ( Unsigned Ascending sort ). 
call sort                   ; Calling the Sort Subroutine.

exit:
mov ax,0x4c00               ; Program Terminated.
int 0x21
