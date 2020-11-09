#include <stdio.h>

void print_ln()
{
    printf("\n");
}

void print_line(int size)
{
    for (int i = 0; i < size; i += 1) {
        printf("#");
    }
    print_ln();
}
