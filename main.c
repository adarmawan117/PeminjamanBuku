/**
Versi 2
===========
27-September-2021
===========
- Tambah Peminjam/Penyewa
- Lihat list peminjam
- Mengembalikan buku


DATA Peminjam
-------------
id
nama
statusAnggota => 0 untuk bukan anggota, dan 1 untuk anggota


##################################

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
statusSewa

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

typedef struct {
    char id[MAX_ID];
    char namaPeminjam[MAX_NAMA];
    int statusAnggota; // 0 untuk bukan anggota, dan 1 merupakan anggota
} DATA_PEMINJAM;






DATA_BUKU listBuku[MAX_STRUCT];
int banyakBuku = 0;

DATA_PEMINJAM listPeminjam[MAX_STRUCT];
int banyakPeminjam = 0;








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


void tampilSatuPeminjam(int i) {
    printf("||%-5d||%-10s||%-40s||", (i+1), listPeminjam[i].id, listPeminjam[i].namaPeminjam);

    char statusAnggota[MAX_NAMA] = "Bukan Anggota";
    if(listPeminjam[i].statusAnggota == 1) {
        strcpy(statusAnggota, "Anggota");
    }
    printf("%-25s||\n", statusAnggota);
}

void tampilListPeminjam() {

    if(banyakPeminjam == 0) {
        printf("Peminjam masih kosong!\n");
        return;
    }

    int i;
    printf("==========================================================================================\n");
    printf("||%-5s||%-10s||%-40s||%-25s||\n", "No", "ID", "Nama", "Status Anggota");
    printf("==========================================================================================\n");
    for(i = 0; i < banyakBuku; i++) {
        tampilSatuPeminjam(i);
    }
    printf("==========================================================================================\n");
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

void initBuku() {
    strcpy(listBuku[banyakBuku].id, "BK-01");
    strcpy(listBuku[banyakBuku].namaBuku, "Belajar Pemrograman JAVA");
    listBuku[banyakBuku].hargaSewa = 30000;
    listBuku[banyakBuku].statusSewa = 0;
    banyakBuku++;
}

void initPeminjam() {
    strcpy(listPeminjam[banyakPeminjam].id, "PMJ-01");
    strcpy(listPeminjam[banyakPeminjam].namaPeminjam, "Hendra Maulana");
    listPeminjam[banyakPeminjam].statusAnggota = 0;
    banyakPeminjam++;
}

void init() {
    initBuku();
    initPeminjam();
}

void menuUtama() {

    int pilihan;
    init();
    do {
        printf("MENU UTAMA\n");
        printf("1. Tampil List Buku\n");
        printf("2. Pinjam Buku\n");
        printf("3. Tampil List Peminjam\n");
        printf("4. Tambah Peminjam\n");
        printf("5. Keluar\n");
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
            tampilListPeminjam();
            break;
        case 4:
            //tambahPeminjam();
            break;
        case 5:
            break;
        default:
            printf("Pilihan hanya dari 1 - 5 saja!\n");
        }
    } while(pilihan != 5);
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
