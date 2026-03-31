#include "ab_string.h"

#include "ab_types.h"

size_t ab_strlen(const char *s)
{
    unsigned long len = 0;

    while (s[len] != '\0')
        len++;

    return len;
}