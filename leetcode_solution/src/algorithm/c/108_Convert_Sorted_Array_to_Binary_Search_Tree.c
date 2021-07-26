/*
108. 将有序数组转换为二叉搜索树

将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。

本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

示例:

给定有序数组: [-10,-3,0,5,9],

一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：

      0
     / \
   -3   9
   /   /
 -10  5
*/


#include <stdio.h>

/* Definition for a binary tree node. */
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct TreeNode *aux_func(int *nums, int left, int right)
{
	if (left > right)
		return NULL;

	int mid = (left + right + 1) / 2;
	struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));

	node->val = nums[mid];
	node->left = aux_func(nums, left, mid - 1);
	node->right = aux_func(nums, mid + 1, right);

	return node;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize)
{
	return aux_func(nums, 0, numsSize - 1);
}

int main()
{

	return 0;
}
