#include <iostream>
#include "pengguna.h"
#include "skill.h"
using namespace std;

void createArrayPengguna(ArrayPengguna &A) {
    A.jumlah = 0;
}

bool tambahPengguna(ArrayPengguna &A, const string &id,
                    const string &nama, const string &kontak) {
    bool berhasil = false;

    if (A.jumlah < MAX_PENGGUNA && cariPenggunaSequential(A, id) == -1) {
        A.data[A.jumlah].id = id;
        A.data[A.jumlah].nama = nama;
        A.data[A.jumlah].kontak = kontak;
        A.data[A.jumlah].firstSkill = nullptr;
        A.jumlah++;
        berhasil = true;
    }

    return berhasil;
}

int cariPenggunaSequential(const ArrayPengguna &A, const string &id) {
    int posisi = -1;
    int i = 0;

    while (i < A.jumlah && posisi == -1) {
        if (A.data[i].id == id) {
            posisi = i;
        }
        i++;
    }

    return posisi;
}

void urutkanPengguna(ArrayPengguna &A) {
    int i, j;
    Pengguna sementara;

    for (i = 0; i < A.jumlah - 1; i++) {
        for (j = 0; j < A.jumlah - i - 1; j++) {
            if (A.data[j].id > A.data[j + 1].id) {
                sementara = A.data[j];
                A.data[j] = A.data[j + 1];
                A.data[j + 1] = sementara;
            }
        }
    }
}

int cariPenggunaBinary(const ArrayPengguna &A, const string &id) {
    int kiri = 0;
    int kanan = A.jumlah - 1;
    int tengah;
    int posisi = -1;

    while (kiri <= kanan && posisi == -1) {
        tengah = (kiri + kanan) / 2;

        if (A.data[tengah].id == id) {
            posisi = tengah;
        } else if (A.data[tengah].id < id) {
            kiri = tengah + 1;
        } else {
            kanan = tengah - 1;
        }
    }

    return posisi;
}

void tampilkanPengguna(const ArrayPengguna &A) {
    int i;
    NodeSkill* skillPertama;

    cout << "\n========== DAFTAR PENGGUNA ==========" << endl;
    if (A.jumlah == 0) {
        cout << "Belum ada pengguna.\n";
    } else {
        cout << "ID\tNama\t\tKontak\t\tSkill Utama" << endl;
        cout << "-------------------------------------------------------------" << endl;
        for (i = 0; i < A.jumlah; i++) {
            cout << A.data[i].id << "\t" << A.data[i].nama << "\t\t"
                 << A.data[i].kontak << "\t";
            skillPertama = A.data[i].firstSkill;
            if (skillPertama != nullptr) {
                cout << skillPertama->namaSkill;
            } else {
                cout << "Belum ada skill";
            }
            cout << endl;
        }
    }
}
