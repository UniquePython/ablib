#include "ab_stdio.h"

#include "ablib.h"

int ab_puts(const char *s)
{
    unsigned long len = ab_strlen(s);

    ab_write(1, s, len);
    ab_write(1, "\n", 1);

    return 0;
}