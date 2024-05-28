// created_by_Serly Eka Putri_23343083
// 1.	Shell sort 1 

#include <stdio.h>

void shellsort(int array[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += 1) {
            int temp = array[i];
            int j;
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap) {
                array[j] = array[j - gap];
            }
            array[j] = temp;
        }
    }
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d ", array[i]); // Menambahkan spasi di sini
    }
    printf("\n");
}

int main() {
    int data[] = {9, 6, 3, 7, 6, 4, 1};
    int size = sizeof(data) / sizeof(data[0]); // Menambahkan deklarasi dan inisialisasi size
    shellsort(data, size);
    printf("Sorted array:\n");
    printArray(data, size);
    return 0;
}
