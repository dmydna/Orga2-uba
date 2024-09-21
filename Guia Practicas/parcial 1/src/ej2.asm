extern abs


section .rodata
; Poner acá todas las máscaras y coeficientes que necesiten para el filtro

float_r dd 0.2126
float_g dd 0.7152
float_b dd 0.0722

mask_r:     times 16 db 0xFF, 0x00, 0x00, 0x00
mask_g:     times 16 db 0x00, 0xFF, 0x00, 0x00
mask_b:     times 16 db 0x00, 0x00, 0xFF, 0x00
mask_a:     times 16 db 0x00, 0x00, 0x00, 0xFF
mask_rg:    times 16 db 0xFF, 0xFF, 0x00, 0x00
mask_rgb:   times 16 db 0xFF, 0xFF, 0xFF, 0x00
alpha_255: db 0x00, 0x00, 0x00, 0xFF

section .text

; Marca un ejercicio como aún no completado (esto hace que no corran sus tests)
FALSE EQU 0
; Marca un ejercicio como hecho
TRUE  EQU 1

p_lenght EQU 4
r_offset EQU 0
g_offset EQU 1
b_offset EQU 2
a_offset EQU 3

; Marca el ejercicio 2 como hecho (`true`) o pendiente (`false`).
;
; Funciones a implementar:
;   - ej1
global EJERCICIO_2_HECHO
EJERCICIO_2_HECHO: db FALSE ; Cambiar por `TRUE` para correr los tests.



; Aplica un efecto de "mapa de calor" sobre una imagen dada (`src`). Escribe la
; imagen resultante en el canvas proporcionado (`dst`).
;
; Para calcular el mapa de calor lo primero que hay que hacer es computar la
; "temperatura" del pixel en cuestión:
; ```
; temperatura = (rojo + verde + azul) / 3
; ```
;
; Cada canal del resultado tiene la siguiente forma:
; ```
; |          ____________________
; |         /                    \
; |        /                      \        Y = intensidad
; | ______/                        \______
; |
; +---------------------------------------
;              X = temperatura
; ```
;
; Para calcular esta función se utiliza la siguiente expresión:
; ```
; f(x) = min(255, max(0, 384 - 4 * |x - 192|))
; ```
;
; Cada canal esta offseteado de distinta forma sobre el eje X, por lo que los
; píxeles resultantes son:
; ```
; temperatura  = (rojo + verde + azul) / 3
; salida.rojo  = f(temperatura)
; salida.verde = f(temperatura + 64)
; salida.azul  = f(temperatura + 128)
; salida.alfa  = 255
; ```
;
; Parámetros:
;   - dst:    La imagen destino. Está a color (RGBA) en 8 bits sin signo por
;             canal.
;   - src:    La imagen origen A. Está a color (RGBA) en 8 bits sin signo por
;             canal.
;   - width:  El ancho en píxeles de `src` y `dst`.
;   - height: El alto en píxeles de `src` y `dst`.
global ej2

f_: ; uint8 f_(uint8_t temperatura[rdi])
	push rbp
	mov rbp, rsp
	sub rsp, 8

	;4 * abs(temperatura - 192)
	mov rsi, 192
	sub rdi, rsi
	;call abs;
	mov rcx, 4
	mul rcx

	;384 - 4 * abs(temperatura - 192)
	mov rsi, 384
	sub rsi, rax

	if: cmp rsi, 0
	    jl min
	else_if: cmp rsi, 255
	    jb max

	min: mov rax, 0
	     jmp exit
	max: mov rax, 255

	exit:
	add rsp, 8
	mov rsp, rsp
	pop rbp
	ret

ej2:
	; Te recomendamos llenar una tablita acá con cada parámetro y su
	; ubicación según la convención de llamada. Prestá atención a qué
	; valores son de 64 bits y qué valores son de 32 bits.
	;
	; r/m64 = rgba_t*  dst
	; r/m64 = rgba_t*  src
	; r/m32 = uint32_t width
	; r/m32 = uint32_t height
	push rbp
	mov rbp, rsp

	;obtengo cantidadPixeles
	mov rax, rdx
	mul rcx ; width * height

	while:
		cmp rax, 0
		je end
		; cargamos dst[i]
		movdqu xmm11, [rdi]  ; carga 4 pixels
		; cargamos src[i]
		movdqu xmm10, [rsi]  ; carga 4 pixel
		; rojo  -> xmm1
		; verde -> xmm2
		; azul  -> xmm3
		; alfa  -> xmm4
		; temperatura -> xmm5

		; SEPARO COLORES
		;obtengo valores rojos de src
		movdqu xmm1, xmm10
		psrld xmm1, 16 ; shifte
		;obtengo valores verdes de src
		movdqu xmm2, xmm10
		pand xmm2, [mask_g]
		psrld xmm2, 8  ; shifteo
		;obtengo valores azules de src
		movdqu xmm3, xmm10
		pand xmm3, [mask_b]
		psrld xmm3, 4  ; shifteo
		;obtengo valores alfa [opcional]
		movdqu xmm4, xmm10
		pand xmm4, [mask_a] ; packed_and

		; TEMPERATURA
		paddusb xmm1, xmm2  ; r + g
		paddusb xmm1, xmm3  ; r + g + b
		;divpd xmm1,   3       ; (r+g+b)/3
		cvtps2dq xmm0, xmm1 ;(r+g+b)/3 -> int
		movdqu xmm5, xmm0 ;  temperatura -> xmm5

		;f(temperatura)
		pxor xmm11, xmm11      ; limpio rgba
		call f_
		paddusb xmm11, xmm0    ; red = f(temperatura)

		;f(tempratura + 64)
		pand xmm11, [mask_r]    ; limpio green, blue
		movdqu xmm0, xmm5
		;addss xmm0, 64
		call f_
		paddusb xmm11, xmm0		 ; green = f(tempratura + 64)

		;f(tempratura + 128)
		pand xmm11, [mask_rg]	 ; limpio blue
		movdqu xmm0, xmm5
		;addss xmm0, 128
		call f_
		paddusb xmm11, xmm0      ; blue = f(temperatura + 128)

		;alpha 255
		paddusb xmm11, [alpha_255]   ; seteo valores de alfa 255

		movdqu [rdi], xmm11       ; guardo los cambios
		add rdi, p_lenght         ; dst ++
		add rsi, p_lenght         ; src ++

		sub eax, 4                ; cantPíxeles = cantPíxeles - 4
		jmp while

	end:
	mov rsp, rbp
	pop rbp
	ret
