/**
Versi 1
===========
26-September-2021
===========
Peminjaman BUKU
- Login
- Tampil list buku
- Pinjam Buku

DATA BUKU
----------
id
nama
pengarang
hargaSewa perhari

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define USERNAME "agus"
#define PASSWORD "agus"
#define NAMA "Agus Darmawan"

#define MAX_ID 10
#define MAX_NAMA 40
#define MAX_STRUCT 50

typedef struct {
    char id[MAX_ID];
    char namaBuku[MAX_NAMA];
    int hargaSewa;
} DATA_BUKU;

DATA_BUKU listBuku[MAX_STRUCT];
int banyakBuku = 0;

void tampilListBuku() {

    if(banyakBuku == 0) {
        printf("Buku masih kosong!\n");
        return;
    }

    int i;

    printf("================================================================================\n");
    printf("||%-5s||%-10s||%-40s||%-15s||\n", "No", "ID", "Nama", "Harga");
    printf("================================================================================\n");
    for(i = 0; i < banyakBuku; i++) {
        printf("||%-5d||%-10s||%-40s||%-15d||\n", (i+1), listBuku[i].id, listBuku[i].namaBuku, listBuku[i].hargaSewa);
    }
    printf("================================================================================\n");
}

void pinjamBuku() {
    // cek apakah ada buku yagn bisa dipinjam
    if(banyakBuku == 0) {
        printf("Buku masih kosong!\n");
        return;
    }

    int pilihBuku;
    tampilListBuku();

    do {
        printf("Pilih buku no : ");
        scanf("%d", &pilihBuku);
    } while(pilihBuku < 1 || pilihBuku > banyakBuku);
}

void init() {
    strcpy(listBuku[banyakBuku].id, "BK-01");
    strcpy(listBuku[banyakBuku].namaBuku, "Belajar Pemrograman JAVA");
    listBuku[banyakBuku].hargaSewa = 30000;
    banyakBuku++;


}

void menuUtama() {

    int pilihan;
    init();
    do {
        printf("MENU UTAMA\n");
        printf("1. Tampil List Buku\n");
        printf("2. Pinjam Buku\n");
        printf("3. Keluar\n");
        printf("Pilihan >> ");
        scanf("%d", &pilihan);

        switch(pilihan) {
        case 1:
            tampilListBuku();
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            printf("Pilihan hanya dari 1 - 3 saja!\n");
        }
    } while(pilihan != 3);
}

void login() {

    char username[100];
    char password[100];

    printf("Masukan username : ");
    scanf("%s", username);

    printf("Masukan password : ");
    scanf("%s", password);

    if(strcmp(username, USERNAME) == 0 && strcmp(password, PASSWORD) == 0) {
        printf("Selamat Datang %s\n", NAMA);
        menuUtama();
    } else {
        printf("Username dan password tidak dikenali\n");
    }

}

int main() {

    menuUtama();

    return 0;
}
