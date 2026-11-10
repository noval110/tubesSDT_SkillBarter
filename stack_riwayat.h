#ifndef STACK_RIWAYAT_H
#define STACK_RIWAYAT_H

#include <string>
using namespace std;

struct NodeRiwayat {
    string aksi;
    NodeRiwayat* next;
};

struct StackRiwayat {
    NodeRiwayat* top;
    int jumlah;
};

// I.S. Stack belum diinisialisasi.
// F.S. Stack kosong dengan top = nullptr.
void createStack(StackRiwayat &S);

// I.S. S mungkin kosong atau berisi riwayat.
// F.S. Catatan aksi baru ditambahkan pada posisi top.
void pushStack(StackRiwayat &S, const string &aksi);

// I.S. S mungkin kosong atau berisi riwayat.
// F.S. Catatan paling atas diambil dan dihapus jika S tidak kosong.
bool popStack(StackRiwayat &S, string &aksiKeluar);

// I.S. S mungkin kosong atau berisi riwayat.
// F.S. Seluruh riwayat ditampilkan dari top ke bawah.
void tampilkanStack(const StackRiwayat &S);

// I.S. S mungkin berisi node.
// F.S. Seluruh node stack dihapus dan S kembali kosong.
void hapusStack(StackRiwayat &S);

#endif
