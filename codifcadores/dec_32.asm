;PI
.model small
.stack 512
.data
   entrada  db 0,0,1
   resul db 8 dup ('0'),'$'
   aux db 0
  .code
    .startup
    
; Codificador----------------------
  
    
  cmp entrada[0],0
  jg p1
  cmp entrada[1],0
  jg p2
  cmp entrada[2],0
  jg p5
  jmp resultado
  
  p1 proc;---------
  
  cmp entrada[1],0
  jg p6
  cmp entrada[2],0
  jg p3
  mov SI,4
  jmp resultado
  ret
  p1 endp
  
  p2 proc
  cmp entrada[2],0
  jg p4
  mov SI,2
  jmp resultado
  ret
  p2 endp
  
  p3 proc
  mov SI,5
  jmp resultado
  ret
  p3 endp

  
   p4 proc
  
   mov SI,3
  jmp resultado
  ret
  p4 endp
  
   p5 proc
   mov SI,1
  jmp resultado
  ret
  p5 endp
  
   p6 proc
  cmp entrada[2],0
  jg p7
  mov SI,6
  jmp resultado
  ret
  p6 endp
  
   p7 proc
   mov SI,7
  jmp resultado
  ret
  p7 endp
  

  
  resultado:
  ;mov cx,8
  ;mov SI,aux
  ;ciclo:
   mov dl,1        ;Proceso para imprimir cadena final con numero binario
      add dl,30h
      mov resul[SI],dl
  mov ah,09h
  lea Dx,resul
  int 21h
  ; inc SI
   ;loop ciclo
   
    
  .exit
end