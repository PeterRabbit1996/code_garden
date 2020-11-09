#include <stdio.h>
#include "shape.h"

void print_tri(struct triangle *tri)
{
	printf("tri:\n");
	printf("\ta = %f\n", tri->a);
	printf("\tb = %f\n", tri->b);
	printf("\tc = %f\n", tri->c);

	return ;
}

void print_rec(struct rectangle *rec)
{
	printf("rec:\n");
	printf("\tlength = %f\n", rec->length);
	printf("\twidth = %f\n", rec->width);

	return ;
}
