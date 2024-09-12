#include <stdio.h>
#include "comp.h"

int int_compare(const void* a, const void* b)
{
    return *((int*)a) - *((int*)b);
}
