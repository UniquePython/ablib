int main();

void _start()
{
    int result = main();

    __asm__ volatile(
        "mov $60, %%rax\n"
        "syscall\n"
        :
        : "D"(result)
        : "rcx", "r11", "memory");
}