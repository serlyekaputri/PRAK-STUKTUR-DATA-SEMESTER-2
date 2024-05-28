/*created_by_Serly Eka Putri_23343083*/
#include <stdio.h>

// Mendefinisikan struktur untuk data mahasiswa
struct Mahasiswa {
    int NIM;
    char Nama[50];
    char TanggalLahir[20];
    float IPK;
};

int main() {
    // Deklarasi variabel bertipe struct Mahasiswa
    struct Mahasiswa mhs1;

    // Mengisi nilai ke variabel struct mhs1
    mhs1.NIM = 23343083;
    strcpy(mhs1.Nama, "Serly Eka Putri");
    strcpy(mhs1.TanggalLahir, "02-02-2005");
    mhs1.IPK = 3.30;

    // Menampilkan informasi mahasiswa
    printf("Informasi Mahasiswa:\n");
    printf("NIM: %d\n", mhs1.NIM);
    printf("Nama: %s\n", mhs1.Nama);
    printf("Tanggal Lahir: %s\n", mhs1.TanggalLahir);
    printf("IPK: %.2f\n", mhs1.IPK);

    return 0;
}
