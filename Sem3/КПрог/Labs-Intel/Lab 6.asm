.model small
.stack 100h
.code
Start:
    MOV AX, @data
    MOV DS, AX
    MOV BX, 0080h
    MOV CX, ES:BX
    CMP CX, 0D00h
    JE END
    MOV BX, 0082h
    MOV SI, 0h
    
FindFilePath:
    MOV AH, 9h
    MOV DX, offset InputFilePath
    INT 21h  
    MOV AH, 0Ah   
    MOV PathToFile[SI], 0FFh
    MOV DX, offset Length
    INT 21h
    MOV SI, 0h
    
FindDollar:
    CMP PathToFile[SI], 13
    JE Fun1
    INC SI
    JMP FindDollar
    
Fun1:
    MOV PathToFile[SI], 0h
    
    
Check1:
    DEC SI
    CMP PathToFile[SI], 't'
    JE Check2 
    JMP BadFileFormat
    
Check2:
    DEC SI
    CMP PathToFile[SI], 'x'
    JE Check3
    JMP BadFileFormat    
    
Check3:
    DEC SI
    CMP PathToFile[SI], 't'
    JE Check4
    JMP BadFileFormat    
    
Check4:
    DEC SI
    CMP PathToFile[SI], '.'
    JE OpenFileTest
    JMP BadFileFormat    
            
    
OpenFileTest:
    CMP CmpLength, 0h
    MOV Cnt, 0h
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
    MOV DX, offset InputStr
    INT 21h
    MOV CmpLength, 0h

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
    MOV BX, CmpLength
    MOV AX, 000Ah
    MOV CL, DL
    MOV DX, 0
    MUL BX
    MOV BX, AX
    JO InputError
    MOV CH, 0
    ADD BX, CX
    CMP BX, CmpLength
    JB InputError 
    MOV CmpLength, BX
    JMP InputSimble

CheckInput:
    JO InputError
    MOV BX, CmpLength
       
OpenFile:
    CMP CmpLength, 0h
    MOV Cnt, 0h
    JE InputError
    MOV DX, offset PathToFile
    MOV AH, 3Dh
    MOV AL, 00h
    INT 21h
    JC BadFile
    MOV BX, AX 
    MOV DI, 01
    MOV SI, 17
    
ReadAllFile:
    MOV CX, 017
    MOV DX, offset Stg
    MOV AH, 3Fh
    INT 21h 
    PUSH SI
    MOV SI, AX
    MOV Stg[SI], 0h
    POP SI
    CMP AX, 0h
    JE EndOfSearch
    SUB SI, 17
        
CountNmbOfn:
    CMP STG[SI], 13
    JE ItIsNewLine
    CMP STG[SI], 0
    JE EndOfSearch
    INC SI
    INC Cnt 
    CMP SI, 017
    JE ReadAllFile
    JMP CountNmbOfn
    
ItIsNewLine:
    INC SI
    INC SI
    PUSH CX
    MOV CX, Cnt
    CMP CX, CmpLength
    JB ItIsAbove     
    POP CX
    MOV Cnt, 0h
    CMP SI, 016
    JA ReadAllFile
    JMP CountNmbOfn
    
ItIsAbove:
    INC LineNmb
    POP CX   
    MOV Cnt, 0
    CMP SI, 016
    JA ReadAllFile
    JMP CountNmbOfn
    
EndOfSearch:
    MOV SI, Cnt
    CMP SI, CmpLength
    JB EndOfSearchA  
    JMP StartConvert

EndOfSearchA:
    INC LineNmb
    JMP StartConvert 
  
CloseFile:
    MOV AH, 3Eh
    INT 21h 
    MOV SI, 0h
    MOV BX, 0h

StartConvert:
    MOV SI, 0h
    MOV BX, 0Ah
    MOV CX, 0h
    CALL NewLine
    CALL NewLine
    CALL NewLine
    MOV AH, 9h
    MOV DX, offset OutputStr
    INT 21h   
    MOV DX, 0h
    MOV AX, LineNmb
    
ConvertHexTo10:
    CMP AX, 0h
    JE CoutFromStack
    DIV BX
    ADD DL, '0'
    PUSH DX
    INC SI
    CMP AX, 0h
    JE ConvertHexTo10
    
CoutFromStack:
    CMP SI, 0
    JE END
    MOV AH, 2h
    POP DX
    INT 21h
    DEC SI
    CMP SI, 0
    JE END
    JMP CoutFromStack             
    
BadFile:
    CALL NewLine
    MOV AH, 9h
    MOV DX, offset OutbadFile 
    INT 21h
    JMP END
    
BadFileFormat:
    CALL NewLine
    MOV AH, 9h
    MOV DX, offset OutBadFormat 
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
    MOV AX, 9h
    MOV DX, offset OutputStr
    
    
     
     
.data
    OutbadFile db 'Bad Path $' 
    OutBadFormat db 'Bad format not txt $'
    InputStr db 'Input needed length from 0 to 65535: $' 
    InputErrorStr db 'Input error $'                                 
    InputFilePath db 'Input file path: $' 
    OutputStr db 'Answer: $'
    CmpLength dw 0h
    LineNmb dw 0h
    Cnt dw 0h
    Length dw 0FFh
    PathToFile db 0FF (0h)
    Stg db 0FFh dup (0h)     