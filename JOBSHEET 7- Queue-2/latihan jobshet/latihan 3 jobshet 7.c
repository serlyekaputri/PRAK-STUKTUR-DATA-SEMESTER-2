/* cretead_by_Serly Eka Putri-23343083 */

#include <stdio.h>

#define ukuran 6
int queue[ukuran];
int front = -1;
int rear = -1;

void enqueue(int element) {
    if ((front == 0 && rear == ukuran - 1) || (rear == (front - 1) % (ukuran - 1))) {
        printf("Antrian telah penuh.\n");
        return;
    } else if (front == -1) {
        front = rear = 0;
    } else if (rear == ukuran - 1 && front != 0) {
        rear = 0;
    } else {
        rear++;
    }
    queue[rear] = element;
}

void dequeue() {
    if (front == -1) {
        printf("\nQueue belum penuh.\n");
        return;
    }
    printf("\nElemen yang di dequeue adalah %d\n", queue[front]);
    if (front == rear) {
        front = rear = -1;
    } else if (front == ukuran - 1) {
        front = 0;
    } else {
        front++;
    }
}

void display() {
    if (front == -1) {
        printf("\nQueue kosong.\n");
        return;
    }
    printf("\nElemen pada queue adalah: ");
    if (rear >= front) {
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
    } else {
        for (int i = front; i < ukuran; i++)
            printf("%d ", queue[i]);
        for (int i = 0; i <= rear; i++)
            printf("%d ", queue[i]);
    }
}

int main() {
    int menu = 1, x;
    while (menu != 0) {
        printf("\n******************Circular Queue*****************\n");
        printf("\n=================================================\n");
        printf("\n1: Tambah sebuah elemen");
        printf("\n2: Hapus sebuah elemen");
        printf("\n3: Tampilkan sebuah elemen");
        printf("\n0: Keluar");
        printf("\nMasukkan pilihanmu: ");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                printf("Silakan masukkan elemen yang ingin kamu tambah: ");
                scanf("%d", &x);
                enqueue(x);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 0:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
                break;
        }
    }
    return 0;
}
