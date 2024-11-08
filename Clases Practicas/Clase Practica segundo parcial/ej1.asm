_isr99:
   pushad
   
   push ESI
   push EDI
   push EAX
   call espiar
   
   ;acomodo la pila
   add ESP, 12
   
   ;IMPORTANTE no pisar el resultado con el popad
   mov [ESP+offset_EAX], eax
   
   popad
   iret


