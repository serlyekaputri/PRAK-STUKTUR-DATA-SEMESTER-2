/* created_by_Serly Eka Putri */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Fungsi untuk mengecek apakah suatu bilangan adalah bilangan prima
bool isPrime(int num) {
    if (num <= 1) 
        return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}

// Fungsi untuk mencetak bilangan prima pertama sampai ke-n
void printPrimes(int n) {
    int count = 0;
    int *primes = NULL;
    int current_num = 2; // Dimulai dari bilangan 2
    
    while (count < n) {
        if (isPrime(current_num)) {
            count++;
            primes = realloc(primes, count * sizeof(int));
            if (primes == NULL) {
                printf("Pengalokasian memori gagal.");
                exit(1);
            }
            primes[count - 1] = current_num;
        }
        current_num++;
    }
    
    printf("Bilangan prima pertama %d:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");

    // Free memory yang telah dialokasikan
    free(primes);
}

int main() {
    int n, m;

    printf("Masukkan nilai n: ");
    scanf("%d", &n);

    printf("Masukkan ukuran memori baru (m): ");
    scanf("%d", &m);

    // Periksa jika n atau m <= 0
    if (n <= 0 || m <= 0) {
        printf("Nilai n dan m harus lebih besar dari 0.\n");
        return 1;
    }

    printPrimes(n);

    return 0;
}
