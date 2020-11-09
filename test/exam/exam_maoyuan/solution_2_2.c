#include <stdio.h>

int get_max_profit(int price[], int size)
{
    if (size <= 1)
        return 0;

    int cur_max = 0;
    int left = 0;
    int right = 1;
    int last = size;

    while (right < last) {
        if (price[right] < price[left]) {
            left = right; 
            right++;
            continue;
        }
        if (cur_max < price[right] - price[left]) {
            cur_max = price[right] - price[left];
            right++;
            continue;
        }
        right++;
    }

    //printf("%d %d %d %d\n", cur_max, left, right, last);

    return cur_max;
}

int main()
{
    int pri[] = {3, 5, 1, 4, 5, 2, 6, 4, 6, 2};
    printf("get max profit is [%d]\n", get_max_profit(pri, sizeof(pri) / sizeof(int)));

    return 0;
}
