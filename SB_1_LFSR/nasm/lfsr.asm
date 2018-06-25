%include "asm_io.inc"

%macro randomGet 0
	;xor dx, dx	;zerar dx
	mov bx, ax
	mov cx, ax

	shr bx, 0	;selecionar bit 16
	and bx, 1	;isolar bit 16
	shr cx, 2	;selecionar bit 14
	and cx, 1	;isolar bit 14
	mov dx, bx	;colocar bx em dx
	xor dx, cx	;xor bits[16] e bits[14]

	mov bx, ax
	shr bx, 3	;selecionar bit 13
	and bx, 1	;isolar bit 13
	xor dx, bx	;xor dx e bits[13]

	mov bx, ax
	shr bx, 5	;selecionar bit 11
	and bx, 1	;isolar bit 11
	xor dx, bx	;xor dx e bits[11]


	shl dx, 15	;colocar resultado na posicao de bit 0
	shr ax, 1	;shift left 1 da operacao random
	or ax, dx	;adicionar bit resultado ao bits[0]

	call print_int
	call print_nl
%endmacro


section .dat

segment .bss

segment .text
  global  main
	main:
		enter	0,0
		pusha

mov ax, 3	;valor seed
randomGet
randomGet
randomGet
randomGet
randomGet

popa
mov	eax, 0
leave
ret
