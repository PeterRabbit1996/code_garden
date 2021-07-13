#include <stdio.h>
#include "dynamic.h"
#include "static.h"

int func_dynamic()
{
    printf("%s...\n", __FUNCTION__);
    // func_static();

    return 0;
}