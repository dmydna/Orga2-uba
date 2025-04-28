;typedef struct str_array {
;  uint8_t size;	1 byte, 0 offset
;  uint8_t capacity;    1 byte, 1 offset
;  char** data;         1 byte, 2 offset
;} str_array_t;         struct = 3 bytes

section .rodata

section .text

extern malloc

global strArrayNew
global strArrayGetSize
global strArrayGetSize
global strArrayRemove
global strArrayDelete


;EJERCICIO 0:

;str_array_t* strArrayNew(uint8_t capacity)

;rdi -> capacity
strArrayNew:
push rbp
mov rbp, rsp
mov rsi, rdi

mov rdi, 3
call malloc
mov [rax], rsi
mov [rax+1], byte 0
mov [rax+2], byte 0

mov rsp, rbp
pop rbp
ret



;EJERCICIO 1:
;uint8_t strArrayGetSize(str_array_t* a);

;rdi -> *a
strArrayGetSize:
push rbp
mov rbp, rsp

mov ax, [rdi]

mov rsp, rbp
pop rbp
ret

;EJERCICIO 2:
;char* strArrayGet(str_array_t* a, uint8_t i);

; rdi -> *a, rsi -> i
strArrayGet:
push rbp
mov rbp, rsp
push rdi
push rsi

.while:
	cmp rcx, rsi
	je .end
	mov rax, [rdi+2]
	add rdi, 3
	inc rcx
	jmp .while
.end:
mov rsp, rbp
pop rbp
ret

;EJERCICIO 3:
;char* strArrayRemove(str_array_t* a, uint8_t i);

rdi -> *a, rsi -> i
strArrayRemove:
push rbp
pusb rbp, rsp

mov r14, rdi;    guardo rdi
mov r15, rsi;    guardo rsi

mov r8, [rdi];   a->size
mov r9, [rdi+1]; a->capacity
mov r10,[rdi+2]; a->data

cmp rsi, r8
jb fuera_rango

dec r8 ; new_size
dec r9 ; new_capacity


mov rdi, r8; new_size
call malloc
mov r10, rax ; new_data

xor rcx, rcx; indice
.loop_1:
	cmp rcx, rsi ; j < i
	je .loop_2

	;son punteros a str
	mov rax, r10 ; new_data[j] = a->data[j]

	inc r10      ; new_data ++
	inc rax      ; data ++
	inc rcx      ; indice ++
	jmp .loop_1

.loop_2
	cmp rcx, r8 ; j<new_size
	je .end

	add r10, 1   ; data[j+1]
	mov rax, r10

	inc r10      ; new_data ++
	inc rax      ; data ++
	inc rcx      ; indice ++
	jmp .loop_2
.end:
mov [rax], 0;

;free(a->data)
mov rdi, r10
call free

mov [rdi], r8;   a->size
mov [rdi+1],r9; a->capacity
mov [rdi+2],; a->data

mov rsp,rbp
pop rbp
ret

EJERCICIO 4:
;void strArrayDelete(str_array_t* a);

rdi -> *a
strArrayDelete:
push rbp
mov rbp, rsp
sub rsp, 8
push rdi ; guardo *a

mov rsi, [rdi];   size
mov rcx, [rdi+1]; capacity
mov rdx, [rdi+2]; data

xor r8, r8; indice

.while:
	cmp r8, rsi
	je .end
	mov rdi, [rdx]
	call free
	inc rdx
	dec rsi
	jmp .while
.end:
pop rdi

mov rdi, rdi
;free(a->size)
call free

mov rdi, rcx
;free(a->capacity)
call free

mov rdi, rdx
;free(a->data)
call free

mov rsp, rbp
pop rbp
ret
