
; TODO: save constants as macros

if defined __pagesize
  _pagesize = __pagesize
else
  _pagesize = 4096 ; 4KB
end if

segment readable executable

  if used bigint_map_pages

    ; rax : destination pointer
    ; rdx : amount of pages, cannot be zero
    ; destroys : rax, rbx, rcx, rdx, rsi, rdi, r10, r8, r9, r11, r12, r13
    bigint_map_pages:
      mov r12, rax
      mov r13, rdx

      mov rax, 9    ; mmap
      mov rsi, _pagesize
      xor rdi, rdi
      mov rdx, 3    ; PROT_READ | PROT_WRITE
      mov r10, 34   ; MAP_PRIVATE | MAP_ANONYMOUS
      xor r8, r8
      dec r8
      xor r9, r9
      syscall

      cmp rax, -4096
      ja bigint_map_pages_exit_failure

      mov [r12], rax
      mov rax, r12
      mov rdx, r13
      add rax, 8
      dec rdx

      jz bigint_map_pages_exit_success
      jmp bigint_map_pages

      bigint_map_pages_exit_success:
        xor eax, eax
        ret
      bigint_map_pages_exit_failure:
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

      mov eax, 11 ; munmap
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

      jz bigint_zero_pages_exit
      jmp bigint_zero_pages

      bigint_zero_pages_exit:
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

          inc rsi
          cmp rsi, (_pagesize / 8)
          jne bigint_add_into_loop

        add r12, 8
        add r13, 8
        add r14, 8
        dec r15
        jnz bigint_add_into_page_loop

      ret

  end if

  if used fmt_bigint

    ; rax : source pointer, with sign
    ; rbx : write leading zeros
    ; rdx : amount of pages, cannot be zero
    ; rdi : pointer to buffer of size 1+rdx+
    ; returns the amount of characters written, in rax
    ; destroys : rax, rbx, rcx, rdx, rsi, rdi, r12, r13, r14
    fmt_bigint:
      mov r12, rax
      xor r13, r13

      mov rax, [r12]
      test eax, eax
      setnz al
      add al, al
      add al, '+'
      stosb
      inc r13

      lea r12, [r12 + 8 * rdx]

      fmt_bigint_page_loop:
        mov r14, [r12]
        mov esi, (_pagesize / 8)
        fmt_bigint_loop:
          dec esi
          mov rax, [r14 + 8 * rsi]

          test rax, rax
          setz cl
          test ebx, ebx
          setz ch
          and cl, ch
          cmovz ebx, ecx
          jnz fmt_bigint_loop

          call fmt_qword
          add r13, 64
          test esi, esi
          jnz fmt_bigint_loop

        sub r12, 8
        dec rdx
        jnz fmt_bigint_page_loop

      mov rax, r13
      ret

  end if

