.286
.model small 
.stack 100h
.code 
Start:
    MOV AX, @data
    MOV DS, AX 
    
FindFilePath:
    MOV AH, 9h
    MOV DX, offset InputFilePathStr
    INT 21h  
    MOV AH, 0Ah   
    MOV PathToFile[SI], 0FFh
    MOV DX, offset LengthOfBuffer
    INT 21h
    MOV SI, 0h
    
FindDollar:
    CMP PathToFile[SI], 13
    JE Set0
    INC SI
    JMP FindDollar
    
Set0:
    MOV PathToFile[SI], 0h  
    
OpenFileTest:
    MOV DX, offset PathToFile
    MOV AH, 3Dh
    MOV AL, 00h
    INT 21h
    JC BadFile
    JMP StartInput

InputError:
    CALL NewLine
    MOV AH, 9h
    MOV DX, offset InputErrorStr
    INT 21h
    CALL NewLine
    
StartInput:
    CALL NewLine
    MOV AH, 9h
    MOV DX, offset InputNumberOfRow
    INT 21h
    MOV LineNmb, 0h

InputSimble:
    MOV AH, 1h
    INT 21h
    CMP AL, 13
    JE CheckInput
    CMP AL, 32
    JE InputSimble
    CMP AL, 9
    JE InputSimble
    MOV DL, AL
    CALL FromCharTo10
    MOV BX, LineNmb
    MOV AX, 000Ah
    MOV CL, DL
    MOV DX, 0
    MUL BX
    MOV BX, AX
    JO InputError
    MOV CH, 0
    ADD BX, CX
    CMP BX, LineNmb
    JB InputError 
    MOV LineNmb, BX
    JMP InputSimble

CheckInput:
    JO InputError
    MOV BX, LineNmb
    
    
CheckAfterInput:
    CMP BX, 0
    JE InputError
    CMP BX, 255
    JA InputError
    CMP BX, 01h
    JE ITISFIRST
    JMP OpenFile

ITISFIRST:
    MOV FoundLine, 1h
         
    
OpenFile:
    CMP LineNmb, 0
    MOV Cnt, 01h
    JE InputError
    MOV DX, offset PathToFile
    MOV AH, 3Dh
    MOV AL, 00h
    INT 21h
    JC BadFile
    MOV BX, AX 
    MOV DI, 01
    MOV SI, 17
    
ReadFile:
    MOV CX, 017
    MOV DX, offset Stg
    MOV AH, 3Fh
    INT 21h 
    PUSH SI
    MOV SI, AX
    MOV Stg[SI], 0h
    POP SI
    CMP AX, 0h
    JE END
    SUB SI, 17
    CMP FoundLine, 1h
    JE StartReadingLine

CountNmbOfN:
    CMP STG[SI], 13
    JE ItIsNewLine
    INC SI
    CMP SI, 17
    JE ReadFile
    JMP CountNmbOfN
    
ItIsNewLine:
    INC SI
    INC SI
    INC Cnt
    PUSH CX
    MOV CX, Cnt   
    CMP CX, LineNmb
    JE EndOfSearch
    CMP SI, 016
    JA GoToReadFile
    POP CX
    JMP CountNmbOfN   

GoToReadFile:  
    POP CX    
    JMP ReadFile
                
EndOfSearch:
    Mov FoundLine, 1h
    POP CX     
             
StartReadingLine:  
    CMP Stg[SI], 13
    JE END
    CMP SI, 016
    JA GoToReadFile
    PUSH SI
    PUSH BX
    MOV BH, Stg[SI] 
    MOV SI, Cursor
    MOV PathToProgram[SI], BH
    POP BX
    POP SI  
    INC SI
    INC Cursor
    JMP StartReadingLine
    
             
JMP END   
    


BadFile:
    CALL NewLine
    MOV AH, 9h
    MOV DX, offset BadFileStr
    INT 21h
    JMP END 
    
FromCharTo10 PROC
    CMP DL, '0'
    JL InputError
    CMP DL, '9'
    JG InputError
    SUB DL, '0'
    RET

NewLine PROC
    MOV AH, 2h
    MOV DL, 13
    INT 21h
    MOV DL, 10
    INT 21h
    RET    
    
END:    
    MOV AH, 4CH
    MOV AL, 00
    INT 21H

DATA SEGMENT 
    InputErrorStr db 'Input error $'                                 
    InputFilePathStr db 'Input file path: $'          
    InputNumberOfRow db 'Input number of row (start from 1): $'
    BadFileStr db 'Bad path. Cant find file', 13, 10, '$'
    FoundLine db 0h
    Cursor dw 0h
    Cnt dw 01h
    LineNmb dw 0h
    LengthOfBuffer dw 0FFh
    PathToFile db 0FFh dup (0h)
    Stg db 0FFh dup (0h)  
    PathToProgram 0FFh dup (0h)
    
ENDS    
                                                   
                                               
