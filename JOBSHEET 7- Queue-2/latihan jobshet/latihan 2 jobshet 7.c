/* cretead_by_Serly Eka Putri-23343083 */

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *front = NULL; // Inisialisasi front dan rear
struct node *rear = NULL;

void tambah();
void hapus();
void display();

int main() {
    int menu;
    while (menu != 4) {
        printf("\n***************** Queue Menggunakan Linked List ****************\n");
        printf("\n==============================================================\n");
        printf("\n1. Tambah sebuah elemen\n2. Hapus sebuah elemen\n3. Tampilkan antrian\n4. Keluar\n");
        printf("\nMasukkan pilihanmu: ");
        scanf("%d", &menu);
        switch (menu) {
            case 1:
                tambah();
                break;
            case 2:
                hapus();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\nKeluar dari program...\n");
                return 0; // Menggunakan return 0 untuk keluar dari program
            default:
                printf("\nMasukkan pilihan menu yang sesuai\n");
        }
    }
    return 0;
}

void tambah() {
    struct node *ptr;
    int item;
    ptr = (struct node *) malloc (sizeof(struct node));
    if (ptr == NULL) {
        printf("\nOVERFLOW\n");
        return;
    } else {
        printf("\nSilakan masukkan elemen yang kamu inginkan: ");
        scanf("%d", &item);
        ptr->data = item;
        ptr->next = NULL;
        if (front == NULL) {
            front = ptr;
            rear = ptr;
        } else {
            rear->next = ptr;
            rear = ptr;
        }
    }
}

void hapus() {
    struct node *ptr;
    if (front == NULL) {
        printf("\nUNDERFLOW\n");
        return;
    } else {
        ptr = front;
        front = front->next;
        free(ptr);
    }
}

void display() {
    struct node *ptr;
    ptr = front;
    if (front == NULL) {
        printf("\nAntrian kosong\n");
    } else {
        printf("\nMenampilkan antrian .......\n");
        while (ptr != NULL) {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}
