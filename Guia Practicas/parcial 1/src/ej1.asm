section .rodata

section .text


global ej1_cesar
global ej2_prefijo_de


; EJERICIO 1

; char* cesar(char* str, int n)

; Asumo por requiere
; que recibo un string
; con chars de [A-Z]
; y n de [0-25]

; rdi -> char* str
; rsi -> int n

ej1_cesar:
    push rbp
    mov rbp, rsp

    ;cl: char actual
    ;rax inicio string
    ;rdi fin string

    mov r8,  rsi ; guarda rsi original
    mov rax, rdi
    while:
    cmp cl, 0
    je end
    ; carga char en cl
    mov cl, [rdi]

    mov rsi, r8 ; restaura rsi
    test cl, 'Z'
    jg if
    jmp else
    if: ; *str > 'Z'
        dec sil ; rsi -> sil
        add sil, 'A'
        mov [rdi], byte sil
        inc rdi
        jmp while
    else:
        add sil, cl
        mov [rdi], byte sil
        inc rdi
        jmp while

    end:
    mov rsp, rbp
    pop rbp
	ret


; EJERCICIO 2

;int prefijo_de(char* str1, char* str2)
; rdi -> *str1
; rsi -> *str2

ej2_prefijo_de:
    push rbp
    mov rbp, rsp

    xor rax, rax
    while_pf:
        mov cl, [rdi]
        mov dl, [rsi]
        test cl, cl
        je end_pf
        test cl, cl
        je end_pf
        test cl, dl
        inc rsi
        inc rdi
        jne end_pf
        inc rax
        jmp while

    end_pf:
    mov rsp, rbp
    pop rbp
    ret
