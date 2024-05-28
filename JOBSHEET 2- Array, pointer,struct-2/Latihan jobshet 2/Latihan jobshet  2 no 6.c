/*created-by-Serly-Eka-Putri-23343083 */
#include <stdio.h>

struct  mahasiswa {
	char nama[50];
	char jurusan[50];
	int nilai;
	
};
typedef struct mahasiswa data;
int main(void)
{
	data mhs01;
	
	strcpy(mhs01.nama, "______");
	strcpy(mhs01.jurusan, "______");
	mhs01.nilai = 100;
	
	printf("%s aadalah mahasiswa jurusan %s", mhs.nama, mhs01.jurusan);
	printf("memperoleh nialai UAS %i \n", mhs01.nilai);
	
	return 0;
}