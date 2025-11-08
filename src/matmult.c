#include <stdio.h>
#include <stdlib.h>

#define N 2000  // Matrix size (N x N)

// Function to print matrix
void printMatrix(float* mat, int n) {
    for (int i = 0; i < n; i++) {
        printf("[ ");
        for (int j = 0; j < n; j++) {
            printf("%6.2f ", mat[i * n + j]);
        }
        printf("]\n");
    }
    putchar('\n');
}

// Function for matrix multiplication on CPU
void matMulCPU(float* A, float* B, float* C, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            float sum = 0.0f;
            for (int k = 0; k < n; k++) {
                sum += A[i * n + k] * B[k * n + j];
            }
            C[i * n + j] = sum;
        }
    }
}

int main() {
    int size = N * N;

    // Allocate memory
    float* A = (float*)malloc(size * sizeof(float));
    float* B = (float*)malloc(size * sizeof(float));
    float* C = (float*)malloc(size * sizeof(float));

    // Initialize matrices
    for (int i = 0; i < size; i++) {
        A[i] = i + 1;
        B[i] = (i + 1) * 0.5f;
    }

    // printf("Matrix A:\n");
    // printMatrix(A, N);

    // printf("Matrix B:\n");
    // printMatrix(B, N);

    // Multiply matrices
    matMulCPU(A, B, C, N);

    printf("Matrix C (A x B) on CPU:\n");
    // printMatrix(C, N);

    // Free memory
    free(A);
    free(B);
    free(C);

    return 0;
}
