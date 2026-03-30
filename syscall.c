long write(int fd, const void *buf, unsigned long count)
{
    long ret;

    __asm__ volatile(
        "mov $1, %%rax\n"
        "syscall\n"
        : "=a"(ret)
        : "D"(fd), "S"(buf), "d"(count));

    return ret;
}