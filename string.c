unsigned long strlen(const char *s)
{
    unsigned long len = 0;

    while (s[len] != '\0')
        len++;

    return len;
}