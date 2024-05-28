// created_by_Serly Eka Putri_23343083
// 4. Selection Sort – Proses Iterasi Pengurutan Data

#include <stdio.h>
#include <stdbool.h>

#define MAX 7

int intArray[MAX] = {4, 6, 3, 2, 1, 9, 7};

void printline(int count) {
    int i;
    for (i = 0; i < count - 1; i++) {
        printf("=");
    }
    printf("=\n");
}

void display() {
    int i;
    printf("[");
    // navigate through all items
    for (i = 0; i < MAX; i++) {
        printf("%d ", intArray[i]);
    }
    printf("]\n");
}

void selectionSort() {
    int indexMin, i, j;
    // loop through all numbers
    for (i = 0; i < MAX - 1; i++) {
        // set current element as minimum
        indexMin = i;
        // check the element to be minimum
        for (j = i + 1; j < MAX; j++) {
            if (intArray[j] < intArray[indexMin]) {
                indexMin = j;
            }
        }
        if (indexMin != i) {
            printf("Items swapped: [ %d, %d ]\n", intArray[i], intArray[indexMin]);
            // swap the numbers
            int temp = intArray[indexMin];
            intArray[indexMin] = intArray[i];
            intArray[i] = temp;
        }
        printf("Iteration %d#:", (i + 1));
        display();
    }
}

int main() {
    printf("Input array: ");
    display();
    printline(50);
    selectionSort();
    printf("Output array: ");
    display();
    printline(50);
    return 0;
}
