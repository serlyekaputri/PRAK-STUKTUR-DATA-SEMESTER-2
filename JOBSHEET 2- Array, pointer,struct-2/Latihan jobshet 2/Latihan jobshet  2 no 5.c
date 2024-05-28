#include <stdio.h>

struct mahasiswa {
	char nama[50];
	char jurusan[50];
	int nilai;
};

int main(void)
{
	struct mahasiswa mhs01;
	
	strcpy(mhs01.nama, "__________");
	strcpy(mhs01.jurusan, "_________");
	mhs01.nilai = 100;
	
	printf("%s adalah mahasiswa jurusan %s ", mhs.nama, mhs01.jurusan);
	printf("memperoleh nilai UAS %i \n", mhs01.nnilai);
	
	return 0;
}