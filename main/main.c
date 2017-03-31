#include <stdio.h>
#include <stdlib.h>
#include "no.c"

int main(int argc, char const *argv[]) {
  pointer root;
 int v, c=1;

  start_root(&root);
  while (1) {
    printf("insira o termo %d\n", c);
    scanf("%i", &v);
    if(v == 0)
      break;
    insert_node(&root, v);
    c++;
  }
  print_node(&root);
  search_node(&root, 10);

  return 0;
}
