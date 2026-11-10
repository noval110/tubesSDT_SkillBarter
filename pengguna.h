#ifndef PENGGUNA_H
#define PENGGUNA_H

#include <string>
using namespace std;

const int MAX_PENGGUNA = 100;

struct NodeSkill;

struct Pengguna {
    string id;
    string nama;
    string kontak;
    NodeSkill* firstSkill;
};

struct ArrayPengguna {
    Pengguna data[MAX_PENGGUNA];
    int jumlah;
};

// I.S. ArrayPengguna belum diinisialisasi.
// F.S. Array kosong dengan jumlah = 0.
void createArrayPengguna(ArrayPengguna &A);

// I.S. A mungkin berisi data pengguna.
// F.S. Pengguna baru ditambahkan jika kapasitas tersedia dan ID belum digunakan.
bool tambahPengguna(ArrayPengguna &A, const string &id,
                    const string &nama, const string &kontak);

// I.S. A berisi data pengguna.
// F.S. Mengembalikan indeks pengguna yang cocok, atau -1 jika tidak ditemukan.
int cariPenggunaSequential(const ArrayPengguna &A, const string &id);

// I.S. A berisi data pengguna.
// F.S. Data pengguna diurutkan menaik berdasarkan ID.
void urutkanPengguna(ArrayPengguna &A);

// I.S. A sudah terurut menaik berdasarkan ID.
// F.S. Mengembalikan indeks pengguna yang cocok, atau -1 jika tidak ditemukan.
int cariPenggunaBinary(const ArrayPengguna &A, const string &id);

// I.S. A mungkin kosong atau berisi data.
// F.S. Seluruh data pengguna ditampilkan.
void tampilkanPengguna(const ArrayPengguna &A);

#endif
