#include <stdio.h>

int find_repeate_num(int num[], int size)
{
    long int res = 0;
    for (int i = 1; i < size - 1; i++) {
        res += i;
        res -= num[i - 1];
    }
    res -= num[size - 1];

    return -res;
}

int main()
{
    int num[] = {3, 5, 6, 1, 4, 2, 7, 4};
    printf("get the repeated num is [%d]\n", find_repeate_num(num, sizeof(num) / sizeof(int)));

    return 0;
}
