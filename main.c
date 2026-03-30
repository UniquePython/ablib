#include "ablib.h"

int main()
{
    const char *msg = "Hello from ablib!\n";
    write(1, msg, 19);
    return 0;
}