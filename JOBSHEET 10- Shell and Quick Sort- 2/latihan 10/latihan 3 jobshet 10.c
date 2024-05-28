// created_by_Serly Eka Putri_23343083
// 3.	Shell sort 3 

#include <stdio.h>

void shellsort(int a[], int n) {
    int increment, i, j, tmp;
    for (increment = n / 2; increment > 0; increment /= 2) {
        for (i = increment; i < n; i++) {
            tmp = a[i];
            for (j = i; j >= increment; j -= increment) {
                if (tmp < a[j - increment])
                    a[j] = a[j - increment];
                else
                    break;
            }
            a[j] = tmp;
        }
    }
}

int main() {
    int i, n, a[10];

    printf("Masukkan jumlah elemen: ");
    scanf("%d", &n);
    printf("Masukkan %d bilangan:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    shellsort(a, n);

    printf("Elemen yang telah diurutkan adalah:\n");
    for (i = 0; i < n; i++) {
        printf("%d\n", a[i]);
    }
    printf("\n");

    return 0;
}
