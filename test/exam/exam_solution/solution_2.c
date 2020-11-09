#include <stdio.h>

#define ARRAY_NUM    5

int search(int x, int *p)
{
    for (int i = 0; i < ARRAY_NUM; i++)
    {
        if (*(p + i) == x) return i;
    }
    return -1;
}

int main()
{
    int num[ARRAY_NUM] = {0};
    int x = 0;
    int result = 0;

    printf("please input %d num:\n", ARRAY_NUM);
    for (int i = 0; i < ARRAY_NUM; i++)
    {
        scanf("%d", &num[i]);
    }
    printf("please input the num you want to search: ");
    scanf("%d", &x);

    result = search(x, num);
    if (result >= 0)
    {
        printf("get the result: %d\n", result);
    }
    else
    {
        printf("Not found.\n");
    }

    return 0;
}
