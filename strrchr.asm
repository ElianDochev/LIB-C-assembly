global strrchr

section .text

strrchr:
  push rbp
  mov rbp, rsp
  ; rdi = str, rsi (8 bits) = sil = c
  xor rax, rax ; rax = 0
.loop:
  cmp [rdi], sil; *rdi == rsi
  je .found
.continue:
  cmp byte [rdi], 0 ; *rdi == 0
  je .end
  inc rdi ; rdi++ increase pointer
  jmp .loop

.found:
  mov rax, rdi ; rax gets the address of the char
  jmp .continue

.end:
  mov rsp, rbp
  pop rbp
  ret
