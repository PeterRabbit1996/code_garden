/*
面试题 04.04. 检查平衡性

实现一个函数，检查二叉树是否平衡。在这个问题中，平衡树的定义如下：任意一个节点，其两棵子树的高度差不超过 1。


示例 1:
给定二叉树 [3,9,20,null,null,15,7]
    3
   / \
  9  20
    /  \
   15   7
返回 true 。

示例 2:
给定二叉树 [1,2,2,3,3,null,null,4,4]
      1
     / \
    2   2
   / \
  3   3
 / \
4   4
返回 false 。
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//Definition for a binary tree node.
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

static bool balence = true;

int tree_height(struct TreeNode *root)
{
	if (root == NULL || balence == false)
		return 0;
	int left_height = tree_height(root->left);
	int right_height = tree_height(root->right);
	if (abs(left_height - right_height) > 1)
		balence = false;

	return ((left_height > right_height ? left_height : right_height) + 1);
}

bool isBalanced(struct TreeNode* root)
{
	balence = true;
	tree_height(root);

	return balence;
}

struct TreeNode *buildTree(int treeVal[], int isNull[], int size)
{
	struct TreeNode *tree_node[size];

	for (int i = 0; i < size; i++) {
		if (isNull[i] == 0) {
			tree_node[i] = NULL;
			continue;
		}
		struct TreeNode *node =(struct TreeNode *) malloc(sizeof(struct TreeNode));
		memset(node, 0, sizeof(struct TreeNode));
		node->val = treeVal[i];
		tree_node[i] = node;
	}

	for (int i = 0; i < size; i++) {
		if (tree_node[i] == NULL)
			continue;
		if (i * 2 + 1 < size)
			tree_node[i]->left = tree_node[i * 2 + 1];
		if (i * 2 + 2 < size)
			tree_node[i]->right = tree_node[i * 2 + 2];
	}

/*
	for (int i = 0; i < size; i++) {
		if (tree_node[i] == NULL){
			printf("null\n");
			continue;
		}

		printf("%d, ", tree_node[i]->val);

		if (tree_node[i]->left != NULL)
			printf("%d, ", tree_node[i]->left->val);
		else
			printf("null, ");

		if (tree_node[i]->right != NULL)
			printf("%d, ", tree_node[i]->right->val);
		else
			printf("null, ");

		printf("\n");
	}
*/

	return tree_node[0];
}

int main()
{
	int treeVal[] = {3, 9, 20, 0, 0, 15, 7};
	int isNull[] = {1, 1, 1, 0, 0, 1, 1};
	int size = sizeof(treeVal) / sizeof(int);
	printf("balance = %d\n", isBalanced(buildTree(treeVal, isNull, size)));

	return 0;
}
