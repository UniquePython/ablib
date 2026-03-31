#ifndef AB_IO_H
#define AB_IO_H

#include "ab_types.h"

long ab_read(int fd, void * buf, size_t n);
long ab_write(int fd, const void * buf, size_t n);
long ab_open(const char * path, int flags, int mode);
long ab_close(int fd);
long ab_lseek(int fd, long offset, int whence);
void * ab_mmap(void * addr, size_t len, int prot, int flags, int fd, long off);
long ab_munmap(void * addr, size_t len);
long ab_mprotect(void * addr, size_t len, int prot);
long ab_brk(void * addr);
int ab_getpid(void);
int ab_getppid(void);
int ab_gettid(void);
int ab_getuid(void);
int ab_getgid(void);
long ab_kill(int pid, int sig);
__attribute__((noreturn)) void ab_exit(int code);
__attribute__((noreturn)) void ab_exit_group(int code);
long ab_stat(const char * path, void * buf);
long ab_fstat(int fd, void * buf);
long ab_openat(int dirfd, const char * path, int flags, int mode);
long ab_unlink(const char * path);
long ab_mkdir(const char * path, int mode);
long ab_rmdir(const char * path);
long ab_rename(const char * oldpath, const char * newpath);
long ab_getcwd(char * buf, size_t size);
long ab_dup(int fd);
long ab_dup2(int oldfd, int newfd);
long ab_nanosleep(const void * req, void * rem);
long ab_clock_gettime(int clkid, void * tp);
#endif
