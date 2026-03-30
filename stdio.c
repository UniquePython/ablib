#include "ablib.h"

int puts(const char *s)
{
    unsigned long len = strlen(s);

    write(1, s, len);
    write(1, "\n", 1);

    return 0;
}