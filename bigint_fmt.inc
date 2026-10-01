
  if used bigint_fmt_qword_bin

    ; rax : qword to format
    ; rdi : pointer to buffer of size 64+
    ; destroys : rbx, rcx, rdi (increments by 64)
    bigint_fmt_qword_bin:
      mov ecx, 63
      bigint_fmt_qword_bin_loop:
        bt rax, rcx
        setc bl
        add bl, '0'
        mov [rdi], bl
        inc rdi
        dec ecx
        jns bigint_fmt_qword_bin_loop
      ret

  end if

  if used bigint_fmt_qword_bin_map

    ; rax : qword to format
    ; rbx : value of character for bits 0
    ; rcx : value of character for bits 1
    ; rdi : pointer to buffer of size 64+
    ; destroys : rdx, rsi, rdi (increments by 64)
    bigint_fmt_qword_bin_map:
      mov rdx, 63
      bigint_fmt_qword_bin_map_loop:
        mov rsi, rbx
        bt rax, rdx
        cmovc rsi, rcx
        mov [rdi], sil
        inc rdi
        dec edx
        jns bigint_fmt_qword_bin_map_loop
      ret

  end if

  if used bigint_fmt_bin

    ; rax : source pointer, with sign
    ; rbx : write leading zeros
    ; rdx : amount of pages, cannot be zero
    ; rdi : pointer to buffer of size 2+rdx+
    ; returns the amount of characters written, in rax
    ; destroys : rax, rbx, rcx, rdx, rsi, rdi (increments by the amount of characters written), r12, r13, r14, r15
    bigint_fmt_bin:
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
      bigint_fmt_bin_page_loop:
        mov r14, [r12]

        test ebx, ebx
        jnz bigint_fmt_bin_loop
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

        bigint_fmt_bin_loop:
          dec esi
          js bigint_fmt_bin_loop_end
          mov rax, [r14 + 8 * rsi]

          xor ecx, ecx
          or rcx, rax
          or ecx, ebx
          jz bigint_fmt_bin_loop

          call bigint_fmt_qword_bin
          add r13, 64
          mov rbx, r13 ; nonzero
          test esi, esi
          jnz bigint_fmt_bin_loop

        bigint_fmt_bin_loop_end:

        sub r12, 8
        dec rdx
        jnz bigint_fmt_bin_page_loop

      xor eax, eax
      test r13, r13
      setz al
      inc eax
      add r13, rax

      bigint_fmt_bin_ret:
      mov rax, r13
      ret

  end if

  if used bigint_fmt_qword_hex

    segment readable

      bigint_fmt_qword_hex_hexdigits db "0123456789abcdef"

    segment readable executable

    ; rax : qword to format
    ; rdi : pointer to buffer of size 64+
    ; destroys : rax, rbx, rcx, rdi (increments by 16)
    bigint_fmt_qword_hex:
      mov ecx, 15
      bigint_fmt_qword_hex_loop:
        mov rbx, rax
        shr rbx, 60
        mov bl, [bigint_fmt_qword_hex_hexdigits + rbx]
        mov [rdi], bl
        shl rax, 4
        inc rdi
        dec ecx
        jns bigint_fmt_qword_hex_loop
      ret

  end if

  if used bigint_fmt_qword_HEX

    segment readable

      bigint_fmt_qword_HEX_HEXdigits db "0123456789ABCDEF"

    segment readable executable

    ; rax : qword to format
    ; rdi : pointer to buffer of size 64+
    ; destroys : rax, rbx, rcx, rdi (increments by 16)
    bigint_fmt_qword_HEX:
      mov ecx, 15
      bigint_fmt_qword_HEX_loop:
        mov rbx, rax
        shr rbx, 60
        mov bl, [bigint_fmt_qword_HEX_HEXdigits + rbx]
        mov [rdi], bl
        shl rax, 4
        inc rdi
        dec ecx
        jns bigint_fmt_qword_HEX_loop
      ret

  end if

  if used bigint_fmt_hex

    ; rax : source pointer, with sign
    ; rbx : write leading zeros
    ; rdx : amount of pages, cannot be zero
    ; rdi : pointer to buffer of size 2+rdx+
    ; returns the amount of characters written, in rax
    ; destroys : rax, rbx, rcx, rdx, rsi, rdi (increments by the amount of characters written), r12, r13, r14, r15
    bigint_fmt_hex:
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
      bigint_fmt_hex_page_loop:
        mov r14, [r12]

        test ebx, ebx
        jnz bigint_fmt_hex_loop
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

        bigint_fmt_hex_loop:
          dec esi
          js bigint_fmt_hex_loop_end
          mov rax, [r14 + 8 * rsi]

          xor ecx, ecx
          or rcx, rax
          or ecx, ebx
          jz bigint_fmt_hex_loop

          call bigint_fmt_qword_hex
          add r13, 64
          mov rbx, r13 ; nonzero
          test esi, esi
          jnz bigint_fmt_hex_loop

        bigint_fmt_hex_loop_end:

        sub r12, 8
        dec rdx
        jnz bigint_fmt_hex_page_loop

      xor eax, eax
      test r13, r13
      setz al
      inc eax
      add r13, rax

      bigint_fmt_hex_ret:
      mov rax, r13
      ret

  end if

  if used bigint_fmt_HEX

    ; rax : source pointer, with sign
    ; rbx : write leading zeros
    ; rdx : amount of pages, cannot be zero
    ; rdi : pointer to buffer of size 2+rdx+
    ; returns the amount of characters written, in rax
    ; destroys : rax, rbx, rcx, rdx, rsi, rdi (increments by the amount of characters written), r12, r13, r14, r15
    bigint_fmt_HEX:
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
      bigint_fmt_HEX_page_loop:
        mov r14, [r12]

        test ebx, ebx
        jnz bigint_fmt_HEX_loop
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

        bigint_fmt_HEX_loop:
          dec esi
          js bigint_fmt_HEX_loop_end
          mov rax, [r14 + 8 * rsi]

          xor ecx, ecx
          or rcx, rax
          or ecx, ebx
          jz bigint_fmt_HEX_loop

          call bigint_fmt_qword_HEX
          add r13, 64
          mov rbx, r13 ; nonzero
          test esi, esi
          jnz bigint_fmt_HEX_loop

        bigint_fmt_HEX_loop_end:

        sub r12, 8
        dec rdx
        jnz bigint_fmt_HEX_page_loop

      xor eax, eax
      test r13, r13
      setz al
      inc eax
      add r13, rax

      bigint_fmt_HEX_ret:
      mov rax, r13
      ret

  end if

