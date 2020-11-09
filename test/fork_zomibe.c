#include <stdio.h>
#include <unistd.h>

int main()
{
    if (fork()) printf("I am father\n");
    else {printf("I am son\n"); sleep(8);}

    return 0;
}
