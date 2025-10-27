#include <stdio.h>

#define MAXSIZE 100

int treeNodes[MAXSIZE];
int last = 0;  // cuántos elementos hay en el heap

void insert(int item);
void reHeapUp(int index);
void reHeapDown(int index);
int removeMax(void);
void showHeap(void);

int main() {
    int i;
    int data[] = {42, 35, 23, 27, 21, 22, 4, 19};
    int n = 8;

    printf("=== INSERTANDO ELEMENTOS ===\n");
    for (i = 0; i < n; i++) {
        insert(data[i]);
        printf("\nDespués de insertar %d:\n", data[i]);
        showHeap();
    }

    printf("\n=== ELIMINANDO ELEMENTOS ===\n");
    for (i = 0; i < 3; i++) {
        int max = removeMax();
        printf("\nSe eliminó el máximo: %d\n", max);
        showHeap();
    }

    return 0;
}

void insert(int item) {
    treeNodes[last] = item;
    reHeapUp(last);
    last++;
}

// Subir el nuevo elemento si es mayor que su padre
void reHeapUp(int index) {
    int i = index;
    int parent = (i - 1) / 2;
    int aux;

    while (i > 0 && treeNodes[i] > treeNodes[parent]) {
        aux = treeNodes[i];
        treeNodes[i] = treeNodes[parent];
        treeNodes[parent] = aux;

        i = parent;
        parent = (i - 1) / 2;
    }
}

int removeMax(void) {
    int max;

    if (last == 0) {
        printf("El heap está vacío\n");
        return -1;
    }

    max = treeNodes[0];
    treeNodes[0] = treeNodes[last - 1];
    last--;

    reHeapDown(0);

    return max;
}

// Bajar el elemento de la raíz si es menor que alguno de sus hijos
void reHeapDown(int index) {
    int i = index;
    int left, right, bigger;
    int aux;

    while (1) {
        left = 2 * i + 1;
        right = 2 * i + 2;
        bigger = i;

        if (left < last && treeNodes[left] > treeNodes[bigger])
            bigger = left;

        if (right < last && treeNodes[right] > treeNodes[bigger])
            bigger = right;

        if (bigger == i)
            break;

        aux = treeNodes[i];
        treeNodes[i] = treeNodes[bigger];
        treeNodes[bigger] = aux;

        i = bigger;
    }
}

void showHeap(void) {
    int i;
    printf("Heap: ");
    for (i = 0; i < last; i++) {
        printf("%d ", treeNodes[i]);
    }
    printf("\n");
}
