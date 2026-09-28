
include "constants.inc"


segment readable executable

  if used bigint_map_pages

    ; rax : destination pointer
    ; rdx : amount of pages, cannot be zero
    ; destroys : rax, rbx, rcx, rdx, rsi, rdi, r10, r8, r9, r11, r12, r15
    bigint_map_pages:
      mov r12, rax
      mov r15, rdx

      mov rax, __NR_mmap
      mov rsi, _pagesize
      xor rdi, rdi
      mov rdx, (PROT_READ or PROT_WRITE)
      mov r10, (MAP_PRIVATE or MAP_ANONYMOUS)
      xor r8, r8
      dec r8
      xor r9, r9
      syscall

      cmp rax, -4096
      ja bigint_map_pages_ret_failure

      mov [r12], rax
      mov rax, r12
      add rax, 8
      mov rdx, r15
      dec rdx

      jnz bigint_map_pages

      bigint_map_pages_ret_success:
        xor eax, eax
        ret
      bigint_map_pages_ret_failure:
        xor eax, eax
        dec rax
        ret

  end if

  if used bigint_unmap_pages

    ; rax : source pointer
    ; rdx : amount of pages, cannot be zero
    ; destroys : rax, rcx, rdx, rsi, rdi, r12
    bigint_unmap_pages:
      mov r12, rax

      mov eax, __NR_munmap
      mov rdi, [r12]
      mov rsi, _pagesize
      syscall

      mov rax, r12
      add rax, 8
      dec rdx

      jnz bigint_unmap_pages

      ret

  end if

  if used bigint_zero_pages

    ; rax : destination pointer
    ; rdx : amount of pages, cannot be zero
    ; destroys : rax, rcx, rdx, rdi, r12
    bigint_zero_pages:
      mov rcx, (_pagesize / 8)
      mov rdi, [rax]
      mov r12, rax
      xor eax, eax
      cld
      rep stosq ; memset 0

      mov rax, r12
      add rax, 8
      dec rdx

      jnz bigint_zero_pages

      ret

  end if

  if used bigint_random_pages

    segment readable
      dev_random_path db "/dev/random", 0
      dev_random_path_len = $ - dev_random_path

    segment readable executable

    ; rax : destination pointer, without sign
    ; rdx : amount of pages, cannot be zero
    ; destroys : rax, rcx, rdx, rsi, rdi, r12, r13, r15
    bigint_random_pages:
      mov r12, rax
      mov r15, rdx

      mov rax, __NR_open
      mov rdi, dev_random_path
      mov rsi, O_RDONLY
      xor rdx, rdx
      syscall

      cmp rax, -4096
      ja bigint_random_pages_ret
      mov r13, rax

      bigint_random_pages_loop:
        mov rax, __NR_read
        mov rdi, r13
        mov rsi, [r12 + 8 * r15 - 8]
        mov edx, _pagesize
        syscall

        cmp rax, -4096
        ja bigint_random_pages_close

        dec r15
        jnz bigint_random_pages_loop

      bigint_random_pages_close:
      mov r13, __NR_close
      mov rdi, r13
      syscall
      bigint_random_pages_ret:
        ret

  end if

  if used bigint_set_zero

    ; rax : destination pointer, with sign
    ; rdx : amount of pages, cannot be zero
    ; destroys : rax, rcx, rdx, rdi, r12
    bigint_set_zero:
      mov qword [rax], 0
      add rax, 8
      call bigint_zero_pages
      ret

  end if

  if used bigint_negate

    ; rax : destination pointer, with sign
    bigint_negate:
      xor [rax], 1
      ret

  end if

  if used bigint_add_into

    ; rax : pointer to the first number, without sign
    ; rbx : pointer to the second number, without sign
    ; rcx : pointer to the destination number, without sign
    ; rdx : amount of pages, cannot be zero
    ; destroys : rax, rbx, rcx, rdx, rsi, r12, r13, r14, r15
    bigint_add_into:
      mov r12, rax
      mov r13, rbx
      mov r14, rcx
      mov r15, rdx

      xor eax, eax
      bigint_add_into_page_loop:
        xor esi, esi
        bigint_add_into_loop:
          sahf
            mov rbx, [r12]
            mov rbx, [rbx + 8 * rsi]
            mov rcx, [r13]
            mov rcx, [rcx + 8 * rsi]
            adc rbx, rcx
            mov rdx, [r14]
            mov [rdx + 8 * rsi], rbx
          lahf

          inc esi
          cmp esi, (_pagesize / 8)
          jne bigint_add_into_loop

        add r12, 8
        add r13, 8
        add r14, 8
        dec r15
        jnz bigint_add_into_page_loop

      ret

  end if

  if used bigint_fmt_qword

    ; rax : qword to format
    ; rdi : pointer to buffer of size 64+
    ; destroys : rbx, rcx, rdi (increments by 64)
    bigint_fmt_qword:
      mov ecx, 63
      bigint_fmt_qword_loop:
        bt rax, rcx
        setc bl
        add bl, '0'
        mov [rdi], bl
        inc rdi
        dec ecx
        jns bigint_fmt_qword_loop
      ret

  end if

  if used bigint_fmt

    ; rax : source pointer, with sign
    ; rbx : write leading zeros
    ; rdx : amount of pages, cannot be zero
    ; rdi : pointer to buffer of size 2+rdx+
    ; returns the amount of characters written, in rax
    ; destroys : rax, rbx, rcx, rdx, rsi, rdi, r12, r13, r14, r15
    bigint_fmt:
      mov r12, rax
      xor r13, r13

      mov rax, [r12]
      test eax, eax
      setnz al
      add al, al
      add al, '+'
      cld
      stosb
      mov al, '0'
      mov byte [rdi], al

      lea r12, [r12 + 8 * rdx]

      std
      bigint_fmt_page_loop:
        mov r14, [r12]
        mov esi, (_pagesize / 8)
        test ebx, ebx
        jnz bigint_fmt_loop
        mov r15, rdi
        lea rdi, [r14 + _pagesize - 8]
        mov ecx, (_pagesize / 8)
        xor eax, eax
        repz scasq
        mov rsi, rdi
        sub rsi, r14
        sar rsi, 3
        add rsi, 2
        mov rdi, r15
        bigint_fmt_loop:
          dec esi
          js bigint_fmt_loop_end
          mov rax, [r14 + 8 * rsi]

          xor ecx, ecx
          or rcx, rax
          or ecx, ebx
          jz bigint_fmt_loop

          call bigint_fmt_qword
          add r13, 64
          mov rbx, r13 ; nonzero
          test esi, esi
          jnz bigint_fmt_loop

        bigint_fmt_loop_end:

        sub r12, 8
        dec rdx
        jnz bigint_fmt_page_loop

      xor eax, eax
      test r13, r13
      setz al
      inc eax
      add r13, rax

      bigint_fmt_ret:
      mov rax, r13
      ret

  end if

