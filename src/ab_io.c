#include "ab_io.h"
#include "ab_syscall.h"
#include "ab_syscall_nums.h"

long ab_read(int fd, void * buf, size_t n)
{
    return (long)ab_syscall3(SYS_read, (long)fd, (long)(uintptr_t)buf, (long)n);
}

long ab_write(int fd, const void * buf, size_t n)
{
    return (long)ab_syscall3(SYS_write, (long)fd, (long)(uintptr_t)buf, (long)n);
}

long ab_open(const char * path, int flags, int mode)
{
    return (long)ab_syscall3(SYS_open, (long)(uintptr_t)path, (long)flags, (long)mode);
}

long ab_close(int fd)
{
    return (long)ab_syscall1(SYS_close, (long)fd);
}

long ab_lseek(int fd, long offset, int whence)
{
    return (long)ab_syscall3(SYS_lseek, (long)fd, (long)offset, (long)whence);
}

void *ab_mmap(void * addr, size_t len, int prot, int flags, int fd, long off)
{
    return (void *)ab_syscall6(SYS_mmap, (long)(uintptr_t)addr, (long)len, (long)prot, (long)flags, (long)fd, (long)off);
}

long ab_munmap(void * addr, size_t len)
{
    return (long)ab_syscall2(SYS_munmap, (long)(uintptr_t)addr, (long)len);
}

long ab_mprotect(void * addr, size_t len, int prot)
{
    return (long)ab_syscall3(SYS_mprotect, (long)(uintptr_t)addr, (long)len, (long)prot);
}

long ab_brk(void * addr)
{
    return (long)ab_syscall1(SYS_brk, (long)(uintptr_t)addr);
}

int ab_getpid(void)
{
    return (int)ab_syscall0(SYS_getpid);
}

int ab_getppid(void)
{
    return (int)ab_syscall0(SYS_getppid);
}

int ab_gettid(void)
{
    return (int)ab_syscall0(SYS_gettid);
}

int ab_getuid(void)
{
    return (int)ab_syscall0(SYS_getuid);
}

int ab_getgid(void)
{
    return (int)ab_syscall0(SYS_getgid);
}

long ab_kill(int pid, int sig)
{
    return (long)ab_syscall2(SYS_kill, (long)pid, (long)sig);
}

__attribute__((noreturn)) void ab_exit(int code)
{
    ab_syscall1(SYS_exit, (long)code);
    __builtin_unreachable();
}

__attribute__((noreturn)) void ab_exit_group(int code)
{
    ab_syscall1(SYS_exit_group, (long)code);
    __builtin_unreachable();
}

long ab_stat(const char * path, void * buf)
{
    return (long)ab_syscall2(SYS_stat, (long)(uintptr_t)path, (long)(uintptr_t)buf);
}

long ab_fstat(int fd, void * buf)
{
    return (long)ab_syscall2(SYS_fstat, (long)fd, (long)(uintptr_t)buf);
}

long ab_openat(int dirfd, const char * path, int flags, int mode)
{
    return (long)ab_syscall4(SYS_openat, (long)dirfd, (long)(uintptr_t)path, (long)flags, (long)mode);
}

long ab_unlink(const char * path)
{
    return (long)ab_syscall1(SYS_unlink, (long)(uintptr_t)path);
}

long ab_mkdir(const char * path, int mode)
{
    return (long)ab_syscall2(SYS_mkdir, (long)(uintptr_t)path, (long)mode);
}

long ab_rmdir(const char * path)
{
    return (long)ab_syscall1(SYS_rmdir, (long)(uintptr_t)path);
}

long ab_rename(const char * oldpath, const char * newpath)
{
    return (long)ab_syscall2(SYS_rename, (long)(uintptr_t)oldpath, (long)(uintptr_t)newpath);
}

long ab_getcwd(char * buf, size_t size)
{
    return (long)ab_syscall2(SYS_getcwd, (long)(uintptr_t)buf, (long)size);
}

long ab_dup(int fd)
{
    return (long)ab_syscall1(SYS_dup, (long)fd);
}

long ab_dup2(int oldfd, int newfd)
{
    return (long)ab_syscall2(SYS_dup2, (long)oldfd, (long)newfd);
}

long ab_nanosleep(const void * req, void * rem)
{
    return (long)ab_syscall2(SYS_nanosleep, (long)(uintptr_t)req, (long)(uintptr_t)rem);
}

long ab_clock_gettime(int clkid, void * tp)
{
    return (long)ab_syscall2(SYS_clock_gettime, (long)clkid, (long)(uintptr_t)tp);
}
