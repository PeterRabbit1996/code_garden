#include <stdio.h>
#include <stdlib.h>

int main()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if(random() % 2 == 0)
                printf("\\  ");
            else
                printf("`  ");
        }

        printf("\n");
    }

    return 0;
}


#if 0
#include <stdio.h>

int main()
{
    unsigned char *p1;
    unsigned long *p2;
    p1 = (unsigned char *)0x801000;
    p2 = (unsigned long *)0x810000;

    printf("%x, %x\n", p1 + 5, p2 + 5);

    return 0;
}
#endif


#if 0
#include <stdio.h>

char *funcA()
{
    char str[16] = "hello, world!\n";
    printf("[%s] %s", __FUNCTION__, str);

    return str;
}

int *funcB()
{
    int num = 99;

    return &num;
}

int main()
{
    printf("[%s] %s", __FUNCTION__, funcA());
    printf("[%d] %s", __FUNCTION__, funcB());

    return 0;
}
#endif
