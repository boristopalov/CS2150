; Boris Topalov, bnt4yb, 3/29/20
; mathlib.s
; Description: Implementation of product and power subroutines
;

	global product
	global power
		
	section .text
	
product:
	xor rax, rax 		; zero out the return register
		
prodstart:
	cmp rsi, 0 		; we are done if our 2nd param is 0
	je done			; 2nd param serves as a counter
	add rax, rdi		; add first param to return register
	dec rsi			; decrement 2nd param and loop to start
	jmp prodstart
	
done:
	ret




power:
	mov rax, 1 		; set return register to 1 (base case)
	mov r10, rsi		; copy over 2nd param to r10
	mov r11, rdi		; cop over 1st param to r11

powstart:
	cmp r10, 0		; if r10 (our counter) is 0 jump
	je powzero		; to our zero case
	cmp r10, 1 		; if r10 is 1 jump
	je powone		; to our one case
	mov rsi, r11 		; otherwise 2nd param becomes r11 
	call product		; r11 is the initial first param
	mov rdi, rax 		; first param becomes result from calling product
	dec r10 		; decrement r10 (our counter) and loop back
	call powstart

powzero:
	ret
powone:
	mov rsi, 1 		; if 2nd param is one, we call product
	call product 		; with value 1 as our 2nd parameter
	ret


	
