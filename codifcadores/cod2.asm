;PI
.model small
.stack 512
.data
   peatonal  db 0,0,1,0
   resul db ?,?
    num1 db ?
    num2 db ?
   
  .code
    .startup
    
; Codificador----------------------

  
  ;mov al,0
  mov al, 0
  mov resul[0], al
  mov resul[1],al
  cmp peatonal[0],1
  je resultado1
  ;mov al,1
  mov al, 0
  mov resul[0], al
  mov al,1
  mov resul[1],al
  cmp peatonal[1],1
  je resultado1
  ;mov al,2
  mov al, 1
  mov resul[0], al
  mov al,0
  mov resul[1],al
   cmp peatonal[2],1
   je resultado1
  ;mov al,3
  mov al, 1
  mov resul[0], al
  mov resul[1],al
   cmp peatonal[3],1
   je resultado1
  
  resultado1:
  mov al,resul[0]
  mov num1,al
  ; imprimir para probar---------
   add num1,30h
     mov ah,02h 
     mov dl,num1
   int 21h
   jmp resultado2
   
   resultado2:
   mov al,resul[1]
   mov num2,al
  ; imprimir para probar---------
   add num2,30h
     mov ah,02h 
     mov dl,num2
   int 21h
  
   
    
  .exit
end