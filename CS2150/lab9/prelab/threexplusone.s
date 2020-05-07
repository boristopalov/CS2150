	;; Boris Topalov, bnt4yb, 4/4/20
	;; threexplusone.s
	;; Description: x86 implementation of collatz conjecture



	global threexplusone
	
	

	section .text


threexplusone:
	xor rax, rax 		; zero out return register
	
			
start:
	cmp rdi, 1 		; if param = 1, jump to done
	je done

	mov r12, rdi
	and r12, 1 		; check if param is odd or even
	jz even


	lea rdi, [rdi*2+rdi]
	add rdi, 1
	inc rax			; count += 1
		
even:
	shr rdi, 1
	inc rax			; count += 1
	call start
		

done:
	ret

	
