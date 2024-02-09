#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur untuk menyimpan informasi barang
struct Barang {
    char nama[50];
    int kode;
    int stok;
    float harga;
};

// Fungsi untuk menambahkan barang ke dalam stok
void tambahBarang(struct Barang *barang, int *jumlahBarang) {
    printf("Masukkan nama barang: ");
    scanf("%s", barang[*jumlahBarang].nama);
    printf("Masukkan kode barang: ");
    scanf("%d", &barang[*jumlahBarang].kode);
    printf("Masukkan stok barang: ");
    scanf("%d", &barang[*jumlahBarang].stok);
    printf("Masukkan harga barang: ");
    scanf("%f", &barang[*jumlahBarang].harga);

    (*jumlahBarang)++;
    printf("Barang berhasil ditambahkan!\n");
}

// Fungsi untuk menampilkan daftar barang
void tampilkanBarang(struct Barang *barang, int jumlahBarang) {
    printf("\nDaftar Barang:\n");
    printf("-------------------------------------------------\n");
    printf("| %-5s | %-20s | %-10s | %-10s |\n", "Kode", "Nama", "Stok", "Harga");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < jumlahBarang; i++) {
        printf("| %-5d | %-20s | %-10d | %-10.2f |\n", barang[i].kode, barang[i].nama, barang[i].stok, barang[i].harga);
    }
    printf("-------------------------------------------------\n");
}

// Fungsi untuk memperbarui informasi barang
void perbaruiBarang(struct Barang *barang, int jumlahBarang) {
    int kode;
    printf("Masukkan kode barang yang akan diperbarui: ");
    scanf("%d", &kode);

    for (int i = 0; i < jumlahBarang; i++) {
        if (barang[i].kode == kode) {
            printf("Masukkan nama barang baru: ");
            scanf("%s", barang[i].nama);
            printf("Masukkan stok barang baru: ");
            scanf("%d", &barang[i].stok);
            printf("Masukkan harga barang baru: ");
            scanf("%f", &barang[i].harga);

            printf("Informasi barang berhasil diperbarui!\n");
            return;
        }
    }

    printf("Barang dengan kode %d tidak ditemukan.\n", kode);
}

// Fungsi untuk menghapus barang dari stok
void hapusBarang(struct Barang *barang, int *jumlahBarang) {
    int kode;
    printf("Masukkan kode barang yang akan dihapus: ");
    scanf("%d", &kode);

    for (int i = 0; i < *jumlahBarang; i++) {
        if (barang[i].kode == kode) {
            // Geser semua barang setelah barang yang dihapus
            for (int j = i; j < *jumlahBarang - 1; j++) {
                barang[j] = barang[j + 1];
            }

            (*jumlahBarang)--;
            printf("Barang berhasil dihapus!\n");
            return;
        }
    }

    printf("Barang dengan kode %d tidak ditemukan.\n", kode);
}

// Fungsi utama
int main() {
    struct Barang barang[100]; // Array untuk menyimpan informasi barang
    int jumlahBarang = 0; // Jumlah barang dalam stok
    int pilihan;

    do {
        // Tampilkan menu
        printf("\nMenu:\n");
        printf("1. Tambah Barang\n");
        printf("2. Tampilkan Daftar Barang\n");
        printf("3. Perbarui Informasi Barang\n");
        printf("4. Hapus Barang\n");
        printf("5. Keluar\n");
        printf("Pilihan Anda: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                // Tambah barang
                tambahBarang(barang, &jumlahBarang);
                break;
            case 2:
                // Tampilkan daftar barang
                tampilkanBarang(barang, jumlahBarang);
                break;
            case 3:
                // Perbarui informasi barang
                perbaruiBarang(barang, jumlahBarang);
                break;
            case 4:
                // Hapus barang
                hapusBarang(barang, &jumlahBarang);
                break;
            case 5:
                // Keluar dari program
                printf("Trima kasih orang baik!\n");
                break;
            default:
                // Pilihan tidak valid
                printf("Mohon maaf permintaan anda tidak dimengerti, harap masukkan informasi yg valid!;(\n");
        }
    } while (pilihan != 5);

    return 0;
}