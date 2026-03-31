#include "ab_syscall.h"

long ab_syscall0(long n)
{
    long ret;
    __asm__ volatile(
        "syscall\n"
        : "=a"(ret)
        : "0"(n)
        : "rcx", "r11", "memory");
    return ret;
}

long ab_syscall1(long n, long a1)
{
    long ret;
    __asm__ volatile(
        "syscall\n"
        : "=a"(ret)
        : "0"(n), "D"(a1)
        : "rcx", "r11", "memory");
    return ret;
}

long ab_syscall2(long n, long a1, long a2)
{
    long ret;
    __asm__ volatile(
        "syscall\n"
        : "=a"(ret)
        : "0"(n), "D"(a1), "S"(a2)
        : "rcx", "r11", "memory");
    return ret;
}

long ab_syscall3(long n, long a1, long a2, long a3)
{
    long ret;
    __asm__ volatile(
        "syscall\n"
        : "=a"(ret)
        : "0"(n), "D"(a1), "S"(a2), "d"(a3)
        : "rcx", "r11", "memory");
    return ret;
}

long ab_syscall4(long n, long a1, long a2, long a3, long a4)
{
    long ret;
    __asm__ volatile(
        "mov %[a4], %%r10\n"
        "syscall\n"
        : "=a"(ret)
        : "0"(n), "D"(a1), "S"(a2), "d"(a3), [a4] "r"(a4)
        : "rcx", "r11", "r10", "memory");
    return ret;
}

long ab_syscall5(long n, long a1, long a2, long a3, long a4, long a5)
{
    long ret;
    __asm__ volatile(
        "mov %[a4], %%r10\n"
        "mov %[a5], %%r8\n"
        "syscall\n"
        : "=a"(ret)
        : "0"(n), "D"(a1), "S"(a2), "d"(a3), [a4] "r"(a4), [a5] "r"(a5)
        : "rcx", "r11", "r10", "r8", "memory");
    return ret;
}

long ab_syscall6(long n, long a1, long a2, long a3, long a4, long a5, long a6)
{
    long ret;
    __asm__ volatile(
        "mov %[a4], %%r10\n"
        "mov %[a5], %%r8\n"
        "mov %[a6], %%r9\n"
        "syscall\n"
        : "=a"(ret)
        : "0"(n), "D"(a1), "S"(a2), "d"(a3), [a4] "r"(a4), [a5] "r"(a5), [a6] "r"(a6)
        : "rcx", "r11", "r10", "r8", "r9", "memory");
    return ret;
}
