#include <stdio.h>
#define MAX 1000

int isEmpty(int top) {
    return top == -1;
}

int isFull(int top, int cap) {
    return top == cap - 1;
}

int main(void) {
    char s[MAX];
    if (!fgets(s, sizeof s, stdin)) return 0;

    char stack[MAX];   // pila para aperturas
    int pos[MAX];      // posición de cada apertura
    int top = -1;      // pila vacía
    int ok = 1;

    for (int i = 0; s[i] && s[i] != '\n'; i++) {
        char c = s[i];

        // ignorar lo que no sea paréntesis, corchete o llave
        if (c!='(' && c!=')' && c!='[' && c!=']' && c!='{' && c!='}')
            continue;

        // caso: apertura
        if (c=='(' || c=='[' || c=='{') {
            if (isFull(top, MAX)) {
                printf("ERROR %d\n", i);
                return 0;
            }
            stack[++top] = c;
            pos[top] = i;
        }

        // caso: cierre
        else {
            if (isEmpty(top)) {
                printf("ERROR %d\n", i); // cierre sin apertura
                return 0;
            }
            char t = stack[top--];
            if ((c==')' && t!='(') ||
                (c==']' && t!='[') ||
                (c=='}' && t!='{')) {
                printf("ERROR %d\n", i); // cierre que no coincide
                return 0;
            }
        }
    }

    // al final, si quedan aperturas sin cerrar
    if (!isEmpty(top)) {
        printf("ERROR %d\n", pos[0]); // primer opener sin pareja
        return 0;
    }

    printf("OK\n");
    return 0;
}
