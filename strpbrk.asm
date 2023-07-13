section	.text
    global	strpbrk

strpbrk:
    push rbp
    mov rbp, rsp
	xor r8, r8 ; r8 will be used to iterate through the string
	xor	r9, r9 ; r9 will be used to iterate through the accept string

.outer_loop:
	mov	al, byte [rdi + r8]
	cmp	al, 0
	je	.not_found ; if we reach the end of the string, return 0
	inc	r8
	xor	r10, r10

.inner_loop:
	mov	r9b, byte [rsi + r10]
	cmp	r9b, 0
	je	.outer_loop
	cmp	al, r9b
	je	.found ; if we find a match, return the pointer to the match
	inc	r10
	jmp	.inner_loop

.found:
	sub	r8, 1
	add	rdi, r8
	mov	rax, rdi
	jmp	.end

.not_found:
    xor rax, rax

.end:
    mov rsp, rbp
    pop rbp
    ret