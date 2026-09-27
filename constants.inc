
if ~ definite _pagesize
  _pagesize = 4096 ; 4 KB
end if

if ~ definite __NR_read
  __NR_read = 0
end if

if ~ definite __NR_write
  __NR_write = 1
end if

if ~ definite __NR_open
  __NR_open = 2
end if

if ~ definite __NR_close
  __NR_close = 3
end if

if ~ definite __NR_stat
  __NR_stat = 4
end if

if ~ definite __NR_fstat
  __NR_fstat = 5
end if

if ~ definite __NR_lstat
  __NR_lstat = 6
end if

if ~ definite __NR_poll
  __NR_poll = 7
end if

if ~ definite __NR_lseek
  __NR_lseek = 8
end if

if ~ definite __NR_mmap
  __NR_mmap = 9
end if

if ~ definite __NR_mprotect
  __NR_mprotect = 10
end if

if ~ definite __NR_munmap
  __NR_munmap = 11
end if

if ~ definite __NR_brk
  __NR_brk = 12
end if

if ~ definite __NR_rt_sigaction
  __NR_rt_sigaction = 13
end if

if ~ definite __NR_rt_sigprocmask
  __NR_rt_sigprocmask = 14
end if

if ~ definite __NR_rt_sigreturn
  __NR_rt_sigreturn = 15
end if

if ~ definite __NR_ioctl
  __NR_ioctl = 16
end if

if ~ definite __NR_pread64
  __NR_pread64 = 17
end if

if ~ definite __NR_pwrite64
  __NR_pwrite64 = 18
end if

if ~ definite __NR_readv
  __NR_readv = 19
end if

if ~ definite __NR_writev
  __NR_writev = 20
end if

if ~ definite __NR_access
  __NR_access = 21
end if

if ~ definite __NR_pipe
  __NR_pipe = 22
end if

if ~ definite __NR_select
  __NR_select = 23
end if

if ~ definite __NR_sched_yield
  __NR_sched_yield = 24
end if

if ~ definite __NR_mremap
  __NR_mremap = 25
end if

if ~ definite __NR_msync
  __NR_msync = 26
end if

if ~ definite __NR_mincore
  __NR_mincore = 27
end if

if ~ definite __NR_madvise
  __NR_madvise = 28
end if

if ~ definite __NR_shmget
  __NR_shmget = 29
end if

if ~ definite __NR_shmat
  __NR_shmat = 30
end if

if ~ definite __NR_shmctl
  __NR_shmctl = 31
end if

if ~ definite __NR_dup
  __NR_dup = 32
end if

if ~ definite __NR_dup2
  __NR_dup2 = 33
end if

if ~ definite __NR_pause
  __NR_pause = 34
end if

if ~ definite __NR_nanosleep
  __NR_nanosleep = 35
end if

if ~ definite __NR_getitimer
  __NR_getitimer = 36
end if

if ~ definite __NR_alarm
  __NR_alarm = 37
end if

if ~ definite __NR_setitimer
  __NR_setitimer = 38
end if

if ~ definite __NR_getpid
  __NR_getpid = 39
end if

if ~ definite __NR_sendfile
  __NR_sendfile = 40
end if

if ~ definite __NR_socket
  __NR_socket = 41
end if

if ~ definite __NR_connect
  __NR_connect = 42
end if

if ~ definite __NR_accept
  __NR_accept = 43
end if

if ~ definite __NR_sendto
  __NR_sendto = 44
end if

if ~ definite __NR_recvfrom
  __NR_recvfrom = 45
end if

if ~ definite __NR_sendmsg
  __NR_sendmsg = 46
end if

if ~ definite __NR_recvmsg
  __NR_recvmsg = 47
end if

if ~ definite __NR_shutdown
  __NR_shutdown = 48
end if

if ~ definite __NR_bind
  __NR_bind = 49
end if

if ~ definite __NR_listen
  __NR_listen = 50
end if

if ~ definite __NR_getsockname
  __NR_getsockname = 51
end if

if ~ definite __NR_getpeername
  __NR_getpeername = 52
end if

if ~ definite __NR_socketpair
  __NR_socketpair = 53
end if

if ~ definite __NR_setsockopt
  __NR_setsockopt = 54
end if

if ~ definite __NR_getsockopt
  __NR_getsockopt = 55
end if

if ~ definite __NR_clone
  __NR_clone = 56
end if

if ~ definite __NR_fork
  __NR_fork = 57
end if

if ~ definite __NR_vfork
  __NR_vfork = 58
end if

if ~ definite __NR_execve
  __NR_execve = 59
end if

if ~ definite __NR_exit
  __NR_exit = 60
end if

if ~ definite __NR_wait4
  __NR_wait4 = 61
end if

if ~ definite __NR_kill
  __NR_kill = 62
end if

if ~ definite __NR_uname
  __NR_uname = 63
end if

if ~ definite __NR_semget
  __NR_semget = 64
end if

if ~ definite __NR_semop
  __NR_semop = 65
end if

if ~ definite __NR_semctl
  __NR_semctl = 66
end if

if ~ definite __NR_shmdt
  __NR_shmdt = 67
end if

if ~ definite __NR_msgget
  __NR_msgget = 68
end if

if ~ definite __NR_msgsnd
  __NR_msgsnd = 69
end if

if ~ definite __NR_msgrcv
  __NR_msgrcv = 70
end if

if ~ definite __NR_msgctl
  __NR_msgctl = 71
end if

if ~ definite __NR_fcntl
  __NR_fcntl = 72
end if

if ~ definite __NR_flock
  __NR_flock = 73
end if

if ~ definite __NR_fsync
  __NR_fsync = 74
end if

if ~ definite __NR_fdatasync
  __NR_fdatasync = 75
end if

if ~ definite __NR_truncate
  __NR_truncate = 76
end if

if ~ definite __NR_ftruncate
  __NR_ftruncate = 77
end if

if ~ definite __NR_getdents
  __NR_getdents = 78
end if

if ~ definite __NR_getcwd
  __NR_getcwd = 79
end if

if ~ definite __NR_chdir
  __NR_chdir = 80
end if

if ~ definite __NR_fchdir
  __NR_fchdir = 81
end if

if ~ definite __NR_rename
  __NR_rename = 82
end if

if ~ definite __NR_mkdir
  __NR_mkdir = 83
end if

if ~ definite __NR_rmdir
  __NR_rmdir = 84
end if

if ~ definite __NR_creat
  __NR_creat = 85
end if

if ~ definite __NR_link
  __NR_link = 86
end if

if ~ definite __NR_unlink
  __NR_unlink = 87
end if

if ~ definite __NR_symlink
  __NR_symlink = 88
end if

if ~ definite __NR_readlink
  __NR_readlink = 89
end if

if ~ definite __NR_chmod
  __NR_chmod = 90
end if

if ~ definite __NR_fchmod
  __NR_fchmod = 91
end if

if ~ definite __NR_chown
  __NR_chown = 92
end if

if ~ definite __NR_fchown
  __NR_fchown = 93
end if

if ~ definite __NR_lchown
  __NR_lchown = 94
end if

if ~ definite __NR_umask
  __NR_umask = 95
end if

if ~ definite __NR_gettimeofday
  __NR_gettimeofday = 96
end if

if ~ definite __NR_getrlimit
  __NR_getrlimit = 97
end if

if ~ definite __NR_getrusage
  __NR_getrusage = 98
end if

if ~ definite __NR_sysinfo
  __NR_sysinfo = 99
end if

if ~ definite __NR_times
  __NR_times = 100
end if

if ~ definite __NR_ptrace
  __NR_ptrace = 101
end if

if ~ definite __NR_getuid
  __NR_getuid = 102
end if

if ~ definite __NR_syslog
  __NR_syslog = 103
end if

if ~ definite __NR_getgid
  __NR_getgid = 104
end if

if ~ definite __NR_setuid
  __NR_setuid = 105
end if

if ~ definite __NR_setgid
  __NR_setgid = 106
end if

if ~ definite __NR_geteuid
  __NR_geteuid = 107
end if

if ~ definite __NR_getegid
  __NR_getegid = 108
end if

if ~ definite __NR_setpgid
  __NR_setpgid = 109
end if

if ~ definite __NR_getppid
  __NR_getppid = 110
end if

if ~ definite __NR_getpgrp
  __NR_getpgrp = 111
end if

if ~ definite __NR_setsid
  __NR_setsid = 112
end if

if ~ definite __NR_setreuid
  __NR_setreuid = 113
end if

if ~ definite __NR_setregid
  __NR_setregid = 114
end if

if ~ definite __NR_getgroups
  __NR_getgroups = 115
end if

if ~ definite __NR_setgroups
  __NR_setgroups = 116
end if

if ~ definite __NR_setresuid
  __NR_setresuid = 117
end if

if ~ definite __NR_getresuid
  __NR_getresuid = 118
end if

if ~ definite __NR_setresgid
  __NR_setresgid = 119
end if

if ~ definite __NR_getresgid
  __NR_getresgid = 120
end if

if ~ definite __NR_getpgid
  __NR_getpgid = 121
end if

if ~ definite __NR_setfsuid
  __NR_setfsuid = 122
end if

if ~ definite __NR_setfsgid
  __NR_setfsgid = 123
end if

if ~ definite __NR_getsid
  __NR_getsid = 124
end if

if ~ definite __NR_capget
  __NR_capget = 125
end if

if ~ definite __NR_capset
  __NR_capset = 126
end if

if ~ definite __NR_rt_sigpending
  __NR_rt_sigpending = 127
end if

if ~ definite __NR_rt_sigtimedwait
  __NR_rt_sigtimedwait = 128
end if

if ~ definite __NR_rt_sigqueueinfo
  __NR_rt_sigqueueinfo = 129
end if

if ~ definite __NR_rt_sigsuspend
  __NR_rt_sigsuspend = 130
end if

if ~ definite __NR_sigaltstack
  __NR_sigaltstack = 131
end if

if ~ definite __NR_utime
  __NR_utime = 132
end if

if ~ definite __NR_mknod
  __NR_mknod = 133
end if

if ~ definite __NR_uselib
  __NR_uselib = 134
end if

if ~ definite __NR_personality
  __NR_personality = 135
end if

if ~ definite __NR_ustat
  __NR_ustat = 136
end if

if ~ definite __NR_statfs
  __NR_statfs = 137
end if

if ~ definite __NR_fstatfs
  __NR_fstatfs = 138
end if

if ~ definite __NR_sysfs
  __NR_sysfs = 139
end if

if ~ definite __NR_getpriority
  __NR_getpriority = 140
end if

if ~ definite __NR_setpriority
  __NR_setpriority = 141
end if

if ~ definite __NR_sched_setparam
  __NR_sched_setparam = 142
end if

if ~ definite __NR_sched_getparam
  __NR_sched_getparam = 143
end if

if ~ definite __NR_sched_setscheduler
  __NR_sched_setscheduler = 144
end if

if ~ definite __NR_sched_getscheduler
  __NR_sched_getscheduler = 145
end if

if ~ definite __NR_sched_get_priority_max
  __NR_sched_get_priority_max = 146
end if

if ~ definite __NR_sched_get_priority_min
  __NR_sched_get_priority_min = 147
end if

if ~ definite __NR_sched_rr_get_interval
  __NR_sched_rr_get_interval = 148
end if

if ~ definite __NR_mlock
  __NR_mlock = 149
end if

if ~ definite __NR_munlock
  __NR_munlock = 150
end if

if ~ definite __NR_mlockall
  __NR_mlockall = 151
end if

if ~ definite __NR_munlockall
  __NR_munlockall = 152
end if

if ~ definite __NR_vhangup
  __NR_vhangup = 153
end if

if ~ definite __NR_modify_ldt
  __NR_modify_ldt = 154
end if

if ~ definite __NR_pivot_root
  __NR_pivot_root = 155
end if

if ~ definite __NR__sysctl
  __NR__sysctl = 156
end if

if ~ definite __NR_prctl
  __NR_prctl = 157
end if

if ~ definite __NR_arch_prctl
  __NR_arch_prctl = 158
end if

if ~ definite __NR_adjtimex
  __NR_adjtimex = 159
end if

if ~ definite __NR_setrlimit
  __NR_setrlimit = 160
end if

if ~ definite __NR_chroot
  __NR_chroot = 161
end if

if ~ definite __NR_sync
  __NR_sync = 162
end if

if ~ definite __NR_acct
  __NR_acct = 163
end if

if ~ definite __NR_settimeofday
  __NR_settimeofday = 164
end if

if ~ definite __NR_mount
  __NR_mount = 165
end if

if ~ definite __NR_umount2
  __NR_umount2 = 166
end if

if ~ definite __NR_swapon
  __NR_swapon = 167
end if

if ~ definite __NR_swapoff
  __NR_swapoff = 168
end if

if ~ definite __NR_reboot
  __NR_reboot = 169
end if

if ~ definite __NR_sethostname
  __NR_sethostname = 170
end if

if ~ definite __NR_setdomainname
  __NR_setdomainname = 171
end if

if ~ definite __NR_iopl
  __NR_iopl = 172
end if

if ~ definite __NR_ioperm
  __NR_ioperm = 173
end if

if ~ definite __NR_create_module
  __NR_create_module = 174
end if

if ~ definite __NR_init_module
  __NR_init_module = 175
end if

if ~ definite __NR_delete_module
  __NR_delete_module = 176
end if

if ~ definite __NR_get_kernel_syms
  __NR_get_kernel_syms = 177
end if

if ~ definite __NR_query_module
  __NR_query_module = 178
end if

if ~ definite __NR_quotactl
  __NR_quotactl = 179
end if

if ~ definite __NR_nfsservctl
  __NR_nfsservctl = 180
end if

if ~ definite __NR_getpmsg
  __NR_getpmsg = 181
end if

if ~ definite __NR_putpmsg
  __NR_putpmsg = 182
end if

if ~ definite __NR_afs_syscall
  __NR_afs_syscall = 183
end if

if ~ definite __NR_tuxcall
  __NR_tuxcall = 184
end if

if ~ definite __NR_security
  __NR_security = 185
end if

if ~ definite __NR_gettid
  __NR_gettid = 186
end if

if ~ definite __NR_readahead
  __NR_readahead = 187
end if

if ~ definite __NR_setxattr
  __NR_setxattr = 188
end if

if ~ definite __NR_lsetxattr
  __NR_lsetxattr = 189
end if

if ~ definite __NR_fsetxattr
  __NR_fsetxattr = 190
end if

if ~ definite __NR_getxattr
  __NR_getxattr = 191
end if

if ~ definite __NR_lgetxattr
  __NR_lgetxattr = 192
end if

if ~ definite __NR_fgetxattr
  __NR_fgetxattr = 193
end if

if ~ definite __NR_listxattr
  __NR_listxattr = 194
end if

if ~ definite __NR_llistxattr
  __NR_llistxattr = 195
end if

if ~ definite __NR_flistxattr
  __NR_flistxattr = 196
end if

if ~ definite __NR_removexattr
  __NR_removexattr = 197
end if

if ~ definite __NR_lremovexattr
  __NR_lremovexattr = 198
end if

if ~ definite __NR_fremovexattr
  __NR_fremovexattr = 199
end if

if ~ definite __NR_tkill
  __NR_tkill = 200
end if

if ~ definite __NR_time
  __NR_time = 201
end if

if ~ definite __NR_futex
  __NR_futex = 202
end if

if ~ definite __NR_sched_setaffinity
  __NR_sched_setaffinity = 203
end if

if ~ definite __NR_sched_getaffinity
  __NR_sched_getaffinity = 204
end if

if ~ definite __NR_set_thread_area
  __NR_set_thread_area = 205
end if

if ~ definite __NR_io_setup
  __NR_io_setup = 206
end if

if ~ definite __NR_io_destroy
  __NR_io_destroy = 207
end if

if ~ definite __NR_io_getevents
  __NR_io_getevents = 208
end if

if ~ definite __NR_io_submit
  __NR_io_submit = 209
end if

if ~ definite __NR_io_cancel
  __NR_io_cancel = 210
end if

if ~ definite __NR_get_thread_area
  __NR_get_thread_area = 211
end if

if ~ definite __NR_lookup_dcookie
  __NR_lookup_dcookie = 212
end if

if ~ definite __NR_epoll_create
  __NR_epoll_create = 213
end if

if ~ definite __NR_epoll_ctl_old
  __NR_epoll_ctl_old = 214
end if

if ~ definite __NR_epoll_wait_old
  __NR_epoll_wait_old = 215
end if

if ~ definite __NR_remap_file_pages
  __NR_remap_file_pages = 216
end if

if ~ definite __NR_getdents64
  __NR_getdents64 = 217
end if

if ~ definite __NR_set_tid_address
  __NR_set_tid_address = 218
end if

if ~ definite __NR_restart_syscall
  __NR_restart_syscall = 219
end if

if ~ definite __NR_semtimedop
  __NR_semtimedop = 220
end if

if ~ definite __NR_fadvise64
  __NR_fadvise64 = 221
end if

if ~ definite __NR_timer_create
  __NR_timer_create = 222
end if

if ~ definite __NR_timer_settime
  __NR_timer_settime = 223
end if

if ~ definite __NR_timer_gettime
  __NR_timer_gettime = 224
end if

if ~ definite __NR_timer_getoverrun
  __NR_timer_getoverrun = 225
end if

if ~ definite __NR_timer_delete
  __NR_timer_delete = 226
end if

if ~ definite __NR_clock_settime
  __NR_clock_settime = 227
end if

if ~ definite __NR_clock_gettime
  __NR_clock_gettime = 228
end if

if ~ definite __NR_clock_getres
  __NR_clock_getres = 229
end if

if ~ definite __NR_clock_nanosleep
  __NR_clock_nanosleep = 230
end if

if ~ definite __NR_exit_group
  __NR_exit_group = 231
end if

if ~ definite __NR_epoll_wait
  __NR_epoll_wait = 232
end if

if ~ definite __NR_epoll_ctl
  __NR_epoll_ctl = 233
end if

if ~ definite __NR_tgkill
  __NR_tgkill = 234
end if

if ~ definite __NR_utimes
  __NR_utimes = 235
end if

if ~ definite __NR_vserver
  __NR_vserver = 236
end if

if ~ definite __NR_mbind
  __NR_mbind = 237
end if

if ~ definite __NR_set_mempolicy
  __NR_set_mempolicy = 238
end if

if ~ definite __NR_get_mempolicy
  __NR_get_mempolicy = 239
end if

if ~ definite __NR_mq_open
  __NR_mq_open = 240
end if

if ~ definite __NR_mq_unlink
  __NR_mq_unlink = 241
end if

if ~ definite __NR_mq_timedsend
  __NR_mq_timedsend = 242
end if

if ~ definite __NR_mq_timedreceive
  __NR_mq_timedreceive = 243
end if

if ~ definite __NR_mq_notify
  __NR_mq_notify = 244
end if

if ~ definite __NR_mq_getsetattr
  __NR_mq_getsetattr = 245
end if

if ~ definite __NR_kexec_load
  __NR_kexec_load = 246
end if

if ~ definite __NR_waitid
  __NR_waitid = 247
end if

if ~ definite __NR_add_key
  __NR_add_key = 248
end if

if ~ definite __NR_request_key
  __NR_request_key = 249
end if

if ~ definite __NR_keyctl
  __NR_keyctl = 250
end if

if ~ definite __NR_ioprio_set
  __NR_ioprio_set = 251
end if

if ~ definite __NR_ioprio_get
  __NR_ioprio_get = 252
end if

if ~ definite __NR_inotify_init
  __NR_inotify_init = 253
end if

if ~ definite __NR_inotify_add_watch
  __NR_inotify_add_watch = 254
end if

if ~ definite __NR_inotify_rm_watch
  __NR_inotify_rm_watch = 255
end if

if ~ definite __NR_migrate_pages
  __NR_migrate_pages = 256
end if

if ~ definite __NR_openat
  __NR_openat = 257
end if

if ~ definite __NR_mkdirat
  __NR_mkdirat = 258
end if

if ~ definite __NR_mknodat
  __NR_mknodat = 259
end if

if ~ definite __NR_fchownat
  __NR_fchownat = 260
end if

if ~ definite __NR_futimesat
  __NR_futimesat = 261
end if

if ~ definite __NR_newfstatat
  __NR_newfstatat = 262
end if

if ~ definite __NR_unlinkat
  __NR_unlinkat = 263
end if

if ~ definite __NR_renameat
  __NR_renameat = 264
end if

if ~ definite __NR_linkat
  __NR_linkat = 265
end if

if ~ definite __NR_symlinkat
  __NR_symlinkat = 266
end if

if ~ definite __NR_readlinkat
  __NR_readlinkat = 267
end if

if ~ definite __NR_fchmodat
  __NR_fchmodat = 268
end if

if ~ definite __NR_faccessat
  __NR_faccessat = 269
end if

if ~ definite __NR_pselect6
  __NR_pselect6 = 270
end if

if ~ definite __NR_ppoll
  __NR_ppoll = 271
end if

if ~ definite __NR_unshare
  __NR_unshare = 272
end if

if ~ definite __NR_set_robust_list
  __NR_set_robust_list = 273
end if

if ~ definite __NR_get_robust_list
  __NR_get_robust_list = 274
end if

if ~ definite __NR_splice
  __NR_splice = 275
end if

if ~ definite __NR_tee
  __NR_tee = 276
end if

if ~ definite __NR_sync_file_range
  __NR_sync_file_range = 277
end if

if ~ definite __NR_vmsplice
  __NR_vmsplice = 278
end if

if ~ definite __NR_move_pages
  __NR_move_pages = 279
end if

if ~ definite __NR_utimensat
  __NR_utimensat = 280
end if

if ~ definite __NR_epoll_pwait
  __NR_epoll_pwait = 281
end if

if ~ definite __NR_signalfd
  __NR_signalfd = 282
end if

if ~ definite __NR_timerfd_create
  __NR_timerfd_create = 283
end if

if ~ definite __NR_eventfd
  __NR_eventfd = 284
end if

if ~ definite __NR_fallocate
  __NR_fallocate = 285
end if

if ~ definite __NR_timerfd_settime
  __NR_timerfd_settime = 286
end if

if ~ definite __NR_timerfd_gettime
  __NR_timerfd_gettime = 287
end if

if ~ definite __NR_accept4
  __NR_accept4 = 288
end if

if ~ definite __NR_signalfd4
  __NR_signalfd4 = 289
end if

if ~ definite __NR_eventfd2
  __NR_eventfd2 = 290
end if

if ~ definite __NR_epoll_create1
  __NR_epoll_create1 = 291
end if

if ~ definite __NR_dup3
  __NR_dup3 = 292
end if

if ~ definite __NR_pipe2
  __NR_pipe2 = 293
end if

if ~ definite __NR_inotify_init1
  __NR_inotify_init1 = 294
end if

if ~ definite __NR_preadv
  __NR_preadv = 295
end if

if ~ definite __NR_pwritev
  __NR_pwritev = 296
end if

if ~ definite __NR_rt_tgsigqueueinfo
  __NR_rt_tgsigqueueinfo = 297
end if

if ~ definite __NR_perf_event_open
  __NR_perf_event_open = 298
end if

if ~ definite __NR_recvmmsg
  __NR_recvmmsg = 299
end if

if ~ definite __NR_fanotify_init
  __NR_fanotify_init = 300
end if

if ~ definite __NR_fanotify_mark
  __NR_fanotify_mark = 301
end if

if ~ definite __NR_prlimit64
  __NR_prlimit64 = 302
end if

if ~ definite __NR_name_to_handle_at
  __NR_name_to_handle_at = 303
end if

if ~ definite __NR_open_by_handle_at
  __NR_open_by_handle_at = 304
end if

if ~ definite __NR_clock_adjtime
  __NR_clock_adjtime = 305
end if

if ~ definite __NR_syncfs
  __NR_syncfs = 306
end if

if ~ definite __NR_sendmmsg
  __NR_sendmmsg = 307
end if

if ~ definite __NR_setns
  __NR_setns = 308
end if

if ~ definite __NR_getcpu
  __NR_getcpu = 309
end if

if ~ definite __NR_process_vm_readv
  __NR_process_vm_readv = 310
end if

if ~ definite __NR_process_vm_writev
  __NR_process_vm_writev = 311
end if

if ~ definite __NR_kcmp
  __NR_kcmp = 312
end if

if ~ definite __NR_finit_module
  __NR_finit_module = 313
end if

if ~ definite __NR_sched_setattr
  __NR_sched_setattr = 314
end if

if ~ definite __NR_sched_getattr
  __NR_sched_getattr = 315
end if

if ~ definite __NR_renameat2
  __NR_renameat2 = 316
end if

if ~ definite __NR_seccomp
  __NR_seccomp = 317
end if

if ~ definite __NR_getrandom
  __NR_getrandom = 318
end if

if ~ definite __NR_memfd_create
  __NR_memfd_create = 319
end if

if ~ definite __NR_kexec_file_load
  __NR_kexec_file_load = 320
end if

if ~ definite __NR_bpf
  __NR_bpf = 321
end if

if ~ definite __NR_execveat
  __NR_execveat = 322
end if

if ~ definite __NR_userfaultfd
  __NR_userfaultfd = 323
end if

if ~ definite __NR_membarrier
  __NR_membarrier = 324
end if

if ~ definite __NR_mlock2
  __NR_mlock2 = 325
end if

if ~ definite __NR_copy_file_range
  __NR_copy_file_range = 326
end if

if ~ definite __NR_preadv2
  __NR_preadv2 = 327
end if

if ~ definite __NR_pwritev2
  __NR_pwritev2 = 328
end if

if ~ definite __NR_pkey_mprotect
  __NR_pkey_mprotect = 329
end if

if ~ definite __NR_pkey_alloc
  __NR_pkey_alloc = 330
end if

if ~ definite __NR_pkey_free
  __NR_pkey_free = 331
end if

if ~ definite __NR_statx
  __NR_statx = 332
end if

if ~ definite __NR_io_pgetevents
  __NR_io_pgetevents = 333
end if

if ~ definite __NR_rseq
  __NR_rseq = 334
end if

if ~ definite __NR_pidfd_send_signal
  __NR_pidfd_send_signal = 424
end if

if ~ definite __NR_io_uring_setup
  __NR_io_uring_setup = 425
end if

if ~ definite __NR_io_uring_enter
  __NR_io_uring_enter = 426
end if

if ~ definite __NR_io_uring_register
  __NR_io_uring_register = 427
end if

if ~ definite __NR_open_tree
  __NR_open_tree = 428
end if

if ~ definite __NR_move_mount
  __NR_move_mount = 429
end if

if ~ definite __NR_fsopen
  __NR_fsopen = 430
end if

if ~ definite __NR_fsconfig
  __NR_fsconfig = 431
end if

if ~ definite __NR_fsmount
  __NR_fsmount = 432
end if

if ~ definite __NR_fspick
  __NR_fspick = 433
end if

if ~ definite __NR_pidfd_open
  __NR_pidfd_open = 434
end if

if ~ definite __NR_clone3
  __NR_clone3 = 435
end if

if ~ definite __NR_close_range
  __NR_close_range = 436
end if

if ~ definite __NR_openat2
  __NR_openat2 = 437
end if

if ~ definite __NR_pidfd_getfd
  __NR_pidfd_getfd = 438
end if

if ~ definite __NR_faccessat2
  __NR_faccessat2 = 439
end if

if ~ definite __NR_process_madvise
  __NR_process_madvise = 440
end if

if ~ definite __NR_epoll_pwait2
  __NR_epoll_pwait2 = 441
end if

if ~ definite __NR_mount_setattr
  __NR_mount_setattr = 442
end if

if ~ definite __NR_quotactl_fd
  __NR_quotactl_fd = 443
end if

if ~ definite __NR_landlock_create_ruleset
  __NR_landlock_create_ruleset = 444
end if

if ~ definite __NR_landlock_add_rule
  __NR_landlock_add_rule = 445
end if

if ~ definite __NR_landlock_restrict_self
  __NR_landlock_restrict_self = 446
end if

if ~ definite __NR_memfd_secret
  __NR_memfd_secret = 447
end if

if ~ definite __NR_process_mrelease
  __NR_process_mrelease = 448
end if

if ~ definite __NR_futex_waitv
  __NR_futex_waitv = 449
end if

if ~ definite __NR_set_mempolicy_home_node
  __NR_set_mempolicy_home_node = 450
end if

if ~ definite __NR_cachestat
  __NR_cachestat = 451
end if

if ~ definite __NR_fchmodat2
  __NR_fchmodat2 = 452
end if

if ~ definite __NR_map_shadow_stack
  __NR_map_shadow_stack = 453
end if

if ~ definite __NR_futex_wake
  __NR_futex_wake = 454
end if

if ~ definite __NR_futex_wait
  __NR_futex_wait = 455
end if

if ~ definite __NR_futex_requeue
  __NR_futex_requeue = 456
end if

if ~ definite __NR_statmount
  __NR_statmount = 457
end if

if ~ definite __NR_listmount
  __NR_listmount = 458
end if

if ~ definite __NR_lsm_get_self_attr
  __NR_lsm_get_self_attr = 459
end if

if ~ definite __NR_lsm_set_self_attr
  __NR_lsm_set_self_attr = 460
end if

if ~ definite __NR_lsm_list_modules
  __NR_lsm_list_modules = 461
end if

if ~ definite STDIN_FILENO
  STDIN_FILENO = 0
end if

if ~ definite STDOUT_FILENO
  STDOUT_FILENO = 1
end if

if ~ definite STDERR_FILENO
  STDERR_FILENO = 2
end if

if ~ definite SEEK_SET
  SEEK_SET = 0
end if

if ~ definite SEEK_CUR
  SEEK_CUR = 1
end if

if ~ definite SEEK_END
  SEEK_END = 2
end if

if ~ definite PROT_READ
  PROT_READ = 0x1
end if

if ~ definite PROT_WRITE
  PROT_WRITE = 0x2
end if

if ~ definite PROT_EXEC
  PROT_EXEC = 0x4
end if

if ~ definite PROT_SEM
  PROT_SEM = 0x8
end if

if ~ definite PROT_NONE
  PROT_NONE = 0x0
end if

if ~ definite PROT_GROWSDOWN
  PROT_GROWSDOWN = 0x01000000
end if

if ~ definite PROT_GROWSUP
  PROT_GROWSUP = 0x02000000
end if

if ~ definite MAP_TYPE
  MAP_TYPE = 0x0f
end if

if ~ definite MAP_FIXED
  MAP_FIXED = 0x10
end if

if ~ definite MAP_ANONYMOUS
  MAP_ANONYMOUS = 0x20
end if

if ~ definite MAP_POPULATE
  MAP_POPULATE = 0x008000
end if

if ~ definite MAP_NONBLOCK
  MAP_NONBLOCK = 0x010000
end if

if ~ definite MAP_STACK
  MAP_STACK = 0x020000
end if

if ~ definite MAP_HUGETLB
  MAP_HUGETLB = 0x040000
end if

if ~ definite MAP_SYNC
  MAP_SYNC = 0x080000
end if

if ~ definite MAP_FIXED_NOREPLACE
  MAP_FIXED_NOREPLACE = 0x100000
end if

if ~ definite MAP_UNINITIALIZED
  MAP_UNINITIALIZED = 0x4000000
end if

if ~ definite MAP_SHARED
  MAP_SHARED = 0x01
end if

if ~ definite MAP_PRIVATE
  MAP_PRIVATE = 0x02
end if

if ~ definite MAP_SHARED_VALIDATE
  MAP_SHARED_VALIDATE = 0x03
end if

