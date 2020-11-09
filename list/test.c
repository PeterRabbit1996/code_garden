#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "shape.h"

int main()
{
	struct triangle *tri = (struct triangle *)malloc(sizeof(struct triangle));
	list_init(&(tri->cur));

	struct rectangle *rec = (struct rectangle *)malloc(sizeof(struct rectangle));
	list_tail_add(&(tri->cur), &(rec->cur));

	print_tri(tri);
	print_rec(rec);

	return 0;
}
