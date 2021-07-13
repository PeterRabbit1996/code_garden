#include <stdio.h>
#include "static.h"

int func_static()
{
    printf("%s...\n", __FUNCTION__);

    return 0;
}
