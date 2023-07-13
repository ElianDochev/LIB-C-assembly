section .text
  global strcmp

strcmp:
  push rbp
  mov rbp, rsp
  xor rax, rax; rdi = dest, rsi = src
  xor r8, r8; r8 = 0 = rcx
  xor r9, r9; r9 = 0

.loop:
  mov al, byte [rdi + r8]
  mov r9b, byte [rsi + r8]
  cmp rax, 0
  je .end
  cmp r9, 0
  je .end
  cmp al, r9b
  jne .end
  inc r8
  jmp .loop

.end:
  sub rax, r9
  mov rsp, rbp
  pop rbp
  ret
