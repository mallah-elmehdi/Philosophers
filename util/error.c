#include "util.h"

int error(const char *msg)
{
    printf("Error: %s\n", msg);
    return (ERROR);
}