
segment readable executable

  if used fmt_qword

    ; rax : qword to format
    ; rdi : pointer to buffer of size 64+
    ; destroys : rbx, rcx, rdi
    fmt_qword:
      mov ecx, 63
      fmt_qword_loop:
        bt rax, rcx
        setc bl
        add bl, '0'
        mov [rdi], bl
        inc rdi
        dec ecx
        jns fmt_qword_loop
      ret

  end if

