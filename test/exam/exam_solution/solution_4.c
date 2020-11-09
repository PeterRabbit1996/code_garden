#include <stdio.h>

int main()
{
    char c;
    scanf("%c", &c);

    if (c >= '0' && c <= '9')
    {
        printf("%c\n", c);
    }
    else if ((c >= 'A' && c <= 'Z') ||
             (c >= 'a' && c <= 'z')
            )
    {
        printf("%d\n", c);
    }
    else
    {
        printf("输入错误！\n");
    }

    return 0;
}


/*
a
97
bash-3.2$
bash-3.2$
bash-3.2$ ./solution_4
z
122
bash-3.2$
bash-3.2$ ./solution_4
A
65
bash-3.2$ ./solution_4
Z
90
*/
