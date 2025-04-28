section .text

extern rand

global ej3
global ej4

:typedef struct cliente_str {
;	char nombre [NAME_LEN];		size:1+6p,	offset:0
;	char apellido[NAME_LEN];	size:1+6p,	offset:8
;	uint64_t compra;				size:8,		offset:8 
;	uint32_t dni;					size:4+4p,	offset:16
;} cliente_t;
;total= 24

typedef struct __attribute__((__packed__)) packed_cliente_str {
	char nombre [NAME_LEN];		size:1,		 offset:0
	char apellido[NAME_LEN];	size:2,		 offset:1
	uint64_t compra;				size:8,		 offset:3
	uint32_t dni;					size:4,		 offset:11
} __atribute__((packed)) packed_cliente_t; 
;total = 15


ej3:
	push rbp
	mov rbp, rsp
	pop rsi
	pop rdi
	
	mov rdi, rsi
	call rand
	pop rdi
	pop rsi
	
	idiv rsi ; rax mod rsi -> rdx
	xor rsi, rsi 
	
	; rdx target 
	; rsi actual 
	
	while:
		cmp rsi, rdx
		je target
		mov r8, [rdi]	
		add rdi, 24
		inc rsi
		jmp while
	target:
	mov rax, rdi ; devuelve ptr
	mov rsp, rbp
	pop rbp	
	ret


ej4b:
	
	ret
