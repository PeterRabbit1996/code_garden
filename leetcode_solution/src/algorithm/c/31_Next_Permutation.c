/*
31. 下一个排列

实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。

如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。

必须原地修改，只允许使用额外常数空间。

以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/

#include <stdio.h>

void print_res(int *nums, int size)
{
	for (int i = 0; i < size; i++)
		printf("%d ", nums[i]);
	printf("\n");

	return ;
}

void swap(int *nums, int l, int r)
{
	if (nums[l] == nums[r])
		return ;

	nums[l] ^= nums[r];
	nums[r] ^= nums[l];
	nums[l] ^= nums[r];

	return ;
}

void reserse(int *nums, int l, int r)
{
	while (l < r) {
		swap(nums, l, r);
		l++;
		r--;
	}

	return ;
}

void nextPermutation(int* nums, int numsSize)
{
	int l = numsSize - 1;
	int r = numsSize - 1;

	while (l >= 1 && nums[l - 1] >= nums[l])
		l--;
	l--;

	if (l >= 0) {
		r = numsSize - 1;
		while (r > l && nums[r] <= nums[l])
			r--;
		swap(nums, l, r);
	}
	reserse(nums, l + 1, numsSize - 1);

	return ;
}

int main()
{
	//int nums[] = {1, 2, 3};
	//int nums[] = {1,5,8,4,7,6,5,3,1};
	//int nums[] = {1, 5, 1};
	//int nums[] = {1, 1};
	int nums[] = {5, 1, 1};
	int size = sizeof(nums) / sizeof(int);
	nextPermutation(nums, size);
	print_res(nums, size);

	return 0;
}
