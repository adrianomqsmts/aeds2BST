#include "no.h"
#include "row.c"
#include <stdio.h>
#include <stdlib.h>
//INICIALIZA A RAIZ
void start_root(pointer * root){
  (*root) = NULL;
}
//INSERE UM NO NA ÁRVORE
void insert_node(pointer * n, int key){
  if(*n == NULL){
    *n = (pointer)malloc(sizeof(node));
    (*n)->key = key;
    (*n)->left = NULL;
    (*n)->right = NULL;
  }else{
    if((*n)->key > key)
      insert_node(&(*n)->left, key);
    else if ((*n)->key < key)
      insert_node(&(*n)->right , key);
    else
        printf("Valor já inserido\n");
  }
}
//EXIBE A ÁRVORE EM ORDEM
void print_node(pointer * n){
  if(*n != NULL){
    print_node(&(*n)->left);
    printf("%d\n", (*n)->key );
    print_node(&(*n)->right);
  }
}

void delete_node(pointer * n, int key){

}
//ṔROCURA UMA CHAVA NA ÁRVORE
void search_node(pointer * n, int key){
  if((*n)!=NULL){
    if((*n)->key == key)
      printf("%d\n", (*n)->key);
    else if((*n)->key > key)
      search_node(&(*n)->left, key);
    else
      search_node(&(*n)->right, key);
  }else{
    printf("VALOR NÃO EXISTE\n");
  }
}

void width_tree(pointer * n){
  row r;
  start_row(&r);
  _width_tree(&(*n), &r);
}
//EXIBE A LARGURA DA ÁRVORE
void _width_tree(pointer * n, row * r){
node aux;
  if((*n) != NULL ){
    insert_item_row(&(*r), (*n));
    while(null_row(r)){
      remove_item_row(r, &(aux));
      printf("%d\n", aux.key);
      if(aux.left != NULL)
        insert_item_row(&(*r), (*n));
      if(aux.right != NULL)
        insert_item_row(&(*r), (*n));
    }
  }
}

//EXIBE A ALTURA DA ARVORE
int height_tree(pointer *n){
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
