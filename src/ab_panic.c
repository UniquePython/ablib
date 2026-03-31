#include "ab_panic.h"
#include "ab_io.h"
#include "ab_signal.h"
#include "ab_syscall_nums.h"

__attribute__((noreturn)) void ab_panic(const char *msg)
{
    ab_write(2, msg, ab_strlen(msg));
    ab_write(2, "\n", 1);

#ifdef AB_PANIC_ABORT
    ab_kill(ab_getpid(), SIGABRT);
    __builtin_unreachable();
#else
    ab_exit_group(1);
#endif
}