section .text
  global memset

memset:
  push rbp
  mov rbp, rsp
  cmp rdx, 0
  je .end
  mov rax, rdi ; rax = dest , rsi = value , rdx count_bites

.loop:
  mov [rax], sil
  inc rax
  dec rdx
  jnz .loop

.end:
  mov rsp, rbp
  pop rbp
  mov rax, rdi
  ret