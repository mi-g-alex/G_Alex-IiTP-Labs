.model small
.stack 100h
.data 
    InputFirstStr db 'Input first numnber from 0 to FFFF: $'
    InputSecondStr db 'Input second number from 0 to FFFF: $' 
    InputError db 'Input error$'
    OutPutAND db 'OutPut -- 1 AND 2: $'
    OutPutOR db 'OutPut -- 1 OR 2: $'
    OutPutXOR db 'OutPut -- 1 XOR 2: $'
    OutPutNOT1 db 'OutPut -- NOT 1: $'
    OutPutNOT2 db 'OutPut -- NOT 2: $'
    A dw 0000h
    B dw 0000h    
.code
    
    MOV AX, @data
    MOV DS, AX
Start:    
    MOV AH, 9h
    MOV DX, offset InputFirstStr
    INT 21h
    MOV SI, 0h
    JMP InputFirst   
    
InputFirstWrong:
    CALL NewLine
    MOV AH, 9h
    MOV DX, offset InputError
    INT 21h
    CALL NewLine
    MOV AH, 9h
    MOV DX, offset InputFirstStr
    INT 21h
    MOV A, 0000h
    MOV SI, 0h
    
InputFirst:
    MOV AH, 1h
    INT 21h
    CMP AL, 13
    JE InputFirstNewLineCheck
    MOV DL, AL
    CALL Convert10ToHex
    JC InputFirstWrong 
    INC SI
    MOV BX, A
    MOV AX, 0010h
    MOV CL, DL
    IMUL BX
    MOV BX, AX
    ADD BL, CL
    MOV A, BX
    JMP InputFirst   

InputFirstNewLineCheck:
    CMP SI, 4
    JG InputFirstWrong
    CALL NewLine
    MOV AH, 9h
    MOV DX, offset InputSecondStr
    INT 21h
    MOV SI, 0h
    MOV AX, 0h
    MOV BX, 0h
    MOV DX, 0h
    JMP InputSecond
    
InputSecondWrong:
    CALL NewLine
    MOV AH, 9h
    MOV DX, offset InputError
    INT 21h
    CALL NewLine
    MOV AH, 9h
    MOV DX, offset InputSecondStr
    INT 21h
    MOV B, 0000h
    MOV SI, 0h
    
InputSecond:
    MOV AH, 1h
    INT 21h
    CMP AL, 13
    JE InputSecondNewLineCheck
    MOV DL, AL
    CALL Convert10ToHex
    JC InputSecondWrong 
    INC SI
    MOV BX, B
    MOV AX, 0010h
    MOV CL, DL
    IMUL BX
    MOV BX, AX
    ADD BL, CL
    MOV B, BX
    JMP InputSecond   

InputSecondNewLineCheck:
    CMP SI, 4
    JG InputSecondWrong
    
MakeAnd:
    CALL NewLine
    MOV AH, 9h
    MOV DX, offset OutPutAND
    INT 21h
    MOV AX, A
    MOV BX, B
    AND AX, BX
    MOV CX, AX
    CALL PrintAX
    
MakeOr:
    CALL NewLine
    MOV AH, 9h
    MOV DX, offset OutPutOR
    INT 21h
    MOV AX, A
    MOV BX, B
    OR AX, BX
    MOV CX, AX
    CALL PrintAX

MakeXor:
    CALL NewLine
    MOV AH, 9h
    MOV DX, offset OutPutXOR
    INT 21h
    MOV AX, A
    MOV BX, B
    XOR AX, BX
    MOV CX, AX
    CALL PrintAX
    
MakeNot1:
    MOV AH, 2h
    MOV DL, 13
    INT 21h
    MOV DL, 10
    INT 21h
    MOV AH, 9h
    MOV DX, offset OutPutNOT1
    INT 21h
    MOV AX, A
    NOT AX
    MOV CX, AX
    CALL PrintAX    

MakeNot2:
    CALL NewLine
    MOV AH, 9h
    MOV DX, offset OutPutNOT2
    INT 21h
    MOV AX, B
    NOT AX
    MOV CX, AX
    CALL PrintAX
    JMP END               
    
PrintAX PROC
    MOV DX, CX
    SHR DX, 12
    CALL ConvertHex10ToChar
    MOV DX, CX
    SHL DX, 4
    SHR DX, 12
    CALL ConvertHex10ToChar
    MOV DX, CX
    SHL DX, 8
    SHR DX, 12
    CALL ConvertHex10ToChar
    MOV DX, CX
    SHL DX, 12
    SHR DX, 12
    CALL ConvertHex10ToChar
    RET
        

Convert10ToHex PROC
    CMP DL,'0'
    JL ConvError
    CMP DL,'9'
    JG ConvertAFToHex
    SUB DL,'0'
    RET
 
ConvertAFToHex:
    AND DL,11011111b
    CMP DL,'A'
    JL ConvError
    CMP DL,'F'
    JG ConvError            
    SUB DL,'A'-10           
    RET                     
 
ConvError:
    MOV DL, 0h
    STC
    RET  

ConvertHex10ToChar PROC
    CMP DL, 9      
    JG ConvertHexAFToChar
    ADD DL, '0'
    MOV AH, 02h
    INT 21h
    RET
    
ConvertHexAFToChar:
    ADD DL, 'A'-10
    MOV AH, 02h
    INT 21h
    RET
    
NewLine PROC
    MOV AH, 2h
    MOV DL, 13
    INT 21h
    MOV DL, 10
    INT 21h
    RET    
    
END:
    CALL NewLine
    CALL NewLine
    MOV AX, 0h
    MOV BX, 0h
    MOV A, 0h
    MOV B, 0h
    MOV SI, 0h
    JMP Start