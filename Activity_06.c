#include <stdio.h>
#include <stdlib.h>

/* Helper for row/col indexing if needed later */
int idx(int r, int c, int cols) {
    return r * cols + c;
}

int main(void) {
    int rows, cols;
    scanf("%d %d", &rows, &cols);

    /* Allocate row-pointer arrays */
    int **A = (int**)malloc(rows * sizeof(int*));
    int **B = (int**)malloc(rows * sizeof(int*));
    int **C = (int**)malloc(rows * sizeof(int*));

    /* Allocate each row */
    for (int i = 0; i < rows; i++) {
        A[i] = (int*)malloc(cols * sizeof(int));
        B[i] = (int*)malloc(cols * sizeof(int));
        C[i] = (int*)malloc(cols * sizeof(int));
    }

    /* Bytes info (per row and per int) */
    printf("Bytes for row-pointer arrays: %zu\n", (size_t)rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        printf("Row %d of A uses %zu bytes (%d ints)\n",
               i, (size_t)cols * sizeof(int), cols);
    }
    printf("\n");

    /* Fill A */
    printf("Enter %d integers for A (%dx%d):\n", rows*cols, rows, cols);
    for (int r = 0; r < rows; r++)
        for (int c = 0; c < cols; c++)
            scanf("%d", (A[r] + c));

    /* Fill B */
    printf("Enter %d integers for B (%dx%d):\n", rows*cols, rows, cols);
    for (int r = 0; r < rows; r++)
        for (int c = 0; c < cols; c++)
            scanf("%d", (B[r] + c));

    /* Compute C = A + B */
    for (int r = 0; r < rows; r++)
        for (int c = 0; c < cols; c++)
            *(*(C + r) + c) = *(*(A + r) + c) + *(*(B + r) + c);

    /* Print A */
    printf("\nMatrix A:\n");
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++)
            printf("%4d", *(*(A + r) + c));
        printf("\n");
    }

    /* Print B */
    printf("\nMatrix B:\n");
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++)
            printf("%4d", *(*(B + r) + c));
        printf("\n");
    }

    /* Print C */
    printf("\nMatrix C = A + B:\n");
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++)
            printf("%4d", *(*(C + r) + c));
        printf("\n");
    }

    /* Free memory */
    for (int i = 0; i < rows; i++) {
        free(A[i]); free(B[i]); free(C[i]);
    }
    free(A); free(B); free(C);

    return 0;
}
