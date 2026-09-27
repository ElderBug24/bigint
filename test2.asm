format ELF64 executable 32      ; Tells FASM to output a 64-bit Linux executable
entry start                     ; Defines the execution entry point

include "bigint.inc"
include "constants.inc"

segment readable executable

start:
  lea rax, [bigint_a + 8]
  mov rdx, 4
  call bigint_map_pages

  lea rax, [bigint_b + 8]
  mov rdx, 4
  call bigint_map_pages

  lea rax, [bigint_c + 8]
  mov rdx, 4
  call bigint_map_pages

  mov rax, [bigint_a + 8]
  mov qword [rax], 32783612
  mov qword [rax + 8], 12315782
  mov [bigint_a], 0
  mov rax, [bigint_b + 8]
  mov qword [rax], 1
  mov [bigint_b], 0
  mov [bigint_c], 0

  mov rax, bigint_a
  xor ebx, ebx
  mov rdx, 1
  mov rdi, format_buffer
  call fmt_bigint

  mov rdx, rax
  mov eax, __NR_write
  mov edi, STDOUT_FILENO
  mov rsi, format_buffer
  syscall

  mov eax, __NR_write
  mov edi, STDOUT_FILENO
  mov rsi, newline
  mov edx, 1
  syscall
  mov eax, __NR_write
  syscall

  mov rax, bigint_b
  xor ebx, ebx
  mov rdx, 1
  mov rdi, format_buffer
  call fmt_bigint

  mov rdx, rax
  mov eax, __NR_write
  mov edi, STDOUT_FILENO
  mov rsi, format_buffer
  syscall

  mov eax, __NR_write
  mov edi, STDOUT_FILENO
  mov rsi, newline
  mov edx, 1
  syscall
  mov eax, __NR_write
  syscall

  lea rax, [bigint_a + 8]
  lea rbx, [bigint_b + 8]
  lea rcx, [bigint_c + 8]
  mov rdx, 4
  call bigint_add_into

  mov rax, bigint_c
  xor ebx, ebx
  mov rdx, 1
  mov rdi, format_buffer
  call fmt_bigint

  mov rdx, rax
  mov eax, __NR_write
  mov edi, STDOUT_FILENO
  mov rsi, format_buffer
  syscall

  ; Exit the program
  mov eax, __NR_exit
  xor edi, edi
  syscall

segment readable

  newline db 10

segment readable writeable

  bigint_a rq 5
  bigint_b rq 5
  bigint_c rq 5
  format_buffer rb 131073

