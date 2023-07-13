section	.text
    global	strcspn

strcspn:
    push rbp
    mov rbp, rsp
	xor	r9, r9 ; r9 will be the current character of the first string
	xor r10, r10 ; r10 will be the index of the second string
	xor r11, r11 ; r11 will be the length of the string

.outer_loop:
	mov	al, byte [rdi + r11]
	cmp	al, 0
	je	.not_found; if we reach the end of the string, return the length
	inc	r11
	xor	r10, r10

.inner_loop:
	mov	r9b, byte [rsi + r10]
	cmp	r9b, 0
	je	.outer_loop
	cmp	al, r9b
	je	.found
	inc	r10
	jmp	.inner_loop

.found:
	sub	r11, 1
	mov	rax, r11
	jmp	.end

.not_found:
	mov	rax, r11

.end:
    mov rsp, rbp
    pop rbp
    ret