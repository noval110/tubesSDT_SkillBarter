#include <iostream>
#include "skill.h"
using namespace std;

bool tambahSkill(Pengguna &P, const string &idSkill, const string &namaSkill) {
    bool berhasil = false;
    NodeSkill* baru;
    NodeSkill* bantu;

    if (!cariSkill(P, idSkill)) {
        baru = new NodeSkill;
        baru->idSkill = idSkill;
        baru->namaSkill = namaSkill;
        baru->next = nullptr;

        if (P.firstSkill == nullptr) {
            P.firstSkill = baru;
        } else {
            bantu = P.firstSkill;
            while (bantu->next != nullptr) {
                bantu = bantu->next;
            }
            bantu->next = baru;
        }
        berhasil = true;
    }

    return berhasil;
}

bool cariSkill(const Pengguna &P, const string &idSkill) {
    bool ditemukan = false;
    NodeSkill* bantu = P.firstSkill;

    while (bantu != nullptr && !ditemukan) {
        if (bantu->idSkill == idSkill) {
            ditemukan = true;
        }
        bantu = bantu->next;
    }

    return ditemukan;
}

void tampilkanSkill(const Pengguna &P) {
    NodeSkill* bantu = P.firstSkill;
    int nomor = 1;

    cout << "\nSkill milik " << P.nama << " (" << P.id << ")" << endl;
    if (bantu == nullptr) {
        cout << "Belum ada skill yang terdaftar.\n";
    } else {
        while (bantu != nullptr) {
            cout << nomor << ". " << bantu->idSkill << " - "
                 << bantu->namaSkill << endl;
            bantu = bantu->next;
            nomor++;
        }
    }
}

void hapusSemuaSkill(Pengguna &P) {
    NodeSkill* hapus;

    while (P.firstSkill != nullptr) {
        hapus = P.firstSkill;
        P.firstSkill = P.firstSkill->next;
        delete hapus;
    }
}
