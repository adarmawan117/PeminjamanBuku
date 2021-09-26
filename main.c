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
#include <ctype.h>

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
    int statusSewa; // 0 untuk avail, 1 untuk dipinjam
} DATA_BUKU;

DATA_BUKU listBuku[MAX_STRUCT];
int banyakBuku = 0;

void tampilSatuBuku(int i) {
    printf("||%-5d||%-10s||%-40s||%-15d||", (i+1), listBuku[i].id, listBuku[i].namaBuku, listBuku[i].hargaSewa);

    char statusSewa[MAX_NAMA] = "Avail";
    if(listBuku[i].statusSewa == 1) {
        strcpy(statusSewa, "Dipinjam");
    }
    printf("%-22s||\n", statusSewa);
}

void tampilListBuku() {

    if(banyakBuku == 0) {
        printf("Buku masih kosong!\n");
        return;
    }

    int i;

    printf("========================================================================================================\n");
    printf("||%-5s||%-10s||%-40s||%-15s||%-22s||\n", "No", "ID", "Nama", "Harga", "Status Peminjaman");
    printf("========================================================================================================\n");
    for(i = 0; i < banyakBuku; i++) {
        tampilSatuBuku(i);
    }
    printf("========================================================================================================\n");
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

    pilihBuku--;
    char confirm;
    do {
        printf("Ingin meminjam buku dengan judul %s [Y/T]?", listBuku[pilihBuku].namaBuku);
        fflush(stdin);
        confirm = (char) toupper((char) getchar());

        if(confirm == 'Y') {
            printf("Selamat, anda berhasil meminjam buku %s\n", listBuku[pilihBuku].namaBuku);
            listBuku[pilihBuku].statusSewa = 1; // buku sudah dipinjam
        } else {
            printf("Anda membatalkan peminjaman buku %s\n", listBuku[pilihBuku].namaBuku);
        }


    } while(confirm != 'Y' && confirm != 'T');
}

void init() {
    strcpy(listBuku[banyakBuku].id, "BK-01");
    strcpy(listBuku[banyakBuku].namaBuku, "Belajar Pemrograman JAVA");
    listBuku[banyakBuku].hargaSewa = 30000;
    listBuku[banyakBuku].statusSewa = 0;
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
            pinjamBuku();
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
