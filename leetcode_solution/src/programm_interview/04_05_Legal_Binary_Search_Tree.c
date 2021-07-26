/*
面试题 04.05. 合法二叉搜索树

实现一个函数，检查一棵二叉树是否为二叉搜索树。

示例 1:
输入:
    2
   / \
  1   3
输出: true

示例 2:
输入:
    5
   / \
  1   4
     / \
    3	6
输出: false
解释: 输入为: [5,1,4,null,null,3,6]。
     根节点的值为 5 ，但是其右子节点值为 4 。
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/************************************
 * Definition for a binary tree node.
************************************/
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

/************************************
 * Definition for a binary tree node.
************************************/
struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode *head_node;
struct ListNode *cur_node;

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

void tree_ldr(struct TreeNode *tree_node)
{
	if (tree_node == NULL)
		return;

	tree_ldr(tree_node->left);

	struct ListNode *list_node = (struct ListNode *)malloc(sizeof(struct ListNode));
	cur_node->next = list_node;
	cur_node = cur_node->next;
	cur_node->val = tree_node->val;
	cur_node->next = NULL;

	tree_ldr(tree_node->right);

}

bool isValidBST(struct TreeNode* root)
{
	if (root == NULL)
		return true;

	head_node = (struct ListNode *)malloc(sizeof(struct ListNode));
	cur_node = head_node;

	tree_ldr(root);
	cur_node = head_node->next;
	if (cur_node == NULL)
		return true;

	while (cur_node->next != NULL) {
		if (cur_node->val >= cur_node->next->val)
			return false;
		cur_node = cur_node->next;
	}

	return true;
}

/*
bool g_balanced = true;
bool g_min_valid = false;
int g_min = 0;

void dfs(struct TreeNode *root)
{
	if (root == NULL || !g_balanced)
		return;

	dfs(root->left);
	if (g_min_valid && root->val <= g_min) {
		g_balanced = false;
		return;
	}
	g_min_valid = true;
	g_min = root->val;
	dfs(root->right);    

	return;
}

bool isValidBST(struct TreeNode* root){
	g_balanced = true;
	g_min_valid = false;

	dfs(root);

	return g_balanced;
}
*/

int main()
{
	/*
	int tree_val[] = {5, 1, 4, 0, 0, 3, 6};
	int is_null[] = {1, 1, 1, 0, 0, 1, 1};
	int size = sizeof(tree_val) / sizeof(int);
	*/
	int tree_val[] = {2, 1, 3};
	int is_null[] = {1, 1, 1};
	int size = sizeof(tree_val) / sizeof(int);
	printf("is_valid_bst = %d\n", isValidBST(buildTree(tree_val, is_null, size)));

	return 0;
}
