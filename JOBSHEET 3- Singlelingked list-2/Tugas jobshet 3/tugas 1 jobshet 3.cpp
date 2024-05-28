/* created_by_Serly Eka Putri */

#include <stdio.h>
#include <stdlib.h>

// Fungsi untuk menghasilkan deret Fibonacci
int *fibonacci(int n) {
    int *fib = (int *)malloc(n * sizeof(int));
    
    if (fib == NULL) {
        printf("Pengalokasian memori gagal.");
        exit(1);
    }
    
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    
    return fib;
}

int main() {
    int n;

    printf("Masukkan nilai n: ");
    scanf("%d", &n);

    // Periksa jika n <= 0
    if (n <= 0) {
        printf("Nilai n harus lebih besar dari 0.\n");
        return 1;
    }

    int *fib = fibonacci(n);

    // Tampilkan deret Fibonacci
    printf("Deret Fibonacci pertama %d:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", fib[i]);
    }
    printf("\n");

    // Free memory yang telah dialokasikan
    free(fib);

    return 0;
}
