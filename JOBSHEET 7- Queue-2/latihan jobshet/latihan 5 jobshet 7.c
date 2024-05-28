/* cretead_by_Serly Eka Putri-23343083 */

// 5. Priority Queue 

#include <stdio.h>

int ukuran = 0;

// Fungsi untuk menukar elemen
void swap(int *a, int *b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

// Fungsi untuk mengatur ulang elemen heap pada tree
void heapify(int array[], int ukuran, int i) {
    if (ukuran == 1) {
        printf("Elemen tunggal pada heap\n");
    } else {
        // Menemukan yang terbesar di antara root, left child, dan right child
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < ukuran && array[l] > array[largest])
            largest = l;
        if (r < ukuran && array[r] > array[largest])
            largest = r;

        // Tukar dan lanjutkan proses untuk mengatur ulang elemen heap jika root bukan yang terbesar
        if (largest != i) {
            swap(&array[i], &array[largest]);
            heapify(array, ukuran, largest);
        }
    }
}

// Fungsi untuk memasukkan elemen pada tree
void insert(int array[], int newNUM) {
    if (ukuran == 0) {
        array[0] = newNUM;
        ukuran = 1;
    } else {
        array[ukuran] = newNUM;
        ukuran += 1;
        for (int i = ukuran / 2 - 1; i >= 0; i--) {
            heapify(array, ukuran, i);
        }
    }
}

// Fungsi untuk menghapus elemen dari tree
void deleteRoot(int array[], int num) {
    int i;
    for (i = 0; i < ukuran; i++) {
        if (num == array[i])
            break;
    }
    swap(&array[i], &array[ukuran - 1]);
    ukuran -= 1;
    for (int i = ukuran / 2 - 1; i >= 0; i--) {
        heapify(array, ukuran, i);
    }
}

// Menampilkan array
void printArray(int array[], int ukuran) {
    for (int i = 0; i < ukuran; ++i)
        printf("%d ", array[i]);
    printf("\n");
}

// Kode driver untuk menjalankan program
int main() {
    int array[10];
    insert(array, 3);
    insert(array, 4);
    insert(array, 9);
    insert(array, 5);
    insert(array, 2);

    printf("max-heap array adalah: ");
    printArray(array, ukuran);

    deleteRoot(array, 4);
    printf("setelah proses penghapusan elemen: ");
    printArray(array, ukuran);

    return 0;
}
