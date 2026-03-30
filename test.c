void _start(void)
{
    __asm__ volatile(
        "mov $60, %rax\n" // syscall: exit
        "mov $0, %rdi\n"  // status = 0
        "syscall\n");
}