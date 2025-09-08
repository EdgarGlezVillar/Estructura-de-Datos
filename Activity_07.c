#include <stdio.h>

void printSpiral(int rows, int cols, int matrix[rows][cols]) {
    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;

    while (top <= bottom && left <= right) {
        // Traverse left to right
        for (int i = left; i <= right; i++)
            printf("%d ", matrix[top][i]);
        top++;

        // Traverse top to bottom
        for (int i = top; i <= bottom; i++)
            printf("%d ", matrix[i][right]);
        right--;

        // Traverse right to left
        if (top <= bottom) {
            for (int i = right; i >= left; i--)
                printf("%d ", matrix[bottom][i]);
            bottom--;
        }

        // Traverse bottom to top
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                printf("%d ", matrix[i][left]);
            left++;
        }
    }
}

int main() {
    int matrix[5][4] = {
        {1, 2, 3, 4},
        {14, 15, 16, 5},
        {13, 20, 17, 6},
        {12, 19, 18, 7},
        {11, 10, 9, 8}
    };

    int rows = 5, cols = 4;
    printf("Spiral order: ");
    printSpiral(rows, cols, matrix);
    return 0;
}
