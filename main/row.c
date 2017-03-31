#include "row.h"
#include <stdio.h>
#include <stdlib.h>

void start_row(row * r){
  r->first = (pCell)malloc(sizeof(cell));
  r->last = r->first;
  r->first->next = NULL;

}
void insert_item_row(row * r, pointer* n){
  pCell newItem;
  newItem  = (pCell)malloc(sizeof(cell));
  r->last->next = newItem;
  r->last = newItem;
  newItem->no = n;
  newItem->next = NULL;
}

void remove_item_row(row * r, pointer * exit){
  pCell temp;
  if (!null_row(r)){
    temp = r->first;
    exit = r->first->no;
    r->first = r->first->next;
    free(temp);
  }
}
int null_row(row * r){
  return (r->first == r->last);
}
