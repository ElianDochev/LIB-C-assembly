section .text
  global strchr


strchr:
  push rbp
  mov rbp, rsp
  ; rdi = str, rsi (8 bits) = sil = c
  xor rax, rax ; rax = 0
.loop:
  cmp byte [rdi], sil ; *rdi == rsi
  je .found
  cmp byte [rdi], 0 ; *rdi == 0
  je .end
  inc rdi ; rdi++ increase pointer
  jmp .loop

.found:
  mov rax, rdi ; rax gets the address of the char

.end:
  mov rsp, rbp
  pop rbp
  ret
