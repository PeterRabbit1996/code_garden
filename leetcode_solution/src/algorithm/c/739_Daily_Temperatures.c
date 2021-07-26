/*
739. 每日温度

根据每日 气温 列表，请重新生成一个列表，对应位置的输出是需要再等待多久温度才会升高超过该日的天数。如果之后都不会升高，请在该位置用 0 来代替。

例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，你的输出应该是 [1, 1, 4, 2, 1, 1, 0, 0]。

提示：气温 列表长度的范围是 [1, 30000]。每个气温的值的均为华氏度，都是在 [30, 100] 范围内的整数。
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/************************************************************************
 * Note: The returned array must be malloced, assume caller calls free().
************************************************************************/
int* dailyTemperatures(int* T, int TSize, int* returnSize)
{
	int *res = (int *)malloc(sizeof(int) * TSize);
	int *stack = (int *)malloc(sizeof(int) * TSize);

	int cur_ptr = 0;
	for (int i = 0; i < TSize; i++) {
		while (cur_ptr > 0 && T[i] > T[cur_ptr]) {
			*(res + *(stack + cur_ptr)) = i - *(stack + cur_ptr);
			cur_ptr -= 1;
		} 
		cur_ptr += 1;
		*(stack + cur_ptr) = T[i + 1];
	}

	*returnSize = TSize;
	return res;
}

void print_res(int *res, int size)
{
	for (int i = 0; i < size; i++)
		printf("%d ", *(res + i));
	printf("\n");
}

int main()
{
	int T[] = {73, 74, 75, 71, 69, 72, 76, 73};
	int TSize = 8;
	int returnSize;
	print_res(dailyTemperatures(T, TSize, &returnSize), TSize);

	return 0;
}
