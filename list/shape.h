#ifndef _SHAPE_H
#define _SHAPE_H

#include "list.h"

struct triangle{
        struct list *cur;
        double a;
        double b;
        double c;
};

struct rectangle {
        struct list *cur;
        double length;
        double width;
};

void print_tri(struct triangle *tri);
void print_rec(struct rectangle *rec);

#endif
