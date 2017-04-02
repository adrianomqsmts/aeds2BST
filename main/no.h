#ifndef NO_H_INCLUDED
#define NO_H_INCLUDED
typedef struct _Node {
  int key;
  struct _Node *left, *right;
}Node;

typedef struct _Cell{
    Node* no;
    struct _Cell *next;
}Cell;

typedef struct {
  Cell *first, *last;
}Queue;

//FILA
void init_queue(Queue * r);
void insert_item_queue(Queue * r, Node * n);
void remove_item_queue(Queue * r, Node * n);
int null_queue(Queue * r);
//BST
void init_root(Node ** root);
void insert_node(Node ** n, int key);
void print_tree(Node ** n);
void print_node(Node * n);
void search_node(Node * n, int key);
void width_tree(Node * n);
void _width_tree(Node * n, Queue * r);
int height_tree(Node **n);


#endif
