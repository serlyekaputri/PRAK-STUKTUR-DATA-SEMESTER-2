/*created_by_Serly Eka Putri_23343083*/

#include <stdio.h>

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
    scanf("%s", mhs->Nama);
    printf("Masukkan Tanggal Lahir (dd-mm-yyyy): ");
    scanf("%s", mhs->TanggalLahir);
    printf("Masukkan IPK: ");
    scanf("%f", &mhs->IPK);
}

// Fungsi untuk menampilkan data mahasiswa
void tampilkanDataMahasiswa(struct Mahasiswa mhs) {
    printf("\nInformasi Mahasiswa:\n");
    printf("NIM: %d\n", mhs.NIM);
    printf("Nama: %s\n", mhs.Nama);
    printf("Tanggal Lahir: %s\n", mhs.TanggalLahir);
    printf("IPK: %.2f\n", mhs.IPK);
}

int main() {
    struct Mahasiswa mhs1;

    // Memanggil fungsi inputDataMahasiswa untuk mengisi data mahasiswa
    inputDataMahasiswa(&mhs1);

    // Memanggil fungsi tampilkanDataMahasiswa untuk menampilkan data mahasiswa yang telah diinput
    tampilkanDataMahasiswa(mhs1);

    return 0;
}
