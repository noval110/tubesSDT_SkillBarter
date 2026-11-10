#include <iostream>
#include <string>
#include "pengguna.h"
#include "skill.h"
#include "queue_barter.h"
#include "stack_riwayat.h"
using namespace std;

// I.S. Array pengguna, queue barter, dan stack riwayat sudah dibuat kosong.
// F.S. Data simulasi pengguna, skill, antrean barter, dan riwayat sudah dimasukkan.
void isiDataContoh(ArrayPengguna &A, QueueBarter &Q, StackRiwayat &S) {
    PermintaanBarter p;
    int posisi;

    // Data pengguna disimpan pada Array of Struct.
    tambahPengguna(A, "U001", "Rani", "081200000001");
    tambahPengguna(A, "U002", "Budi", "081200000002");
    tambahPengguna(A, "U003", "Sinta", "081200000003");
    tambahPengguna(A, "U004", "Dimas", "081200000004");

    // Daftar skill setiap pengguna disimpan menggunakan Linked List.
    posisi = cariPenggunaSequential(A, "U001");
    if (posisi != -1) {
        tambahSkill(A.data[posisi], "S001", "Desain Grafis");
        tambahSkill(A.data[posisi], "S002", "Editing Video");
        tambahSkill(A.data[posisi], "S003", "Fotografi");
    }

    posisi = cariPenggunaSequential(A, "U002");
    if (posisi != -1) {
        tambahSkill(A.data[posisi], "S004", "Gitar");
    }

    posisi = cariPenggunaSequential(A, "U003");
    if (posisi != -1) {
        tambahSkill(A.data[posisi], "S005", "Bahasa Inggris");
    }

    posisi = cariPenggunaSequential(A, "U004");
    if (posisi != -1) {
        tambahSkill(A.data[posisi], "S006", "Python");
    }

    // Permintaan barter dimasukkan ke Queue secara FIFO.
    p.idPermintaan = "Q001";
    p.idPemohon = "U001";
    p.namaPemohon = "Rani";
    p.idTujuan = "U002";
    p.namaTujuan = "Budi";
    p.skillDitawarkan = "Desain Grafis";
    p.skillDiminta = "Gitar";
    enqueue(Q, p);

    p.idPermintaan = "Q002";
    p.idPemohon = "U003";
    p.namaPemohon = "Sinta";
    p.idTujuan = "U004";
    p.namaTujuan = "Dimas";
    p.skillDitawarkan = "Bahasa Inggris";
    p.skillDiminta = "Python";
    enqueue(Q, p);

    p.idPermintaan = "Q003";
    p.idPemohon = "U002";
    p.namaPemohon = "Budi";
    p.idTujuan = "U003";
    p.namaTujuan = "Sinta";
    p.skillDitawarkan = "Gitar";
    p.skillDiminta = "Bahasa Inggris";
    enqueue(Q, p);

    // Riwayat dimasukkan berurutan; aksi terakhir berada di TOP.
    pushStack(S, "Pengguna Dimas didaftarkan");
    pushStack(S, "Skill Sinta ditambahkan");
    pushStack(S, "Barter Rani-Budi selesai");
}

// I.S. Program siap menerima pilihan pengguna.
// F.S. Menu utama SkillBarter ditampilkan ke layar.
void menuUtama() {
    cout << "\n==============================================" << endl;
    cout << "             APLIKASI SKILLBARTER             " << endl;
    cout << "       Aplikasi Barter Keterampilan C++       " << endl;
    cout << "==============================================" << endl;
    cout << "1.  Tampilkan seluruh pengguna (Array)" << endl;
    cout << "2.  Tambah pengguna (Array of Struct)" << endl;
    cout << "3.  Cari pengguna - Sequential Search" << endl;
    cout << "4.  Cari pengguna - Binary Search" << endl;
    cout << "5.  Tampilkan skill seorang pengguna (Linked List)" << endl;
    cout << "6.  Tambah skill pengguna (Linked List)" << endl;
    cout << "7.  Ajukan permintaan barter (Enqueue)" << endl;
    cout << "8.  Tampilkan antrean barter (Queue)" << endl;
    cout << "9.  Proses permintaan terdepan (Dequeue)" << endl;
    cout << "10. Tampilkan riwayat aksi (Stack)" << endl;
    cout << "11. Catat aksi baru (Push)" << endl;
    cout << "12. Hapus catatan terakhir (Pop)" << endl;
    cout << "0.  Keluar" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "Pilih menu: ";
}

// I.S. Program belum dijalankan.
// F.S. Program menjalankan menu SkillBarter, kemudian membebaskan seluruh memori dinamis.
int main() {
    ArrayPengguna daftarPengguna;
    QueueBarter antreanBarter;
    StackRiwayat riwayatAksi;

    int pilihan = -1;
    int posisi;
    string id, nama, kontak, idSkill, namaSkill;
    string idPemohon, idTujuan, skillDitawarkan, skillDiminta;
    string aksi, aksiKeluar;
    PermintaanBarter permintaan;

    createArrayPengguna(daftarPengguna);
    createQueue(antreanBarter);
    createStack(riwayatAksi);
    isiDataContoh(daftarPengguna, antreanBarter, riwayatAksi);

    cout << "\nData simulasi awal berhasil dimuat." << endl;
    cout << "Gunakan menu untuk mencoba empat struktur data." << endl;

    while (pilihan != 0) {
        menuUtama();

        if (!(cin >> pilihan)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Input harus berupa angka. Silakan coba lagi.\n";
            pilihan = -1;
        } else {
            cin.ignore(10000, '\n');

            if (pilihan == 1) {
                tampilkanPengguna(daftarPengguna);
            } else if (pilihan == 2) {
                cout << "ID pengguna: ";
                getline(cin, id);
                cout << "Nama pengguna: ";
                getline(cin, nama);
                cout << "Kontak: ";
                getline(cin, kontak);

                if (tambahPengguna(daftarPengguna, id, nama, kontak)) {
                    pushStack(riwayatAksi, "Pengguna " + nama + " didaftarkan");
                    cout << "Pengguna berhasil ditambahkan.\n";
                } else {
                    cout << "Gagal menambahkan pengguna. Kapasitas penuh atau ID sudah digunakan.\n";
                }
            } else if (pilihan == 3) {
                cout << "Masukkan ID pengguna yang dicari: ";
                getline(cin, id);
                posisi = cariPenggunaSequential(daftarPengguna, id);
                if (posisi != -1) {
                    cout << "Pengguna ditemukan: " << daftarPengguna.data[posisi].nama
                         << " | Kontak: " << daftarPengguna.data[posisi].kontak << endl;
                } else {
                    cout << "Pengguna tidak ditemukan.\n";
                }
            } else if (pilihan == 4) {
                urutkanPengguna(daftarPengguna);
                cout << "Data telah diurutkan berdasarkan ID untuk Binary Search.\n";
                cout << "Masukkan ID pengguna yang dicari: ";
                getline(cin, id);
                posisi = cariPenggunaBinary(daftarPengguna, id);
                if (posisi != -1) {
                    cout << "Pengguna ditemukan: " << daftarPengguna.data[posisi].nama
                         << " | Kontak: " << daftarPengguna.data[posisi].kontak << endl;
                } else {
                    cout << "Pengguna tidak ditemukan.\n";
                }
            } else if (pilihan == 5) {
                cout << "Masukkan ID pengguna: ";
                getline(cin, id);
                posisi = cariPenggunaSequential(daftarPengguna, id);
                if (posisi != -1) {
                    tampilkanSkill(daftarPengguna.data[posisi]);
                } else {
                    cout << "Pengguna tidak ditemukan.\n";
                }
            } else if (pilihan == 6) {
                cout << "Masukkan ID pengguna: ";
                getline(cin, id);
                posisi = cariPenggunaSequential(daftarPengguna, id);
                if (posisi != -1) {
                    cout << "ID skill: ";
                    getline(cin, idSkill);
                    cout << "Nama skill: ";
                    getline(cin, namaSkill);
                    if (tambahSkill(daftarPengguna.data[posisi], idSkill, namaSkill)) {
                        pushStack(riwayatAksi, "Skill " + namaSkill + " ditambahkan untuk " + daftarPengguna.data[posisi].nama);
                        cout << "Skill berhasil ditambahkan.\n";
                    } else {
                        cout << "Gagal menambahkan skill. ID skill sudah digunakan pada pengguna tersebut.\n";
                    }
                } else {
                    cout << "Pengguna tidak ditemukan.\n";
                }
            } else if (pilihan == 7) {
                cout << "ID permintaan: ";
                getline(cin, permintaan.idPermintaan);
                cout << "ID pengguna pemohon: ";
                getline(cin, idPemohon);
                cout << "ID pengguna tujuan: ";
                getline(cin, idTujuan);

                posisi = cariPenggunaSequential(daftarPengguna, idPemohon);
                int posisiTujuan = cariPenggunaSequential(daftarPengguna, idTujuan);

                if (posisi != -1 && posisiTujuan != -1 && idPemohon != idTujuan) {
                    permintaan.idPemohon = idPemohon;
                    permintaan.namaPemohon = daftarPengguna.data[posisi].nama;
                    permintaan.idTujuan = idTujuan;
                    permintaan.namaTujuan = daftarPengguna.data[posisiTujuan].nama;
                    cout << "Skill yang ditawarkan: ";
                    getline(cin, skillDitawarkan);
                    cout << "Skill yang diminta: ";
                    getline(cin, skillDiminta);
                    permintaan.skillDitawarkan = skillDitawarkan;
                    permintaan.skillDiminta = skillDiminta;
                    enqueue(antreanBarter, permintaan);
                    pushStack(riwayatAksi, "Permintaan " + permintaan.idPermintaan + " masuk ke antrean");
                    cout << "Permintaan berhasil masuk ke antrean.\n";
                } else {
                    cout << "ID pemohon/tujuan tidak valid atau pengguna tidak boleh sama.\n";
                }
            } else if (pilihan == 8) {
                tampilkanQueue(antreanBarter);
            } else if (pilihan == 9) {
                if (dequeue(antreanBarter, permintaan)) {
                    cout << "Permintaan terdepan sedang diproses:" << endl;
                    cout << permintaan.idPermintaan << " | " << permintaan.namaPemohon
                         << " -> " << permintaan.namaTujuan << endl;
                    cout << "Menawarkan: " << permintaan.skillDitawarkan
                         << " | Meminta: " << permintaan.skillDiminta << endl;
                    pushStack(riwayatAksi, "Permintaan " + permintaan.idPermintaan + " telah diproses");
                } else {
                    cout << "Tidak ada permintaan untuk diproses.\n";
                }
            } else if (pilihan == 10) {
                tampilkanStack(riwayatAksi);
            } else if (pilihan == 11) {
                cout << "Masukkan deskripsi aksi: ";
                getline(cin, aksi);
                pushStack(riwayatAksi, aksi);
                cout << "Aksi berhasil dicatat pada TOP stack.\n";
            } else if (pilihan == 12) {
                if (popStack(riwayatAksi, aksiKeluar)) {
                    cout << "POP berhasil. Catatan terakhir dihapus dari stack: "
                         << aksiKeluar << endl;
                    cout << "Catatan: POP pada progres ini menghapus catatan riwayat, "
                         << "belum membatalkan perubahan data pengguna/barter.\n";
                } else {
                    cout << "Stack kosong, tidak ada riwayat untuk dihapus.\n";
                }
            } else if (pilihan == 0) {
                cout << "Menutup SkillBarter...\n";
            } else {
                cout << "Pilihan tidak tersedia. Silakan pilih menu 0-12.\n";
            }
        }
    }

    int i;
    for (i = 0; i < daftarPengguna.jumlah; i++) {
        hapusSemuaSkill(daftarPengguna.data[i]);
    }
    hapusQueue(antreanBarter);
    hapusStack(riwayatAksi);

    return 0;
}
