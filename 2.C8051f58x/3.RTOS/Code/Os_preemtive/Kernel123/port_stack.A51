$NOMOD51
$INCLUDE (REG51.INC)

; Bi?n khai báo external
EXTRN XDATA (user_tasks)    ; Bi?n user_tasks là SEG_XDATA
EXTRN XDATA (current_task)  ; Bi?n current_task là SEG_XDATA
EXTRN XDATA (next_stack_addr)  ; Bi?n next_stack_addr là SEG_XDATA
EXTRN XDATA (task_count)    ; Bi?n task_count là SEG_XDATA
EXTRN XDATA (G_systick)     ; Bi?n G_systick là SEG_XDATA

EXTRN XDATA (pxXRAMStack)    ; Bi?n pxXRAMStack là SEG_XDATA
EXTRN DATA (pxRAMStack)     ; Bi?n pxRAMStack là SEG_DATA
EXTRN DATA (ucStackBytes)   ; Bi?n ucStackBytes là SEG_DATA

ORG 002BH
TIMER2_ISR:
        ; Luu ng? c?nh hi?n t?i 
        PUSH    ACC
        PUSH    IE
        CLR     EA
        PUSH    DPL
        PUSH    DPH
        PUSH    B

        ; Luu R0–R7 qua d?a ch? RAM tr?c ti?p
        MOV     A, 0x02  ; R2
        PUSH    ACC
        MOV     A, 0x03  ; R3
        PUSH    ACC
        MOV     A, 0x04  ; R4
        PUSH    ACC
        MOV     A, 0x05  ; R5
        PUSH    ACC
        MOV     A, 0x06  ; R6
        PUSH    ACC
        MOV     A, 0x07  ; R7
        PUSH    ACC
        MOV     A, 0x00  ; R0
        PUSH    ACC
        MOV     A, 0x01  ; R1
        PUSH    ACC
        PUSH    PSW
        MOV PSW, #0
        
        ; T?i d?a ch? t? user_tasks[current_task].psp_value
        MOV     DPTR, #user_tasks
        MOV     A, current_task
        MOV     B, #SIZEOF_TASK_STRUCT
        MUL     AB
        ADD     A, #OFFSET_PSP
        MOV     R0, A
        MOV     DPL, @R0
        MOV     DPH, @R0+1
        MOV     DPTR, #pxXRAMStack
        MOV     A, DPL
        MOVX    @DPTR, A
        MOV     DPTR, #pxXRAMStack+1
        MOV     A, DPH
        MOVX    @DPTR, A

        MOV     A, #0
        MOV     pxRAMStack, A

        ; Tính toán s? lu?ng byte c?a stack
        MOV     A, SP
        CLR     C
        SUBB    A, #(configSTACK_START - 1)
        MOV     ucStackBytes, A

        ; Ghi kích thu?c stack vào byte d?u tiên trong XRAM
        MOV     DPTR, #pxXRAMStack
        MOV     A, ucStackBytes
        MOVX    @DPTR, A

        ; Copy t? IRAM -> XRAM
COPY_LOOP:
        MOV     A, ucStackBytes
        JZ      COPY_END

        INC     pxXRAMStack
        INC     pxRAMStack

        MOV     R0, pxRAMStack
        MOV     A, @R0
        MOV     DPTR, pxXRAMStack
        MOVX    @DPTR, A

        DEC     ucStackBytes
        SJMP    COPY_LOOP
COPY_END:

        ; Th?c hi?n chuy?n d?i task (context_switching)
        ; Copy t? XRAM -> IRAM
COPY_LOOP2:
        MOV     A, ucStackBytes
        JZ      COPY_END2

        INC     pxXRAMStack
        INC     pxRAMStack

        MOV     R0, pxXRAMStack
        MOVX    A, @R0
        MOV     R1, pxRAMStack
        MOV     @R1, A

        DEC     ucStackBytes
        SJMP    COPY_LOOP2
COPY_END2:

        ; Restore ng? c?nh task ti?p theo 
        POP     PSW
        POP     ACC     ; R1
        MOV     0x01, A
        POP     ACC     ; R0
        MOV     0x00, A
        POP     ACC     ; R7
        MOV     0x07, A
        POP     ACC     ; R6
        MOV     0x06, A
        POP     ACC     ; R5
        MOV     0x05, A
        POP     ACC     ; R4
        MOV     0x04, A
        POP     ACC     ; R3
        MOV     0x03, A
        POP     ACC     ; R2
        MOV     0x02, A

        POP     B
        POP     DPH
        POP     DPL
        POP     ACC
        JB      ACC.7, set_ea
        CLR     IE.7
        SJMP    done
set_ea:
        SETB    IE.7
done:
        POP     ACC
        RETI

END
