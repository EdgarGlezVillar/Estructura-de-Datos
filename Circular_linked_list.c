#include <stdio.h>
#include <stdlib.h>

// Definición del nodo
typedef struct node {
    int data;
    struct node *next;
} Node;

Node *head = NULL;  // cabeza de la lista

// Verificar si la lista está vacía
int isEmpty() {
    return head == NULL;
}

// Agregar al frente
void addFront(int value) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = value;

    if (isEmpty()) {
        newNode->next = newNode;
        head = newNode;
    } else {
        Node *temp = head;
        while (temp->next != head)
            temp = temp->next;
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
}

// Agregar al final
void addEnd(int value) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = value;

    if (isEmpty()) {
        newNode->next = newNode;
        head = newNode;
    } else {
        Node *temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }
}

// Mostrar la lista completa
void display() {
    if (isEmpty()) {
        printf("\nLa lista está vacía.\n");
        return;
    }

    Node *temp = head;
    printf("\nLista circular: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Obtener tamaño de la lista
int size() {
    if (isEmpty()) return 0;
    int count = 0;
    Node *temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}

// Buscar valor
int search(int value) {
    if (isEmpty()) return 0;
    Node *temp = head;
    do {
        if (temp->data == value)
            return 1;
        temp = temp->next;
    } while (temp != head);
    return 0;
}

// Limpiar la lista
void clear() {
    if (isEmpty()) return;

    Node *temp = head;
    Node *nextNode;
    do {
        nextNode = temp->next;
        free(temp);
        temp = nextNode;
    } while (temp != head);
    head = NULL;
}

// Obtener primer y último nodo
int getHead() {
    if (isEmpty()) return -1;
    return head->data;
}

int getTail() {
    if (isEmpty()) return -1;
    Node *temp = head;
    while (temp->next != head)
        temp = temp->next;
    return temp->data;
}

// Prueba del programa
int main() {
    int val;

    printf("Agrega tres elementos a la lista:\n");
    for (int i = 0; i < 3; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%d", &val);
        addEnd(val);
    }

    display();
    printf("Tamaño: %d\n", size());
    printf("Primer elemento: %d\n", getHead());
    printf("Último elemento: %d\n", getTail());

    printf("\nAgrega un elemento al frente: ");
    scanf("%d", &val);
    addFront(val);

    display();
    printf("Tamaño: %d\n", size());

    printf("\nValor a buscar: ");
    scanf("%d", &val);
    if (search(val))
        printf("El valor %d está en la lista.\n", val);
    else
        printf("El valor %d no está en la lista.\n", val);

    clear();
    display();

    return 0;
}
