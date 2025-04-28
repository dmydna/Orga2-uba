extern malloc
extern free
extern fprintf

section .data

str_null db "NULL", 0 ; 'N','U','L','L',0
formato db "%s", 0 ; '%','s', 0


section .text

global strCmp
global strClone
global strDelete
global strPrint
global strLen

; ** String **

; int32_t strCmp(char* a, char* b)
strCmp:
	; rdi -> a
	; rsi -> b
	push rbp
	mov rbp, rsp

	mov [rsi], cl
	mov [rdi], dl

	mov rax, 0

	while:
		cmp cl, dl
			jb .AesMayorQueB
			jl .AesMenorQueB

		cmp cl, 0
		jz .end
		cmp dl, 0
		jz .end
    
		inc rsi
		inc rdi
		jmp .while

	.AesMayorQueB:
	mov rax, 1
	jmp .end
	.AesMenorQueB:
	mov rax, -1

	.end:
	ret

; char* strClone(char* a)
strClone:
;	rdi-> a
	push rbp
	mov rbp, rsp
;   resguarda rdi 
	push rdi
;   alinea pila	
	push rdi; 
	
	call strLen
	inc rax

	mov rdi, rax
	call malloc

	pop rdi
	pop rdi

	mov cl, [rdi]
	.while:
		test cl, cl
		jz .end
		mov [rax], cl
		inc rdi
		inc rax
	.end:

	mov byte [rax], 0

	pop rbp
	ret

; void strDelete(char* a)
strDelete:
	push rbp
	mov rbp, rsp

	call free

	pop rbp
	ret

; void strPrint(char* a, FILE* pFile)
strPrint:
	push rbp
	mov rbp, rsp

	;fprintf ( *file, [format], var)

	mov cl, rsi

	.if: test cl, 0
	  je .else
		mov rdx, [str_null] ; str es NULL
		mov rdi, rsi 
		mov rsi, [formato]

		call fprintf 
		jmp .end
	.else:
		mov rdx, rdi ; str es *a
		mov rdi, rsi  
		mov rsi, [formato]

		call fprintf
	
	.end:
	pop rbp
	ret

; uint32_t strLen(char* a)
strLen:
	mov cl, [rdi] 
	xor rax, rax
	.while:
		test cl, cl
		jz .end
		add rax, 1
		inc rdi
		jmp .while
	.end:
	ret


