/*
102. 二叉树的层序遍历

给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。

 

示例：
二叉树：[3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [9,20],
  [15,7]
]
*/

/*********************************************************
 * It tooks me a lot of time to get this solution.
 * 20 lines of code will be finished if solved with pyhon.
 * But it would benefit me a lot by using c language.
*********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/************************************
 * Definition for a binary tree node.
************************************/
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

/************************************
 * Definition for a List that contains tree node.
************************************/
struct ListTreeNode {
	struct TreeNode *tree;
	struct ListTreeNode *next;
	struct ListTreeNode *adjoin;
};

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

/************************************************************************************************
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
************************************************************************************************/
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{
	if (root == NULL) {
		*returnSize = 0;
		*returnColumnSizes = NULL;
		return NULL;
	}

	*returnSize = 0;
	struct ListTreeNode *head_list = (struct ListTreeNode *)malloc(sizeof(struct ListTreeNode));
	head_list->tree = root;
	head_list->next = NULL;
	head_list->adjoin = NULL;

	struct ListTreeNode *cur_list = head_list;
	while (cur_list != NULL) {
		*returnSize += 1;

		struct ListTreeNode *next_list = (struct ListTreeNode *)malloc(sizeof(struct ListTreeNode));
		memset(next_list, 0, sizeof(struct ListTreeNode));

		struct ListTreeNode *cur_adjoin = cur_list;
		struct ListTreeNode *next_adjoin = next_list;
		while (cur_adjoin != NULL) {
			if (cur_adjoin->tree->left != NULL) {
				next_adjoin->adjoin = (struct ListTreeNode *)malloc(sizeof(struct ListTreeNode));
				next_adjoin = next_adjoin->adjoin;

				next_adjoin->tree = cur_adjoin->tree->left;
				next_adjoin->next = NULL;
				next_adjoin->adjoin = NULL;
			}
			if (cur_adjoin->tree->right != NULL) {
				next_adjoin->adjoin = (struct ListTreeNode *)malloc(sizeof(struct ListTreeNode));
				next_adjoin = next_adjoin->adjoin;

				next_adjoin->tree = cur_adjoin->tree->right;
				next_adjoin->next = NULL;
				next_adjoin->adjoin = NULL;
			}

			cur_adjoin = cur_adjoin->adjoin;
		}

		cur_list->next = next_list->adjoin;
		cur_list = cur_list->next;
		free(next_list);
	}

	/*
	cur_list = head_list;
	while (cur_list != NULL) {
		struct ListTreeNode *cur_adjoin = cur_list;
		while (cur_adjoin != NULL) {
			printf("%d, ", cur_adjoin->tree->val);
			cur_adjoin = cur_adjoin->adjoin;
		}
		printf("\n");
		cur_list = cur_list->next;
	}
	*/

	*returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));

	cur_list = head_list;
	for (int i = 0; cur_list != NULL; cur_list = cur_list->next, i++) {
		*(*returnColumnSizes + i) = 0;
		for (struct ListTreeNode *cur_adjoin = cur_list; cur_adjoin != NULL; cur_adjoin = cur_adjoin->adjoin)
			*(*returnColumnSizes + i) += 1;
	}

	int **ans = (int **)malloc(sizeof(int *) * (*returnSize));
	cur_list = head_list;
	for (int i = 0; cur_list != NULL; cur_list = cur_list->next, i++) {
		*(ans + i) = (int *)malloc(sizeof(int) * *(*returnColumnSizes + i));
		struct ListTreeNode *cur_adjoin = cur_list;
		for (int j = 0; cur_adjoin != NULL; cur_adjoin = cur_adjoin->adjoin, j++)
			*(*(ans + i) + j) = cur_adjoin->tree->val;
	}

	return ans;
}

void print_res(int **res, int* returnSize, int** returnColumnSizes)
{
	for (int i = 0; i < *returnSize; i++) {
		for (int j = 0; j < *(*returnColumnSizes + i); j++)
			printf("%d, ", *(*(res + i) + j));
		printf("\n");
	}
}

int main()
{
	int tree_val[] = {3, 9, 20, 0, 0, 15, 7};
	int is_null[] = {1, 1, 1, 0, 0, 1, 1};
	int size = sizeof(tree_val) / sizeof(int);

	int return_size = 0;
	int *return_column_sizes = NULL;
	int **res = levelOrder(buildTree(tree_val, is_null, size), &return_size, &return_column_sizes);
	print_res(res, &return_size, &return_column_sizes);

	return 0;
}
