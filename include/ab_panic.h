#ifndef AB_PANIC_H
#define AB_PANIC_H

#include "ab_types.h"

__attribute__((noreturn)) void ab_panic(const char *msg);

#endif