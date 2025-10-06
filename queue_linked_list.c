#include <stdio.h>
#include <stdlib.h>

// Definición de nodo
typedef struct node {
    int data;
    struct node *next;
} Node;

// Punteros globales
Node *front = NULL;   // primer elemento (cabeza de la cola)
Node *rear  = NULL;   // último elemento (cola final)

// Verificar si la cola está vacía
int isEmpty() {
    return front == NULL;
}

// Enqueue (agregar al final)
void enqueue(int value) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Enqueued: %d\n", value);
}

// Dequeue (quitar del frente)
void dequeue() {
    if (isEmpty()) {
        printf("La cola está vacía.\n");
        return;
    }

    Node *temp = front;
    int value = temp->data;
    front = front->next;

    if (front == NULL)
        rear = NULL;  // si ya no hay elementos

    free(temp);
    printf("Dequeued: %d\n", value);
}

// Mostrar todos los elementos
void display() {
    if (isEmpty()) {
        printf("Cola vacía.\n");
        return;
    }

    Node *temp = front;
    printf("Cola (front → rear): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Obtener el elemento al frente
int getFront() {
    if (isEmpty()) return -1;
    return front->data;
}

// Obtener el elemento al final
int getRear() {
    if (isEmpty()) return -1;
    return rear->data;
}

// Limpiar toda la cola
void clear() {
    while (!isEmpty()) {
        dequeue();
    }
}

// Probar el ADT
int main() {
    int choice, value;

    do {
        printf("\n--- Queue ADT ---\n");
        printf("1) Enqueue\n");
        printf("2) Dequeue\n");
        printf("3) Display\n");
        printf("4) Get Front\n");
        printf("5) Get Rear\n");
        printf("0) Exit\n");
        printf("Opción: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Valor: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                if (!isEmpty())
                    printf("Front = %d\n", getFront());
                else
                    printf("Cola vacía.\n");
                break;
            case 5:
                if (!isEmpty())
                    printf("Rear = %d\n", getRear());
                else
                    printf("Cola vacía.\n");
                break;
            case 0:
                clear();
                printf("Programa terminado.\n");
                break;
            default:
                printf("Opción inválida.\n");
        }
    } while (choice != 0);

    return 0;
}
