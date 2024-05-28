// created_by_Serly Eka Putri_23343083\
// 2. Merge Sort – Before and After 

#include <stdio.h>

#define MAX 10

int a[MAX + 1] = {10, 14, 19, 26, 27, 31, 33, 35, 42, 44, 0};
int b[MAX];

void merging(int low, int mid, int high) {
    int l1, l2, i;

    for (l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
        if (a[l1] <= a[l2]) 
            b[i] = a[l1++];
        else 
            b[i] = a[l2++];
    }

    while (l1 <= mid)
        b[i++] = a[l1++];
    while (l2 <= high)
        b[i++] = a[l2++];

    for (i = low; i <= high; i++)
        a[i] = b[i];
}

void sort(int low, int high) {
    int mid;
    if (low < high) {
        mid = (low + high) / 2;
        sort(low, mid);
        sort(mid + 1, high);
        merging(low, mid, high);
    }
}

int main() {
    int i;

    printf("Data sebelum diurutkan:\n");
    for (i = 0; i < MAX; i++)
        printf("%d ", a[i]);

    sort(0, MAX - 1);

    printf("\nData setelah diurutkan:\n");
    for (i = 0; i < MAX; i++)
        printf("%d ", a[i]);

    return 0;
}
