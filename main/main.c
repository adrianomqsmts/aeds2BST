#include <stdio.h>
#include <stdlib.h>
#include "no.h"

int main(int argc, char const *argv[]) {
    Node *root;
    int v, c=1;

    init_root(&root);
    while (1) {
        printf("insira o termo %d\n", c);
        scanf("%i", &v);
        if(v == 0) break;
        insert_node(&root, v);
        c++;
    }
    print_node(root);
    search_node(root, 10);
    width_tree(root);

    return 0;
}
