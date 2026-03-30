#include "ablib.h"

int main()
{
    const char *msg = "Hello using strlen!\n";
    write(1, msg, strlen(msg));
    return 0;
}