#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate an n x n matrix with random numbers
void generate_matrix(double** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = (double)rand() / RAND_MAX;  // Generates random numbers between 0 and 1
        }
    }
}

// Function for matrix multiplication
void multiply_matrices(double** a, double** b, double** c, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c[i][j] = 0;
            for (int k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <matrix_size>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);  // Matrix size passed as an argument

    // Allocate memory for the matrices
    double** a = (double**)malloc(n * sizeof(double*));
    double** b = (double**)malloc(n * sizeof(double*));
    double** c = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        a[i] = (double*)malloc(n * sizeof(double));
        b[i] = (double*)malloc(n * sizeof(double));
        c[i] = (double*)malloc(n * sizeof(double));
    }

    // Generate matrices A and B with random values
    srand(time(NULL));
    generate_matrix(a, n);
    generate_matrix(b, n);

    // Perform the multiplication
    clock_t start = clock();
    multiply_matrices(a, b, c, n);
    clock_t end = clock();

    // Calculate the execution time
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Matrix multiplication of size %dx%d took %f seconds.\n", n, n, time_spent);

    // Free the memory
    for (int i = 0; i < n; i++) {
        free(a[i]);
        free(b[i]);
        free(c[i]);
    }
    free(a);
    free(b);
    free(c);

    return 0;