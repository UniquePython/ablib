int main();

void _start()
{
    int result = main();
    ab_exit_group(result);
}