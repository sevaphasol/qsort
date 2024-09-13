#include <stdio.h>
#include <string.h>
#include "comp.h"

int int_compare(const void* a, const void* b)
{
    return *((const int*) a) - *((const int*) b);
}

int char_compare(const void* a, const void* b)
{
    printf("%c - %c = %d\n", *((const char*) a), *((const char*) b), *((const char*) a) - *((const char*) b));
    return *((const char*) a) - *((const char*) b);
}

int str_compare(const void* a, const void* b)
{
    return strcmp((const char*) a, (const char*) b);
}
