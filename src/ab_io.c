#include "ab_syscall.h"
#include "ab_syscall_nums.h"

long ab_write(int fd, const void *buf, size_t n)
{
    return ab_syscall3(SYS_write, fd, (long)buf, (long)n);
}