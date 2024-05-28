/*created_by_Serly Eka Putri_23343083*/

#include <stdio.h>
#include <stdlib.h> // Untuk menggunakan fungsi exit()

// Mendefinisikan struktur untuk data mahasiswa
struct Mahasiswa {
    int NIM;
    char Nama[50];
    char TanggalLahir[20];
    float IPK;
};

// Fungsi untuk input data mahasiswa
void inputDataMahasiswa(struct Mahasiswa *mhs) {
    printf("Masukkan NIM: ");
    scanf("%d", &mhs->NIM);

    printf("Masukkan Nama: ");
    getchar(); // Mengonsumsi karakter newline sebelum menerima input
    fgets(mhs->Nama, sizeof(mhs->Nama), stdin);

    printf("Masukkan Tanggal Lahir: ");
    scanf("%s", mhs->TanggalLahir);

    printf("Masukkan IPK: ");
    scanf("%f", &mhs->IPK);
}

int main() {
    struct Mahasiswa mhs1;

    // Memanggil fungsi inputDataMahasiswa untuk mengisi data mahasiswa
    inputDataMahasiswa(&mhs1);

    // Menampilkan informasi mahasiswa yang telah diinput
    printf("\nInformasi Mahasiswa:\n");
    printf("NIM: %d\n", mhs1.NIM);
    printf("Nama: %s", mhs1.Nama); // Nama sudah berupa string, tidak perlu format %s
    printf("Tanggal Lahir: %s\n", mhs1.TanggalLahir);
    printf("IPK: %.2f\n", mhs1.IPK);

    return 0;
}
