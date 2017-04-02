#include "no.h"
#include <stdio.h>
#include <stdlib.h>
//INICIALIZA A RAIZ
void init_root(Node ** root){
  (*root) = NULL;
}
//INSERE UM NO NA ÁRVORE
void insert_node(Node ** n, int key){
  if(*n == NULL){
    *n = (Node *)malloc(sizeof(Node));
    (*n)->key = key;
    (*n)->left = NULL;
    (*n)->right = NULL;
  }
  else{
    if((*n)->key > key)
      insert_node(&(*n)->left, key);
    else if ((*n)->key < key)
      insert_node(&(*n)->right , key);
    else
        printf("Valor já inserido\n");
  }
}
//EXIBE A ÁRVORE EM ORDEM
void print_node(Node * n){
  if(n != NULL){
    print_node(n->left);
    printf("%d\n", n->key );
    print_node(n->right);
  }
}


//ṔROCURA UMA CHAVA NA ÁRVORE
void search_node(Node * n, int key){
  if(n!=NULL){
    if(n->key == key)
      printf("%d\n", n->key);
    else if(n->key > key)
      search_node(n->left, key);
    else
      search_node(n->right, key);
  }else{
    printf("VALOR NÃO PRESENTE NA ÁRVORE\n");
  }
}

void width_tree(Node * n){
  Queue r;
  init_queue(&r);
  _width_tree(n, &r);
}
//EXIBE A LARGURA DA ÁRVORE
void _width_tree(Node * n, Queue * r){
    Node aux;
    if(n != NULL ){
        insert_item_queue(r, n);
        while(!null_queue(r)){
            remove_item_queue(r, &(aux));
            printf("%d\n", aux.key);
            if(aux.left != NULL){
                insert_item_queue(r, aux.left);
            }
            if(aux.right != NULL){
                insert_item_queue(r, aux.right);
            }
        }
    }
}

//EXIBE A ALTURA DA ARVORE
int height_tree(Node **n){
  int left, right;
    if((*n) == NULL)
      return -1;
    left = height_tree(&(*n)->left);
    right = height_tree(&(*n)->right);
    if(left > right)
      return left+1;
    else
      return right+1;
}

void init_queue(Queue * r){
  r->first = (Cell *)malloc(sizeof(Cell));
  r->last = r->first;
  r->first->next = NULL;

}
void insert_item_queue(Queue * r, Node * n){
  Cell * newItem;
  newItem  = (Cell *)malloc(sizeof(Cell));
  r->last->next = newItem;
  r->last = newItem;
  newItem->no = n;
  newItem->next = NULL;
}

void remove_item_queue(Queue * r, Node * exit){
  Cell * temp;
  if (!null_queue(r)){
    temp = r->first->next;
    *exit = *r->first->next->no;
    r->first->next = r->first->next->next;
    if(r->last == temp) r->last = r->first;
    free(temp);
  }
  else printf("VAZIA\n");
}
int null_queue(Queue * r){
  return (r->first == r->last);
}
