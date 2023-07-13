section .text
  global strstr

strstr:
	push rbp
  mov rbp, rsp
  xor rax, rax
  xor r8, r8 ;
  mov al, byte [rdi + r8] ; al = haystack char
  cmp al, 0 ; check if it is the end of the haystack
  je .check_empty ; will define later

.outer_loop:
  xor r9, r9 ;
  mov al, byte [rdi + r8]
  mov r10b, byte [rsi + r9]
  cmp al, 0 ; check if it is the end of the haystack
  je .return_null ; will define later
  cmp r10b, 0 ; check if it is the end of the needle
  je .load_res ; will define later
  mov r11, r8;
  inc r8
  cmp al, r10b
  jne .outer_loop

.inner_loop:
  mov al, byte [rdi + r11]
  mov r10b, byte [rsi + r9]
  cmp al, 0 ; check if it is the end of the haystack
  je .end_heystack ; will define later
  cmp r10b, 0 ; check if it is the end of the needle
  je .load_res ; will define later
  inc r9
  inc r11
  cmp al, r10b
  jne .outer_loop
  jmp .inner_loop

.check_empty:
  mov r10b, byte [rsi]
  cmp r10b, 0
  jne .outer_loop
  jmp .load_res

.end_heystack:
  cmp byte [rsi + r9], 0
  jne .return_null
  sub r8, 1
  add rdi, r8
  mov rax , rdi
  jmp .end

.return_null:
  xor rax, rax
  jmp .end

.load_res:
  mov rax, rdi

.end:
  mov rsp, rbp
  pop rbp
  ret
