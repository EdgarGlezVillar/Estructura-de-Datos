#include <stdio.h>

#define QUEUESIZE 5

int queue[QUEUESIZE];
int front = 0;
int rear  = 0;
int numCurrentElements = 0;

int isEmpty() { return numCurrentElements == 0; }
int isFull()  { return numCurrentElements == QUEUESIZE; }

void enqueue(int val) {
    if (isFull()) {
        printf("La cola esta llena.\n");
        return;
    }
    queue[rear] = val;          // agregar al final
    numCurrentElements++;       // contar elemento
    rear++;                     // mover rear
    if (rear == QUEUESIZE) rear = 0; // vuelta circular
}

int dequeue() {
    if (isEmpty()) {
        printf("La cola esta vacia.\n");
        return -1;              // valor centinela
    }
    int val = queue[front];     // tomar del frente
    numCurrentElements--;       // descontar
    front++;                    // avanzar frente
    if (front == QUEUESIZE) front = 0; // vuelta circular
    return val;
}

void printQueue() {
    printf("\nQueue:");
    if (isEmpty()) { printf(" (vacia)\n"); return; }

    // Opción simple: imprimir contados desde front
    int idx = front;
    for (int k = 0; k < numCurrentElements; k++) {
        printf(" %d", queue[idx]);
        idx++;
        if (idx == QUEUESIZE) idx = 0; // vuelta circular
    }
    printf("   (front=%d, rear=%d, size=%d)\n", front, rear, numCurrentElements);
}

int main(void) {
    int opcion, valor;

    printf("Cola circular (tam=%d)\n", QUEUESIZE);
    printQueue();

    do {
        printf("\n1) Enqueue  2) Dequeue  3) Imprimir  0) Salir  -> ");
        if (scanf("%d", &opcion) != 1) return 0;

        if (opcion == 1) {
            printf("Valor: ");
            if (scanf("%d", &valor) != 1) return 0;
            enqueue(valor);
            printQueue();
        } else if (opcion == 2) {
            int out = dequeue();
            if (out != -1) printf("Desencolado: %d\n", out);
            printQueue();
        } else if (opcion == 3) {
            printQueue();
        }
    } while (opcion != 0);

    return 0;
}
