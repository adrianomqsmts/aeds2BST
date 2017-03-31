#ifndef NO_H_INCLUDED
#define NO_H_INCLUDED
#include "row.h"
typedef struct node * pointer;
typedef struct node {
  int key;
  pointer left, right;
}node;

void start_root(pointer * root);
void insert_node(pointer * n, int key);
void print_tree(pointer * n);
void delete_node(pointer * n, int key);
void search_node(pointer * n, int key);
void width_tree(pointer * n);
void _width_tree(pointer * n, row * r);
int height_tree(pointer *n);

#endif
