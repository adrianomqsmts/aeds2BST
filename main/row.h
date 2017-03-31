#ifndef ROW_H_INCLUDED
#define ROW_H_INCLUDED
#include "no.c"
typedef struct cell * pCell ;

typedef struct cell{
    pointer no;
    pCell next;
}cell;

typedef struct {
  pCell first, last;
}row;

void start_row(row * r);
void insert_item_row(row * r, pointer * n);
void remove_item_row(row * r, pointer * n);
int null_row(row * r);

#endif
