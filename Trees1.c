#include <stdio.h>

#define MAXSIZE 100

typedef struct {
    char nodes[MAXSIZE];
    int numElements;
} BinaryTree;

int main() {
    BinaryTree tree;

    // Árbol binario full (nodo K agregado como hijo derecho de F)
    tree.nodes[0] = 'G';
    tree.nodes[1] = 'D';
    tree.nodes[2] = 'I';
    tree.nodes[3] = 'B';
    tree.nodes[4] = 'F';
    tree.nodes[5] = 'H';
    tree.nodes[6] = 'J';
    tree.nodes[7] = 'A';
    tree.nodes[8] = 'C';
    tree.nodes[9] = 'E';
    tree.nodes[10] = 'K';  // nuevo nodo agregado

    tree.numElements = 11;

    printf("Full Binary Tree:\n");
    for (int i = 0; i < tree.numElements; i++) {
        printf("[%d] %c\n", i, tree.nodes[i]);
    }

    return 0;
}
