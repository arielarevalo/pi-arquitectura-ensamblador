.model flat, stdcall
.stack 4096

ExitProcess PROTO, dwExitCode:DWORD

.DATA
    WRITE DB 0
    DUPL DB 0
    VAL_O DB 0,1
    PEAT DB 3
    COORD DB 0
.code
main PROC
    XOR ECX, ECX            ; Cero al Contador
start:
    MOV AL, DUPL            ; Confirmar si DUPL es cero
    TEST AL, AL         
    JZ true             
    TEST ECX, ECX           ; Confirmar si contador es cero
    JZ true             
    MOV AL, CL              ; Valor de fase al Acumulador
    INC ECX                 ; Contador de fase aumenta
    JMP fases
true:
    MOV WRITE, 1            ; Solicitar valor reciente al validador
                            ; [TODO: Llamar validador]
    DEC WRITE               
    MOV AL, VAL_O[1]        ; Extraer valor de salida del validador
    SHL AL, 1
    ADD AL, VAL_O[0]      
    ADD AL, PEAT            ;   Valor de fase al Acumulador
fases:
    PUSH ECX            
    MOV ECX, 3              ; Número de bits del valor de salida al Contador 
    MOV EDI, OFFSET COORD 
    MOV EDX, EAX        
digito:        
    XOR EAX, EAX            ; Extraer un bit de la fase del Acumulador
    RCR EDX, 1          
    ADC EAX, 0
    MOV [EDI], AL           ;   Valor de bit de la fase a salida coordinador
    INC EDI
    LOOP digito             ; Tres bits en total
    POP ECX
    CALL ExitProcess
main ENDP
END main