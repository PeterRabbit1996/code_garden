#ifndef _LIST_H
#define _LIST_H

struct list {
	struct list *pre;
	struct list *next;
};

void list_init(struct list *head);
void list_tail_add(struct list *tail, struct list *new);

#endif
