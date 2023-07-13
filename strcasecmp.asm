section .text
  global strcasecmp

.module_al:
  cmp al, 122 ; 122 = 'z'
  jg .module_r9 ; if al > 122, then al is not a lowercase letter
  sub al, 32 ; convert to uppercase
  jmp .module_r9 ; continue check for r9 (src) to be a lowercase letter

.module_r9_1:
  cmp r9, 122 ; 122 = 'z'
  jg .compare
  sub r9, 32 ; convert to uppercase
  jmp .compare

.module_r9:
  cmp r9, 97 ; 97 = 'a'
  jge .module_r9_1 ; if r9 >= 97, then r9 is a lowercase letter
  jmp .compare

.check:
  cmp al, 97 ; 97 = 'a'
  jge .module_al ; if al >= 97, then al is a lowercase letter
  jmp .module_r9

strcasecmp:
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
  jmp .check
.compare:
  cmp al, r9b
  jne .end
  inc r8
  jmp .loop

.end:
  sub rax, r9
  mov rsp, rbp
  pop rbp
  ret
