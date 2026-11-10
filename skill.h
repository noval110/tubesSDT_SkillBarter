#ifndef SKILL_H
#define SKILL_H

#include <string>
#include "pengguna.h"
using namespace std;

struct NodeSkill {
    string idSkill;
    string namaSkill;
    NodeSkill* next;
};

// I.S. Pengguna sudah tersedia.
// F.S. Skill baru ditambahkan di akhir linked list jika ID skill belum digunakan.
bool tambahSkill(Pengguna &P, const string &idSkill, const string &namaSkill);

// I.S. Pengguna memiliki linked list skill.
// F.S. Mengembalikan true jika ID skill ditemukan.
bool cariSkill(const Pengguna &P, const string &idSkill);

// I.S. Pengguna memiliki linked list skill atau list kosong.
// F.S. Seluruh skill pengguna ditampilkan.
void tampilkanSkill(const Pengguna &P);

// I.S. Pengguna mungkin memiliki linked list skill.
// F.S. Seluruh node skill dihapus dan firstSkill menjadi nullptr.
void hapusSemuaSkill(Pengguna &P);

#endif
