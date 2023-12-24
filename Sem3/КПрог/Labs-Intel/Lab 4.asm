    .model small;   
.stack 100h;    
.data
    N dw 0h
    InputStr db 'Input string: $'
    OutputStr db 'Output string: $'
    Stg db 100h dup(0h)

.code
Start:          
    MOV AX, @data
    MOV DS, AX
    MOV AH, 9h
    MOV DX, offset InputStr
    INT 21h
    MOV AH, 1h     
    MOV SI, 0h
    MOV BX, 0h
    
Input:
    INT 21h  
    MOV CX, SI
    MOV Stg[BX], CL
    CMP AL, 32
    JNE InputNotSpace 
    MOV SI, 0h
    ADD BX, 10h
    JMP Input
   
InputNotSpace:
    INC SI
    MOV Stg[BX+SI], AL
    CMP AL, 13
    JNE Input
    MOV Stg[BX+SI], 0h
    MOV N, BX
    MOV BX, 0h      
    
SortStart:
    MOV DI, BX
    MOV AX, BX
    ADD AX, 10h

IsMax:
    MOV SI, AX
    MOV CL, Stg[DI]
    CMP CL, Stg[SI]
    ;JA NextWord  ; From long to short
    JB NextWord  ; From short to long
    MOV DI, SI

NextWord:
    ADD AX, 10h
    CMP AX, N
    JBE IsMax
    MOV SI, 0h

Swap:
    MOV CL, Stg[BX+SI]
    MOV AL, Stg[DI], CL
    MOV Stg[BX+SI], AL
    MOV Stg[DI], CL
    INC SI
    INC DI
    CMP SI, 10h
    JB Swap
    ADD BX, 10H
    CMP BX, N
    JB SortStart

MOV AH, 02h
MOV BH, 0h
MOV DH, 2h
MOV DL, 0h
INT 10h
MOV BX, 0h
MOV SI, 0h
MOV AH, 9h
MOV DX, offset OutputStr
INT 21h
MOV AH, 2h
    

Output:
    INC SI
    MOV DX, word ptr Stg[BX+SI]
    CMP DX, 0h
    JNE OutS
    CMP BX,N
    JE EXIT
    MOV SI, 0h
    ADD BX,10h
    MOV DX, ' '

OutS:
    INT 21h
    CMP BX, N
    JBE Output
    
EXIT:
    MOV AH, 4Ch
    INT 21h
    