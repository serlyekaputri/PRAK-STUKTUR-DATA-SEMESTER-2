// created_by_Serly Eka Putri_23343083
// 7. Selection Sort – Entry Elements Cara 2

#include <stdio.h>

int main() {
    int a[100], n, i, j, position, swap;
    printf("Masukkan jumlah elemen: ");
    scanf("%d", &n);
    printf("Masukkan %d buah bilangan\n", n);
    
    // Menggunakan loop untuk memasukkan bilangan ke dalam array
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Algoritma selection sort untuk mengurutkan array
    for (i = 0; i < n - 1; i++) {
        position = i; // Inisialisasi posisi awal sebagai indeks saat ini
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[position]) {
                position = j; // Perbarui posisi jika ditemukan elemen yang lebih kecil
            }
        }
        // Tukar elemen saat ini dengan elemen terkecil yang ditemukan
        swap = a[i];
        a[i] = a[position];
        a[position] = swap;
    }

    printf("Array yang telah diurutkan:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}
