; section .data
;  msg: db "Hello, World!", 0x0a
;  format: db "%d", 0x0a

section .text
  global strlen

strlen:
  push rbp
  mov rbp, rsp
  ;rdi = string
  xor rax, rax ; rax = len = 0

.loop:
  mov r8b, [rdi + rax] ; rax is offset
  inc rax ; first time rax = 1
  cmp r8b, 0
  jne .loop
  dec rax ; this should be the len
  mov rsp, rbp
  pop rbp
  ret

; _start:
;   mov rdi, msg
;   call strlen
;   mov rdi, format
;   mov rsi, rax
;   mov al, 0
;   call printf
;   mov rax, 60
;   mov rdi, 0
;   syscall
;   ret
