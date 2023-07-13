
global memcpy

section .text
memcpy:
  push rbp
  mov rbp, rsp
  xor r8, r8 ; this is the counter
  mov rax, rdi ; rdo = dest, rsi = src, rdx = n

.loop:
  cmp r8, rdx ; compare counter to n
  je .end
  mov r9b, byte [rsi + r8] ; move the byte from src to r9 (8 bits)
  mov byte [rax + r8], r9b ; move the byte from r9 to dest
  inc r8 ; icr counter
  jmp .loop

.end:
  mov rax, rdi ; reset rax to dest
  mov rsp, rbp
  pop rbp
  ret