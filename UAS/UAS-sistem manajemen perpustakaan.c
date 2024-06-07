// Created_by_Serly Eka Putri_23343083

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definisi panjang maksimal judul dan penulis buku
#define MAX_JUDUL_LENGTH 50
#define MAX_PENULIS_LENGTH 50

// Definisi struktur Buku
typedef struct Buku {
    int id; // ID buku
    char judul[MAX_JUDUL_LENGTH]; // Judul buku
    char penulis[MAX_PENULIS_LENGTH]; // Penulis buku
    int dipinjam; // Status peminjaman (0: tersedia, 1: dipinjam)
    struct Buku *next; // Pointer ke buku berikutnya dalam linked list
} Buku;

Buku *head = NULL; // Pointer ke buku pertama dalam linked list
int jumlahBuku = 0; // Jumlah buku dalam perpustakaan

// Fungsi untuk menambah buku baru
void tambahBuku() {
    Buku *bukuBaru = (Buku *)malloc(sizeof(Buku)); // Alokasi memori untuk buku baru
    if (!bukuBaru) {
        printf("Gagal mengalokasikan memori.\n");
        return;
    }

    bukuBaru->id = jumlahBuku + 1; // Mengatur ID buku
    printf("Masukkan judul: ");
    scanf(" %[^\n]%*c", bukuBaru->judul); // Membaca judul buku
    printf("Masukkan penulis: ");
    scanf(" %[^\n]%*c", bukuBaru->penulis); // Membaca penulis buku
    bukuBaru->dipinjam = 0; // Status buku adalah tersedia
    bukuBaru->next = NULL; // Tidak ada buku berikutnya

    if (!head) {
        head = bukuBaru; // Jika belum ada buku, set buku baru sebagai head
    } else {
        Buku *temp = head;
        while (temp->next) {
            temp = temp->next; // Menemukan buku terakhir dalam linked list
        }
        temp->next = bukuBaru; // Tambahkan buku baru di akhir linked list
    }

    jumlahBuku++; // Tambah jumlah buku
    printf("Buku berhasil ditambahkan!\n");
}

// Fungsi untuk meminjam buku
void pinjamBuku() {
    int id;
    printf("Masukkan ID buku yang ingin dipinjam: ");
    scanf("%d", &id); // Membaca ID buku yang ingin dipinjam

    Buku *temp = head;
    while (temp) {
        if (temp->id == id) {
            if (temp->dipinjam) {
                printf("Buku sudah dipinjam.\n");
            } else {
                temp->dipinjam = 1; // Mengubah status buku menjadi dipinjam
                printf("Anda berhasil meminjam \"%s\".\n", temp->judul);
            }
            return;
        }
        temp = temp->next;
    }
    printf("Buku tidak ditemukan.\n");
}

// Fungsi untuk mengembalikan buku
void kembalikanBuku() {
    int id;
    printf("Masukkan ID buku yang ingin dikembalikan: ");
    scanf("%d", &id); // Membaca ID buku yang ingin dikembalikan

    Buku *temp = head;
    while (temp) {
        if (temp->id == id) {
            if (!temp->dipinjam) {
                printf("Buku tidak dipinjam.\n");
            } else {
                temp->dipinjam = 0; // Mengubah status buku menjadi tersedia
                printf("Anda berhasil mengembalikan \"%s\".\n", temp->judul);
            }
            return;
        }
        temp = temp->next;
    }
    printf("Buku tidak ditemukan.\n");
}

// Fungsi untuk mencari buku berdasarkan judul atau penulis
void cariBuku() {
    char kataKunci[MAX_JUDUL_LENGTH];
    printf("Masukkan judul atau penulis untuk mencari: ");
    scanf(" %[^\n]%*c", kataKunci); // Membaca kata kunci pencarian

    Buku *temp = head;
    while (temp) {
        if (strstr(temp->judul, kataKunci) != NULL || strstr(temp->penulis, kataKunci) != NULL) {
            printf("ID: %d, Judul: %s, Penulis: %s, %s\n", temp->id, temp->judul, temp->penulis,
                   temp->dipinjam ? "Dipinjam" : "Tersedia"); // Menampilkan informasi buku yang cocok dengan kata kunci
        }
        temp = temp->next;
    }
}

// Fungsi untuk menampilkan daftar semua buku
void daftarBuku() {
    printf("\nDaftar buku di perpustakaan:\n");
    Buku *temp = head;
    while (temp) {
        printf("ID: %d, Judul: %s, Penulis: %s, %s\n", temp->id, temp->judul, temp->penulis,
               temp->dipinjam ? "Dipinjam" : "Tersedia"); // Menampilkan informasi semua buku
        temp = temp->next;
    }
}

// Fungsi untuk menukar informasi antara dua buku
void tukarBuku(Buku *a, Buku *b) {
    int idTemp = a->id;
    char judulTemp[MAX_JUDUL_LENGTH];
    char penulisTemp[MAX_PENULIS_LENGTH];
    int dipinjamTemp = a->dipinjam;

    strcpy(judulTemp, a->judul);
    strcpy(penulisTemp, a->penulis);

    a->id = b->id;
    strcpy(a->judul, b->judul);
    strcpy(a->penulis, b->penulis);
    a->dipinjam = b->dipinjam;

    b->id = idTemp;
    strcpy(b->judul, judulTemp);
    strcpy(b->penulis, penulisTemp);
    b->dipinjam = dipinjamTemp;
}

// Fungsi untuk mengurutkan buku berdasarkan judul
void sortBuku() {
    if (!head || !head->next) {
        return;
    }

    int swapped;
    Buku *ptr1;
    Buku *lptr = NULL;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (strcmp(ptr1->judul, ptr1->next->judul) > 0) {
                tukarBuku(ptr1, ptr1->next); // Menukar buku jika urutannya salah
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);

    printf("Buku berhasil diurutkan berdasarkan judul.\n");
}

// Fungsi utama yang berisi menu program
int main() {
    int pilihan;

    while (1) {
        printf("\nSistem Manajemen Perpustakaan\n");
        printf("1. Tambah Buku\n");
        printf("2. Pinjam Buku\n");
        printf("3. Kembalikan Buku\n");
        printf("4. Cari Buku\n");
        printf("5. Daftar Semua Buku\n");
        printf("6. Urutkan Buku Berdasarkan Judul\n");
        printf("7. Keluar\n");
        printf("Masukkan pilihan Anda: ");
        scanf("%d", &pilihan); // Membaca pilihan dari pengguna

        switch (pilihan) {
            case 1:
                tambahBuku();
                break;
            case 2:
                pinjamBuku();
                break;
            case 3:
                kembalikanBuku();
                break;
            case 4:
                cariBuku();
                break;
            case 5:
                daftarBuku();
                break;
            case 6:
                sortBuku();
                break;
            case 7:
                exit(0); // Keluar dari program
            default:
                printf("Pilihan tidak valid!\n");
        }
    }

    return 0;
}
