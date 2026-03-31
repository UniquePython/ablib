#ifndef AB_SYSCALL_H
#define AB_SYSCALL_H

#include "ab_types.h"

long ab_syscall0(long n);
long ab_syscall1(long n, long a1);
long ab_syscall2(long n, long a1, long a2);
long ab_syscall3(long n, long a1, long a2, long a3);
long ab_syscall4(long n, long a1, long a2, long a3, long a4);
long ab_syscall5(long n, long a1, long a2, long a3, long a4, long a5);
long ab_syscall6(long n, long a1, long a2, long a3, long a4, long a5, long a6);

#endif