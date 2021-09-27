/**
Versi 2
===========
27-September-2021
===========
- Tambah Peminjam/Penyewa = DONE
- Lihat list peminjam     = DONE
- Mengembalikan buku
- Logout                  = DONE
- Update login agar bisa membatalkan login (exit program) = DONE


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
- Login              = DONE
- Tampil list buku   = DONE
- Pinjam Buku        = DONE

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
    for(i = 0; i < banyakPeminjam; i++) {
        tampilSatuPeminjam(i);
    }
    printf("==========================================================================================\n");
}

void tambahPeminjam() {
    char id[MAX_ID];
    char namaPeminjam[MAX_NAMA];

    int panjangID;
    do {
        printf("Masukan ID Peminjam   : ");
        fflush(stdin);
        scanf("%[^\n]", listPeminjam[banyakPeminjam].id);

        panjangID = strlen(listPeminjam[banyakPeminjam].id);

        if(panjangID > MAX_ID) {
            printf("Panjang ID tidak boleh lebih dari %d karakter\n", MAX_ID);
        }

    } while(panjangID > MAX_ID);

    int panjangNama;
    do {
        printf("Masukan nama peminjam : ");
        fflush(stdin);
        scanf("%[^\n]", listPeminjam[banyakPeminjam].namaPeminjam);

        panjangNama = strlen(listPeminjam[banyakPeminjam].namaPeminjam);

        if(panjangNama > MAX_NAMA) {
            printf("Panjang Nama tidak boleh lebih dari %d karakter\n", MAX_NAMA);
        }

    } while(panjangNama > MAX_NAMA);

    char confirm;
    do {
        printf("Ingin menyimpan %s [Y/T] : ", listPeminjam[banyakPeminjam].namaPeminjam);
        fflush(stdin);
        confirm = (char) toupper((char) getchar());

        if(confirm == 'Y') {
            printf("Selamat, pelanggan \"%s\" berhasil ditambahkan\n", listPeminjam[banyakPeminjam].namaPeminjam);
            banyakPeminjam++;
        } else {
            printf("Anda batal menambahkan pelanggan %s\n", listPeminjam[banyakPeminjam].namaPeminjam);
        }


    } while(confirm != 'Y' && confirm != 'T');
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
        printf("5. Logout\n");
        printf("6. Keluar\n");
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
            tambahPeminjam();
            break;
        case 5:
            break;
        case 6:
            break;
        default:
            printf("Pilihan hanya dari 1 - 6 saja!\n");
        }
    } while(pilihan != 5);

    if(pilihan == 5) {
        login();
    } // selain itu keluar (exit) program
}

void login() {

    char username[100];
    char password[100];

    printf("\n\nMasukan 0 pada username dan password untuk membatalkan login\n\n");

    printf("Masukan username : ");
    scanf("%s", username);

    printf("Masukan password : ");
    scanf("%s", password);

    if(strcmp(username, "0") == 0 && strcmp(password, "0") == 0) {
        exit(0);
    } else if(strcmp(username, USERNAME) == 0 && strcmp(password, PASSWORD) == 0) {
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
