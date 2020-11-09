#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int val;
	struct node *next;
} Node;

int recursive_print(Node *root)
{
	Node *cur = root;
	int size = 0;

	while (cur != NULL) {
		size += 1;
		cur = cur->next;
	}

	int *stack = (int *)malloc(sizeof(int) * size);
	if (stack == NULL)
		return -1;

	cur = root;
	for (int i = 0; i < size; i++) {
		*(stack + i) = cur->val;
		cur = cur->next;
	}

	for (int i = size - 1; i >= 0; i--)
		printf("%d, ", *(stack + i));
	printf("\n");

	free(stack);
	return 0;
}

int main()
{
	Node *root = malloc(sizeof(Node));
	Node *cur = root;
	int size = 5;
	for (int i = 0; i < size - 1; i++) {
		Node *tmp = malloc(sizeof(Node));
		cur->val = i;
		cur->next = tmp;
		cur = cur->next;
	}
	cur->val = size - 1;
	cur->next = NULL;

	for (cur = root; cur != NULL; cur = cur->next)
		printf("%d, ", cur->val);
	printf("\n");

	recursive_print(root);	

	return 0;
}
