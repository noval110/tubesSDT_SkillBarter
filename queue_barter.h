#ifndef QUEUE_BARTER_H
#define QUEUE_BARTER_H

#include <string>
using namespace std;

struct PermintaanBarter {
    string idPermintaan;
    string idPemohon;
    string namaPemohon;
    string idTujuan;
    string namaTujuan;
    string skillDitawarkan;
    string skillDiminta;
};

struct NodeQueue {
    PermintaanBarter info;
    NodeQueue* next;
};

struct QueueBarter {
    NodeQueue* front;
    NodeQueue* rear;
    int jumlah;
};

// I.S. Queue belum diinisialisasi.
// F.S. Queue kosong dengan front dan rear = nullptr.
void createQueue(QueueBarter &Q);

// I.S. Q mungkin kosong atau berisi permintaan.
// F.S. Permintaan baru ditambahkan pada bagian rear.
void enqueue(QueueBarter &Q, const PermintaanBarter &data);

// I.S. Q mungkin kosong atau berisi permintaan.
// F.S. Permintaan paling depan diambil dan dihapus jika Q tidak kosong.
bool dequeue(QueueBarter &Q, PermintaanBarter &dataKeluar);

// I.S. Q mungkin kosong atau berisi permintaan.
// F.S. Seluruh isi antrean ditampilkan dari front ke rear.
void tampilkanQueue(const QueueBarter &Q);

// I.S. Q mungkin berisi node.
// F.S. Seluruh node queue dihapus dan Q kembali kosong.
void hapusQueue(QueueBarter &Q);

#endif
