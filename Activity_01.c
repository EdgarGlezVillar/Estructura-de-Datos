#include <stdio.h>
#include <stdlib.h>

// Definición del nodo
typedef struct node {
    int data;
    struct node *next;
} Node;

// Puntero HEAD
Node *head = NULL;

// Función para mostrar la lista
void showList() {
    if (head == NULL) {
        printf("\nLa lista está vacía\n");
    } else {
        Node *aux = head;
        printf("\nLista: ");
        while (aux != NULL) {
            printf("%d ", aux->data);
            aux = aux->next;
        }
        printf("\n");
    }
}

int main() {
    int ans = 0;

    do {
        printf("\nPresiona '0' para agregar un número, otro valor para salir: ");
        scanf("%d", &ans);

        if (ans == 0) {
            // 1. Crear nodo
            Node *newNode = (Node*) malloc(sizeof(Node));
            if (newNode != NULL) {
                // 2. Inicializar nodo
                printf("Ingresa el número: ");
                scanf("%d", &(newNode->data));
                newNode->next = NULL;

                // 3. Agregar nodo a la lista
                if (head == NULL) {
                    head = newNode;   // primer nodo
                } else {
                    Node *aux = head;
                    while (aux->next != NULL) {
                        aux = aux->next;
                    }
                    aux->next = newNode;  // enlazar al final
                }
            }
        }
    } while (ans == 0);

    // Mostrar la lista resultante
    showList();

    return 0;
}
