/*
88. 合并两个有序数组

给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。

说明:
初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。
你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。

示例:

输入:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

输出: [1,2,2,3,5,6]
*/

#include <stdio.h>

/*******************************************************************************
 * gcc -O -g -fsanitize=address 88_Merge_Sorted_Array.c -o 88_Merge_Sorted_Array
*******************************************************************************/

void print_num(int num[], int size)
{
	for (int i = 0; i < size; i++)
		printf("%d, ", num[i]);
	printf("\n");
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
	if (n == 0)
		return;
	else if (m == 0) {
		for (int i = 0; i < n; i++)
			nums1[i] = nums2[i];
		return;
	}

	for (int i = m - 1, j = m + n - 1; i >= 0; i--, j--)
		nums1[j] = nums1[i];

	for (int i = n, j = 0, k = 0; i < m + n || j < n; ) {
		if (nums1[i] < nums2[j]) {
			nums1[k] = nums1[i];
			i++;
			k++;
		}
		else {
			nums1[k] = nums2[j];
			j++;
			k++;
		}

		if (i == m + n) {
			while (j < n) {
				nums1[k] = nums2[j];
				j++;
				k++;
			}
		}
		if (j == n) {
			while (i < m + n) {
				nums1[k] = nums1[i];
				i++;
				k++;
			}
		}
	}
}

int main()
{
	int num1[] = {1, 2, 3, 0, 0, 0};
	int num2[] = {2, 5, 6};
	int num1_size = sizeof(num1) / sizeof(int);
	int num2_size = sizeof(num2) / sizeof(int);
	merge(num1, num1_size, 3, num2, num2_size, 3);
	print_num(num1, num1_size);

	return 0;
}
