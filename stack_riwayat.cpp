#include <iostream>
#include "stack_riwayat.h"
using namespace std;

void createStack(StackRiwayat &S) {
    S.top = nullptr;
    S.jumlah = 0;
}

void pushStack(StackRiwayat &S, const string &aksi) {
    NodeRiwayat* baru = new NodeRiwayat;
    baru->aksi = aksi;
    baru->next = S.top;
    S.top = baru;
    S.jumlah++;
}

bool popStack(StackRiwayat &S, string &aksiKeluar) {
    bool berhasil = false;
    NodeRiwayat* hapus;

    if (S.top != nullptr) {
        hapus = S.top;
        aksiKeluar = hapus->aksi;
        S.top = S.top->next;
        delete hapus;
        S.jumlah--;
        berhasil = true;
    }

    return berhasil;
}

void tampilkanStack(const StackRiwayat &S) {
    NodeRiwayat* bantu = S.top;
    int nomor = 1;

    cout << "\n========== RIWAYAT AKSI (STACK / LIFO) ==========" << endl;
    if (bantu == nullptr) {
        cout << "Belum ada riwayat aksi.\n";
    } else {
        while (bantu != nullptr) {
            cout << nomor << ". " << bantu->aksi;
            if (nomor == 1) {
                cout << "  <-- TOP";
            }
            cout << endl;
            bantu = bantu->next;
            nomor++;
        }
    }
}

void hapusStack(StackRiwayat &S) {
    NodeRiwayat* hapus;

    while (S.top != nullptr) {
        hapus = S.top;
        S.top = S.top->next;
        delete hapus;
    }
    S.jumlah = 0;
}
