#include <stddef.h>
#include "list.h"

void list_init(struct list *head)
{
	head->next = NULL;
	head->pre = NULL;
}

void list_tail_add(struct list *tail, struct list *new)
{
	tail->next = new;
	new->pre = tail;
	new->next = NULL;
}
