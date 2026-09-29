format ELF64 executable 32
entry start

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

    ; lea rax, [bigint_a + 8]
    ; mov rdx, 4
    ; call bigint_random_pages
    mov rax, [bigint_a + 8]
    mov qword [rax], 5
    mov [bigint_a], 0

    mov rax, [bigint_b + 8]
    mov qword [rax], 4
    mov [bigint_b], 0
    mov [bigint_c], 0

    mov rax, bigint_a
    xor ebx, ebx
    mov rdx, 4
    mov rdi, format_buffer
    call bigint_fmt

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
    mov edx, 1
    mov rdi, format_buffer
    call bigint_fmt

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
    call bigint_fmt

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

    mov rax, bigint_a
    mov rbx, bigint_b
    mov rdx, 1
    call bigint_cmp_signed
    ja above
    jb below

    equal:
    mov rax, __NR_write
    mov rdi, STDOUT_FILENO
    mov rsi, equal_msg
    mov edx, 2
    syscall
    jmp case_end

    above:
    mov rax, __NR_write
    mov rdi, STDOUT_FILENO
    mov rsi, above_msg
    mov edx, 2
    syscall
    jmp case_end

    below:
    mov rax, __NR_write
    mov rdi, STDOUT_FILENO
    mov rsi, below_msg
    mov edx, 2
    syscall

    case_end:

    mov eax, __NR_exit
    xor edi, edi
    syscall

segment readable

  newline db 10
  equal_msg db "=", 10
  above_msg db ">", 10
  below_msg db "<", 10

segment readable writeable

  bigint_a rq 5
  bigint_b rq 5
  bigint_c rq 5
  format_buffer rb 131073

