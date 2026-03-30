int main(void)
{
    return 42;
}

void _start(void)
{
    int result = main();

    __asm__ volatile(
        "mov $60, %%rax\n" // syscall: exit
        "syscall\n"
        :
        : "D"(result));
}